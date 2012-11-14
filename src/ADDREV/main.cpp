#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//Macros
#define LOOP(start, end, step) for(int i = start; i != end; i+= step)

using namespace std;

void trimZeroes(string* number, int step) {

    int newLength = step < 0 ? (*number).length() - 1 : 0;
    int totalLength = newLength;
    for(; (*number)[newLength] == '0' && newLength >= 0 && newLength <= totalLength; newLength += step);

    if (newLength < totalLength) {
        (*number).resize(newLength + 1);
    }

}

string reverseAdd(string* firstNum, string* secondNum) {

    int firstLength = firstNum->length();
    int secondLength = secondNum->length();

    int maxLength = max(firstLength, secondLength);
    firstNum->resize(maxLength + 1, '0');
    secondNum->resize(maxLength + 1, '0');

    int carry = 0;
    string sum = "";
    char* digit = (char*) malloc(sizeof(char));

    for(int i = 0; i < maxLength + 1; i++) {
        int newDigit = (int)(*firstNum)[i] + (int)(*secondNum)[i] + carry - 96;
        sprintf(digit, "%d", newDigit%10);
        sum += *digit;
        carry = newDigit/10;
    }

    return sum;
}

int main() {

    int N;
    scanf("%d", &N);
    while(N--) {
        string firstNum, secondNum;
        char* fn, sn;
        scanf("%s %s", fn, sn);
        string sum = reverseAdd(&firstNum, &secondNum);
        trimZeroes(&sum, -1);
        sum = string(sum.rbegin(), sum.rend());
        trimZeroes(&sum, -1);
        printf("%s\n", sum);
    }
    return 0;
}
