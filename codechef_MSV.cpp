#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

std::unordered_map <int, int> mp ;

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n ;
	while(t--){
		mp.clear() ;

		int tmp ;
		std::cin >> n ;

		int max_ = 0 ;

		for(int i = 0 ; i < n ; i++){
			std::cin >> tmp ;

			if(mp.count(tmp)){
				max_ = std::max(max_, mp[tmp]) ;
			}

			for(int i = 1 ; i <= std::sqrt(tmp) ; i++) {
				if(tmp%i == 0){

					if(mp.count(i)){
						mp[i]++ ;
					}
					else mp[i] = 1 ;
					
					if(tmp/i != i){
						if(mp.count(tmp/i)){
							mp[tmp/i]++ ;
						}
						else mp[tmp/i] = 1 ;	
					}
				}	
			}
		}
		std::cout << max_ << "\n" ;
	}
}