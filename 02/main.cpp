#include"sub1/test.h" 
#include <iostream>
using namespace std;  

void foo(void)
{
    cout<<"hello"<<endl;  
    test c(2,3);
    c.getA();
    printf("a:%d",c.getA());
    c.printt();

    test d;
}
int main(void)
{  

    foo();
    return 0;

}
