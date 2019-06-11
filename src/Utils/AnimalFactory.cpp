#include "Utils/AnimalFactory.h"
Animal* AnimalFactory::createAnimal(const char* species){

    if(strcmp(species,"Brown Bear")==0){
        return new PredatorMammal(species, new Meat(), 5);
    }
    else if(strcmp(species,"Wolf")==0){
        return new PredatorMammal(species, new Meat(), 3);
    }
    else if(strcmp(species,"Wild Goat")==0){
        return new HerbivoreMammal(species, new PlantFood(), 2);
    }
    else if(strcmp(species,"Owl")==0){
        return new PredatorBird(species, new Meat(), 0.3);
    }
    else if(strcmp(species,"Eagle")==0){
        return new PredatorBird(species, new Meat(), 0.5);
    }
    else if(strcmp(species,"Lion")==0){
        return new PredatorMammal(species, new Meat(), 8);
    }
    else if(strcmp(species,"Tiger")==0){
        return new PredatorMammal(species, new Meat(), 7);
    }
    else if(strcmp(species,"Lynx")==0){
        return new PredatorMammal(species,  new Meat(), 3);
    }
    else if(strcmp(species,"Lemur")==0){
        return new HerbivoreMammal(species, new PlantFood(), 1);
    }
    else if(strcmp(species,"Parrot")==0){
        return new HerbivoreBird(species, new PlantFood(), 0.3);
    }
    else if(strcmp(species,"Giraffe")==0){
        return new HerbivoreMammal(species, new PlantFood(), 6);
    }
    else if(strcmp(species,"Elephant")==0){
        return new HerbivoreMammal(species, new PlantFood(), 9);
    }
    else if(strcmp(species,"Zebra")==0){
        return new HerbivoreMammal(species, new PlantFood(), 7);
    }
    else if(strcmp(species,"Polar Bear")==0){
        return new PredatorMammal(species, new FishFood(), 6);
    }
    else if(strcmp(species,"Penguin")==0){
        return new PredatorFish(species, new FishFood(), 2);
    }
    else if(strcmp(species,"Seal")==0){
        return new PredatorFish(species, new FishFood(), 1);
    }
    else if(strcmp(species,"Dolphin")==0){
        return new PredatorFish(species, new FishFood(), 1.4);
    }
    else if(strcmp(species,"Shark")==0){
        return new PredatorFish(species, new FishFood(), 6);
    }
    else if(strcmp(species,"Clown Fish")==0){
        return new PredatorFish(species, new FishFood(), 0.2);
    }
    else if(strcmp(species,"Python")==0){
        return new PredatorReptile(species, new Meat(), 1.4);
    }
    else if(strcmp(species,"Monitor Lizard")==0){
        return new PredatorReptile(species, new Meat(), 2.7);
    }
    else if(strcmp(species,"Chameleon")==0){
        return new PredatorReptile(species, new Meat(), 0.9);
    }
    else{
        return 0;
    }
}
