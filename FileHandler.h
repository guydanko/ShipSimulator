/*class that handles input and output of different data objects to files and vice versa*/
#include <string>
#include <list>
#include "Ship.h"
#include "CargoOperation.h"
#include "Container.h"
#include "SimulatorError.h"
#include <memory>
#include <unordered_map>

using std::list;
using std::string;
using std::shared_ptr;
using std::unordered_map;

#ifndef SHIPGIT_FILEHANDLER_H
#define SHIPGIT_FILEHANDLER_H

class FileHandler {

public:
    /*appends containers to list*/
    static int fileToContainerList(const string &fileName, list<shared_ptr<Container>> &containerList,
                                   const string &errorFile = "", const string& portName = "");

    static int fileToRouteList(const string &fileName, list<string> &route, const string &errorFile = "");

    /*returns null ptr if ship was not created*/

    static int
    createShipMapFromFile(const string &fileName, shared_ptr<shared_ptr<ShipMap>> ship, const string &errorFile = "");

    static list<shared_ptr<CargoOperation>>
    createCargoOpsFromFile(const string &fileName, list<shared_ptr<Container>> &containerList);

    static void operationsToFile(list<CargoOperation> operations, const string &fileName, const string &currentPort);

    /*returns empty list if invalid file or no legal containers*/

    static void
    simulatorErrorsToFile(const list<SimulatorError> &simErrors, const string &fileName, const string &travelName,
                          const string &portName = "", int visitNumber = 0,
                          const string &errorFile = "");

};

#endif //SHIPGIT_FILEHANDLER_H
