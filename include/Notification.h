#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <string>
#include <iostream>
using namespace std;

class Notification {
private:
    int notificationId;
    string createdOn;
    string content;  
public:
    bool sent_notification();
    void set_notification_content(string message);
    void set_notification_date();
};
#endif
