#include <iostream>
#include <queue>
#include <stack>
#include "waitinglist.h"

using namespace std;

queue<ResourceWaitlist> waitingList;
stack<CancelledReservation> cancellationHistory;

void addToWaitingList(ResourceWaitlist r) {
    waitingList.push(r);

    cout << r.studentName << " added to waiting list." << endl;
}

void removeFromWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    ResourceWaitlist r = waitingList.front();
    waitingList.pop();

    cout << r.studentName << " removed from waiting list." << endl;
}

void displayWaitingList() {
    if (waitingList.empty()) {
        cout << "Waiting list is empty." << endl;
        return;
    }

    queue<ResourceWaitlist> temp = waitingList;

    cout << "\nWaiting List:" << endl;

    while (!temp.empty()) {
        ResourceWaitlist r = temp.front();

        cout << r.reservationID << " | "
             << r.studentID << " | "
             << r.studentName << " | "
             << r.room << " | "
             << r.date << endl;

        temp.pop();
    }
}

void cancelReservation(CancelledReservation r) {
    cancellationHistory.push(r);

    cout << r.studentName << "'s  was cancelled." << endl;
}

bool hasCancelledReservations() {
    if(cancellationHistory.empty()) {
        return false;
    }
    else {
        return true;
    }
}

CancelledReservation popCancelled() {
    CancelledReservation r = cancellationHistory.top();
    cancellationHistory.pop();
    return r;
}

void displayCancellationHistory() {
    if (cancellationHistory.empty()) {
        cout << "Cancellation history is empty." << endl;
        return;
    }

    stack<CancelledReservation> temp = cancellationHistory;

    cout << "\nCancellation History:" << endl;

    while (!temp.empty()) {
        CancelledReservation r = temp.top();

        cout << r.reservationID << " | "
             << r.studentID << " | "
             << r.studentName << " | "
             << r.room << " | "
             << r.date << endl;

        temp.pop();
    }
}
