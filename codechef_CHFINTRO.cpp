#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int n, r ;

    std::cin >> n >> r ;

    int rat ;
    while(n--){
        std::cin >> rat ;

        if(rat < r){
            std::cout << "Bad boi\n" ;
        }
        else{
            std::cout << "Good boi\n" ;
        }
    }
}

