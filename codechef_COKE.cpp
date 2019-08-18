#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int crr[1000] ;
	int prr[1000] ;

	int n, m, k, l, r ;
	while(t--){
		std::cin >> n >> m >> k >> l >> r ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> crr[i] >> prr[i] ;
		}

		for(int i = 0 ; i < n ; i++){
			if(crr[i] <= k - 1){
				crr[i] = std::min(k, crr[i] + m) ;
			}
			else if(crr[i] >= k - 1){
				crr[i] = std::max(k, crr[i] - m) ;
			}
		}

		int p = INT_MAX ;
		for(int i = 0 ; i < n ; i++){
			if(crr[i] >= l && crr[i] <= r){
				p = std::min(p,  prr[i]) ;
			}
		}
		std::cout << (p == INT_MAX ? -1 : p) << "\n" ;
	}
}