//C/C++实现
#include <iostream>
#include <algorithm>
#include <iomanip>


bool compare(double* a,double* b)
{
	return a[2]>b[2];
}

double getMaxEarnings(){
	int n,need;
	std::cin>>n>>need;
	double **cargo=new double*[n];
	for(int i=0;i<n;i++)
		cargo[i]=new double[3];

	for(int i=0;i<n;i++) 
		std::cin>>cargo[i][0];
	for(int i=0;i<n;i++)
	{
		std::cin>>cargo[i][1];
		cargo[i][2]=cargo[i][1]/cargo[i][0];
	}

	std::sort(cargo,cargo+n,compare);

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<3;j++)
	// 	{
	// 		std::cout<<cargo[i][j]<<" ";
	// 	}
	// 	std::cout<<std::endl;
	// }

	double j=need;
	double income=0;
	for(int i=0;i<n;i++)
	{
		double r=cargo[i][0];
		double unitprice=cargo[i][2];
		if(r<=j)
		{
			income+=cargo[i][1];
			j-=r;
			if(j<=0)break;
		}
		else{
			income+=unitprice*j;
			break;
		}
	}

	std::cout<< std::fixed << std::setprecision(2)<<income<<std::endl;
	for(int i=0;i<n;i++) 
		delete cargo[i];
	delete [] cargo;
	return income;
}

// int main(){
// 	getMaxEarnings();
// }