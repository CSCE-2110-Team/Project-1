#ifndef RESERVE_H
#define RESERVE_H

class Reservation {
private:
  int expieValue; //temporary. Remove after experimenting.
  Reservation* next;
  Reservation* prev;
public:
  //Constructor. Defaults next and prev to nullptr. Expie value part is very temporary.
  Reservation(int Expievalue);

  //Getter Setter methods for next.
  Reservation* getNext() const;
  void setNext(Reservation* next);

  //Getter Setter methods for prev.
  Reservation* getPrev() const;
  void setPrev(Reservation* prev);

  //Getter for expieValue. No setter. Also temporary, seriously, remove me later.
  int getExpie() const;
};
#endif
