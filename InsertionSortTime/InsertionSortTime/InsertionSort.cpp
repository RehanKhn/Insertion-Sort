#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<chrono> 
#include<fstream>

using namespace std;
using namespace std::chrono;

const int arraySize = 1000;
int* InsertionSort(int arr[], int size);
int* RandomArray();
void WriteToFile(int*);

int main() {
	int* p;
	auto start = high_resolution_clock::now();
	p = InsertionSort(RandomArray(), arraySize);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast< microseconds > (stop - start); //for precision output in microseconds
	cout <<"It took " <<duration.count()<<" miliseconds to sort "<<arraySize << " random numbers in range 1-1^6."<< endl;
	WriteToFile(p);
	return 0;
}

int* RandomArray() {
	static int rArray[arraySize];
	srand(time(NULL));
	for (int i = 0; i < arraySize; i++) {
		rArray[i] = (rand() % 1000000) + 1;
	}
	return rArray;
}

int* InsertionSort(int arr[], int size) {
	int key, i, j;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			if (j < 0)break;
		}
		arr[j + 1] = key;
	}
	return arr;
}

void WriteToFile(int* p) {
	ofstream ofs;
	ofs.open("sorted.txt");
	for (int i = 0; i < arraySize; i++)
	{
		ofs << *(p + i)<<endl;
	}
}