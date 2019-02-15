#include <iostream>

int sqroot(int n){
    int i ;
    for(i = 1 ; i*i <= n ; i++) ;

    return i - 1;
}

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int t, n ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        std::cout << sqroot(n) << "\n" ;
    }
}
