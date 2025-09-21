#include "../include/Book.h"
#include <iostream>
using namespace std;

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