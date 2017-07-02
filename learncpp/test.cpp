#include <iostream>
using namespace std;


int main(){

char cv='a',*pcv=&cv;  
short sv=1, *psv=&sv;  
int iv=1, *piv=&iv;  
long lv=1, *plv=&lv;  
long long llv=1, *pllv=&llv;  
float fv=1.0, *pfv=&fv;  
double dv=1.0, *pdv=&dv;  
long double ldv=1.0, *pldv=&ldv;  
   
//cout<<"pcv:"<<pcv<<" pcv+1: "<<pcv+1<<endl;  
cout<<"psv:"<<psv<<" psv+1: "<<psv+1<<" "<<psv+1-psv<<endl;  
cout<<"piv:"<<piv<<" piv+1: "<<piv+1<<endl;  
cout<<"plv:"<<plv<<" plv+1: "<<plv+1<<endl;  
cout<<"pllv:"<<pllv<<" pllv+1: "<<pllv+1<<endl;  
cout<<"pfv:"<<pfv<<" pfv+1: "<<pfv+1<<endl;  
cout<<"pdv:"<<pdv<<" pdv+1: "<<pdv+1<<endl;  
cout<<"pldv:"<<pldv<<" pldv+1: "<<pldv+1<<endl;  
cout<<endl; 
}