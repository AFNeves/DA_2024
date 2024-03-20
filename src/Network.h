#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <unordered_map>

#include "Node.h"
#include "Reservoir.h"
#include "City.h"
#include "Station.h"

class Network {
public:

    /* Constructor */
    Network();

    /* Destructor */
    ~Network();

    /* Getters */
    const std::unordered_map<std::string, Node *> &getNodeSet() const;

    /* Setters */
    void setNodeSet(std::unordered_map<std::string, Node *> &nodeSet);

    /* Functions */
    int getNumNodes() const;
    Node *findNode(const std::string& nodeCode);
    bool addPipe(const std::string& src, const std::string& dest, int capacity);
    bool removePipe(const std::string& src, const std::string& dest);
    bool addNode(int id, const std::string& code);
    bool removeNode(int id, const std::string& code);

    /* Parsing */

    bool readStations(const std::string &fileLocation);
    bool readCities(const std::string &fileLocation);
    bool readReservoirs(const std::string &fileLocation);
    bool readPipes(const std::string &fileLocation);

    const std::vector<Reservoir>& getReservoirs() const;
    const std::vector<City>& getCities() const;
    const std::vector<Station>& getStations() const;
private:
    std::unordered_map<std::string, Node *> nodeSet;
    std::vector<Reservoir> reservoirs;
    std::vector<City> cities;
    std::vector<Station> stations;

};

#endif /* NETWORK_H */