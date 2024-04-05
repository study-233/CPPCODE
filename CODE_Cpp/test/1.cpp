#include <iostream>
using namespace std;
int main(){
    int a = 2,res = 0;
    switch(a){
        case 1:
            res += a;
        case 2:
            res += 2 * a;
        case 3:
            res += 3;
            break;
    }
    cout << res << endl;
}