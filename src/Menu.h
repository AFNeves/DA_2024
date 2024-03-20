/*#ifndef MENU_H
#define MENU_H

#include "Network.h"

class Menu {
public:

    Menu();
    void setUpMenu();
    void setUpCustom();
    void setUpPrinter(int flag);
    void mainMenu(bool isLoading);
    void mainMenuOptions(bool isLoading);
    void basicServiceMenu();
    void basicServiceMenuPrinter();
    void basicMaxFlow();
    void basicWaterDemand();
    void basicMetrics();
    void lineFailuresMenu();
    void lineFailuresMenuPrinter();
    void failuresRemoveStation();
    void failuresRemoveReservoirs();
    void failuresRemovePipes();

private:

    Network network;
    Network subNetwork;
    std::string dataPath;

};

#endif //MENU_H*/