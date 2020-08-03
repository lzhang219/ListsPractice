#include <iostream>
#include "sllist.h"
using namespace std;
int main() {
    SLList<int> n(20, 50);
    n.modElement(30,1);
    n.InsElement(40,4);
    n.removeElement(23);
    for (int i = 0; i <n.size(); ++i) {
        cout << n.getElement(i) << ' ';
    }
    cout<<endl;
    cout<<"Test"<<endl;
    return 0;
}
