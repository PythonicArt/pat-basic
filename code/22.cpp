#include <string>
#include <stack>
#include <sstream>
#include <iostream>

std::string countnum(int n,int m,int d){

	int s=n+m;
	std::stack<int> result;
	std::stringstream tmp;
	do
	{
		result.push(s%d);
		s/=d;
	}while(s!=0);
	while(!result.empty())
	{
		tmp<<result.top();
		result.pop();
	}
	return tmp.str();
}

int main(){
	int n,m,d;
	std::cin>>n>>m>>d;
	std::cout<<countnum(n,m,d)<<std::endl;
}