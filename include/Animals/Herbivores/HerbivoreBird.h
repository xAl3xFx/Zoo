#ifndef HERBIVOREBIRD_H
#define HERBIVOREBIRD_H
#include "Animals/Models/Bird.h"
#include "Animals/Models/Herbivore.h"

/**
 * Class holding information about the specific class HerbivoreBird which inherits Bird and Herbivore.
 */
class HerbivoreBird : public Bird, public Herbivore{
public:
    HerbivoreBird(const char*, Food*, const double);
    ~HerbivoreBird();
};

#endif // HERBIVOREBIRD_H
