#include "buscas.h"
#include <iostream>
using namespace std;


int main () {
    int item;
    int lista [7] = {0,1,2,3,4,5,6};
    cin >> item;
    cout << binarySearch(lista, item, 0, 6);
}