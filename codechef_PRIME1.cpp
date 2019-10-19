#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0) ;
	std::cin.tie(0) ; std::cout.tie(0) ;
}

int main(){
	int n, m ;
	fast();
	int t ;
	std::cin >> t ;


	while(t--){
		std::cin >> n >> m ;

		for(int i = std::max(2, n) ; i <= m ; i++){
			int k = i ;

			bool prime = 1 ;
			for(int div = 2 ; div <= std::sqrt((double)k) ; div++){
				if(k % div == 0) {
					prime = 0 ;
					break ;
				}
			}

			if(prime) std::cout << k << "\n" ;
		}	
		std::cout << "\n" ;
	}
}