#include <iostream>
typedef long long int lld ;

int main(){
    int t, p1, p2, k ;
    lld sum ;

    std::cin >> t ;

    while(t--){
        std::cin >> p1 >> p2 >> k ;
        sum = p1 + p2 ;

        int times = sum/((lld)k) ;
       // odd == cook even == chef

        if(times%2 == 1){
            std::cout << "COOK\n" ;
        }
        else{
            std::cout << "CHEF\n" ;
        }
    }
}
