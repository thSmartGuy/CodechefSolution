#include <iostream>
#include <set>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 11 ;

// CODE FROM HERE
int main(){
    fast ;

    int t, m, x, y ;

    std::cin >> t ;

    while(t--){
        std::cin >> m >> x >> y ;

        int range = x*y ;

        std::set <int> notsafe ;

        int police ;
        FOR(i, 0, m){
            std::cin >> police ;
            FOR(i, std::max(1, police - range), std::min(101, police + range + 1)){
                notsafe.insert(i) ;
            }
        }
        int ans = 0 ;

        FOR(i, 1, 101){
            if(notsafe.find(i) == notsafe.end()){
                ans++ ;
            }
        }

        print(ans) ;
    }
}

