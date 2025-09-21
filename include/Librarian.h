#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include<iostream>
#include<string>
#include "Book.h"
#include "LibraryDatabase.h"
#include "LibraryManagementSystem.h"
using namespace std;

class Librarian {
private:
    int id;
    string name;
public:
    void add_book(LibraryDatabase& db, Book book);
    void search_book(LibraryDatabase& db, int bookId);
    void update_book(LibraryDatabase& db, int bookId, bool status);
    void issue_book(LibraryDatabase& db, int bookId);
    void remove_book(LibraryDatabase& db, int bookId);
    void return_book(LibraryDatabase& db, int bookId);
    void reverse_book(LibraryDatabase& db, int bookId);
    void verify_member(LibraryManagementSystem& lms, string username);
    void logout();


};
#endif
