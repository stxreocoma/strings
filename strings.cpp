#include "strings.h"

#include <ctype.h>
#include <iostream>

void dot(char* string, int length, int dot_index, int dot_count) {

    for (int i = dot_index + dot_count; i < length; i++) {
        string[i - dot_count+1] = string[i];
        string[i] = ' ';
    }
}

void strings_handler(char* string, int length) {
    bool letter_flg = false, dot_flg = false;
    int dot_index = -1, dot_count = 0, dif = 0, length_dif = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(string[i-dif])) {
            letter_flg = true;
        }
        if (string[i-dif] == '.' && letter_flg && !dot_flg) {
            dot_index = i-dif;
            dot_count++;
            dot_flg = true;
        }
        else if (string[i-dif] == '.' && dot_index != -1) {
            dot_count++;
        }
        else if (dot_index != -1 && dot_count % 2 != 0 && dot_count > 1 && letter_flg) {
            dot(string, length - length_dif, dot_index, dot_count);
            length_dif += dot_count - 1;
            dif += dot_count - 1;
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(string[i-dif])) {
                letter_flg = false;
            }
        }
        else if (dot_index != -1 && dot_count % 2 == 0 && string[i-dif] != '.') {
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(string[i - dif])) {
                letter_flg = false;
            }
        }
    }
    if (dot_index != -1 && dot_count % 2 != 0) {
        for (int index = dot_index + 1; index < length-length_dif; index++) {
            string[index] = ' ';
        }
    }
}

void print_string(char* string, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << string[i];
    }
}

void dynamic_strings_handler(char* string, int length) {
    bool letter_flg = false, dot_flg = false;
    int dot_index = -1, dot_count = 0, dif = 0, length_dif = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(string[i - dif])) {
            letter_flg = true;
        }
        if (string[i - dif] == '.' && letter_flg && !dot_flg) {
            dot_index = i - dif;
            dot_count++;
            dot_flg = true;
        }
        else if (string[i - dif] == '.' && dot_index != -1) {
            dot_count++;
        }
        else if (dot_index != -1 && dot_count % 2 != 0 && dot_count > 1 && letter_flg) {
            dot(string, length - length_dif, dot_index, dot_count);
            length_dif += dot_count - 1;
            dif += dot_count - 1;
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(string[i - dif])) {
                letter_flg = false;
            }
        }
        else if (dot_index != -1 && dot_count % 2 == 0 && string[i - dif] != '.') {
            dot_index = -1;
            dot_count = 0;
            dot_flg = false;
            if (!isalpha(string[i - dif])) {
                letter_flg = false;
            }
        }
    }
    if (dot_index != -1 && dot_count % 2 != 0) {
        for (int index = dot_index + 1; index < length - length_dif; index++) {
            string[index] = ' ';
        }
    }
    string = (char*)realloc(string, length - length_dif - dot_count + 1);
}