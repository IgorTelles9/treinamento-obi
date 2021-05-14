#include <bits/stdc++.h>
using namespace std;

int main () {
    int qtdeFigurinhas, qtdeFigurinhasCarimbadas, qtdeFigurinhasCompradas;

    cin >> qtdeFigurinhas;
    cin >> qtdeFigurinhasCarimbadas;
    cin >> qtdeFigurinhasCompradas;
    
    int figurinhasCarimbadas [qtdeFigurinhasCarimbadas], figurinhasCompradas [qtdeFigurinhasCompradas];
    memset(figurinhasCompradas, 0, sizeof(figurinhasCompradas) );
    int carimbadasRestantes = qtdeFigurinhasCarimbadas;
    int figurinhaAtual;
    bool figurinhaValida;
    
    for (int i = 0; i < qtdeFigurinhasCarimbadas; i++){
        cin >> figurinhasCarimbadas[i];
    }

    for (int i =0; i < qtdeFigurinhasCompradas; i++){
        cin >> figurinhaAtual;
        figurinhaValida = true;
        
        for (int j = 0; j < i; j++){
            if (figurinhaAtual == figurinhasCompradas[j]){
                figurinhaValida = false;
            }
        }

        if (figurinhaValida){
            figurinhasCompradas[i] = figurinhaAtual;
        }
    }

    for (int i  = 0; i < qtdeFigurinhasCarimbadas; i++){
        for (int j = 0; j < qtdeFigurinhasCompradas; j++){
            if (figurinhasCarimbadas[i] == figurinhasCompradas [j]){
                carimbadasRestantes--;
            }
        }
    }

    cout << carimbadasRestantes << endl;

    return 0;
}
