#include <stdio.h>
#include <string.h>
#include "myString.h"

void copyline(char *dest, char *src){
    char *p1 = dest;
    char *p2 = src;
    while (*p2!='\n' && *p2!='\0' && *p2!=EOF){
        *p1=*p2;
        p1++;
        p2++;
    }
}

void copyword(char *dest, char *src){
    char *p1 = dest;
    char *p2 = src;
    while (*p2!=' ' && *p2!='\n' && *p2!='\t' && *p2!='\0' && *p2!=EOF){
        *p1=*p2;
        p1++;
        p2++;
    }
}

int getLine(char s[]) {
    int count=0;
    char c = s[count];
    while (c!='\n' && c!= EOF && c!='\0'){
        count++;
        c = s[count];
    }
    return count;
}

int getword(char w[]){
    int count=0;
    char c = w[count];
    while (c!='\n' && c!='\t' && c!=' ' && c!=EOF && c!='\0'){
        count++;
        c = w[count];
    }
    return count;
}

int substring(char *str1, char *str2){
    char *sptr1 = str1;
    char *sptr2 = str2;
    if (strlen(str1)<strlen(str2)) {
        return 0;
    }
    int count=0;
    while (*(sptr1+count) != '\0' && *(sptr2+count) != '\0'){
        if (*(sptr1+count) != *(sptr2+count)) {
            ++sptr1;
            count = 0;
            continue;
        }
        if (*(sptr1+count) == *(sptr2+count)) {
            count++;
            if (count == strlen(str2)) return 1;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    int len = strlen(t);
    char str[len];
    char* ptr = s;
    int i=0;
    if (strlen(s)-n>strlen(t)) return 0;
    while (n>=0 && *(ptr+i)!='\0' && *(t+i)!='\0') {
        if (*(ptr+i)==*(t+i)){
            str[i] = *(t+i);
            i++;
        }else{
            n--;
            ptr++;
            continue;
        }
    }
    if (n<0) return 0;
    str[len] = '\0';
    if (strcmp(str,t)!=0) {
        return 0;
    }
    return 1;
}

void print_lines(char *str,char *text){
    char *sptr=text;
    char line[LINE];
    int index=getLine(sptr);
    copyline(line,sptr);
    line[index]='\0';
    while (*(sptr)!='\0' && *(sptr)!=EOF){
        char *lptr=sptr;
        int wordIndex = getword(lptr);
        char temp[WORD];
        copyword(temp,lptr);
        temp[wordIndex] = '\0';
        while (*lptr!='\0' && *lptr!=EOF){
            if (similar(temp,str,0)==1){
                printf("%s\n",line);
                break;
            }
            lptr+=wordIndex;
            if (*lptr==' ' || *lptr=='\t') lptr+=1;
            if (*lptr=='\n') break;
            wordIndex = getword(lptr);
            copyword(temp,lptr);
            temp[wordIndex]='\0';
        }
        sptr+=index;
        if (*sptr=='\n') sptr++;
        if (*sptr=='\0') return;
        index = getLine(sptr);
        copyline(line,sptr);
        line[index]='\0';
    }
}

void print_similar_words(char *str,char *text){
    char *sptr = text;
    int index = getword(sptr);
    char temp[WORD];
    copyword(temp,sptr);
    temp[index] = '\0';
    while (*(sptr)!='\0' && *(sptr)!=EOF){
        if (similar(temp,str,1)==1){
            printf("%s\n",temp);
        }
        sptr+= index;
        if (*sptr==' ' || *sptr=='\n' || *sptr=='\t') sptr+=1;
        index = getword(sptr);
        copyword(temp,sptr);
        temp[index]='\0';
    }
}