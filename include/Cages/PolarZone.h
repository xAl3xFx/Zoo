#ifndef POLARZONE_H
#define POLARZONE_H
#include "Cages/Cage.h"

/**
 * Class holding information about the specific cage class Polar Zone which inherits the abstract class Cage.
 */
class PolarZone : public Cage{
public:
    PolarZone(const int, const int, const char*, const double);
    ~PolarZone();
    /**
    * Implementation of the virtual function addAnimal.
    */
    void addAnimal(Animal&);
};

#endif // POLARZONE_H
