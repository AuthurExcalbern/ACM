//‘≠Ã‚µÿ÷∑£∫ http://acm.hdu.edu.cn/showproblem.php?pid=1009
#include<stdio.h>
int main(){
	double javaBeams[1000],catFood[1000],max_trade_rate;
	int cases_num=1000,count_i,count_j,catFood_M,line_N;
	while(cases_num--){
		scanf("%d%d",&catFood_M,&line_N);
		if(catFood_M==-1&&line_N==-1) break;
		count_j=line_N;
		for(count_i=0;line_N--;count_i++){
			scanf("%f%f",javaBeams[count_i],catFood[count_i]);
		}
		while(count_j--){
			if(javaBeams[count_j]/catFood[count_j]>=javaBeams[++count_j]/catFood[++count_j]) continue;
			else javaBeams[count_j]=javaBeams[++count_j];catFood[count_j]=catFood[++count_j];
		}
		max_trade_rate=javaBeams[count_j]/catFood[count_j];
		printf("%7.3f",max_trade_rate);
	}
	return 0;
}
