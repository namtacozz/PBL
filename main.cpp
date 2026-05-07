#include "StartUp.h"
#include "ATM.h"
#include "Shutdown.h"
#include "Utils.h"

using namespace std;

int main() {
    string currentSecretCode;
    loadSecretCode(currentSecretCode);

    // 1. Mảng dữ liệu Khách Hàng
    string accountNumbers[MAX_ACCOUNTS];
    string pins[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS];
    int dailyTransactionCount[MAX_ACCOUNTS];
    bool isLocked[MAX_ACCOUNTS];
    double dailyTransAmount[MAX_ACCOUNTS];
    int totalAccounts = 0;

    // 2. Mảng dữ liệu Giao Dịch
    string transAccountNumbers[MAX_TOTAL_TRANSACTIONS];
    string transTypes[MAX_TOTAL_TRANSACTIONS];
    double transAmounts[MAX_TOTAL_TRANSACTIONS];
    string transTimestamps[MAX_TOTAL_TRANSACTIONS];
    int totalTransactions = 0;

    // 3. Hệ thống thời gian giả lập
    int currentDay, currentMonth, currentYear;

    if (StartUp(accountNumbers, pins, balances, dailyTransactionCount, isLocked, dailyTransAmount, totalAccounts, currentDay, currentMonth, currentYear, currentSecretCode)) { 
        
        runATMLoop(accountNumbers, pins, balances, dailyTransactionCount, isLocked, dailyTransAmount, totalAccounts, transAccountNumbers, transTypes, transAmounts, transTimestamps, totalTransactions, currentDay, currentMonth, currentYear, currentSecretCode);
        
        shutdown(accountNumbers, pins, balances, isLocked, totalAccounts, transAccountNumbers, transTypes, transAmounts, transTimestamps, totalTransactions, currentDay, currentMonth, currentYear);
    }
    return 0;
}