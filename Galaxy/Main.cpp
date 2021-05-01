#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include"Battleship.h"


int main() {
    Planet planetOfYoda;
    planetOfYoda.set_name("Coruscant");
    planetOfYoda.set_planetSystem("Coruscant system");
    planetOfYoda.set_republic("Republic");
    planetOfYoda.set_typeofplanet(typeOfPlanet::Ice_planet);
    Jedi j;
    j.set_name("Yoda");
    j.set_midi_chlorian(1770);
    j.set_militaryRank("Jedi General");
    j.set_spicies("Yoda's species");
    j.set_planet(planetOfYoda);
    j.set_rank(rankOfJedi::Grand_Master);
    
    BattleShip <Jedi> X;
    std::vector< BattleShip<Jedi> > flot(10);
    flot[0].set_ammo(Category_ammunition::Light);
    flot[0].set_amount_of_fuel(70);
    flot[0].set_cannons(25);
    flot[0].set_pilot(j);
    flot[0].set_hull(40);
    flot[0].set_hyperjump(false);
    flot[0].set_size(100);
    flot[0].set_speed(300);
    flot[1].set_ammo(Category_ammunition::Medium);
    flot[1].set_amount_of_fuel(100);
    flot[1].set_cannons(25);
    flot[1].set_hull(100);
    flot[1].set_hyperjump(false);
    flot[1].set_size(100);
    flot[1].set_speed(300);
    flot[1].set_pilot(j);
    flot[2].set_ammo(Category_ammunition::Light);
    flot[2].set_amount_of_fuel(12);
    flot[2].set_cannons(25);
    flot[2].set_hull(50);
    flot[2].set_hyperjump(false);
    flot[2].set_size(100);
    flot[2].set_speed(300);
    flot[2].set_pilot(j);

  
    std::cout << flot[1];
    std::cout << flot[2];
    MyLinkedList* ActivityLog = new MyLinkedList();
    X.fuel_refill(flot);
    ActivityLog->pushBack("Fuel refill");
    X.remove_broken(flot);
    ActivityLog->pushBack("Broken battleships removed");
    X.ammo_change(flot, 2, Category_ammunition::Heavy);
    ActivityLog->pushBack("Ammo changed");
    ActivityLog->print();

    ActivityLog->recursionReverse(ActivityLog->get_node());
    ActivityLog->print();
    ActivityLog->reverse();
    ActivityLog->print();
    return 0;
}
