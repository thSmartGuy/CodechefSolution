#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 111111

typedef long long int lld  ;

std::vector <int> p ;
std::vector <int> prime(MAX, 0) ;

void sieve(){
    FOR(i, 2, MAX){
        if(prime[i] == 0){
            for(int j = i ; j < MAX ; j += i){
                prime[j] += 1 ;
            }
        }
    }

    FOR(i, 2, MAX){
        if(prime[i] == 1){
            p.push_back(i) ;
        }
    }
}

int main(){
    fast ;

    int t, n, temp ;

    sieve() ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::vector <int> freq(MAX, 0) ;

        FOR(i, 0, n){
            std::cin >> temp ;
            freq[temp]++ ;
        }

        std::vector <int> divBythisNo(MAX, 0) ;

        FOR(i, 2, MAX){
            for(int j = i ; j < MAX ; j += i){
                divBythisNo[i] += freq[j] ;
            }
        }

        lld ans = 0 ;
        FOR(i, 2, MAX){
            int count_ = prime[i] ;
            ans = std::max(ans, 1ll*count_*divBythisNo[i]) ;
        }

        std::cout << ans << "\n" ;
    }
}
