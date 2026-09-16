#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>
using namespace std;

//chose struct because it is public and allows class to access the data
struct Resource {
    string id;
    string name;
    string type;
    string availabilityStatus;
};

class ResourceManager {
public:
    bool loadResources(const string &filename);
    //loads the resources.txt file and stores  them in their vectors
    //used referenceso there is no unecessary copy made
    void displayResources() const;
    //displays data without changing it

private:
    vector<Resource> resources;
};
#endif
