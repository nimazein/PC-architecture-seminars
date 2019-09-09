// Translation of number systems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

using namespace std;

void RightAnswer(long long binaryNumber, int checkedAnswer);

int main()
{
	// 0101111110001000 - 24456
	// 1001111110001110 - -24690
	// 0001111110000000 - 8064


	long long binaryNumber;
	cin >> binaryNumber;

	int highByte = binaryNumber / 100000000;
	int lowerByte = binaryNumber % 100000000;

	int decimal = 0;

	uint16_t iterator = 0;

	int mask = 1;

	__asm
	{
		xor cx, cx
		mov eax, lowerByte

	start:

		xor edx, edx
		mov ebx, 10
		div ebx
		
		cmp edx, 0h
		ja addBitToDecimal

	check:

		xor ebx, ebx
		mov ebx, mask
		shl ebx, 1
		mov mask, ebx

		inc cx
		cmp cx, 8
		je getHighByte
		cmp cx, 15
		jb start
	
	determineSign:
		
		cmp eax, 0h
		je aw

		mov eax, decimal
		mov ebx, 32768 // 2^15
		sub ebx, eax

		neg ebx
		mov decimal, ebx
		jmp aw

	getHighByte:

		mov eax, highByte
		jmp start

	addBitToDecimal:
		xor edx, edx
		xor ebx, ebx

		mov edx, decimal
		mov ebx, mask

		add edx, ebx

		mov decimal, edx
		jmp check

	aw:
		nop;
	}

	cout << decimal << endl;
	RightAnswer(binaryNumber, decimal);

	_getch();
	return 0;

}
void RightAnswer(long long binaryNumber, int checkedAnswer) {

	int decimalNumber = 0;
	int mask = 1;

	for (int i = 0; i < 15; i++)
	{
		if (binaryNumber % 10 == 1)
		{
			decimalNumber += mask;
		}
		mask <<= 1;
		binaryNumber /= 10;
	}

	if (binaryNumber == 1)
	{
		decimalNumber -= 32768;	//2^15
	}

	setlocale(LC_CTYPE, "rus");
	if (decimalNumber == checkedAnswer)
	{
		cout << "Ответ верен";
	}
	else
	{
		cout << "Ответ не верен";
	}




}
