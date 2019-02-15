#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;

typedef long long int lld  ;

int main(){
    fast ;
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        int arr[n] ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        if(n%2 == 1){
            std::cout << "NO\n" ;
        }
        else{
            int flag = 1 ;
            for(int i = 0 ; i < n/2 ; i++){
                if(arr[i] == -1 && arr[i + n/2] == -1){
                    arr[i] = 1 ;
                    arr[i + n/2] = 1 ;
                }
                else if(arr[i] == -1 || arr[i + n/2] == -1){
                    if(arr[i] == -1){
                        arr[i] = arr[i + n/2] ;
                    }
                    else{
                        arr[i + n/2] = arr[i] ;
                    }
                }
                else if(arr[i] != arr[i + n/2]){
                    std::cout << "NO\n" ;
                    flag = 0 ;
                    break ;
                }
                else{
                    // possible
                }
            }

            if(flag){
                std::cout << "YES\n" ;
                for(int i = 0 ; i < n ; i++){
                    std::cout << arr[i] << " " ;
                }
                std::cout << "\n" ;
            }
        }
    }
}

