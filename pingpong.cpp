#include <stdio.h>
#define MAXN 64
int a[MAXN+1][MAXN+1] = {0};//����ȫ������
/*
 * ������k
 * ��ʼ��n��ѡ�ֵ��ճ�
 * ����gamecal��1,4������ʾ��1��ѡ�ֿ�ʼ������4λѡ���ճ�
 * */
void gamecal(int k, int n){
    int i,j;
    //�ݹ����
    if(n == 2){
        a[k][1] = k;//����ѡ�ֱ��
        a[k][2] = k+1;//����ѡ�ֱ��
        a[k+1][1] = k+1;//����ѡ�ֱ��
        a[k+1][2] = k;//����ѡ�ֱ��
    } else{
        gamecal(k,n/2);//�ݹ����
        gamecal(k+n/2, n/2);//�ݹ����
        for (i = k;  i < k+n/2 ; i++) {//������Ͻ�
            for (int j = n/2; j <=n ; j++) {
                a[i][j] = a[i+n/2][j-n/2];

            }
        }

        for (i = k+n/2;  i < k+n ; i++) {//������½�
            for (int j = n/2+1; j <=n ; j++) {
                a[i][j] = a[i-n/2][j-n/2];

            }
        }
    }

}

//int main(){
//    //
//    int m,i,j;
//    printf("��������");
//    scanf("%d",&m);
//    //ע���������������2���������ݣ��Ҳ�����64
//    gamecal(1,m);//���ú���
//    printf("\n���");
//    for (i=2; i <= m; i++) {
//        printf("%2d��", i - 1);
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
