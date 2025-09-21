#include "../include/LibraryManagementSystem.h"
#include <string>
#include <iostream>
using namespace std;

LibraryManagementSystem::LibraryManagementSystem() {

}

void LibraryManagementSystem::create_account(int userId, string userName, string pass, string phone, string email) {
    this -> id = userId;
    this -> username = userName;
    this -> password = pass;
    this -> phoneNumber = phone;
    this -> emailId = email;
    cout << "Account created successfully for " << this -> name << endl;
}

bool LibraryManagementSystem::login(string userName, string pass) {
    if (userName == this -> username && pass == this -> password) {
        cout << "Login successful!" << endl;
        return true;
    }
    cout << "Invalid credentials!" << endl;
    return false;
}

void LibraryManagementSystem::logout() {
    cout << "Logged out successfully!" << endl;
}