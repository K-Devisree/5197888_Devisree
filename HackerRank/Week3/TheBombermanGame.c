Question:The Bomberman Game

Bomberman lives in a rectangular grid. Each cell in the grid either contains a bomb or nothing at all.

Each bomb can be planted in any cell of the grid but once planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it's destroyed — along with anything in its four neighboring cells. This means that if a bomb detonates in cell , any valid cells  and  are cleared. If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without detonating, so there's no chain reaction.

Bomberman is immune to bombs, so he can move freely throughout the grid. Here's what he does:

Initially, Bomberman arbitrarily plants bombs in some of the cells, the initial state.
After one second, Bomberman does nothing.
After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. No bombs detonate at this point.
After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
Bomberman then repeats steps 3 and 4 indefinitely.
Note that during every second Bomberman plants bombs, the bombs are planted simultaneously (i.e., at the exact same moment), and any bombs planted at the same time will detonate at the same time.

Given the initial configuration of the grid with the locations of Bomberman's first batch of planted bombs, determine the state of the grid after  seconds.

Solution:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deto(int r,int c,char g[r][c+1],char res[r][c+1]){
    int dr[]={-1,1,0,0,0};
    int dc[]={0,0,-1,1,0};
    char temp[r][c+1];

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp[i][j]='O';

        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(g[i][j]=='O'){
                for(int k=0;k<5;k++){
                    int ni=i+dr[k], nj=j+dc[k];
                    if(ni>=0 && ni<r && nj>=0 && nj<c)
                        temp[ni][nj]='.';
                }
            }
        }
    }

        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            res[i][j]=temp[i][j];
        res[i][c]='\0';
    }
}

int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    char grid[r][c+1], t3[r][c+1], t5[r][c+1];

    for(int i=0;i<r;i++)
        scanf("%s", grid[i]);

        if(n==1){
        for(int i=0;i<r;i++)
            printf("%s\n", grid[i]);
        return 0;
    }

        deto(r, c, grid, t3);

       deto(r, c, t3, t5);

    
    if(n%2==0){  
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                printf("O");
            printf("\n");
        }
    }
    else if(n%4==3){  
        for(int i=0;i<r;i++)
            printf("%s\n", t3[i]);
    }
    else if(n%4==1){  // t=5 pattern
        for(int i=0;i<r;i++)
            printf("%s\n", t5[i]);
    }

    return 0;
}
