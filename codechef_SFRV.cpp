#include <iostream>

int arr[100011] ;
long long ans ;

void findMax(int n){
    long long sum = 0 ;

    for(int i = 0 ; i < n ; i++){
        sum += (long long)(i + 1ll)*arr[i] ;
    }
//
//    if(sum > ans){
//        for(int i = 0 ; i < n ; i++) std::cout << arr[i] << " " ; std::cout << "\n" ;
//    }

    ans = std::max(ans, sum) ;
}

void recur(int idx, int n, bool swapped){
    if(idx == n) return ;

    if(idx == n - 1){
        findMax(n) ;
    }

    if(swapped){ // than cannot swap again
        recur(idx + 1, n, 0) ;
    }
    else{
        if(idx + 1 < n && arr[idx + 1] < arr[idx]){
            std::swap(arr[idx], arr[idx + 1]) ;
            recur(idx + 1, n, 1) ;
            std::swap(arr[idx], arr[idx + 1]) ;
        }
        recur(idx + 1, n, 0) ;
    }
    return ;
}

int main(){
    int t, n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;
        ans = 0 ;

        for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;

        recur(0, n, 0) ;

        std::cout << ans << "\n" ;
    }
}
