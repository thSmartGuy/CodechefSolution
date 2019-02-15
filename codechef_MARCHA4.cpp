#include <iostream>
#include <math.h> // log
#include <iomanip>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE

int power10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int  mod ;
int lastK(lld n, lld b, int mod){
    lld res = 1 ;

    lld power = n ;
    while(b){
        if(b % 2 == 1){
            res = (1ll * res * power) % mod ;
        }
        power = (1ll * power * power) % mod ;
        b /= 2 ;
    }

    return res ;
}

int main(){
    //fast() ;
    int t, n, k ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;

        //  mod = std::pow(10, k); // std::pow is INCOSITENT AD GAVE WRONG RESULTS DUE TO FLOATING
        // => x = n^n
        // => log10(x) = n*log10(n)
        // => x = (10^n)*(10^log10(n))
        long double val = n*log10(n) ;
        //print(val) ;
        long double decPart = std::fmod(val, 1) ;
        //print(decPart) ;
        decPart = std::pow(10, decPart) ;


        long double mul = (decPart*power10[k - 1]) ;
        mul = int(mul) ;
        //print(mul) ;

        std::cout << mul << " " ;
        lld ans = lastK(n, n, power10[k]) ;
        std::cout << std::setfill('0') << std::setw(k) << ans << "\n" ;
    }
}

//367879442 999999999

