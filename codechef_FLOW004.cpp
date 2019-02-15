#include <iostream>

int main(){
    int t ;
    std::string n ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        std::cout << n[0] - '0' + n[n.size() - 1] - '0' << "\n" ;
    }
}
