#include "../include/Book.h"
#include <iostream>
using namespace std;

Book::Book(int id, string t, string s, string a) {
    this -> bookId = id;
    this -> title = t;
    this -> subject = s;
    this -> author = a;
    this -> status = false;
}

void Book::display_book() {
    cout << "Book ID: " << this -> bookId << ", Title: " << title << ", Subject: " << subject << ", Author: " << author;
    cout << (status ? " (Available)" : " (Issued)") << endl;
}

void Book::update_book_status (bool isIssued) {
    this -> status = isIssued;
}

bool Book::get_status() {
    return this -> status;
}

int Book::get_id() {
    return this -> bookId;
}

string Book::get_title() {
    return this -> title;
}

void Book::set_status(bool s) {
    status = s;
}