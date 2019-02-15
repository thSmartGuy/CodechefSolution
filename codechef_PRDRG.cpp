
#include <iostream>
#include <cmath>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

lld x[26], y[26] ;

lld gcd(lld a, lld b){
    if(a == 0){
        return b ;
    }

    return gcd(b%a, a) ;
}

void pre(){
    x[1] = 1 ; x[2] = 1 ;
    y[1] = 2 ; y[2] = 4 ;

    lld div ;
    for(int i = 3 ; i <= 25 ; i++){
        x[i] = (lld)(1LL*y[i - 2]*x[i - 1] + 1LL*x[i - 2]*y[i - 1]) ;
        y[i] = (lld)(1LL*2*y[i - 1]*y[i - 2]) ;

        if(x[i] < y[i])
            div = gcd(x[i], y[i]) ;
        else{
            div = gcd(y[i], x[i]) ;
        }

        x[i] = x[i]/div ;
        y[i] = y[i]/div ;
    }
}

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;

    pre() ;
    while(t--){
        std::cin >> n ;

        std::cout << x[n] << " " << y[n] << " " ;
    }
}
