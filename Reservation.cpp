#include "Reservation.h"

Reservation::Reservation() : expieValue(0), next(nullptr) {}

Reservation* Reservation::getNext() const
{
   return next;
}

void Reservation::setNext(Reservation* next)
{
  this->next = next;
}

int Reservation::getExpie() const
{
  return expieValue;
}
