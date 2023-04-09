#include "header.h"

int main() {
    ofstream file;
    file.open("Bad.csv");
    int** a = new int* [8];
    file << "크기,퀵정렬(QuickSort),병합정렬(MergeSort)\n";
    for (int i = 0; i <= 8; i++)
    {
        file << i+i << ",";
        a[i] = new int[i+2];
        BadSetting(&(a[i]));
        file << QuickSort(&(a[i])) << ",";
        BadSetting(&(a[i]));
        file << MergeSort(&(a[i])) << "\n";
    }
    for (int i = 0; i <= 8; i++)
        delete[] a[i];
    file.close();
    return 0;
}
