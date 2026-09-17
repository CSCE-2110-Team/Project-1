#include "Reservation.h"
#include "Reservationmanager.h"

ReservationManager::ReservationManager() : head(nullptr), tail(nullptr), length(0) {}

void ReservationManager::addReserve(Reservation* reserve)
{
  //sets current head to be next after reserve.
  reserve->setNext(head);
  //set reserve's previous to be nullptr, just in case y'know?
  reserve->setPrev(nullptr);
  //sets reserve as the new head.
  head = reserve;
  //if there is no tail, the list is empty, set reserve to be the tail.
  //Otherwise, update the next's prev to be this new reserve.
  if (tail == nullptr)
    tail = reserve;
  else
    reserve->getNext()->setPrev(reserve);
  length++;
}

void ReservationManager::addReserve(Reservation* reserve, Reservation* at)
{
  //safety to ensure nullptr is redirected to the head.
  //bold to assume this makes it safe.
  if (at == nullptr)
  {
    addReserve(reserve);
    return;
  }

  //sets reserve's next to at's next and it's prev to at.
  reserve->setNext(at->getNext());
  reserve->setPrev(at);

  //set reserve to be the tail if next is a nullptr, otherwise set the next's prev to reserve.
  if (at->getNext() == nullptr)
    tail = reserve;
  else
    at->getNext()->setPrev(reserve);
  //sets reserve to be at's next. 
  at->setNext(reserve);
  length++;
}

void ReservationManager::removeReserve(Reservation* reserve)
{
  //if reserve is at the tail, set the tail to it's previous.
  //else, set the next's previous to reserve's previous.
  if(reserve->getNext() == nullptr)
    tail = reserve->getPrev();
  else
    reserve->getNext()->setPrev(reserve->getPrev());

  //if reserve is at the head, set the head to it's next.
  //else, set the previous' next to reserve's next.
  if(reserve->getPrev() == nullptr)
    head = reserve->getNext();
  else
    reserve->getPrev()->setNext(reserve->getNext());

  //cleans up reserve's pointers.
  reserve->setNext(nullptr);
  reserve->setPrev(nullptr);
  
  length--;
}

//SO TEMPORARY YOU WOULDN'T BELIEVE. Yeah, temporary.
Reservation* ReservationManager::findReserve(int expieValue)
{
  //Sets the current pointer being evaluated to be the head to initialize.
  Reservation* Evaluating = head;
  //Loop runs until it's given a null pointer, which should be at the end of the list.
  while (Evaluating != nullptr)
  {
    //if it matches, give us back the evaluating pointer.
    if (Evaluating->getExpie() == expieValue)
      return Evaluating;
    //else it moves the evaluation to the next pointer in the list. 
    Evaluating = Evaluating->getNext();
  }
  //if we got nothing, we got nothing.
  return nullptr;
}
