#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "russian");  
    int size;
    int mass[7];
    int** matrix;
    int newrows = 0;
    bool trueorfalse;


    std::ifstream file ("input.txt");
    if (file.is_open() == 0)
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
        return 0;
    }
    file >> size;
    
    matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
   



    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];

        }

    }
    mass[0] = 1;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[newrows][j] == 1  ) {
                for (int k = 0; k < i; ++k) {
                    if (j + 1 == mass[k]) {
                        trueorfalse = false;
                        break;
                    }
                    else  trueorfalse = true;
                }
                if (trueorfalse) {
                    newrows = j;
                    mass[i] = j + 1;
                    break;
                }
            }
        }

    }

    std::cout << "Порядок обхода вершин: ";
    for (int i = 0; i < size; ++i) {
        std::cout << mass[i] << ' ';
    }
    return 0;
}

