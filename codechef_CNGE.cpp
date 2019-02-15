#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
     fast() ;

    int n, tmp ;

    std::cin >> n ;

    int n100 = 0, n50 = 0;

    bool poss = 1 ;
    FOR(i, 0, n){
        std::cin >> tmp ;

        if(tmp == 50){
            n50++ ;
        }
        else if(tmp == 100){
            n50-- ;
        }
        else{
            if(n100 > 0){
                n100-- ; n50-- ;
            }
            else n50-=2 ;
        }

        if(n50 < 0 || n100 < 0) poss = 0 ;
    }

    std::cout << (poss ? "YES" : "NO") ;
}

