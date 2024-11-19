//Problem #29
#include <iostream>
using namespace std;

enum enPrimeNotPrime{Prime=1,NotPrime=0};

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

enPrimeNotPrime CheckPrime(int Num)
{
	int X = round(Num / 2);

	for (int i = 2; i <= X; i++)
	{
		if (Num % i==0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}
	return enPrimeNotPrime::Prime;
}



void FillArray(int arr[100], int& arrLength)
{
	cout << "Enter how many elements: ";
	cin >> arrLength;

	for (int i = 0; i < arrLength;i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void CheckPrimeInArray(int arr[100],int arrPrime[100],int arrLength,int &PrimeLength)
{
	PrimeLength = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arr[i]) == enPrimeNotPrime::Prime)
		{
		arrPrime[PrimeLength]=arr[i];
		PrimeLength++;
		}
	}
	
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100],arrPrime[100], arrLength, PrimeLength;

	FillArray(arr, arrLength);

	cout << "Array elements: \n";
	PrintArray(arr, arrLength);

	cout << "\nArray with Prime Numbers: \n";
	CheckPrimeInArray(arr, arrPrime, arrLength, PrimeLength);
	PrintArray(arrPrime, PrimeLength);

	return 0;
}