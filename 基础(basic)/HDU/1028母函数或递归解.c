//����Ϊĸ������� 

//�ο����ϣ�   http://www.wutianqi.com/?p=596

#include<stdio.h>
int f(int n){
	int s[130],a[130];
	int i,j,k;
	for(i=0;i<=n;i++){
        s[i]=1;
        a[i]=0;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=n;j++)
        	for(k=0;k*i+j<=n;k++)
                a[k*i+j]+=s[j];
                for(k=0;k<=n;k++){
                    s[k]=a[k];
                    a[k]=0;
                }
	}
    return s[n];
}
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",f(n));
    }
    return  0;
}

/*����Ϊ�ݹ����

 �������������ǽ�һ��������n���һ�������Ӳ�����n����ʽ�����������е�������������n��
    ��6����������Ϊ
    
    6
    5 + 1
    4 + 2, 4 + 1 + 1
    3 + 3, 3 + 2 + 1, 3 + 1 + 1 + 1
    2 + 2 + 2, 2 + 2 + 1 + 1, 2 + 1 + 1 + 1 + 1
    1 + 1 + 1 + 1 + 1 + 1
    
    ��11�֡��������һ��ͨ���ݹ鷽���õ�һ���������Ļ�������
    
    �ݹ麯��������Ϊint split(int n, int m);����nΪҪ���ֵ���������m�ǻ����е�������(��m > nʱ��������Ϊn)��
    1 ��n = 1��m = 1ʱ��split��ֵΪ1���ɸ�������������ֻ��һ������1 �� 1 + 1 + 1 + 1 + 1 + 1
    ���ó����ʾΪif(n == 1 || m == 1) return 1;
    
    2 ���濴һ��m �� n�Ĺ�ϵ�����������ֹ�ϵ
    (1) m > n
    ������������ʵ�������������ܴ���n�����������������Եȼ�Ϊsplit(n, n);
    ���ó����ʾΪif(m > n) return split(n, n);    
    (2) m = n
    ����������õݹ��ʾΪsplit(n, m - 1) + 1�������������п��Կ�������������
    ��Ϊ6��С��6�Ļ���֮��
    �ó����ʾΪif(m == n) return (split(n, m - 1) + 1);
    (3) m < n
    ������һ���������ڻ��ֵĴ����ʱ�������������
    ���������Կ�������m = 4����split(6, 4)��ֵ��������С��4������������2�Ļ������ĺ͡�
    ��ˣ�split(n, m)�ɱ�ʾΪsplit(n, m - 1) + split(n - m, m)
    
    ���������������ɵ�Դ�������£�
 
#include<stdio.h>
int s[130][130]={0};
int split (int n,int m)
{
    if(s[n][m])
        return s[n][m];
    if(n<1||m<1)
        return s[n][m]=0;
    if(n==1||m==0)
        return 1;
    if(n<m)
        return s[n][m]=split(n,n);
    if(n==m)
        return s[n][m]=(split(n,m-1)+1);
    else
        return s[n][m]=(split(n,m-1)+split(n-m,m));
}
int main ()
{
    int n;
    split(120,120);
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",split(n,n));
    return 0;
}
*/ 
