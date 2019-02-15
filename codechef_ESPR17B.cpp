#include <iostream>

int main(){
    std::string n ;

    std::cin >> n ;

    int sakshi = 0, nidhi = 0 ;

    for(int i = 0 ; i < n.size() ; i++){
        if((n[i] - '0')%2 != 0) //even
            sakshi += n[i] - '0' ;
        else
            nidhi += n[i] - '0' ;
    }

    if(nidhi == sakshi)
        std::cout << "TIE" ;
    else if(nidhi > sakshi){
        std::cout << "NIDHI" ;
    }
    else{
        std::cout << "SAKSHI" ;
    }
}
