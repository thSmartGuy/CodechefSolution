#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 700000 ;

// CODE FROM HERE
std::vector <int> arr(50055) ;
std::vector <bool> p(MAX, true) ;
std::vector <int> primes ;

const int mod = 1e9 + 1 ;

void verify(int n){
    std::cout << "__________________________________________________\n" ;

    std::cout << "Verifying for " << n << "\n" ;
    FOR(i, 0, n){
        if(gcd(arr[i], arr[(i + 1)%n]) == 1){
            std::cout << i << " pe 2 wala galat hai\n" ;
//            return ;
        }


        if(gcd(gcd(arr[i], arr[(i + 1)%n]), arr[(i + 2)%n]) != 1){
            std::cout << i << " pe 3 wala galat hai :: " << gcd(gcd(arr[i], arr[(i + 1)%n]), arr[(i + 2)%n]) << "\n" ;
//            return ;
        }
    }
    std::cout << "__________________________________________________\n" ;
}

void sieve(){
    for (int i=2; i*i<=MAX; i++){
        if (p[i]){
            for (int j=i*i; j<=MAX; j += i)
                p[j] = false;
        }
    }

    FOR(i, 2, MAX){
        if(p[i]){
            primes.push_back(i) ;
        }
    }
}

lld power(int a, int y){
    lld ans = 1 ;

    while(y){
        if(y%2 == 1)
            ans *= a ;
        a = a*a ;
        y /= 2 ;
    }

    return ans ;
}

int main(){
    fast() ;

    int t, n ;

    sieve() ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        FOR(i, 0, n){
            arr[i] = primes[i + 4] ;
        }

        int mul[] = {10, 6, 15} ;

        int j = 0 ;
        FOR(i, 0, n){
            arr[i] *= mul[j++] ;
            j %= 3 ;
        }

        if(n%3 == 1){
            arr[n - 1] = 77*primes[n - 1 + 4] ;
            arr[n - 2] *= 7 ;
            arr[0] *= 11 ;
        }

        if(n%3 == 2){
            arr[n - 1] = 77*primes[n - 1 + 4] ;
            arr[n - 2] *= 7 ;
            arr[0] *= 11 ;
        }

//        verify(n) ;

        FOR(i, 0, n){
            std::cout << arr[i] << " " ;
        }
        std::cout << "\n" ;
    }
}
