#include <iostream>
#include <string>
using namespace std;
int main()
{
  int count=0;
  for(int i=1;i<100000000;i++){
    string str = to_string(i);
    int len = str.size();
    int sum1=0,sum2=0;
    if(len%2 == 0){
      for(int j=0;j<len/2;j++){
        sum1+=int(str[j]);
      }
      for(int j=len/2;j<len;j++){
        sum2+=int(str[j]);
      }
      if(sum1==sum2){
        count++;
      }
    }
    else continue;
  }
  cout<<count;
  return 0;
}