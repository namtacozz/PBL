#include "ATM.h"
#include "Utils.h"
#include "Shutdown.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================
// MENU HIỂN THỊ - UI RỘNG VÀ ĐẸP HƠN
// ============================================

void displayWelcomeScreen() {
    clearScreen();
    cout << "\n\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                                                                                                 |\n";
    cout << "  |                       [*] AUTOMATED TELLER MACHINE (ATM) [*]                                    |\n";
    cout << "  |                                                                                                 |\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                        KNPBANK - Ngan Hang So Hang Dau Viet Nam                                 |\n";
    cout << "  |-------------------------------------------------------------------------------------------------|\n";
    cout << "  | [*] Mien phi 100% phi chuyen khoan noi bo va lian ngan hang 24/7                                |\n";
    cout << "  | [*] Trai nghiem giao dich sieu toc, an toan bao mat dinh cao                                    |\n";
    cout << "  | [*] Tam nhin: Cung cap dich vu tai chinh toan dien, mang lai gia tri tot nhat cho khach hang    |\n";
    cout << "  | [*] Hotline 24/7: 1900 5555 88   ---   Website: www.knpbank.com.vn                              |\n";
    cout << "  ===================================================================================================\n";
    cout << "\n";
}

void displayCustomerMenu(string accountNumber) {
    clearScreen();
    cout << "\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                         [$] KNPBANK - CUSTOMER MENU [$]                                         |\n";
    cout << "  ===================================================================================================\n";
    cout << "  |   [@] Tai khoan: " << accountNumber;
    for(size_t i = accountNumber.length(); i < 77; i++) cout << " ";
    cout << "|\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                                                                                                 |\n";
    cout << "  |                       [1] [+] Gui tien (Deposit)                                                |\n";
    cout << "  |                       [2] [-] Rut tien (Withdraw)                                               |\n";
    cout << "  |                       [3] [>] Chuyen khoan (Transfer)                                           |\n";
    cout << "  |                       [4] [=] Kiem tra so du (Balance)                                          |\n";
    cout << "  |                       [5] [X] Dang xuat (Logout)                                                |\n";
    cout << "  |                                                                                                 |\n";
    cout << "  ===================================================================================================\n";
    cout << "\n";
}

void displayAdminMenu() {
    clearScreen();
    cout << "\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                       [#] KNPBANK - ADMIN CONTROL PANEL [#]                                     |\n";
    cout << "  ===================================================================================================\n";
    cout << "  |   [!] WARNING: AUTHORIZED PERSONNEL ONLY                                                        |\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                                                                                                 |\n";
    cout << "  |                       [1] [!] Shutdown System (Tat he thong)                                    |\n";
    cout << "  |                       [2] [*] Change Secret Code (Doi ma Secret)                                |\n";
    cout << "  |                       [3] [X] Logout (Dang xuat)                                                |\n";
    cout << "  |                                                                                                 |\n";
    cout << "  ===================================================================================================\n";
    cout << "\n";
}

// ============================================
// LOGIC CŨ - GIỮ NGUYÊN (NHƯNG ĐIỀU CHỈNH LỀ)
// ============================================

int findAccount(string accNum, string accNums[], int totalAccs) {
    for(int i = 0; i < totalAccs; i++) {
        if(accNums[i] == accNum) return i;
    }
    return -1;
}

double depositMoney(string accId, double currentBalance, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    double amt; 
    cout << "    [_] So tien gui: "; cin >> amt;
    
    if ((long long)amt % 50000 != 0) {
        cout << "    [X] Loi: So tien phai chia het cho 50,000 VND.\n";
        waitForEnter(); return currentBalance;
    }

    if(amt > 0) {
        currentBalance += amt;
        tAccs[tTotal] = accId; tTypes[tTotal] = "DEPOSIT"; tAmts[tTotal] = amt;
        tTimes[tTotal] = getCurrentTimestamp(d, m, y);
        tTotal++; dCount++;
        
        cout << "    [V] Gui tien thanh cong!\n";
        cout << "    [i] So du hien tai: " << (long long)currentBalance << " VND\n";
    } else { cout << "    [X] Loi: So tien khong hop le.\n"; }
    waitForEnter(); return currentBalance;
}

double withdrawMoney(string accId, double currentBalance, double& dailyAmt, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    double amt; 
    cout << "    [_] So tien rut: "; cin >> amt;
    
    if ((long long)amt % 50000 != 0) {
        cout << "    [X] Loi: So tien phai chia het cho 50,000 VND.\n";
        waitForEnter(); return currentBalance;
    }
    if (dailyAmt + amt > MAX_DAILY_AMOUNT) {
        cout << "    [X] Loi: Vuot qua han muc giao dich 20,000,000 VND/ngay!\n";
        waitForEnter(); return currentBalance;
    }

    if(amt > 0 && amt <= currentBalance) {
        currentBalance -= amt; dailyAmt += amt; 
        tAccs[tTotal] = accId; tTypes[tTotal] = "WITHDRAW"; tAmts[tTotal] = amt;
        tTimes[tTotal] = getCurrentTimestamp(d, m, y);
        tTotal++; dCount++;
        
        cout << "    [V] Rut tien thanh cong!\n";
        cout << "    [i] So du hien tai: " << (long long)currentBalance << " VND\n";
    } else { cout << "    [X] Loi: So du khong du.\n"; }
    waitForEnter(); return currentBalance;
}

void transferMoney(string srcId, double& srcBalance, double& srcDailyAmt, string tgtId, double& tgtBalance, double amt, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& srcDCount, int d, int m, int y) {
    if (srcDailyAmt + amt > MAX_DAILY_AMOUNT) {
        cout << "    [X] Loi: Vuot qua han muc giao dich!\n";
        waitForEnter(); return;
    }

    if(amt > 0 && amt <= srcBalance) {
        srcBalance -= amt; tgtBalance += amt; srcDailyAmt += amt;
        tAccs[tTotal] = srcId; tTypes[tTotal] = "TRANSFER"; tAmts[tTotal] = amt;
        tTimes[tTotal] = getCurrentTimestamp(d, m, y);
        tTotal++; srcDCount++;
        
        cout << "    [V] Chuyen khoan thanh cong!\n";
        cout << "    [i] So du hien tai: " << (long long)srcBalance << " VND\n";
    } else { cout << "    [X] Loi: So du khong du hoac so tien khong hop le.\n"; }
    waitForEnter();
}

double checkBalance(string accId, double currentBalance, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    cout << "    [_] So du tai khoan: " << (long long)currentBalance << " VND\n";
    tAccs[tTotal] = accId; tTypes[tTotal] = "CHECK_BAL"; tAmts[tTotal] = 0;
    tTimes[tTotal] = getCurrentTimestamp(d, m, y);
    tTotal++; dCount++;
    waitForEnter(); return currentBalance;
}

// ============================================
// ADMIN MENU
// ============================================

void adminMenu(string& currentSecretCode, bool& shouldShutdown) {
    while (true) {
        displayAdminMenu();
        
        cout << "    [_] Chon chuc nang: ";
        string choice; cin >> choice;

        if (choice == "3") {
            cout << "    [i] Dang xuat admin...\n";
            waitForEnter();
            break;
        }
        else if (choice == "1") {
            cout << "\n    [!] SHUTDOWN - YEU CAU TAT HE THONG\n";
            cout << "    [_] Nhap ma Secret de xac nhan: ";
            string pass = getHiddenInput();
            
            if (authenticate(pass, currentSecretCode)) {
                cout << "    [V] Xac thuc thanh cong. Dang tat he thong...\n";
                shouldShutdown = true;
                waitForEnter();
                return;
            } else {
                cout << "    [X] Sai ma Secret! Tiep tuc hoat dong.\n";
                waitForEnter();
            }
        }
        else if (choice == "2") {
            cout << "\n    [*] SYSTEM - DOI MA SECRET\n";
            cout << "    [_] Nhap ma Secret hien tai: ";
            string pass = getHiddenInput();
            
            if (authenticate(pass, currentSecretCode)) {
                cout << "    [_] Nhap ma Secret moi: ";
                string newPass = getHiddenInput();
                cout << "    [_] Xac nhan ma Secret moi: ";
                string confirmPass = getHiddenInput();
                
                if (newPass == confirmPass && newPass.length() >= 4) {
                    currentSecretCode = newPass;
                    saveSecretCode(currentSecretCode);
                    cout << "    [V] Doi ma Secret thanh cong!\n";
                } else {
                    cout << "    [X] Loi: Ma khong khop hoac qua ngan (toi thieu 4 ky tu).\n";
                }
            } else {
                cout << "    [X] Sai ma Secret hien tai!\n";
            }
            waitForEnter();
        }
        else { cout << "    [X] Loi: Lua chon khong hop le.\n"; waitForEnter(); }
    }
}

// ============================================
// MAIN ATM LOOP - ĐĂNG NHẬP CHUNG
// ============================================

void runATMLoop(string accNums[], string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int totalAccs, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int d, int m, int y, string& currentSecretCode) {
    while (true) {
        displayWelcomeScreen();
        
        cout << "    [_] Vui long nhap So Tai Khoan (nhap 'SECRET' de quan tri): ";
        string accInput; cin >> accInput;

        if (accInput == "SECRET") {
            // ADMIN LOGIN
            cout << "    [_] Nhap ma Secret Code: ";
            string secretInput = getHiddenInput();
            
            if (authenticate(secretInput, currentSecretCode)) {
                cout << "\n    [V] Dang nhap admin thanh cong!\n";
                waitForEnter();
                
                bool shouldShutdown = false;
                adminMenu(currentSecretCode, shouldShutdown);
                
                if (shouldShutdown) {
                    break;
                }
            } else {
                cout << "\n    [X] Sai ma PIN!\n";
                waitForEnter();
            }
        } else {
            // CUSTOMER LOGIN
            int accIndex = findAccount(accInput, accNums, totalAccs);
            if (accIndex == -1) {
                cout << "\n    [X] Loi: Khong tim thay tai khoan!\n";
                waitForEnter();
                continue;
            }

            if (locks[accIndex]) {
                cout << "\n  ===================================================================================================\n";
                cout << "  |  [!] CANH BAO: THE DA BI KHOA VA GIU LAI                                                        |\n";
                cout << "  |  [#] Vui long den chi nhanh KNPBANK gan nhat de mo khoa                                         |\n";
                cout << "  ===================================================================================================\n";
                waitForEnter();
                continue;
            }

            int attempts = 0; bool loggedIn = false;
            while (attempts < 3) {
                cout << "    [_] Nhap ma PIN: ";
                string pin = getHiddenInput();
                
                if (authenticate(pin, pins[accIndex])) {
                    loggedIn = true; break;
                } else {
                    attempts++;
                    cout << "\n    [X] Sai ma PIN! Con " << 3 - attempts << " lan thu.\n";
                }
            }

            if (!loggedIn) {
                locks[accIndex] = true; 
                updateAccountsData(accNums, pins, bals, locks, totalAccs, true); 

                cout << "\n  ===================================================================================================\n";
                cout << "  |  [!] CANH BAO BAO MAT: NHAP SAI MA PIN 3 LAN                                                    |\n";
                cout << "  |  [!] THE CUA BAN DA BI GIU LAI BOI MAY ATM                                                      |\n";
                cout << "  ===================================================================================================\n";
                waitForEnter();
                continue;
            }

            // CUSTOMER MENU LOOP
            while (true) {
                displayCustomerMenu(accNums[accIndex]);
                
                cout << "    [_] Chon chuc nang: ";
                string choice; cin >> choice; 

                if (choice == "5") break;
                else if (choice == "1") {
                    bals[accIndex] = depositMoney(accNums[accIndex], bals[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else if (choice == "2") {
                    bals[accIndex] = withdrawMoney(accNums[accIndex], bals[accIndex], dailyAmts[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else if (choice == "3") {
                    string tgt; double amt;
                    cout << "\n    [_] Tai khoan nhan: "; cin >> tgt;
                    
                    if (tgt == accNums[accIndex]) {
                        cout << "    [X] Loi: Khong the chuyen cho chinh minh!\n";
                        waitForEnter(); continue;
                    }

                    int tIdx = findAccount(tgt, accNums, totalAccs);
                    if(tIdx != -1) {
                        cout << "    [_] So tien: "; cin >> amt;
                        if ((long long)amt % 50000 != 0) {
                            cout << "    [X] Loi: So tien phai chia het cho 50,000 VND.\n";
                            waitForEnter(); continue;
                        }
                        transferMoney(accNums[accIndex], bals[accIndex], dailyAmts[accIndex], accNums[tIdx], bals[tIdx], amt, tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                    } else { cout << "    [X] Loi: Khong tim thay tai khoan nhan.\n"; waitForEnter(); }
                }
                else if (choice == "4") {
                    bals[accIndex] = checkBalance(accNums[accIndex], bals[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else { cout << "\n    [X] Loi: Lua chon khong hop le.\n"; waitForEnter(); }
            }
        }
    }
}

