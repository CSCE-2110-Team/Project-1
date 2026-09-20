#include <iostream>
#include <stack>
#include <queue>
#include "waitinglist.h"
using namespace std;

queue<string> waitinglist;

// Queue
queue<Reservation> waitinglist;

// Stack for cancellation history
stack<Reservation> cancellationHistory;


// Adding
void addToWaitinglist(Reservation r) {
    waitinglist.push(r);

    cout << r.studentName << " added to waiting list." << endl;
}


// Remove student
void removeFromWaitinglist() {
    if (waitinglist.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    Reservation r = waitinglist.front();
    waitinglist.pop();

    cout << r.studentName << " removed from waiting list." << endl;
}


// Display 
void displayWaitinglist() {
    if (waitinglist.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    queue<Reservation> temp = waitinglist;

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
