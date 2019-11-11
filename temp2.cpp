#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <int> vrr ;

void leftShift(int cur){
    for(int i = cur ; i < vrr.size() - 1 ; i++){
        vrr[i] = vrr[i + 1] ;
    }
}

int main(){
    int n; 
    std::cin >> n ;

    vrr.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        std::cin >> vrr[i] ;
    }

    bool flag = 1 ;
    while(flag){
        flag = 0 ;

        for(int i = 0 ; i < vrr.size() - 1 ; i++){
            if(vrr[i] == vrr[i + 1]){
                flag = 1 ;

                vrr[i]++ ;
                leftShift(i + 1) ;
                vrr.pop_back() ;
            }
        }
    }

    int max_ = 0 ;
    for(int i = 0 ; i < vrr.size() ; i++){
        max_ = std::max(max_, vrr[i]) ;
    }

    std::cout <<  max_ << "\n" ;
}