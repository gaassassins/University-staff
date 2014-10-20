#include <iostream>
#include <ctime>

using namespace std;

void downHeap(int a[], long k, long n)
{
// процедура просеивания следующего элемента 
int new_elem;
long child;
new_elem = a[k];

while (k <= n / 2) 
{
child = 2 * k;

if ((child < n) && (a[child] < a[child + 1]))
child++;
if (new_elem >= a[child])
break;
// иначе 
a[k] = a[child]; // переносим сына наверх 
k = child;
}
a[k] = new_elem;
}

void heapSort(int a[], long size)
{
long i;
int temp;

// строим пирамиду 
for (i = size / 2 - 1; i >= 0; —i)
downHeap(a, i, size - 1);

// теперь a[0]...a[size-1] пирамида 

for (i = size - 1; i > 0; —i)
{

temp = a[i];
a[i] = a[0];
a[0] = temp;
// восстанавливаем пирамидальность a[0]...a[i-1] 
downHeap(a, 0, i - 1);
}
}

//главная функция
void main()
{
setlocale(LC_ALL, "Rus");
clock_t time;

int number;

cout « "Введите размерность: ";
cin » number;

int *A = new int[number];
cout « "Входящий массив: ";
for (int i = 0; i<number; i++)
{
A[i] = rand() % 1000;
cout « A[i] « " ";
}

time = clock();

heapSort(A, number);
cout « endl « "Исходящий массив: ";

for (int i = 0; i<number; i++)
cout « A[i] « " ";

time = clock() - time;
cout « endl;

cout « "Time:";
printf("%f", (double)time / CLOCKS_PER_SEC);
cout « endl;

delete[]A;
system("pause");
}