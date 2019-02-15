#include <iostream>
#include <vector>
#define fast std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
#define MAX 8

typedef long long int lld  ;

std::vector <std::string> days(110) ;

void pre(){
    std::string odays[] =  {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"} ;

    int j = 0 ;
    FOR(i, 0, 110){
        days[i] = odays[j++] ;
        j%=7 ;
    }
}

int main(){
    fast ;

    int t, l, r ;

    std::cin >> t ;

    pre() ;
    while(t--){
        std::string s, e ;

        std::cin >> s >> e >> l >> r ;

        int start_ = 0 ;
        while(days[start_] != s){
            start_++ ;
        }
        int init_start = start_ ;

        start_ += (l - 1) ;
        int m = 0 ;

        int i = start_ ;


        FOR(j, start_, start_ + r - l + 1){
            if(days[j] == e){
                i = j ;
                m++ ;
            }
        }

        if(m == 0){
            std::cout << "impossible\n" ;
        }
        else if(m == 1){
            std::cout << i - init_start + 1<< "\n" ;
        }
        else{
            std::cout << "many\n" ;
        }
    }
}
