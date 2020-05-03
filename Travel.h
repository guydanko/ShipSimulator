/*Data structure to control flow of a specific travel of a ship via ports*/
#ifndef SHIPGIT_TRAVEL_H
#define SHIPGIT_TRAVEL_H

#include <unordered_map>
#include <iostream>
#include "Container.h"
#include "Ship.h"
#include "ShipMap.h"

using std::tuple;
using std::string;
using std::unordered_map;
using std::list;
using std::get;

class Travel {
    unordered_map<string, tuple<int, int>> portCounter;
    shared_ptr<ShipMap> shipMap;
    list<string> route;
    string travelPath;
    string travelName;
    int shipPlanError = 0, routeError = 0;
public:

    Travel(const string &travelPath, const string &travelName, shared_ptr<ShipMap> ship,list<string> route, int routeError, int shipError);

    Travel(const Travel &other);

    shared_ptr<ShipMap> getShipMap() { return this->shipMap; }

    list<string>& getRoute() { return this->route; }

    string getTravelName() const;

    int getContainerList(const string &errorFile, list<shared_ptr<Container>> &contList);

    void goToNextPort();

    void setShipPlanError(int error) { this->shipPlanError = error; };

    void setRouteError(int error) { this->routeError = error; };

    int getShipPlanError() { return this->shipPlanError; };

    int getRouteError() { return this->routeError; };


    bool didTravelEnd() { return this->route.empty(); };

    int getCurrentVisitNumber() { return get<0>(this->portCounter.find(this->route.front())->second); }

    void errorsToFile(const string &fileName) const;

    const string &getTravelPath() { return this->travelPath; }

    const string getNextCargoFilePath();

    string getCurrentPort(){ return this->route.front();};

private:
    void increaseVisits(const string &port);

    tuple<int, int> getVisits(const string &port);

};

#endif //SHIPGIT_TRAVEL_H
