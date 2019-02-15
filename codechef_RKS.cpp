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

std::vector <int> row, col ;
std::vector <int> a1, a2 ;

int main(){
    fast() ;

    int t ;

    std::cin >> t ;

    int n, k, r, c ;
    while(t--){
        std::cin >> n >> k ;

        row.assign(n, 0) ; col.assign(n, 0) ;

        FOR(i, 0, k){
            std::cin >> r >> c ;

            row[r - 1] = 1 ; col[c - 1] = 1 ;
        }

        std::cout << n - k << " " ;

        a1.clear() ; a2.clear() ;
        FOR(i, 0, n){
            if(row[i] == 0) a1.push_back(i + 1) ;
            if(col[i] == 0) a2.push_back(i + 1) ;
        }

        FOR(i, 0, n - k){
            std::cout << a1[i] << " " << a2[i] << " " ;
        }
        std::cout << "\n" ;
    }
}

