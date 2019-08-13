#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

// FOR STAR GRAPH ONLY 	
std::vector <std::vector<int>> edges ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	int p[3] ;
	while(t--){
		std::cin >> n ;

		edges.clear() ;
		edges = std::vector <std::vector <int>> (n + 1) ;

		for(int i = 0 ; i < 3 ; i++) std::cin >> p[i] ;

		int u, v ;

		for(int i = 1 ; i < n ; i++){
			std::cin >> u >> v ;

			edges[u].push_back(v) ;
			edges[v].push_back(u) ;
		}

		// FOR STAR GRAPH ONLY
		long long ans ;

		for(int i = 1 ; i <= n ; i++){
			if(edges[i].size() == n - 1){
				u = i ;
				break ;
			}
		}

		long long elementSmallerThanU = 0 ;
		long long elementBiggerThanU = 0 ;

		for(int i = 0 ; i < edges[u].size() ; i++){
			if(edges[u][i] < u){
				elementSmallerThanU++ ;
			}
			else if(edges[u][i] > u){
				elementBiggerThanU++ ;
			}
		}
		
		if(p[1] == 3){ // max is u
			//std::cout << "max case: " ;
			// nC2 
			ans = (long long)((long long)((elementSmallerThanU)*(elementSmallerThanU - 1ll)))/2ll ;
		}
		else if(p[1] == 1){ // min is u
			//std::cout << "min case: " ;
			// nC2 
			ans = (long long)((long long)(elementBiggerThanU*(elementBiggerThanU - 1ll)))/2ll ;
		}
		else{ // u is neither max nor min
			//std::cout << "else case: " ;
			ans = (long long)((long long)elementBiggerThanU*elementSmallerThanU) ;
		}
		std::cout << ans << "\n" ;
	}
}
