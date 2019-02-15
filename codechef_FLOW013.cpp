#include <iostream>

int main(){
    int t, a, b, c ;

    std::cin >> t ;
    std::string ans ;
    while(t--){
        std::cin >> a >> b >> c ;

        if(a + b + c == 180){
            ans = "YES\n" ;
        }
        else{
            ans = "NO\n" ;
        }

        std::cout << ans ;
    }
}
