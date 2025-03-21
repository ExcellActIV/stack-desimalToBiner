#include <stdlib.h>
#include "stack.h"

void createStack(Stack *S)
{
    (*S).TOP = Nil;
}

void allocate(address *P, infotype x)
{
    Create_Node(P, x);
}

void fillStack(Stack *S, infotype x)
{
    address P;
    allocate(&P, x);
    if (P != Nil)
    {
        Ins_Awal(&(*S).TOP, P);
    }
}

void deallocate(address P)
{
    free(P);
}

void push(Stack *S, infotype x)
{
    address P; 
    allocate(&P, x);
    if (P != Nil)
    {
        next(P) = (*S).TOP;
        (*S).TOP = P;
    }
}

void pop(Stack *S, infotype *x)
{
    if (!isEmptyStack(*S))
    {
        address P = (*S).TOP;
        *x = info(P);
        printf("Popped: %d\n", *x);
        (*S).TOP = next(P);
        deallocate(P);
    }
}

bool isEmptyStack(Stack S)
{
    return isEmpty(S.TOP);
}

void printStack(Stack S)
{
    Tampil_List(S.TOP);
}