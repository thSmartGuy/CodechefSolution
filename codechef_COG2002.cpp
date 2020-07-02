#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long arr[111111] ;

int main(){
	//fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;

	int t = 1 ;
	std::cin >> t ;

	int n ;
	while(t--){
		std::cin >> n ; 

		long long l = 0 ;
		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
		}

		long long ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			ans = std::max(ans, arr[(i-1+n)%n] + arr[i] + arr[(i+1)%n]) ;
		}

		// for(int i = 0 ; i < n ; i++){
		// 	std::cout << arr[i] << " " ;
		// }
		// std::cout << "\n" ;

		std::cout << ans << "\n" ;
	}
}