#ifndef SAVANNA_H
#define SAVANNA_H
#include "Cages/Cage.h"

/**
 * Class holding information about the specific cage class Savanna which inherits the abstract class Cage.
 */
class Savanna : public Cage{
public:
    Savanna(const int, const int, const char*, const double);
    ~Savanna();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // SAVANNA_H
