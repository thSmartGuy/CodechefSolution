#include <cstdio>

int main(){
    int t, s, h;
    scanf("%d", &t) ;
    while(t--){
        scanf("%d%d", &s, &h) ;
        if(h>=s){
            printf("Himawari\n") ;
        }
        else{
            printf("Shinchan\n") ;
        }
    }
}
