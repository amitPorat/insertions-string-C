#include <stdio.h>
#include <string.h>
#include "myString.h"

int main() {
    char text[65536];
    int num=scanf("%[^\n]s",text);
    char *ptr=text;
    int len = getword(text);
    char str[len];
    copyword(str,text);
    str[len]='\0';
    ptr+=len+1;
    char option = *ptr;
    ptr+=5;
    if (option=='a'){
        print_lines(str,ptr);
    }else if (option=='b'){
        print_similar_words(str,ptr);
    }else printf("input error");
    return 0;
}