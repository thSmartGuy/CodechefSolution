#include <iostream>
const int N = 200 + 1 ;

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int t, n ;
    long sum ;

    std::cin >> t ;

    bool one ;
    while(t--){
        sum = 0 ;
        one = false ;
        std::cin >> n ;

        int arr[n] ;
        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
            sum += arr[i] ;
            if(arr[i] == 1){
                one = true ;
            }
        }

        if(!one){
            std::cout << n << "\n" ;
        }
        else{
            if(arr[0] == 2 && arr[n - 1] == 2){
                std::cout << sum - 1 << "\n" ;
            }
            else{
                std::cout << sum << "\n" ;
            }
        }
    }
}

