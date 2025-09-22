#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include "LibraryDatabase.h"
#include "User.h"
using namespace std;

class Customer : public User {
    public:
        Customer(string username, string password);
        void login(string userName, string pass);
        void check_account();
        void search_book(LibraryDatabase& db, int bookId);
        void issue_book(LibraryDatabase& db, int bookId);
        void return_book(LibraryDatabase& db, int bookId);
        void reserve_book(LibraryDatabase& db, int bookId);
        void logout();
};
#endif
