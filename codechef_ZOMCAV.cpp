#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int C[100011] ; 
std::vector <int> pre, health ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	while(t--){
		std::cin >> n ;
		health.resize(n) ;
		pre.assign(n, 0) ;

		for(int i = 0 ; i < n ; i++) std::cin >> C[i] ;
		for(int i = 0 ; i < n ; i++) std::cin >> health[i] ;

		std::fill(&pre[0], &pre[n], 0) ;

		int l, r ;

		long ll = 0 ;
		for(int i = 0 ; i < n ; i++){
			l = i - C[i], r = i + C[i] ; r++ ;

			if(l >= 0){
				pre[l] += 1 ;
			}
			else{
				ll++ ;
			}

			if(r < n){
				pre[r] -= 1 ; 
			}
		}

		for(int i = 0 ; i < n ; i++){
			ll += pre[i] ;
			pre[i] = ll ;
		}

		//for(int i = 0 ; i < n ; i++) std::cout << pre[i] << " " ; std::cout << "\n" ;

		std::sort(pre.begin(), pre.end()) ;
		std::sort(health.begin(), health.end()) ;

		if(health == pre){
			std::cout << "YES\n" ;
		}
		else std::cout << "NO\n" ;
	}
}
