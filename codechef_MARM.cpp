#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

long long arr[11111] ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	long long k ;
	while(t--){
		std::cin >> n >> k ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> arr[i] ;
		}

		bool flag = ((k > (n/2)) ? 1 : 0) ;

		k %= (3*n) ;

		for(int i = 0 ; i < k ; i++){
			long long a = arr[(i%n)] ;
			long long b = arr[n - (i%n) - 1] ;

			arr[(i%n)] = a^b ;
		}

		if(n&1 && flag){
			arr[(n/2)] = 0 ;
		}

		for(int i = 0 ; i < n ; i++){
			std::cout << arr[i] << " " ;
		}
		std::cout << "\n" ;
	}
}