#include "../include/Notification.h"
#include <iostream>
#include <string>
using namespace std;
bool Notification::sent_notification() {
    cout << "Notification sent: " << content << endl;
    return true;
}

void Notification::set_notification_content(string message) {
    content = message;
}

void Notification::set_notification_date() {
    time_t now = time(0);
    char* dt = ctime(&now);
    createdOn = string(dt);
}