#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#define LINE 256
#define WORD 30

void copyline(char *dest, char *src);

void copyword(char *dest, char *src);

int getLine(char s[]);

int getword(char w[]);

int substring(char *str1, char *str2);

int similar(char *s, char *t, int n);

void print_lines(char *str, char *text);

void print_similar_words(char *str, char *text);

#endif