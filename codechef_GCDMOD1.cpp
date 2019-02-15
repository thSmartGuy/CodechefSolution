#include <iostream>
const int mod = 1e9 + 7 ;
typedef unsigned long long int lld ;

lld calc(lld a, lld n, lld mo = mod){
    auto a1 = a%mo ;
    lld ans = 1 ;
    while(n){
        if(n%2 != 0){
            ans = (1LL*ans*a1)%mo ;
        }
        n = n/2 ;
        a1 = (1LL*a1*a1)%mo ;
    }
    return ans ;
}

lld gcd(lld a, lld b){
    if(a == 0){
        return b ;
    }
    return gcd(b%a, a) ;
}

lld gcdcalc(lld small, lld a, lld b, lld n){
    if(small == 0){
        return (1LL*(calc(a, n) + calc(b, n)))%mod ;
    }
    return gcd((1LL*(calc(a, n, small) + calc(b, n, small)))%small, a - b) ;
}

int main(){
    int t ;
    lld a, b, n ;
    std::cin >> t ;
    while(t--){
        std::cin >> a >> b >> n ;
        std::cout << gcdcalc(a - b, a, b, n)%mod << "\n" ;
    }
}

