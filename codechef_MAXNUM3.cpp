#include <iostream>
#include <cstring>

typedef long long int lld ;

int main(){
    int t, remove_, n ;
    char old ;
    std::string str ;

    std::cin >> t ;
    while(t-->0){
        lld sum = 0 ;
        std::cin >> str ;

        n = str.size() ;
        for(int i = 0 ; i < n ; i++){
            sum += str[i] ;
            sum %= 3 ;
        }

        remove_ = -1 ;
        if((str[n - 1] - '0')%2 == 0){ // if last digit is zero that is overall number is divisible by 2
            for(int i = 0 ; i < n - 2 ; i++){
                if(str[i] < str[i + 1] && (sum - (str[i] - '0'))%3 == 0){
                    remove_ = i ;
                    break ;
                }
            }
            if(remove_ == -1){
                for(int i = n - 2 ; i  >= 0 ; i--){
                    if((sum - (str[i] - '0'))%3 == 0){
                        remove_ = i ;
                        break ;
                    }
                }
                if((str[n - 2] - '0')%2 == 0 && (sum - (str[n - 1] - '0'))%3 == 0){
                    remove_ = n - 1 ;
                }
            }
        }
        else{ // last digit must be removed
            if((str[n - 2] - '0')%2 == 0){
                if((sum - (str[n - 1] - '0'))%3 == 0){
                    remove_ = n - 1 ;
                }
            }
        }

        if(remove_ == -1){
            std::cout << -1 << "\n" ;
        }
        else{
            for(int i = 0 ; i < n ; i++){
                if(i != remove_){
                    std::cout << str[i] ;
                }
            }
            std::cout << "\n" ;
        }
    }
}
