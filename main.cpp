#include <iostream>
#include "list.h"
using namespace std;
int main() {
    List<int> n(20, 50);
    n.modElement(30,1);
    n.InsElement(40,4);
    n.removeElement(23);

    for (int i = 0; i <n.size(); ++i) {
        cout<<n.getElement(i)<<' ';
    }
    cout<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
