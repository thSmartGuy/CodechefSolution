#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 8 ;

// CODE FROM HERE
int board[MAX][MAX] ;

int solve(int r, int c, int k){
    FOR(i, 0, MAX){
        FOR(j, 0, MAX){
            board[i][j] = 0 ;
        }
    }

    FOR(i, 0, MAX){
        int d1 = std::abs(i - r) ;
        FOR(j, 0, MAX){
            int d2 = std::abs(j - c) ;
            if(std::max(d1, d2) <= k){
                board[i][j] = 1 ;
            }
        }
    }

    int count_ = 0 ;
    FOR(i, 0, MAX){
        FOR(j, 0, MAX){
            if(board[i][j]) count_++ ;
        }
    }

    return count_ ;
}

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int r, c, k ;
    while(t--){
        std::cin >> r >> c >> k ; r-- ; c-- ;

        print(solve(r, c, k)) ;
    }
}

