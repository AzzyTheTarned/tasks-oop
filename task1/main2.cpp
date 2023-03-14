#include <iostream>
#include <cmath>
using namespace std;

const int n = 5;   // ВВОД РАЗМЕРНОСТИ МАТРИЦЫ
const int x = n, y = n;

int getLeastNum (int** _array) {
    int least = _array[0][0];
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            if (_array[p][q] < least) {
                least = _array[p][q];
            }
        }
    }
    return least;
}

int getPositiveSum (int** _array) {
    int sum = 0;
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            if (_array[p][q] > 0) {
                sum += _array[p][q];
            }
        }
    }
    return sum;
}

bool isPrime(int num)
{
    if (num <= 0) return false;
    for (int i = 2; i<=sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int getNumberOfPrimesOnDiags(int** _array) {
    int count = 0;
    int i = 0,j = 0;
    while (i < n && j < n) {
        if (isPrime(_array[i][j])) count++;
        if (isPrime(_array[i][n-j-1])) count++;
        i++; j++;
    }
    return count;
}

int main() {
    int** array = (int**) alloca (sizeof (int*) * x);
    for (int i = 0; i < x; i++) {
        array [i] = (int*) alloca (sizeof (int) * y);
    }
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            array[p][q] = rand() % 200 - 100;
            cout << array[p][q];
            if (q == n-1) {
                cout << endl;
            }
            else {
                cout << " ";
            }
        }
    }
    cout << endl << getLeastNum(array);
    cout << endl << getPositiveSum(array);
    cout << endl << getNumberOfPrimesOnDiags(array);
}