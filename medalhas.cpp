#include <iostream>

using namespace std;

int main () {
    int tempos [3];
    int bronze = -1; 
    int prata = -1;
    int ouro = -1; 
    int j, k, m;
    for (int i = 0; i < 3; i ++){
        cin >> tempos [i];
    }

    for (int i =0; i < 3; i++){
        if (tempos[i] > bronze) {
            bronze  = tempos[i];
            j = i;
        }

    }

    for (int i = 0; i < 3; i++){
        if (i != j){
            if (tempos[i] > prata){
                prata = tempos [i];
                k = i;
            }
        }
    }

    for (int i = 0; i < 3; i ++){
        if (i != j && i != k){
            ouro = tempos [i];
            m = i;
        }
    }

    cout << m + 1 << endl;
    cout << k + 1 << endl;
    cout << j + 1 << endl;


    return 0;
}