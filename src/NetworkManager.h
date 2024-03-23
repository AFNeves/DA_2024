// NetworkManager.h
#ifndef DA_2024_NETWORKMANAGER_H
#define DA_2024_NETWORKMANAGER_H

#include "Reservoir.h"
#include "City.h"
#include "Station.h"
#include "Network.h"
#include <vector>
#include <iostream>

class NetworkManager {
public:
    // Declaration of the function to determine the maximum amount of water that can reach each city
    void determineMaxFlowToCities(Network& network,
                                                  const std::vector<Reservoir>& reservoirs,
                                                  const std::vector<City>& cities,
                                                  const std::vector<Station>& stations);
};

#endif //DA_2024_NETWORKMANAGER_H
