#ifndef UTILS_H
#define UTILS_H

#include <string>

// Các hằng số dùng chung thay thế cho biến toàn cục
const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 5;
const double MAX_DAILY_AMOUNT = 20000000.0; 
void loadSecretCode(std::string& code);
void saveSecretCode(std::string code);

// Các hàm xử lý thời gian
void loadSystemDate(int& d, int& m, int& y);
void saveSystemDate(int d, int m, int y);
void incrementDate(int& d, int& m, int& y);
std::string getCurrentTimestamp(int d, int m, int y);
std::string getFileDateString(int d, int m, int y); 
std::string padZero(int val); // 

// Các tiện ích
void clearScreen();
void waitForEnter();
std::string getHiddenInput(); 

// Hàm xác thực dùng chung cho cả SECRET và USER
bool authenticate(std::string inputCode, std::string correctCode);

#endif