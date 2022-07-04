#include<iostream>
using namespace std; 
template<typename T>
class prueba
{
    protected:
        T dato;
    public:
        prueba(){}
        prueba(T aux):dato(aux){}
        T getDato(){return dato;}
        void setDato(T aux){dato = aux;}
};
template<typename T>
void crearLista(prueba<T>* &arreglo,int &n)
{
    cout<<"\nIngrese el numero de elementos de su arreglo: ",cin>>n;
    arreglo = new prueba<T>[n];
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        T temp;
        cout<<"Ingrese el siguiente elemento del arreglo: ",cin>>temp;
        arreglo[i].setDato(temp);
    }
}
template<typename T>
void crearLista(T* &arreglo,int &n)
{
    cout<<"\nIngrese el numero de elementos de su arreglo: ",cin>>n;
    arreglo = new T[n];
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<"Ingrese el siguiente elemento del arreglo: ",cin>>arreglo[i];
}
template<typename T>
void imprimirLista(prueba<T>* &arreglo,int &n)
{
    cout<<"\nLa lista: ";
    for(int i=0;i<n;i++) 
        cout <<arreglo[i].getDato()<<" "; 
    cout<<endl;
}
template<typename T>
void imprimirLista(T* &arreglo,int &n)
{
    cout<<"\nLa lista: ";
    for(int i=0;i<n;i++) 
        cout <<arreglo[i]<<" "; 
    cout<<endl;
}
template<typename T>
void insertionsort(prueba<T>* arreglo,int n, bool(*comparPtr)(T,T))
{
    for(int k=1; k<n; k++) 
    { 
        T temp = arreglo[k].getDato(); 
        int j= k-1; 
        while(j>=0 && comparPtr(temp,arreglo[j].getDato())) 
        { 
            arreglo[j+1].setDato(arreglo[j].getDato()); 
            j--;
        } 
        arreglo[j+1].setDato(temp); 
    } 
}
template<typename T>
void insertionsort(T* arreglo,int n, bool(*comparPtr)(T,T))
{
    for(int k=1; k<n; k++) 
    { 
        T temp = arreglo[k]; 
        int j= k-1; 
        while(j>=0 && comparPtr(temp,arreglo[j])) 
        { 
            arreglo[j+1] = arreglo[j]; 
            j--;
        } 
        arreglo[j+1] = temp; 
    } 
}
template<typename T>
void eliminaLista(T*&arreglo,int&n)
{
    delete []arreglo;
}
template<typename T>
bool comparacionMayor(T x, T y)
{
    return x>y;
}
template<typename T>
bool comparacionMenor(T x, T y)
{
    return x<=y;
}
int main() 
{
    void (*operaListas[])(prueba<int>*&,int&) = {crearLista,imprimirLista,eliminaLista};
    int n;
    prueba<int> *arreglo;

    operaListas[0](arreglo,n);
    operaListas[1](arreglo,n);

    cout<<"\nOrdenando...\n";
    insertionsort<int>(arreglo,n,comparacionMenor);
    operaListas[1](arreglo,n);
    cout<<endl;
}