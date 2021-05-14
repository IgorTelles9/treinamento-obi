#include <iostream>

using namespace std;

int main () {
    int dias, custoDiario;

    while(scanf("%d",&dias)!=EOF){
        int receitas[dias];
        cin >> custoDiario;
        for (int i =0; i < dias; i++){
            cin >> receitas[i];
        }
        int maiorLucro = 0;
        int lucroParcial, somaReceita;

        for (int i = 0; i < dias; i++) {
            somaReceita = receitas [i];
            if (receitas[i] - custoDiario > maiorLucro){
                maiorLucro = receitas[i] - custoDiario;
            }
            for (int j = i + 1; j < dias; j++){
                somaReceita += receitas[j];
                lucroParcial = somaReceita - ((j - i + 1)*custoDiario);
                if (lucroParcial > maiorLucro){
                    maiorLucro = lucroParcial;
                }
            }
        }

        cout << maiorLucro << endl;
    }
    return 0;
}
