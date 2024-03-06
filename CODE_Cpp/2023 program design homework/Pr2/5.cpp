#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

static int handle = 0;
static int sum = 0;//用来计算总内存

int main() {
    int T, MaxMem;
    while (cin >> T >> MaxMem) {
        vector<int> arr(T + 1, -2); //用来存放句柄
        vector<int> sizeArr(T + 1); //用来存放句柄对应的size
        cin.ignore();
        for (int i = 0; i < T; i++) {
            string str;
            getline(cin, str);
            istringstream ss(str);
            string op;
            int size = 0;
            ss >> op;
            if (str.length() > 3) {
                ss >> size;
            }
            if (op == "new") {
                sum += size;
                if (sum <= MaxMem) {
                    handle++;
                    arr[handle] = size;
                    sizeArr[handle] = size;
                    cout << handle << endl;
                } else {
                    sum -= size;
                    cout << "NULL" << endl;
                }
            } else if (op == "del" && arr[size] != -1) {
                arr[size] = -1; //-1表示删除了该句柄
            } else if (op == "del" && arr[size] == -1) {
                cout << "ILLEGAL_OPERATION" << endl;
            } else if (op == "def") {
                for (int j = 0; j < arr.size(); j++) {
                    if (arr[j] == -1) {
                        sum -= sizeArr[j];
                    }
                }
            }
        }
    }
    return 0;
}