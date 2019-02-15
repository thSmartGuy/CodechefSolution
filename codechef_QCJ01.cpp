#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 8 ;

// CODE FROM HERE
void solve(int r, int c, int x, int y, int turn){
    if(turn == 1 && (r == 8)){
        std::cout << "Black\n" ;
        return ;
    }

    if(turn == 2 && (x == 1)){
        std::cout << "White\n" ;
        return ;
    }

    if(turn == 1 && r + 1 == x && (c + 1 == y || c - 1 == y)){
        std::cout << "White\n" ;
        return ;
    }

    if(turn == 2 && x - 1 == r && (y - 1 == c || y + 1 == c)){
        std::cout << "Black\n" ;
        return ;
    }

    if(turn == 1) solve(r + 1, c, x, y, 2) ;
    if(turn == 2) solve(r, c, x - 1, y, 1) ;
}

int main(){
    // fast() ;

    int t ;

    std::cin >> t ;

    int r1, c1, r2, c2 ;
    while(t--){
        std::cin >> r1 >> c1 >> r2 >> c2 ;

        if(c1 == c2){
            while(1){
                r1++ ;
                if(r1 == r2 || r1 > 8){
                    print("Black") ;
                    break ;
                }
                r2-- ;
                if(r1 == r2 || r2 < 1){
                    print("White") ;
                    break ;
                }
            }
        }
        else if(std::abs(c1 - c2) > 1){
            while(1){
                r1++ ;
                r2-- ;

                if(r1 > 8){
                    print("Black") ;
                    break ;
                }

                if(r2 < 1){
                    print("White") ;
                    break ;
                }
            }
        }
        else{
            solve(r1, c1, r2, c2, 1) ;
        }
    }
}

