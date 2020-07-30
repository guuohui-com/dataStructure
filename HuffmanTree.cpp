/*
 * HuffmanTree
 * �������������Ŷ�������
 * */
#include <iostream>
using namespace std;

typedef struct HuffmanTreeNode{
    int weight;//Ȩֵ
    char data; //������
    HuffmanTreeNode *left;//��ڵ�
    HuffmanTreeNode *right;//�ҽڵ�
    HuffmanTreeNode *parent;//���ڵ�
}HuffmanTreeNode,*HuffmanTreeNodePtr;



HuffmanTreeNode* findMin(HuffmanTreeNode *arr,int n){
    HuffmanTreeNode *x = NULL;
    int b = 999;
    int i = 0,tem = 0;

    for (i = 0 ; i < n; ++i) {
        if(arr[i].data != '#' && arr[i].weight <= b){
            x = &arr[i];
            b = arr[i] .weight;
            tem = i;
        }
    }
    arr[tem].data = '#';
    cout<<"��СֵΪ"<<x->weight<<endl;
    return x;
}
/*
 * �����������
 * arr[]:Ҷ�ڵ㼯�ϣ�n��Ҷ�ڵ�����
 * */
HuffmanTreeNode* createHuffmanTree (HuffmanTreeNode arr[], int n){

    HuffmanTreeNode *minFirst, *minSec;
    HuffmanTreeNode *result ;
    int sum = n;
    for (;;) {
        if(sum==1){
            break;
        }
        HuffmanTreeNode *newNode = (HuffmanTreeNode*)malloc(sizeof(HuffmanTreeNode));
        minFirst = findMin(arr,n);
        sum--;
        minSec = findMin(arr,n);
        sum--;
        newNode->left = minFirst;
        newNode->right = minSec;
        newNode->weight = minFirst->weight + minSec->weight;
        arr[n] = *newNode;
        n++;
        sum++;
        result = newNode;
    }
    return result;
};

int main(){

    HuffmanTreeNode d1;
    d1.weight = 1;
    d1.right= NULL;
    d1.left=NULL;
    HuffmanTreeNode d2;
    d2.weight = 2;
    d2.right= NULL;
    d2.left=NULL;
    HuffmanTreeNode d4;
    d4.weight = 4;
    d4.right= NULL;
    d4.left=NULL;
    HuffmanTreeNode d6;
    d6.weight = 6;
    d6.right= NULL;
    d6.left=NULL;
    HuffmanTreeNode d8;
    d8.weight = 8;
    d8.right= NULL;
    d8.left=NULL;

    HuffmanTreeNode arr[100] ={d1,d4,d8,d2,d6};

    HuffmanTreeNode *h = createHuffmanTree(arr ,5);
    while (h){
        cout<<h->weight<<" ";
        h = h->right;
    }
}