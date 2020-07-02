#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1e5 + 1 ;

// CODE FROM HERE
std::vector <int> primes(MAX, 1) ;

void sieve(){
    FOR(i, 2, MAX){
        if(primes[i] == 1){
            primes[i] = i ;

            for(int j = i*2 ; j < MAX ; j += i) primes[j] = i ;
        }
    }
}

std::vector <int> count_ ;

int main(){
    freopen("input.txt", "r", stdin)
     fast() ;

    sieve() ;
    int t, n, tmp ;

    std::cin >> t ;


    while(t--){
        std::cin >> n ;

        count_.assign(MAX, 0) ;

        FOR(i, 0, n){
            std::cin >> tmp ;

            int local = tmp ;

            while(local > 1){
                int inc = primes[local] ; // GET SMALLEST PRIME OF tmp

                count_[inc]++ ;

                while(local%inc == 0) local /= inc ;
            }
        }

        int max_ = -1 ;
        FOR(i, 2, MAX) max_ = std::max(max_, count_[i]) ;

        print(max_) ;
    }
}

