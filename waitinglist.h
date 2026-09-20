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
void restoreReservation();
void displayCancellationHistory();

#endif
