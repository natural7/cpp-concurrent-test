#include "bike.h"

bike::bike(void)//构造函数不能为虚函数
{
    cout << "bike constructor"<<endl;
}
    
bike::~bike(void)
{
    cout << "bike destructor will go away"<<endl;
}