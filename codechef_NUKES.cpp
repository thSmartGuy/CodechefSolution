#include <algorithm>
#include <iostream>

int main(){
    int a, n, k ;
    std::cin >> a >> n >> k ;

    for(int i = 0 ; i < k ; i++){
        std::cout << a%(n+1) << " " ;
        a = a/(n+1) ;
    }
}
