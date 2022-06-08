#include "iostream"
#include "vector"
using namespace std;

template<typename T>
class stack
{
    private:
        vector<T> myStack;
    public:
        stack(){}
        ~stack(){}
        bool empty(){if(myStack.size()==0){return true;}return false; }
        void push(const T &item){myStack.push_back(item);}
        void pop(){myStack.pop_back();}
        void print()
        {
            if(!this->empty())
            {
                for(auto i = myStack.begin();i != myStack.end();i++)
                    cout<<*i<<" ";
            }
            else
                cout<<"Pila vacia"<<endl;
        }
        T& top(){return myStack[myStack.size()-1];}
};
int main()
{
    cout<<"\nPila en C++:\n";
    cout<<"\nCreando pila...\n\nImprimiendo pila recien creada...\n";
    stack<int> miPila;
    miPila.print();
    cout<<"La pila esta vacia, debemos ingresar numeros en ella...\n\nIngresando numeros del 1 al 7...\nImprimiendo...\n";
    for(int i = 0;i<7;i++)
        miPila.push(i+1);
    miPila.print();cout<<endl;
    cout<<"\nImpresion exitosa...\nEliminando los dos ultimos elementos...\n";
    miPila.pop();
    miPila.pop();
    miPila.print();
    cout<<"\nAgregando como ultimo elemento '1'...\n";
    miPila.top() = 1;
    miPila.print();
    cout<<"\nFin del programa"<<endl<<endl;
}