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

void addToWaitingList(ResourceWaitlistn r);
void removeFromWaitingList();
void displayWaitingList();

void cancelReservation(CancelledReservation r);
bool hasCancelledReservations();
CancelledReservation popCancelled();
void displayCancellationHistory();

#endif
