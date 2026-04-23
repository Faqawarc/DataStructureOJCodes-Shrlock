#include<iostream>
#include<iomanip>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    while(n--) {
        int cnt=1;
        double num;
        cin>>num;
        double low=0;
        double high=num;
        double flag;
        double k=(low+high)/2;
        while(1) {
            flag=k*k-num;
            if(abs(flag)<0.00001) {
                cout<<cnt<<" "<<fixed<<setprecision(3)<<k<<endl;
                break;
            } else if(flag>0) {
                high=k;
                k=(low+high)/2;
            } else {
                low=k;
                k=(low+high)/2;
            }
            cnt++;
        }
    }
    return 0;
}