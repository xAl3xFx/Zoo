#ifndef HERBIVOREMAMMAL_H
#define HERBIVOREMAMMAL_H
#include "Animals/Models/Mammal.h"
#include "Animals/Models/Herbivore.h"

/**
 * Class holding information about the specific class HerbivoreMammal which inherits Mammal and Herbivore.
 */
class HerbivoreMammal : public Mammal, public Herbivore{
public:
    HerbivoreMammal(const char*, Food*, const double);
    ~HerbivoreMammal();
};

#endif // HERBIVOREMAMMAL_H
