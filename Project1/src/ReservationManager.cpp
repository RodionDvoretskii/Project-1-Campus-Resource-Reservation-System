#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>


void ReservationManager::createReservation()
{
    int ReservationID, StudentID;
    string ResourceID, Name, ReservationDate;

    cout << "Enter Reservation ID: ";
    cin >> ReservationID;
    cout << "Enter Student ID: ";
    cin >> StudentID;
    cout << "Enter";
    cin.ignore();
    getline(cin, ResourceID);
    getline(cin, Name);
    getline(cin, ResevationDate);

    Reservation reservation(ReservationID, StudentID, ResourceID, Name, ReservationDate);

    reservations.insertReservation(reservation);
}


bool ReservationManager::loadFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	
	if (fin.fail())
	{
		cout << "File error" << endl;
		return false; // error of file-reading
	}

	int ReservationID, StudentID;
    string Name, ResourceID, ReservationDate;
	while (getline(fin, ReservationID, '|'))
	{
		getline(fin, StudentID, '|'); // reads until '|' excluding this character
		getline(fin, Name, '|');
        getline(fin, ResourceID, '|');
		getline(fin, ReservationDate); // read until enter/space
		
		Reservation reservation(ReservationID, StudentID, ResourceID, Name, ReservationDate);
		reservations.insertReservation(reservation); // added a new reservation into ReservationList (linked-list)
	}
	
	// close resources
	fin.close();
	// successful reading
	return true;
}


void ReservationList::displayReservationbyID(int reservationID) const
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data.get_ReservationID() == reservationID)
        {
            cout << "Reservation is found by reservation ID: " << endl;
            cout << "Reservation ID: " << current->data.get_ReservationID() << endl;
            cout << "Student ID: " << current->data.get_StudentID() << endl;
            cout << "Name: " << current->data.get_Name() << endl;
            cout << "Resource ID: " << current->data.get_ResourceID() << endl;
            cout << "Reservation Date: " << current->data.get_ReservationDate() << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }
    cout << "Not found." << endl;
}

void ReservationList::displayReservationbyStudentName(string Name) const
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data.get_Name() == Name)
        {
            cout << "Reservation is found by name of the student: " << endl;
            cout << "Reservation ID: " << current->data.get_ReservationID() << endl;
            cout << "Student ID: " << current->data.get_StudentID() << endl;
            cout << "Name: " << current->data.get_Name() << endl;
            cout << "Resource ID: " << current->data.get_ResourceID() << endl;
            cout << "Reservation Date: " << current->data.get_ReservationDate() << endl;
            cout << endl;
            return;
        }
        current = current->next;
    }
    cout << "Not found." << endl;
}

// returns size of the list of reservations
int ReservationManager::getSize() const
{
	return resources.getCount();
}




