#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int lArray[10000], rArray[10000] ;
int lSum, rSum ;

int ans ;

void recur(int idx, int n){
	if(idx >= n){
		ans = std::min(ans, std::abs(lSum - rSum)) ;
		return ;
	}

	recur(idx + 1, n) ;

	lSum -= lArray[idx] ;
	rSum -= rArray[idx] ;

	lSum += rArray[idx] ;
	rSum += lArray[idx] ;
	
	ans = std::min(ans, std::abs(lSum - rSum)) ;

	lSum += lArray[idx] ;
	rSum += rArray[idx] ;

	lSum -= rArray[idx] ;
	rSum -= lArray[idx] ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	while(t--){
		std::cin >> n ; 

		int mid = n / 2 ;

		std::string str ;
		for(int i = 0 ; i < n ; i++){
			std::cin >> str ;

			lArray[i] = rArray[i] = 0 ;
			
			for(int j = 0 ; j < n ; j++){
				if(j < mid) lArray[i] += (str[j] == '1' ? 1 : 0) ;
				if(j >= mid) rArray[i] += (str[j] == '1' ? 1 : 0) ;
			}
		}
		/*

		for(int i = 0 ; i < n ; i++){
			std::cout << lArray[i] << " " ;
		}
		std::cout << "\n"  ;


		for(int i = 0 ; i < n ; i++){
			std::cout << rArray[i] << " " ;
		}
		std::cout << "\n"  ;

		//*/

		lSum = 0, rSum = 0 ;
		for(int i = 0 ; i < n ; i++){
			lSum += lArray[i] ;
			rSum += rArray[i] ;
		}
		ans = INT_MAX ; 

/*
		std::cout << "lSUm: " << lSum << "\n" ;
		std::cout << "rSum: " << rSum << "\n" ;
		//*/

		recur(0, n) ;
		std::cout << ans << "\n" ;
	}
}