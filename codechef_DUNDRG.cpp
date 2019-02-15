#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 2*1e6 ;

// CODE FROM HERE
std::vector <int> p(MAX, 2) ;


void sieve(){
    FOR(i, 2, MAX){
        for(int j = 2*i ; j < MAX ; j += i) p[j]++ ;
    }

    FOR(i, 1, MAX){
        if(p[i] == 3){
            count_[i] = 1 + count_[i - 1] ;
        }
        else{
            count_[i] = count_[i - 1] ;
        }
    }
}

int main(){
     fast() ;

    int t, n ;

    sieve() ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        print(count_[n]) ;
    }
}

