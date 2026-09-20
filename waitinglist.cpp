#include <iostream>
#include <queue>
#include <stack>
#include "waitinglist.h"

using namespace std;

// Queue for waiting list
queue<Reservation> waitingList;

// Stack for cancellation history
stack<Reservation> cancellationHistory;

// Adding student to waiting list
void addToWaitingList(Reservation r) {
    waitingList.push(r);

    cout << r.studentName << " added to waiting list." << endl;
}

// Remove student from waiting list
void removeFromWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    Reservation r = waitingList.front();
    waitingList.pop();

    cout << r.studentName << " removed from waiting list." << endl;
}

// Display waiting list
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

// Restore most recently cancelled reservation
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
