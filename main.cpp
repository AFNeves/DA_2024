#include <iostream>

#include "src/Station.h"
#include "src/Pipe.h"

using namespace std;

int main()
{
    Station station1(3,"S-09");
    Station station2(6,"S-52");

    Pipe pipe(&station1, &station2, 50, false);

    cout << "\nStation | ID:" << pipe.getA()->getID() << " Code:" << pipe.getA()->getCode() << "\n";
    cout << "\nStation | ID:" << pipe.getB()->getID() << " Code:" << pipe.getB()->getCode() << "\n";
    cout << "\nPipe | Capacity:" << pipe.getCapacity() << " IsDirection:" << pipe.isBiDirectional() << "\n\n";

    return 0;
}