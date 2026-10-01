#include "ReservationList.h"
#include <iostream>
#include <iomanip>


ReservationList::ReservationList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}


// deletes all elements when the list is destroyed
ReservationList::~ReservationList()
{
	Node* current = head;
	while (current != nullptr)
	{
		// remember the next one BEFORE deleting
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void ReservationList::insertReservation(Reservation r)
{
	// Node constructor stores r and sets next = NULL
	Node* newNode = new Node(r);
	
	// empty list: the new node is both first and last
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		// attach after the last node
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}


bool ReservationList::removeReservationByID(int reservationID, Reservation& removed)
{
	Node* previous = nullptr;
	Node* current = head;
	
	// walk through the list until we find the ID
	while (current != nullptr && current->data.get_ReservationID() != reservationID)
	{
		previous = current;
		current = current->next;
	}
	
	// reached the end: not found
	if (current == nullptr)
	{
		return false;
	}
	
	// give the removed reservation back (it goes to the stack)
	removed = current->data;
	
	// removing the first node
	if (previous == nullptr)
	{
		head = current->next;
	}
	else
	{
		// skip over the node
		previous->next = current->next;
	}
	
	// removed the last node: move tail back
	if (current == tail)
	{
		tail = previous;
	}
	
	delete current;
	count--;
	return true;
}

bool ReservationList::removeReservationByName(string name, Reservation& removed)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data.get_Name() == name)
        {
            return removeReservationByID(current->data.get_ReservationID(), removed);
        }
        current = current->next;
    }
    return false;
}

bool ReservationList::findReservation(int reservationID) const
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data.get_ReservationID() == reservationID)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}


int ReservationList::getCount() const
{
	return count;
}


void ReservationList::viewCurrentReservations() const
{
	if (head == nullptr)
	{
		cout << "No active reservations." << endl;
		return;
	}
	
	cout << "====== Reservations' Info: =====" << endl;
	
	Node* current = head;
	while (current != nullptr)
	{
        cout << "Reservation ID: " << current->data.get_ReservationID() << endl;
        cout << "Student ID: " << current->data.get_StudentID() << endl;
        cout << "Name: " << current->data.get_Name() << endl;
        cout << "Resource ID: " << current->data.get_ResourceID() << endl;
        cout << "Reservation Date: " << current->data.get_ReservationDate() << endl;
		current = current->next;
        cout << "_____________________________________________________" << endl;
	}
	cout << endl;
}