#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>

void fast(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0) ;
}

int main(){
	//fast();
	// freopen("input.txt", "r", stdin) ;
	// freopen("output.txt", "w", stdout) ;
	
	std::srand(std::time(nullptr)); 
	
	int t = 1 ;
	std::cin >> t ;

	int noOfQue, Options, noOfForms ;
	while(t--){
		std::cin >> noOfQue >> Options >> noOfForms ;

		std::vector <std::map <int, int>> v(noOfQue) ;
		for(int i = 0 ; i < noOfQue ; i++){
			// std::cout << "i: " << i << " " ;
			for(int j = 0 ; j < noOfForms ; j++){
				int answer ; std::cin >> answer ;
				v[i][answer]++ ;
			}
		}
		// std::cout << "\n" ;

		std::vector <int> equalArray ;

		for(int i = 0 ; i < noOfQue ; i++){
			int answer = -1, max = 0 ;

			equalArray.clear() ;
			
			// for(auto it: v[i]){
			// 	if(it.second > max){
			// 		max = it.second ;
			// 		equalArray.clear() ;
			// 		equalArray.push_back(it.first) ;
			// 	}
			// 	else if(it.second == max){
			// 		equalArray.push_back(it.first) ;	
			// 	}
			// }

			// int n = equalArray.size() ;
			// int random_variable = std::rand() % n ;

			// answer = equalArray[random_variable] ;

			// std::cout << answer << " " ;

			std::cout << 1 + std::rand() % Options << "\n" ;
		}
		std::cout << "\n" ;
	}
}