#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, k, n) for(int i = k ; i < n ; i++)
void fast() {std::ios_base::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0);}
typedef long long int lld  ;
lld gcd(lld a, lld b){ if(!a) return b ; return gcd(b%a, a) ;}
template <class T> void print(T a) {std::cout << a << "\n" ;}
const int MAX = 1111 ;

// CODE FROM HERE
int d1[] = {0, 0, -1, 1} ;
int d2[] = {-1, 1, 0, 0} ;

std::string arr[2] ;
bool vis[2][MAX] ;

int n, black ;

void pre(){
    FOR(i, 0, MAX){
        vis[0][i] = 0 ;
        vis[1][i] = 0 ;
    }
}

bool valid(int i, int j){
    if(i == 0 || i == 1){
        if(j >= 0 && j < n){
            if(arr[i][j] == '#' && !vis[i][j]){
                return true ;
            }
        }
    }
    return false ;
}

void dfs(int i, int j){
    vis[i][j] = 1 ;
    black ++ ;

    FOR(k, 0, 4){
        int d11 = i + d1[k], d22 = j + d2[k] ;

        if(valid(d11, d22)){
            dfs(d11, d22) ;
        }
    }
}

int main(){
    // fast() ;
    int t ;

    std::cin >> t ;

    while(t--){
        std::cin >> n ;

        pre() ; black = 0 ;
        std::cin >> arr[0] >> arr[1] ;

        int cnt = 0, xx, yy ;
        FOR(i, 0, 2){
            FOR(j, 0, n){
                if(arr[i][j] == '#'){cnt++ ; xx = i ; yy = j ;}
            }
        }

        dfs(xx, yy) ;
        int blCnt = black ;

        if(blCnt == cnt){
            bool snake = 1 ;


            print(snake ? "yes" : "no") ;
        }
        else print("no") ;
    }
}

