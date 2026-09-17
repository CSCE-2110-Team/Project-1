#include <iostream>
#include <string>
#include <string>
#include <queue>
using namespace std;

queue<string> waitinglist;
struct Reservation {
    int reservationID;
    int studentID;
    string studentName;
    string room;
    string date;
};

// Queue
queue<Reservation> waitingList;

// Stack for cancellation history
stack<Reservation> cancellationHistory;


// Adding
void addToWaitingList(Reservation r) {
    waitingList.push(r);

    cout << r.studentName << " added to waiting list." << endl;
}


// Remove student
void removeFromWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    Reservation r = waitingList.front();
    waitingList.pop();

    cout << r.studentName << " removed from waiting list." << endl;
}


// Display 
void displayWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    queue<Reservation> temp = waitingList;

    cout << "\nWaiting List:" << endl;

    while (!temp.empty()) {
        Reservation r = temp.front();

        cout << r.reservationID << " | "
             << r.studentID << " | "
             << r.studentName << " | "
             << r.room << " | "
             << r.date << endl;

        temp.pop();
    }
}


// Cancel reservation
void cancelReservation(Reservation r) {
    cancellationHistory.push(r);

    cout << r.studentName << "'s reservation was cancelled." << endl;
}


// Restore recently cancelled reservation
void restoreReservation() {
    if (cancellationHistory.empty()) {
        cout << "No cancelled reservations." << endl;
        return;
    }

    Reservation r = cancellationHistory.top();
    cancellationHistory.pop();

    cout << "Restored reservation:" << endl;

    cout << r.reservationID << " | "
         << r.studentID << " | "
         << r.studentName << " | "
         << r.room << " | "
         << r.date << endl;
}


// Display cancellation history
void displayCancellationHistory() {
    if (cancellationHistory.empty()) {
        cout << "Cancellation history is empty." << endl;
        return;
    }

    stack<Reservation> temp = cancellationHistory;

    cout << "\nCancellation History:" << endl;

    while (!temp.empty()) {
        Reservation r = temp.top();

        cout << r.reservationID << " | "
             << r.studentID << " | "
             << r.studentName << " | "
             << r.room << " | "
             << r.date << endl;

        temp.pop();
    }
}
