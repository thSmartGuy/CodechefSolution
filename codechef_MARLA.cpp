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
int graph[MAX][MAX] ;
bool vis[MAX][MAX] ;

int n, m, temp_area ;

int d1[] = {0, 1, 0, -1} ;
int d2[] = {1, 0, -1, 0} ;

void pre(){
    FOR(i, 0, MAX) FOR(j, 0, MAX) vis[i][j] = 0 ;
}

bool valid(int i, int j, int val){
    if(i >= 0 && i < n){
        if(j >= 0 && j < m){
            if(!vis[i][j]){
                if(val == graph[i][j]){
                    return true ;
                }
            }
        }
    }
    return false ;
}

void dfs(int i, int j){
    vis[i][j] = true ;

    temp_area++ ;
    FOR(k, 0, 4){
        int ni = i + d1[k], nj = j + d2[k] ;

        if(valid(ni, nj, graph[i][j])){
            dfs(ni, nj) ;
        }
    }
}

int main(){
     fast() ;
     // MY FIRST DFS QUESTION

    pre() ;
    std::cin >> n >> m ;

    FOR(i, 0, n) FOR(j, 0, m) std::cin >> graph[i][j] ;

    int area = 0, val ;
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(!vis[i][j]){
                temp_area = 0 ;
                dfs(i, j) ;

                if(temp_area > area){
                    area = temp_area ;
                    val = graph[i][j] ;
                }
                else if(temp_area == area && graph[i][j] < val){
                    val = graph[i][j] ;
                }
            }
        }
    }

    std::cout << val << " " << area << "\n" ;
}

