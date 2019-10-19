#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <std::vector<int>> edges1, edges2 ;
std::map <int, std::pair <int, int>> graph1, graph2 ;

void dfs1(int cur, bool *vis, int n){
	if(cur >= n) return ;

	if(vis[cur]){
		return ;
	}

	vis[cur] = 1 ;

	for(int a : edges1[cur]){
		dfs1(a, vis, n) ;
	}
}

void dfs2(int cur, bool *vis, int n){
	if(cur >= n) return ;
	if(vis[cur]){
		return ;
	}

	vis[cur] = 1 ;

	for(int a : edges2[cur]){
		dfs2(a, vis, n) ;
	}
}

int main(){
	int t = 1 ; std::cin >> t ;
	fast();
	
	int n, m ;
	while(t--){
		std::cin >> n >> m ;
		graph1.clear() ;
		graph2.clear() ;

		int u, v ;
		for(int i = 0 ; i < m ; i++){
			std::cin >> u >> v ;
			u--, v-- ;

			assert(u < n && v < n) ;
			graph1[i + 1] = {u, v} ;
		}

		for(int i = 0 ; i < m ; i++){
			std::cin >> u >> v ;
			u--, v-- ;

			assert(u < n && v < n) ;
			graph2[i + 1] = {u, v} ;
		}

		long long kk = 1 ;
		for(int i = 0 ; i < m ; i++){
			kk *= 2 ;
		}

		int ans = m ;

		int start = 0 ;
		for(int i = 0 ; i < n - 1 ; i++){
			start = start*2 + 1 ;
		}

		for(int ii = start ; ii < kk ; ii++){
			int opop = ii ;

			edges1 = std::vector <std::vector <int>> (n + 111) ;
			edges2 = std::vector <std::vector <int>> (n + 111) ;

			int cur = 1 ;
			while(opop){
				if(opop&1){
					if(graph1.count(cur)){
						u = graph1[cur].first ;
						v = graph1[cur].second ;

						assert(u < n && v < n) ;
						edges1[u].push_back(v) ;
						edges1[v].push_back(u) ;
					}

					if(graph2.count(cur)){
						u = graph2[cur].first ;
						v = graph2[cur].second ;

						assert(u < n && v < n) ;
						edges2[u].push_back(v) ;
						edges2[v].push_back(u) ;
					}
				}
				opop /= 2 ;
				cur++ ;
				if(cur > m) break ;
			}

			bool *vis = new bool[n + 111] ;
			for(int i = 0 ; i < n + 111; i++){
				vis[i] = 0 ;
			}

			dfs1(0, vis, n) ;

			int c1 = 0 ;
			for(int i = 0 ; i < n + 111 ; i++){
				if(vis[i]){
					c1++ ;
				}
				vis[i] = 0 ;
			}

			dfs2(0, vis, n) ;

			int c2 = 0 ;
			for(int i = 0 ; i < n + 111 ; i++){
				if(vis[i]){
					c2++ ;
				}
				vis[i] = 0 ;
			}

			if(c1 == n && c2 == n){
				ans = std::min(__builtin_popcount(ii), ans) ;
				break ;
			}
			delete [] vis ;
		}

		std::cout << ans << "\n" ;
	}
}