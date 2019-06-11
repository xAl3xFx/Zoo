#ifndef PREDATORREPTILE_H
#define PREDATORREPTILE_H
#include "Animals/Models/Reptile.h"
#include "Animals/Models/Predator.h"

/**
 * Class holding information about the specific class PredatorReptile which inherits Reptile and Predator.
 */
class PredatorReptile : public Reptile, public Predator{
public:
    PredatorReptile(const char*, Food*, const double);
    ~PredatorReptile();
};

#endif // PREDATORREPTILE_H
