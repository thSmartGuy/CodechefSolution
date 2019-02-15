#include  <iostream>

int main(){
    int t, n, m, index, chef ;
    std::cin >> t ;
    while(t-->0){
        chef = 1 ;
        std::cin >> n >> m ;
        bool arr[n+1] = {} ;
        for(int i = 0; i < m ; i++){
            std::cin >> index ;
            arr[index] = true ;
        }

        for(int i = 1 ; i <= n ; i++){
            if(!arr[i]){
                if(chef){
                    std::cout << i << " " ;
                    arr[i] = true ;
                    chef = 0;
                }
                else{
                    chef = 1 ;
                }
            }
        }

        std::cout << "\n" ;

        for(int i = 1 ; i <= n ; i++){
            if(!arr[i]){
                std::cout << i << " " ;
            }
        }
        std::cout << "\n" ;
    }
}
