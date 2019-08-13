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

int countA(std::string str, int size){
	int c = 0 ;
	for(int i = 0 ; i < size ; i++){
		if(str[i] == 'a') c++ ;
		else break ;
	}
	return c ;
}

bool solve(std::string &str, int i, int removed, int size){
	if(countA(str, size) == size) return 1 ;
	if(i >= size) return 0 ;

	std::cout << str << "\n" ;
	if(str[i] == '1'){ // either flip or do not flip
		str[i] = 'a' ;
		flip(str, i - 1) ;
		flip(str, i + 1) ;
		if(solve(str, 0, 0, i) && solve(str, i + 1, 0, size)){
			return 1 ;
		}
		else{
			str[i] = '1' ; // backtrack
			flip(str, i - 1) ;
			flip(str, i + 1) ;
			return solve(str, i + 1, removed, size) ;
		}
	}
	return solve(str, i + 1, removed, size) ; // do not flip
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	std::string str ;
	while(t--){
		std::cin >> str ;

		std::cout << (solve(str, 0, 0, str.size()) ? "YES\n" : "NO\n") << "\n" ;
	}
}