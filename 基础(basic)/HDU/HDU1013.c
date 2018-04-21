/*
 * HDU 1013
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1013
 * 
 * The digital root of a positive integer is found by summing the digits of the integer.
 * If the resulting value is a single digit then that digit is the digital root.
 * If the resulting value contains two or more digits, those digits are summed and the process is repeated.
 * This is continued as long as necessary to obtain a single digit.
 * For example, consider the positive integer 24.
 * Adding the 2 and the 4 yields a value of 6. Since 6 is a single digit, 6 is the digital root of 24.
 * Now consider the positive integer 39. Adding the 3 and the 9 yields 12.
 * Since 12 is not a single digit, the process must be repeated. Adding the 1 and the 2 yeilds 3, a single digit and also the digital root of 39.
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char array[10010];
    int count_i;
    int sum;
    int len;
    
    while(~scanf("%s", array), strcmp(array, "0") )
    {
        sum = 0;                                        //Initialize
        len = strlen(array);
        
        for( count_i = 0; count_i < len; count_i++)
            sum = sum + array[count_i] - '0';
        
        printf("%d\n", (sum-1) % 9 + 1);                //Find its regular
    }
    return 0;
}
