#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 2222 ;

// CODE FROM HERE
int arr[MAX][MAX], brr[MAX][MAX], tarr[MAX][MAX] ;

bool rowmatch(int k, int n){
    FOR(i, 0, n){
        if(arr[k][i] != brr[k][i]) return false ;
    }
    return true ;
}

std::vector <bool> col ;

bool searchcolforrow_(int k, int n){
    FOR(i, 0, n){
        if(arr[i][k] != brr[k][i]) return false ;
    }

    FOR(i, 0, n){
        int temp = arr[i][k] ;
        arr[i][k] = arr[k][i] ;
        arr[k][i] = temp ;
    }

    return true ;
}

int main(){
    // fast() ;
    int t ;

    std::cin >> t ;

    int n ; char c ;
    while(t--){
        std::cin >> n ;

        col.assign(MAX, 1) ;
        FOR(i, 0, n){
            FOR(j, 0, n){
                std::cin >> c ;
                arr[i][j] = c - '0' ;
            }
        }

        FOR(i, 0, n){
            FOR(j, 0, n){
                std::cin >> c ;
                brr[i][j] = c - '0' ;
            }
        }

        FOR(i, 0, n){
            if(!rowmatch(i, n)){ // IF ANY ROW DIDNT MATCH TRY TO MATCH A COL OF A WITH B
                if(searchcolforrow_(i, n)){
                    // PASS
                }
            }
        }

        FOR(i, 0, n){
            if(!rowmatch(i, n)){ // IF ANY ROW DIDNT MATCH TRY TO MATCH A COL OF A WITH B
                if(searchcolforrow_(i, n)){
                    // PASS
                }
            }
        }

        bool flg = 1 ;
        FOR(i, 0, n){
            FOR(j, 0, n){
                if(arr[i][j] != brr[i][j]) flg = 0 ;
            }
        }

        std::cout << (flg ? "Yes\n" : "No\n") ;
    }
}

