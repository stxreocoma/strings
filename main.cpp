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

void dynamic_task1() {
	char* string;
	char* string2;
	char c = getchar();
	int length = 1;
	
	string = (char*)malloc(length * sizeof(char));
	string[length - 1] = c;
	c = getchar();
	while (c != '\n') {
		length++;
		string2 = (char*)malloc(length * sizeof(char));
		for (int i = 0; i < length - 1; i++) {
			string2[i] = string[i];
		}
		string2[length - 1] = c;
		c = getchar();
		free(string);
		string = string2;
	}

	dynamic_strings_handler(string, length);
	print_string(string, length);
}

void dynamic_task2() {
	char* string;
	char c;
	int i = 0;
	int size = 3;
	int length = 0;

	string = (char*)calloc(size, sizeof(char));
	c = getchar();
	while (c != '\n') {
		string[i] = c;
		length++;
		i++;
		if (i > size - 1) {
			string = (char*)realloc(string, (size += 3) * sizeof(char));
		}
		c = getchar();
	}
	dynamic_strings_handler(string, length);
	print_string(string, length);
}

void dynamic_task3() {
	FILE* file = fopen("text.txt", "r+");
	char* string;
	char c;
	int i = 0;
	int size = 3;
	int length = 0;
	string = (char*)calloc(size, sizeof(char));
	c = fgetc(file);
	while (c != '0') {
		string[i] = c;
		length++;
		i++;
		if (i > size - 1) {
			string = (char*)realloc(string, (size += 3) * sizeof(char));
		}
		c = fgetc(file);
	}

	dynamic_strings_handler(string, length);
	fputs(" ", file);
	fputs(string, file);
	fclose(file);
}

int main() {
	//task1();
	//task2();
	//task3();
	//dynamic_task1();
	//dynamic_task2();
	dynamic_task3();
	return 0;
}

