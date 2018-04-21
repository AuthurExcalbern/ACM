/*
 *POJ 2251
 *
 *URL:
 *
 */

#include<stdio.h>
#include<string.h>
//#include<stdlib.h

char map[35][35][35];
int L, R, C;
int ans, cnt;
int S_L, S_R, S_C;
int E_L, E_R, E_C;

int DFS(int l, int c, int r)
{
    while(ans == -1 && (map[l][c][r] == '.' || map[l][c][r] == 'E') )
    {
        if(map[l][c][r] == 'E')
            return cnt;
        else
        {
            DFS(l + 1, c, r); cnt++;
            DFS(l - 1, c, r);
            DFS(l, c + 1, r);
            DFS(l, c - 1, r);
            DFS(l, c, r + 1);
            DFS(l, c, r - 1);
        }
    }
    return -1;
}

int main(void)
{
    int cnt_i, cnt_j, cnt_k;

    while(scanf("%d %d %d", &L, &R, &C), L != 0 && R != 0 && C != 0)
    {
        ans = -1;
        cnt = 0;
        memset(map, 0, sizeof(map) );

        for(cnt_i = 1; cnt_i <= L; cnt_i++)
            for(cnt_j = 1; cnt_j <= C; cnt_j++)
                for(cnt_k = 1; cnt_k <= R; cnt_k++)
                {
                    scanf("%c", &map[cnt_i][cnt_j][cnt_k] );
                    if(map[cnt_i][cnt_j][cnt_k] == 'S')
                    {
                        S_L = cnt_i;
                        S_C = cnt_j;
                        S_R = cnt_k;
                    }
                /*if(map[cnt_i][cnt_j][cnt_k] == 'E')
                {
                    E_L = cnt_i;
                    E_C = cnt_j;
                    E_R = cnt_k;
                }*/
            }

        ans = DFS(S_L, S_C, S_R);

        if(ans == -1)
            printf("Trapped!");
        else
            printf("Escaped in %d minute(s).", ans);
    }
    return 0;
}
