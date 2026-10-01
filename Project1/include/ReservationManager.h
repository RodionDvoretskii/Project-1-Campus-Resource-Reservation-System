#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H


#include "ReservationList.h"
#include "Reservation.h"
#include "Resource.h"
#include <stack>


class ReservationManager
{
	public:
        void createReservation();

        void printInfo();


		bool loadFromFile(string fileName);
        
        // both are linear search
		void findReservationByID(int reservationID) const;
        void findReservationByStudentName(string Name) const;


        // FIXME
		int getCount() const;
		Resource& getResource(int index);
		bool setAvailability(string resourceID, string status);
		void displayAll() const;
		void displayAvailability() const;
	private:
		ReservationList reservations; // linked-list containing "reservations" with data type "Reservation"
        stack<Reservation> history; // cancellations
};


#endif