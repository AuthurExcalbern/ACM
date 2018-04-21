#include<stdio.h>
int main()
{
    int testCase;
    int testNum,num[1000];
    int count_i,count_j,count_z;
    int key;
    scanf("%d",&testCase);
    for(count_i = 0;count_i < testCase;count_i++)
    {
        scanf("%d",&testNum);
        for(count_j = 0;count_j < testNum;count_j++)
        {
            scanf("%d",&num[count_j]);
        }
        for(count_j = 1;count_j < testNum;count_j++)
        {
            key = num[count_j];
            count_z = count_j - 1;
            while(count_z >= 0 && num[count_z] > key)
            {
                num[count_z + 1] = num[count_z];
                count_z = count_z - 1;
            }
            num[count_z + 1] = key;
        }
        for(count_j = 0;count_j < (testNum - 1);count_j++)
            printf("%d ",num[count_j]);
        printf("%d\n",num[count_j]);
    }
    return 0;
}
            