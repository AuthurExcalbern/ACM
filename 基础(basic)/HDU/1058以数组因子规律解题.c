#include<stdio.h>
int main()
{
    void findHumble(int humbleList[5842]);
    void print(int num,int humbleList[5842]);
    int humbleNum;
    int num;
    int humbleList[5842];
    findHumble(humbleList);
    while(scanf("%d",&num) != EOF)
    {
        if(num == 0)
            break;
        print(num,humbleList);
    }
    return 0;
}
void findHumble(int humbleList[5842])
{
    int count_i;
    int key,key_x,key_y,key_z,key_g;
    humbleList[0] = 1;
    key_x = key_y = key_z = key_g = 0;
    for(count_i = 1;count_i < 5842;count_i++)
    {
        while(humbleList[key_x] * 2 <= humbleList[count_i - 1])
            key_x++;
        while(humbleList[key_y] * 3 <= humbleList[count_i - 1])
            key_y++;
        while(humbleList[key_z] * 5 <= humbleList[count_i - 1])
            key_z++;
        while(humbleList[key_g] * 7 <= humbleList[count_i - 1])
            key_g++;
        key = humbleList[key_x]*2;
        if(humbleList[key_y] * 3 < key)
            key = humbleList[key_y]*3;
        if(humbleList[key_z] * 5 < key)
            key = humbleList[key_z]*5;
        if(humbleList[key_g] * 7 < key)
            key = humbleList[key_g]*7;
        humbleList[count_i] = key;
    }
}
void print(int num,int humbleList[5842])
{
    int numJudge = num % 10;
    if(num == 11 || num == 12 || num == 13)
        printf("The %dth humble number is %d.\n",num,humbleList[num-1]);
    else if(numJudge == 1)
        printf("The %dst humble number is %d.\n",num,humbleList[num-1]);
    else if(numJudge == 2)
        printf("The %dnd humble number is %d.\n",num,humbleList[num-1]);
    else if(numJudge == 3)
        printf("The %drd humble number is %d.\n",num,humbleList[num-1]);
    else
        printf("The %dth humble number is %d.\n",num,humbleList[num-1]);
}