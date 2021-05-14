#include <iostream>
using namespace std;

int main () {
    int numeroLinhas, numeroColunas; 
    bool isNumeroLinhasEven, isNumeroColunasEven;
    int ultimaCasa;

    cin >> numeroLinhas;
    cin >> numeroColunas;

    if (numeroLinhas % 2 == 0) {
        isNumeroLinhasEven = true;
    } 
    else{
        isNumeroLinhasEven = false;
    }

    if (numeroColunas % 2 == 0) {
        isNumeroColunasEven = true;
    }
    else {
        isNumeroColunasEven = false; 
    }

    if (isNumeroColunasEven && isNumeroLinhasEven) {
        ultimaCasa = 1;
    } 
    else if (!isNumeroLinhasEven && !isNumeroColunasEven){
        ultimaCasa = 1;
    } 
    else {
        ultimaCasa = 0;
    }

    cout << ultimaCasa << endl;

    return 0;
}