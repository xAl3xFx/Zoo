#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <typeinfo>
#include <cwchar>
#include "Utils/CommandDispatcher.h"
#include "Utils/Validator.h"
#include "Cage.h"
#include "Forest.h"
#include "Savanna.h"
#include "Jungle.h"
#include "PolarZone.h"
#include "Aquarium.h"
#include "Terrarium.h"
#include "Warehouse.h"

 /**
 * Class holding information about the zoo (cages and warehouse).
 */
 using namespace std;
class Zoo{
    /**
    * Variable giving access to the console.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
    * Array from cages, storing the cages in the zoo.
    */
    Cage** cages;
    /**
    * The warehouse in the zoo.
    */
    Warehouse warehouse;
    /**
    * Variables holding information for the current position and the capacity in the array of cages.
    */
    int cap, cur;
    /**
    * Function that resizes the capacity of the array of cages.
    */
    void resizeCages();
    /**
    * Copy function (used in copy constructor and operator=.
    */
    void copyZoo(const Zoo&);
public:
    Zoo();
    ~Zoo();
    /**
    * Copy constructor.
    */
    Zoo(const Zoo&);
    /**
    * Operator =.
    */
    Zoo& operator=(const Zoo&);
    /**
    * Making CommandDispatcher class friend to this class, so it can have access to it, since it performs all of the logic needed.
    */
    friend class CommandDispatcher;
    /**
    * Function that runs the zoo.
    */
    void run();
};

#endif // ZOO_H
