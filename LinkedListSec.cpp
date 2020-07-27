#include<iostream>
using namespace std;

#define ERROR -1;
#define OK 0;

struct LNode{//节点的结构体
    int Data;
    struct LNode *next;
};

// 初始化链表
void New_LinkList(struct LNode* L, int n){
    int v;
    int i = 0;
    L->next = NULL; //头结点
    struct LNode *p;

    struct LNode *t;//指向尾节点
    t = (struct LNode *)malloc(sizeof(struct LNode));
    t->next = L;
    for(i = 0; i < n; i++){//插到了尾上
        p = (struct LNode *)malloc(sizeof(struct LNode));//首元结点
        cin>>v;
        p->Data = v;

        p->next = t->next->next;
        t->next->next = p;
        t->next = p;
    }
}

//获取链表长度
int GetListLength(struct LNode *L){

    LNode *p = L->next;
    int result = 0;
    int i = 0;
    while(p != NULL){
        result++;
        p = p->next;
    }

    return result;
}

// 获取链表中指定位置的数据元素{
int GetElem_LinkList(struct LNode* L,int i){
    int j = 0;
    struct LNode *p = L->next;

    if(i < 0 || i > GetListLength(L)){
        return ERROR;
    }
    for (j = 1; j < i; j++) {
        p = p->next;
    }
    return p->Data;
}

// 在链表中指定位置插入数据
int InsertElem_LinkList(struct LNode* L,int i){
    struct LNode* p = L->next;
    int v = 0;
    if(i < 0){
        return ERROR;
    }

    if(i > GetListLength(L)){//插在尾部
        for (int j = 1; j < GetListLength(L)-1; j++) {
            p = p->next;
        }
        cin>>v;
        p->Data = v;
        return OK;
    }

    for(int j = 1; j < i-1; j++){
        p = p->next;//指向插入节点的前一个位置
    }

    struct LNode *s;
    cout<<"插入节点值是"<<endl;
    cin>>v;
    cout<<"插入节点"<<endl;
    s = (LNode *)malloc(sizeof(LNode));
    s->Data = v;
    s->next = p->next;
    p->next= s;
    return OK;
}

// 删除链表中制定数据元素
int Delete_LinkList(struct LNode* L, int i){
    struct LNode *p = L->next;
    struct LNode *s;
    if(i < 0 || i > GetListLength(L)){
        return  ERROR;
    }

    for(int j = 1; j < i-1; j++){
        p = p->next;
    }
    //p->next 是需要删除的节点
    s = p->next;
    p->next = p->next->next;
    free(s); //释放内存
    return OK;
}

// 显示链表所有节点的数据域
int Print_LinkList(struct LNode* L){
    struct LNode *p = L->next;
    if(p == NULL){
        cout<<"链表是空"<<endl;
        return ERROR
    }
    while(p != NULL){
        cout<<p->Data<<"  ";
        p = p->next;
    }
    cout<<endl;
    return OK;
}

//int main(){
//    struct LNode list;
//    cout<<"请输入链表数据"<<endl;
//    New_LinkList(&list, 5);
//    Print_LinkList(&list);
//    cout<<"链表长度是"<<GetListLength(&list)<<endl;
//    //插入元素
//    int index;
//    int choose;
//    while(true){
//        cin>>choose;
//        switch (choose){
//            case 1:{//插入节点
//                cout<<"输入插入位置"<<endl;
//                cin>>index;
//                InsertElem_LinkList(&list,index);
//                Print_LinkList(&list);
//                break;
//            }
//            case 2:{//删除节点
//                cout<<"输入删除节点位置"<<endl;
//                cin>>index;
//                Delete_LinkList(&list,index);
//                Print_LinkList(&list);
//                break;
//            }
//            case 3:{
//                cin>>index;
//                cout<<"链表第"<<index<<"个元素是"<<GetElem_LinkList(&list,index)<<endl;
//                break;
//            }
//            case 4:{
//                cout<<"链表长度是"<<GetListLength(&list);
//                break;
//            }
//            case -1:{
//                exit(0);
//                break;
//            }
//        }
//
//    }
//    return 0;
//}
