#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 11 ;

// CODE FROM HERE

int fact[MAX] ;

void pre(){
    fact[0] = 1 ;

    FOR(i, 1, MAX){
        fact[i] = i*fact[i - 1] ;
    }
}

int main(){
    // fast() ;

    int x, n, free ;
    std::string s ;

    int ways ;

    ways = 0 ;
    std::cin >> x >> n ;

    pre() ;
    while(n--){
        std::cin >> s ;

        int count_[MAX] = {} ;
        FOR(i, 0, 54){
            if(s[i] == '0'){
                if(i < 36) count_[i/4]++ ;
                else count_[8 - (i - 36)/2]++ ;
            }
        }

        FOR(i, 0, 9)
        if(count_[i] >= x){
            int z = count_[i] ;
            ways += fact[z]/fact[z - x]/fact[x] ;
        }
    }
    print(ways) ;
}

