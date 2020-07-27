#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define MAXLENGTH 100 //��󳤶�
#define OVERFLOW -2
#define OK 1;
#define ERROR -1;

typedef int status;   //����ֵ״̬
typedef int ELemType; //����ֵ״̬

struct Book{
    int id;
    string name;
};

//˳���Ľṹ��
typedef struct {
    Book *eLem;   //ָ������Ԫ�صĻ���ַ
    int length;   //���Ա�ĵ�ǰ����
} SqList;

//˳���ĳ�ʼ��
status InitlistSq(SqList &L){
    L.eLem = new Book[MAXLENGTH];
    if(!L.eLem){
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
};

//˳����ȡֵ
status GetElems(SqList &L, int i){
    //cout<<L.eLem[i-1].name<<endl;
    Book e;
    if(i<1 || i>L.length){
        return ERROR;
    }
    e = L.eLem[i-1];
    cout<<e.name<<endl;
    return OK;
}

//˳���Ĳ���
status SearchSq(SqList L, string e){
    int i = 0;
    for(i = 0; i<L.length; i++){
        if(L.eLem[i].name == e){
            return i+1;
        }
    }
    return -1;
}

//˳���Ĳ���
status ListInsertSq(SqList &L,int i,Book e){
    if(i<1 || (i>(L.length+1))){//����λ�ò��Ϲ淶
        cout<<"ERROR"<<endl;
        return ERROR;
    }
    if(L.length == MAXLENGTH){//���Ա�����
        cout<<"ERROR2"<<endl;
        return ERROR;
    }
    if(L.length>0){//���Ա��ǿ�
        for(int j=L.length-1;j>i-1;j--){
            L.eLem[j+1] = L.eLem[j];
        }
    }
    L.eLem[i-1] = e;
    L.length++;
    return OK;
}

//˳����ɾ��
status ListDeleteSq(SqList &L,int i){
    if(i<1||(i>L.length)){
        cout<<"ERROR";
        return ERROR;
    }
    for(int j = i;j<L.length;j++){
        L.eLem[j-1] = L.eLem[j];
    }
    --L.length;
    return OK;
}

//int main(){
//    SqList L;
//    int i = 0,choose = -1;
//    int index = 0;
//    Book e;
//    Book book1, book2, book3, book4, book5 ;
//
//    while(choose!=0){
//        scanf("%d",&choose);
//        switch(choose){
//            case 1:{//����˳���
//                if (InitlistSq(L)){
//                    printf("˳������ɹ�/n");
//                } else{
//                    printf("˳�����ʧ��/n");
//                }
//                break;
//            }
//            case 2:{//˳��������Ϣ
//                book1.id=1;
//                book2.id=2;
//                book3.id=3;
//                book4.id=4;
//                book5.id=5;
//                book1.name="����";
//                book2.name="���Ʋ��";
//                book3.name="���޴�½";
//                book4.name="ʥ��";
//                book5.name="����";
//                struct Book book[5] = {book1,book2,book3,book4,book5};
//                for(i = 1; i <= 5; i++){
//                    ListInsertSq(L,i,book[i-1]);
//                    GetElems(L, i);
//                }
//                break;
//            }
//            case 3:{
//                cout<<"������index"<<endl;
//                scanf("%d",&index);
//                GetElems(L, index);
//                break;
//            }
//            case 4:{//����
//                string e = "";
//                printf("����������/n");
//                cin>>e;
//                cout<<SearchSq(L, e);
//            }
//            case 5:{//ɾ��
//                printf("Ҫɾ����λ����");
//                scanf("%d",&index);
//                ListDeleteSq(L, index);
//                for(i = 1; i <= L.length; i++){
//                    GetElems(L, i);
//                }
//            }
//        }
//    }
//}