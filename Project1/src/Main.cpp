#include "ResourceManager.h"
#include "ReservationManager.h"
#include <string>
#include <list>
#include <stack>

#include <iostream>
using namespace std;

void printHeader() // banner
{
	cout<<"+------------------------------------------------------+"<<endl;
	cout<<"|         Computer Science and Engineering             |"<<endl;
	cout<<"|    CSCE 2110 - Foundations of Data Structures        |"<<endl;
	cout<<"|     Rodion  rd0824   RodionDvoretskii@my.unt.edu     |"<<endl;
    cout<<"|     Arumit  ******   ArumitKumar@my.unt.edu          |"<<endl;
    cout<<"|     Vic     ves0058  VicScorgie@my.unt.edu           |"<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
    cout << endl;
}

void printMenu()
{
    cout << "====== Campus Resource Reservation System ======" << endl;
    cout << "1. View Resources" << endl;
    cout << "2. Create Reservation" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. View Waiting List" << endl;
    cout << "5. Undo Cancellation" << endl;
    cout << "6. Search Reservation" << endl;
    cout << "7. Sort Resources" << endl;
    cout << "8. Generate Report" << endl;
    cout << "9. Exit" << endl;
    cout << endl;
    cout<<"Select an option (1-9): ";
}


int main()
{
    printHeader();

    ResourceMananger resourceManager;
    ReservationManager reservationManager;

    string resourcesFile = "";
    string reservationsFile = "";

    resourceManager.readFromFile(resourcesFile);
    reservationManager.readFromFile(reservationsFile);

    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            resourceManager.viewResources();
        }
        else if (choice == 2)
        {
            reservationManager.createReservation();
        }
        else if (choice == 3)
        {
            int answer;
            cout << "How you want to cancel reservation? 1 - by ID, 2 - by studnet name: ";
            cin >> answer;

            string name;
            int reservationID;

            if (answer == 1)
            {
                Reservation removed;

                // by ID
                if (reservations.removeReservationByID(301, removed))
                {
                    history.push(removed);
                }
                else
                {
                    cout << "Not found." << endl;
                }
            }
            else if (answer == 2)
            {
                // by name
                if (reservations.removeReservationByName("Alice Smith", removed))
                {
                    history.push(removed);
                }
                else
                {
                    cout << "Not found." << endl;
                }
            }
            else
            {
                cout << "Wrong choice! Try again." << endl;
            }
        }
        else if (choice == 4)
        {

        }
        else if (choice == 5)
        {

        }
        else if (choice == 6)
        {

        }
        else if (choice == 7)
        {

        }
        else if (choice == 8)
        {

        }
        else
        {
            cout << "Thank you for using Campus Resource Reservation System!" << endl;
            break;
        }
    }


    Reservation *reserveptr;// creating a Reservation class pointer to store addressed of instances
    list<Reservation*>currentReservations; //This is a temp list to check if my
                                            // Reservation mangmemenr works!
                                            //also this is a doubly linked list!
    stack<Reservation*>cancellationStack;
    /*This is temp stack which will let us iterate over the stack withour loosing the original elements*/
    stack<Reservation*>tempstack = cancellationStack;


    while(true)
    {
        int choice = 0;
        cout << 
        cout << "===== Campus Resource Reservation System =====" << endl;

        cout << "1. Create reservations\n"
             << "2. Display active reservations\n"
             << "3. Cancel reservation\n"
             << "4. Restore the most recent cancelled reservation\n"
             << "5. Display cancellation history\n"
             <<"6. Exit" << endl;
        cin >> choice;

        if (choice == 1) // DONE
        {
            char validate;
            int ReservationID;
            int StudentID;
            string ResourceID;
            string Name;
            string ReservationDate;

            cout << "Enter the Reservation ID : " << endl;
            cin >> ReservationID;

            cout << "Enter the Student ID : " << endl;
            cin >> StudentID;

            cout << "Enter the Resource ID : " << endl;
            cin >> ResourceID;

            cin.ignore();

            cout << "Enter student Name : " << endl;
            getline(cin, Name);

            cout << "Enter the Reservation Date : " << endl;
            getline(cin, ReservationDate);

            cout << "Validate y/n?" << endl;
            cin >> validate;

            if (validate == 'y')
            {
                reserveptr = new Reservation(ReservationID,
                                              StudentID,
                                              ResourceID,
                                              Name,
                                              ReservationDate);
                //Here I'm storing pointer address to this object instance to the 
                //doubly linked list, in linked list it only contains the address\
                //not the data!
                currentReservations.push_back(reserveptr);
                cout<<"Size right now is "<< currentReservations.size()<<endl;
            }
            else{
                cout<<"please start over!"<<endl;
            }
        }

        if(choice == 2){ // DONE
            cout<<"Displaying Data below!"<<endl;

                for(auto ptr: currentReservations){
                        printInfo(ptr);
                }
        }
        if(choice == 3){ // DONE
            char cancel;
            cout<<"Do you want to cancel the most recent Reservation? y/n "<<endl;
            cin>>cancel;

            if(cancel == 'y'){
                cout<<"Cancelling reservation for : "<<currentReservations.back()->get_Name()<<endl;
                cancellationStack.push(currentReservations.back());
                currentReservations.pop_back();
            }
            else{
                cout<<"Try again"<<endl;
                continue;
            }
        }
        if(choice == 4){
            char cancel;
            cout<<"Do you want to restore the most recent cancelled Reservation? y/n "<<endl;
            cin>>cancel;
            if(cancellationStack.empty()){
                cout<<"Cancellation stack is empty right now!"<<endl;
            }
            if(cancel == 'y'){
                currentReservations.push_back(cancellationStack.top());
                cout<<"Success Student : "<<currentReservations.back()->get_Name()<<endl;
                cancellationStack.pop();
            }
            else{
                cout<<"Try again"<<endl;
                continue;
            }

        }
        if(choice == 5){
            cout<<"Displaying Cancellation history!"<<endl;
            tempstack = cancellationStack;
            if(tempstack.empty()){
                cout<<"Cancellation list is currently empty!"<<endl;
                continue;
            }
            
            while(!tempstack.empty()){
                Reservation* ptr = tempstack.top();
                printInfo(ptr);
                tempstack.pop();
            }
        }
        if(choice == 6){
            cout<<"Thank you for using this program!"<<endl;
            break;
        }
    }

    for(auto ptr : currentReservations){
        delete ptr;
    }
    currentReservations.clear();

}