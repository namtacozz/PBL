#ifndef ATM_H
#define ATM_H

#include <string>

void displayMenu();
int findAccount(std::string accNum, std::string accNums[], int totalAccs);

double depositMoney(std::string accId, double currentBalance, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int& tTotal, int& dCount, int d, int m, int y);
double withdrawMoney(std::string accId, double currentBalance, double& dailyAmt, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int& tTotal, int& dCount, int d, int m, int y);
void transferMoney(std::string srcId, double& srcBalance, double& srcDailyAmt, std::string tgtId, double& tgtBalance, double amt, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int& tTotal, int& srcDCount, int d, int m, int y);
double checkBalance(std::string accId, double currentBalance, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int& tTotal, int& dCount, int d, int m, int y);
void changePIN(std::string accNums[], std::string pins[], double bals[], bool locks[], int totalAccs, int accIndex);

void runATMLoop(std::string accNums[], std::string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int totalAccs, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int& tTotal, int d, int m, int y, std::string& currentSecretCode);

#endif