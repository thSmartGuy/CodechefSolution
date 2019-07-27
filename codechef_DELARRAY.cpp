#include <iostream>

int arr[100011] ;

bool isRight(int st, int en, int n){
    // if left part is sorted
    if(en - st == n - 1) return 0 ;
    //std::cout << st << en << ": " ;

    bool tr = 1 ;
    for(int i = 0 ; i < st - 1 ; i++){
        if(arr[i] >= arr[i + 1]){
            tr = 0 ;
            break ;
        }
    }

    if(st - 1 >= 0 && en + 1 < n && arr[en + 1] < arr[st - 1]){
        tr = 0 ;
    }

    // if righ part is sorted
    for(int i = en + 1 ; i < n - 1 ; i++){
        if(arr[i] >= arr[i + 1]){
            tr = 0 ;
            break ;
        }
    }
    //std::cout << tr << "\n" ;
    return tr ;
}

int main(){
    int t ;

    std::cin >> t ;

    while(t--){
        int n ;

        std::cin >> n ;

        for(int i = 0 ; i < n ; i++){
            std::cin >> arr[i] ;
        }

        long long ans = 0 ;

        for(int start = 0 ; start < n ; start++){
            for(int end = start ; end < n ; end++){
                if(isRight(start, end, n)){
                    ans++ ;
                }
            }
        }
        std::cout << ans << "\n" ;
    }
}
