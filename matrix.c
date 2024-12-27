#include<stdio.h>

#define V 4

void printMatrix(int adj[V][V]){
    for(int i = 0; i< V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", adj[i][j]);
          }
          printf("\n");
        }
      }

int main(){
        // khoi tao ma tran ke
        int adj[V][V] = {0};

        //them cac canh cho matrix
        adj[0][1] = 1;
        adj[0][2] = 1;
        adj[1][2] = 1;
        adj[2][3] = 1;

        printf("ma tran ke cua do thi: \n");
        printMatrix(adj);
        return 0;
      }
