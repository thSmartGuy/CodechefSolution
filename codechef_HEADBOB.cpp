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

    std::string s ;
    while(t--){
        std::cin >> n >> s ;

        std::map <char, int> mp ;
        FOR(i, 0, n){
            mp[s[i]]++ ;
        }

        if(mp.count('Y') == 0 && mp.count('I') == 0){ // only N
            std::cout << "NOT SURE\n" ;
        }
        else if(mp.count('I')){
            std::cout << "INDIAN\n" ;
        }
        else{
            std::cout << "NOT INDIAN\n" ;
        }
    }
}

