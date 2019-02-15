#include <iostream>

int main(){
    int t, n, m, allzero ;
    std::cin >> t ;
    std::string ola ;
    while(t--){
        allzero = 1 ;
        std::cin >> n >> m ;
        int arr[n][m] ;
        int row[n] = {}, col[m] = {};
        for(int i = 0 ; i < n ; i++){
            std::cin >> ola ;
            for(int j = 0 ; j < m ; j++){
                arr[i][j] = ola[j] - '0' ;
                if((arr[i][j]) == 1){
                    row[i] = 1;
                    col[j] = 1 ;
                    allzero = 0 ;
                }
            }
        }

        if(allzero){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    std::cout << -1 << " " ;
                }
                std::cout << "\n" ;
            }
        }
        else{
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(arr[i][j]){
                        std::cout << 0 << " " ;
                    }
                    else{
                        if(row[i] || col[j]){
                            std::cout << 1 << " " ;
                        }
                        else{
                            std::cout << 2 << " " ;
                        }
                    }
                }
                std::cout << "\n" ;
            }
        }
    }
}
