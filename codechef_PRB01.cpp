#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
const int MAX = 111111 ;
typedef long long int lld  ;

lld gcd(lld a, lld b){
    if(!a)
        return b ;
    return gcd(b%a, a) ;
}

// CODE FROM HERE

std::vector <bool> prime(MAX, true) ;

void sieve(){
    prime[1] = 0 ;
    FOR(i, 2, MAX){
        if(prime[i]){
            for(int j = i*2 ; j < MAX ; j += i){
                prime[j] = false ;
            }
        }
    }
}

int main(){
    fast ;

    int t, n ;

    sieve() ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        if(prime[n]){
            std::cout << "yes\n" ;
        }
        else{
            std::cout << "no\n" ;
        }
    }
}
