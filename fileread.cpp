#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

extern std::string divide(char*,int);

int main()
{

  string a;
  int i=0;
  ifstream in("input");
  // ifstream rin("result");
  // if (not in || not rin)
  if (not in)
    perror("input");
  else
  {
    int n;
    while(in>>n)
      {
        cout<<in.tellg()<<" "<<n<<endl;
        int pos=in.tellg();
        in.seekg(0);
      }

    in.close();
  }

   // scanf("%s %c %s %c",a,&c,b,&d);
}