#include<iostream>

using namespace std;

class integer

{

  int m,n;

  public:

    integer(int x,int y){

      m=x;

      n=y;

      cout<<"1st constructor called"<<endl;

    }

    integer(){

      m=1,n=2;

      cout<<"2nd constructor called"<<endl;

    }

    integer(integer &i){

     m=i.m+5;

     n=i.n+6;

     cout<<"3rd constructor called"<<endl;

    }

    void putdata(){

     cout<<"  m: "<<m<<"\n  n: "<<n<<endl;

    }

};

int main()

{

   integer inte(5,6);

   inte.putdata();

   integer b;

   b.putdata();

   integer c(inte);

   c.putdata();

    return 0;

}
