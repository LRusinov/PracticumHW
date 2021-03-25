#include "Jedi.h"
char* Jedi::get_name()const {
    return name;
}
void Jedi::set_name(const char* _name) {
    if (name != nullptr)
        delete[]name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
rankOfJedi Jedi::get_rank()const {
    return rank;
}
void Jedi::set_rank(const rankOfJedi _rank) {
    rank = _rank;
}
double Jedi::get_midi_chlorian()const {
    return midi_chlorian;
}
void Jedi::set_midi_chlorian(const double _midi_chlorian) {
    midi_chlorian = _midi_chlorian;
}
Planet Jedi::get_planet()const {
    return planet;
}
void Jedi::set_planet(const Planet _planet) {
    planet = _planet;
}
char* Jedi::get_spicies()const {
    return spicies;
}
void Jedi::set_spicies(const char* _spicies) {
    if (spicies != nullptr)
        delete[]spicies;
    spicies = new char[strlen(_spicies) + 1];
    strcpy(spicies, _spicies);
}
char* Jedi::get_militaryRank()const {
    return militaryRank;
}
void Jedi::set_militaryRank(const char* _militaryRank) {
    if (name != nullptr)
        delete[]militaryRank;
    militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(militaryRank, _militaryRank);
}
Jedi::Jedi() {
    name = nullptr;
    spicies = nullptr;
    militaryRank = nullptr;
    midi_chlorian = 0;
    set_rank(rankOfJedi::Youngling);
}
Jedi::Jedi(const char* _name, const rankOfJedi _rank, const double _midi_chlorian, const Planet _planet, const char* _spicies, const char* _militaryRank) {
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->spicies = new char[strlen(_spicies) + 1];
    strcpy(this->spicies, _spicies);

    this->militaryRank = new char[strlen(_militaryRank) + 1];
    strcpy(this->militaryRank, _militaryRank);

    this->rank = _rank;
    this->midi_chlorian = _midi_chlorian;
    this->planet = _planet;

}
    Jedi::Jedi(Jedi& other) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->spicies = new char[strlen(other.spicies) + 1];
    strcpy(this->spicies, other.spicies);

    this->militaryRank = new char[strlen(other.militaryRank) + 1];
    strcpy(this->militaryRank, other.militaryRank);

    this->midi_chlorian = other.midi_chlorian;
    this->rank = other.rank;
    this->planet = other.planet;
}
Jedi::~Jedi() {
    delete[]name;
    name = nullptr;
    delete[]spicies;
    spicies = nullptr;
    delete[]militaryRank;
    militaryRank = nullptr;
}
void Jedi::print_Jedi() {
    std::cout << "Jedi's name: " << name << std::endl;
    std::cout << "Rank: ";
    switch (rank)
    {
    case rankOfJedi::Youngling: std::cout << "Youngling" << std::endl;   break;
    case rankOfJedi::Padawan: std::cout << "Padawan" << std::endl;   break;
    case rankOfJedi::Service: std::cout << "Service" << std::endl;   break;
    case rankOfJedi::Corps: std::cout << "Corps" << std::endl;   break;
    case rankOfJedi::Knight: std::cout << "Knight" << std::endl;   break;
    case rankOfJedi::Consular: std::cout << "Consular" << std::endl;   break;
    case rankOfJedi::Guardian: std::cout << "Guardian" << std::endl;   break;
    case rankOfJedi::Sentinel: std::cout << "Sentinel" << std::endl;   break;
    case rankOfJedi::Council_Member: std::cout << "Council_Member" << std::endl;   break;
    case rankOfJedi::Grand_Master: std::cout << "Grand_Master" << std::endl;   break;
    }
    std::cout << "Midi-chlorian: " << midi_chlorian << std::endl;
    planet.print_planet<const char*, const typeOfPlanet>(planet.get_name(), planet.get_planetSystem(), planet.get_republic(), planet.get_typeofplanet());
    std::cout << "Spicies: " << spicies << std::endl;
    std::cout << "MilitaryRank: " << militaryRank << std::endl << std::endl;
}
bool Jedi:: operator==(const Jedi& other) const {
    return !strcmp(this->name, other.name) && (this->planet == other.planet) && (this->rank == other.rank) && !strcmp(this->spicies, other.spicies) && !strcmp(this->militaryRank, other.militaryRank) && (this->midi_chlorian == other.midi_chlorian);
}
bool Jedi:: operator!=(const Jedi& other) const {
    return !(*this == other);
}
Jedi& Jedi::operator=(const Jedi& other) {
    if (this != &other) {
        delete[] name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        delete[] spicies;
        this->spicies = new char[strlen(other.spicies) + 1];
        strcpy(this->spicies, other.spicies);
        delete[] militaryRank;
        this->militaryRank = new char[strlen(other.militaryRank) + 1];
        strcpy(this->militaryRank, other.militaryRank);
        planet = other.planet;
        rank = other.rank;
        midi_chlorian = other.midi_chlorian;
    }
    return *this;
}
void Jedi::Write_file(const Planet& P, const Stormtrooper& S, const Jedi& J) {
    std::ofstream myfile;
    myfile.open("Jedis.txt", std::ios::out);
    myfile << J.get_name() << std::endl;
    switch (J.get_rank())
    {
    case rankOfJedi::Youngling: myfile << "Youngling" << std::endl;   break;
    case rankOfJedi::Padawan: myfile << "Padawan" << std::endl;   break;
    case rankOfJedi::Service: myfile << "Service" << std::endl;   break;
    case rankOfJedi::Corps: myfile << "Corps" << std::endl;   break;
    case rankOfJedi::Knight: myfile << "Knight" << std::endl;   break;
    case rankOfJedi::Consular: myfile << "Consular" << std::endl;   break;
    case rankOfJedi::Guardian: myfile << "Guardian" << std::endl;   break;
    case rankOfJedi::Sentinel: myfile << "Sentinel" << std::endl;   break;
    case rankOfJedi::Council_Member: myfile << "Council_Member" << std::endl;   break;
    case rankOfJedi::Grand_Master: myfile << "Grand_Master" << std::endl;   break;
    };
    myfile << J.get_midi_chlorian() << std::endl;
    myfile << P.get_name() << std::endl;
    myfile << J.get_spicies() << std::endl;
    myfile << J.get_militaryRank() << std::endl<<std::endl;
    myfile.close();
}
void Jedi::Read_file_J(Jedi& jedi_fromfile) {
    unsigned int counter=0;
    std::string text;
    std::ifstream  myfile("Jedis.txt");
    while (getline(myfile, text)&& text!="") {
        char* buff = new char[text.size()+1];
        strcpy(buff, text.c_str());
        switch (counter) {
        case 0: jedi_fromfile.set_name(buff) ; counter++; break;
        case 1: jedi_fromfile.set_rank(jedi_fromfile.char_to_enum(buff, jedi_fromfile.rank)); counter++; break;
        case 2: jedi_fromfile.set_midi_chlorian(jedi_fromfile.char_to_double(buff, jedi_fromfile.midi_chlorian)); counter++; break;
        case 3: jedi_fromfile.planet.set_name(buff); counter++; break;
        case 4: jedi_fromfile.set_spicies(buff); counter++; break;
        case 5: jedi_fromfile.set_militaryRank(buff); counter = 0; break;
        }
    }

    myfile.close();

}
double Jedi::char_to_double(const char* str, double midi_chlorian_out) {
    midi_chlorian_out = 0;
    int s = strlen(str);
    bool point = false;
    char buff=' ';
    for (unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            point = true;
            s = i;
            break;
        }
    }
    
    if (point) {
        
        unsigned int temp = s;
        for (unsigned int i = 0; i < temp; i++) {
            midi_chlorian_out += (double(str[i]) - 48) * pow(10, s);
            s--;
        }
        s -= 1;
        for (unsigned int i = temp+1 ; i < strlen(str); i++) {
            midi_chlorian_out += (double(str[i]) - 48) * (pow(10, s));
            std::cout << (double(str[i]) - 48) << std::endl;
            s--;
        }

    }
    else {
        s--;
        for (unsigned int i = 0; i < strlen(str); i++) {
            midi_chlorian_out += (double(str[i]) - 48) * pow(10, s);
            s--;
        }
    }
    return midi_chlorian_out;
}
rankOfJedi Jedi::char_to_enum(const char* str, rankOfJedi& rank_out) {
    
    if(str =="Youngling") rank_out =rankOfJedi::Youngling;
    if (str == "Padawan") rank_out = rankOfJedi::Padawan;
    if (str == "Service") rank_out =rankOfJedi::Service;
    if (str == "Corps") rank_out =rankOfJedi::Corps;
    if (str == "Knight") rank_out =rankOfJedi::Knight;
    if (str == "Consular") rank_out =rankOfJedi::Consular;
    if (str == "Guardian") rank_out =rankOfJedi::Guardian;
    if (str == "Sentinel") rank_out =rankOfJedi::Sentinel;
    if (str == "Council_Member") rank_out = rankOfJedi::Council_Member;
    if (str == "Grand_Master") rank_out = rankOfJedi::Grand_Master;
    
    return rank_out;
}
std::ostream& operator<<(std::ostream& os, const Jedi& jedi_out) {
    os << jedi_out.get_name() << std::endl;
    switch (jedi_out.get_rank())
    {
    case rankOfJedi::Youngling: os << "Youngling" << std::endl;   break;
    case rankOfJedi::Padawan: os << "Padawan" << std::endl;   break;
    case rankOfJedi::Service: os << "Service" << std::endl;   break;
    case rankOfJedi::Corps: os << "Corps" << std::endl;   break;
    case rankOfJedi::Knight: os << "Knight" << std::endl;   break;
    case rankOfJedi::Consular: os << "Consular" << std::endl;   break;
    case rankOfJedi::Guardian: os << "Guardian" << std::endl;   break;
    case rankOfJedi::Sentinel: os << "Sentinel" << std::endl;   break;
    case rankOfJedi::Council_Member: os << "Council_Member" << std::endl;   break;
    case rankOfJedi::Grand_Master: os << "Grand_Master" << std::endl;   break;
    };
    os << jedi_out.get_midi_chlorian() << std::endl;
    os << jedi_out.planet.get_name() << std::endl;
    os << jedi_out.get_spicies() << std::endl;
    os << jedi_out.get_militaryRank() << std::endl;
    return os;
}
