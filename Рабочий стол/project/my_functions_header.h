#ifndef MY_FUNCTIONS_HEADER_H
#define MY_FUNCTIONS_HEADER_H

#include "struct_tovar_header.h"
int count_structs(char *filename);
void print(tovar* tv, int n);
int open(tovar* tv, char filename[]);
void save(tovar* tv, int n, char filename[]);
int add(tovar* tv, int n);
void find(tovar* tv, int n);
void correct(tovar* tv, int n);
int deletet(tovar* tv, int n);

#endif // !MY_FUNCTIONS_HEADER_H
