#ifndef AQUARIUM_H
#define AQUARIUM_H
#include "Cages/Cage.h"

/**
 * Class holding information about the specific cage class Aquarium which inherits the abstract class Cage.
 */
class Aquarium : public Cage{
public:
    Aquarium(const int, const int, const char*);
    ~Aquarium();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // AQUARIUM_H
