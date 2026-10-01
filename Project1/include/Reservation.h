#ifndef RESERVATION_H // header guard
#define RESERVATION_H


#include <string>
using namespace std;

class Reservation
{
    private:
        // attributes/fields
        int ReservationID;
        int StudentID;
        string ResourceID;
        string Name;
        string ReservationDate;

    public:
        // Default constructor
        Reservation();       
        
        // fully parametrized construtor
        Reservation(int ReservationID, int StudentID, string ResourceID, string Name, string ReservationDate); 

        // getters/accessors
        int get_ReservationID() const;
        int get_StudentID() const;
        string get_ResourceID() const;
        string get_Name() const;
        string get_ReservationDate() const;
        
        // setters/mutators
        void set_ReservationID(int ReservationID);
        void set_StudentID(int StudentID);
        void set_ResourceID(string ResourceID);
        void set_Name(string Name);
        void set_ReservationDate(string ReservationDate);
};


#endif