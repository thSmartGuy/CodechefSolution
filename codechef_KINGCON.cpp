#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::vector <std::vector <int>> edges ; 

std::vector <int>  discoveryTime, isArtPoint ;

int time_ ;
int dfs(int cur, int parent, bool *visited){
    discoveryTime[cur] = ++time_ ;

    int minCurTime = discoveryTime[cur] ;
    
    visited[cur] = 1 ;

    int child = 0 ;
    int neighbourMin ;
    for(int v : edges[cur]){
        if(!visited[v]){
            child++ ;
            neighbourMin = dfs(v, cur, visited) ;
            minCurTime = std::min(neighbourMin, minCurTime) ;

            if(neighbourMin >= discoveryTime[cur]){
                isArtPoint[cur] = 1 ;
            }
        }
        else if(parent != v){
            minCurTime = std::min(minCurTime, discoveryTime[v]) ;
        }
    }

    if(cur == 0){
        if(child > 1){
            isArtPoint[0] = 1 ;
        }
        else isArtPoint[0] = 0 ;
    }
    
    std::cout << "low time for " <<  cur << " is : " << minCurTime << "\n" ;
    return minCurTime ;
}

int main(){
    int t = 1 ;
    std::cin >> t ;

    long long n, m, k ;
    while(t--){
        time_ = 0 ;
        std::cin >> n >> m >> k ;

        edges = std::vector <std::vector<int>> (n) ;

        int u, v ;
        for(int i = 0 ; i < m ; i++){
            std::cin >> u >> v ;

            edges[u].push_back(v) ;
            edges[v].push_back(u) ;
        }

        isArtPoint.assign(n, 0) ;
        discoveryTime.assign(n, 0) ;

        bool *visited = new bool[n] ;

        for(int i = 0 ; i < n ; i++){
            visited[i] = 0 ;
        }

        dfs(0, -1, visited) ;

        for(int i= 0 ; i < n ; i++)
            std::cout << discoveryTime[i] << " ";
        std::cout << "\n" ;

        delete [] visited ;

        long long c = 0 ; 
        for(int v: isArtPoint){
            c += (v) ;
        }

        long long ans = ((long long)k*c) ;
        std::cout << ans << "\n" ;
    }
}