#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long hrr[311111], xrr[311111] ;

long long dis[311111] ;
int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();

	long long n ;
	while(t--){
		std::cin >> n ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> xrr[i] >> hrr[i] ;
		}

		dis[0] = xrr[1] - xrr[0] ;
		for(int i = 1 ; i < n - 1 ; i++){
			dis[i] = (xrr[i + 1] - xrr[i]) + (xrr[i] - xrr[i - 1]) ;
		}
		dis[n - 1] = xrr[n - 1] - xrr[n - 2] ;

		std::sort(dis, dis + n) ;
		std::sort(hrr, hrr + n) ;

		long long ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			ans += (1ll*dis[i]*hrr[i]) ;
		}
		std::cout << ans << "\n" ;
	}
}