#include <iostream>

int main(){
    int t, n, i;
    std::cin >> t;
    std::string str ;
    char c ;
    while(t-->0){
        std::cin >> n ;
        std::cin >> str ;

        for(i = 0; i < n ; i += 2){
            if(n-i <= 1){
                break;
            }
            c = str[i] ;
            str[i] = str[i+1] ;
            str[i+1] = c ;
        }

        for(i = 0; i < n ; i++){
            c = str[i] ;
            c = 'z' - c + 'a';
            str[i] = c ;
        }
        std::cout << str << "\n" ;
    }
}
