#include <stdio.h>

//ввод переменных для определения наибольшего количества вместимых вещей
int max_items(int a, int b)
{ return (a > b) ? a : b; }
//ks - рюкзак
//C - (Knapsack capacity) вместимость рюкзака
//Код для решения задачи

int ks(int C, int wg[], int vl[], int n)
{
//Изначальное состояние рюкзака
if (n == 0 || C == 0)
return 0;

//По условию вес вещей не может превышать предел вместимости рюкзака
else if (wg[n - 1] > C)
return ks(C, wg, vl, n - 1);


else
return max_items(
vl[n - 1] + ks(C - wg[n - 1], wg, vl, n - 1),
ks(C, wg, vl, n - 1));
}

//Условие задачи
int main()
{
//определение ценности вещи
int vl[] = { 50, 60, 70 };
//определение веса вещи
int wg[] = { 5, 10, 15 };
//определение вместимости рюкзака
int C = 25;
int n = sizeof(vl) / sizeof(vl[0]);
printf("\nУсловие задачи: Вместимость рюкзака 25 единиц, вам даны вещи вместимость которых 5, 10, 15 единиц с ценностью в 50, 60, 70. Определите при каком раскладе у задачи получится решение с наибольшим значением.\n");
printf("\nОтвет задачи: %d\n", ks(C, wg, vl, n));
return 0;
}
