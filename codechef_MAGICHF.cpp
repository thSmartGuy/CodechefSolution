#include <iostream>

int main(){
    int t, n, x, s, a, b ;
    std::cin >> t ;

    while(t--){
        std::cin >> n >> x >> s ;

        for(int i = 0 ; i < s ; i++){
            std::cin >> a >> b ;

            if(a == x || b == x){
                if(a == x){
                    x = b ;
                }
                else{
                    x = a ;
                }
            }
        }

        std::cout << x << "\n" ;
    }
}
