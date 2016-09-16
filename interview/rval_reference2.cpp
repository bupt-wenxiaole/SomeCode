//g++ -std=c++11 
//A(10) 是一个临时变量也就是一个右值，所以需要用右值引用，否则
//A &a = A(10)时编译不通过，
//error: invalid initialization of non-const reference of type ‘A&’ from an rvalue of type ‘A’


class A
{
public:
  A(int a)
  {

  }

};
int main(int argc, char const *argv[])
{
  A&& a = A(10);
  return 0;
}