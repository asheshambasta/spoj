#include <stdio.h>
#include <stdlib.h>

bool compare(char *num) {

    return !(*(num) == '4' && *(num + 1) == '2' && *(num + 2) == '\0');
}

int main() {

    char *input = (char*) malloc(100*sizeof(char));
    scanf("%s", input);
    while(compare(input)) {
        printf("%s\n", input);
        scanf("%s", input);
    }

    return 0;
}
