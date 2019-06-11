#ifndef FISH_H
#define FISH_H
#include "Animals/Models/Animal.h"

/**
 * Class holding information about the abstract class Fish which inherits the abstract class Animal.
 */
class Fish : public Animal{
public:
    Fish(const char*, Food*, const double);
    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Fish();
};

#endif // FISH_H
