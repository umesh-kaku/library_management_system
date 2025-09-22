#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H
#include "LibraryDatabase.h"
#include "User.h"
#include <string>
using namespace std;
class LibraryManagementSystem {
private:
    LibraryDatabase* databaseObject;
    User* currentUser;
    bool isLoggedIn;
    void show_login_menu();
    void show_librarian_menu();
    void show_customer_menu();
public:
    LibraryManagementSystem(LibraryDatabase* databaseObject);
    void start_system();
    void login(const string& username, const string& password);
    void logout();
};
#endif
