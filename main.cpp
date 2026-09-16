#include <iostream>
#include "Resource.h"
using namespace std;

int main() {
  int selection = 0;
  ResourceManager resourceManager;
  //load in file
  if (!resourceManager.loadResources("resource.txt")) {
    return 1;
  }

  while (selection != 9) {
    cout << "===== Campus Resource Reservation System =====" << endl;
    cout << endl;
    cout << " 1. View Resources" << endl;
    cout << " 2. Create Reservation" << endl;
    cout << " 3. Cancel Reservation" << endl;
    cout << " 4. View Waiting Lists" << endl;
    cout << " 5. Undo Cancellation" << endl;
    cout << " 6. Search Reservations" << endl;
    cout << " 7. Sort Resources" << endl;
    cout << " 8. Generate Report" << endl;
    cout << " 9. Exit" << endl;

    //input selection
    cout << "Enter choice: ";
    cin >> selection;
    cout << endl;
    if (selection == 1) {
      resourceManager.displayResources();
    }
    else if (selection == 2) {
      
    }
    else if (selection == 3) {
      
    }
    else if (selection == 4) {
      
    }
    else if (selection == 5) {
      
    }
    else if (selection == 6) {
      
    }
    else if (selection == 7) {
      
    }
    else if (selection == 8) {
      
    }
    else {
      
    }
  }
return 0;
}
