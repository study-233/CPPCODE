#include <iostream>
using namespace std;
class Sample {
    public:
        int v;
        Sample(int a_){
            v=a_;
        }
        Sample(const Sample &b){
            v=b.v+2;
        }
        Sample(){
        }
        void PrintAndDouble(Sample);
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}