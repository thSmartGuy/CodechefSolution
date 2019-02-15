#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision ;

const int mod = 1e9 + 7 ;
//typedef unsigned long long int int128_t ;

int128_t calc(int128_t a, int128_t n, int128_t mo = mod){
    auto a1 = a%mo ;
    int128_t ans = 1 ;
    while(n){
        if(n%2 != 0){
            ans = (ans*a1)%mo ;
        }
        n = n >> 1 ;
        a1 = (a1*a1)%mo ;
    }
    return ans ;
}

int128_t gcd(int128_t a, int128_t b){
    if(a == 0){
        return b ;
    }
    return gcd(b%a, a) ;
}

int128_t gcdcalc(int128_t small, int128_t a, int128_t b, int128_t n){
    if(small == 0){
        return ((calc(a, n) + calc(b, n)))%mod ;
    }
    return gcd(((calc(a, n, small) + calc(b, n, small)))%small, a - b) ;
}

int main(){
    std::ios_base::sync_with_stdio(false) ;
    std::cin.tie(NULL) ;
    int t ;
    int128_t a, b, n ;
    std::cin >> t ;
    while(t--){
        std::cin >> a >> b >> n ;
        std::cout << gcdcalc(a - b, a, b, n)%mod << "\n" ;
    }
}
