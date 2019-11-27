#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class test
{
private:
    /* data */
public:
    test(int a);
    ~test();
    int get_a(void);

private:
    int a;
};

test::test(int a)
{
    // cout << "i am constructor"<<endl;
    this->a = a; 
}

test::~test()
{
    // cout << "i am destructor"<<endl; 
    cout << "a: "<<this->a<<"   ~des"<<endl; 
}

int test::get_a(void)
{
    return this->a;
}

/*shared_ptr 内部是一个指针和一个long的计数count，所以占8个字节*/


shared_ptr<test> q(new test(2));
void foo()
{
    shared_ptr<test> p(new test(1));
    cout<<"p.use_count: "<<p.use_count()<<endl;
    cout<<"p.get()"<<p.get()<<" "<<endl;

    p = q;/*在这里p指向的对象就销毁了*/
    
    cout<<"-----------"<<endl;
    shared_ptr<test> r(new test(3));
    cout<<"r.use_count: "<<r.use_count()<<endl;
    cout<<"r.get()"<<r.get()<<" "<<endl;
    cout << "r.get()->get_a()"<<r.get()->get_a()<<endl;/*get方法获取所指向的变量*/

    p = r;
    cout<<"p.use_count: "<<p.use_count()<<endl;
    cout<<"p.get()"<<p.get()<<" "<<endl;
    cout<<"r.use_count: "<<r.use_count()<<endl;/*此时，p r的count都是2，同时发生变化*/
    cout<<"r.get()"<<r.get()<<" "<<endl;

    cout<<"-----------"<<endl;
    shared_ptr<test> m(new test(4));
    cout<<"m.use_count: "<<m.use_count()<<endl;
    cout<<"m.get()"<<m.get()<<" "<<endl;
    p = m;
    cout<<"p.use_count: "<<p.use_count()<<endl;
    cout<<"p.get()"<<p.get()<<" "<<endl;

    // system("pause");
    // _sleep(1);
}

int main()
{
    foo();
    cout<<"q.get()"<<q.get()<<" "<<endl;
    cout<<"sizeof q:"<<sizeof q <<" "<<endl;
    // system("pause");
    return 0;
}