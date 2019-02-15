#include <iostream>
#include <climits>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

int goals[100000] ;
int mini[100000] ;

int main(){
    //fast ;

    int t, n ;

    std::cin >> t ;

    while(t--){
        int diff = INT_MIN ;
        std::cin >> n ;

        for(int i = 0; i < n ; i++){
            std::cin >> goals[i] ;
            mini[i] = goals[i] ;
        }

        for(int i = 1; i < n ; i++){
            mini[i] = std::min(mini[i - 1], goals[i]) ;
            diff = std::max(diff, goals[i] - mini[i]) ;
        }

        if(diff > 0){
            std::cout << diff << "\n" ;
        }
        else{
            std::cout << "UNFIT\n" ;
        }
    }
}
