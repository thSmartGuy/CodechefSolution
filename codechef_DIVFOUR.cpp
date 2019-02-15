#include <iostream>
#include <cmath>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

// NOT DONE

typedef long long int lld  ;
const int mod = 1e9 + 7 ;

lld power(lld times){
    //std::cout << times << "\n" ;
    if(times == 0){
        return 1 ;
    }

    return (2*power(times - 1))%mod ;
}

int main(){
    fast ;

    std::string big ;

    std::cin >> big ;

    int ans = 0 ;
    for(int i = big.size() - 1 ; i >= 0 ; i--){
        if((big[i] - '0')%4 == 0){
            ans = (ans + 1)%mod ;
        }

        for(int j = i - 1 ; j >= 0 ; j--){
            if(((big[i] - '0') + (big[j] - '0')*10)%4 == 0){
                ans = ((lld)(ans + power(j)))%mod ;
            }
        }
    }

    //std::cout << power(100000) ;
    std::cout << ans ;
}

