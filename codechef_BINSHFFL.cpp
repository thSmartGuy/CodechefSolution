#include <iostream>
#include <cstdio>
#define scan(n) scanf("%d", &n)
#define scan2(n, m) scanf("%lld%lld", &n, &m)
#define rep(i, n, k) for(int i = k ; i < n ; i++)
#define print(a) printf("%d\n", a)
typedef long long int lld ;

int findbits(lld a){
    int setBits = 0;
    while(a){
        if(a%2 == 1){
            setBits++ ;
        }
        a = a >> 1 ;
    }
    return setBits ;
}

int main(){
    int t, bitsA, bitsB ;
    lld a, b ;
    scan(t) ;
    while(t-->0){
        scan2(a, b) ;
        if(a == b){
            print(0) ;
        }
        else if(b <= 1 && a){
            print(-1) ;
        }
        else{
            bitsA = findbits(a) ;
            bitsB = findbits(b-1) ;
            if(bitsB >= bitsA){
                print(bitsB - bitsA + 1) ;
            }
            else{
                print(2) ;
            }
        }
    }
}
