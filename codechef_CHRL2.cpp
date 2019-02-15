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
    fast ;

    std::string str ;

    std::cin >> str ;

    std::map <char, int> mp ;
    mp['C'] = 0 ; mp['H'] = 0 ; mp['E'] = 0 ; mp['F'] = 0 ;
    FOR(i, 0, str.size()){
        if(str[i] == 'C'){
            mp['C']++ ;
        }

        if(str[i] == 'H'){
            if(mp['C'] > mp['H']){
                mp['H']++ ;
            }
        }

        if(str[i] == 'E'){
            if(mp['H'] > mp['E']){
                mp['E']++ ;
            }
        }

        if(str[i] == 'F'){
            if(mp['E'] > mp['F']){
                mp['F']++ ;
            }
        }
    }

    std::cout << mp['F'] << "\n" ;
}

