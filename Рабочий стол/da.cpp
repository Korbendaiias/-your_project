#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
using namespace std;

struct tovar{
string name;
double price;
string TTH;
int k;
};

void print(tovar *tv, int n){
if (n == 0) {
printf("Нет записей\n");
}
for (int i = 0; i < n; i++){
printf("%s, цена: %.2f, ТТХ: %s, кол-во: %d\n", tv[i].name.c_str(), tv[i].price, tv[i].TTH.c_str(), tv[i].k);
}
}

int open(tovar *tv){
ifstream file("file.txt");
int i = 0;
while (!file.eof()){
file » tv[i].name;
file » tv[i].price;
file » tv[i].TTH;
file » tv[i].k;
i++;
}
file.close();
return i;
}

void save(tovar *tv, int n){
ofstream file("file.txt");
int i = 0;
for(int i=0;i<n;i++){
file « tv[i].name.c_str()«endl;
file « tv[i].price « endl;
file « tv[i].TTH.c_str() « endl;
file « tv[i].k;
if (i != n - 1) file « endl;
i++;
}
file.close();
}

int add(tovar *tv, int n){
if (n == 100) return 100;
printf("Новык компьютер: ");
scanf("%s", tv[n].name.c_str());
printf("Цена: ");
scanf("%lf", &tv[n].price);
printf("Описание: ");
scanf("%s", tv[n].TTH.c_str());
printf("Количество: ");
scanf("%d", &tv[n].k);
return n+1;
}

void find(tovar *tv, int n){
if (n == 0) {
printf("Нет записей\n");
system("pause");
return;
}
int fnd = -1;
string tmp;
printf("Искомый компьютер: ");
scanf("%s", tv[n].name.c_str());
for (int i = 0; i < n; i++){
if (tv[i].name.c_str()){
fnd = i;
break;
}
}
if (fnd == -1) printf("Не найден\n");
else printf("%s, цена: %.2f, ТТХ: %s, кол-во: %d\n", tv[fnd].name.c_str(), tv[fnd].price, tv[fnd].TTH.c_str(), tv[fnd].k);

system("pause");
}

void correct(tovar *tv, int n){
if (n == 0) {
printf("Нет записей\n");
system("pause");
return;
}

int fnd = -1;
printf("Номер редактируемого компьютера: ");
scanf("%d", &fnd);
if (n<fnd||fnd>=0) {
printf("Неверный номер записи\n");
system("pause");
return;
}
fnd--;
printf("Новое название: ");
scanf("%s", tv[fnd].name.c_str());
printf("Цена: ");
scanf("%lf", &tv[fnd].price);
printf("Описание: ");
scanf("%s", tv[fnd].TTH.c_str());
printf("Количество: ");
scanf("%d", &tv[fnd].k);

system("pause");
}

int deletet(tovar *tv, int n){
if (n == 0) {
printf("Нет записей\n");
system("pause");
return n;
}

int fnd = -1;
printf("Номер удаляемого компьютера: ");
scanf("%d", &fnd);
if (n<fnd || fnd >= 0) {
printf("Неверный номер записи\n");
system("pause");
return n;
}

for (int i = fnd; i < n; i++)
tv[fnd - 1] = tv[fnd];
return n - 1;
}



int main(){
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
tovar tv[100];
int n = 0,t=0;

do{
system("cls");
print(tv, n);
printf("\n1. Добавить\n2. Поиск\n3. Редактирование\n4. Удаление\n5. Открыть файл\n6. Сохранить в файл\n\n» ");
scanf("%d", &t);
switch (t){
case 1: n=add(tv, n); break;
case 2: find(tv, n); break;
case 3: correct(tv, n); break;
case 4: n = deletet(tv, n); break;
case 5: n =open(tv); break;
case 6: save(tv, n); break;



}
printf("%d\n", n);



} while (t != 0);

return 0;
}
