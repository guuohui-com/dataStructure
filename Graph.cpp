/*
 * Created by df on 2020/8/4.
 *
 * 图的描述及操作
 * 邻接矩阵描述
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define INFINITY 99 //认为是无穷大的值
#define MaxSize 50 //顶点个数最大值

typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
/*
 * DG,有向图
 * DN,有向网
 * UG,无向图
 * UN,无向网
 * */
typedef enum {DG,DN,UG,UN}GraphKind;

/*
 * 顶点
 * */
typedef struct {
    int adj; //权值

    InfoPtr *info;//与狐或者边相关信息
}ArcNode,AdjMatrix[MaxSize][MaxSize];

/*
 * 图
 * */
typedef struct {
    VertexType vex[MaxSize]; //用预存定点的一维数组
    AdjMatrix arc;// 用于存弧或边的二维数组
    int vexnum,arcnum;//顶点数和边（弧）数
    GraphKind kind;
}MGraph;

int LocateVertex(MGraph N,VertexType v);
//销毁图
void DestroyGraph(MGraph *N);
//输出邻接矩阵存储图示
void DisplayGraph(MGraph N);

/*
 *用邻接矩阵表示有向网
 * */
void CreateGraph(MGraph *N){
    int vNum = 0,i =0 ,j = 0, k = 0, w = 0;
    VertexType v1,v2;
    cout<<"请输入有向网的顶点数和弧数"<<endl;
    cin>>N->vexnum>>N->arcnum;
    cout<<"请输入"<<N->vexnum<<"个顶点的值"<<endl;
    //输入的顶点值
    for (i = 0; i < N->vexnum; ++i) {
        cin>>N->vex[i];
    }
    //初始化邻接矩阵
    for (i = 0; i < N->vexnum; ++i) {
        for (j = 0; j < N->vexnum; ++j) {
            N->arc[i][j].adj = INFINITY; //弧的权值无穷大
            N->arc[i][j].info = NULL; // 弧的相关信息为空
        }
    }
    cout<<"请输入"<<N->arcnum<<"条弧的弧尾和弧头值"<<endl;
    for (k = 0; k < N->arcnum; ++k) {
        cin>>v1>>v2>>w;//输入两个顶点和权值
        i = LocateVertex(*N, v1);//从顶点向量上查找顶点，返回所在序号。
        j = LocateVertex(*N, v2);//从顶点向量上查找顶点，返回所在序号。
        N->arc[i][j].adj =w;//给弧赋权值
    }
    N->kind = DN;//图的类型是有向网
}
/*
 * 再顶点向量中查找顶点v，找到返回在向量的序号，否则返回-1
 * */
int LocateVertex(MGraph N,VertexType v){
    int i ;
    for(i = 0; i < N.vexnum; i++){
        /*
         *C 库函数 int strcmp(const char *str1, const char *str2)
         * 把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
         * 如果返回值小于 0，则表示 str1 小于 str2。
         * 如果返回值大于 0，则表示 str1 大于 str2。
         * 如果返回值等于 0，则表示 str1 等于 str2。
         * */
        if(strcmp(N.vex[i],v) == 0){
            return i;
        }
    }
    return -1;
}
//销毁网
void DestroyGraph(MGraph *N){
    int i, j ;
    for(i = 0; i < N->vexnum; i++){
        for (j = 0; j < N->vexnum; ++j) {
            if (N->arc[i][j].adj != INFINITY){//如果存在弧
                if(N->arc[i][j].info != NULL){//如果弧存在相关信息，则释放该信息所占用空间
                    free(N->arc[i][j].info);
                    N->arc[i][j].info = NULL;
                }
                N->vexnum = 0;//将顶点数值为零
                N->arcnum = 0;//将弧数值为零
            }
        }
    }
}

//输出邻接矩阵存储表示的图
void DisplayGraph(MGraph N){
    int i, j;
    cout<<"有向网具有"<<N.vexnum<<"个顶点"<<N.arcnum<<"条弧，顶点依次是"<<endl;
    for (i = 0; i < N.vexnum; i++) {
        cout<<N.vex[i]<<" ";
    }
    cout<<endl<<"有向网是"<<endl<<"序号 i = ";
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
//    cout<<"创建一个有向网"<<endl;
//    CreateGraph(&N);
//    cout<<"输出网的顶点和弧"<<endl;
//    DisplayGraph(N);
//    cout<<"销毁网"<<endl;
//    DestroyGraph(&N);
//};