/*
 * Created by df on 2020/8/4.
 *
 * ͼ������������
 * �ڽӾ�������
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define INFINITY 99 //��Ϊ��������ֵ
#define MaxSize 50 //����������ֵ

typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
/*
 * DG,����ͼ
 * DN,������
 * UG,����ͼ
 * UN,������
 * */
typedef enum {DG,DN,UG,UN}GraphKind;

/*
 * ����
 * */
typedef struct {
    int adj; //Ȩֵ

    InfoPtr *info;//������߱������Ϣ
}ArcNode,AdjMatrix[MaxSize][MaxSize];

/*
 * ͼ
 * */
typedef struct {
    VertexType vex[MaxSize]; //��Ԥ�涨���һά����
    AdjMatrix arc;// ���ڴ满��ߵĶ�ά����
    int vexnum,arcnum;//�������ͱߣ�������
    GraphKind kind;
}MGraph;

int LocateVertex(MGraph N,VertexType v);
//����ͼ
void DestroyGraph(MGraph *N);
//����ڽӾ���洢ͼʾ
void DisplayGraph(MGraph N);

/*
 *���ڽӾ����ʾ������
 * */
void CreateGraph(MGraph *N){
    int vNum = 0,i =0 ,j = 0, k = 0, w = 0;
    VertexType v1,v2;
    cout<<"�������������Ķ������ͻ���"<<endl;
    cin>>N->vexnum>>N->arcnum;
    cout<<"������"<<N->vexnum<<"�������ֵ"<<endl;
    //����Ķ���ֵ
    for (i = 0; i < N->vexnum; ++i) {
        cin>>N->vex[i];
    }
    //��ʼ���ڽӾ���
    for (i = 0; i < N->vexnum; ++i) {
        for (j = 0; j < N->vexnum; ++j) {
            N->arc[i][j].adj = INFINITY; //����Ȩֵ�����
            N->arc[i][j].info = NULL; // ���������ϢΪ��
        }
    }
    cout<<"������"<<N->arcnum<<"�����Ļ�β�ͻ�ͷֵ"<<endl;
    for (k = 0; k < N->arcnum; ++k) {
        cin>>v1>>v2>>w;//�������������Ȩֵ
        i = LocateVertex(*N, v1);//�Ӷ��������ϲ��Ҷ��㣬����������š�
        j = LocateVertex(*N, v2);//�Ӷ��������ϲ��Ҷ��㣬����������š�
        N->arc[i][j].adj =w;//������Ȩֵ
    }
    N->kind = DN;//ͼ��������������
}
/*
 * �ٶ��������в��Ҷ���v���ҵ���������������ţ����򷵻�-1
 * */
int LocateVertex(MGraph N,VertexType v){
    int i ;
    for(i = 0; i < N.vexnum; i++){
        /*
         *C �⺯�� int strcmp(const char *str1, const char *str2)
         * �� str1 ��ָ����ַ����� str2 ��ָ����ַ������бȽϡ�
         * �������ֵС�� 0�����ʾ str1 С�� str2��
         * �������ֵ���� 0�����ʾ str1 ���� str2��
         * �������ֵ���� 0�����ʾ str1 ���� str2��
         * */
        if(strcmp(N.vex[i],v) == 0){
            return i;
        }
    }
    return -1;
}
//������
void DestroyGraph(MGraph *N){
    int i, j ;
    for(i = 0; i < N->vexnum; i++){
        for (j = 0; j < N->vexnum; ++j) {
            if (N->arc[i][j].adj != INFINITY){//������ڻ�
                if(N->arc[i][j].info != NULL){//��������������Ϣ�����ͷŸ���Ϣ��ռ�ÿռ�
                    free(N->arc[i][j].info);
                    N->arc[i][j].info = NULL;
                }
                N->vexnum = 0;//��������ֵΪ��
                N->arcnum = 0;//������ֵΪ��
            }
        }
    }
}

//����ڽӾ���洢��ʾ��ͼ
void DisplayGraph(MGraph N){
    int i, j;
    cout<<"����������"<<N.vexnum<<"������"<<N.arcnum<<"����������������"<<endl;
    for (i = 0; i < N.vexnum; i++) {
        cout<<N.vex[i]<<" ";
    }
    cout<<endl<<"��������"<<endl<<"��� i = ";
    for(i = 0; i < N.vexnum; i++){
        cout<<i<<"    ";
    }
    cout<<endl;
    for (i = 0; i < N.vexnum; ++i) {
        cout<<i<<"    ";
        for (j = 0; j < N.arcnum; ++j) {
            cout<<N.arc[i][j].adj<<"    ";
        }
        cout<<endl;
    }

}
//
//int main(){
//    MGraph N;
//    cout<<"����һ��������"<<endl;
//    CreateGraph(&N);
//    cout<<"������Ķ���ͻ�"<<endl;
//    DisplayGraph(N);
//    cout<<"������"<<endl;
//    DestroyGraph(&N);
//};