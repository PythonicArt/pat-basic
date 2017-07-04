#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

int findnum(int n,long long p)
{
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	int final_count = 0;
    for(int i = 0; i < n; ++i){
        long long max = v[i] * p;
        for(int j = i + final_count; j < n; ++j){
            if(v[j] <= max){
                if(j - i + 1 > final_count){
                    final_count = j - i + 1;
                }
            }
            else{
                break;
            }
        }
    }
	return final_count;
}

int main()
{
	int n,p;
	cin>>n>>p;
    cout<<findnum(n,p)<<endl;
}