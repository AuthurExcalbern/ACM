#include<stdio.h>
int main(){
    int a,b;
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        printf("%d\n",2*b*b-b+1);
    }
}