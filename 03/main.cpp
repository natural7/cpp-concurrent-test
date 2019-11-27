#include"people/people.h" 
#include"student/student.h" 
#include"implement/implement.h"

#include <iostream>
using namespace std;  

const bool type = 1;

void test_student(void)
{
   student st0("stdent",20,90);
   st0.print_student();

   student st1("stdent",20,90,type);
   st1.print_student();

   student st2(st1);
   st2.print_student();

   student st3;/*no para*/
   st3.print_student();
}

void test_interface(void)
{
   implement imp;
   imp.dress();
   imp.eat();
   imp.live();
   imp.move();
}

int main(void)
{  

    test_student();
    test_interface();
    return 0;

}
