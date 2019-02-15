#include <iostream>
#include <climits>

typedef long long int lld ;

void prepre(){
    std::ios_base::sync_with_stdio(false) ;
    //std::cin.tie(NULL) ; std::cout.tie(NULL) ;
}

int arr[300] ;
char opr[300] ;

int main(){

    prepre() ;

    int t, n, a ;
    std::cin >> t ;
    while(t--){
        std::cin >> n ;

        std::cin >> arr[0] ;
        for(int i = 1 ; i < n ; i++){
            std::cin >> opr[i - 1] >> arr[i] ;
        }

        lld dpMax[n][n], dpMin[n][n] ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                dpMax[i][j] = INT_MIN ;
                dpMin[i][j] = INT_MAX ;

                if(i == j){
                    dpMax[i][j] = arr[i] ;
                    dpMin[i][j] = arr[i] ;
                }
            }
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                for(int k = j ; k < i ; k++){
                    if(opr[k] == '-'){
                        // max = max - min
                        // min = min - max

            //            std::cout << "Case '-' : \n" ;

              //          std::cout << "selecting maximum bw dpMax[" << j << "][" << i << "] & " << "dpMax[" << j << "][" << k << "] - " << "dpMin[ " << k + 1 << "][" << i << "]\n" ;
                        dpMax[j][i] = std::max(dpMax[j][i], dpMax[j][k] - dpMin[k + 1][i]) ;
                //        std::cout << "selecting minimum bw dpMin[" << j << "][" << i << "] & " << "dpMin[" << j << "][" << k << "] - " << "dpMax[ " << k + 1 << "][" << i << "]\n" ;
                        dpMin[j][i] = std::min(dpMin[j][i], dpMin[j][k] - dpMax[k + 1][i]) ;
                    }
                    else{

                  //      std::cout << "Case '+' : \n" ;

                    //    std::cout << "selecting maximum bw dpMax[" << j << "][" << i << "] & " << "dpMax[" << j << "][" << k << "] + " << "dpMax[ " << k + 1 << "][" << i << "]\n" ;


                        dpMax[j][i] = std::max(dpMax[j][i], dpMax[j][k] + dpMax[k + 1][i]);

                      //  std::cout << "selecting minimum bw dpMin[" << j << "][" << i << "] & " << "dpMin[" << j << "][" << k << "] + " << "dpMin[ " << k + 1 << "][" << i << "]\n" ;
                        dpMin[j][i] = std::min(dpMin[j][i], dpMin[j][k] + dpMin[k + 1][i]);
                    }
                }
            }
        }
/*
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                std::cout << "0 " ;
            }

            for(int j = i ; j < n ;j++){
                std::cout << dpMax[i][j] << " " ;
            }
            std::cout << "\n" ;
        }
        std::cout << "\n\n" ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                std::cout << "0 " ;
            }
            for(int j = i ; j < n ;j++){
                std::cout << dpMin[i][j] << " " ;
            }
            std::cout << "\n" ;
        }
        std::cout << "\n" ;*/

        std::cout << dpMax[0][n - 1] << "\n" ;
    }
}
