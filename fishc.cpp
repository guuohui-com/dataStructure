#include <iostream>
#include <stack>
using namespace std;
////********************************************************分解质因数
//判断质数
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
//分解质因数
//int resove(int n){
//    int i = 0;
//    if(prime(n)){//是质数
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
//***************************************************************************分解质因数

////**************************************************************************汉诺塔问题
//
//void move(char from, char to){
//    cout<<from <<" -> " << to <<endl;
//}
//
//void hanno(int n ,char first, char sed, char third){////定义hanoi函数，将n个盘子从first借助sec移动到third
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
//**************************************************************************汉诺塔问题

////*************************************************************************栈 模拟进制转换
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
//    cout<<"请输入将要转换的数"<<endl;
//    cin>>num;
//    cout<<endl<<"请输入进制";
//    cin>>zhi;
//    translate(num, zhi);
//    while(!s.empty()){
//        cout<<s.top()<<endl;
//        s.pop();
//    }
//    return 0;
//}
//*************************************************************************栈 模拟进制转换
