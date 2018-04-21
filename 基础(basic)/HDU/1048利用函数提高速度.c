#include<stdio.h>
#include<string.h>
char str[110];
int main()
{
    void shilf();
    char start[10],end[10];
    //char std[10] = "ENDOFINPUT";
    //char str[110];

   // menset(
    while(1)
    {
        //printf("START\n");
        gets(start);
        if(!strcmp(start,"ENDOFINPUT"))
            break;
        //printf("END\n");
        gets(str);
        shilf();
        gets(end);
        puts(str);
    }
    return 0;
}
void shilf()
{
    int count_i;
    for(count_i = 0;str[count_i] != '\0';count_i++)
    {
        if(str[count_i] >= 'F' && str[count_i] <= 'Z')
            str[count_i] = str[count_i] - 5;
        else if(str[count_i] >= 'A' && str[count_i] <= 'E')
            str[count_i] = str[count_i] + 21;
    }
}