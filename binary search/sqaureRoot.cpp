#include<iostream>
using namespace std;

int squareRoot(int k){
    int s = 0;
    int e = k;
    int m = s + (e-s)/2;
    int ans;

    while(s <= e){
        if(m*m == k){
            return m;
        };
        if(m*m > k){
            e = m-1;
        } else {
            ans = m;
            s = m+1;
        }
        m = s + (e-s)/2;
    }
    return ans;
}

double morePrecision(int n, int prec, int ans){
    double factor = 1;
    for(int i=0; i<prec; i++){
        factor = factor/10;
        for(int j=ans; j*j<n; j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int num = 16;
    int ans = squareRoot(num);
    cout<<ans<<endl;
    return 0;
}