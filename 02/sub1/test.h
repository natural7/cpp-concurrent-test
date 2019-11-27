#include <iostream>
using namespace std;  
  
class test
{
   public:
   test(int aa,int bb):a(aa),b(bb)
   {
      cout<<"hello test"<<endl;
   };

   test(void);
   ~ test(void);
   void setA(int a);
   void setB(int b);
   int getA(void);
   int getB(void);
   void printt(void);

   private:
   int a;
   int b;
};