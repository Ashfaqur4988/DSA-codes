#include<iostream>
using namespace std;

int main(){
    int arr[5] = {2,6,8,5,9};
    int size = 5;
    int num;

    for(int i = 0; i < size; i++){
        num = num + arr[i];
    }
    cout<<num<<endl;
    return 0;
}