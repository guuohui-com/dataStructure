#include <iostream>
#include <stack>
using namespace std;
////********************************************************�ֽ�������
//�ж�����
//bool prime(int n){
//    int i = 2;
//    if(n == 2){
//        return true;
//    } else{
//      for(i = 2; i < n; i++){
//          if(n % i == 0){
//              return false;
//          }
//      }
//    }
//    return true;
//}
//�ֽ�������
//int resove(int n){
//    int i = 0;
//    if(prime(n)){//������
//        cout<<n<<" * ";
//        return n;
//    } else{
//        for(i = 2;;i++){
//            if(n % i == 0){
//                resove(n/i);
//                resove(i);
//                break;
//            }
//        }
//    }
//    return 0;
//}
//
//int main(){
//    while (true){
//        int n;
//        cin>>n;
//        cout<<n<<" = ";
//        resove(n);
//    }
//}
//***************************************************************************�ֽ�������

////**************************************************************************��ŵ������
//
//void move(char from, char to){
//    cout<<from <<" -> " << to <<endl;
//}
//
//void hanno(int n ,char first, char sed, char third){////����hanoi��������n�����Ӵ�first����sec�ƶ���third
//    if(n == 1){
//        move(first,third);
//    }else{
//       hanno(n-1,first,third,sed);
//       move(first,third);
//       hanno(n-1,sed,first,third);
//    }
//}
//
//int main(){
//    hanno(3,'A','B','C');
//    return 0;
//}
//**************************************************************************��ŵ������

////*************************************************************************ջ ģ�����ת��
//
//stack<int> s;
//
//int translate(int n,int x){
//    while (n/x != 0){
//        s.push(n%x);
//        n = n/x;
//    }
//    s.push(n%x);
//}
//
//int main(){
//    int num, zhi;
//    cout<<"�����뽫Ҫת������"<<endl;
//    cin>>num;
//    cout<<endl<<"���������";
//    cin>>zhi;
//    translate(num, zhi);
//    while(!s.empty()){
//        cout<<s.top()<<endl;
//        s.pop();
//    }
//    return 0;
//}
//*************************************************************************ջ ģ�����ת��
