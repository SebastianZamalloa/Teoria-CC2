#include <iostream>
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
void swap(T* a, T* b) 
{ 
    T t = *a; 
    *a = *b; 
    *b = t; 
} 
template<typename T>
int partition (prueba<T> *arr, int low, int high,bool (*compPtr)(T,T)) 
{ 
    T pivot = arr[high].getDato(); 
    int i = (low - 1); 
    for (int j = low; j <= high- 1; j++) 
    { 
        if (compPtr(arr[j].getDato(),pivot)) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
template<typename T>
int partition (T *arr, int low, int high,bool (*compPtr)(T,T)) 
{ 
    T pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high- 1; j++) 
    { 
        if (compPtr(arr[j],pivot)) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
template<typename T>
void quickSort(prueba<T> *arr, int low, int high,bool (*compPtr)(T,T)) 
{ 
    if (low < high) 
    { 
        int pivot = partition(arr, low, high, compPtr); 
        quickSort(arr, low, pivot - 1,compPtr); 
        quickSort(arr, pivot + 1, high,compPtr); 
    } 
} 
template<typename T>
void quickSort(T *arr, int low, int high,bool (*compPtr)(T,T)) 
{ 
    if (low < high) 
    { 
        int pivot = partition(arr, low, high, compPtr); 
        quickSort(arr, low, pivot - 1,compPtr); 
        quickSort(arr, pivot + 1, high,compPtr); 
    } 
} 
template<typename T>
void eliminaLista(T*&arreglo,int&n)
{
    delete []arreglo;
}
int main() 
{ 
    void (*operaListas[])(prueba<string>*&,int&) = {crearLista,imprimirLista,eliminaLista};
    int n;
    prueba<string> *arreglo;

    operaListas[0](arreglo,n);
    operaListas[1](arreglo,n);

    cout<<"\nOrdenando...\n";
    quickSort<string>(arreglo, 0, n-1,comparacionMenor); 
    operaListas[1](arreglo,n);
    cout<<endl;
}
