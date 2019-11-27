#include <iostream>
#include"./test.h"
using namespace std;  


test::test(void)
{
   cout<< "just test, no pata"<< endl;
}

test::~test(void)
{
   cout<< " ~test "<< endl;
}
void test::setA(int a)
{
   cout<< "set a"<< endl;
   this->a = a;
}

void test::setB(int b)
{
    cout<< "set b"<< endl;
    this->b = b;
}

int test::getA(void)
{
   cout<< "set a: "<< this->a << endl;
   return this->a;
}

int test::getB(void)
{
    cout<< "get b: "<< this->b <<endl;
    return this->b;
}

void test::printt(void)
{
   cout<<this->a<<" "<<this->b<< endl;
}