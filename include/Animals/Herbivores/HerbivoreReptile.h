#ifndef HERBIVOREREPTILE_H
#define HERBIVOREREPTILE_H
#include "Animals/Models/Reptile.h"
#include "Animals/Models/Herbivore.h"

/**
 * Class holding information about the specific class HerbivoreReptile which inherits Reptile and Herbivore.
 */
class HerbivoreReptile : public Reptile, public Herbivore{
public:
    HerbivoreReptile(const char*, Food*, const double);
    ~HerbivoreReptile();
};

#endif // HERBIVOREREPTILE_H
