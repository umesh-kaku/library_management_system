#ifndef LIBRARYMANAGEMENTSYSTEM_H
#define LIBRARYMANAGEMENTSYSTEM_H
class LibraryManagementSystem {
private:
    int id;
    string name;
    string username;
    string password;
    string phoneNumber;
    string emailId;
public:
    LibraryManagementSystem();
    void create_account(int userId, string userName, string pass, string phone, string email);
    bool login(string userName, string pass);
    void logout();

};
#endif
