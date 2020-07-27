#include<iostream>
using namespace std;

#define ERROR -1;
#define OK 0;

struct LNode{//�ڵ�Ľṹ��
    int Data;
    struct LNode *next;
};

// ��ʼ������
void New_LinkList(struct LNode* L, int n){
    int v;
    int i = 0;
    L->next = NULL; //ͷ���
    struct LNode *p;

    struct LNode *t;//ָ��β�ڵ�
    t = (struct LNode *)malloc(sizeof(struct LNode));
    t->next = L;
    for(i = 0; i < n; i++){//�嵽��β��
        p = (struct LNode *)malloc(sizeof(struct LNode));//��Ԫ���
        cin>>v;
        p->Data = v;

        p->next = t->next->next;
        t->next->next = p;
        t->next = p;
    }
}

//��ȡ������
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

// ��ȡ������ָ��λ�õ�����Ԫ��{
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

// ��������ָ��λ�ò�������
int InsertElem_LinkList(struct LNode* L,int i){
    struct LNode* p = L->next;
    int v = 0;
    if(i < 0){
        return ERROR;
    }

    if(i > GetListLength(L)){//����β��
        for (int j = 1; j < GetListLength(L)-1; j++) {
            p = p->next;
        }
        cin>>v;
        p->Data = v;
        return OK;
    }

    for(int j = 1; j < i-1; j++){
        p = p->next;//ָ�����ڵ��ǰһ��λ��
    }

    struct LNode *s;
    cout<<"����ڵ�ֵ��"<<endl;
    cin>>v;
    cout<<"����ڵ�"<<endl;
    s = (LNode *)malloc(sizeof(LNode));
    s->Data = v;
    s->next = p->next;
    p->next= s;
    return OK;
}

// ɾ���������ƶ�����Ԫ��
int Delete_LinkList(struct LNode* L, int i){
    struct LNode *p = L->next;
    struct LNode *s;
    if(i < 0 || i > GetListLength(L)){
        return  ERROR;
    }

    for(int j = 1; j < i-1; j++){
        p = p->next;
    }
    //p->next ����Ҫɾ���Ľڵ�
    s = p->next;
    p->next = p->next->next;
    free(s); //�ͷ��ڴ�
    return OK;
}

// ��ʾ�������нڵ��������
int Print_LinkList(struct LNode* L){
    struct LNode *p = L->next;
    if(p == NULL){
        cout<<"�����ǿ�"<<endl;
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
//    cout<<"��������������"<<endl;
//    New_LinkList(&list, 5);
//    Print_LinkList(&list);
//    cout<<"��������"<<GetListLength(&list)<<endl;
//    //����Ԫ��
//    int index;
//    int choose;
//    while(true){
//        cin>>choose;
//        switch (choose){
//            case 1:{//����ڵ�
//                cout<<"�������λ��"<<endl;
//                cin>>index;
//                InsertElem_LinkList(&list,index);
//                Print_LinkList(&list);
//                break;
//            }
//            case 2:{//ɾ���ڵ�
//                cout<<"����ɾ���ڵ�λ��"<<endl;
//                cin>>index;
//                Delete_LinkList(&list,index);
//                Print_LinkList(&list);
//                break;
//            }
//            case 3:{
//                cin>>index;
//                cout<<"�����"<<index<<"��Ԫ����"<<GetElem_LinkList(&list,index)<<endl;
//                break;
//            }
//            case 4:{
//                cout<<"��������"<<GetListLength(&list);
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
