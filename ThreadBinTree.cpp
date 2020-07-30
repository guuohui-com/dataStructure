/*
 * ������������@���ڶ������Ľṹ
 * //�󲿷ִ����ChainBinTree�ϸ��ƹ���
 * //������������������(���ӽṹ���е����ԣ���һ��ö������)
 * //���Ӳ�������������������
 *
 * */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 *ǰ����������
 * */
typedef struct ChainTree;

/*
 * ȫ�ֱ���
 * */
ChainTree *Privous = NULL;//ǰ���ڵ�ָ��

typedef enum {
    Subtree,  //����
    Thread,   //����
}NodeFlag;

struct DATA{
    char c;
};

//�����������ṹ��
typedef struct ChainTree{
    DATA data;
    struct ChainTree* left = NULL;
    struct ChainTree* right = NULL;
    NodeFlag leftFlag;//���־
    NodeFlag rightFlag;//�ɱ�־
}ChainBinTree;


//��������ʼ��
ChainTree *BinTreeInit(){
    ChainBinTree *root;
    char data;
    if(root = (ChainTree *)malloc(sizeof(ChainBinTree))){
        cout<<"��������ڵ�����"<<endl;
        cin>>data;
        root ->data.c = data;
        root ->left = NULL;
        root ->right = NULL;
        return root;
    }
    return NULL;
}

//�������в�������
ChainBinTree *BinTreeFind(ChainBinTree *root, char data){
    ChainBinTree *p;
    if(root == NULL){
        return NULL;
    } else{
        if(root->data.c == data){
            cout<<"���ڵ�Ϊ"<<root->data.c<<endl;
            return root;
        } else{
            if((p = BinTreeFind(root->left,data))){
                return p;
            } else if((p = BinTreeFind(root -> right,data))){
                return p;
            } else
                return NULL;
        }
    }

}

//��data������root��father�ڵ��µ�n����־���ҽڵ㣩��
bool AddNode(ChainBinTree * root, DATA data, char father,int n){
    if(root == NULL){
        cout<<"����Ϊ����"<<endl;
        return false;
    }
    ChainBinTree * p = BinTreeFind(root, father);//�ҵ����ڵ��λ��
    if(!p){
        cout<<"δ�ҵ����ڵ�"<<endl;
        return false;
    }
    ChainBinTree* q = (ChainBinTree *)malloc(sizeof(struct ChainTree));
    q->data = data;
    q->left = NULL;
    q->right =NULL;
    if(n == 0){//�嵽������
        if(p ->left == NULL){
            p ->left = q;
            p->leftFlag = Subtree;
            cout<<p->data.c<<"�������� = "<<p->left->data.c<<endl;
//            free(q);
            return true;
        } else{
            cout<<"�ýڵ��������Ѵ���"<<endl;
            return false;
        }
    } else if(n == 1){//���뵽������
        if(p->right == NULL){
            p->right = q;
            p->rightFlag = Subtree;
            cout<<p->data.c<<"�������� = "<<p->right->data.c<<endl;
            return true;
        } else{
            cout<<"�ýڵ��������Ѵ���"<<endl;
            return false;
        }
    }
    return false;
}

//��ȡ������
ChainBinTree *BinTreeLeft(ChainBinTree *father){
    if(father->left != NULL){
        return father->left;
    } else{
        cout<<"������Ϊ��"<<endl;
        return NULL;
    }
}

//��ȡ������
ChainBinTree *BinTreeRight(ChainBinTree *father){
    if(father->right != NULL){
        return father->right;
    } else{
        cout<<"������Ϊ��"<<endl;
        return NULL;
    }
}

//���ܣ��ж϶������Ƿ�Ϊ��
int BinTreeIsEmpty(ChainBinTree *bt){
    if(bt)
        return 0;//���ǿ�
    else
        return 1;//��
}

//���ܣ�������������
int BinTreeDepth(ChainBinTree *bt){
    int depLeft,depRight;
    if(bt == NULL){
        return 0;
    } else{
        depLeft = BinTreeDepth(bt -> left);
        depRight = BinTreeDepth(bt->right);
        if(depLeft > depRight){
            return depLeft + 1;
        } else{
            return depRight + 1;
        }
    }
}

//���ܣ���ն�����
/*
 *�˺�����Ƿȱ������bug
 * */
void BinTreeClear(ChainBinTree *bt){
    if(bt != NULL && bt ->right ==NULL && bt ->left ==NULL){
        free(bt);
        return;
    }
    BinTreeClear(bt -> left);
    BinTreeClear(bt -> right);
    return ;
}

//���ܣ����ٶ�����
void BinTreeDestory(ChainBinTree *bt){
    if(bt){
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt=NULL;
    }
    return ;
}
//����������ݹ���ǵݹ飩
/*
 * �ݹ�ʵ��
 * */
void BinTree_DLR_Recursion(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    cout<<bt->data.c<<" ";
    BinTree_DLR_Recursion(bt->left);
    BinTree_DLR_Recursion(bt->right);
}
/*
 * �ǵݹ�ʵ��
 * */
void BinTree_DLR_NotRecursion(ChainBinTree *bt){
    ChainBinTree *p = bt;
    stack<ChainBinTree *> s;
    if (bt == NULL){
        return;
    }
    while(!s.empty() || p != NULL){
        while(p != NULL){
            cout<<p->data.c<<" ";
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }

    }
    cout<<endl;
}

/*
 * ��������������
 * */
void BinTreeThreading_DLR(ChainBinTree *bt){
    if (!bt){
        return;
    }
    if(bt->left ==NULL){
        bt -> left == Privous;
        bt -> leftFlag = Thread;
    }
    if(Privous != NULL && Privous -> right == NULL){
        Privous -> right = bt;
        Privous -> rightFlag = Thread;
    }
    Privous = bt;
    if(bt -> leftFlag == Subtree){
        BinTreeThreading_DLR(bt -> left);
    }
    if(bt -> rightFlag == Subtree){
        BinTreeThreading_DLR(bt -> right);
    }
}
/*
 * ��������������
 * */
void BinTreeThreading_DLR_PreOrder(ChainBinTree* Root)
{
    if (Root == NULL){
        return;
    }
    ChainBinTree* pCur = Root;
    while (pCur != NULL)
    {
        while (pCur->left != NULL && pCur->leftFlag == Subtree)//�ҵ�����ߵĽڵ�,����һֱΪLink
        {
            cout << pCur->data.c << ' ';
            pCur = pCur->left;
        }
        //����������ߵĵĽڵ㻹û�з���
        cout << pCur->data.c << ' ';

        //��������������������������
        if(pCur ->rightFlag == Thread){
            pCur = pCur -> right;
        } else{//û������������������
            pCur = pCur -> right;
        }

//        if (pCur->leftFlag == Thread)//�������� �Ϳ��ҽڵ�
//        {
//            pCur = pCur->right;
//        }
        while (pCur != NULL)//ѭ���ҽڵ�
        {
            if (pCur->left != NULL && pCur->leftFlag == Subtree)//������ڵ���� �� �����
            {
                break;
            }
            cout << pCur->data.c << ' ';
            pCur = pCur->right;
        }
    }
}

//����������ݹ���ǵݹ飩
/*
 * �ݹ�ʵ��
 * */
void BinTree_LDR_Recursion(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    BinTree_LDR_Recursion(bt->left);
    cout<<bt->data.c<<" ";
    BinTree_LDR_Recursion(bt->right);
}

/*
 * �ǵݹ�ʵ��
 * */
void BinTree_LDR_NotRecursion(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    stack<ChainBinTree *> s;
    ChainBinTree *p = bt;
    while(!s.empty() || p != NULL){
        while (p != NULL){
            s.push(p);
            p = p->left;
        }
        //���򵽴ˣ�˵������ڵ�����ջ��
        if (!s.empty()){
            p = s.top();
            cout<<p->data.c<<" ";
            s.pop();
            p = p->right;
        }
    }
    cout<<endl;
}

/*
 * ��������������
 * */
void BinTreeThreading_LDR(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    BinTreeThreading_LDR(bt->left);
    if(bt ->left == NULL){
        bt->left = Privous;
        bt->leftFlag = Thread;
    }
    if (Privous != NULL && Privous ->right == NULL){
        Privous -> right = bt;
        Privous -> rightFlag = Thread;
    }
    Privous = bt;
    BinTreeThreading_LDR(bt ->right);
}

/*
 * ������������������
 * */
void BinTreeThreading_LDR_inOrder(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    while(p != NULL){
        while(p -> leftFlag == Subtree){
            p = p->left;
        }
        cout<<p->data.c<<" ";
        /*
         *
         * �����ҵ�����ڵ㲢�ҷ���
         * */
        while(p != NULL && p ->rightFlag ==Thread){
            p = p->right;
            cout<<p->data.c<<" ";
        }
        /*
         *����Ϊ��������ʱ��ֱ�ӷ���������
         * */
        p = p->right;
        /*
         * �˴���ʾû��������������������
         * */
    }
    cout<<endl;
}

/*
 * ������������������ǰ���ڵ�
 * */
void findPre_LDR(ChainBinTree *bt){
    if (bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    //�����������
    if(p -> leftFlag == Thread && p -> left != NULL){
        cout<<p->left->data.c<<endl;
        return;
    }
    p = p->left;
    //û��������������ǰ�������������ĵ�һ���ҽڵ�
    while (p != NULL && p -> rightFlag == Subtree){
        p = p->right;
    }
    if(!p){
        cout<<"������"<<endl;
        return;
    }
    cout<<p->data.c<<endl;
    return;
}

/*
 * �����������������Һ�̽ڵ�
 * */
void findNext_LDR(ChainBinTree *bt){
    if (bt == NULL){
        return;
    }
    if(bt ->rightFlag == Thread){
        cout<< bt -> right->data.c<<endl;
        return;
    }
    ChainBinTree *p = bt -> right;
    //�����������������������ģ�����ڵ㣩
    while(p != NULL && p -> leftFlag == Subtree){
        p = p -> left;
    }
    if(!p){
        cout<<"������"<<endl;
        return;
    }
    cout<<p->data.c<<endl;
    return;
}

//����������ݹ���ǵݹ飩
/*
 * �ݹ�ʵ��
 * */
void BinTree_LRD_Recursion(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    BinTree_LRD_Recursion(bt->left);
    BinTree_LRD_Recursion(bt->right);
    cout<<bt->data.c<<" ";
}

/*
 * �ǵݹ�ʵ��
 * //**********************************************����������ʱ��Ҫ���жϣ����������ѭ������������δ�޸�
 * */
void BinTree_LRD_NotRecursion(ChainBinTree *bt) {
    if(bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    stack<ChainBinTree *> s;
    while (!s.empty() || p != NULL){
        while (p != NULL){
            s.push(p);
            p = p->left;
        }
        //��ڵ��Ѿ���ջ
        if (!s.empty()){
            p = s.top();
            if(p->right == NULL){
                cout<<p->data.c;
                s.pop();
            }
            p = p->right;
        }
    }
}

/*
 * ��������������
 * */
void BinTreeThreading_LRD(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    if(p -> leftFlag == Subtree){
        BinTreeThreading_LRD(p -> left);
    }
    if(p -> rightFlag == Subtree){
        BinTreeThreading_LRD(p->right);
    }
    //���˵�һ��Ҷ�ڵ�

    if (p -> left == NULL){
        p -> left = Privous;
        p -> leftFlag = Thread;
    }
    if(Privous != NULL && Privous ->right ==NULL){
        Privous -> right = p;
        Privous -> rightFlag = Thread;
    }
    Privous = p;

}

/*
 *���������������ı���
 * δ�������ƣ����ܳ�����Ҫ���parentָ��
 * */
void BinTreeThreading_LDR_postOrder(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    while(p){
        //��������ڵ�

        cout<<p->data.c<<" ";
        while (p -> rightFlag == Thread){
            p = p->right;
            cout<<p->data.c<<" ";
        }
        //�޺����

    }
}

//�㼶����
void BinTree_Level(ChainBinTree *bt) {
    if(bt == NULL){
        return;
    }
    queue<ChainBinTree *> q;
    ChainBinTree * p = bt;
    q.push(p);
    while(!q.empty()){
        p = q.front();
        cout<<p->data.c<<" ";
        q.pop();
        if(p->left != NULL){
            q.push(p->left);
        }
        if(p->right != NULL){
            q.push(p->right);
        }
    }
    cout<<endl;
}

//int main(){
//    int choose,i = 0;
//    ChainBinTree * root = BinTreeInit();
//    ChainBinTree *p;
//    DATA db ;
//    db.c ='B';
//    AddNode(root,db,'A',0);
//    DATA dc ;
//    dc.c = 'C';
//    AddNode(root,dc,'A',1);
//    DATA dd ;
//    dd.c = 'D';
//    AddNode(root,dd,'B',1);
//    DATA de ;
//    de.c = 'E';
//    AddNode(root,de,'C',1);
//    DATA df ;
//    df.c = 'F';
//    AddNode(root,df,'D',0);
//    DATA dg ;
//    dg.c = 'G';
//    AddNode(root,dg,'E',0);
//    DATA dh;
//    dh.c = 'H';
//    AddNode(root,dh,'E',1);
//
//    while (true){
//        cin>>choose;
//        switch (choose){
//            case 1:{//�������
//                BinTree_DLR_Recursion(root);
//                cout<<endl;
//                BinTree_DLR_NotRecursion(root);
//                cout<<endl;
//                break;
//            }
//            case 2:{
//                BinTreeThreading_DLR(root);
//                cout<<endl;
//                BinTreeThreading_DLR_PreOrder(root);
//                break;
//            }
//            case 3:{//�������������
//                BinTree_LDR_Recursion(root);
//                cout<<endl;
//                BinTree_LDR_NotRecursion(root);
//                break;
//            }
//            case 4:{
//                BinTreeThreading_LDR(root);
//                BinTreeThreading_LDR_inOrder(root);
//                ChainBinTree * p = root;
//                findPre_LDR(p);
//                findNext_LDR(p);
//                cout<<"end"<<endl;
//                break;
//            }
//        }
//    }
//}