#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE
int board[MAX][MAX] ;

void init(){
    FOR(i, 0, MAX){
        FOR(j, 0, MAX){
            board[i][j] = 0 ;
        }
    }
}

int main(){
     fast() ;

    int n, m, p, r1, c1, r2, c2 ;

    init() ;
    std::cin >> n >> m >> p ;

    while(p--){
        std::cin >> r1 >> c1 >> r2 >> c2 ;

        board[r1][c1] += 1 ; board[r1][c2 + 1] += -1 ;       // SIMILAR TO ARRAY MANIPULATION
        board[r2 + 1][c1] += -1 ; board[r2 + 1][c2 + 1] += 1 ; // // SIMILAR TO ARRAY MANIPULATION COL WISE
    }

    int l = 0 ;
    FOR(i, 1, n + 2){
        FOR(j, 1, m + 2){
            l += board[i][j] ;
            board[i][j] = l ;
        }
    }

    int ans = 0 ;
    FOR(j, 1, m + 1){
        int ad = 0 ;
        FOR(i, 1, n + 1){
            ad += board[i][j] ;
            board[i][j] = ad ;
            if(ad == 0){
                ans++ ;
            }
        }
    }
//
//    FOR(i, 1, n + 1){
//        FOR(j, 1, m + 1){
//            std::cout << board[i][j] << " " ;
//        }
//        std::cout << "\n" ;
//    }
//    std::cout << "\n" ;

    print(ans) ;
}

