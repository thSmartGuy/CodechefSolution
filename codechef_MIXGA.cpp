#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>

//typedef long long int lld;

int main(){
    std::ios_base::sync_with_stdio(false) ;
    //std::cin.tie(NULL) ; std::cout.tie(NULL) ;

    int t, n, k ;
    std::cin >> t ;
    int arr[30001] ;
    int sum ;

    while(t-->0){
        sum = 0 ;
        std::cin >> n >> k ;

        for(int i = 1 ; i <= n ; i++){
            std::cin >> arr[i] ;
        }

        for(int i = 1 ; i <= n ; i++){
            if(arr[i] == 0){
                continue ;
            }

            if(i%2 == 1){ // Vturn
                if(sum >= 0){
                    sum += arr[i] ;
                }
                else if(sum < 0){
                    sum -= arr[i] ;
                }
            }
            else{ // M turn
                if(sum > 0){
                    sum -= arr[i] ;
                }
                else{
                    sum += arr[i] ;
                }
            }
        }

        if(std::abs(sum) >= k){
            std::cout << 1 << "\n" ;
        }
        else{
            std::cout << 2 << "\n" ;
        }
    }

    return 0 ;
}
