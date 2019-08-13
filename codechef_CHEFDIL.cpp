#include <iostream>
#include <vector>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

void flip(std::string &str, int idx){
	if(idx >= 0 && idx < str.size()){
		str[idx] = str[idx] == '1' ? '0' : (str[idx] == '0' ? '1' : str[idx]) ;
	}
}

bool solve(std::string str){
	int c = 0, n = str.size() ;
	for(int i = 0 ; i < n ; i++){
		if(str[i] == '1'){
			int j = i - 1 ;

			str[i] = 'a' ;
			flip(str, i - 1) ;
			flip(str, i + 1) ;
			c++ ;
			//std::cout << str << "\n" ;
			
			while(j >= 0 && str[j] == '1'){
				str[i] = 'a' ;
				flip(str, j - 1) ;
				flip(str, j + 1) ;
				j-- ;
				c++ ;
			}
		}
		//std::cout << "c: " << c << " n: " << n << "\n" ;
		if(c == n) return 1 ;
	}
	return 0 ;
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	std::string str ;
	while(t--){
		std::cin >> str ;

		std::cout << (solve(str) ? "WIN\n" : "LOSE\n") ;
	}
}