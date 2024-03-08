#include <iostream>

#include "src/Station.h"
#include "src/Pipe.h"

using namespace std;

int main()
{
    Station station1(3,"S-09");
    Station station2(6,"S-52");

    Pipe pipe(&station1, &station2, 50);

    cout << "\nStation | ID:" << pipe.getSrc()->getID() << " Code:" << pipe.getSrc()->getCode() << "\n";
    cout << "\nStation | ID:" << pipe.getDest()->getID() << " Code:" << pipe.getDest()->getCode() << "\n";
    cout << "\nPipe | Capacity:" << pipe.getCapacity() << "\n\n";

    return 0;
}