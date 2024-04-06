#ifndef MENU_H
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
    void basicMaxFlowMenu();
    void basicMaxFlowMenuPrinter();
    void basicMaxFlowAll();
    void basicMaxFlowSingle();
    void basicWaterDemand();

    /*
    void lineFailuresMenu();
    void lineFailuresMenuPrinter();
    void failuresRemoveStation();
    void failuresRemoveReservoirs();
    void failuresRemovePipes();
    */

    City* receiveCity();
    //static bool confirmChoice();
    static void pressEnterToReturn();

private:

    Network network;
    Network subNetwork;
    std::string dataPath;

};

#endif //MENU_H
