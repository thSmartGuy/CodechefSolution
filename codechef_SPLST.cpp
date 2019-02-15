#include <iostream>

bool check(int a, int b, int c, int x){
    if(x > a + b && x > a + c && x > b + c){
        return false ;
    }
    return true ;
}

int main(){
    int t, a, b, c, x, y, flag ;
    std::cin >> t ;
    while(t-->0){
        flag = 0 ;
        std::cin >> a >> b >> c >> x >> y ;
        if(a+b+c == x + y && check(a,b,c,x) && check(a,b,c,y)){
            if(((y - a) + (x - b) == c) || ((y - b) + (x - a) == c)){
                flag = 1 ;
            }

        }
        if(flag){
            std::cout << "YES\n" ;
        }
        else{
            std::cout << "NO\n" ;
        }
    }
}
