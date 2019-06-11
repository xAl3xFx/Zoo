#ifndef FOREST_H
#define FOREST_H
#include "Cages/Cage.h"
#include <iostream>

/**
 * Class holding information about the specific cage class Forest which inherits the abstract class Cage.
 */
class Forest : public Cage{
public:
    Forest(const int, const int, const char*, const double);
    ~Forest();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // FOREST_H
