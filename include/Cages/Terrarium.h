#ifndef TERRARIUM_H
#define TERRARIUM_H
#include "Cages/Cage.h"

/**
 * Class holding information about the specific cage class Terrarium which inherits the abstract class Cage.
 */
class Terrarium : public Cage{
public:
    Terrarium(const int, const int, const char*);
    ~Terrarium();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // TERRARIUM_H
