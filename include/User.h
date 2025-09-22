#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User {
    protected:
    int userId;
    string name;
    int age;
    string username;
    string password;
    string email;
    string phoneNumber;
    void    set_name(string name);
    void    set_age(int age);
    void    set_username(string username);
    void    set_password(string password);
    void    set_phone_number(string phoneNumber);
    void    set_email_address(string email);
    
    public:
    int     get_user_id();
    string  get_name();
    int     get_age();
    string  get_username();
    string  get_email();
    string  get_phone_number();
    User();
    User(int userId, string name, int age, string username, string password, string email, string phoneNumber);
    virtual ~User();
    bool checkPassword(string password);
};
#endif