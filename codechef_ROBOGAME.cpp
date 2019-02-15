#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    fast ;

    int t ;

    std::cin >> t ;

    std::string s, orig ;
    while(t--){
        std::cin >> orig ;
        s = "" ;
        int n = orig.size() ;

        FOR(i, 0, n) s += "." ;

        bool safe = 1 ;
        FOR(i, 0, n){
            if(orig[i] != '.'){
                int move_ = orig[i] - '0' ;
                for(int j = std::max(0, i - move_) ; j <= std::min(i + move_, n - 1) ; j++){
                    if(s[j] == '.'){
                        s[j] = 'V' ;
                    }
                    else{
                        safe = 0 ;
                        break ;
                    }
                }
            }
            if(!safe) break ;
        }

        std::cout << (safe ? "safe\n" : "unsafe\n") ;
    }
}

