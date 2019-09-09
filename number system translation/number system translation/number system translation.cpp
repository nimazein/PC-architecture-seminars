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


			aw :
		nop;


	}

	cout << decimal << endl;

	_getch();
	return 0;

}
