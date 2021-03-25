#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include<cstring>

#include"Planet.h"

enum class rankOfStormtrooper { Cadet, Private, Lance_Corporal, Corporal, Sergeant, Staff_Sergeant, Master_Sergeant };
class Stormtrooper {
private:
    char* id;
    rankOfStormtrooper rank;
    char* type;
    Planet planet;

public:
Stormtrooper();
Stormtrooper(const char* _id, const rankOfStormtrooper _rank, const char* _type, const Planet _planet);
Stormtrooper(const Stormtrooper& other);
~Stormtrooper();
char* get_id()const;
void set_id(const char* _id);
rankOfStormtrooper get_rank()const;
void set_rank(const rankOfStormtrooper _rank);
char* get_type()const;
void set_type(const char* _type);
Planet get_planet()const;
void set_planet(const Planet _planet);

bool operator==(const Stormtrooper& other) const;
bool operator!=(const Stormtrooper& other) const;
Stormtrooper& operator=(const Stormtrooper& other);
void print_stormtrooper()const;
void Read_file_S(Stormtrooper& stormtrooper_fromfile);
friend std::ostream& operator<<(std::ostream& os, const Stormtrooper& stormtrooper_out);
rankOfStormtrooper char_to_enum(const char* str, rankOfStormtrooper& rank_out);
void Write_file(const Stormtrooper& S);
}; 
