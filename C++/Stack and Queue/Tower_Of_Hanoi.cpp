#include <bits/stdc++.h>
using namespace std;

/*
There are 3 Rods A, B, C. Rod A has N discs of diffrent sizes in sorted manner in it.
You have to move all N discs from rod A to C (Use Rod B for convenience). but 3 given rules should be followed..

1. we can move only one disc at a time..
2. we can't put smaller discs below a larger disc..
3. disc's in Rod C also should be in sorted manner..

***********  APPROACH *********
WRITE THE STEPS TO MOVE 2 AND 3 DISC FROM ROD A TO C ON YOUR OWN..
FOLLOW THE SAME STEPS TO MOVE N DISCS...

*/


void TOH(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0) {return;}

    TOH(n - 1, from_rod, aux_rod, to_rod);

    cout << "Move disk " << n << " from rod " << from_rod <<  " to rod " << to_rod << endl;

    TOH(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n; cin>>n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}
