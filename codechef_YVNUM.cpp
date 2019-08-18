#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int mod = 1e9 + 7 ;

void fast(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0) ;
}

long long modPower[111111] ;

void preModPower(){
    modPower[0] = 1 ;

    for(int i = 1 ; i < 100011 ; i++){
        modPower[i] = (modPower[i - 1]*10)%mod ;
    }
}

int main(){
    int t = 1 ;
    std::cin >> t ;

    //fast();
    preModPower() ;

    std::string num ;
    while(t--){
        std::cin >> num ;
        const long long n = num.size() ;

        long long curNum = 0 ;
        for(char c: num){
            curNum = ((curNum*10)%mod + (c - '0'))%mod ;
        }

        // curName currently have result of num%mod ;

        std::string tmpNum = num ;
        tmpNum += num ;

        //std::cout << "num; " << tmpNum << "\n" ;

        long long ans = curNum ;
        for(int shift = 1 ; shift < n ; shift++){
          //  std::cout << tmpNum.substr(shift, n) << "\n" ;
            curNum = ((curNum - ((long long)(num[shift - 1] - '0')*modPower[n - 1])%mod)%mod + mod)%mod ;
            curNum = (curNum*10ll)%mod ;
            curNum = (curNum + (num[shift - 1] - '0'))%mod ;

            ans = ((ans*modPower[n])%mod + curNum)%mod ;
        }
        std::cout << ans << "\n" ;
    }
}