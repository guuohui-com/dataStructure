//
// Created by df on 2020/8/7.
//图的邻接表表示（无向图）
//
#include <iostream>
using namespace std;

#define Maxsize 50 //顶点个数最大值

typedef enum {DG,DN,UG,UN,} GraphKind;//图的类型：有向图，有向网，无向图，无向网

typedef struct VNode;

typedef struct{

}Data;

typedef struct ArcNode{//边节点的类型定义
    int vnode; //弧指向的顶点的位置，因为所有顶点使用数组存，所以只要记录其下标即可
    char *Info ; //弧相关信息
    ArcNode * nextarc ; //弧邻接边节点
};

typedef struct VNode{//头结点的类型定义
    char data;//用于存储顶点
    ArcNode * firstNode; //头结点指针域，指向第一个边节点
}VNode;

typedef VNode AdjList[Maxsize];//存顶点的数组

typedef struct{ //图的类型定义
    AdjList adjList; //顶点集合
    GraphKind graphKind;//图的类型
    int vexnum,arcnum; //顶点数，边数
}AdjGraph;

//返回图中顶点所在位置
int LocateVertex(AdjGraph adjGraph, char v);

//采用邻接表结构创建无向图
void CreateGraph(AdjGraph *adjGraph);

//销毁图
void DestoryGraph(AdjGraph *adjGraph);

//展示图
void DisPlayGraph(AdjGraph adjGraph);

void DFSTraverse(AdjGraph *adjGraph);

void DFS(AdjGraph *adjGraph, int v);

/*
 * 找w的下一个邻接点的位置
 * */
int NextAdjVertex(AdjGraph *adjGraph,char v, char w);

/*
 * 找v的第一个邻接点的位置
 * */
int FirstAdjVertex(AdjGraph *adjGraph,char v);


void CreateGraph(AdjGraph *adjGraph){

    cout<<"输入图的顶点个数"<<endl;
    cin>>adjGraph->vexnum;
    cout<<"输入图的边数"<<endl;
    cin>>adjGraph->arcnum;
    cout<<"输入顶点值"<<endl;

    int i = 0,j=0,z=0;

    char from,to;
    ArcNode *node;

    while (i < adjGraph->vexnum){
        cin>>adjGraph->adjList[i].data;
        //将相关联的顶点置为空
        adjGraph->adjList[i].firstNode=NULL;

        i++;
    }


    i = 0;
    //建立边表
    while (z < adjGraph->arcnum){

        cout<<"输入弧尾和弧头"<<endl;
        cin>>from>>to;

        i = LocateVertex(*adjGraph,from);
        j = LocateVertex(*adjGraph,to);

        /*
         * 以j为弧尾，
         * i为弧头，插入边表
         * */

        //分配内存空间
        node = (ArcNode*)malloc(sizeof(ArcNode));
        //弧的指向是j
        node->vnode = j;
        //弧的信息值为空
        node->Info = NULL;
        /*
         * 边表，在此处采用的是头插法
         * */
        //将头结点表指向的节点赋给新的边节点
        node->nextarc = adjGraph->adjList[i].firstNode;
        //将新的节点赋值给头结点的指针域，实现头插法
        adjGraph->adjList[i].firstNode = node;
        /*
         * 无向图所以，再次以i为弧尾，j为弧头插入边表
         * 若为有向图，则可以无此操作
         * */
        node = (ArcNode *) malloc(sizeof(ArcNode));
        node->vnode = i;
        node->nextarc = adjGraph->adjList[j].firstNode;
        adjGraph->adjList[j].firstNode = node;
        z ++;
    }

    //图为无向图
    adjGraph->graphKind = UG;

    //图为有向图
//    adjGraph->graphKind = DG;

    /*
     *若是有向图，则在插入边节点时，无需双向插入
     * 若是有权图，则在边表节点的info中写入权值即可
     * */
}

int LocateVertex(AdjGraph adjGraph, char v){
    for (int i = 0; i < adjGraph.vexnum; ++i) {
        if (v == adjGraph.adjList[i].data){
            return i;
        }
    }
    return -1;
}

//销毁无向图
void DestoryGraph(AdjGraph *adjGraph){
    int i=0;
    ArcNode *p, *q;
    for(i;i<adjGraph->vexnum;i++){
        p = adjGraph->adjList[i].firstNode;
        if(p!=NULL){//如果边表节点不为空
            //临时存储
            q = p->nextarc;
            free(p);
            p=q;
        }
    }
    //将顶点数值零
    adjGraph->vexnum=0;
    //将边数值为零
    adjGraph->arcnum=0;
}

//展示图
void DisPlayGraph(AdjGraph adjGraph){
    int i=0;
    ArcNode *node;

    //先输出图的所有顶点
    cout<<"输出图的所有顶点"<<endl;
    for (i = 0; i < adjGraph.vexnum; ++i) {
        cout<<adjGraph.adjList[i].data<<" ";
    }
    cout<<endl;

    //输出图的所有边
    cout<<"输出图的所有边"<<endl;
    for (i = 0; i < adjGraph.vexnum; i++) {
        node = adjGraph.adjList[i].firstNode;
        while(node != NULL){
            cout<<adjGraph.adjList[i].data<<"-"<<adjGraph.adjList[node->vnode].data<<" ";
            node = node->nextarc;
        }
        cout<<endl;
    }
}


/*
 * 节点访问标志数组
 * */
int visited[9];

/*
 * 图的深度优先搜索算法（DFS）
 * */
void DFSTraverse(AdjGraph *adjGraph){
    int v;
    //初始化节点访问标志数组
    for (v = 0; v < adjGraph->vexnum; ++v) {
        visited[v] = 0; //0 是未被访问
    }
    //开始访问
    for (v = 0; v < adjGraph->vexnum; ++v) {
        if (visited[v] == 0){
            DFS(adjGraph,v);
        }
        cout<<endl;
    }
}

/*
 * 从顶点V触发，进行深度优先搜索
 * */
void DFS(AdjGraph *adjGraph, int v){
    int w = 0;

    //设置标志位1，表示其已经被访问过
    visited[v] = 1;
    //访问第v个节点
    cout<<adjGraph->adjList[v].data<<" ";

    for (w = FirstAdjVertex(adjGraph,adjGraph->adjList[v].data); w >= 0 ;
    w = NextAdjVertex(adjGraph,adjGraph->adjList[v].data,adjGraph->adjList[w].data) ) {

        if(visited[w] == 0){
            DFS(adjGraph,w);
        }
    }

}

/*
 * 找v的第一个邻接点的位置,弱不存在，则返回-1
 * */
int FirstAdjVertex(AdjGraph *adjGraph,char v){

   ArcNode *p;
   int v1;

   //v1 是v 在图中所在位置的序号
   v1 = LocateVertex(*adjGraph,v);

   if(v1 < 0){
       return  -1;
   }

   p = adjGraph->adjList[v1].firstNode;

   if (p != NULL){
       return p ->vnode;
   } else{
       return -1;
   }
}

/*
 * 找v的相对于w的下一个邻接点的位置
 * */
int NextAdjVertex(AdjGraph *adjGraph,char v, char w){
    //找到头结点
    int head = LocateVertex(*adjGraph,v);
    int v2 = LocateVertex(*adjGraph,w);

    //指向头结点的第一个邻接顶点
    ArcNode *arcNode = adjGraph->adjList[head].firstNode;
    ArcNode *p ;

    while (arcNode != NULL){
        if (v2 != arcNode->vnode){
            arcNode = arcNode ->nextarc;
        } else{
            break;
        }
    }
    p = arcNode;
    if(p==NULL || p ->nextarc == NULL ){
        return -1;
    }else{
        return p->nextarc->vnode;
    }
    return -1;
}

int main(){
    cout<<"创建有向图"<<endl;
    AdjGraph  graph;
    CreateGraph(&graph);

    cout<<"展示有向图"<<endl;
    DisPlayGraph(graph);

    cout<<"============="<<FirstAdjVertex(&graph,'c')<<endl;

    cout<<"深度优先搜索"<<endl;
    DFSTraverse(&graph);

    cout<<"销毁有向图"<<endl;
    DestoryGraph(&graph);
}