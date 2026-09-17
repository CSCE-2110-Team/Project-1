#ifndef RESERVEMANAGER_H
#define RESERVEMANAGER_H
#include "Reservation.h"

class ReservationManager {
private:
  Reservation* head;
  Reservation* tail;
  int length;
public:
  // Constructor defaults to nullptr for head and tail while length defaults to 0.
  ReservationManager();

  // Adds a reservation at the pointer
  void addReserve(Reservation* reserve, Reservation* at);
  
  // Adds a reservation at the head.
  void addReserve(Reservation* reserve);
  
  // Removes a reservation at the head.
  void removeReserve();

  // Removes a reservation by pointer.
  void removeReserve(Reservation* reserve);

  // Finds a reservation based on expieValue, currently. Prone to change. For ctrl+f purposes, temporary.
  Reservation* findReserve(int expieValue);
};

#endif
