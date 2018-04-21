#include<stdio.h>
#include<string.h>
int mem[110][110];
int dp(int n,int p,int m,int t)
{
    int ans=0;
    if(mem[m][p]>=0)
        return mem[m][p];
    if(m==0){
        if(p==t) 
            return 1;
        else 
            return 0;
    } 
    if(p>=1&&p<n)
        ans+=dp(n,p+1,m-1,t);
    if(p>1&&p<=n)  
        ans+=dp(n,p-1,m-1,t);
    mem[m][p]=ans;
    return ans;
}
int main()
{
    int n,p,m,t;
    while(~scanf("%d%d%d%d",&n,&p,&m,&t))
    {
        memset(mem,-1,sizeof(mem));
        printf("%d\n",dp(n,p,m,t));
    }
    return 0;
}
/*
 * 
一开始觉得是一道组合数学的问题，因为从起点P走到终点T必为向左走或向右走的有限集合（即只可以由向左走或向右走构成），且从起点P走到终点T的步是必走的，那么走M步减去从起点P到T必走的步后就是点与点之间的来回走了（即剩下的步向左走与向右走的步数必相等），那么总的方案数就是从走M步中挑出向左走或向右走的较少步（即为C(较少步，M)）。如果从起点P走到终点T为一直向左走，那么向右走就为较少步，同理，如果是向右走，那么向左走就为较少步，不难得出，较少步即为(M-|P-T|)/2,所有最终结果即为C((M-|P-T|)/2,M)。但是这种走法必须是不受限制的，比如如果起点为2，那么不能开始连续向左走2步，如果走到3，就不能连续向左走3步，所以这种方法解决不了。
     换个思路，其实从第M步走到T只有两种可能，即第M-1步已经走到T-1了，然后从T-1走一步到T，或者第M-1步已经走到T+1了，然后从T+1走一步到T，而M-1步走到T-1必为从M-2步走到T-2或者从M-2步走到T走一步到T-1，同理，第M-1步走到T+1必为从第M-2步走到T或者走到T+2走一步到T+1，那么，很明显的dp了。
     我们设数组dp[i][j].表示第i分钟从起点p走到j的方案数，很明显，按照以上结论，第i分钟从p走到j为从第i-1分钟在j-1或者第i-1分钟在j+1走一步第j,即dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1](即从起点走i步到j的方案数等于从起点走i-1步到j-1或者从起点走i-1步到j+1的方案数之和)。枚举i从第一分钟到第M分钟，枚举j从第一个点到第N个点就AC了。

最后贴个代码：

import java.util.*;
import java.math.*;
public class Main
{
	static int [][]dp=new int[110][110];
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			for(int i=0;i<110;i++)
				Arrays.fill(dp[i], 0);
			int n=cin.nextInt();
			int p=cin.nextInt();
			int m=cin.nextInt();
			int t=cin.nextInt();
			if(p-1>=1) dp[1][p-1]=1;
			if(p+1<=n) dp[1][p+1]=1;
			for(int i=2;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
					dp[i][j]=dp[i-1][j-1]
							+dp[i-1][j+1];
			}
			System.out.println(dp[m][t]);
		}
	}
}

*/