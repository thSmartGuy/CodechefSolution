#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

template <class olaola>
void print(olaola a) {std::cout << a << "\n" ;}

int main(){
    fast ;

    int t ;

    std::cin >> t ;

    double h, c, ten ;
    while(t--){
        std::cin >> h >> c >> ten ;

        int grade ;
        if(h > 50 && c < 0.7 && ten > 5600) print(10) ;
        else if(h > 50 && c < 0.7) print(9) ;
        else if(c < 0.7 && ten > 5600) print(8) ;
        else if(h > 50 && ten > 5600) print(7) ;
        else if(h > 50 || c < 0.7 || ten > 5600) print(6) ;
        else print(5) ;
    }
}

