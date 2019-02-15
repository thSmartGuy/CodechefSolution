#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

void print(int a, int b) {std::cout << a << " " << b << "\n" ;}

// CODE FROM HERE
int main(){
    fast ;

    int t ;

    std::cin >> t ;

    std::string a, b ;
    while(t--){
        std::cin >> a >> b ;

        int min_ = 0 ;
        int max_ = 0 ;
        FOR(i, 0, a.size()){
            if(a[i] != '?' && b[i] != '?'){
                if(a[i] != b[i])
                    min_++ ;
            }
            else max_++ ;
        }

        print(min_, max_ + min_) ;
    }
}

