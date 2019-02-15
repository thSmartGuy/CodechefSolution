#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision ;

const int mod = 1e9 + 7 ;

int128_t power(int128_t x, int128_t y){
    int128_t res = 1 ;
    x %= mod ;
    while(y){
        if(y%2 == 1){
            res = (res*x)%mod ;
        }

        y >>= 1 ;
        x = (x*x)%mod ;
    }
    return res ;
}

int128_t modInv(int128_t a, int128_t m = mod){
	if(a == 1)
        return 1 ;
	return power(a, m - 2) ;
}

int main(){
//     fast() ;

    int t, n, k, m ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k >> m ;

        if(m == 1 || n == 1){
            std::cout << modInv(n) << "\n" ;
        }
        else{
            if(n > k && m > 1){
                while(n > k){
                    n -= k ;
                }
                m-- ;
            }

//            std::cout << n << " " << m << "\n" ;

            if(m%2 == 0){
                m = m/2 ;

                int128_t p = 0 ;
                p = (power(n, m)%mod) ;
                p -= (power(n - 1, m)%mod) ;
                if(p < 0) p += mod ;
                p %= mod ;
                p *= (n + k) ;
                p %= mod ;

                p += power(n - 1, m) ; p %= mod ;


                int128_t q = (power(1ll*n, m)*(n + k)) ;
//                std::cout << p << "/" << q << "\n" ;

                int128_t div = gcd(p, q) ;
                p /= div ; q /= div ;

                q = modInv(1ll*q) ;

                std::cout << (p*q)%mod << "\n" ;
            }
            else{
                m = (m + 1)/2 ;

                int128_t p1, p2, p ;
                p1 = (power(n, m)%mod) ;
                p2 = (power(n - 1, m)%mod) ;
                p = p1 - p2 ;
                if(p < 0) p += mod ;
                p %= mod ;

                int128_t q = power(1ll*n, m) ;
//                std::cout << "q: " << q << "\n" ;
                int128_t div = gcd(p, q) ;
                p /= div ; q /= div ;


//                std::cout << p << "/" << q << "\n" ;
                q = modInv(1ll*q) ;
                std::cout << (p*q)%mod << "\n" ;
            }

        }
    }
}
//5 50 50 5 50 50 6 50 50 7 50 50 49 50 50 50
//134456001
//133111441
//131766881
//712259295
//125136698
