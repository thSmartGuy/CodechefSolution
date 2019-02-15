#include <iostream>
#include <algorithm>
typedef long long int lld ;

int main(){
    int t, n ;
    lld p, q;
    std::cin >> t ;
    while(t-->0){
        std::cin >> n ;
        q = std::pow(10, n) ;
        if(n%2 == 0){
            p = 10*(n/2) ;
        }
        else{
            p = 10*(n/2) ;
        }

        std::cout << p << "\n" << q << "\n" ;
    }
}
