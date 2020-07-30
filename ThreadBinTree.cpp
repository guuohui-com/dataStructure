/*
 * 线索二叉树：@基于二叉树的结构
 * //大部分代码从ChainBinTree上复制过来
 * //增加中序线索化函数(增加结构体中的属性，和一个枚举类型)
 * //增加测试中序化线索函数代码
 *
 * */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 *前项引用声明
 * */
typedef struct ChainTree;

/*
 * 全局变量
 * */
ChainTree *Privous = NULL;//前驱节点指针

typedef enum {
    Subtree,  //子树
    Thread,   //线索
}NodeFlag;

struct DATA{
    char c;
};

//线索二叉树结构体
typedef struct ChainTree{
    DATA data;
    struct ChainTree* left = NULL;
    struct ChainTree* right = NULL;
    NodeFlag leftFlag;//左标志
    NodeFlag rightFlag;//由标志
}ChainBinTree;


//二叉树初始化
ChainTree *BinTreeInit(){
    ChainBinTree *root;
    char data;
    if(root = (ChainTree *)malloc(sizeof(ChainBinTree))){
        cout<<"请输入根节点数据"<<endl;
        cin>>data;
        root ->data.c = data;
        root ->left = NULL;
        root ->right = NULL;
        return root;
    }
    return NULL;
}

//二叉树中查找数据
ChainBinTree *BinTreeFind(ChainBinTree *root, char data){
    ChainBinTree *p;
    if(root == NULL){
        return NULL;
    } else{
        if(root->data.c == data){
            cout<<"父节点为"<<root->data.c<<endl;
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

//将data插入树root的father节点下的n（标志左右节点）。
bool AddNode(ChainBinTree * root, DATA data, char father,int n){
    if(root == NULL){
        cout<<"此树为空树"<<endl;
        return false;
    }
    ChainBinTree * p = BinTreeFind(root, father);//找到父节点的位置
    if(!p){
        cout<<"未找到父节点"<<endl;
        return false;
    }
    ChainBinTree* q = (ChainBinTree *)malloc(sizeof(struct ChainTree));
    q->data = data;
    q->left = NULL;
    q->right =NULL;
    if(n == 0){//插到左子树
        if(p ->left == NULL){
            p ->left = q;
            p->leftFlag = Subtree;
            cout<<p->data.c<<"的左子树 = "<<p->left->data.c<<endl;
//            free(q);
            return true;
        } else{
            cout<<"该节点左子树已存在"<<endl;
            return false;
        }
    } else if(n == 1){//插入到右子树
        if(p->right == NULL){
            p->right = q;
            p->rightFlag = Subtree;
            cout<<p->data.c<<"的右子树 = "<<p->right->data.c<<endl;
            return true;
        } else{
            cout<<"该节点右子树已存在"<<endl;
            return false;
        }
    }
    return false;
}

//获取左子树
ChainBinTree *BinTreeLeft(ChainBinTree *father){
    if(father->left != NULL){
        return father->left;
    } else{
        cout<<"左子树为空"<<endl;
        return NULL;
    }
}

//获取右子树
ChainBinTree *BinTreeRight(ChainBinTree *father){
    if(father->right != NULL){
        return father->right;
    } else{
        cout<<"右子树为空"<<endl;
        return NULL;
    }
}

//功能：判断二叉树是否为空
int BinTreeIsEmpty(ChainBinTree *bt){
    if(bt)
        return 0;//不是空
    else
        return 1;//空
}

//功能：求二叉树的深度
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

//功能：清空二叉树
/*
 *此函数有欠缺，存在bug
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

//功能：销毁二叉树
void BinTreeDestory(ChainBinTree *bt){
    if(bt){
        BinTreeClear(bt->left);
        BinTreeClear(bt->right);
        free(bt);
        bt=NULL;
    }
    return ;
}
//先序遍历（递归与非递归）
/*
 * 递归实现
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
 * 非递归实现
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
 * 先序线索化函数
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
 * 先序线索树遍历
 * */
void BinTreeThreading_DLR_PreOrder(ChainBinTree* Root)
{
    if (Root == NULL){
        return;
    }
    ChainBinTree* pCur = Root;
    while (pCur != NULL)
    {
        while (pCur->left != NULL && pCur->leftFlag == Subtree)//找到最左边的节点,左标记一直为Link
        {
            cout << pCur->data.c << ' ';
            pCur = pCur->left;
        }
        //到这来，左边的的节点还没有访问
        cout << pCur->data.c << ' ';

        //如果有右线索，则访问其右线索
        if(pCur ->rightFlag == Thread){
            pCur = pCur -> right;
        } else{//没有右线索，有右子树
            pCur = pCur -> right;
        }

//        if (pCur->leftFlag == Thread)//遇到线索 就看右节点
//        {
//            pCur = pCur->right;
//        }
        while (pCur != NULL)//循环右节点
        {
            if (pCur->left != NULL && pCur->leftFlag == Subtree)//遇到左节点存在 ， 则访问
            {
                break;
            }
            cout << pCur->data.c << ' ';
            pCur = pCur->right;
        }
    }
}

//中序遍历（递归与非递归）
/*
 * 递归实现
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
 * 非递归实现
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
        //程序到此，说明，左节点已入栈，
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
 * 中序线索化函数
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
 * 中序线索化函数遍历
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
         * 以上找到最左节点并且访问
         * */
        while(p != NULL && p ->rightFlag ==Thread){
            p = p->right;
            cout<<p->data.c<<" ";
        }
        /*
         *以上为有右线索时，直接访问右线索
         * */
        p = p->right;
        /*
         * 此处表示没有右线索，则有有子树
         * */
    }
    cout<<endl;
}

/*
 * 中序线索化二叉树找前驱节点
 * */
void findPre_LDR(ChainBinTree *bt){
    if (bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    //如果有左线索
    if(p -> leftFlag == Thread && p -> left != NULL){
        cout<<p->left->data.c<<endl;
        return;
    }
    p = p->left;
    //没有左线索，则其前驱在其左子树的第一个右节点
    while (p != NULL && p -> rightFlag == Subtree){
        p = p->right;
    }
    if(!p){
        cout<<"不存在"<<endl;
        return;
    }
    cout<<p->data.c<<endl;
    return;
}

/*
 * 中序线索化二叉树找后继节点
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
    //无右线索，则后继在右子树的（最左节点）
    while(p != NULL && p -> leftFlag == Subtree){
        p = p -> left;
    }
    if(!p){
        cout<<"不存在"<<endl;
        return;
    }
    cout<<p->data.c<<endl;
    return;
}

//后序遍历（递归与非递归）
/*
 * 递归实现
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
 * 非递归实现
 * //**********************************************进入右子树时需要加判断，否则出现死循环，本程序尚未修改
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
        //左节点已经入栈
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
 * 后序线索化函数
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
    //到了第一个叶节点

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
 *后序线索化函数的遍历
 * 未经过完善，可能出现需要添加parent指针
 * */
void BinTreeThreading_LDR_postOrder(ChainBinTree *bt){
    if(bt == NULL){
        return;
    }
    ChainBinTree *p = bt;
    while(p){
        //先找最左节点

        cout<<p->data.c<<" ";
        while (p -> rightFlag == Thread){
            p = p->right;
            cout<<p->data.c<<" ";
        }
        //无后继了

    }
}

//层级遍历
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
//            case 1:{//先序遍历
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
//            case 3:{//二叉树中序遍历
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