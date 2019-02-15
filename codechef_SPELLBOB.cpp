#include <iostream>

int main(){
    int t, flag ;
    std::string f, b ;
    std::cin >> t ;
    while(t--){
        flag = 0 ;
        std::cin >> f >> b ;
        if((f[0] == 'b' || b[0] == 'b') && (f[1] == 'o' || b[1] == 'o') && (f[2] == 'b' || b[2] == 'b'))
            flag = 1 ;
        else if((f[0] == 'o' || b[0] == 'o') && (f[1] == 'b' || b[1] == 'b') && (f[2] == 'b' || b[2] == 'b'))
            flag = 1 ;
        else if((f[0] == 'b' || b[0] == 'b') && (f[1] == 'b' || b[1] == 'b') && (f[2] == 'o' || b[2] == 'o')){
            flag = 1 ;
        }

        if(flag) std::cout << "yes\n" ; else std::cout << "no\n" ;
    }
}
