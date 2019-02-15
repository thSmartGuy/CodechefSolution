#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 10001 ;

// CODE FROM HERE
int dp[MAX][MAX] ;

void pre(){
    FOR(i, 0, MAX){
        FOR(j, 0, MAX){
            dp[i][j] = 0 ;
        }
    }
}

int minimumSquare(int m, int n){
    if(m == n){
        return 1 ;
    }

    if(dp[m][n]) return dp[m][n] ;

    int max1 = INT_MAX, max2 = INT_MAX ;

    FOR(i, 1, m/2){
        max1 = std::min(minimumSquare(i, n) + minimumSquare(m - i, n), max1) ;
    }

    FOR(i, 1, n/2){
        max2 = std::min(minimumSquare(m, i) + minimumSquare(m, n - i), max2) ;
    }

    dp[m][n] = std::min(max1, max2) ;

    return dp[m][n] ;
}

int main(){
    // fast() ;

    int t, n, m ;

    std::cin >> t ;

    pre() ;
    while(t--){
        std::cin >> m >> n ;

        std::cout << minimumSquare(m, n) << "\n" ;
    }
}
