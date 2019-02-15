#include <iostream>
#define rep(i, n) for(int i = 1 ; i < n ; i++)

int main(){
    int t, n, k, kvalue, kpos ;
    std::cin >> t ;
    while(t-->0){
        kpos = 1 ;
        std::cin >> n ;
        int arr[n+1] ;
        rep(i, n + 1){
            std::cin >> arr[i] ;
        }
        std::cin >> k ;
        kvalue = arr[k] ;

        rep(i, n + 1){
            if(arr[i] < kvalue){
                kpos++ ;
            }
        }

        std::cout << kpos << "\n" ;
    }
}
