#include<iostream>
using namespace std; 

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
void imprimirLista(T* &arreglo,int &n)
{
    cout<<"\nLa lista: ";
    for(int i=0;i<n;i++) 
        cout <<arreglo[i]<<" "; 
    cout<<endl;
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
    void (*operaListas[])(char*&,int&) = {crearLista,imprimirLista,eliminaLista};
    int n;
    char *arreglo;

    operaListas[0](arreglo,n);
    operaListas[1](arreglo,n);

    cout<<"\nOrdenando...\n";
    insertionsort(arreglo,n,comparacionMenor);
    operaListas[1](arreglo,n);
    cout<<endl;
}
