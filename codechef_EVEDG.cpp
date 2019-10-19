#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector<int> par, count_ ;

void init(int n){
	par.assign(n + 1, 1) ;
	count_.assign(n + 1, 0) ;
}

std::vector <std::vector <int>> edges ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	int n, m ;
	while(t--){
		std::cin >> n >> m ;

		init(n) ;
		edges = std::vector <std::vector <int>> (n + 1) ;

		int u, v ;
		for(int i = 0 ; i < m ; i++){
			std::cin >> u >> v ;
			edges[u].push_back(v) ;
			edges[v].push_back(u) ;

			count_[u]++ ; 
			count_[v]++ ;
		}

		int k = 1 ;

		if(m&1){
			bool tr = 0 ;

			for(int i = 1 ; i <= n ; i++){
				if(count_[i]&1){
					par[i] = 2 ;
					k = 2 ;
					tr = 1 ;
					break ;
				}
			}

			if(!tr){
				k = 3 ;

				for(int i = 1 ; i <= n ; i++){
					if(count_[i] >= 2){
						for(int j = 0 ; j < edges[i].size() ; j++){
							int node = edges[i][j] ;

							if(count_[node] >= 2){
								par[i] = 2 ;
								par[node] = 3 ;
								tr = 1 ;
								break ;
							}
						}
						if(tr) break ;
					}
				}
			}
		}

		std::cout << k << "\n" ;
		for(int i = 1 ; i < n + 1 ; i++){
			std::cout << par[i] << " " ;
		}
		std::cout << "\n" ;
	}
}