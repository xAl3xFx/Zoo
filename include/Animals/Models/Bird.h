#ifndef BIRD_H
#define BIRD_H
#include "Animals/Models/Animal.h"

/**
 * Class holding information about the abstract class Bird which inherits the abstract class Animal.
 */
class Bird : public Animal{
public:
    Bird(const char*, Food*, const double);
    /**
    * Virtual destructor because this is an abstract class.
    */
    virtual ~Bird();
};

#endif // BIRD_H
