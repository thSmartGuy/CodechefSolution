#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::vector <std::vector <int>> edges ;

std::vector <long long> val ;

void update(int cur, long long data, bool *vis){
	if(vis[cur]){
		return ;
	}

	vis[cur] = 1 ;

	long long data2 = val[cur] ;
	val[cur] = data ;

	bool flg = 1 ;
	for(int i = 0 ; i < edges[cur].size() ; i++){
		if(!vis[edges[cur][i]]){
			update(edges[cur][i], data2, vis) ;
			flg = 0 ;
		}
	}

	if(flg){ // leaf node
		val[cur] = (long long)(data + data2) ;
		return ;
	}
}

int main(){
	int n, q ;

	fast() ;
	std::cin >> n >> q ;

	val.assign(n, 0) ;

	edges = std::vector <std::vector <int>> (n) ;

	int x, y ;
	for(int i = 0 ; i < n - 1 ; i++){
		std::cin >> x >> y ;
		x--, y-- ;

		edges[x].push_back(y) ;
		edges[y].push_back(x) ;	
	}

	for(int i = 0 ; i < n ; i++){
		std::cin >> val[i] ;
	}

	char query ;
	int v, k ;
	bool *vis = new bool[n] ;
	for(int qq = 0 ; qq < q ; qq++){
		std::cin >> query >> v ;
		v-- ;

		for(int i = 0 ; i < n ; i++){
			vis[i] = 0 ;
		}

		update(0, 0, vis) ;
		
		if(query == '?'){
			std::cout << val[v] << "\n" ;
		}
		else{ // + 
			long long k ;
			std::cin >> k ;

			val[v] = (long long)(val[v] + k) ;
		}

		/*
		for(int i = 0 ; i < n ; i++){
			std::cout << val[i] << " " ;
		}
		std::cout << "\n" ;

		//*/
	}
	delete [] vis ;
}