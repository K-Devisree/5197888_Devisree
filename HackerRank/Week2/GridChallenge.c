Question: Grid Challenge
Given a square grid of characters in the range ascii[a-z], rearrange elements of each row alphabetically, ascending. Determine if the columns are also in ascending alphabetical order, top to bottom. Return YES if they are or NO if they are not.

Solution:

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a;
    scanf("%d",&a);
    
    while(a--){
        int n;
        scanf("%d",&n);
        char grid[n][n+1];
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(grid[i][j]>grid[i][k]){
                        char temp=grid[i][j];
                        grid[i][j]=grid[i][k];
                        grid[i][k]=temp;
                    }
                }
            }
        }
        int v=1;
        for(int i=0;i<n && v;i++){
            for(int j=1;j<n;j++){
                if(grid[j][i]<grid[j-1][i]){
                    v=0;
                    break;
                }
            }
        }
        if(v){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}

