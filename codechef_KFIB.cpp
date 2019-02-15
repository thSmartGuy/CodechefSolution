#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;
const int mod = 1e9 + 7 ;

long long sum[2000000];
int main(){
     fast ;
    int n, k ;

    std::cin >> n >> k ;

    sum[0] = 0 ;
    sum[k + 1] = k ;

    for(int i = 1 ; i <= k ; i++){
        sum[i] = 1 ;
    }

    for(int i = k + 2 ; i <= n ; i++){
        sum[i]=(sum[i-1]-sum[i-k-1]+sum[i-1])%mod;
    }

    std::cout << sum[n] ;
}

