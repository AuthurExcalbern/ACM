/* 下面是正统的贪心解法
 * HDU:1050
 * 
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1050
 * 
 * It is solved by greedy algoorithm!
 * This isn't easy.But I make it!
 * Of cause,it also is solved by signing section,but it have some different.
 * 
 */

#include<stdio.h>
#include<string.h>
#define swap(a, b, key) key = a, a = b, b = key;

int N,count,list[210];

//The struct can let us check section status easily.
struct section
{
    int start,end;
    int bool;//It's used to sign whether the section was signed.
}sec[210];

//I use insertion sort to sort the "sec" struct arrey according to its size of end.
void insort(int len)
{
    int key1,key2,z,i,j;
    
    for(j = 1; j < len; j++)
    {
        //If we want to swap end, we should swap start too!!!
        key1 = sec[j].end;
        key2 = sec[j].start;
        z = j - 1;
        while(z >= 0 && sec[z].end > key1)
        {
            sec[z + 1].end = sec[z].end;
            sec[z + 1].start = sec[z].start;
            z = z - 1;
        }
        sec[z + 1].end = key1;
        sec[z + 1].start = key2;
    }
    
}

//This function is use recursion to choose the suitable section at each time. 
void choose(int beg, int len)
{
    int i,j = 0,z,min = 210;
    
    sec[beg].bool = 1;//Change the section status
    
    memset(list,0,sizeof(list));//Initialize the arrey
    
    for( i = beg + 1; i < len; i++)//
        if( sec[i].start > sec[beg].end && sec[i].bool == 0)
        {
            //The "list" arrey is used to record which section can be choosed.
            //It's very importent.
            //Because we can get plural choices when we choose the next section.
            //And we should choose the section which have the mininum "start".
            list[j] = i; 
            j++;
        }
    if( j != 0)
    {
        //Just search the section that have the mininum "start"
        for( i = 0; i < j; i++)
            if( min > sec[ list[i] ].start)
            {
                min = sec[ list[i] ].start;
                z = list[i];//Use "z" to record it.
            }
        
        //Use recursion to get the biggest table number (we can move) each time.
        choose(z, len);
    }
    else
        return;
}

int main()
{
    int count_i,count_j,testNum,eachTestNum,ans;
    int swapKey = 0;
    
    scanf("%d",&testNum);
    
    while(testNum--)
    {
        ans = 0;//Initialize the arrey
        
        scanf("%d",&eachTestNum);
        
        for( count_i = 0; count_i < eachTestNum; count_i++)
        {
            
            scanf("%d %d",&sec[count_i].start,&sec[count_i].end);
            
            //Just make the section more simple.
            sec[count_i].start = (sec[count_i].start + 1) / 2;
            sec[count_i].end = (sec[count_i].end + 1) / 2;
            
            //Pay attention to it!!
            //Maybe the start room number will bigger then the room end number.
            if( sec[count_i].start > sec[count_i].end)
                swap( sec[count_i].start, sec[count_i].end, swapKey);
            
            sec[count_i].bool = 0;//Initialize it!!!!!
        }
        
        insort(eachTestNum);
        
        for( count_i = 0; count_i < eachTestNum; count_i++)
        {
            if( sec[count_i].bool == 0)
            {
                ans++;
                choose(count_i, eachTestNum);
            }
        }
        
        ans = ans * 10;
        printf("%d\n",ans);
    }
    return 0;
}

/*下面是简单的标记区间解法 
 * HDU:1050
 * 
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1050
 * 
 * This is one kind of my solution,signing each section.
 * It is so easy.
 * But it's not solve by greedy algorithm.
 * So I will solve this problen by greedy algorithm latter.
 * In the other file named HDU1050_G,you could see it.
 * GOOD LUCK!
 * 
 *

#include<stdio.h>
#include<string.h>
#define swap(a, b, key) key = a, a = b, b = key;

int main(void)
{
    int count[210];//It is used to be record how many time every section have been used.
    int swapKey,count_i,count_j;
    int testNum,eachTestNum;
    int roomStart,roomEnd;
    int ans;
    
    scanf("%d",&testNum);//Input the test case number.
    
    while(testNum--)
    {
        memset(count,0,sizeof(count));//Initialize the array
        scanf("%d",&eachTestNum);
        
        for( count_i = 0; count_i < eachTestNum; count_i++)
        {
            scanf("%d %d", &roomStart, &roomEnd);
            
            //Just make the section more simple.
            roomEnd = (roomEnd + 1) / 2;
            roomStart = (roomStart + 1) / 2;
            
            //Pay attention to it!!
            //Maybe the start room number will bigger then the room end number.
            if(roomStart > roomEnd )
                swap(roomStart, roomEnd, swapKey);
            
            //Sign the section
            for( count_j = roomStart; count_j <= roomEnd; count_j++)
                count[count_j]++;
        }
        
        ans = -1;
        
        //Find the biggest signed times in the signed sections
        for( count_i = 0; count_i < 205; count_i++)
            if(ans < count[count_i])
                ans = count[count_i];
        
        printf("%d\n",ans*10);
    }
    return 0;
}
*/
