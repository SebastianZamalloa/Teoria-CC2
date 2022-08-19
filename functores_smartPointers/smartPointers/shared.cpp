#include <memory>
#include <iostream>
using namespace std;
class Person 
{
    public:
        Person(string name, int age):name(move(name)), age(age){}
        void operator()(int anios){age += anios;}
        string name;
        int age;
};

void describe_person(Person* p) {cout<<endl<<p->name<<" tiene "<<p->age<<" anios\n";}


int main() 
{
    auto maria = make_shared<Person>("Maria", 40); 
    auto hermanaGemelaDeMaria = maria; 
    describe_person(maria.get());
    describe_person(hermanaGemelaDeMaria.get());
    (*hermanaGemelaDeMaria)(5);
    describe_person(maria.get());
    describe_person(hermanaGemelaDeMaria.get());
    cout<<endl;
}
