#ifndef PREDATORMAMMAL_H
#define PREDATORMAMMAL_H
#include "Animals/Models/Mammal.h"
#include "Animals/Models/Predator.h"

/**
 * Class holding information about the specific class PredatorMammal which inherits Mammal and Predator.
 */
class PredatorMammal : public Mammal, public Predator{
public:
    PredatorMammal(const char*, Food*, const double);
    ~PredatorMammal();
};

#endif // PREDATORMAMMAL_H
