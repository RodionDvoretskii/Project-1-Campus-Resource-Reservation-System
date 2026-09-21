#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <string>

using namespace std;

struct WaitingNode
{
    int studentID;
    string studentName;
    string resourceID;
    string date;
    WaitingNode* next;
};

class WaitingList
{
private:
    WaitingNode* front;
    WaitingNode* rear;

public:
    WaitingList();
    ~WaitingList();

    bool isEmpty();

    void addStudent(int studentID, string studentName, string resourceID, string date);

    WaitingNode removeStudent();

    void display();
};

#endif
