#include <clocale>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;
using namespace chrono;



const int N2 = 100;
const int N3 = 10;
const int mini = -99;
const int maxi = 99;

int TempArr [N2];

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int opora = arr[left + (right - left) / 2];

    while (i <= j) {
        while (arr[i] < opora) i++;
        while (arr[j] > opora) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void bubbleSort(int arr[]) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < (N2-1); i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

void shakerSort(int arr[], int start, int end) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        if (sorted) {
            break;
        }

        end--;

        for (int i = end; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }

        start++;
    }
}

void combSort(int arr[]) {
    int gap = N2;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = int(gap / 1.247);

        if (gap < 1) {gap = 1;}

        swapped = false;
        for (int i = 0; i + gap < N2; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void insertionSort(int arr[]) {
    for (int i = 1; i < N2; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void arrInStdOut(int arr[]) {
    for (int i = 0; i < N2; i++) {
        std::cout << arr[i] << " ";
        if (i % 33 == 0 && i != 0) {std::cout << "\n";}
    }
}

void printMatrix(int* p) {
    for (int i = 0; i < N3; i++) {cout << "--------";}
    cout << "\n\n";

    for (int i = 0; i < N3; i++) {
        for (int j = 0; j < N3; j++)
            cout << *(p + i * N3 + j) << "\t";
        cout << "\n";
    }

    for (int i = 0; i < N3; i++) {cout << "--------";}
    cout << "\n\n";
}

void circleFill(int* p) {
    for (int i = 0; i < N3 * N3; i++) {*(p + i) = 0;}

    int top = 0, bottom = N3 - 1;
    int left = 0, right = N3 - 1;

    while (top <= bottom && left <= right) {

        for (int col = left; col <= right; col++) {
            *(p + top * N3 + col) = rand() % (N3*N3 - 1 + 1) + 1;
        }
        printMatrix(p);
        top++;

        for (int row = top; row <= bottom; row++) {
            *(p + row * N3 + right) = rand() % (N3*N3 - 1 + 1) + 1;
        }
        printMatrix(p);
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                *(p + bottom * N3 + col) = rand() % (N3*N3 - 1 + 1) + 1;
            }
            printMatrix(p);
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                *(p + row * N3 + left) = rand() % (N3*N3 - 1 + 1) + 1;
            }
            if (bottom >= top) {
                printMatrix(p);
            }
            left++;
        }
    }
}

void zmeyaFill(int* p) {
    for (int i = 0; i < N3 * N3; i++) {*(p + i) = 0;}

    for (int col = 0; col < N3; col++) {
        if (col%2 == 0) {
            for (int row = 0; row <= (N3-1); row++) {
                *(p + row*N3 + col) = rand() % (N3*N3 - 1 + 1) + 1;
            }
        }
        else {
            for (int row = (N3-1); row >= 0; row--) {
                *(p + row*N3 + col) = rand() % (N3*N3 - 1 + 1) + 1;
            }
        }
    }
}

void matrixPermutaionA(int* p) {
    for (int row = 0; row <= (N3/2 - 1); row ++) {
        for (int col = 0; col <= (N3/2 - 1); col++) {
            int* A = (p + row*N3 + col);
            int* B = (p + row*N3 + (N3/2 + col));
            int* C = (p + N3*(N3/2 + row) + (col + N3/2));
            int* D = (p + N3*(N3/2 + row) + col);

            int temp = *B;
            *B = *A;
            *A = *D;
            *D = *C;
            *C = temp;
        }
    }
}

void matrixPermutaionB(int* p) {
    for (int row = 0; row <= (N3/2 - 1); row ++) {
        for (int col = 0; col <= (N3/2 - 1); col++) {
            int* A = (p + row*N3 + col);
            int* B = (p + row*N3 + (N3/2 + col));
            int* C = (p + N3*(N3/2 + row) + (col + N3/2));
            int* D = (p + N3*(N3/2 + row) + col);

            int temp = *A;
            *A = *C;
            *C = temp;
            temp = *B;
            *B = *D;
            *D = temp;
        }
    }
}

void matrixPermutaionC(int* p) {
    for (int row = 0; row <= (N3/2 - 1); row ++) {
        for (int col = 0; col <= (N3/2 - 1); col++) {
            int* A = (p + row*N3 + col);
            int* B = (p + row*N3 + (N3/2 + col));
            int* C = (p + N3*(N3/2 + row) + (col + N3/2));
            int* D = (p + N3*(N3/2 + row) + col);

            int temp = *A;
            *A = *D;
            *D = temp;
            temp = *B;
            *B = *C;
            *C = temp;
        }
    }
}

void matrixPermutaionD(int* p) {
    for (int row = 0; row <= (N3/2 - 1); row ++) {
        for (int col = 0; col <= (N3/2 - 1); col++) {
            int* A = (p + row*N3 + col);
            int* B = (p + row*N3 + (N3/2 + col));
            int* C = (p + N3*(N3/2 + row) + (col + N3/2));
            int* D = (p + N3*(N3/2 + row) + col);

            int temp = *A;
            *A = *B;
            *B = temp;
            temp = *C;
            *C = *D;
            *D = temp;
        }
    }
}

void ptrQuickSort(int* left, int* right) {
    int* i = left;
    int* j = right;
    int opora = *(left + (right - left) / 2);

    while (i <= j) {
        while (*i < opora) i++;
        while (*j > opora) j--;

        if (i <= j) {
            swap(*i, *j);
            i++;
            j--;
        }
    }

    if (left < j) ptrQuickSort(left, j);
    if (i < right) ptrQuickSort(i, right);
}

void ptrShakerSort(int* p, int* start, int* end) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int* i = start; i < end; i++) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                sorted = false;
            }
        }

        if (sorted) {
            break;
        }

        end--;

        for (int* i = end; i > start; i--) {
            if (*(i - 1) > *i) {
                swap(*(i - 1), *i);
                sorted = false;
            }
        }

        start++;
    }
}

void ptrCombSort(int* p) {
    int gap = N3*N3;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = int(gap / 1.247);
        if (gap < 1) gap = 1;

        swapped = false;

        for (int* i = p, *j = p + gap; j < p + N3*N3; i++, j++) {
            if (*i > *j) {
                swap(*i, *j);
                swapped = true;
            }
        }
    }
}

void ptrInsertionSort(int* start, int* end) {
    for (int* i = start + 1; i <= end; ++i) {
        int key = *i;
        int* j = i - 1;

        while (j >= start && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

void changeElements(int* p) {
    cout << "Что сделать?\n" << "1. +\n" << "2. -\n" << "3. *\n" << "4. /\n";

    int choice;
    int value;
    cin >> choice;

    cout << "С чем?" << "\n";
    cin >> value;

    int* end = p + N3*N3;

    switch (choice) {
        case 1:
            for (int* i = p; i < end; i++) {
                *i += value;
            }
        break;

        case 2:
            for (int* i = p; i < end; i++) {
                *i -= value;
            }
        break;

        case 3:
            for (int* i = p; i < end; i++) {
                *i *= value;
            }
        break;

        case 4:
            if (value == 0) {
                cout << "Деление на ноль!\n";
                return;
            }
            for (int* i = p; i < end; i++) {
                *i /= value;
            }
        break;
    }
}

void idz17() {
    int matrix[N3*N3];
    int* p = matrix;

    for (int* i = p; i < p + N3*N3; i++) {
        *i = rand() % (100 - 1 + 1) + 1;
    }

    cout << "idz17:\n\n";
    for (int row = 0; row < N3; row++) {
        int rowSum = 0;
        for (int col = 0; col < N3; col++) {
            int value = *(p + row * N3 + col);
            cout << value << "\t";
            rowSum += value;
        }

        cout << "| " << rowSum << "\n";
    }

    for (int i = 0; i < N3; i++) {cout << "--------";}

    cout << "\n";

    for (int col = 0; col < N3; col++) {
        int colSum = 0;
        for (int row = 0; row < N3; row++) {
            colSum += *(p + row * N3 + col);
        }

        cout << colSum << "\t";
    }
    cout << "\n";
}

int searchSubstring(string &text, string &pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            cout << "Позиция: " << i << "\n";
            count++;
        }
    }
    return count;
}

vector<int> computeLps(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

vector<int> kmp(string text, string pattern) {
    vector<int> lps = computeLps(pattern);
    vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) { occurrences.push_back(i - j); j = lps[j - 1]; }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return occurrences;
}

int main() {

    bool escapeLabaChoice = false;
    int Labachoice;

    while(!escapeLabaChoice) {

        cout << "Какой лабу запустить? (5 - выйти)\n";
        cin >> Labachoice;

        switch (Labachoice) {
        




            case 1: {
            setlocale(0, "");
            {
                //17 Создание бесконечности. Установите все биты порядка в 1, а все биты мантиссы — в 0. Знаковый бит оставьте без изменения. Вы получите +inf или -inf.
                union FloatUnion 
                {
                float f;
                unsigned int u;
                };

                std::cout << "ИДЗ\n\nВведите число\n";

                unsigned int inf = 0b1111111100000000000000000000000;
                unsigned int mask = 0b1111111111111111111111111111111;
                FloatUnion value;

                std::cin >> value.f;

                value.u = (value.u & ~mask) | (inf & mask);

                std::cout << "Бесконечность: "<< value.f;
            }


            std::cout << "\n\nЗадание 1\n\n";


            {
                
                std::cout 
                << "int: " << sizeof(int)
                << "\nshort int: " << sizeof(short int) 
                << "\nlong int: " <<  sizeof(long int) 
                << "\nfloat: " << sizeof(float) 
                << "\ndouble: " <<  sizeof(double) 
                << "\nlong double: " << sizeof(long double) 
                << "\nchar: " << sizeof(char) 
                << "\nbool: " << sizeof(bool);
            }


            std::cout << "\n\nЗадание 2\n\n";


            {
                
                std::cout << "Введите целое число\n";

                int value;
                std::cin >> value;

                int order = (sizeof(int) * 8);
                unsigned int mask = 1 << (order - 1);

                std::cout << value << " = ";

                for (int i = 1; i <= order; i++)
                {
                    putchar(value & mask ? '1' : '0');
                    value <<= 1;

                    if (i % 8 == 0 || i % order - 1 == 0)
                    {
                        putchar(' ');
                    }
                }
            }


            std::cout << "\n\nЗадание 3\n\n";


            {
            union FloatUnion 
            {
                float f;
                unsigned int u;
            };


                std::cout << "Введите число типа float\n";

                FloatUnion fu;
                std::cin >> fu.f;

                int order = (sizeof(float) * 8);
                unsigned int mask = 1 << (order - 1);

                std::cout << fu.f << " = ";

                for (int i = 1; i <= order; i++) 
                {
                    putchar(fu.u & mask ? '1' : '0');
                    fu.u <<= 1;

                    if (i == 1 || i == 9) putchar(' ');
                }
            }


            std::cout << "\n\nЗадание 4\n\n";


            {
            union DoubleUnion 
            {
                double d;
                unsigned long long u;
            };


                std::cout << "Введите число типа double\n";

                DoubleUnion du;
                std::cin >> du.d;

                int order = (sizeof(double) * 8);
                unsigned long int mask = 1ULL << (order - 1);

                std::cout << du.d << " = ";

                for (int i = 1; i <= order; i++) 
                {
                    putchar(du.u & mask ? '1' : '0');
                    mask >>= 1;

                    if (i == 1 || i == 12) putchar(' ');
                }
            }


            std::cout << "\n\nЗадание 5\n\n";


            {
                

                union DoubleIntUnion 
                {
                double d;
                unsigned long long u;
                };

                std::cout << "Выберите тип вводимого числа:\n1. Целое\n2. Дробное\n";
                
                int TypeChoice;
                std::cin >> TypeChoice;

                DoubleIntUnion diu;

                if (TypeChoice == 1) 
                {
                    std::cout << "Введите целое число\n";
                    std::cin >> diu.u;

                    int order = (sizeof(long int) * 8);
                    unsigned long long mask = 1ULL << (order - 1);

                    std::cout << diu.u << " = ";

                    for (int i = 1; i <= order; i++)
                    {
                        putchar(diu.u & mask ? '1' : '0');

                        mask >>= 1;

                        if (i % 8 == 0 || i % order - 1 == 0)
                        {
                        putchar(' ');
                        }
                    }

                    std::cout << "\n\nКакой бит изменить? (считая справа)\n";
                    
                    int BitChoice;
                    std::cin >> BitChoice;

                    mask = 1;

                    diu.u = diu.u ^ (mask << BitChoice);

                    std::cout << diu.u << " = ";

                    mask = 1ULL << (order - 1);

                    for (int i = 1; i <= order; i++)
                    {
                        putchar(diu.u & mask ? '1' : '0');

                        mask >>= 1;

                        if (i % 8 == 0 || i % order - 1 == 0)
                        {
                        putchar(' ');
                        }
                    }
                }

                if (TypeChoice == 2) 
                {
                    std::cout << "Введите дробное число\n";
                    std::cin >> diu.d;

                    int order = (sizeof(double) * 8);
                    unsigned long long mask = 1ULL << (order - 1);

                    std::cout << diu.d << " = ";

                    for (int i = 1; i <= order; i++) 
                    {
                        putchar(diu.u & mask ? '1' : '0');
                        mask >>= 1;

                        if (i == 1 || i == 12) putchar(' ');
                    }

                    std::cout << "\nКакой бит изменить? (считая справа)\n";
                    
                    int BitChoice;
                    std::cin >> BitChoice;

                    mask = 1;

                    diu.u = diu.u ^ (mask << BitChoice);

                    std::cout << diu.d << " = ";

                    mask = 1ULL << (order - 1);

                    for (int i = 1; i <= order; i++)
                    {
                        putchar(diu.u & mask ? '1' : '0');

                        mask >>= 1;

                        if (i == 1 || i == 12)
                        {
                        putchar(' ');
                        }
                    }
                }
                std::cout << "\n";
            }
            break;
            }





            case 2: {
                setlocale(0, "");

                bool escape = false;
                int arr [N2] = {0};
                srand(time(NULL));
                for (int i = 0; i < N2; i++) {arr[i] = rand() % (maxi - mini + 1) + mini;}



                while (!escape) {

                    for (int i = 0; i < N2; i++) {TempArr[i] = arr[i];}

                    std::cout << "Текущий массив: " << "\n";
                    arrInStdOut(arr);



                    std::cout << "\n" << "ИДЗ №17 для текущего массива: ";

                    //ИДЗ №17 (Найти моду массива, если таких значений несколько, то вывести все. Подсчитать время поиска)


                    quickSort(TempArr, 0, int (N2-1));


                    auto start = steady_clock::now();

                    const int countArrSize = maxi + (mini < 0 ? -mini : mini) + 1;

                    int countArr [countArrSize] = {0};

                    for (int i = 0; i < N2; i++) {
                        countArr[arr[i] + abs(mini)]++;
                    }

                    int resultArr [N2] = {0};
                    int quantityOfMods = 0;
                    int max = 0;

                    for (int i = 0; i < countArrSize; i++) {
                        if (countArr[i] > max) {
                            quantityOfMods = 0;
                            resultArr[quantityOfMods] = (i - maxi);
                            quantityOfMods++;

                            max = countArr[i];
                        }

                        else if (countArr[i] == max) {
                            resultArr[quantityOfMods] = (i - maxi);
                            quantityOfMods++;
                        }
                    }


                    auto end = steady_clock::now();
                    auto result = duration_cast<nanoseconds>(end-start);


                    for (int i = 0; i < quantityOfMods; i++) {
                        std::cout << resultArr[i] << " ";
                    }

                    std::cout << "\n" << "Время затраченное на нахождение мода: " << result.count() << " " << "наносекунд" << "\n\n";



                    std::cout << "\n\n"
                    << "1. Сгенерировать новый массив из ста целых чисел" << "\n"
                    << "2. Отсортировать массив" << "\n"
                    << "3. Найти максимальный и минимальный элемент массива" << "\n"
                    << "4. Найти среднее значение максимального и минимального элемента, индексы элементов в массиве равные среднему занчению и их количество в отсортированном и неотсортированном массиве" << "\n"
                    << "5. Найти количество элементов меньше заданного числа в отсортированном массиве" << "\n"
                    << "6. Найти количество элементов больше заданного числа в отсортированном массиве" << "\n"
                    << "7. Проверка наличия произвольного элемента в массиве" << "\n"
                    << "8. Поменять местами произвольные элементы массива" << "\n"
                    << "9. Готово!" << "\n";

                    int choice;
                    std::cin >> choice;
                    std::cin.ignore();
                    std::cout << "\n\n\n\n\n\n\n";

                    switch (choice) {
                        case 1:
                            for (int i = 0; i   <  N2; i++) {arr[i] = rand() % (maxi - mini + 1) + mini;}
                        break;






                        case 2: {
                            auto start0 = steady_clock::now();


                            bubbleSort(TempArr);


                            auto end0 = steady_clock::now();
                            auto result0 = duration_cast<nanoseconds>(end0-start0);


                            std::cout << "Время затраченное на сортировку пузырьком: " << result.count() << " " << "наносекунд" << "\n";
                            for (int i = 0; i < N2; i++) {TempArr[i] = arr[i];}

                            
                            auto start1 = steady_clock::now();


                            shakerSort(TempArr, 0, int (N2-1));


                            auto end1 = steady_clock::now();
                            auto result1 = duration_cast<nanoseconds>(end1-start1);
                            
                            
                            std::cout << "Время затраченное на шейкерную сортировку: " << result1.count() << " " << "наносекунд" << "\n";
                            for (int i = 0; i < N2; i++) {TempArr[i] = arr[i];}


                            auto start2 = steady_clock::now();


                            combSort(TempArr);


                            auto end2 = steady_clock::now();
                            auto result2 = duration_cast<nanoseconds>(end2-start2);


                            std::cout << "Время затраченное на сортировку рассчёсткой: " << result2.count() << " " << "наносекунд" << "\n";
                            for (int i = 0; i < N2; i++) {TempArr[i] = arr[i];}


                            auto start3 = steady_clock::now();


                            insertionSort(TempArr);


                            auto end3 = steady_clock::now();
                            auto result3 = duration_cast<nanoseconds>(end3-start3);


                            std::cout << "Время затраченное на сортировку вставками: " << result3.count() << " " << "наносекунд" << "\n";
                            for (int i = 0; i < N2; i++) {TempArr[i] = arr[i];}


                            auto start4 = steady_clock::now();


                            quickSort(TempArr, 0, int (N2-1));


                            auto end4 = steady_clock::now();
                            auto result4 = duration_cast<nanoseconds>(end4-start4);


                            std::cout << "Время затраченное на сортировку quicksort: " << result4.count() << " " << "наносекунд" << "\n";


                            std::cout << "\n\n" << "Отсортированный массив: " << "\n";


                            arrInStdOut(TempArr);



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 3: {

                            quickSort(TempArr, 0, int (N2-1));
                            int max = mini;
                            int min = maxi;


                            auto start1 = steady_clock::now();


                            for (int i = 0; i < N2; i++) {
                                if (arr[i] < min) {min = arr[i];}
                                if (arr[i] > max) {max = arr[i];}
                            }


                            auto end1 = steady_clock::now();
                            auto unsortedResult = duration_cast<nanoseconds>(end1 - start1);


                            auto start2 = steady_clock::now();


                            min = TempArr[0];
                            max = TempArr[N2-1];


                            auto end2 = steady_clock::now();
                            auto sortedResult = duration_cast<nanoseconds>(end2 - start2);


                            std::cout << "Максимальный элемент: " << max << "\n"
                            << "Минимальный элемент: " << min << "\n\n"
                            << "Время затраченное на поиск элементов в неотсортированном массиве: " << unsortedResult.count() << "наносекунд" << "\n"
                            << "Время затраченное на поиск элементов в отсортированном массиве: " << sortedResult.count() << "наносекунд" << "\n";



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 4: {

                            quickSort(TempArr, 0, int (N2-1));
                            int max = mini;
                            int min = maxi;
                            int avg;
                            int k = 0;


                            auto start1 = steady_clock::now();

                            for (int i = 0; i < N2; i++) {
                                if (arr[i] < min) {min = arr[i];}
                                if (arr[i] > max) {max = arr[i];}
                            }

                            avg = round((max + min) / 2.0);

                            std::cout << "Неотсортированный массив" << "\n\n"
                            << "Среднее значение максимального и минимального элементов: " << avg << "\n"
                            << "Индексы элементов равные среднему значению: ";

                            bool found = false;
                            for (int i = 0; i < N2; i++) {
                                if (arr[i] == avg) {
                                    found = true;
                                    std::cout << i << " ";
                                    k++;
                                }
                            }

                            if (found == false) {std::cout << "индексы не найдены";}

                            std::cout << "\nКоличество элементов равных среднему значению: " << k << "\n";


                            auto end1 = steady_clock::now();
                            auto unsortedResult = duration_cast<nanoseconds>(end1 - start1);

                            std::cout << "Время затраченное на поиск среднего значения, индексов элементов равных среднему значению в неотсортированном массиве: " << unsortedResult.count()
                            << "\n\n\n";



                            k = 0;

                            quickSort(TempArr, 0, int (N2-1));


                            auto start2 = steady_clock::now();


                            min = TempArr[0];
                            max = TempArr[N2-1];
                            avg = round((max + min) / 2.0);

                            std::cout << "Отсортированный массив" << "\n\n"
                            << "Среднее значение максимального и минимального элементов: " << avg << "\n"
                            << "Индексы элементов равные среднему значению: ";

                            int left = 0;
                            int right = N2-1;
                            int mid;
                            found = false;

                            while (left <= right) {
                                mid = left + (right - left) / 2;

                                if (TempArr[mid] == avg) {
                                    found = true;
                                    std::cout << mid << " ";
                                    k++;

                                    int i = mid - 1;
                                    while (i >= 0 && TempArr[i] == avg) {
                                        std::cout << i << " ";
                                        k++;
                                        i--;
                                    }

                                    i = mid + 1;
                                    while (i < N2 && TempArr[i] == avg) {
                                        std::cout << i << " ";
                                        k++;
                                        i++;
                                    }
                                    break;
                                }
                                if (TempArr[mid] < avg) {
                                    left = mid + 1;
                                }
                                else {
                                    right = mid - 1;
                                }
                            }

                            if (!found) {std::cout << "индексы не найдены";}

                            std::cout << "\nКоличество элементов равных среднему значению: " << k << "\n";


                            auto end2 = steady_clock::now();
                            auto sortedResult = duration_cast<nanoseconds>(end2 - start2);


                            std::cout << "Время затраченное на поиск среднего значения, индексов элементов равных среднему значению в отсортированном массиве: " << sortedResult.count() << "\n";



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 5: {
                            int a;
                            std::cout << "Введите целое число..." << "\n";
                            std::cin >> a;
                            std::cin.ignore();



                            quickSort(TempArr, 0, int (N2-1));

                            int k = 0;

                            for (int i = 0; i < N2; i++) {
                                if (TempArr[i] >= a) {
                                    break;
                                }
                                k++;
                                
                            }

                            std::cout << "Количество элементов меньше заданного числа: " << k << "\n";



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 6: {
                            int b;
                            std::cout << "Введите целое число..." << "\n";
                            std::cin >> b;
                            std::cin.ignore();



                            quickSort(TempArr, 0, int (N2-1));

                            int k = 0;

                            for (int i = (N2-1); i >= 0; i--) {
                                if (TempArr[i] <= b) {
                                    break;
                                }
                                k++;
                            }
                            

                            std::cout << "Количество элементов больше заданного числа: " << k << "\n";



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 7: {
                            int number;
                            std::cout << "Введите целое число..." << "\n";
                            std::cin >> number;
                            std::cin.ignore();



                            quickSort(TempArr, 0, int (N2-1));


                            auto start1 = steady_clock::now();


                            int left = 0;
                            int right = N2-1;
                            int mid;
                            bool found = false;

                            while (left <= right) {
                                mid = left + (right - left) / 2;

                                if (TempArr[mid] == number) {
                                    found = true;
                                    break;
                                }
                                if (TempArr[mid] < number) {
                                    left = mid + 1;
                                }
                                else {
                                    right = mid - 1;
                                }
                            }


                            auto end1 = steady_clock::now();
                            auto binaryResult = duration_cast<nanoseconds>(end1 - start1);

                            std::cout << "Время затраченное на поиск бинарным поиском: " << binaryResult.count() << "\n";



                            auto start2 = steady_clock::now();


                            for (int i = 0; i < N2; i++) {
                                if (TempArr[i] == number) {
                                    break;
                                }
                            }


                            auto end2 = steady_clock::now();
                            auto notBinaryResult = duration_cast<nanoseconds>(end2 - start2);


                            std::cout << "Время затраченное на поиск перебором: " << notBinaryResult.count() << "\n";
                            cout << (found ? "Элемент найден\n" : "Элемент не найден\n");



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }





                        case 8: {
                            int firstNumber, secondNumber;

                            std::cout << "Введите индекс первого элемента" << "\n";
                            std::cin >> firstNumber;

                            std::cout << "Введите индекс второго элемента" << "\n";
                            std::cin >> secondNumber;

                            std::cin.ignore();



                            if ((0 <= firstNumber && firstNumber <= (N2-1)) && (0 <= secondNumber && secondNumber <= (N2-1))) {
                                auto start = steady_clock::now();


                                swap(TempArr[firstNumber], TempArr[secondNumber]);


                                auto end = steady_clock::now();
                                auto result = duration_cast<nanoseconds>(end - start);


                                std::cout << "Время затраченное на обмен: " << result.count() << "\n";

                                std::cout << "Массив после обмена: " << "\n";

                                arrInStdOut(TempArr);
                            }
                            else {
                                std::cout << "Индексы выходят за пределы массива";
                            }



                            std::cin.get();
                            std::cout << "\n\n\n\n\n\n\n";
                        break;
                        }
                        case 9:
                            escape = true;
                        break;
                    }
                }
            break;
            }





            case 3: {
                srand(time(nullptr));

                int matrix[N3*N3];
                int* p = matrix;

                idz17();

                zmeyaFill(p);
                printMatrix(p);

                matrixPermutaionA(p);
                printMatrix(p);

                ptrQuickSort(p, (p + N3*N3-1));
                printMatrix(p);

                changeElements(p);
                printMatrix(p);
            break;
            }





            case 4: {
                cout << "Выберите способ ввода:\n1 - с клавиатуры\n2 - из файла\n> ";
                int choice;
                cin >> choice;
                cin.ignore();

                string input;
                if (choice == 1) {
                    cout << "Введите строку:\n";
                    getline(cin, input);
                } else if (choice == 2) {
                    ifstream file("input.txt");
                    if (!file) { cout << "Файл input.txt не найден\n"; return 1; }
                    getline(file, input);
                    file.close();
                } else { 
                    cout << "Неверный выбор\n"; return 1; 
                }

                if (input.empty() || input.back() != '.') {
                    cout << "Ошибка: строка должна заканчиваться точкой\n";
                    return 1;
                }

                cout << "\nКоличество символов в каждом слове исходной последовательности:\n";
                istringstream issInput(input);
                vector<string> originalWords;
                string word;
                while (issInput >> word) {
                    cout << word << ": " << word.length() << "\n";
                    originalWords.push_back(word);
                }

                if (originalWords.size() < 1 || originalWords.size() > 50) {
                    cout << "Ошибка: количество слов должно быть от 1 до 50\n";
                    return 1;
                }
                for (int i = 0; i < originalWords.size(); i++) {
                    if (originalWords[i].length() < 1 || originalWords[i].length() > 10) {
                        cout << "Ошибка: длина слова \"" << originalWords[i] << "\" должна быть от 1 до 10 символов\n";
                        return 1;
                    }
                }

                string edited;
                int i = 0;
                while (i < input.length()) {
                    char c = input[i];

                    if (c == '.' && i + 2 < input.length() && input[i+1] == '.' && input[i+2] == '.') {
                        if (!edited.empty() && edited.back() == ' ') {
                            edited.pop_back();
                        }
                        edited += "...";
                        i += 3;
                        continue;
                    }

                    if (isspace(c)) {
                        if (!edited.empty() && edited.back() != ' ') {
                            edited += ' ';
                        }
                        i++;
                        continue;
                    }

                    if (ispunct(c)) {
                        if (!edited.empty() && ispunct(edited.back())) {
                            i++;
                            continue;
                        } else {
                            edited += c;
                            i++;
                            continue;
                        }
                    }

                    edited += tolower(c);
                    i++;
                }

                if (edited.size() >= 2 && edited[edited.size()-2] == ' ' && edited.back() == '.') {
                    edited.erase(edited.size()-2, 1);
                }

                cout << "\nОтредактированный текст:\n" << edited << "\n";


                vector<string> words;
                istringstream issEdited(edited);
                while (issEdited >> word) {
                    words.push_back(word);
                }

                cout << "\nСлова в обратном порядке:\n";
                for (int i = words.size()-1; i >= 0; i--) {
                    cout << words[i] << " ";
                }
                cout << "\n";

                vector<string> sortedWords = words;
                sort(sortedWords.begin(), sortedWords.end());
                cout << "\nСлова в алфавитном порядке:\n";
                for (int i = 0; i < sortedWords.size(); i++) {
                    cout << sortedWords[i] << " ";
                }
                cout << "\n";

                cout << "\nСлова вертикально:\n";
                for (int i = 0; i < words.size(); i++) {
                    cout << words[i] << "\n";
                }

                string pattern;
                cout << "\nВведите подстроку для поиска:\n> ";
                getline(cin, pattern);
                for (int i = 0; i < pattern.length(); i++) {
                    pattern[i] = tolower(pattern[i]);
                }

                cout << "\nЛинейный поиск:\n";
                int linearCount = searchSubstring(edited, pattern);
                cout << "Найдено " << linearCount << " вхождений.\n";

                vector<int> kmpPositions = kmp(edited, pattern);
                cout << "\nKMP поиск: найдено " << kmpPositions.size() << " вхождений.\n";
                for (int i = 0; i < kmpPositions.size(); i++) {
                    cout << "Позиция: " << kmpPositions[i] << "\n";
                }
            break;
            }






            case 5: {
                escapeLabaChoice = true;
            break;
            }
        }
    }
}