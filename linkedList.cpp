#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define MAXLENGTH 100 //最大长度
#define OVERFLOW -2
#define OK 1;
#define ERROR -1;

typedef int status;   //返回值状态
typedef int ELemType; //返回值状态

struct Book{
    int id;
    string name;
};

//顺序表的结构体
typedef struct {
    Book *eLem;   //指向数据元素的基地址
    int length;   //线性表的当前长度
} SqList;

//顺序表的初始化
status InitlistSq(SqList &L){
    L.eLem = new Book[MAXLENGTH];
    if(!L.eLem){
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
};

//顺序表的取值
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

//顺序表的查找
status SearchSq(SqList L, string e){
    int i = 0;
    for(i = 0; i<L.length; i++){
        if(L.eLem[i].name == e){
            return i+1;
        }
    }
    return -1;
}

//顺序表的插入
status ListInsertSq(SqList &L,int i,Book e){
    if(i<1 || (i>(L.length+1))){//插入位置不合规范
        cout<<"ERROR"<<endl;
        return ERROR;
    }
    if(L.length == MAXLENGTH){//线性表满了
        cout<<"ERROR2"<<endl;
        return ERROR;
    }
    if(L.length>0){//线性表不是空
        for(int j=L.length-1;j>i-1;j--){
            L.eLem[j+1] = L.eLem[j];
        }
    }
    L.eLem[i-1] = e;
    L.length++;
    return OK;
}

//顺序表的删除
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
//            case 1:{//创建顺序表
//                if (InitlistSq(L)){
//                    printf("顺序表创建成功/n");
//                } else{
//                    printf("顺序表创建失败/n");
//                }
//                break;
//            }
//            case 2:{//顺序表插入信息
//                book1.id=1;
//                book2.id=2;
//                book3.id=3;
//                book4.id=4;
//                book5.id=5;
//                book1.name="龙族";
//                book2.name="斗破苍穹";
//                book3.name="斗罗大陆";
//                book4.name="圣墟";
//                book5.name="御龙";
//                struct Book book[5] = {book1,book2,book3,book4,book5};
//                for(i = 1; i <= 5; i++){
//                    ListInsertSq(L,i,book[i-1]);
//                    GetElems(L, i);
//                }
//                break;
//            }
//            case 3:{
//                cout<<"请输入index"<<endl;
//                scanf("%d",&index);
//                GetElems(L, index);
//                break;
//            }
//            case 4:{//查找
//                string e = "";
//                printf("请输入书名/n");
//                cin>>e;
//                cout<<SearchSq(L, e);
//            }
//            case 5:{//删除
//                printf("要删除的位置是");
//                scanf("%d",&index);
//                ListDeleteSq(L, index);
//                for(i = 1; i <= L.length; i++){
//                    GetElems(L, i);
//                }
//            }
//        }
//    }
//}