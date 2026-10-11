#include <iostream>
#include "Resource.h"
#include "ReservationManager.h"
#include "waitinglist.h"
using namespace std;

int main() {
  int selection = 0;
  int reportSelection = 0;
  ResourceManager resourceManager;
  //load in file
  if (!resourceManager.loadResources("data/resources.txt")) {
    return 1;
  }
  ReservationManager reservationManager;
  if (!reservationManager.loadReservations("data/reservations.txt"))
    return 1;

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
    cout << "10. View Cancellation History" << endl;

    //input selection
    cout << "Enter choice: ";
    cin >> selection;
    cout << endl;
    if (selection == 1) {
      resourceManager.displayResources();
    }
    else if (selection == 2) {
      reservationManager.reservationCreation();
    }
    else if (selection == 3) {
      reservationManager.reservationCancellation();
    }
    else if (selection == 4) {
      displayWaitingList();
    }
    else if (selection == 5) {
      reservationManager.reservationRestoration();
    }
    else if (selection == 6) {
      reservationManager.reservationSearch();
    }
    else if (selection == 7) {
      resourceManager.sortResources();
      resourceManager.displayResources();
    }
    else if (selection == 8) {
      cout << "Please select which report you would like to generate" << endl;
      cout << endl;
      cout << " 1. Active Reservations" << endl;
      cout << " 2. Resource Utilization" << endl;
      cout << " 3. Requested Resources" << endl;
      cout << " 4. Waiting List Statistics" << endl;
      cout << " 5. Main Menu" << endl;
      cout << "Enter choice" << endl;
      cin >> reportSelection;
      cout << endl;
      if (reportSelection == 1) {
        reservationManager.reservationDisplay();
      }
      else if (reportSelection == 2) {
        resourceManager.generateReport(reservationManager);
      }
      else if (reportSelection == 3) {
        resourceManager.displayReservedResources(reservationManager);
      }
      else if (reportSelection == 4) {
      displayWaitingListStatistics();
      }
      else if (reportSelection == 5) {
        cout << "Returning to main menu." << endl;
        continue;
      }
      else {
        cout << "Please make a valid selection" << endl;
      }
    }
    else if (selection == 9) {
      cout << "Exiting..." << endl;
    }
    else if (selection == 10) {
      displayCancellationHistory();
    }
    else {
    cout << "Invalid selection." << endl;
    }
  }
return 0;
}
