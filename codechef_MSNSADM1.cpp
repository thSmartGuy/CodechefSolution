#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[1001], brr[1001] ;
int main(){
	int t = 1, n ;
	std::cin >> t ;

	//fast();
	while(t--){
		std::cin >> n ;

		for(int i = 0 ; i < n ; i++) std::cin >> arr[i] ;
		for(int i = 0 ; i < n ; i++) std::cin >> brr[i] ;

		int max = 0 ;
		for(int i = 0 ; i < n ; i++){
			max = std::max(max, arr[i]*20 - brr[i]*10) ;
		}
		std::cout << max << "\n" ;
	}
}