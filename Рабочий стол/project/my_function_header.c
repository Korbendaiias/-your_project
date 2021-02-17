#include <stdio.h>
#include "struct_tovar_header.h"

void print(tovar* tv, int n) {
if (n == 0) {
printf("Нет записей\n");
}
for (int i = 0; i < n; i++) {
printf("%s, цена: %.2lf, ТТХ: %s, кол-во: %d\n", tv[i].name, tv[i].price, tv[i].TTH, tv[i].k);
}
}

int open(tovar* tv, char filename[]) {
FILE* file = fopen(filename, "r");
if (file == NULL) fprintf(stderr, "File no open");
int i = 0;
while (!feof(file)) {
fgets(tv[i].name, N, file);
fscanf(file, "%lf", &tv[i].price);
fgetc(file);
fgets(tv[i].TTH, N, file);
fscanf(file, "%d", &tv[i].k);
fgetc(file);
i++;
}
fclose(file);
return i;
}
void save(tovar* tv, int n, char filename[]) {
FILE* file = fopen(filename, "w");
if (file == NULL) fprintf(stderr, "File not open\n");
int i = 0;
for (int i = 0; i<n; i++) {
fprintf(file, "%s\n", tv[i].name);
fprintf(file, "%lf\n", tv[i].price);
fprintf(file, "%s\n", tv[i].TTH);
fprintf(file, "%d\n", tv[i].k);
if (i != n - 1) fprintf(file, "\n");
i++;
}
fclose(file);
}

int add(tovar* tv, int n) {
if (n == 100) return 100;
printf("Новый компьютер: ");
scanf("%s", tv[n].name);
printf("Цена: ");
scanf("%lf", &tv[n].price);
printf("Описание: ");
scanf("%s", tv[n].TTH);
printf("Количество: ");
scanf("%d", &tv[n].k);
return n + 1;
}

void find(tovar* tv, int n) {
if (n == 0) {
printf("Нет записей\n");
return;
}
int fnd = -1;

printf("Искомый компьютер: ");
scanf("%s", tv[n].name);
for (int i = 0; i < n; i++) {
if (tv[i].name) {
fnd = i;
break;
}
}
if (fnd == -1) printf("Не найден\n");
else printf("%s, цена: %.2f, ТТХ: %s, кол-во: %d\n", tv[fnd].name, tv[fnd].price, tv[fnd].TTH, tv[fnd].k);

}

void correct(tovar* tv, int n) {
if (n == 0) {
printf("Нет записей\n");
return;
}

int fnd = -1;
printf("Номер редактируемого компьютера: ");
scanf("%d", &fnd);
if (n<fnd || fnd >= 0) {
printf("Неверный номер записи\n");
return;
}
fnd--;
printf("Новое название: ");
scanf("%s", tv[fnd].name);
printf("Цена: ");
scanf("%lf", &tv[fnd].price);
printf("Описание: ");
scanf("%s", tv[fnd].TTH);
printf("Количество: ");
scanf("%d", &tv[fnd].k);

}

int deletet(tovar* tv, int n) {
if (n == 0) {
printf("Нет записей\n");
return n;
}

int fnd = -1;
printf("Номер удаляемого компьютера: ");
scanf("%d", &fnd);
if (n<fnd || fnd >= 0) {
printf("Неверный номер записи\n");
return n;
}

for (int i = fnd; i < n; i++)
tv[fnd - 1] = tv[fnd];
return n - 1;
}
int count_structs(char *filename)
{
FILE* file = fopen(filename, "r");
tovar tmp;
int i = 0;
if (file == NULL) fprintf(stderr, "File not open\n");
while (!feof(file))
{
fgets(tmp.name, N, file);
fscanf(file, "%lf", &tmp.price);
fgetc(file);
fgets(tmp.TTH, N, file);
fscanf(file, "%d", &tmp.k);
fgetc(file);
++i;
}
fclose(file);

return i;
}
