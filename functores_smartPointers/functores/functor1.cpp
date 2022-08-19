#include <iostream>
using namespace std;

class ejemplo
{
    private:
        int dato;
    public:
        ejemplo(int temp):dato(temp){}
        int getDato(){return dato;}
        void setDato(int temp){dato=temp;}
        void print(){cout<<"\nDATO: "<<dato<<"\n";}
        void operator()(ejemplo &extraido)
        {
            cout<<"\nExtraccion\n";
            dato += extraido.getDato();
            extraido.setDato(0);
        }   
};
int main()
{
    ejemplo obj1(10);
    ejemplo obj2(5);
    obj1.print();
    obj2.print();
    obj1(obj2);
    obj1.print();
    obj2.print();
    cout<<endl;
}