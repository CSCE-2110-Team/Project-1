#include "ReservationManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

ReservationManager::ReservationManager() : head(nullptr), tail(nullptr), length(0) {}

//credit to Robby, I lifted this code from his work and adjusted it for my own. All comments from here until I say otherwise are Robby's. -Wesley
bool ReservationManager::loadReservations(const string &filename) {
  //checks if file is there and able to be opened. Program stops if unable to open the file.
  ifstream inputFile(filename);
  if (!inputFile) {
    cout << "Unable to open reservation file: " << filename << endl;
    return false;
  }
  //resources.clear(); //clears the current resources in the resource vector. prevents duplicates if the file is loaded multiple times
  //I have nothing that mimics this, nor do I particularly think I need it either for reservations. -Wesley
  string line; //used to go through the file one line at a time
  while (getline(inputFile, line)) //whole line from the file is read and put into line from above
{
  if (line.empty()) {
    continue;//skip any blank lines there might be
  }
  stringstream lineStream(line);//helps split line so they can be added seperatly
  //Resource resource; Doesn't work how my reservations work. -Wesley 
  //reads into struct based on positiions between pipe
  string reserveId, studentId, studentName, resourceId, reserveDate; //Used to work with how reservations are handled. Jank, I know. -Wesley
  getline(lineStream, reserveId, '|');
  getline(lineStream, studentId, '|');
  getline(lineStream, studentName, '|');
  getline(lineStream, resourceId, '|');
  getline(lineStream, reserveDate, '|');
  
  Reservation* reserve = new Reservation(stoi(reserveId), stoi(studentId), studentName, resourceId, reserveDate);
  

  //verifies that every line in the struct has a value, and all must be true for it to be added to the vector
  //if (!resource.id.empty() && !resource.name.empty() && !resource.type.empty() && !resource.availabilityStatus.empty()) {
  //  resources.push_back(resource);
  //} This entire part isn't part of how my linked list works -Wesley

  //make sure there is no overlap in resource and date, or reservation Id. Student Id and Name can overlap.
  if (validateReserve(reserve))
  {
    delete reserve;
    continue;
  }
  
  this->addReserve(reserve);
}
  return true; //output of the boolean function
}
//That's all of the stuff I stole- er, I mean borrowed from Robby.

void ReservationManager::reservationDisplay()
{
  //initialize with the pointer to the first item in the linked list.
  Reservation* current = head;

  //loops through every item in the linked list and reports what its values are.
  while (current != nullptr)
  {
      cout << "Reservation " << current->getReserveId() << ", Student Id " << current->getStudentId() << ", Student Name " << current->getStudentName() << ", Resource Id " << current->getResourceId() << ", Reservation Date " << current->getReserveDate() << endl;
      current = current->getNext();
  }
}
void ReservationManager::reservationCreation()
{
  int reserveId;
  int studentId;
  string studentName;
  string resourceId;
  string reserveDate;

  //get all reservation information.
  cout << "Enter Reservation ID: ";
  cin >> reserveId;

  cout << "Enter Student ID: ";
  cin >> studentId;

  cin.ignore();

  cout << "Enter Student Name: ";
  getline(cin, studentName);

  cout << "Enter Resource ID: ";
  cin >> resourceId;

  cout << "Enter Reservation Date: ";
  cin >> reserveDate;

  //create reservation.
  Reservation* reserve = new Reservation(
    reserveId,
    studentId,
    studentName,
    resourceId,
    reserveDate
  );

  if (validateReserve(reserve))
  {
    cout << resourceId << " is already reserved for " << reserveDate << ", or you used a duplicate reservation Id." << endl;
    delete reserve;
    return;
  }
  
  addReserve(reserve);

  //report.
  cout << "Reservation created." << endl;
}

void ReservationManager::reservationCancellation()
{
  int reserveId;

  //Figure out what reservation the user wants to cancel. Or -1 to not do that.
  cout << "Enter Reservation ID to cancel (-1 to cancel): ";
  cin >> reserveId;
  
  if (reserveId == -1)
    return;

  Reservation* reserve = findReserve(reserveId);

  //Make sure the reservation actually exists.
  if (reserve == nullptr)
  {
    cout << "Reservation not found." << endl;
    return;
  }

  //eliminate the reservation with massive cruelty or something.
  removeReserve(reserve);

  //report
  cout << "Reservation cancelled." << endl;
}

void ReservationManager::reservationSearch()
{

  //find what the reservation the user wants to find. Or if they want the full list.
  int reserveId;
  
  cout << "Enter Reservation ID (-1 to cancel. -2 for a full list instead): ";
  cin >> reserveId;

  if (reserveId == -1)
    return;
  if (reserveId == -2)
  {
    reservationDisplay();
    return;
  }

  Reservation* reserve = findReserve(reserveId);

  //make sure the reservation actually was found.
  if (reserve == nullptr)
  {
    cout << "Reservation not found." << endl;
    return;
  }

  //spill all the details.
  cout <<
    "Reservation ID: " << reserve->getReserveId() << endl <<
    "Student ID: " << reserve->getStudentId() << endl <<
    "Student Name: " << reserve->getStudentName() << endl <<
    "Resource ID: " << reserve->getResourceId() << endl <<
    "Reservation Date: " << reserve->getReserveDate() << endl;
}

//returns 1 if it finds a conflict. Really it just translates nullptr to 1 and anything else to 0.
bool ReservationManager::validateReserve(Reservation* reserve) const
{
  return findReserve(reserve->getResourceId(), reserve->getReserveDate(), reserve->getReserveId()) != nullptr;
}

void ReservationManager::addReserve(Reservation* reserve)
{
  //don't feed it a nullptr. Duh. || And don't feed it a node that's already owned, dummy!
  if (reserve == nullptr || reserve->getOwner() != nullptr)
    return;
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
  reserve->setOwner(this);
  length++;
}

void ReservationManager::addReserve(Reservation* reserve, Reservation* at)
{
  //don't feed it a nullptr. Duh. || And don't feed it a node that's already owned, dummy! || AND don't try to add at a list that isn't this one! Silly!
  if (reserve == nullptr || reserve->getOwner() != nullptr || at != nullptr && at->getOwner() != this)
    return;
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
  reserve->setOwner(this);
  length++;
}

void ReservationManager::removeReserve()
{
  if (head == nullptr)
    return;
  removeReserve(head);
}

void ReservationManager::removeReserve(Reservation* reserve)
{
  //don't feed it a nullptr. Duh. || And don't feed it a node that's not yours, dummy!
  if (reserve == nullptr || reserve->getOwner() != this)
    return;
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
  reserve->setOwner(nullptr);
  
  length--;
}

//Turns out this wasn't temporary. Shifted to reserveId instead.
Reservation* ReservationManager::findReserve(int reserveId) const
{
  //Sets the current pointer being evaluated to be the head to initialize.
  Reservation* evaluating = head;
  //Loop runs until it's given a null pointer, which should be at the end of the list.
  while (evaluating != nullptr)
  {
    //if it matches, give us back the evaluating pointer.
    if (evaluating->getReserveId() == reserveId)
      return evaluating;
    //else it moves the evaluation to the next pointer in the list. 
    evaluating = evaluating->getNext();
  }
  //if we got nothing, we got nothing.
  return nullptr;
}

//findReserve variant for validation purposes to prevent scheduling conflicts.
Reservation* ReservationManager::findReserve(string resourceId, string reserveDate, int reserveId) const
{
  //Sets the current pointer being evaluated to be the head to initialize.
  Reservation* evaluating = head;
  //Loop runs until it's given a null pointer, which should be at the end of the list.
  while (evaluating != nullptr)
  {
    //if it matches, give us back the evaluating pointer.
    if ((evaluating->getResourceId() == resourceId && evaluating->getReserveDate() == reserveDate) || evaluating->getReserveId() == reserveId)
      return evaluating;
    //else it moves the evaluation to the next pointer in the list. 
    evaluating = evaluating->getNext();
  }
  //if we got nothing, we got nothing.
  return nullptr;
}

Reservation* ReservationManager::getHead() const
{
  return head;
}

Reservation* ReservationManager::getTail() const
{
  return tail;
}
