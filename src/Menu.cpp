/*#include "Menu.h"

#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>

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
            case 0:
                return;
            case 1:
                dataPath = "../data/";
                network.createNetwork(dataPath);
                mainMenu(true);
                return;
            case 2:
                setUpCustom();
                network.createNetwork(dataPath);
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

    cout << endl << "   Please enter the data file's path: ";

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
    switch (flag) {
        case 0:
            cout << endl
                 << "   Please select the data file's location:" << endl << endl
                 << "     1. Data folder" << endl << endl
                 << "     2. Custom path" << endl << endl
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
            *//*
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
                lineFailuresMenu();
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
                basicMaxFlow();
                return;
            case 2:
                basicWaterDemand();
                return;
            case 3:
                basicMetrics();
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
         << "     1. Max Flow" << endl << endl
         << "     2. Water Demand" << endl << endl
         << "     3. Metrics" << endl << endl << endl
         << "     9. Return to Main Menu" << endl << endl
         << "     0. Exit application" << endl << endl
         << "   Select your option : ";
}

void Menu::basicMaxFlow() {
    Node* source = receiveNode(true);
    Node* destination = receiveNode(false);
    unsigned int maxFlow = network.edmondsKarp(source, destination);

    system("clear || cls");
    cout << endl
         << "   | MAX FLOW |" << endl << endl;

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

    cout << "   The maximum number of trains that can simultaneously travel between this two specific stations is of " << maxFlow << "." << endl;

    pressEnterToReturn();
    basicServiceMenu();
}

// ------------------- Line Failures ------------------- //

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

// ----------------- Auxiliar Functions ---------------- //

Node* Menu::receiveStation(bool type) {
    string input;
    Node* stationptr;

    system("clear || cls");

    if (type)
        cout << endl << "   -> SOURCE <-" << endl
             << endl << "   Please enter a valid station name : ";
    else
        cout << endl << "   -> DESTINATION <-" << endl
             << endl << "   Please enter a valid station name : ";

    getline(cin >> ws, input);

    do {
        if (network.doesNodeExist(input, stationptr)) {
            if (isStationOutputSafe(stationptr))
                cout << endl << "   ! FOUND !" << endl
                     << endl << "   You've selected the " << stationptr->getName() << " station located in "
                     << stationptr->getMunicipality() << ", " << stationptr->getDistrict() << "." << endl;
            else
                cout << endl << "   ! FOUND !" << endl
                     << endl << "   You've selected the " << stationptr->getName() << " station." << endl;
            if (confirmChoice()) return stationptr;
        }
        cout << endl << "   Please enter a valid station name : ";
        getline(cin >> ws, input);
    }
    while(true);
}

bool Menu::confirmChoice() {
    int input;

    cout << endl
         << "     1. Confirm choice and proceed" << endl << endl
         << "     2. Go back and make changes" << endl << endl
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

void Menu::pressEnterToContinue() {
    cout << endl << "   Press ENTER to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool Menu::isStationOutputSafe(Station* stationptr) {}

// -------------------- END OF FILE -------------------- //

 */
