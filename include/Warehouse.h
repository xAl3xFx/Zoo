#ifndef WAREHOUSE_H
#define WAREHOUSE_H

/**
 * Class holding information about the warehouse of the zoo.
 */
class Warehouse{
/**
 * Variables holding information for the meat, fish, plants in stock.
 */
double meat,fish,plants;
public:
    Warehouse();
    ~Warehouse();
    /**
    * Function that loads meat, fish and plants (passed as arguments) to the warehouse.
    */
    void loadFood(const double, const double, const double);
    /**
    * Function that takes certain amount of meat (passed as argument) from the warehouse.
    */
    bool takeMeat(const double);
    /**
    * Function that takes certain amount of fish (passed as argument) from the warehouse.
    */
    bool takeFish(const double);
    /**
    * Function that takes certain amount of plants (passed as argument) from the warehouse.
    */
    bool takePlants(const double);
};

#endif // WAREHOUSE_H
