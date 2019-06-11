#ifndef REPTILE_H
#define REPTILE_H
#include "Animals/Models/Animal.h"

/**
 * Class holding information about the abstract class Reptile which inherits the abstract class Animal.
 */
class Reptile : public Animal{
protected:
    Reptile(const char*, Food*, const double);
    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Reptile();
};

#endif // REPTILE_H
