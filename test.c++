#include<bits/stdc++.h>
using namespace std;


int main(){
    int num1 = 333, num2 = 1110;
    int cnt = 0;
    while(num1 != 0 && num2 != 0){
        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
        cnt++;
    }
    cout<<cnt;
    return 1;
}