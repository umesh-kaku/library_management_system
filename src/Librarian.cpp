#include<string>
#include<iostream>
#include "../include/LibraryDatabase.h"
#include "../include/Librarian.h"

void Librarian::add_book(LibraryDatabase& db, Book book) {
        db.add(book);
    }

    void search_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book) {
            book->display_book();
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void update_book(LibraryDatabase& db, int bookId, bool status) {
        db.update(bookId, status);
    }

    void issue_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book && book->get_status()) {
            book->update_book_status(false);
            cout << "Book issued by librarian!" << endl;
        } else {
            cout << "Book is already issued or unavailable!" << endl;
        }
    }

    void remove_book(LibraryDatabase& db, int bookId) {
        db.delete_book(bookId);
    }

    void return_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book) {
            book->update_book_status(true);
            cout << "Book returned by librarian!" << endl;
        }
    }

    void reverse_book(LibraryDatabase& db, int bookId) {
        // Reversal of librarian's action
        cout << "Reversing operation for book ID: " << bookId << endl;
    }

    void verify_member(LibraryManagementSystem& lms, string username) {
        // Verify if the customer exists or not
        cout << "Verifying customer: " << username << endl;
    }

    void logout() {
        cout << "Logged out!" << endl;
    }