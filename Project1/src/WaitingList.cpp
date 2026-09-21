#include "WaitingList.h"

WaitingList::WaitingList()
{
    front = nullptr;
    rear = nullptr;
}

WaitingList::~WaitingList()
{
    while (front != nullptr)
    {
        WaitingNode* temp = front;
        front = front->next;
        delete temp;
    }

    rear = nullptr;
}

bool WaitingList::isEmpty()
{
    return front == nullptr;
}

void WaitingList::addStudent(int studentID, string studentName, string resourceID, string date)
{
    WaitingNode* newNode = new WaitingNode;

    newNode->studentID = studentID;
    newNode->studentName = studentName;
    newNode->resourceID = resourceID;
    newNode->date = date;
    newNode->next = nullptr;

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

WaitingNode WaitingList::removeStudent()
{
    if(front == nullptr)
    {
        cout << "Waiting list is empty." <<endl;
        return WaitingNode();
    }

    WaitingNode* temp = front;
    WaitingNode removedStudent = *temp;

    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;

    removedStudent.next = nullptr;
    return removedStudent;
}

void WaitingList::display()
{
    if(front == nullptr)
    {
        cout << "Waiting list is empty." << endl;
        return;
    }

    WaitingNode* current = front;

    while(current != nullptr)
    {
        cout << "Student ID: " << current->studentID << endl;
        cout << "Student Name: " << current->studentName << endl;
        cout << "Resource ID: " << current->resourceID << endl;
        cout << "Date: " << current->date << endl;

        current = current->next;
    }
}
