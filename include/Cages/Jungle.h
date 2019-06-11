#ifndef JUNGLE_H
#define JUNGLE_H
#include "Cages/Cage.h"

/**
 * Class holding information about the specific cage class Jungle which inherits the abstract class Cage.
 */
class Jungle : public Cage{
public:
    Jungle(const int, const int, const char*, const double);
    ~Jungle();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // JUNGLE_H
