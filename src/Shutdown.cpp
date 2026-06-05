#include "../include/Shutdown.h"
#include "../include/Utils.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void updateAccountsData(string accNums[], string pins[], double bals[], bool locks[], int totalAccs, bool silent) {
    ofstream file("data/accounts.dat");
    if (file.is_open()) {
        for (int i = 0; i < totalAccs; i++) {
            file << accNums[i] << " " << pins[i] << " " << (long long)bals[i] << " "
                 << (locks[i] ? "LOCKED" : "ACTIVE") << "\n";
        }
        file.close();
        if (!silent) cout << "[SAVE] Accounts Database Updated Successfully.\n";
    }
}

// LƯU RIÊNG FILE THEO TỪNG NGÀY
void saveTransactionData(string tAccs[], string tTypes[], double tAmts[], string tTimes[], int tTotal, int d, int m, int y) {
    string fileName = "data/transactions_" + getFileDateString(d, m, y) + ".dat";
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << "--- LOG: " << getCurrentTimestamp(d, m, y) << " ---\n";
        for (int i = 0; i < tTotal; i++) {
            file << tTimes[i] << " | " << tAccs[i] << " | " << tTypes[i] << " | " << (long long)tAmts[i] << "\n";
        }
        file.close();
        cout << "[SAVE] Transaction History Saved to " << fileName << ".\n";
    }
}

void shutdown(string accNums[], string pins[], double bals[], bool locks[], int totalAccs, string tAccs[], string tTypes[], double tAmts[], string tTimes[], int tTotal, int& d, int& m, int& y) {
    cout << "\n[SHUTDOWN] FINALIZING SHUTDOWN SEQUENCE...\n";

    saveTransactionData(tAccs, tTypes, tAmts, tTimes, tTotal, d, m, y);
    updateAccountsData(accNums, pins, bals, locks, totalAccs, false);
    
    incrementDate(d, m, y);
    saveSystemDate(d, m, y);
    
    cout << "[*]" " KNPBANK Server is now OFFLINE. Goodnight, Sir!\n";
}