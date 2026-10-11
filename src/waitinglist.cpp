#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include "waitinglist.h"

using namespace std;

// Each resource has its own waiting-list queue.
unordered_map<string, queue<ResourceWaitlist>> waitingLists;

// Cancellation history stack.
stack<CancelledReservation> cancellationHistory;


// =====================================================
// WAITING LIST
// =====================================================

void addToWaitingList(ResourceWaitlist r)
{
    waitingLists[r.room].push(r);

    cout << r.studentName
         << " added to the waiting list for resource "
         << r.room << "." << endl;
}


bool removeFromWaitingList(
    const string& resourceId,
    const string& date,
    ResourceWaitlist& r)
{
    auto it = waitingLists.find(resourceId);

    if (it == waitingLists.end() || it->second.empty())
    {
        return false;
    }

    queue<ResourceWaitlist>& q = it->second;

    queue<ResourceWaitlist> temp;
    bool found = false;

    while (!q.empty())
    {
        ResourceWaitlist current = q.front();
        q.pop();

        if (!found && current.date == date)
        {
            r = current;
            found = true;
        }
        else
        {
            temp.push(current);
        }
    }

    q = temp;

    return found;
}


void displayWaitingList()
{
    bool anyWaiting = false;

    cout << "\n===== WAITING LISTS =====" << endl;

    for (auto& pair : waitingLists)
    {
        const string& resourceId = pair.first;
        queue<ResourceWaitlist> q = pair.second;

        if (q.empty())
            continue;

        anyWaiting = true;

        cout << "\nResource: " << resourceId << endl;

        while (!q.empty())
        {
            ResourceWaitlist r = q.front();

            cout << r.reservationID << " | "
                 << r.studentID << " | "
                 << r.studentName << " | "
                 << r.room << " | "
                 << r.date << endl;

            q.pop();
        }
    }

    if (!anyWaiting)
    {
        cout << "Waiting lists are empty." << endl;
    }
}

void displayWaitingListStatistics() {
    cout << "\n===== WAITING-LIST STATISTICS =====" << endl;
    cout << "Resource ID | Students Waiting" << endl;
    cout << "-------------------------------" << endl;

    if (waitingLists.empty())
    {
        cout << "No waiting-list data available." << endl;
        return;
    }

    for (const auto& pair : waitingLists)
    {
        const string& resourceId = pair.first;
        const queue<ResourceWaitlist>& q = pair.second;

        cout << resourceId << " | "
             << q.size() << endl;
    }
}

// =====================================================
// CANCELLATION HISTORY STACK
// =====================================================

void cancelReservation(CancelledReservation r)
{
    cancellationHistory.push(r);

    cout << r.studentName
         << "'s reservation was cancelled." << endl;
}


bool hasCancelledReservations()
{
    return !cancellationHistory.empty();
}


CancelledReservation popCancelled()
{
    CancelledReservation r = cancellationHistory.top();
    cancellationHistory.pop();

    return r;
}


void displayCancellationHistory()
{
    if (cancellationHistory.empty())
    {
        cout << "Cancellation history is empty." << endl;
        return;
    }

    stack<CancelledReservation> temp = cancellationHistory;

    cout << "\n===== CANCELLATION HISTORY =====" << endl;

    while (!temp.empty())
    {
        CancelledReservation r = temp.top();

        cout << r.reservationID << " | "
             << r.studentID << " | "
             << r.studentName << " | "
             << r.room << " | "
             << r.date << endl;

        temp.pop();
    }
}
