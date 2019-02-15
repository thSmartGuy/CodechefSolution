#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
void pre(bool **grid, int n, int m){
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(i%2 == 0){ // fill odd columns
                if(j%2 != 0){
                    grid[i][j] = 1 ;
                }
            }
            else{ // fill even columns
                if(j%2 == 0){
                    grid[i][j] = 1 ;
                }
            }
        }
    }
}

int count_(bool **grid, int i, int j, int n, int m){
    int count__ = 0 ;

    if(i - 1 >= 0){ // up
        if(grid[i - 1][j]){
            count__++ ;
        }
    }

    if(i + 1 <= n - 1){ // down
        if(grid[i + 1][j]){
            count__++ ;
        }
    }

    if(j - 1 >= 0){ // left
        if(grid[i][j - 1]){
            count__++ ;
        }
    }

    if(j + 1 <= m - 1){ //right
        if(grid[i][j + 1]){
            count__++ ;
        }
    }

    grid[i][j] = 1 ;

    return count__ ;
}

int main(){
    fast ;

    int t, n, m ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;
//
//        bool **grid = new bool*[n] ;
//        FOR(i, 0, n){
//            grid[i] = new bool[m] ;
//        }
//
//        pre(grid, n, m) ;
//
//        int ans = 0 ;
//
//        FOR(i, 0, n){
//            FOR(j, 0, m){
//                if(grid[i][j] == 0){
//                    ans += count_(grid, i, j, n, m) ;
//                }
//            }
//        }
//
//        std::cout << ans << "\n" ;

        // COLOR IN ANY ORDER ANSWER WILL BE SAME

        std::cout << n*(m - 1) + m*(n - 1) << "\n" ;
    }
}

