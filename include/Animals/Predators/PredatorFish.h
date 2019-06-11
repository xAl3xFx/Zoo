#ifndef PREDATORFISH_H
#define PREDATORFISH_H
#include "Animals/Models/Fish.h"
#include "Animals/Models/Predator.h"

/**
 * Class holding information about the specific class PredatorFish which inherits Fish and Predator.
 */
class PredatorFish : public Fish, public Predator{
public:
    PredatorFish(const char*, Food*, const double);
    ~PredatorFish();

};

#endif // PREDATORFISH_H
