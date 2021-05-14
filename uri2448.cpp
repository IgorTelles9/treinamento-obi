#include <bits/stdc++.h>
using namespace std;

int buscaBinaria(int array[], int e, int d, int x){
    while (e<=d){
        int m = e + (d-e)/2;
        if(array[m] == x){
            return m;
        } else if(array[m] < x){
            e = m + 1;
        } else {
            d = m -1;
        }
    }
    return -1;
}

int main(void){

    int n, m, posicaoEntrega, posicaoAtual=0, tempo=0;

    scanf("%d%d", &n, &m);
    int numCasa[n], numEncomenda[m];
    
    for(int i = 0; i < n; i++){
        scanf("%d",&numCasa[i]);
    }
    
    for(int i = 0; i<m; i++){
        scanf("%d", &numEncomenda[i]);
    }

    for (int i=0; i <m; i++){
        posicaoEntrega = buscaBinaria(numCasa, 0, (n-1), numEncomenda[i]);
        tempo += abs(posicaoAtual-posicaoEntrega);
        posicaoAtual = posicaoEntrega;

    }

    printf("%d\n", tempo);

}

