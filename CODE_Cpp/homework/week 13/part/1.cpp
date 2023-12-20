#include  <iostream>      
#include  <cstring>
using  namespace  std;    
class  Manager
{
    private:
        int id;
        
};
Manager::Manager(int  pId,char*  pName,int  pAge)
{

            cout<<"Constructed  with  all  parameters."<<endl;
}
Manager::~Manager()
{

            cout<<"Deconstructed."<<endl;
}
void  printManager(Manager&  manager)
{
            cout<<"id:  "<<manager.id<<",  "
                      <<"name:  "<<manager.name<<",  "
                      <<"age:  "<<manager.age<<endl;
}
int  main()
{
            Manager  m1(1001,"zhangsan",22);
            printManager(m1);
            return  0;
}