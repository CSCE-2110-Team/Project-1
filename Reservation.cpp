#include "Reservation.h"
using namespace std;

Reservation::Reservation(int reserveId, int studentId, string studentName, string resourceId, string reserveDate) : owner(nullptr), reserveId(reserveId), studentId(studentId), studentName(studentName), resourceId(resourceId), reserveDate(reserveDate), prev(nullptr), next(nullptr) {}

Reservation* Reservation::getNext() const
{
   return next;
}

//next/previous getter setters.

void Reservation::setNext(Reservation* next)
{
  this->next = next;
}

Reservation* Reservation::getPrev() const
{
   return prev;
}

void Reservation::setPrev(Reservation* prev)
{
  this->prev = prev;
}

//ownership getter setters.

ReservationManager* Reservation::getOwner() const
{
   return owner;
}

void Reservation::setOwner(ReservationManager* owner)
{
  this->owner = owner;
}


//Getters for reservation values

int Reservation::getReserveId() const
{
   return reserveId;
}

int Reservation::getStudentId() const
{
   return studentId;
}

string Reservation::getStudentName() const
{
   return studentName;
}

string Reservation::getResourceId() const
{
   return resourceId;
}

string Reservation::getReserveDate() const
{
   return reserveDate;
}
