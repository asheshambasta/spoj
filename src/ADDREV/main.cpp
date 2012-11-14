#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

//Macros
#define LOOP(start, end, step) for(int i = start; i != end; i+= step)

using namespace std;

void trimZeroes(char *number, int step) {

    int newLength = step < 0 ? strlen(number) - 1 : 0;
    int totalLength = newLength;
    for(; *(number + newLength) == '0' && newLength >= 0 && newLength <= totalLength; newLength += step);

    if (newLength < totalLength) {
        *(number + newLength + 1) = '\0';
    }

}

void pad(char* str, int start, int end, char padChar) {

    for (int i = start; i < end; i++) {
        *(str + i) = padChar;
    }

    *(str + end) = '\0';

}

char* reverseAdd(char *firstNum, char *secondNum) {

    int firstLength = strlen(firstNum);
    int secondLength = strlen(secondNum);

    int maxLength = max(firstLength, secondLength);

    pad(firstNum, firstLength, maxLength + 1, '0');
    pad(secondNum, secondLength, maxLength + 1, '0');

    int carry = 0;
    char *sum = (char*) malloc(100 * sizeof(char));
    char *digit = (char*) malloc(sizeof(char));

    for(int i = 0; i < maxLength + 1; i++) {
        int newDigit = (int)(*(firstNum + i)) + (int)(*(secondNum + i)) + carry - 96;
        sprintf(digit, "%d", newDigit%10);
        *(sum + i)= *digit;
        carry = newDigit/10;
    }

    *(sum + maxLength + 1) = '\0';
    return sum;
}

char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

int main() {

    int N;
    char *fn, *sn, *sum;
    fn = (char*) malloc(100*sizeof(char));
    sn = (char*) malloc(100*sizeof(char));
    scanf("%d", &N);
    while(N--) {
        string firstNum, secondNum;
        scanf("%s %s", fn, sn);
        sum = reverseAdd(fn, sn);
        trimZeroes(sum, -1);
        sum = strrev(sum);
        trimZeroes(sum, -1);
        sum = strrev(sum);
        printf("%s\n", sum);
    }
    return 0;
}
