#include "../include/ATM.h"
#include "../include/Utils.h"
#include "../include/Shutdown.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================
// MENU DISPLAY - ENGLISH ONLY
// ============================================

void displayWelcomeScreen() {
    clearScreen();
    cout << "\n\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                                                                                                 |\n";
    cout << "  |                       [*] AUTOMATED TELLER MACHINE [*]                                          |\n";
    cout << "  |                                                                                                 |\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                        KNPBANK - Leading Digital Bank of Vietnam                                |\n";
    cout << "  |-------------------------------------------------------------------------------------------------|\n";
    cout << "  | [*] Free internal and interbank transfers 24/7                                                  |\n";
    cout << "  | [*] Fast transaction experience with high security                                              |\n";
    cout << "  | [*] Vision: Provide comprehensive financial services for customers                              |\n";
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
    cout << "  |   [@] Account: " << accountNumber;
    for(size_t i = accountNumber.length(); i < 82; i++) cout << " ";
    cout << "|\n";
    cout << "  ===================================================================================================\n";
    cout << "  |                                                                                                 |\n";
    cout << "  |                       [1] Deposit                                                               |\n";
    cout << "  |                       [2] Withdraw                                                              |\n";
    cout << "  |                       [3] Transfer                                                              |\n";
    cout << "  |                       [4] Balance Inquiry                                                       |\n";
    cout << "  |                       [5] Change PIN                                                            |\n";
    cout << "  |                       [6] Logout                                                                |\n";
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
    cout << "  |                       [1] Shutdown System                                                       |\n";
    cout << "  |                       [2] Change Secret Code                                                    |\n";
    cout << "  |                       [3] Logout                                                                |\n";
    cout << "  |                                                                                                 |\n";
    cout << "  ===================================================================================================\n";
    cout << "\n";
}

// ============================================
// BUSINESS LOGIC
// ============================================

int findAccount(string accNum, string accNums[], int totalAccs) {
    for(int i = 0; i < totalAccs; i++) {
        if(accNums[i] == accNum) return i;
    }
    return -1;
}

double depositMoney(string accId, double currentBalance, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    while (true) {
        double amt;
        cout << "    Enter amount (0 to cancel): "; cin >> amt;

        if (amt == 0) {
            cout << "    Transaction cancelled.\n";
            waitForEnter();
            return currentBalance;
        }

        if ((long long)amt % 50000 != 0) {
            cout << "    Error: Amount must be divisible by 50,000 VND.\n";
            cout << "    Please try again.\n\n";
            continue;
        }

        if(amt > 0) {
            currentBalance += amt;
            tAccs[tTotal] = accId; tTypes[tTotal] = "DEPOSIT"; tAmts[tTotal] = amt;
            tTimes[tTotal] = getCurrentTimestamp(d, m, y);
            tTotal++; dCount++;

            cout << "    Deposit successful!\n";
            cout << "    Current balance: " << (long long)currentBalance << " VND\n";
            waitForEnter();
            return currentBalance;
        } else {
            cout << "    Error: Invalid amount.\n";
            cout << "    Please try again.\n\n";
        }
    }
}

double withdrawMoney(string accId, double currentBalance, double& dailyAmt, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    while (true) {
        double amt;
        cout << "    Enter amount (0 to cancel): "; cin >> amt;

        if (amt == 0) {
            cout << "    Transaction cancelled.\n";
            waitForEnter();
            return currentBalance;
        }

        if ((long long)amt % 50000 != 0) {
            cout << "    Error: Amount must be divisible by 50,000 VND.\n";
            cout << "    Please try again.\n\n";
            continue;
        }
        if (dailyAmt + amt > MAX_DAILY_AMOUNT) {
            cout << "    Error: Daily limit of 20,000,000 VND exceeded!\n";
            cout << "    Please try again.\n\n";
            continue;
        }

        if(amt > 0 && amt <= currentBalance) {
            currentBalance -= amt; dailyAmt += amt;
            tAccs[tTotal] = accId; tTypes[tTotal] = "WITHDRAW"; tAmts[tTotal] = amt;
            tTimes[tTotal] = getCurrentTimestamp(d, m, y);
            tTotal++; dCount++;

            cout << "    Withdrawal successful!\n";
            cout << "    Current balance: " << (long long)currentBalance << " VND\n";
            waitForEnter();
            return currentBalance;
        } else {
            cout << "    Error: Insufficient balance.\n";
            cout << "    Please try again.\n\n";
        }
    }
}

void transferMoney(string srcId, double& srcBalance, double& srcDailyAmt, string tgtId, double& tgtBalance, double amt, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& srcDCount, int d, int m, int y) {
    if ((long long)amt % 50000 != 0) {
        cout << "    Error: Amount must be divisible by 50,000 VND.\n";
        waitForEnter(); return;
    }
    if (srcDailyAmt + amt > MAX_DAILY_AMOUNT) {
        cout << "    Error: Daily limit exceeded!\n";
        waitForEnter(); return;
    }

    if(amt > 0 && amt <= srcBalance) {
        srcBalance -= amt; tgtBalance += amt; srcDailyAmt += amt;

        // Log giao dịch TRANSFER cho người gửi
        tAccs[tTotal] = srcId; tTypes[tTotal] = "TRANSFER"; tAmts[tTotal] = amt;
        tTimes[tTotal] = getCurrentTimestamp(d, m, y);
        tTotal++; srcDCount++;

        // Log giao dịch RECEIVE cho người nhận
        tAccs[tTotal] = tgtId; tTypes[tTotal] = "RECEIVE"; tAmts[tTotal] = amt;
        tTimes[tTotal] = getCurrentTimestamp(d, m, y);
        tTotal++;

        cout << "    Transfer successful!\n";
        cout << "    Current balance: " << (long long)srcBalance << " VND\n";
    } else { cout << "    Error: Insufficient balance or invalid amount.\n"; }
    waitForEnter();
}

double checkBalance(string accId, double currentBalance, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int& dCount, int d, int m, int y) {
    cout << "    Account balance: " << (long long)currentBalance << " VND\n";
    tAccs[tTotal] = accId; tTypes[tTotal] = "CHECK_BAL"; tAmts[tTotal] = 0;
    tTimes[tTotal] = getCurrentTimestamp(d, m, y);
    tTotal++; dCount++;
    waitForEnter(); return currentBalance;
}

void changePIN(string accNums[], string pins[], double bals[], bool locks[], int totalAccs, int accIndex) {
    cout << "\n    === CHANGE PIN ===\n";
    cout << "    Enter current PIN: ";
    string currentPIN = getHiddenInput();

    if (!authenticate(currentPIN, pins[accIndex])) {
        cout << "    Error: Incorrect current PIN!\n";
        waitForEnter();
        return;
    }

    cout << "    Enter new PIN: ";
    string newPIN = getHiddenInput();

    if (newPIN.length() < 4) {
        cout << "    Error: PIN must be at least 4 digits!\n";
        waitForEnter();
        return;
    }

    cout << "    Confirm new PIN: ";
    string confirmPIN = getHiddenInput();

    if (newPIN != confirmPIN) {
        cout << "    Error: PINs do not match!\n";
        waitForEnter();
        return;
    }

    pins[accIndex] = newPIN;
    updateAccountsData(accNums, pins, bals, locks, totalAccs, true);

    cout << "    PIN changed successfully!\n";
    waitForEnter();
}

// ============================================
// ADMIN MENU
// ============================================

void adminMenu(string& currentSecretCode, bool& shouldShutdown) {
    while (true) {
        displayAdminMenu();

        cout << "    Select option: ";
        string choice; cin >> choice;

        if (choice == "3") {
            cout << "    Logging out admin...\n";
            waitForEnter();
            break;
        }
        else if (choice == "1") {
            cout << "\n    SHUTDOWN - SYSTEM SHUTDOWN REQUEST\n";
            cout << "    Enter Secret Code to confirm: ";
            string pass = getHiddenInput();

            if (authenticate(pass, currentSecretCode)) {
                cout << "    Authentication successful. Shutting down system...\n";
                shouldShutdown = true;
                waitForEnter();
                return;
            } else {
                cout << "    Incorrect Secret Code! Continue operation.\n";
                waitForEnter();
            }
        }
        else if (choice == "2") {
            cout << "\n    SYSTEM - CHANGE SECRET CODE\n";
            cout << "    Enter current Secret Code: ";
            string pass = getHiddenInput();

            if (authenticate(pass, currentSecretCode)) {
                cout << "    Enter new Secret Code: ";
                string newPass = getHiddenInput();
                cout << "    Confirm new Secret Code: ";
                string confirmPass = getHiddenInput();

                if (newPass == confirmPass && newPass.length() >= 4) {
                    currentSecretCode = newPass;
                    saveSecretCode(currentSecretCode);
                    cout << "    Secret Code changed successfully!\n";
                } else {
                    cout << "    Error: Codes do not match or too short (minimum 4 characters).\n";
                }
            } else {
                cout << "    Incorrect current Secret Code!\n";
            }
            waitForEnter();
        }
        else { cout << "    Error: Invalid option.\n"; waitForEnter(); }
    }
}

// ============================================
// MAIN ATM LOOP
// ============================================

void runATMLoop(string accNums[], string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int totalAccs, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int& tTotal, int d, int m, int y, string& currentSecretCode) {
    while (true) {
        displayWelcomeScreen();

        cout << "    Please enter Account Number or SECRET for staff: ";
        string accInput; cin >> accInput;

        if (accInput == "SECRET") {
            // ADMIN LOGIN
            cout << "    Enter Secret Code: ";
            string secretInput = getHiddenInput();

            if (authenticate(secretInput, currentSecretCode)) {
                cout << "\n    Admin login successful!\n";
                waitForEnter();

                bool shouldShutdown = false;
                adminMenu(currentSecretCode, shouldShutdown);

                if (shouldShutdown) {
                    break;
                }
            } else {
                cout << "\n    Incorrect Secret Code!\n";
                waitForEnter();
            }
        } else {
            // CUSTOMER LOGIN
            int accIndex = findAccount(accInput, accNums, totalAccs);
            if (accIndex == -1) {
                cout << "\n    Error: Account not found!\n";
                waitForEnter();
                continue;
            }

            if (locks[accIndex]) {
                cout << "\n  ===================================================================================================\n";
                cout << "  |  [!] WARNING: CARD HAS BEEN LOCKED AND RETAINED                                                 |\n";
                cout << "  |  [#] Please visit the nearest KNPBANK branch to unlock                                          |\n";
                cout << "  ===================================================================================================\n";
                waitForEnter();
                continue;
            }

            int attempts = 0; bool loggedIn = false;
            while (attempts < 3) {
                cout << "    Enter PIN: ";
                string pin = getHiddenInput();

                if (authenticate(pin, pins[accIndex])) {
                    loggedIn = true; break;
                } else {
                    attempts++;
                    cout << "\n    Incorrect PIN! " << 3 - attempts << " attempts remaining.\n";
                }
            }

            if (!loggedIn) {
                locks[accIndex] = true;
                updateAccountsData(accNums, pins, bals, locks, totalAccs, true);

                cout << "\n  ===================================================================================================\n";
                cout << "  |  [!] SECURITY WARNING: INCORRECT PIN 3 TIMES                                                    |\n";
                cout << "  |  [!] YOUR CARD HAS BEEN RETAINED BY THE ATM                                                     |\n";
                cout << "  ===================================================================================================\n";
                waitForEnter();
                continue;
            }

            // CUSTOMER MENU LOOP
            while (true) {
                displayCustomerMenu(accNums[accIndex]);

                cout << "    Select option: ";
                string choice; cin >> choice;

                if (choice == "6") break;

                // Kiểm tra giới hạn giao dịch/ngày (trừ Change PIN và Logout)
                if (choice >= "1" && choice <= "4" && dailyCnts[accIndex] >= MAX_TRANS_PER_DAY) {
                    cout << "\n    Error: Daily transaction limit (" << MAX_TRANS_PER_DAY << ") reached!\n";
                    cout << "    Please come back tomorrow.\n";
                    waitForEnter();
                    continue;
                }

                if (choice == "1") {
                    bals[accIndex] = depositMoney(accNums[accIndex], bals[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else if (choice == "2") {
                    bals[accIndex] = withdrawMoney(accNums[accIndex], bals[accIndex], dailyAmts[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else if (choice == "3") {
                    string tgt;
                    cout << "\n    Recipient account (0 to cancel): "; cin >> tgt;

                    if (tgt == "0") {
                        cout << "    Transaction cancelled.\n";
                        waitForEnter(); continue;
                    }

                    if (tgt == accNums[accIndex]) {
                        cout << "    Error: Cannot transfer to yourself!\n";
                        waitForEnter(); continue;
                    }

                    int tIdx = findAccount(tgt, accNums, totalAccs);
                    if(tIdx != -1) {
                        double amt;
                        cout << "    Amount (0 to cancel): "; cin >> amt;

                        if (amt == 0) {
                            cout << "    Transaction cancelled.\n";
                            waitForEnter(); continue;
                        }

                        transferMoney(accNums[accIndex], bals[accIndex], dailyAmts[accIndex], accNums[tIdx], bals[tIdx], amt, tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                    } else { cout << "    Error: Recipient account not found.\n"; waitForEnter(); }
                }
                else if (choice == "4") {
                    bals[accIndex] = checkBalance(accNums[accIndex], bals[accIndex], tAccs, tTypes, tAmts, tTimes, tTotal, dailyCnts[accIndex], d, m, y);
                }
                else if (choice == "5") {
                    changePIN(accNums, pins, bals, locks, totalAccs, accIndex);
                }
                else { cout << "\n    Error: Invalid option.\n"; waitForEnter(); }
            }
        }
    }
}
