#include <iostream>
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
bool comparacionMayor(T x, T y)
{
    return x>y;
}
template<typename T>
bool comparacionMenor(T x, T y)
{
    return x<=y;
}
template<typename T>
void merge(T* arreglo, int low, int high, int mid, bool (*compPtr)(T,T))
{
    int i = low,k = i;
    int j = mid+1, c[100];

    while (i <= mid && j <= high) 
    {
        if (compPtr(arreglo[i],arreglo[j])) 
        {
            c[k] = arreglo[i];
            i++;
        }
        else
        {
            c[k] = arreglo[j];
            j++;
        }
        k++;
    }
    while (i <= mid) 
    {
        c[k] = arreglo[i];
        k++;
        i++;
    }
    while (j <= high) 
    {
        c[k] = arreglo[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) 
        arreglo[i] = c[i];
}
template<typename T>
void merge_sort(T *arr, int low, int high, bool (*compPtr)(T,T))
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        merge_sort(arr,low,mid,compPtr);
        merge_sort(arr,mid+1,high,compPtr);    
        merge(arr,low,high,mid,compPtr);
    }
}
template<typename T>
void eliminaLista(T*&arreglo,int&n)
{
    delete []arreglo;
}
int main()
{
    void (*operaListas[])(char*&,int&) = {crearLista,imprimirLista,eliminaLista};
    int n;
    char *arreglo;

    operaListas[0](arreglo,n);
    operaListas[1](arreglo,n);

    cout<<"\nOrdenando...\n";
    merge_sort(arreglo, 0, n-1,comparacionMenor);
    operaListas[1](arreglo,n);

    operaListas[2](arreglo,n);
    cout<<endl;
}
