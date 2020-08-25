//
// Created by df on 2020/8/7.
//ͼ���ڽӱ��ʾ������ͼ��
//
#include <iostream>
using namespace std;

#define Maxsize 50 //����������ֵ

typedef enum {DG,DN,UG,UN,} GraphKind;//ͼ�����ͣ�����ͼ��������������ͼ��������

typedef struct VNode;

typedef struct{

}Data;

typedef struct ArcNode{//�߽ڵ�����Ͷ���
    int vnode; //��ָ��Ķ����λ�ã���Ϊ���ж���ʹ������棬����ֻҪ��¼���±꼴��
    char *Info ; //�������Ϣ
    ArcNode * nextarc ; //���ڽӱ߽ڵ�
};

typedef struct VNode{//ͷ�������Ͷ���
    char data;//���ڴ洢����
    ArcNode * firstNode; //ͷ���ָ����ָ���һ���߽ڵ�
}VNode;

typedef VNode AdjList[Maxsize];//�涥�������

typedef struct{ //ͼ�����Ͷ���
    AdjList adjList; //���㼯��
    GraphKind graphKind;//ͼ������
    int vexnum,arcnum; //������������
}AdjGraph;

//����ͼ�ж�������λ��
int LocateVertex(AdjGraph adjGraph, char v);

//�����ڽӱ�ṹ��������ͼ
void CreateGraph(AdjGraph *adjGraph);

//����ͼ
void DestoryGraph(AdjGraph *adjGraph);

//չʾͼ
void DisPlayGraph(AdjGraph adjGraph);

void DFSTraverse(AdjGraph *adjGraph);

void DFS(AdjGraph *adjGraph, int v);

/*
 * ��w����һ���ڽӵ��λ��
 * */
int NextAdjVertex(AdjGraph *adjGraph,char v, char w);

/*
 * ��v�ĵ�һ���ڽӵ��λ��
 * */
int FirstAdjVertex(AdjGraph *adjGraph,char v);


void CreateGraph(AdjGraph *adjGraph){

    cout<<"����ͼ�Ķ������"<<endl;
    cin>>adjGraph->vexnum;
    cout<<"����ͼ�ı���"<<endl;
    cin>>adjGraph->arcnum;
    cout<<"���붥��ֵ"<<endl;

    int i = 0,j=0,z=0;

    char from,to;
    ArcNode *node;

    while (i < adjGraph->vexnum){
        cin>>adjGraph->adjList[i].data;
        //��������Ķ�����Ϊ��
        adjGraph->adjList[i].firstNode=NULL;

        i++;
    }


    i = 0;
    //�����߱�
    while (z < adjGraph->arcnum){

        cout<<"���뻡β�ͻ�ͷ"<<endl;
        cin>>from>>to;

        i = LocateVertex(*adjGraph,from);
        j = LocateVertex(*adjGraph,to);

        /*
         * ��jΪ��β��
         * iΪ��ͷ������߱�
         * */

        //�����ڴ�ռ�
        node = (ArcNode*)malloc(sizeof(ArcNode));
        //����ָ����j
        node->vnode = j;
        //������ϢֵΪ��
        node->Info = NULL;
        /*
         * �߱��ڴ˴����õ���ͷ�巨
         * */
        //��ͷ����ָ��Ľڵ㸳���µı߽ڵ�
        node->nextarc = adjGraph->adjList[i].firstNode;
        //���µĽڵ㸳ֵ��ͷ����ָ����ʵ��ͷ�巨
        adjGraph->adjList[i].firstNode = node;
        /*
         * ����ͼ���ԣ��ٴ���iΪ��β��jΪ��ͷ����߱�
         * ��Ϊ����ͼ��������޴˲���
         * */
        node = (ArcNode *) malloc(sizeof(ArcNode));
        node->vnode = i;
        node->nextarc = adjGraph->adjList[j].firstNode;
        adjGraph->adjList[j].firstNode = node;
        z ++;
    }

    //ͼΪ����ͼ
    adjGraph->graphKind = UG;

    //ͼΪ����ͼ
//    adjGraph->graphKind = DG;

    /*
     *��������ͼ�����ڲ���߽ڵ�ʱ������˫�����
     * ������Ȩͼ�����ڱ߱�ڵ��info��д��Ȩֵ����
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

//��������ͼ
void DestoryGraph(AdjGraph *adjGraph){
    int i=0;
    ArcNode *p, *q;
    for(i;i<adjGraph->vexnum;i++){
        p = adjGraph->adjList[i].firstNode;
        if(p!=NULL){//����߱�ڵ㲻Ϊ��
            //��ʱ�洢
            q = p->nextarc;
            free(p);
            p=q;
        }
    }
    //��������ֵ��
    adjGraph->vexnum=0;
    //������ֵΪ��
    adjGraph->arcnum=0;
}

//չʾͼ
void DisPlayGraph(AdjGraph adjGraph){
    int i=0;
    ArcNode *node;

    //�����ͼ�����ж���
    cout<<"���ͼ�����ж���"<<endl;
    for (i = 0; i < adjGraph.vexnum; ++i) {
        cout<<adjGraph.adjList[i].data<<" ";
    }
    cout<<endl;

    //���ͼ�����б�
    cout<<"���ͼ�����б�"<<endl;
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
 * �ڵ���ʱ�־����
 * */
int visited[9];

/*
 * ͼ��������������㷨��DFS��
 * */
void DFSTraverse(AdjGraph *adjGraph){
    int v;
    //��ʼ���ڵ���ʱ�־����
    for (v = 0; v < adjGraph->vexnum; ++v) {
        visited[v] = 0; //0 ��δ������
    }
    //��ʼ����
    for (v = 0; v < adjGraph->vexnum; ++v) {
        if (visited[v] == 0){
            DFS(adjGraph,v);
        }
        cout<<endl;
    }
}

/*
 * �Ӷ���V���������������������
 * */
void DFS(AdjGraph *adjGraph, int v){
    int w = 0;

    //���ñ�־λ1����ʾ���Ѿ������ʹ�
    visited[v] = 1;
    //���ʵ�v���ڵ�
    cout<<adjGraph->adjList[v].data<<" ";

    for (w = FirstAdjVertex(adjGraph,adjGraph->adjList[v].data); w >= 0 ;
    w = NextAdjVertex(adjGraph,adjGraph->adjList[v].data,adjGraph->adjList[w].data) ) {

        if(visited[w] == 0){
            DFS(adjGraph,w);
        }
    }

}

/*
 * ��v�ĵ�һ���ڽӵ��λ��,�������ڣ��򷵻�-1
 * */
int FirstAdjVertex(AdjGraph *adjGraph,char v){

   ArcNode *p;
   int v1;

   //v1 ��v ��ͼ������λ�õ����
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
 * ��v�������w����һ���ڽӵ��λ��
 * */
int NextAdjVertex(AdjGraph *adjGraph,char v, char w){
    //�ҵ�ͷ���
    int head = LocateVertex(*adjGraph,v);
    int v2 = LocateVertex(*adjGraph,w);

    //ָ��ͷ���ĵ�һ���ڽӶ���
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
    cout<<"��������ͼ"<<endl;
    AdjGraph  graph;
    CreateGraph(&graph);

    cout<<"չʾ����ͼ"<<endl;
    DisPlayGraph(graph);

    cout<<"============="<<FirstAdjVertex(&graph,'c')<<endl;

    cout<<"�����������"<<endl;
    DFSTraverse(&graph);

    cout<<"��������ͼ"<<endl;
    DestoryGraph(&graph);
}