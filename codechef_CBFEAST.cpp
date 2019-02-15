#include <iostream>
#include <deque>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast ;

    int q, k, b, C, d, c ;

    std::cin >> q >> k ;

    std::deque <std::pair <int, int>> dish ;
    int ans = 0 ;

    while(q--){
        std::cin >> b >> C ;

        if(b == 1 || b == 2){
            std::cin >> d ;
            c = C^ans ;
            if(b == 1){
                dish.push_front(std::make_pair(c, d)) ;
            }
            else{
                dish.push_back(std::make_pair(c, d)) ;
            }
        }
        else{ // b == 3
            c = C ;
            lld temp = 0 ;
            FOR(i, 0, dish.size()){
                 if(dish[i])
            }
        }
    }
}

