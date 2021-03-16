#include <iostream>
#include"Jedi.hpp"
int main() {
    Jedi j;
    Planet planetOfYoda;
    planetOfYoda.set_name("Coruscant");
    planetOfYoda.set_planetSystem("Coruscant system");
    planetOfYoda.set_republic("Republic");
    planetOfYoda.set_typeofplanet(typeOfPlanet::Ice_planet);
    j.set_name("Yoda");
    j.set_midi_chlorian(1770);
    j.set_militaryRank("Jedi General");
    j.set_spicies("Yoda's species");
    j.set_planet(planetOfYoda);
    j.set_rank(rankOfJedi::Grand_Master);
    //j.print_Jedi();

    Stormtrooper s;
    Planet planetOfStormtrooper;
    planetOfStormtrooper.set_name("Vardos");
    planetOfStormtrooper.set_planetSystem("Jinata system");
    planetOfStormtrooper.set_republic("Galactic republic");
    planetOfStormtrooper.set_typeofplanet(typeOfPlanet::Protoplanet);
    s.set_id("TK-5331");
    s.set_planet(planetOfStormtrooper);
    s.set_rank(rankOfStormtrooper::Sergeant);
    s.set_type("Shadow Trooper");
    //s.print_stormtrooper();
    
    j.Write_file(planetOfYoda, s, j);
    j.Read_file_J(j);
    std::cout  << j;

    j.Write_file(planetOfStormtrooper, s, j);
    s.Read_file_S(s);
    std::cout << std::endl << s;

    planetOfStormtrooper.Read_file_P(planetOfStormtrooper);
    std::cout << std::endl << planetOfStormtrooper;
    
    return 0;
}