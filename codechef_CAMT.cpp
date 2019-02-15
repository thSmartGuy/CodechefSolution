#include <queue>
#include <iostream>
#include <set>

void init(bool **graph, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            graph[i][j] = false ;
        }
    }
}

int countBipartite(int src, bool **graph, int V){
    int visited[V] ;

    for(int i = 0 ; i < V ; i++){
        visited[i] = 0 ;
    }

    visited[src] = 1 ;

    std::queue <int> q ;
    q.push(src) ;
    int count_ = 1 ;

    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;

        for(int i = 0 ; i < V ; i++){

            if(!visited[i] && graph[u][i]){
          //      std::cout << "coloring " << i << " due to " << u << "\n" ;
                count_++ ;
                visited[i] = 1 ;
                q.push(i) ;
            }
        }
    }

    return count_ ;
}

int main(){
    int n, m, e1, e2, q ;
    std::cin >> n >> m ;
    bool **graph = new bool*[n] ;

    for(int i = 0 ; i < n ; i++){
        graph[i] = new bool[n] ;
    }

    init(graph, n) ;

    //std::set <int> mango ;

    for(int i = 0 ; i < m ; i++){
        std::cin >> e1 >> e2 ;
        graph[e1][e2] = true ; graph[e2][e1] = true ;
//        mango.insert(e1) ; mango.insert(e2) ;
    }

    std::cin >> q ;

    int ans ;

    //m = mango.size() ;

    while(q--){
        std::cin >> e1 >> e2 ;
        graph[e1][e2] = false ; graph[e2][e1] = false ;
        ans = countBipartite(e2, graph, n) ;
        //ans = std::min(ans, m - ans) ;
        graph[e1][e2] = true ; graph[e2][e1] = true ;
        std::cout << ans << "\n" ;
    }
}
