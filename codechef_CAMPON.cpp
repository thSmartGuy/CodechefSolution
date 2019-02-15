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
    // fast ;

    int t ;

    std::cin >> t ;

    while(t--){
        int d ;
        std::cin >> d ;
        std::vector <std::pair <int, int>> prob(d) ;
        FOR(i, 0, d){
            std::cin >> prob[i].first >> prob[i].second ;
        }

        std::sort(prob.begin(), prob.end()) ;
        int ans[32] ;

        lld l = 0 ;
        FOR(i, 1, 32){
            FOR(j, 0, d){
                if(prob[j].first == i)
                    l += prob[j].second ;
            }
            ans[i] = l ;
        }

        int q ;

        std::cin >> q ;

        int dead, req ;
        while(q--){
            std::cin >> dead >> req ;

            if(ans[dead] >= req){
                std::cout << "Go Camp\n" ;
            }
            else{
                std::cout << "Go Sleep\n" ;
            }
        }
    }
}

