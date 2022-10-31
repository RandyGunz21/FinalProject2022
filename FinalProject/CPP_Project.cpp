#include <iostream>
#include <iomanip>

#define RED "\e[0;31m"
#define WHITE "\e[0m"
#define GREEN "\e[0;32m"

using namespace std;

struct matD{
    int row;
    int column;
};
int mainMenu(); int** arrDec(int *row, int *column);
void inputMatrix(int **arr, int *row, int *column);
void printMatrix(int **arr, int *row, int *column);
void inputHeader(int *row, int *col);
void note(int n); void menuHeader(int n);
int chosing(); int chosing2();
int** addition(int **arr1, int **arr2, int *row, int *col);
int** substraction(int **arr1, int **arr2, int *row, int *col);
int** multiply(int **arr1, int **arr2, int *resRow, int *resCol, int *sameRowCol);
int** scalar(int **arr, int *row, int *col, int *k);
int** transpose(int **arr, int *row, int *col);

int main(){
    main:
    int **m1, **m2, **res;
    matD ordo1;
    int count;
    char ans;
    switch(mainMenu()){
        case 1:
        system("cls");
        menuHeader(1); note(1);
        switch(chosing()){
            case 1:
            add:
            system("cls"); menuHeader(1); count = 3;
            note(1); inputHeader(&ordo1.row, &ordo1.column);
            res = arrDec(&ordo1.row, &ordo1.column);
            m1 = arrDec(&ordo1.row, &ordo1.column); m2 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix 1:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            cout << "\nMatrix 2:\n"; inputMatrix(m2, &ordo1.row, &ordo1.column);
            res = addition(m1, m2, &ordo1.row, &ordo1.column);
            do{
                cout << "\nAre you want to add more matrix to add?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    cout << "\nMatrix " << count << ":\n";
                    inputMatrix(m2, &ordo1.row, &ordo1.column); count++;
                    res = addition(res, m2, &ordo1.row, &ordo1.column);
                }
                else{
                    cout << GREEN "\nResult:\n";
                    printMatrix(res, &ordo1.row, &ordo1.column);
                    cout << WHITE;
                    switch(chosing2()){
                        case 1:
                        goto add;

                        case 2:
                        goto main;

                        case 3:
                        system("exit");
                    }
                }
            }while(ans == 'y' || ans == 'Y');
            break;

            case 2:
            goto main;
            break;
        }
        break;

        case 2:
        system("cls");
        menuHeader(2); note(2);
        switch(chosing()){
            case 1:
            subs:
            system("cls"); menuHeader(2); count = 3;
            note(2); inputHeader(&ordo1.row, &ordo1.column);
            res = arrDec(&ordo1.row, &ordo1.column);
            m1 = arrDec(&ordo1.row, &ordo1.column); m2 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix 1:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            cout << "\nMatrix 2:\n"; inputMatrix(m2, &ordo1.row, &ordo1.column);
            res = substraction(m1, m2, &ordo1.row, &ordo1.column);
            do{
                cout << "\nAre you want to add more matrix to substract?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    cout << "\nMatrix " << count << ":\n";
                    inputMatrix(m2, &ordo1.row, &ordo1.column); count++;
                    res = substraction(res, m2, &ordo1.row, &ordo1.column);
                }
                else{
                    cout << GREEN "\nResult:\n";
                    printMatrix(res, &ordo1.row, &ordo1.column);
                    cout << WHITE;
                    switch(chosing2()){
                        case 1:
                        goto subs;

                        case 2:
                        goto main;

                        case 3:
                        system("exit");
                    }
                }
            }while(ans == 'y' || ans == 'Y');
            break;

            case 2:
            goto main;
            break;
        }
        break;

        case 3:
        system("cls");
        menuHeader(3); note(3);
        switch(chosing()){
            case 1:
            multiply:
            matD ordo2, ordoRes; count = 3;
            system("cls"); menuHeader(3); note(3);
            inputHeader(&ordo1.row, &ordo1.column); m1 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix 1:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            do{
                inputHeader(&ordo2.row, &ordo2.column);
                if(ordo1.column != ordo2.row)
                    cout << RED "Matrix 1 column and matrix 2 row should be same\n" << WHITE;

            }while(ordo1.column != ordo2.row);

            m2 = arrDec(&ordo2.row, &ordo2.column);
            cout << "Matrix 2:\n"; inputMatrix(m2, &ordo2.row, &ordo2.column);
            ordoRes.row = ordo1.row; ordoRes.column = ordo2.column;
            res = arrDec(&ordoRes.row, &ordoRes.column);
            res = multiply(m1, m2, &ordo1.row, &ordo2.column, &ordo1.column);
            do{
                cout << GREEN "\nResult:\n";
                printMatrix(res, &ordo1.row, &ordo2.column);
                cout << WHITE "\nAre you want to add more matrix to multiply?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    do{
                        inputHeader(&ordo2.row, &ordo2.column);
                        if(ordoRes.column != ordo2.row)
                            cout << RED "Matrix result column and matrix " << count << " row should be same\n" << WHITE;

                    }while(ordoRes.column != ordo2.row);
                    cout << "Matrix " << count << ":\n";
                    inputMatrix(m2, &ordo2.row, &ordo2.column); count++;
                    res = multiply(res, m2, &ordo1.row, &ordo2.column, &ordoRes.column);
                }
                else{
                    switch(chosing2()){
                        case 1:
                        goto multiply;

                        case 2:
                        goto main;

                        case 3:
                        system("exit");
                    }
                }
            }while(ans == 'y' || ans == 'Y');
            break;

            case 2:
            goto main;
            break;
        }
        break;

        case 4:
        system("cls");
        menuHeader(4); note(4);
        switch(chosing()){
            case 1:
            scalar:
            int mul;
            system("cls"); menuHeader(4);
            note(4); inputHeader(&ordo1.row, &ordo1.column);
            m1 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            cout << "\nMultiplier: "; cin >> mul;
            cout << GREEN << "\nResult:\n";
            printMatrix(scalar(m1, &ordo1.row, &ordo1.column, &mul),
            &ordo1.row, &ordo1.column); cout << WHITE;
            switch(chosing2()){
                case 1:
                goto scalar;

                case 2:
                goto main;

                case 3:
                system("exit");
            }
            break;

            case 2:
            goto main;
            break;
        }
        break;

        case 5:
        system("cls");
        menuHeader(5); note(5);
        switch(chosing()){
            case 1:
            trans:
            system("cls"); menuHeader(5);
            note(5); inputHeader(&ordo1.row, &ordo1.column);
            m1 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            cout << GREEN << "\nResult:\n";
            printMatrix(transpose(m1, &ordo1.row, &ordo1.column),
            &ordo1.column, &ordo1.row); cout << WHITE;
            switch(chosing2()){
                case 1:
                goto trans;

                case 2:
                goto main;

                case 3:
                system("exit");
            }
            break;

            case 2:
            goto main;
            break;
        }
        break;

        case 6:
        system("cls");
        menuHeader(6); note(6);
        switch(chosing()){
            case 1:
            determinant:
            system("cls"); menuHeader(6);
            note(6); inputHeader(&ordo1.row, &ordo1.column);
            m1 = arrDec(&ordo1.row, &ordo1.column);
            cout << "Matrix:\n"; inputMatrix(m1, &ordo1.row, &ordo1.column);
            cout << GREEN << "\nResult:\n";
            printMatrix(transpose(m1, &ordo1.row, &ordo1.column),
            &ordo1.column, &ordo1.row); cout << WHITE;
            switch(chosing2()){
                case 1:
                goto determinant;

                case 2:
                goto main;

                case 3:
                system("exit");
            }
            break;

            case 2:
            goto main;
            break;
        }
        break;
    }
    return 0;
}

int** arrDec(int *row, int *column){
    int **array;
    array = new int *[*row];
    for(int i = 0; i < *row; i++){
        array[i] = new int [*column];
    }
    return array;
}

int mainMenu(){
    int n;
    system("cls");
    cout << "======================================" << endl;
    cout << "|          MATRIX CALCULATOR         |" << endl;
    cout << "======================================" << endl;
    cout << "Please choose the matrix operation you want\n";
    cout << "1. Matrix Addition\n" << "2. Matrix Substraction\n";
    cout << "3. Matrix Multiplication\n" << "4. Scalar Multiplication\n";
    cout << "5. Transpose\n" << "6. Daterminant\n";
    cout << "7. Inverse\n" << "8. Exit\n";
    do{
        cout << "Choose[1-8] >> ";
        cin >> n;
    }
    while(n > 8 || n < 1);

    return n;
}

void inputMatrix(int **arr, int *row, int *column){
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *column; j++){
            cout << "M[" << i+1 << "][" << j+1 << "] : ";
            cin >> arr[i][j];
        }
    }
}

void printMatrix(int **arr, int *row, int *column){
    for(int i = 0; i < *row; i++){
        cout << "|";
        for(int j = 0; j < *column; j++){
            cout << setw(5) << arr[i][j];
        }
        cout << " |\n";
    }
}

void inputHeader(int *row, int *col){
    cout << endl << "Please input the number of column and row\n";
    cout << "Column : ";
    cin >> *col;
    cout << "Row    : ";
    cin >> *row;
    cout << endl;
}

void menuHeader(int n){
    switch(n){
        case 1:
        cout << "======================================" << endl;
        cout << "|           MATRIX ADDITION          |" << endl;
        cout << "======================================" << endl;
        break;

        case 2:
        cout << "======================================" << endl;
        cout << "|         MATRIX SUBSTRACTION        |" << endl;
        cout << "======================================" << endl;
        break;

        case 3:
        cout << "======================================" << endl;
        cout << "|        MATRIX MULTIPLICATION       |" << endl;
        cout << "======================================" << endl;
        break;

        case 4:
        cout << "======================================" << endl;
        cout << "|        SCALAR MULTIPLICATION       |" << endl;
        cout << "======================================" << endl;
        break;

        case 5:
        cout << "======================================" << endl;
        cout << "|          TRANSPOSE MATRIX          |" << endl;
        cout << "======================================" << endl;
        break;

        case 6:
        cout << "======================================" << endl;
        cout << "|         MATRIX DETERMINANT         |" << endl;
        cout << "======================================" << endl;
        break;
    }
}

void note(int n){
    switch(n){
        case 1:
        cout << "Note:\n";
        cout << "The most important rule to add the matrices is that"
        << " the dimensions of matrices should be same.\nOnce the matrices of"
        << " same order are added, then the elements of the matrices are summed up.\n"
        << "The resulting matrix will be of the same order.\n";
        break;

        case 2:
        cout << "Note:\n";
        cout << "The most important rule to substract the matrices is that"
        << " the dimensions of matrices should be same.\nOnce the matrices of"
        << " same order are substract, then the elements of the matrices are substracted up.\n"
        << "The resulting matrix will be of the same order.\n";
        break;

        case 3:
        cout << "Note:\n";
        cout << "The product of two matrices A and B is defined if the number"
        << " of columns of A is equal to the number of rows of B.\n";
        break;

        case 4:
        cout << "Note:\n";
        cout << "The term scalar multiplication refers to the product of a real number "
        << "and a matrix.\nIn scalar multiplication, each entry in the matrix is multiplied "
        << "by the given scalar.\n";
        break;

        case 5:
        cout << "Note:\n";
        cout << "The transpose of a matrix is found by interchanging its rows into columns or columns into rows.\n";
        break;

        case 6:
        cout << "Note:\n";
        cout << "Determinant of matrix only available for square matrix such as 2x2 or 3x3 matrix.\n";
        break;
    }
}

int chosing(){
    int z;
    cout << "1. Calculate\n2. Back\n";
    do{
        cout << "Choose[1-2] >> ";
        cin >> z;
    }while(z < 1 || z > 2);
    return z;
}

int chosing2(){
    int a;
    cout << "\nWhere you want to go?\n";
    cout << "1. Calculate again\n"
    << "2. Main menu\n3. Exit\n";
    do{
        cout << "Choose[1-3] >> ";
        cin >> a;
    }while(a < 1 || a > 3);
    return a;
}

int** addition(int **arr1, int **arr2, int *row, int *col){
    int** result;
    result = arrDec(row, col);
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return result;
}

int** substraction(int **arr1, int **arr2, int *row, int *col){
    int** result;
    result = arrDec(row, col);
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    return result;
}

int** multiply(int **arr1, int **arr2, int *resRow, int *resCol, int *sameRowCol){
    int** result;
    result = arrDec(resRow, resCol);
    for(int i = 0; i < *resRow; i++){
        for(int j = 0; j < *resCol; j++){
            result[i][j] = 0;
            for(int k = 0; k < *sameRowCol; k++){
                result[i][j] += (arr1[i][k]*arr2[k][j]);
            }
        }
    }
    return result;
}

int** scalar(int **arr, int *row, int *col, int *k){
    int **result;
    result = arrDec(row, col);
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            result[i][j] = arr[i][j]*(*k);
        }
    }
    return result;
}

int** transpose(int **arr, int *row, int *col){
    int** result;
    result = arrDec(col, row);
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            result[j][i] = arr[i][j];
        }
    }
    return result;
}

/*int** det(int **arr, int *row, int *col){
    int** result;
    result = arrDec(row, column);
    
}*/
