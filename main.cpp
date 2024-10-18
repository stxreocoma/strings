#define _CRT_SECURE_NO_WARNINGS

#include "strings.h"
#include "iostream"
#include "stdio.h"

void task1() {
	char string[100] = { '\0' };
	char c = getchar();
	int length = 0;

	while (c != '\n') {
		string[length] = c;
		length++;
		c = getchar();
	}

	strings_handler(string, length);
	print_string(string, length);
}

void task2() {
	char string[100] = {};
	int length = strlen(fgets(string, 100, stdin)) - 1;

	strings_handler(string, length);
	print_string(string, length);
}

void task3() {
	char string[100] = {};
	int length;

	FILE* text = fopen("text.txt", "r+");
	
	if (text) {
		length = strlen(fgets(string, 100, text));
	}
	else {
		std::cout << "something went wrong!\n";
		return;
	}

	strings_handler(string, length);
	fputs(" ", text);
	fputs(string, text);
	fclose(text);
}

int main() {
	task1();
	task2();
	task3();
	return 0;
}

