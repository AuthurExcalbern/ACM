//输出第N个素数
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 20000000//定义一个数组长度

bool prime[MAX + 1];//素数表

int main(void)
{
    int i, j, count = 0;//count为计数器
    
    //初始化，将prime数组全部都初始化为true
    //0，1都不是素数，所以为false，2是素数，所以为true
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false; prime[2] = true;
    
    /*从2开始进行遍历，
      i * i <= MAX 就等价于 i < sqrt(MAX);
      但是前者更不容易出错*/
    for(i = 2; i * i <= MAX; i ++)
    {
        //如果没有被标记的话将它的倍数的数标记(标记就是将它赋值为false)
        if(prime[i])
        {
            //因为是从2开始的，所以j = i * i 就行了，最小的一个他的倍数的就是i * i了，不可能有比这个更小的了
            for(j = i + i; j <= MAX; j += i)
                prime[j] = false;
        }
    }
    
    int N;
    scanf("%d", &N);
    
    for(i = 2; i <= MAX; i ++)
    {
        if(prime[i]) count++;
        if(count == N)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
