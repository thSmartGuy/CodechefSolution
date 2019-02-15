#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 100001 ;

// CODE FROM HERE

std::vector <bool> p(MAX, 1) ;
std::vector <int> prime(MAX, 0) ;

void sieve(){
    FOR(i, 2, MAX){
        if(p[i]){
            prime[i] = 1 ;
            for(int j = 2*i ; j < MAX ; j += i){
                p[j] = 0 ;
                prime[j]++ ;
            }
        }
    }
}


int main(){
     fast() ;
    int t ;

    sieve() ;
    std::cin >> t ;

    int a, b, k ;
    while(t--){
        std::cin >> a >> b >> k ;

        int ans = 0 ;
        FOR(i, a, b + 1){
            if(prime[i] == k) ans++ ;
        }

        print(ans) ;
    }
}

