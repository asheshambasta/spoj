#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* palin(char* num) {

  int length = strlen(num);
  int midpoint = length/2;
  int left = midpoint - 1;
  int right = length - midpoint; 
  char* res = (char*) malloc(length);
  memset(res, '\0', sizeof(char) * (length));

  while (0 <= left && right < length) {

    cout<<"LEFT: "<<left<<" RIGHT "<<right<<endl;

    char leftChar = *(num + left);
    char rightChar = *(num + right);

    if (leftChar != rightChar) {
      
      if (rightChar < leftChar) {
        rightChar = leftChar; 
      }

      if (leftChar < rightChar) {
       ++leftChar;
       rightChar = leftChar;
      }
    }

    *(res + left) = leftChar;
    *(res + right) = rightChar;

    --left;
    ++right;
  }

  if (0 != length%2) {
    *(res + midpoint) = *(num + midpoint);
  }
  
  return res;
}

int main() {

  int tests;
  char* k;

  scanf("%d", &tests);

  for (int i = 0; i < tests ; i++) {
    
    scanf("%s", k);
    cout<<palin(k)<<endl;
  }

  return 0;
}
