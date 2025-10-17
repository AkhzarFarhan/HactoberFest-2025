#include <iostream>
#include <ctime>
using namespace std;
 
int main( )
 {
    
time_t ttime = time(0);
    
char* dt = ctime(&ttime);
cout << "The current local date and time is: " << dt << endl;
 
tm *gmt_time = gmtime(&ttime);
dt = asctime(gmt_time);
cout << "The current UTC date and time is:"<< dt << endl;
 }
