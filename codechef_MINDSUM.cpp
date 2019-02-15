#include <iostream>
#include <climits>
#include <vector>
typedef long long int lld ;

int noOfDigits(lld n){
    int ans = 0 ;

    while(n){
        ans++ ;
        n /= 10 ;
    }

    return ans ;
}

int digitSum(lld n){
    int sum = 0 ;

    while(n){
        sum += n%10 ;
        n /= 10 ;
    }

    return sum ;
}

std::pair <lld, int> mindSum(lld n, lld d, int times){

    if(times >= 15){
        return std::make_pair(INT_MAX, times) ;
    }

    if(noOfDigits(n) == 1){
        return std::min(std::make_pair(n, times), mindSum(n + d, d, times + 1)) ;
    }

    return std::min(mindSum(digitSum(n), d, times + 1), mindSum(n + d, d, times + 1)) ;
}

int main(){
    int t;
    lld n, d, times ;

    std::cin >> t ;

    while(t--){
        std::cin >> n >> d ;

        std::pair <lld, int> temp = mindSum(n, d, 0) ;

        std::cout << temp.first << " " << temp.second << "\n" ;
    }
}
