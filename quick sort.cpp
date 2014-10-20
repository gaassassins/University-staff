#include <iostream>
#include <ctime>
using namespace std;
const int n=7;
int first, last;

//функция сортировки
void quicksort(int *mas, int first, int last)
{

int mid, count;
int f=first, l=last;
mid=mas[(f+l) / 2]; //вычисление опорного элемента

do
{
while (mas[f]<mid) f++;
while (mas[l]>mid) l--;
if (f<=l) //перестановка элементов
{
count=mas[f];
mas[f]=mas[l];
mas[l]=count;
f++;
l--;
}
} while (f<l);
if (first<l) quicksort(mas, first, l);
if (f<last) quicksort(mas, f, last);
}

//главная функция
void main()
{

clock_t time;

int number;
cout « "Vvedite razmernost:";
cin » number;
int *A=new int[number];

cout«"Input mas: ";
for (int i=0; i<number; i++)

{
A[i]=rand()%1000;
cout«A[i]«" ";
}

time = clock();
first=0; last=n-1;

quicksort(A, first, last);
cout«endl«"Output mas: ";
for (int i=0; i<number; i++) cout«A[i]«" ";
time = clock() - time;
cout«endl;
cout « "Time:"; 
printf("%f", (double)time / CLOCKS_PER_SEC);
cout«endl;

delete []A;
system("pause");
}