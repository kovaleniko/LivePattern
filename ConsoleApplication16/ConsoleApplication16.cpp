// ConsoleApplication16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <time.h>
#include <iostream>
using namespace std;
inline double multy(int x, int y, int z) {
    return x * y * z;
    //1.нет циклов
    //2.не рекурсивная
    //3.не слишком большая
}
inline int Less(int x, int y) {
    return x < y ? x : y;
}
#define Print(X) cout<<"macros "<<X<<endl;

inline void print() {
    cout << "inline function " << __func__ << endl;
}

void cube(int x) {
    cout << "x^3 =" << x * x * x << endl;
}

double cube_ret(int x) {
    double y = 1;
    y *= x * x * x;
    return y;
}

void print_int(int m[], int size);
void new_value(int abc[], int s);
void init_mas(int mas[][10],int row,int col);
void print_mas(int mas[][10], int row, int col);
//void f(int mas[][10][10]);
int find_max(int name[][10], int row, int col);
int summa(int mas[][10], int row, int col);

void sorting(int mas[][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int k = 0; k < col; ++k) {
            for (int j = 0; j < col - 1; ++j) {
                if (mas[i][j] < mas[i][j + 1]) {
                    int a = mas[i][j + 1];
                    mas[i][j + 1] = mas[i][j];
                    mas[i][j] = a;
                }
            }
        }
    }
}

int summa_values(int a, int b, int c = 3) {
    return a + b + c;
}
//type=0 - заполняем любыми от 0 до 255;
//1- латиница заглавные, 2- строчные, 3 - цифры 
void init_char(char S[], int size, int type = 0);
void print_char(char S[], int size);
int pos_min_max(char S[], int size, bool min_max = true) {
    int min_pos = 0, max_pos = 0;
    for (int i = 0; i < size; ++i)
    {
        if (S[min_pos] > S[i])
            min_pos = i;
        if (S[max_pos] > S[i])
            max_pos = i;
    }
    return min_max ? max_pos : min_pos;
}
double  stepen(int value, int pokazatel = 2) {
    double itog = 1;
    for (; pokazatel--;)
        itog *= value;
    return itog;
}
#define Multy(x,y) (x)*(y)
inline int mult(int x, int y) {
    return x * y;
}
//2 макроса: нахождение квадрата числа, определение максимального из 2 значений
//2 inline функции: деление 2 чисел, определение максимального из 3 значений
//написать функцию сортировки для массива символов определенную прототипом
//void sort_char(char S[], int size, bool how=false)
//по умолчанию сортировка по возрастанию, если how =true по убыванию

//для двумерного массива чисел создать функцию по умолчанию определяет количество 
//четных значений, иначе нечетных
#define Sq(x) (x)*(x)
#define Max(x,y) (  (x)<(y)?(x):(y)  )
void sort_char(int S[], int size, bool how = false) {
    {
        for (int i = 0; i < size - 1; i++) {

            for (int j = 0; j < size - 1; j++) {
                int x = S[j];

                if (S[j] > S[j + 1]) {
                    S[j] = S[j + 1];
                    S[j + 1] = x;
                }
            }
        }
    }
}
int main()
{
    print();
    Print(1);
    cout << Multy(2, 4) << " " << Multy(3 + 1, 2) << endl;
    //2*4                           3+1*2
    cout << mult(2, 4) << " " << mult(3 + 1, 2) << endl;
    cout << Sq(1) << endl;
    //cout << "3 " << summa_values(10, 11, 12) << " 2 " <<
    //                summa_values(1, 2) << endl;
    //char sim1[10], sim2[10], sim3[10];
    //cout << "all simbols\n";
    //init_char(sim1, 10);
    //print_char(sim1, 10);
    //cout << "all litters\n";
    //init_char(sim2, 10,1);
    //print_char(sim2, 10);
    //cout << "numbers \n";
    //init_char(sim3, 10, 3);
    //print_char(sim3, 10);

    //int Max = pos_min_max(sim2, 10);
    //cout << "max " << pos_min_max(sim2, 10) << " value " << sim2[Max] << endl;
    //int Min = pos_min_max(sim2, 10, false);
    //cout << "min " << sim2[Min] << "on position " << Min << endl;
    //cout << "4^2 " << stepen(4) << "  4^7 " << stepen(4, 7) << endl;
    
    //cube(3);
    //int x = 5;
    //cube(x);
    //x = cube_ret(x);
    //cout << "7*7*7 =" << cube_ret(7) << endl;
    //int massive[20];
    //new_value(massive, 20);
    //print_int(massive, 10);
    //int arr[10][10];
    //init_mas(arr, 10, 10);
    //print_mas(arr, 10, 10);
    //cout << "max " << find_max(arr, 10, 10);
    //cout << "  summa elem " << summa(arr, 10, 10) << endl;
    //int other[20][10];
    //init_mas(other, 20, 10);
    //print_mas(other, 20, 10);
    ////вызовите функции find_max, summa  и сортировки для массива other
    //sorting(arr, 10, 10);
    //print_mas(arr, 10, 10);
    ////создать функцию поиска значения для двумерного массива(если числа нет возвращать 0,
    ////если есть - количество таких значений в массиве)
}

void init_char(char S[], int size, int type) {
    for (int i = 0; i < size; ++i) {
        if (type == 0)
            S[i] = rand() % 256;
        else if (type == 1)
            S[i] = rand() % 26 + 'A';
        else if (type == 2)
            S[i] = rand() % 26 + 'a';
        else
            S[i] = rand() % 10 + '0';
    }
}
void print_char(char S[], int size) {
    for (int i = 0; i < size; ++i)
        cout << S[i] << " ";
    cout << endl;
}


void print_int(int m[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << m[i] << " ";
    }
    cout << endl;
}
void new_value(int abc[], int s) {
    for (int i = 0; i < s; ++i) {
        abc[i] = rand() % 100;
    }
}
void init_mas(int mas[][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mas[i][j] = rand() % 90 + 10;
        }
    }
}
void print_mas(int mas[][10], int row, int col) {
    cout << "array 2D\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout<<mas[i][j] <<" ";
        }
        cout << endl;
    }
}

int find_max(int name[][10], int row, int col)
{
    int max = name[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (name[i][j] > max)
                max = name[i][j];
        }
    }
    return max;
}
int summa(int name[][10], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum += name[i][j];
        }
    }
    return sum;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
