#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int mt, pt[100], diff[100],n, l=5, s=0,avg, count=0;
    cout<<"\n enter master time ";
    cin>>mt;

    cout<<"\n enter the number of process ";
    cin>>n;
    cout<<"\n enter their times ";
    for(int i=0;i<n;i++){
        cin>>pt[i];
    }
    for(int i=0;i<n;i++)
    {
        if(abs(mt-pt[i])<5){
            s+=pt[i];
            count++;
        }

    }
    avg = s/count;
    cout<<"n average "<<avg;
    for(int i=0;i<n;i++){

                diff[i]=pt[i]-avg;

    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<" error value for process "<<i<<" difference value "<<diff[i]<<" final clock value "<<pt[i]-diff[i]<<endl;
    }
}