#include <iostream>
#include <memory>
using namespace std;
 
weak_ptr<int> gw;
 
void observe()
{
    cout << "gw.use_count() == " << gw.use_count() << "; ";
    if (shared_ptr<int> spt = gw.lock()) {
        cout << "*spt == " << *spt << '\n';
    }
    else 
    {
        cout << "gw is expired\n";
    }
}
 
int main()
{
    {
        auto sp = make_shared<int>(42);
        gw = sp;
 
        observe();
    }
 
    observe();
}
