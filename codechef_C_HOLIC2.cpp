#include <iostream>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
typedef long long int lld ;

int main(){
    fast ;

    int t, p ;
    lld count_ ;

    std::cin >> t ;

    while(t-->0){
        std::cin >> p ;

        for(lld i = p*4 ; i <= p*5 ; i+=5){

            count_ = 0;

            for(lld j = 5 ; j <= i ; j*=5){
                count_ += (1LL*i)/j ;
            }

            if(count_ >= p){
                std::cout << i << "\n" ;
                break ;
            }
        }
    }
}
