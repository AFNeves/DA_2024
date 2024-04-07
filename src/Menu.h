#ifndef MENU_H
#define MENU_H

#include "Network.h"

class Menu {
public:

    /* Constructor */
    Menu();

    /* Set Up */
    void setUpMenu();
    void setUpCustom();

    /* Main Menu */
    void mainMenu(bool isLoading);
    static void mainMenuOptions(bool isLoading);

    /* Basic Service */
    void basicServiceMenu();
    void basicMaxFlowMenu();
    void basicMaxFlowAll();
    void basicMaxFlowSingle();
    void basicWaterDemand();
    static void basicServiceMenuPrinter();
    static void basicMaxFlowMenuPrinter();

    /* Line Failures */
    void lineFailuresMenu();
    void failuresRemoveStation();
    void failuresRemoveReservoir();
    void failuresRemovePipe();
    static void lineFailuresMenuPrinter();

    /* Auxiliary Functions */
    template<typename NodeType>
    NodeType* receiveNode(const std::string& type, bool network);
    static bool confirmChoice(int flag);
    static void pressEnterToReturn();
    static std::string getFilename();

private:

    Network network;
    Network subNetwork;
    std::string dataPath;

};

#endif //MENU_H
