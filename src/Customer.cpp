#include "../include/Customer.h"
#include "../include/LibraryDatabase.h"
#include <string>
using namespace std;

Customer::Customer(string username, string password) {
    this -> username = username;
    this -> password = password;
}

void Customer::login(string userName, string pass) {
        if (userName == this -> username && pass == this -> password) {
            cout << "Customer login successful!" << endl;
        } else {
            cout << "Invalid customer credentials!" << endl;
        }
    }

    void Customer::check_account() {
        cout << "Customer details: " << endl;
        cout << "Username: " << this -> username << endl;
    }

    void Customer::search_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book) {
            book->display_book();
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void Customer::issue_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book && book->get_status()) {
            book->update_book_status(false);
            cout << "Book issued successfully!" << endl;
        } else {
            cout << "Book is either not available or already issued." << endl;
        }
    }

    void Customer::return_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book && !book->get_status()) {
            book->update_book_status(true);
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "This book was not issued." << endl;
        }
    }

    void Customer::reverse_book(LibraryDatabase& db, int bookId) {
        cout << "Reversing operation for book ID: " << bookId << endl;
    }

    void Customer::logout() {
        cout << "Logged out!" << endl;
    }