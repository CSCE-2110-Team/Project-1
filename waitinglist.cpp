#include <iostream>
#include <queue>
#include <stack>
#include "waitinglist.h"

using namespace std;

queue<Reservation> waitingList;
stack<Reservation> cancellationHistory;

void addToWaitingList(Reservation r) {
    waitingList.push(r);

    cout << r.studentName << " added to waiting list." << endl;
}

void removeFromWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    Reservation r = waitingList.front();
    waitingList.pop();

    cout << r.studentName << " removed from waiting list." << endl;
}

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

void cancelReservation(Reservation r) {
    cancellationHistory.push(r);

    cout << r.studentName << "'s reservation was cancelled." << endl;
}

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
