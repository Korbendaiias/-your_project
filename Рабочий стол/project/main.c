#include <stdio.h>
#include <string.h>
#include "my_functions_header.h"
#include <malloc.h>


int main(int argc, char* argv[1]) {
int size = count_structs(argv[1]); 
tovar* tv = (tovar*)malloc(sizeof(tovar) * size);
int n = 0, t = 0;

do {
print(tv, n);
printf("\n1. Добавить\n2. Поиск\n3. Редактирование\n4. Удаление\n5. Открыть файл\n6. Сохранить в файл\n\n» ");
scanf("%d", &t);
switch (t) {
case 1: n = add(tv, n); break;
case 2: find(tv, n); break;
case 3: correct(tv, n); break;
case 4: n = deletet(tv, n); break;
case 5: n = open(tv, argv[1]); break;
case 6: save(tv, n, argv[1]); break;
}
printf("%d\n", n);

} while (t != 0);
free(tv);
return 0;
}
