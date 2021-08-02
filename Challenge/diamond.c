// <DESCRIPTION>
// Written by <YOUR NAME HERE> on <DATE>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void space(int number){
    for(int i=0;i<number;++i){
        printf(" ");
    }
    return;
}
bool status=true;
int main(void) {
    int lll=0;
    printf("Enter side length: ");
    scanf("%d",&lll);
    int index=1;
    while(index<=lll*2){
        if(!status&&index==0){
            break;
        }
        if(index==lll+1){
            status=false;
            index-=2;
        }
        if(index==1){
            space(lll-1);
            printf("*\n");
        }
        else{
            space(lll-index);
            printf("*");
            space((index-2)*2+1);
            printf("*\n");
        }
        if(status){
            index++;
        }
        else{
            index--;
        }
        
    }
    return 0;
}
