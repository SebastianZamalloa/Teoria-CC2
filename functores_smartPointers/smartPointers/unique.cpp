#include <memory>
#include <iostream>
using namespace std;
struct Pet 
{
  explicit Pet(string name) : name(move(name)) {}
  string name;
};

struct Person 
{
  Person(string name, int age, unique_ptr<Pet> pet):name(move(name)), age(age), pet(move(pet)) {}
  string name;
  int age;
  unique_ptr<Pet> pet;
};

void describe_person(Person* p) 
{
  cout<<endl<<p->name<< " tiene "<<p->age<<" anios\n";
  if (p->pet) 
    cout<<p->name<<" tiene una mascota llamada "<<p->pet->name<<"\n";
}

int main() 
{
    auto scout = make_unique<Pet>("Fido");
    auto nushi = make_unique<Person>("Juan", 23, move(scout));

    describe_person(nushi.get());
    cout<<endl;
}
