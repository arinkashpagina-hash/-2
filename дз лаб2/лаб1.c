#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    float H = 5000.0f;   
    float Vc = 250.0f;  
    float Vp = 800.0f;   
    float S;             
    float a, b, c;        
    float D;              
    float T1, T2, T;      

    printf("Введите расстояние S (в метрах) до пусковой установки: ");
    scanf("%f", &S);
    a = Vp * Vp - Vc * Vc;
    b = 2.0f * S * Vc;
    c = -(S * S + H * H);
    D = b * b - 4.0f * a * c;

    T1 = (-b + sqrtf(D)) / (2.0f * a);
    T2 = (-b - sqrtf(D)) / (2.0f * a);
    T = (T1 > T2) ? T1 : T2;

    printf("Результаты:\n");
    printf("Высота полёта самолёта:    H  = %.2f м\n", H);
    printf("Скорость самолёта:         Vc = %.2f м/с\n", Vc);
    printf("Скорость ракеты:           Vp = %.2f м/с\n", Vp);
    printf("Расстояние до установки:   S  = %.2f м\n", S);
    printf("Коэффициенты уравнения:    a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    printf("Дискриминант:              D = %.2f\n", D);
    printf("Корень T1:                 %.4f с\n", T1);
    printf("Корень T2:                 %.4f с\n", T2);
    printf("Время до поражения цели:   T = %.4f секунд\n", T);
    printf("Это составляет примерно %.2f минут.\n", T / 60.0f);

    return 0;
}