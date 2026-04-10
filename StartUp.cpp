#include "StartUp.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool authenticateSecret(string currentSecretCode) {
    clearScreen();
    cout << "  ===================================================================================================\n";
    cout << "  |                                SYSTEM BOOT (SECRET ONLY)                                        |\n";
    cout << "  ===================================================================================================\n";
    cout << "[LOCK] Enter Secret Code to Boot: ";
    string input = getHiddenInput();

    if (!authenticate(input, currentSecretCode)) { 
        cout << "[X]" " Invalid Code! System halting.\n";
        return false;
    }
    return true;
}

void loadAccountData(string accNums[], string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs) {
    ifstream file("accounts.dat");
    if (!file.is_open()) {
        totalAccs = 5;
        string accs[] = {"1001", "1002", "1003", "1004", "1005"};
        string ps[] = {"1234", "2345", "3456", "4567", "5678"};
        double bs[] = {5000000, 3000000, 10000000, 2000000, 7500000};
        for(int i = 0; i < 5; i++) {
            accNums[i] = accs[i]; pins[i] = ps[i]; bals[i] = bs[i];
            dailyCnts[i] = 0; locks[i] = false; dailyAmts[i] = 0;
        }
    } else {
        totalAccs = 0;
        string status;
        while (file >> accNums[totalAccs] >> pins[totalAccs] >> bals[totalAccs] >> status) {
            dailyCnts[totalAccs] = 0;
            locks[totalAccs] = (status == "LOCKED");
            dailyAmts[totalAccs] = 0;
            totalAccs++;
        }
        file.close();
    }
}

void startATM(string accNums[], string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs, int& d, int& m, int& y) {
    cout << "\n[SYSTEM] Initializing...\n";
    loadSystemDate(d, m, y);
    loadAccountData(accNums, pins, bals, dailyCnts, locks, dailyAmts, totalAccs);
    cout << "[V]" " System Ready. Date: " << padZero(d) << "/" << padZero(m) << "/" << y << "\n";
    waitForEnter();
}

bool StartUp(string accNums[], string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs, int& d, int& m, int& y, string currentSecretCode) {
    if (!authenticateSecret(currentSecretCode)) return false;
    startATM(accNums, pins, bals, dailyCnts, locks, dailyAmts, totalAccs, d, m, y);
    return true;
}