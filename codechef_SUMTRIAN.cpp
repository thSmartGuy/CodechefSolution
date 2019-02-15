#include <iostream>
#include <climits>

int arr[101][101] ;

void init(){
    arr[0][1] = 0 ;
    for(int i = 0 ; i < 101 ; i++){
        arr[i][0] = 0 ;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false) ;

    int t, l, max_sum ;

    std::cin >> t ;

    init() ;
    while(t--){
        max_sum = INT_MIN ;
        std::cin >> l ;

        for(int i = 1 ; i <= l ; i++){
            for(int j = 1 ; j <= i ; j++){
                std::cin >> arr[i][j] ;
            }

            for(int j = 0 ; j <= i ; j++){
                arr[i][j] = std::max(arr[i - 1][j] + arr[i][j], arr[i - 1][j - 1] + arr[i][j]) ;
            }
        }

        for(int i = 1 ; i <= l ; i++){
            if(arr[l][i] > max_sum){
                max_sum = arr[l][i] ;
            }
        }

        std::cout << max_sum << "\n" ;
    }
}
