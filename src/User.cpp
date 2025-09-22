#include <iostream>
#include <string>
#include "../include/User.h"
using namespace std;

void    User::set_name(string name) {
    this -> name = name;
}

void    User::set_age(int age) {
    this -> age = age;
}

void    User::set_username(string username) {
    this -> username = username;
}

void    User::set_password(string password) {
    this -> password = password;
}

void    User::set_phone_number(string phoneNumber) {
    this -> phoneNumber = phoneNumber;
}

void    User::set_email_address(string email) {
    this -> email = email;
}

int     User::get_user_id() {   return this -> userId;}
string  User::get_name()    {   return this -> name;}
int     User::get_age()     {   return this -> age;}
string  User::get_username(){   return this -> username;}
string  User::get_email()   {   return this -> email;}
string  User::get_phone_number() {  return this -> phoneNumber;}
User::User() {}
User::User(int userId, string name, int age, string username, string password, string email, string phoneNumber) {
    this -> userId = userId;
    this -> name = name;
    this -> age = age;
    this -> username = username;
    this -> password = password;
    this -> email = email;
    this -> phoneNumber =phoneNumber;
}
User::~User() {}
bool User::checkPassword(string password) {
    return this -> password == password;
}