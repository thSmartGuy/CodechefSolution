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

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int f = n ; int b = 0 ;

        int m = 10 ;
        while(n){
//            std::cout << "n%10: " << n%10 << "\n" ;
            b = b*m + (n%10) ;
//            std::cout << "m: " << m << "\n" ;
//            std::cout << "b: " << b << "\n";
            n /= 10 ;
        }

        if(f == b){
            std::cout << "wins\n" ;
        }
        else{
            std::cout << "losses\n" ;
        }
    }
}

