#include <stdio.h>
#include "stack.h"

int main() {
    // Membuat program konversi desimal ke biner menggunakan stack
    Stack S;
    infotype x, num;

    printf("Masukkan angka yang ingin dijadikan biner: ");
    scanf("%d", &num);

    createStack(&S);

    // Push nilai biner (sisa) ke stack
    while (num > 0) 
    {
        x = num % 2;
        push(&S, x);
        num /= 2;
    }

    printf("Hasil konversi ke biner: ");
    printStack(S);

    // Dealokasi
    while (!isEmptyStack(S))
    {
        pop(&S, &x);
    }

    return 0;
}