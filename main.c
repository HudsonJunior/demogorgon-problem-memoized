#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 214748369
int min(int a,int b){
    if(a > b) return b;
    else return a;
}

long int mana[2001],memo[2001][2001],dano[MAX]; 

void inicializar_memo(){
    int i,j;
    for(i = 0;i<2001;i++){
        for(j = 0;j<2001;j++){
            memo[i][j] = -1;
        }
    }
}

int demogorgon(long int n,long int hp){
    if(hp <= 0)
        return 0;

    if(n < 0) {
        return MAX;
    }

    if(memo[hp][n] == -1){
        return memo[hp][n] = min(mana[n] + demogorgon(n-1,hp-dano[n]),demogorgon(n-1,hp));
    }
    return memo[hp][n];
}

int main(){
    long int hp,feiticos,i;
    long int ans;

    while(scanf("%ld %ld",&feiticos,&hp) != -1){
        inicializar_memo();

        for(i = 0;i<feiticos;i++){
            scanf("%li %li",&dano[i],&mana[i]);
        }

        ans = demogorgon(feiticos-1,hp);
        if(ans >= MAX) printf("-1\n");
        else printf("%li\n",ans);

    }
}
