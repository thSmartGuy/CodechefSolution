#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE

void print(int a){std ::cout << a << "\n" ;}

int main(){
    fast ;

    int t, n, k ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> k ;

        if(k > n){
            print(n) ;
        }
        else{
            int max_ = 0 ;
            FOR(i, 2, k + 1){
                int temp = n%i ;
                if(temp > max_) max_ = temp ;
            }
            print(max_) ;
        }
    }
}

