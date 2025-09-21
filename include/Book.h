#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    int bookId;
    string subject;
    string author;
    bool status; // true if available, false if issued

public:
    Book(int id, string t, string s, string a);
    void display_book();
    void update_book_status(bool isIssued);
    bool get_status();
    int get_id();
    string get_title();

};
#endif