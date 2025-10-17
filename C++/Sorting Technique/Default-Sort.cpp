// Sort using Default Sort function of
// algorithm library which does the
// sorting in ascending order


#include <iostream>
#include <algorithm>

using namespace std;

int main (){

    // Initializing Array
    int data[] = {32, 71, 12, 45, 26};

    // start ptr, end ptr , function ptr(optional)
    sort (data, data + 5);
    for (int i = 0; i < 5; i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}