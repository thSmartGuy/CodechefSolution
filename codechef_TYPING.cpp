#include <iostream>
#include <map>
#include <algorithm>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
const int MAX = 111111 ;

// CODE FROM HERE
int main(){
    // fast ;

    int t, n ;

    std::cin >> t ;

    int hand[256] = {} ;
    hand['d'] = 1 ; hand['f'] = 1 ;
    hand['j'] = 2 ; hand['k'] = 2 ;

    std::string str ;
    while(t--){
        std::cin >> n ;

        std::map <std::string, int> mp ; // word -> time
        int time_ = 0 ;
        while(n--){
            std::cin >> str ;
            if(mp.count(str)){
                time_ += mp[str] ;
                continue ;
            }

            int local_time = 0 ;
            FOR(i, 0, str.size()){
                if(i != 0 && hand[str[i]] == hand[str[i - 1]]){
                    local_time += 4 ;
                }
                else{
                    local_time += 2 ;
                }
            }

            time_ += local_time ;
            mp[str] = local_time/2 ;
        }

        std::cout << time_ << "\n" ;
    }
}

