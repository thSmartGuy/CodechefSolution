#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <cassert> 

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

struct st{
	int x, y ;
};

st pathHero1[1000011], pathHero2[1000011] ;

void pre(int n, int m){
	int k = 0 ;
	st K ; 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			K.x = i, K.y = j ;
			pathHero1[k++] = K ;
		}
	}

	k = 0 ;
	for(int j = 0 ; j < m ; j++){
		for(int i = 0 ; i < n ; i++){
			K.x = i, K.y = j ;
			pathHero2[k++] = K ;
		}
	}
}

std::vector <int> vis ; 

int main(){
	fast() ;
	int t = 1 ;
	std::cin >> t ;
	int n, m ;
	while(t--){
		std::cin >> n >> m ; 
		vis.assign(n*m + 1, 0) ;

		pre(n, m) ;

		for(int k = 1 ; k <= n*m ; k++){
			// row - wise (path1)
			int counter = 0 ;
			for(int j = 0 ; j < n*m ; j+=k){
				int r = pathHero1[j].x, c = pathHero1[j].y ;

				int idx = r*m + c ;
				//assert(idx < n*m) ;

				vis[idx] = 1 ;
				counter++ ;
			}

			// col - wise (path2)
			for(int j = 0 ; j < n*m ; j+=k){
				int r = pathHero2[j].x, c = pathHero2[j].y ;

				int idx = r*m + c ;
				//assert(idx < n*m) ;

				if(!vis[idx]) counter++ ;
			}

			std::cout << counter << " " ;

			// mARK UNVISITED AGAIN
			for(int j = 0 ; j < n*m ; j+=k){
				int r = pathHero1[j].x, c = pathHero1[j].y ;

				int idx = r*m + c ;
				//assert(idx < n*m) ;

				vis[idx] = 0 ;
			}
		}
		std::cout << "\n" ;
	}
}