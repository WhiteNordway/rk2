// Variant 2

#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iterator>
#include <type_traits>


////// Animal //////
class Animal
{
public:
    Animal(string name, string species): _name(name), _species(species) {}
    
    virtual void display() const
    {
        std::cout << "* The animal is " << animalType()
        << ", its species is '" << _species
        << "'.\n\tName of the animal is '" << _name << "'. ";
    }

    virtual string animalType() const { return "None"; }

    // Setters
    void setName(string name) { _name = name; }
    
    void setSpecies(string species) { _species = species; }
    
    template <typename Type>
    void setAttribute(Type value);  // To set derived class` attribute (_wingspan or _woolType)

protected:
    string _name;
    string _species;
};


////// Bird //////
class Bird: public Animal
{
public:
    Bird(string name, string species, double wingspan): _wingspan(wingspan), Animal(name, species) {}

    void display() const
    {
        Animal::display();
        std::cout << "Its wingspan is " << _wingspan << " cm." << std::endl;
    }
    
    string animalType() const { return "bird"; }
    
    template <typename Type>
    void setAttribute(Type value)
    {
        if (!std::is_same<Type, double>::value)
            throw std::runtime_error("Irrelevant value for replacement.");
        _wingspan = value;
    }

private:
    double _wingspan;
};


////// Mammal //////
enum WoolType { CShortWool, CLongWool };

class Mammal: public Animal
{
public:
    Mammal(string name, string species, WoolType wool): Animal(name, species)
    {_woolType = (wool == CShortWool ? "short" : "long");}
        
    void display() const
    {
        Animal::display();
        std::cout << "Its wool type is " << _woolType << '.' << std::endl;
    }
    
    string animalType() const { return "mammal"; }
    
    template <typename Type>
    void setAttribute(Type value)
    {
        if (!std::is_same<Type, string>::value)
            throw std::runtime_error("Irrelevant value for replacement.");
        _woolType = value;
    }

private:
    string _woolType;
};


enum AttributeGenus { CName, CSpecies, CWingspan, CWoolType };

template<typename AttributeType>
void changeAttribute(Animal *animal, AttributeGenus attribute, AttributeType value)  
{
    switch (attribute)
    {
        case CName:
            if (!std::is_same<AttributeType, string>::value)
            {
                throw std::runtime_error("Irrelevant value for replacement.");
                return;
            }
                
            animal->setName(value);
            break;

        case CSpecies:
            if (!std::is_same<AttributeType, string>::value)
            {
                throw std::runtime_error("Irrelevant value for replacement.");
                return;
            }

            animal->setSpecies(value);
            break;

        case CWingspan:
        case CWoolType:
            if (attribute == CWingspan && animal->animalType() != "bird" ||
                attribute == CWoolType && animal->animalType() != "mammal")
            {
                throw std::runtime_error("Irrelevant attribute time for this animal.");
                return;
            }  
            
            animal->setAttribute<AttributeType>(value);
            break;

        default:
            throw std::runtime_error("Irrelevant attribute type.");
            return;
    }
}


int main()
{
    Bird penguin("Linux", "Aptenodytes patagonicus", 96.58);
    Mammal human("Vanya", "Homo sapience", CShortWool);
    Mammal dog("Corghi", "Pomeranian", CLongWool);
    vector<Animal*> animals = {&penguin, &human, &dog};

    for (auto current = std::begin(animals), end = std::end(animals); current != end; ++current)
    {
        (*current)->display();
    }

    return EXIT_SUCCESS;
}
