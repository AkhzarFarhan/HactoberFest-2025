#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row, col;
    cout << "Enter the number of rows and columns of the 1st matrix: ";
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int>(col));
    cout << "Enter the elements of the 1st matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    int row1, col1;
    cout << "\nEnter the number of rows and columns of the 2nd matrix: ";
    cin >> row1 >> col1;

    vector<vector<int>> arr1(row1, vector<int>(col1));
    cout << "Enter the elements of the 2nd matrix:\n";
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> arr1[i][j];
        }
    }

    
    if (row1 != row || col1 != col) {
        cout << "\nMatrices are not identical." << endl;
    } else {
        bool identical = true; 
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] != arr1[i][j]) {
                    identical = false; 
                    break;
                }
            }
            if (!identical) break; 

        if (identical) {
            cout << "\nMatrices are identical." << endl;
        } else {
            cout << "\nMatrices are not identical." << endl;
        }
    }

    return 0;
}
}
