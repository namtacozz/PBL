#ifndef SHUTDOWN_H
#define SHUTDOWN_H

#include <string>

void updateAccountsData(std::string accNums[], std::string pins[], double bals[], bool locks[], int totalAccs, bool silent = false);
void saveTransactionData(std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int tTotal, int d, int m, int y);
void shutdown(std::string accNums[], std::string pins[], double bals[], bool locks[], int totalAccs, std::string tAccs[], std::string tTypes[], double tAmts[], std::string tTimes[], int tTotal, int& d, int& m, int& y);

#endif