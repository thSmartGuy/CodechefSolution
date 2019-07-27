#include <bits/stdc++.h>

int arr[1000] ;

int getDigitsSum(int n){
    int sum = 0 ;

    while(n){
        sum += n%10 ;
        n /= 10 ;
    }
    return sum ;
}

int main(){
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;

        int max_ = -1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j){
                    max_ = std::max(max_, getDigitsSum(arr[i]*arr[j])) ;
                }
            }
        }
        std::cout << max_ << "\n" ;
    }
}
