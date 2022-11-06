#include <iostream>
#include <iomanip>
#include <cmath>

#define RED "\e[0;31m"
#define WHITE "\e[0m"
#define GREEN "\e[0;32m"

using namespace std;

struct matD{
    int row;
    int column;
};
int mainMenu(); double** arrDec(matD ordo);
void inputMatrix(double **arr, matD ordo);
void printMatrix(double **arr, matD ordo);
void inputHeader(matD &ordo);
void note(int n); void menuHeader(int n);
int chosing(); int chosing2();
double** addition(double **arr1, double **arr2, matD ordo);
double** substraction(double **arr1, double **arr2, matD ordo);
double** multiply(double **arr1, double **arr2, matD ordo1, matD ordo2);
double** scalar(double **arr, matD ordo, double *k);
double** transpose(double **arr, matD ordo);
int det(double **arr, matD ordo);
double** matrixMinor(double **arr, matD ordo);
double** cof(double **arr, matD ordo);
double** inv(double **arr, matD ordo);

int main(){
    main:
    double **m1, **m2, **res;
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
            note(1); inputHeader(ordo1);
            res = arrDec(ordo1);
            m1 = arrDec(ordo1); m2 = arrDec(ordo1);
            cout << "Matrix 1:\n"; inputMatrix(m1, ordo1);
            cout << "\nMatrix 2:\n"; inputMatrix(m2, ordo1);
            res = addition(m1, m2, ordo1);
            do{
                cout << "\nAre you want to add more matrix to add?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    cout << "\nMatrix " << count << ":\n";
                    inputMatrix(m2, ordo1); count++;
                    res = addition(res, m2, ordo1);
                }
                else{
                    cout << GREEN "\nResult:\n";
                    printMatrix(res, ordo1);
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
            note(2); inputHeader(ordo1);
            res = arrDec(ordo1);
            m1 = arrDec(ordo1); m2 = arrDec(ordo1);
            cout << "Matrix 1:\n"; inputMatrix(m1, ordo1);
            cout << "\nMatrix 2:\n"; inputMatrix(m2, ordo1);
            res = substraction(m1, m2, ordo1);
            do{
                cout << "\nAre you want to add more matrix to substract?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    cout << "\nMatrix " << count << ":\n";
                    inputMatrix(m2, ordo1); count++;
                    res = substraction(res, m2, ordo1);
                }
                else{
                    cout << GREEN "\nResult:\n";
                    printMatrix(res, ordo1);
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
            inputHeader(ordo1); m1 = arrDec(ordo1);
            cout << "Matrix 1:\n"; inputMatrix(m1, ordo1);
            do{
                inputHeader(ordo2);
                if(ordo1.column != ordo2.row)
                    cout << RED "Matrix 1 column and matrix 2 row should be same\n" << WHITE;

            }while(ordo1.column != ordo2.row);

            m2 = arrDec(ordo2);
            cout << "Matrix 2:\n"; inputMatrix(m2, ordo2);
            ordoRes.row = ordo1.row; ordoRes.column = ordo2.column;
            res = arrDec(ordoRes);
            res = multiply(m1, m2, ordo1, ordo2);
            do{
                cout << GREEN "\nResult:\n";
                printMatrix(res, ordoRes);
                cout << WHITE "\nAre you want to add more matrix to multiply?\n";
                do{
                    cout << "Choose[y/n] >> ";
                    cin >> ans;
                }while(ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

                if(ans == 'y' || ans == 'Y'){
                    do{
                        inputHeader(ordo2);
                        if(ordoRes.column != ordo2.row)
                            cout << RED "Matrix result column and matrix " << count << " row should be same\n" << WHITE;

                    }while(ordoRes.column != ordo2.row);
                    cout << "Matrix " << count << ":\n";
                    inputMatrix(m2, ordo2); count++;
                    res = multiply(res, m2, ordoRes, ordo2);
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
            double mul;
            system("cls"); menuHeader(4);
            note(4); inputHeader(ordo1);
            m1 = arrDec(ordo1);
            cout << "Matrix:\n"; inputMatrix(m1, ordo1);
            cout << "\nMultiplier: "; cin >> mul;
            cout << GREEN << "\nResult:\n";
            printMatrix(scalar(m1, ordo1, &mul), ordo1); cout << WHITE;
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
            note(5); inputHeader(ordo1);
            m1 = arrDec(ordo1);
            cout << "Matrix:\n"; inputMatrix(m1, ordo1);
            matD tmp;
            tmp.row = ordo1.column; tmp.column = ordo1.row;
            cout << GREEN << "\nResult:\n";
            printMatrix(transpose(m1, ordo1), tmp); cout << WHITE;
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
            system("cls"); menuHeader(6); note(6);
            do{
                inputHeader(ordo1);
                if(ordo1.row != ordo1.column){
                    cout << RED << "The matrix row and column must be same\n" << WHITE;
                }
            }while(ordo1.row != ordo1.column);
            m1 = arrDec(ordo1);
            cout << "Matrix:\n"; inputMatrix(m1, ordo1);
            cout << GREEN << "\nResult: " << det(m1, ordo1) << WHITE << endl;
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

        case 7:
        system("cls");
        menuHeader(7); note(7);
        switch(chosing()){
            case 1:
            inverse:
            system("cls"); menuHeader(7);
            note(7); inputHeader(ordo1);
            m1 = arrDec(ordo1);
            cout << "Matrix:\n"; inputMatrix(m1, ordo1);
            cout << GREEN << "\nResult:\n";
            printMatrix(inv(m1, ordo1), ordo1); cout << WHITE;
            switch(chosing2()){
                case 1:
                goto inverse;

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

        case 8:
        system("exit");
    }
    return 0;
}

double** arrDec(matD ordo){
    double **array;
    array = new double *[ordo.row];
    for(int i = 0; i < ordo.row; i++){
        array[i] = new double [ordo.column];
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
    cout << "5. Transpose\n" << "6. Determinant\n";
    cout << "7. Inverse\n" << "8. Exit\n";
    do{
        cout << "Choose[1-8] >> ";
        cin >> n;
    }
    while(n > 8 || n < 1);

    return n;
}

void inputMatrix(double **arr, matD ordo){
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            cout << "M[" << i+1 << "][" << j+1 << "] : ";
            cin >> arr[i][j];
        }
    }
}

void printMatrix(double **arr, matD ordo){
    for(int i = 0; i < ordo.row; i++){
        cout << "|";
        for(int j = 0; j < ordo.column; j++){
            cout << setw(5) << setprecision(2) << arr[i][j];
        }
        cout << " |\n";
    }
}

void inputHeader(matD &ordo){
    do{
        cout << endl << "Please input the number of column and row\n";
        cout << "Column : ";
        cin >> ordo.column;
        cout << "Row    : ";
        cin >> ordo.row;
        if(ordo.column <= 0 || ordo.row <= 0){
            cout << RED << "\nColumn and Row number must be postive\n" << WHITE;
        }
    }while(ordo.column <= 0 || ordo.row <= 0);
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

        case 7:
        cout << "======================================" << endl;
        cout << "|           INVERSE MATRIX           |" << endl;
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

        case 7:
        cout << "Note:\n";
        cout << "Inverse of matrix only available for square matrix such as 2x2 or 3x3 matrix.\n"
        << "Inverse of matrix also available if the determinat of the matrix is not equal 0.\n";
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

double** addition(double **arr1, double **arr2, matD ordo){
    double** result;
    result = arrDec(ordo);
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return result;
}

double** substraction(double **arr1, double **arr2, matD ordo){
    double** result;
    result = arrDec(ordo);
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    return result;
}

double** multiply(double **arr1, double **arr2, matD ordo1, matD ordo2){
    double** result;
    matD resOrd;
    resOrd.column = ordo2.column;
    resOrd.row = ordo1.row;
    result = arrDec(resOrd);
    for(int i = 0; i < resOrd.row; i++){
        for(int j = 0; j < resOrd.column; j++){
            result[i][j] = 0;
            for(int k = 0; k < ordo1.column; k++){
                result[i][j] += (arr1[i][k]*arr2[k][j]);
            }
        }
    }
    return result;
}

double** scalar(double **arr, matD ordo, double *k){
    double **result;
    result = arrDec(ordo);
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            result[i][j] = arr[i][j]*(*k);
        }
    }
    return result;
}

double** transpose(double **arr, matD ordo){
    double** result;
    unsigned int tmp;
    tmp = ordo.column;
    ordo.column = ordo.row;
    ordo.row = tmp;
    result = arrDec(ordo);
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            result[i][j] = arr[j][i];
        }
    }
    return result;
}

int det(double **arr, matD ordo){
    int result = 0;
    if(ordo.row == 2){
        result = (arr[0][0]*arr[1][1]) - (arr[0][1]*arr[1][0]);
    }
    else{
        matD ordoTMP;
        ordoTMP.column = ordo.column-1;
        ordoTMP.row = ordo.row-1;
        for(int i = 0; i < ordo.column; i++){
            double** tmp;    
            tmp = arrDec(ordoTMP);
            for(int a = 0; a < ordo.row-1; a++){
                for(int b = 0; b < ordo.column-1; b++){
                    if(b >= i){
						tmp[a][b] = arr[a+1][b+1];
					}
                    else{
						tmp[a][b] = arr[a+1][b];
					}
                }
            }
            result += arr[0][i]*(pow(-1, i)*det(tmp, ordoTMP));
        }    
    }
    return result;
}

double** matrixMinor(double **arr, matD ordo){
    double **result, **tmp;
    result = arrDec(ordo);
    matD ordoTMP;
    ordoTMP.row = ordo.row-1;
    ordoTMP.column = ordo.column-1;
    tmp = arrDec(ordoTMP);
    for(int a = 0; a < ordo.row; a++){
        for(int b = 0; b < ordo.column; b++){
            for(int i = 0; i < ordoTMP.row; i++){
                for(int j = 0;  j < ordoTMP.column; j++){
                    if(i >= a && j >= b){
                        tmp[i][j] = arr[i+1][j+1];
                    }
                    else if(i >= a){
                        tmp[i][j] = arr[i+1][j];
                    }
                    else if(j >= b){
                        tmp[i][j] = arr[i][j+1];
                    }
                    else{
                        tmp[i][j] = arr[i][j];
                    }
                }
            }
            result[a][b] = det(tmp, ordoTMP);
        }
    }
    return result;
}

double** cof(double **arr, matD ordo){
    double** result;
    result = arrDec(ordo);
    for(int i = 0; i < ordo.row; i++){
        for(int j = 0; j < ordo.column; j++){
            result[i][j] = pow(-1, i+j)*arr[i][j];
        }
    }
    return result;
}

double** inv(double **arr, matD ordo){
    double **result, k;
    k = (double) 1/det(arr, ordo);
    result = arrDec(ordo);
    result = matrixMinor(arr, ordo);
    result = cof(result, ordo);
    result = transpose(result, ordo);
    result = scalar(result, ordo, &k);
    return result;
}
