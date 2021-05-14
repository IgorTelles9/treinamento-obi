#include <bits/stdc++.h>

int numberLength (int number){
    int contador = 0;
    while (number){
        number = number / 10;
        contador++;
    }
    return contador;
}

using namespace std;


int main () {

    int qtdeMatriz, M, x;
    

    cin >> qtdeMatriz;
    x = 0 ;
    while (x < qtdeMatriz){
        cin >> M;

        int matriz[M][M];
        memset(matriz, 0, sizeof(matriz) );
        int maiorDigito[M]; // apenas colunas
        memset(maiorDigito, 0, sizeof(maiorDigito) );
        int digitos[M][M];
        memset(digitos, 0, sizeof(digitos) );

        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; i++){
                cin >> matriz[i][j];
            }
        }


        for (int i = 0; i < M; i++){                               // quadrado dos numeros             
            for (int j = 0; j < M; j++){
                matriz[i][j] = matriz[i][j] * matriz[i][j];        // qtde de digitos de todos os numeros
                digitos[i][j] = numberLength(matriz[i][j]); 
            
            }
        }

        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                if(maiorDigito[i] < digitos[j][i]){     // pega o numero com mais digitos da coluna 
                    maiorDigito[i] = digitos[j][i];
                }
            }

            for (int j = 0; j < M; j++){
                if (maiorDigito[i] > digitos[j][i]){
                    digitos[j][i] = maiorDigito[i] - digitos[j][i]; //deixa a matriz digitos apenas com os espaços que serão criados antes do numero
                }
            }
        }

        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                for(int k = 0; k < digitos[j][i]; k++){
                    cout << " ";
                }
                cout << matriz[j][i] << " "  << endl;
            }
        }
        
        x++;
    }

    return 0;
}