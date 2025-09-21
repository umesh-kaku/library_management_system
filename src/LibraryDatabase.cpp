#include <string>
#include "../include/LibraryDatabase.h"
#include "../include/Book.h"

using namespace std;

void LibraryDatabase::add(Book book) {
    this -> listOfBooks.push_back(book);
    cout << "Book added to library: " << book.get_title() << endl;
}

void LibraryDatabase::delete_book(int bookId) {
    auto it = remove_if(this -> listOfBooks.begin(), this -> listOfBooks.end(), [bookId](Book& b) { return b.get_id() == bookId; });
    if (it != this -> listOfBooks.end()) {
        listOfBooks.erase(it, listOfBooks.end());
        cout << "Book with ID " << bookId << " removed from library." << endl;
    }
}

void LibraryDatabase::update(int bookId, bool status) {
    for (auto& book : this -> listOfBooks) {
        if (book.get_id() == bookId) {
            book.update_book_status(status);
            cout << "Book status updated for: " << book.get_title() << endl;
            return;
        }
    }
}

Book* LibraryDatabase::search(int bookId) {
    for (auto& book : this -> listOfBooks) {
        if (book.get_id() == bookId) {
            return &book;
        }
    }
    return nullptr;
}

void LibraryDatabase::display() {
    cout << "Displaying all books in the library:" << endl;
    for (auto& book : this -> listOfBooks) {
        book.display_book();
    }
}