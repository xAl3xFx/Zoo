#ifndef PREDATORBIRD_H
#define PREDATORBIRD_H
#include "Animals/Models/Bird.h"
#include "Animals/Models/Predator.h"

/**
 * Class holding information about the specific class PredatorBird which inherits Bird and Predator.
 */
class PredatorBird : public Bird, public Predator{
public:
    PredatorBird(const char*, Food*, const double);
    ~PredatorBird();
};

#endif // PREDATORBIRD_H
