#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    unsigned long long int sum, t ;
    int a, b ;
    int n, count_ ;
    int arr[500000] ;
    std::cin >> t ;
    while(t--){
        std::cin >> n ;
        for(int i = 0 ; i < n ; i++){
            std::cin >> a >> b ;
            arr[i] = (b - a)  ;
        }
        std::sort(arr, arr + n) ;
        sum = 0 ; count_ = 0 ;
        std::cout << "sum_ " << sum << "\n" ;
        std::cout << "count_ " << count_ << "\n" ;
        for(int i = 0 ; i < n ; i++){
            std::cout << arr[i] << "," ;
        }
        std::cout << "\n" ;
        while(count_ < n){
            std::cout << "inside loop \n" ;
            sum = sum + arr[count_] ;
            std::cout << "sum_ " << sum << "\n" ;
            if(sum > 0){
                std::cout << "breaking \n" ;
                break ;
            }
            count_++ ;
            std::cout << "count_ now" << count_ << "\n" ;
        }
        std::cout << count_ << "\n" ;
    }
}
