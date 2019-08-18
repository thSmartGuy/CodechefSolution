#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int possible[100000 + 111] ;

void pre(std::string str){
	int n = str.size() ;

	std::fill(&possible[0], &possible[0] + sizeof(possible)/sizeof(int), 0) ;
	
	for(int i = 0 ; i < n - 2 ; i++){
		if(i) possible[i] = (possible[i - 1]) ;

		if(str[i] == str[i + 1] || 
			str[i + 1] == str[i + 2] || 
			str[i] == str[i + 2]){
			possible[i] += 1 ;
		}
	}
}

int main(){
	int t = 1 ;
	std::cin >> t ;

	//fast();
	int n, q ;

	std::string str ;
	while(t--){
		std::cin >> n >> q ;

		std::cin >> str ;

		pre(str) ;

		int l, r ;
		while(q--){
			std::cin >> l >> r ;
			l--, r-- ;

			int tr = 0 ;
			//std::cout << "l: " << l << " r: " << r << "\n" ;

			if(r - l + 1 >= 3){
				if(l == 0){
					tr = possible[r - 2] ;
				}
				else{
					tr = possible[r - 2] - possible[l - 1] ;
				}
			}

			/*
			for(int i = l ; i <= r - 2 ; i++){
			//	std::cout << i << " " ;
				if(possible[i] == 1){
					tr = 1 ;
					//break ;
				}
			}
			//*/

			std::cout << (tr > 0 ? "YES\n" : "NO\n") ;
		}
	}
}