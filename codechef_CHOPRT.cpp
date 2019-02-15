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
int main(){
    fast ;

    int t, a, b ;

    std::cin >> t ;

    while(t--){
        std::cin >> a >> b ;

        if(a > b){
            std::cout << ">\n" ;
        }
        else if(a < b){
            std::cout << "<\n" ;
        }
        else{
            std::cout << "=\n" ;
        }
    }
}

