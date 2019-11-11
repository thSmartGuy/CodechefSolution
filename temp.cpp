#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int arr[100011] ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n, m, s ;
	while(t--){
		std::cin >> n >> m >> s ;

		for(int i = 0 ; i < n ; i++) {
			std::cin >> arr[i] ;
		}

		std::sort(arr, arr + n);

		int days[n] = {} ;

		for(int i = 0 ; i < n ; i++) {
			days[i] = arr[i] / s ;
		}

		int topics = 0 ;
		int daysComp = 0 ;
		for(int i = 0 ; i < n ; i++) {
			
		}
	}
}