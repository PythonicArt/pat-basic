#include <iostream>

using namespace std;

typedef struct information{
    char name[6];
    int year, month, day;
}info;

int compare(info& a, info& b){
    if(a.year != b.year){
        return a.year - b.year;
    }
    else if(a.month != b.month){
        return a.month - b.month;
    }
    else{
        return a.day - b.day;
    }
}

int main(){
    int n;
    cin>>n;
    info first = {"first", 2014, 9, 6}, last = {"last", 1814, 9, 6}; //之后改成n
    int validnum = 0;
    string minname,maxname;
    info maxbirth={"last", 1814, 9, 6},minbirth={"first", 2014, 9, 6};
    for(int i = 0; i < n; ++i){
    	info table;
        scanf("%s %d/%d/%d", table.name, &table.year, &table.month, &table.day);
        if(compare(table, first) > 0 || compare(table, last) < 0){
            continue;
        }
        ++validnum;
        if (compare(table, minbirth)<0)
		{	
			minbirth=table;
		}
		if(compare(table, maxbirth)>0)
		{
			maxbirth=table;
		}
    }

    if(validnum==0)
		cout<<validnum<<endl;
	else
		cout<<validnum<<" "<<minbirth.name<<" "<<maxbirth.name<<endl;
    return 0;
}
