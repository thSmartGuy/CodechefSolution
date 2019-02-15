#include <iostream>
#include <algorithm>
#include <iomanip>

int main(){
    int t, n ;
    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        double arr[n] ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        std::sort(arr, arr + n) ;

        for(int i = n - 2 ; i >= 0 ; i--){
            arr[i] = arr[i] + (arr[i + 1] - arr[i])/2 ;
        }
        std::cout << std::fixed << std::setprecision(8) << arr[0] << "\n" ;
    }
}
