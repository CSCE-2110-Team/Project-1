#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <queue>
#include "Resource.h"

using namespace std;

void addToWaitingList(Reservation r);
void removeFromWaitingList();
void displayWaitingList();

#endif
