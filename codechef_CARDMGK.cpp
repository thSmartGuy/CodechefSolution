#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

std::vector <int> arr ;

int main(){
    // fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        arr.clear() ; arr.resize(n) ;

        FOR(i, 0, n) std::cin >> arr[i] ;

        bool flag = 1 ;
        FOR(i, 1, n){
            if(arr[i - 1] > arr[i]){ // one decreasing
                FOR(j, i + 1, n){
                    if(arr[j - 1] > arr[j]){ // more than one decreasing
                        flag = 0 ;
                        break ; break ;
                    }
                }
                if(arr[n - 1] > arr[0]){ // last one should be smaller than the first one
                    flag = 0 ;
                    break ;
                }
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n") ;
    }
}

