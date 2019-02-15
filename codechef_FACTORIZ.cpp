#include <iostream>
#include <vector>
#include <cmath>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast ;

    int t ;

    std::cin >> t ;

    std::string str ;
    while(t--){
        std::cin >> str ;

        lld a = 0 ;
        if(str.size() <= 17){
            FOR(i, 0, str.size()){
                a *= 10 ;
                a += str[i] - '0' ;
            }

            std::vector <lld> ans ;

            for(lld i = 2 ; i <= std::sqrt(a) ; i += 2){
                while(a%i == 0){
                    ans.push_back   (i) ;
                    a /= i ;
                }

                if(i == 2) i-- ;

                if(!a) break ;
            }

            if(a){
                ans.push_back(a) ;
            }

            std::cout << ans.size() << "\n" ;

            FOR(i, 0, ans.size()){
                std::cout << ans[i] << "\n" ;
            }
        }
        else{
            std::cout << "1\n" << str << "\n" ;
        }
    }
}

