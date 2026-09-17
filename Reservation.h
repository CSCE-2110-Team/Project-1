#ifndef RESERVE_H
#define RESERVE_H

class Reservation {
private:
  int expieValue; //temporary. Remove after experimenting.
  Reservation* next;
  Reservation* prev;
public:
  //Constructor. Defaults next and prev to nullptr.
  Reservation();

  //Getter Setter methods for next.
  Reservation* getNext() const;
  void setNext(Reservation* next);

  //Getter Setter methods for prev.
  Reservation* getPrev() const;
  void getNext(Reservation* prev);

  //Getter for expieValue. No setter. Also temporary, seriously, remove me later.
  int getExpie() const;
};
#endif
