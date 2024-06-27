#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 10;
    fstream   file;
    int       numbersOut[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int       numbersIn[SIZE];
    file.open("numbers.dat", ios::out | ios::binary);

    cout << "Writing the data to the file.\n";
    file.write((char *)numbersOut, sizeof(numbersOut));
    file.close();
    file.open("numbers.dat", ios::in | ios::binary);

    cout << "Now reading the data back into memory.\n";
    file.read((char *)numbersIn, sizeof(numbersIn));
    for (int count = 0; count < SIZE; count++)
        cout << numbersIn[count] << " ";

    cout << endl;
    file.close();
    return 0;
}