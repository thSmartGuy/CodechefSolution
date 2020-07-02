#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

const int mod = 1e9 + 7 ;

std::vector <std::vector<int>> edges ; 

std::vector  <int> primeFactorsArray ;
void sieve(){
	primeFactorsArray.assign(1000001, 0) ;

	for(int i = 2 ; i < 1000001 ; i+=2){
		primeFactorsArray[i] = 2 ;
	}

	for(int i = 3 ; i < 1000001 ; i+=2){
		if(!primeFactorsArray[i]){
			for(int j = i ; j < 1000001 ; j += i){
				if(!primeFactorsArray[j]){
					primeFactorsArray[j] = i ;
				}
			}
		}
	}
}

std::vector <int> cost ;
std::map <int, long long> primesFreq ;
std::vector <std::vector <long long>> ansArray ;

void getFactors(long num){

	while(num != 1){
		int factor = primeFactorsArray[num] ;
		primesFreq[factor]++ ;

		num /= factor ;
	}

}

void removeFactors(long num){

	while(num != 1){
		int factor = primeFactorsArray[num] ;
		primesFreq[factor]-- ;

		if(primesFreq[factor] == 0) primesFreq.erase(factor) ;

		num /= factor ;
	}

}

void dfs(int from, int cur, bool *vis){
	if(vis[cur]) return ;

	vis[cur] = 1 ;
	// includes factors of cur node in primesFreq
	getFactors(cost[cur]) ;

	// store answer for this node 
	long long ans = 1 ;

	// std::cout << "factors fr " << from << " to " << cur << " : " ;
	for(auto it : primesFreq){
		// std::cout << it.first << "^" << it.second << " " ;

		// if(it.second > 0){
			ans = (((long long)ans*((long long)it.second + 1ll))%mod)%mod ;
		// }
	}
	// std::cout << "\n" ;

	ansArray[from][cur] = ans ;

	for(int v : edges[cur]){
		dfs(from, v, vis) ;
	}

	removeFactors(cost[cur]) ;
}


void pre(int num){
	// mark not visited 
	// std::cout << "inside pre\n" ;
	bool *vis = new bool[num] ;

	for(int i = 1 ; i < num ; i++){

		for(int i = 0 ; i < num ; i++) vis[i] = 0 ;
		primesFreq.clear() ;
		
		dfs(i, i, vis) ;
	}

	delete [] vis ; 
}

int main(){
	fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	sieve() ;

	int n, q ;
	while(t--){
		std::cin >> n ;
		
		edges = std::vector <std::vector <int>> (n + 1) ;

		int u, v ;
		for(int i = 0 ; i < n - 1 ; i++){
			std::cin >> u >> v ;

			edges[u].push_back(v) ;
			edges[v].push_back(u) ;
		}

		// std::cout << "below graph input\n" ;

		cost.resize(n+1) ;
		for(int i = 1 ; i <= n ; i++){
			std::cin >> cost[i] ;
		}

		ansArray = std::vector <std::vector<long long>> (n + 1, std::vector <long long> (n + 1)) ;
		pre(n + 1) ;

		std::cin >> q ;
		while(q--){
			std::cin >> u >> v ;
			std::cout << ansArray[u][v] << "\n" ;
		}
	}
}