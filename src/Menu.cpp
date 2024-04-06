#include "Menu.h"

#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "City.h"

using namespace std;

// -------------------- Constructor -------------------- //

Menu::Menu() {
    setUpMenu();
}

// ----------------------- SetUp ----------------------- //

void Menu::setUpMenu() {
    int input;

    setUpPrinter(0);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 1:
                network.createNetwork(dataPath, true);
                mainMenu(true);
                return;
            case 2:
                dataPath = "../data/large/";
                network.createNetwork(dataPath, false);
                mainMenu(true);
                return;
            case 3:
                setUpCustom();
                network.createNetwork(dataPath, false);
                mainMenu(true);
                return;
            default:
                cout << endl << "   Please select a valid option: ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option: ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::setUpCustom() {
    string input;

    cout << endl << "   Please enter the data set's path: ";

    getline(cin >> ws, input);

    do {
        if (input.back() != '/')
            input.push_back('/');
        replace(input.begin(), input.end(), '\\', '/');
        ifstream testNetwork(input + "Cities.csv");
        if (testNetwork.good()) {
            dataPath = input; return;
        }
        cout << endl << "   Please enter a valid path: ";
        getline(cin >> ws, input);
    }
    while(true);
}

void Menu::setUpPrinter(int flag) {
    system("clear || cls");
    switch (flag) {
        case 0:
            cout << endl
                 << "   Please select the data set:" << endl << endl
                 << "     1. Small Data Set" << endl << endl
                 << "     2. Large Data Set" << endl << endl
                 << "     3. Custom Data Set" << endl << endl
                 << "   Select your option: ";
            break;
        /*
        case 1:
            system("clear || cls");
            cout << endl
                 << "   Please select the desired train prices:" << endl << endl
                 << "     1. Default prices" << endl << endl
                 << "     2. Custom prices" << endl << endl
                 << "   Select your option: ";
            break;
        case 2:
            system("clear || cls");
            cout << endl << "   -> Train Prices <-" << endl
                 << endl << "   STANDARD service : ";
            break;
        case 3:
            cout << endl << "   ALFA PENDULAR service : ";
            break;
        case 4:
            system("clear || cls");
            cout << endl
                 << "   Please select how you want to create the new sub railway:" << endl << endl
                 << "     1. Use the full railway" << endl << endl
                 << "     2. Random generate using a seed" << endl << endl
                 << "     3. Pick connections to remove" << endl << endl
                 << "   Select your option: ";
            break;
        */
        default:
            throw invalid_argument("Invalid option selected.");
    }
}

// --------------------- Main Menu --------------------- //

void Menu::mainMenu(bool isLoading) {
    int input;

    mainMenuOptions(isLoading);

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                basicServiceMenu();
                return;
            case 2:
                //lineFailuresMenu();
                return;
            case 9:
                if (confirmChoice()) setUpMenu();
                else mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::mainMenuOptions(bool isLoading) {
    system("clear || cls");
    if (isLoading) {
        cout << endl
             << "   Water Supply Manager                     A.Neves | L.Cunha | V.Castro" << endl
             << "   ---------------------------------------------------------------------" << endl;
    }
    else
        cout << endl
             << "   Main Menu" << endl
             << "   ---------------------------------------------------------------------" << endl;

    cout << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Basic Service Metrics" << endl << endl
         << "     2. Reliability and Sensitivity to Failures" << endl << endl << endl
         << "     9. Change Data Set" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

// ------------------- Basic Service ------------------- //

void Menu::basicServiceMenu() {
    int input;

    basicServiceMenuPrinter();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                basicMaxFlowMenu();
                return;
            case 2:
                basicWaterDemand();
                return;
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::basicServiceMenuPrinter() {
    system("clear || cls");
    cout << endl
         << "   Basic Service Metrics" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Network Max Flow" << endl << endl
         << "     2. Cities Water Demand" << endl << endl << endl
         << "     9. Go back" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::basicMaxFlowMenu() {
    int input;

    basicMaxFlowMenuPrinter();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                basicMaxFlowAll();
                return;
            case 2:
                basicMaxFlowSingle();
                return;
            case 9:
                basicServiceMenu();
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::basicMaxFlowMenuPrinter() {
    system("clear || cls");
    cout << endl
         << "   Max Flow" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. View all data" << endl << endl
         << "     2. Select a specific city" << endl << endl << endl
         << "     9. Go back" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::basicMaxFlowAll() {
    int maxFlow = network.edmondsKarp(network.getSuperSrc(), network.getSuperSink());

    system("clear || cls");
    cout << endl
         << "   | NETWORK MAX FLOW |" << endl << endl;

    for (City* city : network.getCitySet())
        cout << "   " << city->getCode() << " | " << city->getName() << " -> " << city->getCapacityValue() - city->getCapacity() << endl << endl;

    cout << "   TOTAL NETWORK FLOW: " << maxFlow << endl << endl;

    pressEnterToReturn();
    basicMaxFlowMenu();
}

void Menu::basicMaxFlowSingle() {
    network.edmondsKarp(network.getSuperSrc(), network.getSuperSink());

    City* city = receiveCity();

    cout << endl
         << "   ! FOUND !" << endl << endl
         << "   " << city->getCode() << " | " << city->getName() << " -> " << city->getCapacityValue() - city->getCapacity() << endl << endl;

    pressEnterToReturn();
    basicMaxFlowMenu();
}

void Menu::basicWaterDemand() {
    network.edmondsKarp(network.getSuperSrc(), network.getSuperSink());

    system("clear || cls");
    cout << endl
         << "   | NETWORK WATER DEMAND |" << endl << endl;

    for (City* city : network.getCitySet())
    {
        if (city->getCapacity() != 0)
        {
            cout << "   " << city->getCode() << " | " << city->getName() << endl
                 << "     Demand: " << int(city->getDemand()) << endl
                 << "     Actual Flow: " << city->getCapacityValue() - city->getCapacity() << endl
                 << "     Deficit: " << city->getCapacity() << endl << endl;
        }
    }

    pressEnterToReturn();
    basicServiceMenu();
}

// ------------------- Line Failures ------------------- //

/*

void Menu::lineFailuresMenu() {
    int input;

    lineFailuresMenuPrinter();

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 0:
                return;
            case 1:
                failuresRemoveReservoir();
                return;
            case 2:
                failuresRemoveStation();
                return;
            case 3:
                failuresRemovePipes();
            case 9:
                mainMenu(false);
                return;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::lineFailuresMenuPrinter() {
    system("clear || cls");
    cout << endl
         << "   Reliability and Sensitivity to Line Failures" << endl
         << "   ---------------------------------------------------------------------" << endl
         << "   Please select your desired option by typing it on the selector intake" << endl << endl
         << "     1. Remove Reservoirs" << endl << endl
         << "     2. Remove Stations" << endl << endl
         << "     3. Remove Pipes" << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::failuresRemoveReservoir() {
    Node* source = receiveNode(true);
    Node* destination = receiveNode(false);
    unsigned int maxFlow = subNetwork.edmondsKarp(source, destination);

    system("clear || cls");
    cout << endl
         << "   | MAX NUMBER OF TRAINS IN A SEGMENT - REDUCED CONNECTIVITY |" << endl << endl;

    if (isStationOutputSafe(source))
        cout << "   SOURCE -> \"" << source->getName() << "\" station located in "
             << source->getMunicipality() << ", " << source->getDistrict() << "." << endl << endl;
    else
        cout << "   SOURCE -> \"" << source->getName() << "\" station." << endl << endl;

    if (isStationOutputSafe(destination))
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station located in "
             << destination->getMunicipality() << ", " << destination->getDistrict() << "." << endl << endl;
    else
        cout << "   DESTINATION -> \"" << destination->getName() << "\" station." << endl << endl;

    cout << endl << "   Considering the segment failures, the maximum number of trains that can" << endl
         << endl << "          simultaneously travel between these two specific stations is of " << maxFlow << "." << endl;

    pressEnterToReturn();
    lineFailuresMenu();
}

*/

// ----------------- Auxiliary Functions ---------------- //

City* Menu::receiveCity() {
    string input;
    Node* nodeptr;

    system("clear || cls");
    cout << endl << "   Please enter a valid city code : ";

    getline(cin >> ws, input);

    do {
        nodeptr = network.findNode(input);
        if (nodeptr != nullptr)
            return dynamic_cast<City *>(nodeptr);
        cout << endl << "   Please enter a valid station name : ";
        getline(cin >> ws, input);
    }
    while(true);
}

bool Menu::confirmChoice() {
    int input;

    cout << endl
         << "   -------------------------" << endl << endl
         << "   ! WARNING !" << endl << endl
         << "   You're about to change the data set!" << endl << endl
         << "     1. Confirm" << endl << endl
         << "     2. Go back" << endl << endl
         << "   Select your option : ";

    while (!(cin >> input)) {
        cout << endl << "   Please select a valid option : ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    do {
        switch (input) {
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << endl << "   Please select a valid option : ";
                while (!(cin >> input)) {
                    cout << endl << "   Please select a valid option : ";
                    cin.clear(); cin.ignore(10000, '\n');
                }
        }
    }
    while(true);
}

void Menu::pressEnterToReturn() {
    cout << endl << "   Press ENTER to return...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// -------------------- END OF FILE -------------------- //
