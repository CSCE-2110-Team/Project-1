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

  // File Loader? I'm not quite sure, honestly.
  bool loadReservations(const std::string& filename);

  // UI functions
  void reservationDisplay();
  void reservationCreation();
  void reservationCancellation();
  void reservationSearch();

  // Adds a reservation at the pointer
  void addReserve(Reservation* reserve, Reservation* at);
  
  // Adds a reservation at the head.
  void addReserve(Reservation* reserve);
  
  // Removes a reservation at the head.
  void removeReserve();

  // Removes a reservation by pointer.
  void removeReserve(Reservation* reserve);

  // Finds a reservation based on reservation Id.
  Reservation* findReserve(int reserveId) const;

  // Validation stuffs
  Reservation* findReserve(std::string resourceId, std::string reserveDate, int reserveId) const;
  bool validateReserve(Reservation* reserve) const;

  // Getters for head/tail reservations.
  Reservation* getHead() const;
  Reservation* getTail() const;
};

#endif
