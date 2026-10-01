#include "Reservation.h"
#include <string>

// default constructor
Reservation::Reservation()
{
    ReservationID = 0;
    StudentID = 0;
    ResourceID = "";
    Name = "";
    ReservationDate = "";
}
                             
// parameterized constructor
Reservation::Reservation(int ReservationID, int StudentID, string ResourceID, string Name, string ReservationDate)
{
    this->ReservationID = ReservationID;
    this->StudentID = StudentID;
    this->ResourceID = ResourceID;
    this->Name = Name;
    this->ReservationDate = ReservationDate;
}
                                                                                                          
// getters/accessors
int Reservation::get_ReservationID() const
{
    return ReservationID;
}

int Reservation::get_StudentID() const
{
    return StudentID;
}

string Reservation::get_ResourceID() const
{
    return ResourceID;
}

string Reservation::get_Name() const
{
    return Name;
}

string Reservation::get_ReservationDate() const
{
    return ReservationDate;
}


// setters/mutators
void Reservation::set_ReservationID(int ReservationID)
{
    this->ReservationID = ReservationID;
}

void Reservation::set_StudentID(int StudentID)
{
    this->StudentID = StudentID;
}

void Reservation::set_ResourceID(string ResourceID)
{
    this->ResourceID = ResourceID;
}

void Reservation::set_Name(string Name)
{
    this->Name = Name;
}

void Reservation::set_ReservationDate(string ReservationDate)
{
    this->ReservationDate = ReservationDate;
}