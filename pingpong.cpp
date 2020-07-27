#include <stdio.h>
#define MAXN 64
int a[MAXN+1][MAXN+1] = {0};//定义全局数组
/*
 * 处理编号k
 * 开始的n个选手的日程
 * 例如gamecal（1,4），表示从1号选手开始，安排4位选手日程
 * */
void gamecal(int k, int n){
    int i,j;
    //递归出口
    if(n == 2){
        a[k][1] = k;//参赛选手编号
        a[k][2] = k+1;//对阵选手编号
        a[k+1][1] = k+1;//参赛选手编号
        a[k+1][2] = k;//对阵选手编号
    } else{
        gamecal(k,n/2);//递归调用
        gamecal(k+n/2, n/2);//递归调用
        for (i = k;  i < k+n/2 ; i++) {//填充右上角
            for (int j = n/2; j <=n ; j++) {
                a[i][j] = a[i+n/2][j-n/2];

            }
        }

        for (i = k+n/2;  i < k+n ; i++) {//填充右下角
            for (int j = n/2+1; j <=n ; j++) {
                a[i][j] = a[i-n/2][j-n/2];

            }
        }
    }

}

//int main(){
//    //
//    int m,i,j;
//    printf("输入人数");
//    scanf("%d",&m);
//    //注意输入的数必须是2的整数次幂，且不超过64
//    gamecal(1,m);//调用函数
//    printf("\n编号");
//    for (i=2; i <= m; i++) {
//        printf("%2d天", i - 1);
//        printf("\n");
//    }
//
//    for(i = 1; i <=m; i++){
//        for (j = 1; j <=m; j++) {
//            printf("%4d", a[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
