#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <string>

using namespace std;

struct Reservation {
    int reservationID;
    int studentID;
    string studentName;
    string room;
    string date;
};

void addToWaitingList(Reservation r);
void removeFromWaitingList();
void displayWaitingList();

void cancelReservation(Reservation r);
void restoreReservation();
void displayCancellationHistory();

#endif
