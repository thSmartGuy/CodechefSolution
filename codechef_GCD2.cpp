#include <iostream>

int gcd(int a, int b){
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
    int a, intb ;
    std::string b ;

    int t ;

    std::cin >> t ;

    while(t--){
        std::cin >> a >> b ;

        intb = 1 ;
        if(!a){
            std::cout << b << "\n" ;
        }
        else{
            intb = (int) (b[0] - '0') ;
            for(int i = 1 ; i < b.size() ; i++){
                intb = (intb*10 + (int)(b[i] - '0'))%a ;
            }
            std::cout << gcd(intb, a) << "\n" ;
        }
    }
}
