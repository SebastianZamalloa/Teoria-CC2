#include <iostream>
#include <vector>
#include <map>
using namespace std;

class grafo 
{
    protected :
        map <int,vector <int>> outgoing;
    public :
    grafo(const vector <int> &inicio,const vector<int > &final)
    {
        if(inicio.size() != final.size()) 
            throw invalid_argument ("Las listas de inicio y final tienen diferente cantidad de elementos");
        for(unsigned i = 0; i<inicio.size(); i++) 
        {
            int in = inicio[i];
            int fi = final[i];
            outgoing[in].push_back(fi);
            outgoing[fi];
        }
    }
    int numOutgoing(const int ID_nodo) const{return adyacente(ID_nodo).size();}
    const vector <int> &adyacente(const int ID_nodo) const
    {
        map<int,vector<int>>::const_iterator i = outgoing.find(ID_nodo);
        if(i == outgoing.end()) 
            throw invalid_argument("Id de nodo invalido");
        return i->second;
    }
};

int main()
{
    cout<<"\nGrafo creado en C++: \n";
    vector<int>inicio = {1,1,1,5,5,4};
    vector<int>final = {2,3,4,4,2,2};
    grafo miGrafo(inicio,final);

    cout<<"\nNodos con los que el nodo '1' inicia una arista direccionada hacia ellos: ";
    vector<int> prueba = miGrafo.adyacente(1);
    for(auto i=prueba.begin();i!=prueba.end();i++)
        cout<<*i<<" ";
    cout<<"\nNodos con los que el nodo '5' inicia una arista direccionada hacia ellos: ";
    prueba = miGrafo.adyacente(5);
    for(auto i=prueba.begin();i!=prueba.end();i++)
        cout<<*i<<" ";
    cout<<"\nNodos con los que el nodo '4' inicia una arista direccionada hacia ellos: ";
    prueba = miGrafo.adyacente(4);
    for(auto i=prueba.begin();i!=prueba.end();i++)
        cout<<*i<<" ";
    cout<<endl<<endl;
}