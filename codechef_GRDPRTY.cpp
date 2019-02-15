#include <iostream>
#include <cstdio>
#include <vector>
typedef long long int lld ;

std::vector <int> pre(1000000) ;

void init(){
    pre[0] = 1 ;
    int sum = 2 ;
    for(int i = 1 ; i < 1000000 ; i++){
        pre[i] = pre[i - 1] + sum ;
        sum++ ;
        if(pre[i] > 10000000){
            break ;
        }
    }
}

int main(){
    int t, n ;
    scanf("%d", &t) ;
    init() ;
    while(t-->0){
        scanf("%d", &n) ;
        for(int i = 0 ; i < 1000000 ; i++){
            //std::cout << pre[i] << "\n" ;
            if(n == pre[i]){
                printf("%d\n", i + 1) ;
                break ;
            }
            if(pre[i] > 10000000){
                printf("-1\n") ;
                break ;
            }
        }
    }
}

