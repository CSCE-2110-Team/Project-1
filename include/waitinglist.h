#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <string>

using namespace std;

struct ResourceWaitlist {
    int reservationID;
    int studentID;
    string studentName;
    string room;
    string date;
};

struct CancelledReservation {
    int reservationID;
    int studentID;
    string studentName;
    string room;
    string date;
};

// Waiting list
void addToWaitingList(ResourceWaitlist r);

bool removeFromWaitingList(
    const string& resourceId,
    const string& date,
    ResourceWaitlist& r
);

void displayWaitingList();


void displayWaitingListStatistics();

// Cancellation history
void cancelReservation(CancelledReservation r);
bool hasCancelledReservations();
CancelledReservation popCancelled();
void displayCancellationHistory();

#endif
