#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, ans ;

    std::cin >> t ;
    std::string str ;

    while(t--){
        ans = 0 ;
        std::cin >> str ;

        FOR(i, 0, str.size()){
            if(str[i] == '4'){
                ans++ ;
            }
        }

        std::cout << ans << "\n" ;
    }
}
