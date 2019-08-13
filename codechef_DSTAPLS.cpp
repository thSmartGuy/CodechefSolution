#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	long long n, k ;
	//fast();
	while(t--){
		std::cin >> n >> k ;

		long long sr = std::ceil(std::sqrt(n)) ;
		if(k > sr){
			std::cout << "YES\n" ;
		}
		else{
			long long dv = k*k ;
			if(n%dv == 0){
				std::cout << "NO\n" ;
			}
			else std::cout << "YES\n" ;
		}
	}
}