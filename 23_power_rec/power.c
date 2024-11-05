#include<stdlib.h>
#include<stdio.h>

unsigned power_helper(unsigned x, unsigned y, unsigned ans){
    if(y==0){
        return ans;
    }
    ans *=x;
    return power_helper(x,y-1,ans); 


}

unsigned power(unsigned x, unsigned y){
    if(x==0 && y==0){
        return 1;
    }
    return power_helper(x,y,1);
}
