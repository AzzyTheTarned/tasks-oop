#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    if (num <= 0) return false;
    for (int i = 2; i<=sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

struct Matrix {
private:
    int size;
public:
    vector<vector<int>> array;

    Matrix(int _size, bool _doInit = true) : size(_size) {
        array.resize(size);
        for (int i = 0; i < size; i++) {
            array[i].resize(size);
        }
        if (_doInit) {
            for (int n = 0; n < size; n++) {
                for (int m = 0; m < size; m++) {
                    array[n][m] = rand() % 200 - 100;
                }
            }
        }
    }

    void print() {
        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                cout << array[n][m];
                if (m == size-1) {
                    cout << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }

    int getLeastNum() {
        int least = array[0][0];
        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                if (array[n][m] < least) {
                    least = array[n][m];
                }
            }
        }
        return least;
    }

    int getPositiveSum() {
        int sum = 0;
        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                if (array[n][m] > 0) {
                    sum += array[n][m];
                }
            }
        }
        return sum;
    }

    int getNumberOfPrimesOnDiags() {
        int count = 0;
        int i = 0, j = 0;
        while (i < size && j < size) {
            if (isPrime(array[i][j])) count++;
            if (isPrime(array[i][size-j-1])) count++;
            i++; j++;
        }
        return count;
    }

    Matrix getTranspose() {
        Matrix buff(size, false);
        for (int n = 0; n < size; n++) {
            for (int m = 0; m < size; m++) {
                buff.array[n][m] = array[m][n];
            }
        }
        return buff;
    }
};

int main() {
    srand(time(nullptr));
    int size_of_matrix;
    cout << "Enter the size of matrix: ";
    cin >> size_of_matrix;
    cout << endl;
    Matrix a(size_of_matrix), c(size_of_matrix), b(size_of_matrix, false);
    a.print();
    cout << "The least element: " << a.getLeastNum() << endl;
    cout << "Sum of positive numbers: " << a.getPositiveSum() << endl;
    cout << "Number of primes on diagonals: " << a.getNumberOfPrimesOnDiags() << endl;

    for (int n = 0; n < size_of_matrix; n++) {
        for (int m = 0; m < size_of_matrix; m++) {
            b.array[n][m] = a.array[n][m] * 2 + c.getTranspose().array[n][m];
        }
    }
    b.print();
    return 0;
}