#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

typedef long long lld ;
std::map <lld, std::vector<lld>> ID ; // store odd powers only
std::vector <lld> sieve ;

void makeSieve(){
    sieve.assign(100001, 0) ;
    for(lld i = 2 ; i <= 100000 ; i++){
        if(!sieve[i]){
            for(lld j = i ; j <= 100000 ; j+=i){
                if(!sieve[j])
                    sieve[j] = i ;
            }
        }
    }
}

std::map <lld, lld> auxMap ;
std::vector <lld> auxArray ;
void addFactorizationOf(lld k){ // for non zero k
    if(k == 1){
        ID[k] = {1} ;
        return ;
    }

    auxMap.clear() ;
    auxArray.clear() ;

    lld tmp = k ;
    while(k && k != 1){
        auxMap[ sieve[k] ]++ ;
        k /= sieve[k] ;
    }

    for(auto it : auxMap){
        if((it.second&1)){
            auxArray.push_back(it.first) ;
        }
    }

    if(!auxArray.size()) auxArray = {1} ;
    
    ID[tmp] = auxArray ;
}

void pre(){
    makeSieve() ;
    for(lld i = 1 ; i <= 100000 ; i++){
        addFactorizationOf(i) ;
    }
}
// / / / / / / / / / / / / / / / / / / / / / / / / / / / /


std::unordered_map <lld, lld> perfectX, perfectY ;
lld xrr[111111], yrr[111111] ;

std::map <std::vector <lld>, std::vector<lld>> elementsWithIDX, elementsWithIDY ;

int main(){
    pre() ;

    lld t = 1 ;
    std::cin >> t ;

    lld n, m ;
    while(t--){
        bool zeroSeen = 0 ; 
        lld ans = 0 ;
        std::cin >> n >> m ;
        perfectY.clear() ; perfectX.clear() ; 
        elementsWithIDX.clear() ; elementsWithIDY.clear() ;

        lld newN = n, newM = m ;
        for(lld i = 0 ; i < n ; i++){
            std::cin >> xrr[i] ;

            if(!xrr[i]){ // handling '0' cases seperately
                newN-- ;
                zeroSeen = 1 ;
                continue ;
            }

            perfectX[ xrr[i]*xrr[i] ]++ ;

            if(xrr[i] > 0)
                elementsWithIDX[ ID[xrr[i]] ].push_back(xrr[i]) ;
        }

        for(lld i = 0 ; i < m ; i++){
            std::cin >> yrr[i] ;

            if(!yrr[i]){ // handling '0' cases seperately
                newM-- ;
                zeroSeen = 1 ;
                continue ;
            }

            perfectY[ yrr[i]*yrr[i] ]++ ;

            if(yrr[i] > 0)
                elementsWithIDY[ ID[yrr[i]] ].push_back(yrr[i]) ;
        }
        
        for(lld i = 0 ; i < n ; i++){
            if(xrr[i] < 0){

                for(auto it : elementsWithIDX[ ID[-xrr[i]] ]){

                    if(perfectY.count( it*(-xrr[i]) )){
                        ans += perfectY[ it*(-xrr[i]) ] ;
                    }

                }

            }
        }

        for(lld i = 0 ; i < m ; i++){
            if(yrr[i] < 0){

                for(auto it : elementsWithIDY[ ID[-yrr[i]] ]){

                    if(perfectX.count( it*(-yrr[i]) )){
                        ans += perfectX[ it*(-yrr[i]) ] ;
                    }

                }

            }
        }        

        if(zeroSeen){
            ans += newN*newM ;
        }
        std::cout << ans << "\n" ;
    }
}