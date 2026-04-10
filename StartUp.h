#ifndef STARTUP_H
#define STARTUP_H

#include <string>

bool authenticateSecret(std::string currentSecretCode); 
void loadAccountData(std::string accNums[], std::string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs);
void startATM(std::string accNums[], std::string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs, int& d, int& m, int& y);

bool StartUp(std::string accNums[], std::string pins[], double bals[], int dailyCnts[], bool locks[], double dailyAmts[], int& totalAccs, int& d, int& m, int& y, std::string currentSecretCode);

#endif