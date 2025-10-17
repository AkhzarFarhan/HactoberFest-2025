#include <iostream>
using namespace std;

void towerHanoi(int, char, char, char);

int main(){
    int num;
    cout << "Enter the number of disks : ";
    cin >> num;
    cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
    towerHanoi(num, 'A', 'C', 'B');
    cout << "\n";
}
void towerHanoi(int num, char source, char destination, char auxilliary)
{
    if(num == 1){
    	cout << "\nMove disk 1 from peg " << source <<" to peg "<< destination;
        return;
    }
    towerHanoi(num - 1, source, auxilliary, destination);
    cout << "\nMove disk " << num << " from peg " << source <<" to peg "<< destination;
    towerHanoi(num - 1, auxilliary, destination, source);
}