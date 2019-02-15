#include <cstdio>
#include <vector>
#include <iostream>
const int MAX = 1000001 ;

int primeSum[MAX] ;
std::vector <int> good[MAX] ;

void init(){
    for(int i = 0 ; i < MAX ; i++){
        primeSum[i] = 0 ;
    }

    for(int p = 2 ; p < MAX ; p++){
        if(primeSum[p] == 0){
            for(int i = p ; i < MAX ; i+=p){
                primeSum[i] += p ;
            }
        }
    }

    for(int i = 2 ; i < MAX ; i++){
        for(int j = 2*i ; j < MAX ; j+=i){
            if(primeSum[i] && primeSum[j]%primeSum[i] == 0){
                good[i].push_back(j) ;
            }
        }
    }
}

int a[MAX], freq[MAX] ;

int main(){
    int t, n, temp ;
    long long int ans ;
    std::cin >> t ;

    init() ;

    while(t-->0){
        for(int i = 0 ; i < MAX ; i++){
            freq[i] = 0 ;
        }

        ans = 0 ;
        scanf("%d",&n) ;
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &a[i]) ;
            freq[a[i]]++ ;
        }

        for(int i = 1 ; i < MAX ; i++){
            if(freq[i]){
                if(freq[i] > 1){
                    ans += freq[i]*(long long)(freq[i] - 1) ;
                }

                for(int j = 0 ; j < good[i].size() ; j++){
                    if(i!= good[i][j] && freq[good[i][j]]){
                        ans += freq[i]*(long long)freq[good[i][j]] ;
                    }
                }
            }
        }

        std::cout << ans << "\n" ;
    }
}
