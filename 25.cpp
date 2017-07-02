#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>
// #include <iomanip>


using namespace std;


struct node{
    int address, data, next;
};


int main(){
    int start, n, k, address, data, next;
    cin>>start>>n>>k;
    vector<node> list;
    vector<node>::iterator it;
    //build chain
    for(int i = 0; i < n; ++i){
        node mnode;
        cin>>mnode.address>>mnode.data>>mnode.next;
        if(mnode.address==start)
        {
            node first=list.front();
            if (first.address!=mnode.next)
            {
                node nnode;
                nnode.address=mnode.next; 
                list.insert(list.begin(),nnode);
            }
            list.insert(list.begin(),mnode);
        }
        else{
            bool minlist=false;
            for(it=list.begin();it<list.end();it++)
            {
                if((*it).address==mnode.address)
                {
                    (*it).data=mnode.data;
                    (*it).next=mnode.next;
                    node tmp=*(it+1);
                    if (tmp.address!=mnode.next)
                    {
                        node nnode;
                        nnode.address=mnode.next; 
                        list.insert(it+1,nnode);
                    }
                    minlist=true;
                    break;
                }
                else if((*it).address==mnode.next)
                {
                    if (not minlist)
                    {
                        list.insert(it,mnode);
                        minlist=true;
                    }
                    break;
                }
            }
            if (not minlist)
            {
                list.push_back(mnode);
                node nnode;
                nnode.address=mnode.next;
                list.push_back(nnode);
            }
        }
    }
    list.pop_back();
    // for(int i=0;i<list.size();i++)
    //     cout<<setfill('0')<<setw(5)<<list[i].address<<" "<<endl;

    //reverse
    for(int l = 0, index = 0; l < list.size() / k; ++l){
        reverse(list.begin() + index, list.begin() + index + k);
        index += k;
    }

    //output
    int o = 0;
    for(; o < list.size() - 1; ++o){
        printf("%05d %d %05d\n", list[o].address, list[o].data, list[o + 1].address);
    }
    printf("%05d %d -1\n", list[o].address, list[o].data);
    return 0;
}