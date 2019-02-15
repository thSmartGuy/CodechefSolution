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

    int t ;

    std::cin >> t ;

    std::map <char, std::string> class_ ;

    class_['B'] = "BattleShip" ; class_['b'] = "BattleShip" ;
    class_['C'] = "Cruiser" ; class_['c'] = "Cruiser" ;
    class_['D'] = "Destroyer" ; class_['d'] = "Destroyer" ;
    class_['F'] = "Frigate" ; class_['f'] = "Frigate" ;

    char c ;
    while(t--){
        std::cin >> c ;

        std::cout << class_[c] << "\n" ;
    }
}

