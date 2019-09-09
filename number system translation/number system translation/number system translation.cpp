// Translation of number systems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	// 0101111110001000 - 24456
	// 1001111110001110 - 40846
	// 0001111110000000 - 8064

	// 1111 - 15
	// 1110 - 14
	// 1101 - 13
	// 1100
	// 1000
	// 1001
	// 0110
	// 0111
	// 0011
	// 0001

	long long binaryNumber;
	cin >> binaryNumber;

	int highByte = binaryNumber / 100000000;
	int lowerByte = binaryNumber % 100000000;

	cout << highByte << endl;
	cout << lowerByte << endl;

	int decimal = 0;

	uint16_t iterator = 0;

	int mask = 1;

	__asm
	{
		mov cx, iterator
		solveLowerByte :

		xor edx, edx
			mov eax, lowerByte
			mov ebx, 10

			div ebx

			mov lowerByte, eax

			cmp edx, 0h
			ja addBitToDecimal

			check :

		xor ebx, ebx
			mov ebx, mask
			shl ebx, 1
			mov mask, ebx

			inc cx
			cmp cx, 8
			jb solveLowerByte

			mov cx, 0
			jmp solveHighByte // Переход в функцию верхнего байта

			addBitToDecimal :

		xor eax, eax
			mov eax, decimal
			xor ebx, ebx
			mov ebx, mask

			add eax, ebx
			mov decimal, eax

			jmp check


			solveHighByte :

		xor edx, edx
			mov eax, highByte
			mov ebx, 10

			div ebx

			mov highByte, eax

			cmp edx, 0h
			ja addHighBitToDecimal


			checkHigh :

		xor ebx, ebx
			mov ebx, mask
			shl ebx, 1
			mov mask, ebx

			inc cx
			cmp cx, 7
			jb solveHighByte


			determineSign :

		xor edx, edx
			mov eax, highByte
			mov ebx, 10

			div ebx

			cmp edx, 0h // Если самый левый бит равен нулю, то число положительное
			je aw

			createNegative : // иначе - отриацательное

		mov eax, decimal
			mov ebx, 32768 // 2^15

			sub ebx, eax
			neg ebx

			mov decimal, ebx
			jmp aw

			addHighBitToDecimal :

		xor eax, eax
			mov eax, decimal
			xor ebx, ebx
			mov ebx, mask

			add eax, ebx
			mov decimal, eax

			jmp checkHigh




			aw :
		nop;


	}

	cout << decimal << endl;

	_getch();
	return 0;

}
