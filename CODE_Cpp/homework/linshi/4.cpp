#include  <iostream>
#include  <cstring>  
using  namespace  std;
class  Student{  
private:  
        char  *m_name;      
        int  m_id;        
        const  char  m_gender;
        static  int  s_idGenerator;  //用于给Student对象编号  
public:
        Student(char  *name,  char  gender);            
        ~  Student();
        void  print();
        static  int  getSIDGenerator();
};
int  Student::s_idGenerator=1001;
Student:: Student(char  *name,  const char gender='m'):m_gender(gender){
          m_name=new char[strlen(name)+1];
          strcpy(m_name,name);
          m_id=s_idGenerator;
        s_idGenerator++;
}
int  Student::getSIDGenerator(){
    return s_idGenerator;
};
Student::  ~Student(){
          delete[]  m_name;
          m_name  =  0  ;
}
void  Student::print(){
          cout  <<  m_id  <<  "  "  
                          <<  m_name  <<  "  "
                          <<  m_gender  <<  endl;
}
int  main()  {  
        Student  s1("Tom",  'm');  
        s1.print();
      
        Student  s2("Jerry");
        s2.print();
        
        cout  <<  "Next  ID:  "  
                      <<  
                    Student::getSIDGenerator()
                      <<endl;
        return  0;
}