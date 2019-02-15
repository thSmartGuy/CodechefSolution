#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1e6 + 5 ;

// CODE FROM HERE
std::vector <int> count_ ;

int main(){
     fast() ;

    int t, n, m, tmp ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> m ;

        count_.assign(MAX, 0) ;
        FOR(i, 0, n + m){
            std::cin >> tmp ;
            count_[tmp]++ ;
        }

        int ans = 0 ;
        FOR(i, 0, MAX){
            if(count_[i] > 1){
                ans += count_[i] - 1 ;
            }
        }

        print(ans) ;
    }
}

