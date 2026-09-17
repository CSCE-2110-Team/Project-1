#ifndef RESERVE_H
#define RESERVE_H

class Reservation {
private:
  int expieValue; //temporary. Remove after experimenting.
  Reservation* next; 
public:
  //Constructor. Defaults next to nullptr.
  Reservation();

  //Getter Setter methods for next.
  Reservation* getNext() const;
  void setNext(Reservation* next);

  //Getter for expieValue. No setter. Also temporary, seriously, remove me later.
  int getExpie() const;
};
#endif
