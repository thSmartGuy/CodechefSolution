#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int main(){
	// fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	long long y ;
	while(t--){
		std::cin >> y ;

		long long ans = 0 ;
		for(int i = 1 ; i <= 700 ; i++){
			ans += (y-i >= 1)?(  (long long)std::sqrt(y-i)  ):0 ;
		}
		std::cout << ans << "\n" ;
	}
}