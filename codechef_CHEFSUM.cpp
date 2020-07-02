#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long arr[111111], pre[111111], suff[111111] ;

int main(){
	// fast();
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
			l += arr[i] ;
			pre[i] = l ;
		}

		l = 0 ;
		for(int i = n - 1 ; i >= 0 ; i--){
			l += arr[i] ;
			suff[i] = l ;
		}

		long long ans = 1e11, ansIdx = 0 ;
		for(int i = 0 ; i < n ; i++){
			if(suff[i] + pre[i] < ans){
				ans = suff[i] + pre[i] ;
				ansIdx = i ;
			}
		}
		std::cout << ansIdx + 1 << "\n" ;
	}
}