#include <iostream>

using namespace std;

int mainMenu();
void inputMatrix(int **arr, int *row, int *col);
void printMatrix(int **arr, int *row, int *col);
void inputHeader(int *row, int *col);
void note(int n);

int main(){
    int **m, r, c;
    switch(mainMenu()){
        case 1:
        system("cls");
        note(1);
        inputHeader(&r, &c);
        m = new int *[r];
        for(int i = 0; i < r; i++){
            m[i] = new int [c];
        }
        inputMatrix(m, &r, &c);
    }
    return 0;
}

int mainMenu(){
    int n;
    system("cls");
    cout << "==========================" << endl;
    cout << "|    MATRIX CALCULATOR   |" << endl;
    cout << "==========================" << endl;
    cout << "Please choose the matrix operation you want\n";
    cout << "1. Matrix Addition\n" << "2. Matrix Substraction\n";
    cout << "3. Matrix Multiplication\n" << "4. Scalar Multiplication\n";
    cout << "5. Transpose\n" << "6. Inverse\n";
    cout << "7. Determinant\n" << "8. Exit\n";
    do{
        cout << "Choose[1-7] >> ";
        cin >> n;
    }
    while(n > 7 || n < 1);

    return n;
}

void inputMatrix(int **arr, int *row, int *col){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            cout << "M[" << i+1 << "][" << j+1 << "] : ";
            cin >> arr[i][j];
        }
    }
}

void addition(int **arr1, int *row, int *col, int **arr2){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            arr1[i][j] += arr2[i][j];
        }
    }
}

void substraction(int **arr1, int *row, int *col, int **arr2){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            arr1[i][j] -= arr2[i][j];
        }
    }
}

void transpose(int **arr1, int *row, int *col){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            arr1[i][j] = arr1[j][i];
        }
    }
}

void inverse2x2(int **arr){
    int d;
    int two = 2;
    d = 1/(arr[0][0]*arr[2][2] - arr[0][1]*arr[1][0]);
	arr[0][0] = arr[2][2];
	arr[0][1] = -arr[0][1];
	arr[1][0] = -arr[1][0];
	arr[1][1] = arr[0][0];
	arr = scalarMultiplication(arr, &two, &two, d);
}

int** scalarMultiplication(int **arr, int *row, int *col, int k){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            arr[i][j] *= k;
        }
    }
    return arr;
}

void matrixMult (int **arr1, int **arr2, int *row, int *col){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            arr1[i][j] *= arr2[j][i];
        }
    }
}

void printMatrix(int **arr, int *row, int *col){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            cout << arr[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void inputHeader(int *row, int *col){
    cout << "Please input the number of column and row\n";
    cout << "Column : ";
    cin >> *col;
    cout << "Row    : ";
    cin >> *row;
}

void note(int n){
    switch(n){
        case 1:
        cout << "Note:\n"
        << "The most important rule to add the matrices is that the"
        << "dimensions of matrices should be same. Once the matrices of"
        << "same order are added, then the elements of the matrices are"
        << "summed up. The resulting matrix will be of the same order.";
    }
}