#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct DATA{
    char c;
};
typedef struct ChainTree{
    DATA data;
    struct ChainTree* left = NULL;
    struct ChainTree* right = NULL;
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
 *此函数有欠缺
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

int main(){
    int choose,i = 0;

    ChainBinTree * root = BinTreeInit();
    ChainBinTree *p;
    DATA db ;
    db.c ='B';
    AddNode(root,db,'A',0);
    DATA dc ;
    dc.c = 'C';
    AddNode(root,dc,'A',1);
    DATA dd ;
    dd.c = 'D';
    AddNode(root,dd,'B',0);
    DATA de ;
    de.c = 'E';
    AddNode(root,de,'B',1);
    DATA df ;
    df.c = 'F';
    AddNode(root,df,'C',0);
    DATA dg ;
    dg.c = 'G';
    AddNode(root,dg,'C',1);
    DATA dh;
    dh.c = 'H';
    AddNode(root,dh,'D',0);
    DATA di ;
    di.c = 'I';
    AddNode(root,di,'D',1);
    DATA dj ;
    dj.c = 'J';
    AddNode(root,dj,'E',0);

    while (true){
        cin>>choose;
        switch (choose){
            case 0:{
                if (BinTreeFind(root,'H')->left == NULL){
                    cout<<"true";
                } else{
                    cout<<"false";
                }
                break;
            }
            case 1:{//先序遍历
                BinTree_DLR_Recursion(root);
                cout<<endl;
                BinTree_DLR_NotRecursion(root);
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"您好查找的是:"<<endl;
                char c = NULL;
                cin>>c;
                cout<<BinTreeFind(root,c)->data.c<<endl;
                break;
            }
            case 3:{//中序遍历
                BinTree_LDR_Recursion(root);
                cout<<endl;
                BinTree_LDR_NotRecursion(root);
                cout<<endl;
                break;
            }
            case 4:{//后序遍历
                BinTree_LRD_Recursion(root);
                cout<<endl;
    //            BinTree_LRD_NotRecursion(root);
    //            cout<<endl;
                break;
            }
            case 5:{
                cout<<"C的左节点是："<<BinTreeLeft(BinTreeFind(root,'C'))->data.c<<endl;
                cout<<"C的右节点是："<<BinTreeRight(BinTreeFind(root,'C'))->data.c<<endl;
                break;
            }
            case 6:{
                cout<<BinTreeIsEmpty(root);
                break;
            }
            case 7:{
                cout<<"二叉树深度是"<<BinTreeDepth(root)<<endl;
                break;
            }
            case 8:{
                BinTreeClear(root);
                cout<<"清空二叉树"<<endl;
                cout<<BinTreeIsEmpty(root);
                break;
            }
            case 9:{//层级遍历
                BinTree_Level(root);
                break;
            }
        }
    }
}