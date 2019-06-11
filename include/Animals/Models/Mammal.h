#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animals/Models/Animal.h"

/**
 * Class holding information about the abstract class Mammal which inherits the abstract class Animal.
 */
class Mammal : public Animal{
public:
    Mammal(const char*, Food*, const double);
    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Mammal();
};

#endif // MAMMAL_H
