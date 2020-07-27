#include <stdio.h>

#define MAX 5
#define  NUM 9

int num[NUM];
int lottery[MAX];
int count = 0;
void combine(int n, int m){
    int i, j;
    for(i = n; i >=m; i--){
        lottery[m-1] = num[i-1];
        if(m > 1){
            combine(i-1, m-1);
        } else{
            for(j = MAX - 1; j >=0; j--){
                printf("%3d",lottery[j]);
                count++;
            }
            printf("\n");
        }
    }
}

//int main(){
//    int i, j;
//    for (i = 0; i < NUM ; i++) {
//        num[i] = i+1;
//    }
//    for (i = 0; i < MAX; i++) {
//        lottery[i] = 0;
//    }
//    combine(NUM, MAX);
//    printf("count = %d",&count);
//    return 0;
//}