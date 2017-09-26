#include<bits/stdc++.h>
using namespace std;
#define size 1000001
int main(){
	int a[size];
	map<int , int> mp;
	map<int , int>::iterator itr, it;
	for(int i = 2;i< size; ++i){
		a[i] = i;
	}	

	for(int i = 2; i*i< size ; ++i){
		if(a[i] == i){
			mp.insert(pair<int, int>(i,i));
			for(int j = i*2; j<size ; j+=a[i]){
				a[j] = a[i];
			}
		}
	}
	int count = 0;
	for(int i = 2;i<size; ++i){
		if(a[i] == i){
			++count;
			cout<<a[i]<<endl;
		}
	}
	cout<<"Total "<<count<<endl;

	// mp.clear();

}