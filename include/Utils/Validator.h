#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <windows.h>
using namespace std;

/**
 * Class serving validation functions.
 */
class Validator{
    /**
    * Variable giving access to the console.
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /**
    * Static reference to the only instance of this class (Singleton).
    */
    static Validator* instance;
    /**
    * Private constructor so that it's not possible to create second instance of this class (Singleton).
    */
    Validator();
public:
    /**
    * Function that returns pointer to the only instance of this class (Singleton).
    */
    static Validator* getInstance();
    /**
    * Function which validates that an integer is between two integers which are passed as parameters.
    */
    int validateIntInBetween(const int,const int) const;
};

#endif // VALIDATOR_H
