#include<stdio.h>
#include<string.h>
int s[100010];
int a[200];
int b[200];
int main(){
	while(1){
		int n,m,x,y;
		scanf("%d %d",&n,&m);
		int flag = 0;
		memset(s,0,sizeof(s));//忘了初始化，wa了一次。。。
		if(n==0&&m==0){
			break;
		}
		else{
			for(int i = 0;i<n;i++){
				scanf("%d",&x);
				s[x]=1;
			}
			for(int j = 0;j<m;j++){
				scanf("%d",&y);
				s[y]--;
			}
		}
		for(int i = 0;i<10010;i++){
			if(s[i]==1){
				printf("%d ",i);
				flag = 1;				
			}
		}
		if(flag==1){
			printf("\n");		
		}
		if(flag == 0)
			printf("NULL\n");
	}
}

/*
#include<stdio.h>
#include<stdlib.h>

int cmp(const int *a,const int *b)
{
    return *a - *b;
}

int main()
{
    int n, m, i, j;
    int s[101];
    while( scanf("%d %d",&n, &m) , m + n)
    {
        for( i = 0; i < n; i++)
            scanf("%d", s + i);
        for( i = 0; i < n; i++)
        {
            scanf( "%d", s + n);
            for( j = 0; s[j] != s[n]; j++);
            if( j != n)
                s[j] = s[--n];
        }
        qsort( s, n, sizeof(int), cmp);
        for( i = 0; i < n; i++)
            printf("%d", s[i]);
        printf(n ? "\n" : "NULL\n");
    }
    return 0;
}*/