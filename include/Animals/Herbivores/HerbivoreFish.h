#ifndef HERBIVOREFISH_H
#define HERBIVOREFISH_H
#include "Animals/Models/Herbivore.h"
#include "Animals/Models/Fish.h"

/**
 * Class holding information about the specific class HerbivoreFish which inherits Fish and Herbivore.
 */
class HerbivoreFish : public Fish, public Herbivore{
public:
    HerbivoreFish(const char*, Food*, const double);
    ~HerbivoreFish();
};

#endif // HERBIVOREFISH_H
