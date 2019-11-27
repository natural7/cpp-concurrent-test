#include <iostream>
#include <memory>
#include <thread>

using namespace std;

class A;
class B;
class Aw;
class Bw;

class A
{
    public:
    A(void)
    {
        cout << "A constructor"<<endl;
    }
    ~A(void)
    {
        cout << "A destructor"<<endl;
    }
    shared_ptr<B> pb;

};

class B
{
    public:
    B(void)
    {
        cout << "B constructor"<<endl;
    }
    
    ~B(void)
    {
        cout << "B destructor"<<endl;
    }
    shared_ptr<A> pa;
};

class Aw
{
    public:
    Aw(void)
    {
        cout << "Aw constructor"<<endl;
    }
    ~Aw(void)
    {
        cout << "Aw destructor"<<endl;
    }
    void printAw(void)
    {
        cout << "printAw"<<endl;
    }
    weak_ptr<Bw> pwb;

};

class Bw
{
    public:
    Bw(void)
    {
        cout << "Bw constructor"<<endl;
    }
    
    ~Bw(void)
    {
        cout << "Bw destructor"<<endl;
    }
    weak_ptr<Aw> pwa;
};


void deleter (void* ptr) {
    cout << "&ptr" << &ptr<<endl;
	delete ptr;
	ptr = nullptr;
	cout << "shared_ptr delete the pointer." << endl;
}

void foo()
{

    shared_ptr<A> psa( new A);
    shared_ptr<B> psb( new B);
    {
        psa->pb = psb;
        psb->pa = psa;
    }
    cout << "--psa.use_count: "<<psa.use_count()<<endl;
    cout << "--psb.use_count: "<<psb.use_count()<<endl;
    /*这样形成循环依赖，A B并不会释放*/
}

void foo_compare()
{

    shared_ptr<Aw> psa( new Aw,deleter);//指定deleter之后，不再调用自己的析构函数
    shared_ptr<Bw> psb( new Bw);
    
    cout << "out &ptr" << &psa<<endl;

    psa->pwb = psb;
    psb->pwa = psa;
    /*使用weak_ptr解决循环依赖，A B此时会释放*/
}

void foow()
{

    {
        shared_ptr<Aw> pswa( new Aw);
        shared_ptr<Aw> pswaa(pswa);
        weak_ptr<Aw> pswb(pswa);

        // /*占8个字节*/
        // cout<<"sizeof pswa: "<<sizeof pswa<<endl;

        cout << "--pswa.use_count: "<<pswa.use_count()<<endl;//2
        cout << "--pswaa.use_count: "<<pswaa.use_count()<<endl;//2

        pswa.reset();/*这里只是reset pswa的count，对pswaa没有影响，所以此时New出来的Aw不会析构*/
        cout << "pswa.use_count: "<<pswa.use_count()<<endl;//0
        cout << "pswaa.use_count: "<<pswaa.use_count()<<endl;//1
        if(NULL != pswb.lock())
        {
            pswa->printAw();
        }
        else
        {
            cout << "count already 0"<<endl;
        }
        cout << "befor Aw destory"<<endl;
    }

}

int main()
{
    // foo();
    foo_compare();
    // foow();
    return 0;
}