#include <iostream>

int main(){
    int t, n ;

    std::cin >> t ;
    while(t--){
        std::cin >> n ;

        std::string s, r ;

        std::cin >> s >> r  ;

        int a = 0, b = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1') a++ ;
            else b++ ;
        }

        int c = 0, d = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(r[i] == '1') c++ ;
            else d++ ;
        }

        if(a == c && b == d){
            std::cout << "YES\n" ;
        }
        else std::cout << "NO\n" ;
    }
}
