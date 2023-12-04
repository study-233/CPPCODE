/* 058:从字符串中取数 */
#include <bits/stdc++.h>
using namespace std;
double GetDoubleFromString(char * str){
    static char *start = NULL;
    double x=0;
    bool point=true;   //区分整数部分与小数部分 true->整数
    int count=1;    //小数点后位数
    if(str!=NULL) start=str;  
    if(*start=='\0') return 0;
    for(;!(*start<='9' && *start >='0' || *start=='.');start++);
    for(;(*start<='9' && *start >='0' || *start=='.');start++){
        if(*start<='9' && *start >='0'){
            if(point) x=x*10+(double)(*start-'0');
            else{
                int temp1=count;
                double temp2=(double)(*start-'0');
                while(temp1){
                    temp2/=10;
                    temp1--;
                }
                x+=temp2;
                count++;
            }
        }
        else  point=false;
    }
    return x;
}
int main(){
    freopen("E:\\CPPCODE\\MOOC\\in.txt","r",stdin);
	char line[300];
	while(cin.getline(line,280)){
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}

