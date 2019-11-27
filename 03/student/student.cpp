#include <iostream>
#include"student.h"
using namespace std;  

/*static member assign in .cpp file*/
/*const member assign in initial list*/

uint32_t student::sum = 0;
string student::properity = "student";

student::student(bool type):type(type)
{
   cout<< "hello student, no para" << endl;
}


/*can not compile ok*/
// student::student()
// {
//    cout<< "hello student, no para" << endl;
// }

student::student(const string name, const uint32_t age, const uint8_t score,uint32_t print_num,bool type):people(name,age),score(score),print_num(print_num),type(type)
{
   cout<<"hello student"<<endl;
   sum++;
};

/*when people no copy Copy constructor,the default will be used*/
student::student(const student &st):people(st),print_num(print_num),type(st.type)
{
   this->score = st.score;
   sum++;
}

student::~ student(void)
{
   cout<< "~student " << this->get_name() << " "<< this->get_age() << " " <<this->get_score()<< endl;
}
void student::set_score(uint8_t score)
{
   this->score = score;
}
int student::get_score(void) const
{
   return this->score;
}

/*const function can only call the const function, and can not change the un mutable member variables*/
void student::print_student(void) const
{
   cout<< "student name:" << this->get_name() << " age:" << this->get_age() << " scroe: " << this->get_score()<< " type: "<< this->type << " sum: "<< student::sum << " property: "<< this->properity << endl;
   cout<< " property: "<< student::properity << endl;

   cout << "print_num:"<< print_num++ <<endl;
}

void student::life_style(void)
{
   cout<<"student "<<this->get_name() << " study all day in classroom" << endl;
}

void student::spend_life(void)
{
   cout<<"student "<< this->get_name() << " only love study" << endl;
}