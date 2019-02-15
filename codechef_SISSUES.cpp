#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

int main(){
    fast ;

    int t, n ;

    std::cin >> t ;
    std::string str ;

    while(t--){
        std::cin >> n >> str ;

        int ans = 0 ;

        FOR(i, 0, n){
            if(str[i] == '+'){
                ans++ ;
            }
            else{
                ans-- ;
            }

            if(ans < 0){
                break ;
            }
        }

        if(ans >= 0){
            std::cout << "MAYBE YOU ARE SAFE\n" ;
        }
        else{
            std::cout << "FIND A NEW JOB\n" ;
        }
    }
}
