#include <iostream>

void upper(char a){
    if(a >= 'a' && a <= 'z')
        a = a - 'a' + 'A' ;

    std::cout << a ;
}

void lower(char a){
    if(a >= 'A' && a <= 'Z')
        a = a - 'A' + 'a' ;

    std::cout << a ;
}

int main(){
    int t ;

    std::cin >> t ;
    std::string name ;

    getline(std::cin, name) ;
    while(t--){
        getline(std::cin, name) ;

        int count_ = 1 ;
        for(int i = 0 ; i < name.size() ; i++){
            if(name[i] == ' '){
                count_++ ;
            }
        }

        if(count_ == 1){
            upper(name[0]);
            for(int i = 1 ; i < name.size() ; i++){
                lower(name[i]) ;
            }
            std::cout << "\n" ;
        }
        else if(count_ == 2){
            int i ;
            upper(name[0]);
            std::cout << ". " ;
            for(i = 1 ; name[i] != ' ' ; i++){}
            i++ ;

            upper(name[i]) ;

            for(i = i + 1; i < name.size() ; i++){
                lower(name[i]) ;
            }
            std::cout << "\n" ;
        }
        else{
            int i ;
            upper(name[0]);
            std::cout << ". " ;
            for(i = 1 ; name[i] != ' ' ; i++){}
            i++ ;

            upper(name[i]) ;
            std::cout << ". " ;

            for(i = i + 1; name[i] != ' ' ; i++){}
            i++ ;

            upper(name[i]) ;
            for(i = i + 1 ; i < name.size() ; i++){
                lower(name[i]) ;
            }
            std::cout << "\n" ;
        }
    }
}
