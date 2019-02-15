#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111 ;

// CODE FROM HERE

int matrix[MAX][MAX] ;

void pre(int n){
    lld start =  1 ;
    for (int k = 0; k < n; k++) {
        int row = 0, col = k;
        while (row < n && col >= 0) {
            matrix[row][col] = start ;
            start++ ;
            row++, col--;
        }
    }

    for (int j = 1; j < n; j++) {
        int col = n - 1, row = j;
        while (row < n && col >= 0) {
            matrix[row][col] = start ;
            start++ ;
            row++, col--;
        }
    }
}


int main(){
    // fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        pre(n) ;

        FOR(i, 0, n){
            FOR(j, 0, n){
                std::cout << matrix[i][j] << " " ;
            }
            std::cout << "\n" ;
        }
    }
}
