#ifndef LIBRARYDATABASE_H
#define LIBRARYDATABASE_H
#include <string>
#include <iostream>
#include "../include/Book.h"
#include <vector>
using namespace std;

class LibraryDatabase {
private:
    vector<Book> listOfBooks;
public:
    void add(Book book);
    void delete_book(int bookID);
    void update(int bookId, bool status);
    Book* search(int bookId);
    void display();    
};
#endif
