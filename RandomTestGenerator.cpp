#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include<ctime>

int main(){
	srand(time(0)) ;

	int t = 10 ;

	std::cout << t << "\n" ;

	int n, m ;
	while(t--){
		n = 1 + rand()%10, m = 1 + rand()%10 ;

		std::cout << n << " " << m << "\n" ;

		for(int i = 0 ; i < n ; i++){
			int sign = rand()%2 ;

			if(sign) sign = -1 ;
			else sign = 1 ;

			int num = rand()%20 ; 
			std::cout << sign * num << " " ;
		}
		std::cout << "\n" ;

		for(int i = 0 ; i < m ; i++){
			int sign = rand()%2 ;

			if(sign) sign = -1 ;
			else sign = 1 ;

			int num = rand()%20 ; 
			std::cout << sign * num << " " ;
		}
		std::cout << "\n" ;
	}
}