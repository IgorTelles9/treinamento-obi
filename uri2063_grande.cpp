#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {

    vector <int> contadorCiclos;
    vector <int> contadorCiclosAux;
    int qtdeBuracos;
    
    cin >> qtdeBuracos;
    int buracos [qtdeBuracos];
    memset(buracos, 0, sizeof(buracos));
    int buracoChecker [qtdeBuracos];
    memset(buracoChecker, 0, sizeof(buracoChecker));
    int contador, qtdeCiclos, tempoFinal;

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
    bool fim = false;
    bool unicoCiclo = false;
    int k = 0;
    while (!fim){
        if (contadorCiclos.size() == 1){
            fim = true;
            unicoCiclo = true;
            tempoFinal = contadorCiclos[0];
        } 
        else{
            for (int k = 0; k < contadorCiclos.size(); k+=2){
                if (contadorCiclos[k] && contadorCiclos[k+1]){
                    contadorCiclosAux.push_back ( __gcd(contadorCiclos[k], contadorCiclos[k+1]) );
                } 
                else {
                    contadorCiclosAux.push_back (contadorCiclos[k]);
                }
            }
        
            if (contadorCiclosAux.size() == 1){
                tempoFinal = contadorCiclosAux[0];
                fim = true;

            }
            else if (contadorCiclosAux.size() == 2){
                tempoFinal = __gcd (contadorCiclosAux[0], contadorCiclosAux[1]);
                fim = true;

            } 
            else {
                contadorCiclos.clear();
                for (int j = 0; j < contadorCiclosAux.size(); j++){
                    contadorCiclos [j] = contadorCiclosAux[j];

                }
                contadorCiclosAux.clear();
            }  
        }  
    }

    if (unicoCiclo){
        cout << tempoFinal;
    } else{
        tempoFinal = (contadorCiclos[0] * contadorCiclos[1])/tempoFinal;
        cout << tempoFinal <<endl;
    }
    
}
