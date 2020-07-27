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
 *�˺�����Ƿȱ
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
            case 1:{//�������
                BinTree_DLR_Recursion(root);
                cout<<endl;
                BinTree_DLR_NotRecursion(root);
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"���ò��ҵ���:"<<endl;
                char c = NULL;
                cin>>c;
                cout<<BinTreeFind(root,c)->data.c<<endl;
                break;
            }
            case 3:{//�������
                BinTree_LDR_Recursion(root);
                cout<<endl;
                BinTree_LDR_NotRecursion(root);
                cout<<endl;
                break;
            }
            case 4:{//�������
                BinTree_LRD_Recursion(root);
                cout<<endl;
    //            BinTree_LRD_NotRecursion(root);
    //            cout<<endl;
                break;
            }
            case 5:{
                cout<<"C����ڵ��ǣ�"<<BinTreeLeft(BinTreeFind(root,'C'))->data.c<<endl;
                cout<<"C���ҽڵ��ǣ�"<<BinTreeRight(BinTreeFind(root,'C'))->data.c<<endl;
                break;
            }
            case 6:{
                cout<<BinTreeIsEmpty(root);
                break;
            }
            case 7:{
                cout<<"�����������"<<BinTreeDepth(root)<<endl;
                break;
            }
            case 8:{
                BinTreeClear(root);
                cout<<"��ն�����"<<endl;
                cout<<BinTreeIsEmpty(root);
                break;
            }
            case 9:{//�㼶����
                BinTree_Level(root);
                break;
            }
        }
    }
}