#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void white () {
  printf("\033[0;37m");
}

void enter(int arr[10]) {
        for (int i=0; i<10; i++) {
            printf("a[%d] = ", i);
            scanf("%d", &arr[i]);
        }
        printf("\n\t\tResult: ");
        printf("\nYour array: ");
}
void random(int arr[10]) {
        const int Low = -100;
        const int High = 100;
        srand(time(0));
        for (int i=0; i<10; i++) {
            arr[i] = Low/2 + rand()%High;
        }
        printf("\n\t\tResult: ");
        printf("\nYour array: ");
}
void ArrayBetween(int arr[10]) {
    printf("{");
    for (int i=0; i<10; i++) {
        if (i == 9) {
        printf("\033[1;31m%d", arr[i]);
        white();
        }
        else {
        printf("\033[1;31m%d, ", arr[i]);
        white();
        }
    }
    printf("}");
}
void CountingEvenOdd(int arr[], int arr_size)
{
    int even_count = 0;
    int odd_count = 0;
 
    // цикл для чтения всех значений в массиве
    for (int i = 0; i < arr_size; i++) {
         
        // проверка, полностью ли число
        // делится на 2
        if (arr[i] & 1 == 1)
            odd_count++;
        else
            even_count++;
    }
    printf( "\nNumber of even elements = \033[1;32m%d", even_count);
    white();
    printf( "\nNumber of odd elements = \033[1;32m%d ", odd_count);
    white();
}
void ZeroToNegative ( int arr[10], int e ) {
    //тут ввод количество элементов, заполнение массива vect, его вывод
            int sum = 0;
            int first = 0;
            int second = 0;
            for (int i = 0; i < e; i++)
            {
                if(arr[i]<0 && first == 0)
                {
                    first = i;
                }
                else if(arr[i]<0&&second == 0)
                {
                    second = i;
                    break;
                }
            }
            for(int i = first + 1; i < second;
i++)
            {
                sum += arr[i];
            }
            printf("\nThe sum of the elements of the array, located between the first and second negative elements: \033[1;32m%d", sum);
            white();
}
// Driver Code
int main()
{
    int v;
    printf("\nChoose a method to get the result: ");
    printf("\n\t1: Between [-100/100];\n\t2: Enter your array;\n\t3: Exit.");
    printf("\n\tAnswer: ");
    scanf("%d", &v);
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    int e = sizeof(arr) / sizeof(arr[0]);
    if ( v == 1 ) {
        random(arr);
        ArrayBetween(arr);
        CountingEvenOdd(arr, n);
        ZeroToNegative(arr, e);
    }
    else if ( v == 2) {
        enter(arr); 
        ArrayBetween(arr);
        CountingEvenOdd(arr, n);
        ZeroToNegative(arr, e);
    }
    else {
        return 0;
    }
    return 0;
}