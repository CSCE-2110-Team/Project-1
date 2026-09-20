#ifndef RESERVE_H
#define RESERVE_H

#include <string>

class ReservationManager;

class Reservation {
private:
  ReservationManager* owner;
  int reserveId;
  int studentId;
  std::string studentName;
  std::string resourceId;
  std::string reserveDate;
  Reservation* next;
  Reservation* prev;
public:
  //Constructor.
  Reservation(int reserveId, int studentId, std::string studentName, std::string resourceId, std::string reserveDate);

  //Getter Setter methods for next.
  Reservation* getNext() const;
  void setNext(Reservation* next);

  //Getter Setter methods for prev.
  Reservation* getPrev() const;
  void setPrev(Reservation* prev);

  //Getter setter for ownership, helps prevent mishandling.
  ReservationManager* getOwner() const;
  void setOwner(ReservationManager* owner);

  //Getters for reservation values.
  int getReserveId() const;
  int getStudentId() const;
  std::string getStudentName() const;
  std::string getResourceId() const;
  std::string getReserveDate() const;
};
#endif
