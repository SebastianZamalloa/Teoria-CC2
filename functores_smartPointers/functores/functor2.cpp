#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

class ejemplo
{
    private:
        int dato;
    public:
        ejemplo(){dato = 10 + rand() % 100;}
        int getDato(){return dato;}
        void print(){
            cout<<"\nElemento: "<<dato<<endl;}
        bool operator()(ejemplo x, ejemplo y)
        {
            return (x.getDato()<y.getDato());
        }
} comparator;

int main()
{
    srand(time(NULL));
    cout<<"\nLISTA INICIAL: \n";
    vector<ejemplo> pruebaElements(5);
    for(auto &i:pruebaElements){i.print();}
    sort(pruebaElements.begin(),pruebaElements.end(),comparator);
    cout<<endl<<endl<<"LISTA ORDENADA: \n";
    for(auto &i:pruebaElements){i.print();}
    cout<<endl;
}