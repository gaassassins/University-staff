#include <cstdlib>
#include <iostream>
#include <string>

#define ALPHABET_LEN 255  // длинна алфавита
#define NOT_FOUND patlen // когда не нашли в таблице стоп-символов расстояние С
#define max(a, b) ((a < b) ? b : a) 

using namespace std;

void make_delta1 (int *delta1, char *pat, long int patlen) // таблица стоп-символов
{
	int i;
	for (i=0; i < ALPHABET_LEN; i++) 
		delta1[i] = NOT_FOUND; // нет совпадений
	for (i=0; i < patlen-1; i++) 
		delta1[pat[i]] = patlen-1-i; // сдвижение шаблона на i символов вправо
}

int is_prefix (char *word, int wordlen, int pos) // функция префикс функции
{
	int suffixlen = wordlen - pos; // если окончание слова начиная с word[pos] является префиксом функции, то это истина
	for (int i = 0; i<suffixlen; i++) 
	{
		if (word[i] != word[pos+i]) return 0;
	}
	return 1;
}
int suffix_length (char *word, int wordlen, int pos) //  Длина наибольшего окончания слова, заканчивающегося на word[pos]
{
	int i;
	for (i = 0; (word[pos-i] == word[wordlen-1-i]) && (i < pos); i++); // Увеличиваем длину суффикса i до первого расхождения или начала слова
	return i;
}

void make_delta2(int *delta2, char *pat, long int patlen) // таблица суффиксов
{
	int last_prefix_index = patlen-1;
	int p;
	for (p=patlen-1; p>=0; p--) // От pat[pos+1] до pat[patlen-1] не содержится ничего из шаблона,
	{
		if (is_prefix(pat, patlen, p+1)) last_prefix_index = p+1; // Если подстрока pat[pos+1 .. patlen-1], содержит начало шаблона 
		delta2[p] = last_prefix_index + (patlen-1 - p); // следующее возможное вхождение найдено
	}
	for (p=0; p < patlen-1; p++) // Символы от pat[pos+1] до pat[patlen-1] содержатся в шаблоне.
	{
		int slen = suffix_length(pat, patlen, p);
		if (pat[p-slen]!=pat[patlen-1-slen]) 
			delta2[patlen-1-slen]=patlen-1-p+slen;
	}
}

int boyer_moore (char *string, char *pat) 
{
	long int stringlen = strlen(string); // возвращает длину строки 
	long int patlen =strlen(pat); // возвращает длинну шаблона
	int delta1[ALPHABET_LEN]; // алфавит символов
	make_delta1(delta1, pat, patlen); // таблица стоп-символов
	int *delta2 = new int [patlen * sizeof(int)]; // создается массив для таблицы суффиксов
	make_delta2(delta2, pat, patlen); // таблица суффиксов
	
	int i = patlen-1;
	while (i < stringlen) 
	{	
		int j = patlen-1;
		while (j >= 0 && (string[i] == pat[j])) 
		{
			--i; --j;
		}
		
		if (j < 0) 
		{
			delete delta2;
			return i+2;
		}

		i += max(delta1[string[i]], delta2[j]); // выбирается итоговые значения (подстроки) из двух функцией
		
		
	}

	delete delta2;
	return 0;
}

int main(char *string, char *pat)
{	
	char *string="This is a test string for my test program";
	char *pat="test";

		cout << boyer_moore(string,pat)<<" "<<endl;  

	system("PAUSE");
	return EXIT_SUCCESS;
}
