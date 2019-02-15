#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    // fast ;

    std:: string s ;

    std::cin >> s ;

    std::vector <int> alpha(26, 0) ;

    for(int i = 0 ; i < s.size() ; i++)
        alpha[s[i] - 'a']++ ;

    int ans = 0, odd = 0 ;
    if(s.size()%2 == 0){ // NO ODDS ARE ALLOWED
        for(int i = 0 ; i < 26 ; i++)
            if(alpha[i]%2 != 0){
                odd++ ;
            }

        odd = odd/2 ;

        std::cout << odd ;
    }
    else{ // ODD LENGTH ONE ODD IS ALLOWED
        for(int i = 0 ; i < 26 ; i++)
            if(alpha[i]%2 != 0){
                odd++ ;
            }

        odd-- ;
        odd = odd/2 ;

        std::cout << odd ;
    }
}

