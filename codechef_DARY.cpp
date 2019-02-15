#include <cmath>
#include <iostream>

int main(){
    int t, n, ans ;
    std::cin >> t ;
    std::string str ;
    while(t--){
        std::cin >> str ;
        n = str.size() ;
        if(n%2 == 0){
            ans = n*n/4 ; // equivalent of n = n/2 ; ans = n*n/4 ;
        }
        else{
            ans = (n*n - 1)/4 ; // equivalent of n = (n + 1)/2 ; ans = n*(n - 1) ;
        }
        std::cout << ans << "\n" ;
    }
}
