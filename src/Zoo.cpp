#include "Zoo.h"

Zoo::Zoo(){
    cap = 8;
    cur = 0;
    cages = new Cage*[cap];
    warehouse = Warehouse();
}

Zoo::~Zoo()
{
    delete[] cages;
}

void Zoo::copyZoo(const Zoo& other){
    cap = other.cap;
    cur = other.cur;
    cages = new Cage*[cap];
    for(int i=0; i<cur;i++){
        cages[i] = other.cages[i];
    }
}

Zoo::Zoo(const Zoo& other){
    copyZoo(other);
}

Zoo& Zoo::operator=(const Zoo& other){
    if(this!=&other){
        delete[] cages;
        copyZoo(other);
    }
    return *this;
}

void Zoo::resizeCages() {
	cap *= 2;
	Cage** newArr = new Cage*[cap];
	for (int i = 0; i < cur; i++) {
		newArr[i] = cages[i];
	}
	delete[] cages;
	cages = newArr;
}

void Zoo::run(){
    cout << "Welcome to the Zoo!" << endl;

    int option = 0;
    CommandDispatcher cd = *(CommandDispatcher::getInstance());
    SetConsoleTextAttribute(hConsole, 6);
    while(option!=7){
        cout << endl;
        cout << "What do you want to do with the Zoo?" << endl;
        cout << "(1) Accommodate a new animal." << endl;
        cout << "(2) Feed all of the animals in the zoo." << endl;
        cout << "(3) Fill the zoo's warehouse with food." << endl;
        cout << "(4) Build a new cage." << endl;
        cout << "(5) Show information for an animal from the zoo." << endl;
        cout << "(6) Show information for a cage from the zoo." << endl;
        cout << "(7) Exit from the zoo." << endl;
        option = Validator::getInstance()->validateIntInBetween(1,7);
        switch(option){
            case 1:
                cd.addAnimal(*this);
                break;
            case 2:
                cd.feedTheAnimals(*this);
                break;
            case 3:
                cd.loadFood(*this);
                break;
            case 4:
                cd.buildCage(*this);
                break;
            case 5:
                cd.showAnimalInfo(*this);
                break;
            case 6:
                cd.showCageInfo(*this);
                break;

        }
    }
    SetConsoleTextAttribute(hConsole, 9);
    cout << "Thanks for helping our zoo. Good bye :)" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}
