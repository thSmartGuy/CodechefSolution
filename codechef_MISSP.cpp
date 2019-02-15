#include <iostream>
#include <map>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 111111 ;

// CODE FROM HERE
std::map <int, int> mp ;

int main(){
    fast() ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        mp.clear() ;
        std::cin >> n ;

        int temp ;
        FOR(i, 0, n){
            std::cin >> temp ;

            mp[temp]++ ;
        }

        for(auto itr : mp){
            if(itr.second%2 == 1){
                print(itr.first) ;
                break ;
            }
        }
    }
}

