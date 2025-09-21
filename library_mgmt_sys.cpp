#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class Librarian;
class Customer;
class LibraryDatabase;
class Notification;
class Book;

// Library Management System Class
class LibraryManagementSystem {
private:
    int id;
    string name;
    string username;
    string password;
    int phoneNumber;
    string emailId;

public:
    void create_account(int userId, string userName, string pass, int phone, string email) {
        id = userId;
        username = userName;
        password = pass;
        phoneNumber = phone;
        emailId = email;
        cout << "Account created successfully for " << name << endl;
    }

    bool login(string userName, string pass) {
        if (userName == username && pass == password) {
            cout << "Login successful!" << endl;
            return true;
        }
        cout << "Invalid credentials!" << endl;
        return false;
    }

    void logout() {
        cout << "Logged out successfully!" << endl;
    }
};

// Notification Class
class Notification {
private:
    int notificationId;
    string createdOn;
    string content;

public:
    bool sent_notification() {
        cout << "Notification sent: " << content << endl;
        return true;
    }

    void set_notification_content(string message) {
        content = message;
    }

    void set_notification_date() {
        time_t now = time(0);
        char* dt = ctime(&now);
        createdOn = string(dt);
    }
};

// Book Class
class Book {
private:
    string title;
    int bookId;
    string subject;
    string author;
    bool status; // true if available, false if issued

public:
    Book(int id, string t, string s, string a) : bookId(id), title(t), subject(s), author(a), status(true) {}

    void display_book() {
        cout << "Book ID: " << bookId << ", Title: " << title << ", Subject: " << subject << ", Author: " << author;
        cout << (status ? " (Available)" : " (Issued)") << endl;
    }

    void update_book_status(bool isIssued) {
        status = isIssued;
    }

    bool get_status() const {
        return status;
    }

    int get_id() const {
        return bookId;
    }

    string get_title() const {
        return title;
    }
};

// Library Database Class
class LibraryDatabase {
private:
    vector<Book> listOfBooks;

public:
    void add(Book book) {
        listOfBooks.push_back(book);
        cout << "Book added to library: " << book.get_title() << endl;
    }

    void delete_book(int bookId) {
        auto it = remove_if(listOfBooks.begin(), listOfBooks.end(), [bookId](Book& b) { return b.get_id() == bookId; });
        if (it != listOfBooks.end()) {
            listOfBooks.erase(it, listOfBooks.end());
            cout << "Book with ID " << bookId << " removed from library." << endl;
        }
    }

    void update(int bookId, bool status) {
        for (auto& book : listOfBooks) {
            if (book.get_id() == bookId) {
                book.update_book_status(status);
                cout << "Book status updated for: " << book.get_title() << endl;
                return;
            }
        }
    }

    Book* search(int bookId) {
        for (auto& book : listOfBooks) {
            if (book.get_id() == bookId) {
                return &book;
            }
        }
        return nullptr;
    }

    void display() {
        cout << "Displaying all books in the library:" << endl;
        for (auto& book : listOfBooks) {
            book.display_book();
        }
    }
};

// Customer Class
class Customer {
private:
    string username;
    string password;

public:
    void login(string userName, string pass) {
        if (userName == username && pass == password) {
            cout << "Customer login successful!" << endl;
        } else {
            cout << "Invalid customer credentials!" << endl;
        }
    }

    void check_account() {
        cout << "Customer details: " << endl;
        cout << "Username: " << username << endl;
    }

    void search_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book) {
            book->display_book();
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void issue_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book && book->get_status()) {
            book->update_book_status(false);
            cout << "Book issued successfully!" << endl;
        } else {
            cout << "Book is either not available or already issued." << endl;
        }
    }

    void return_book(LibraryDatabase& db, int bookId) {
        Book* book = db.search(bookId);
        if (book && !book->get_status()) {
            book->update_book_status(true);
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "This book was not issued." << endl;
        }
    }

    void reverse_book(LibraryDatabase& db, int bookId) {
        cout << "Reversing operation for book ID: " << bookId << endl;
    }

    void logout() {
        cout << "Logged out!" << endl;
    }
};

// Librarian Class
class Librarian {
private:
    int id;
    string name;

public:
    void add_book(LibraryDatabase& db, Book book) {
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
};

int main() {
    LibraryManagementSystem lms;

    Book book1(1, "C++ Programming", "Programming", "Bjarne Stroustrup");
    Book book2(2, "Data Structures", "Computer Science", "Robert Sedgewick");
    Book book3(3, "Discrete Mathematics", "Mathematics", "K Ramnath");
    Book book4(4, "Statistics and Queuing Theory", "Mathematics", "S C Kapoor");
    Book book5(5, "Algorithmn Designs", "Computer Science", "Ananya Singh");
    Book book6(6, "Java Programming", "Computer Science", "Kkavya Goyal");
    Book book7(7, "Python Programming", "Computer Science", "Divyanshu Mohapatra");
    Book book8(8, "Cloud Computing", "Computer Science", "Mrutyunjaya Satapathy");
    Book book9(9, "Mangerial Economics", "Management", "Shanshank Thapliyal");
    Book book10(10, "Internet of Things", "Web Development", "Anmol Painuly");
    Book book11(11, "Computer Networks", "Computer Networks", "Praveer Kumar Panda");

    LibraryDatabase db;

    db.add(book1);
    db.add(book2);
    db.add(book3);
    db.add(book4);
    db.add(book5);
    db.add(book6);
    db.add(book7);
    db.add(book8);
    db.add(book9);
    db.add(book10);
    db.add(book11);

    int x; 
    cout<<"Menu options: Choose the option number"<<endl;
    cout<<"1) Login into the Library System:"<<endl;
    cout<<"2) Display all the books in the Library:"<<endl;
    cout<<"3) Issue a book to the customer:"<<endl;
    cout<<"4) Librarian login: Open the menu for the Librarian"<<endl;
    cout<<"5) Return a book back:";
    cin>>x;
    switch(x){
        case 1: {
            Customer customer;
            string password, username;
            cout<<"Enter the username:";
            cin>>username;
            cout<<"Enter the password:";
            cin>>password;
            customer.login(username, password);
            break;
        }

        case 2: {
            db.display();
            break;
        }

        case 3:{
            int id;
            cout<<"Enter the id of the book to be issued:";
            cin>>id;
            Customer customer;
            customer.issue_book(db, id);
        }

        case 4:{
            int y;
            cout<<"Menu for the Librarian:"<<endl;
            cout<<"1) Add book to the library:"<<endl;
            cout<<"2) Remove book from the library:"<<endl;
            cout<<"3) Search the book in the librray:"<<endl;
            cin>>y;
            switch(y){
                case 1:{
                    Librarian librarian;
                    LibraryDatabase db;

                    int id;
                    string name, genre, author;
                    cout<<"Enter the ID for the book:"<<endl;
                    cin>>id;
                    cout<<"Enter the name of the book:"<<endl;
                    cin>>name;
                    cout<<"Enter the genre of the book:"<<endl;
                    cin>>genre;
                    cout<<"Enter the author of the book:"<<endl;
                    cin>>author;
                    librarian.add_book(db, Book(id, name, genre, author));
                    break;
                }
                case 2: {
                    int id;
                    cout<<"Enter the id of the book to be deleted:"<<endl;
                    break;
                }
                case 3: {
                    int id;
                    Librarian librarian;
                    LibraryDatabase db;
                    cout<<"Enter the id of the book to be searched:"<<endl;
                    cin>>id;
                    librarian.search_book(db, 1);
                    break;
                }
                default: {
                    cout<<"Invalid input!"<<endl;
                    break;
                }
            }
            break;
        }
        case 5:{
            Customer customer;
            LibraryDatabase db;
            int id;
            cout<<"Enter the id of the book to be returned:";
            cin>>id;
            customer.return_book(db, id);
            break;
        }
        default: {
            cout<<"invalid input! Re - enter the input";
            break;
        }
    }

    return 0;
}
