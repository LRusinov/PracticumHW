#include"Stormtrooper.hpp"

char* Stormtrooper::get_id()const {
    return id;
}
void Stormtrooper::set_id(const char* _id) {
    if (id != nullptr)
        delete[]id;
    id = new char[strlen(_id) + 1];
    strcpy(id, _id);
}
rankOfStormtrooper Stormtrooper::get_rank()const {
    return rank;
}
void Stormtrooper::set_rank(const rankOfStormtrooper _rank) {
    rank = _rank;
}
char* Stormtrooper::get_type()const {
    return type;
}
void Stormtrooper::set_type(const char* _type) {
    if (type != nullptr)
        delete[]type;
    type = new char[strlen(_type) + 1];
    strcpy(type, _type);
}
Planet Stormtrooper::get_planet()const {
    return planet;
}
void Stormtrooper::set_planet(const Planet _planet) {
    planet = _planet;
}
Stormtrooper::Stormtrooper() {
    id = nullptr;
    type = nullptr;
    set_rank(rankOfStormtrooper::Cadet);
}
Stormtrooper::Stormtrooper(const char* _id, const rankOfStormtrooper _rank, const char* _type, const Planet _planet) {
    this->id = new char[strlen(_id) + 1];
    strcpy(this->id, _id);
    this->type = new char[strlen(_type) + 1];
    strcpy(this->type, _type);
    this->rank = _rank;
    this->planet = _planet;
}
Stormtrooper::Stormtrooper(const Stormtrooper& other) {
    this->id = new char[strlen(other.id) + 1];
    strcpy(this->id, other.id);

    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);

    this->rank = other.rank;
    this->planet = other.planet;
}
Stormtrooper::~Stormtrooper() {
    delete[]id;
    id = nullptr;
    delete[]type;
    type = nullptr;
}
void Stormtrooper::print_stormtrooper()const {
    std::cout << "Stormtrooper's id: " << id << std::endl;
    std::cout << "Rank: ";

    switch (rank)
    {
    case rankOfStormtrooper::Cadet: std::cout << "Cadet" << std::endl;   break;
    case rankOfStormtrooper::Lance_Corporal: std::cout << "Lance_Corporal" << std::endl;   break;
    case rankOfStormtrooper::Corporal: std::cout << "Corporal" << std::endl;   break;
    case rankOfStormtrooper::Sergeant: std::cout << "Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Staff_Sergeant: std::cout << "Staff_Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Master_Sergeant: std::cout << "Master_Sergeant" << std::endl;   break;
    }
    std::cout << "Type: " << type << std::endl;
    planet.print_planet<const char*,const typeOfPlanet>(planet.get_name(),planet.get_planetSystem(),planet.get_republic(),planet.get_typeofplanet());
}

bool Stormtrooper:: operator==(const Stormtrooper& other) const {
    return !strcmp(this->id, other.id) && (this->planet == other.planet) && (this->rank == other.rank) && !strcmp(this->type, other.type);
}
bool Stormtrooper:: operator!=(const Stormtrooper& other) const {
    return !(*this == other);
}
Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other) {
    if (this != &other) {
        delete[] id;
        this->id = new char[strlen(other.id) + 1];
        strcpy(this->id, other.id);
        delete[] type;
        this->type = new char[strlen(other.type) + 1];
        strcpy(this->type, other.type);
        this->planet = other.planet;
        this->rank = other.rank;
    }
    return *this;
}
void Stormtrooper::Read_file_S(Stormtrooper& stormtrooper_fromfile) {
    unsigned int counter = 0;

    std::string text;
    std::ifstream myfile("Stormtrooper.txt");
    while (getline(myfile, text) && text != "") {
        char* buff = new char[text.size() + 1];
        strcpy(buff, text.c_str());
        switch (counter) {
        case 0: stormtrooper_fromfile.set_id(buff); counter++; break;
        case 1: stormtrooper_fromfile.set_rank(stormtrooper_fromfile.char_to_enum(buff, stormtrooper_fromfile.rank)); counter++; break;
        case 2: stormtrooper_fromfile.set_type(buff); counter++; break;
        case 3: stormtrooper_fromfile.planet.set_name(buff); counter=0; break;
        }
    }

    myfile.close();
}
std::ostream& operator<<(std::ostream& os, const Stormtrooper& stormtrooper_out) {
    os << stormtrooper_out.get_id() << std::endl;
    switch (stormtrooper_out.get_rank())
    {
    case rankOfStormtrooper::Cadet: os << "Cadet" << std::endl;   break;
    case rankOfStormtrooper::Lance_Corporal: os << "Lance_Corporal" << std::endl;   break;
    case rankOfStormtrooper::Corporal: os << "Corporal" << std::endl;   break;
    case rankOfStormtrooper::Sergeant: os << "Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Staff_Sergeant: os << "Staff_Sergeant" << std::endl;   break;
    case rankOfStormtrooper::Master_Sergeant: os << "Master_Sergeant" << std::endl;   break;
    };
    os << stormtrooper_out.get_type() << std::endl;
    os << stormtrooper_out.planet.get_name() << std::endl;

    
    return os;
}
rankOfStormtrooper Stormtrooper::char_to_enum(const char* str, rankOfStormtrooper& rank_out) {


    if (str == "Cadet") rank_out = rankOfStormtrooper::Cadet;
    if (str == "Lance_Corporal") rank_out = rankOfStormtrooper::Lance_Corporal;
    if (str == "Corporal") rank_out = rankOfStormtrooper::Corporal;
    if (str == "Sergeant")   rank_out = rankOfStormtrooper::Sergeant;
    if (str == "Staff_Sergeant")  rank_out = rankOfStormtrooper::Staff_Sergeant;
    if (str == "Master_Sergeant")   rank_out = rankOfStormtrooper::Master_Sergeant;
    return rank_out;
}