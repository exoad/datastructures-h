#include <iostream>
#include <random>

using namespace std;

int main(void)
{
      int res[12] = {0};
      for(int i=0;i<10000;i++)
            res[((rand()%6+1)+(rand()%6+1))-1]++;
      for(int i=0;i<12;i++)
            cout<<res[i]<<" result: "<<static_cast<double>(res[i]/100)<<"%\n";
}