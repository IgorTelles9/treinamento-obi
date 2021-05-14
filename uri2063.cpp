#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {

    vector <int> contadorCiclos;
    vector <int> contadorCiclosAux;
    int qtdeBuracos;
    
    cin >> qtdeBuracos;
    int buracos [qtdeBuracos + 1];
    memset(buracos, 0, sizeof(buracos));
    int buracoChecker [qtdeBuracos + 1];
    memset(buracoChecker, 0, sizeof(buracoChecker));
    int contador, tempoFinal;

    for (int i = 1; i <= qtdeBuracos; i++){
        scanf("%d", &buracos[i]);
    }


    /* 
        Esse loop entra em todos os buracos informados e 
        armazena os ciclos de túneis de digletts
    */
    for(int i = 1; i <= qtdeBuracos; i++){
        if(!buracoChecker[i]){                      // entra no máximo uma vez por buraco
            buracoChecker[i]=1;                     // essa linha diz: ja passei por esse buraco       
            contador = 1;                           // novo ciclo detectado, contador = 1;
            int u = buracos [i];                    // u = localizacao do diglet i no tempo T1 

            // esse while entra em todos os buracos de um ciclo;                            
            while(!buracoChecker[u]){               // se o diglet i esta em u, há um tunel entre u e i; ou seja, fazem parte do mesmo ciclo         
                buracoChecker[u] = 1;               // essa linha diz: ja passei por esse buraco 
                u = buracos[u];                     // u = localizacao do diglet que em T0 estava em buracos[i]
                contador++;                         
            }
        
            contadorCiclos.push_back(contador);     // ciclo encerrado; adiciona o tamanho do ciclo ao vector
        }
    }
    //cout << contadorCiclos[0] << endl << contadorCiclos[1] << endl;
    
    tempoFinal = 1;
    for(auto i:contadorCiclos){
        tempoFinal = (tempoFinal * i) /__gcd(tempoFinal, i);
    }
    cout << tempoFinal << endl;
    
}
