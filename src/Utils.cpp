#include "../include/Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void loadSystemDate(int& d, int& m, int& y) {
    ifstream file("data/date.dat");
    if (file.is_open()) {
        file >> d >> m >> y;
        file.close();
    } else {
        d = 24; m = 5; y = 2005;
    }
}

void saveSystemDate(int d, int m, int y) {
    ofstream file("data/date.dat");
    if (file.is_open()) {
        file << d << " " << m << " " << y;
        file.close();
    }
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

void incrementDate(int& d, int& m, int& y) {
    d++;
    if (d > getDaysInMonth(m, y)) {
        d = 1; m++;
        if (m > 12) { m = 1; y++; }
    }
}

string padZero(int val) {
    if (val < 10) return "0" + to_string(val);
    return to_string(val);
}

string getCurrentTimestamp(int d, int m, int y) {
    return padZero(d) + "/" + padZero(m) + "/" + to_string(y) + " 22:00:00";
}

string getFileDateString(int d, int m, int y) {
    return padZero(d) + "_" + padZero(m) + "_" + to_string(y);
}

void clearScreen() {
    for(int i = 0; i < 50; i++) cout << "\n";
}

void waitForEnter() {
    cout << "\n[Press Enter to continue...]";
    cin.ignore(10000, '\n'); 
    cin.get(); 
}

bool authenticate(string inputCode, string correctCode) {
    return inputCode == correctCode;
}

string getHiddenInput() {
    string input = "";
    char ch;
    while (true) {
        ch = _getch(); 
        
        if (ch == '\r' || ch == '\n') {
            cout << endl;
            break;
        } 
        else if (ch == '\b') {
            if (!input.empty()) {
                input.pop_back();
                cout << "\b \b"; 
            }
        } 
        else {
            input += ch; 
            cout << '*'; 
        }
    }
    return input;
}

void loadSecretCode(string& code) {
    ifstream file("data/secret.dat");
    if (file.is_open()) {
        file >> code;
        file.close();
    } else {
        code = "KINAPU"; 
    }
}

void saveSecretCode(string code) {
    ofstream file("data/secret.dat");
    if (file.is_open()) {
        file << code;
        file.close();
    }
}