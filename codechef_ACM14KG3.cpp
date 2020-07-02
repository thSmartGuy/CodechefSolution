#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::map <char, std::vector<char>> mp ;
std::map <char, bool> vis ;

bool reachable(char u, char v){
	if(u == v) return 1 ;
	if(!mp.count(u) || vis.count(u)){
		return 0 ;
	}

	vis[u] = 1 ;

	for(int vv:mp[u]){
		if(reachable(vv, v)) return 1 ;
	}

	return 0 ;
}

int main(){
	fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	std::string given, transfrom ;

	while(t--){
		mp.clear() ;
		std::cin >> given >> transfrom ;

		int m ; std::cin >> m ;

		for(int i = 0 ; i < m ; i++){
			std::string mapping ;	
			std::cin >> mapping ;
			
			char u = mapping[0] ;		
			char v = mapping[3] ;

			if(mp.count(u)){
				mp[u].push_back(v) ;
			}
			else{
				mp[u] = {v} ;
			}
		}

		// for(auto it : mp){
		// 	std::cout << it.first << " -> " ;
		// 	for(char k : it.second){
		// 		std::cout << k << " " ;
		// 	}
		// 	std::cout << "\n" ;
		// }

		bool tr = 1 ;
		if(given.size() != transfrom.size()){
			tr = 0 ;
		}

		if(tr){

			for(int i = 0 ; i < given.size() ; i++){
				if(given[i] != transfrom[i]){
					vis.clear() ;
					if(!reachable(given[i], transfrom[i])){
						tr = 0 ;
						break ;
					}
				}
			}

		}

		std::cout << (tr ? "YES" : "NO") << "\n" ;
	}
}