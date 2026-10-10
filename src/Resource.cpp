#include "Resource.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

bool ResourceManager::loadResources(const string &filename) {
  //checks if file is there and able to be opened. Program stops if unable to open the file.
  ifstream inputFile(filename);
  if (!inputFile) {
    cout << "Unable to open resource file: " << filename << endl;
    return false;
  }
  resources.clear(); //clears the current resources in the resource vector. prevents duplicates if the file is loaded multiple times
  string line; //used to go through the file one line at a time
  while (getline(inputFile, line)) //whole line from the file is read and put into line from above
{
  if (line.empty()) {
    continue;//skip any blank lines there might be
  }
  stringstream lineStream(line);//helps split line so they can be added seperatly
  Resource resource;
  //reads into struct based on positiions between pipe
  getline(lineStream, resource.id, '|');
  getline(lineStream, resource.name, '|');
  getline(lineStream, resource.type, '|');
  getline(lineStream, resource.availabilityStatus, '|');

  //verifies that every line in the struct has a value, and all must be true for it to be added to the vector
  if (!resource.id.empty() && !resource.name.empty() && !resource.type.empty() && !resource.availabilityStatus.empty()) {
    resources.push_back(resource);
  }
}
  return true; //output of the boolean function
}

  void ResourceManager::displayResources() const {
    if (resources.empty()) //if there is no resouces in the file to add to the vector
{
      cout << "No resources are available." << endl;
      return;//exits the function if true
}

    cout << "ID | Name | Type | Availability Status" << endl;
    for (int i = 0; i < static_cast<int>(resources.size()); i++) {
      //for loop that prints resources in the same forat as the input file.
      //static_cast<int> used to get rid of compiler warning
      cout << resources[i].id << " | " << resources[i].name << " | " << resources[i].type << " | " << resources[i].availabilityStatus << endl;
    }
  }

  void ResourceManager::displayAvailability(const string &resourceId) const {
    //searches for the resource with the matching ID and prints if it is available
    for (int i = 0; i < static_cast<int>(resources.size()); i++) {
      if (resources[i].id == resourceId) {
        cout << "That resource is " << resources[i].availabilityStatus << endl;
        return; //stops searching for the resource once it is found. O(n)
      }
    }
    cout << "Resource " << resourceId << " was not found." << endl; //if resourceId not in the vector. worst case scenario
  }  
  
  void mergeSortResources(vector<Resources> &items, vector<Resource> &temporary, int begin, int end) {
    if (end - begin < 2){
      //no need to sort a vector with one item or less
      return;
    }

    int middle = begin + (end - begin) / 2;//finds middle then splits. Sorts down until each temp vector has oen resource.
    mergeSortResources(items, temporary, begin, middle);
    mergeSortResources(items, temporary, middle, end);
    int left = begin;
    int right = middle;
    int output = begin;

    while (left < middle && right < end) {
      if (items[left].name <= items[right].name){
        //compares the split names and whichever alphabetically comes first goes into the vector first.
        temporary[output++] = items[left++];//if names are equal the left is inserted first.
      }
//finish the merge code for temp vector and add in sorted temp to the proper index
