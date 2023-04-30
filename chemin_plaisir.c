#include <stdio.h>
#define INF 99999

int max_plaisir_chemins(int n, int graph[n*n]) {
    int plaisir_max=0;
    int dist[n*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i*n+j] = graph[i*n+j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i*n+k] + dist[k*n+j] > dist[i*n+j]) {
                    dist[i*n+j] = dist[i*n+k] + dist[k*n+j];
                }
            }
        }
    }
    printf("Distance de tous les chemins possibles au depart de 0 :\n");
    for (int i = 0; i < n; i++) {
        printf("0 -> %d : %d\n", i, dist[i]);
        if (dist[i]>plaisir_max){plaisir_max=dist[i];}
    }
    return(plaisir_max);
}

int main() {
    int n=4;
    int tab[n*n];
    for (int i=0; i<n*n;i++){
        tab[i]=-INF;
    }
    tab[1]=-1;
    tab[6]=2;
    tab[11]=1;
   
    int plaisir = max_plaisir_chemins(n,tab);
    printf("%d\n",plaisir);
    return 0;
}