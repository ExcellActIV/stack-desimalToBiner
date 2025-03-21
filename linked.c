#include "linked.h"

bool isEmpty(address p)
{
    return (p == NULL);
}

void Create_Node(address *p, infotype x)
{
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != Nil)
    {
        Isi_Node(p, x);
        next(*p) = Nil;
    }
}

void Isi_Node(address *p, infotype nilai)
{
    info(*p) = nilai;
}

void Tampil_List(address p)
{
    if (isEmpty(p))
    {
        printf("Element List = {}\n\n");
        return;
    }
    printf("Elemen List = {");
    while (next(p) != NULL)
    {
        printf("%d, ", info(p));
        p = next(p);
    }
    printf("%d", info(p));
    printf("}\n\n");
}

void Ins_Awal(address *p, address PNew)
{
    next(PNew) = *p;
    *p = PNew;
}

void Ins_Akhir(address *p, address PNew)
{
    address temp;
    temp = *p;
    while (next(temp) != NULL)
    {
        temp = next(temp);
    }
    next(temp) = PNew;
    next(PNew) = NULL;
}

address Search(address p, infotype nilai)
{
    address temp = p;
    while (temp != NULL && info(temp) != nilai)
    {
        temp = next(temp);
    }
    return temp;
}

void InsertAfter(address *pBef, address *PNew)
{
    next(*PNew) = next(*pBef);
    next(*pBef) = *PNew;
}

void Del_Awal(address *p, infotype *X)
{
    address temp;
    temp = *p;
    *p = next(*p);
    *X = info(temp);
    free(temp);
}

void Del_Akhir(address *p, infotype *X)
{
    address temp, temp2;
    temp = *p;
    while (next(temp) != NULL)
    {
        temp2 = temp;
        temp = next(temp);
    }
    *X = info(temp);
    next(temp2) = NULL;
    free(temp);
}

void Del_After(address *pBef, infotype *X)
{
    address temp = *pBef;
    while (*X != info(next(temp)))
    {
        temp = next(temp);
    }
    temp = next(temp);
    next(temp) = next(next(temp));
    free(temp);
}

void DeAlokasi(address *p)
{
    if (*p == NULL)
    {
        return;
    }
    address current = *p;
    while (current != NULL)
    {
        address temp = current;
        current = next(current);
        free(temp);
    }
    *p = NULL;
}

int NbElmt(address p)
{ 
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = next(p);
    }
    return count;
}

void Ins_Mid(address *p, address PNew)
{
    int mid = NbElmt(*p) / 2 - 1;
    address temp = *p;
    for (int i = 0; i < mid; i++)
    {
        temp = next(temp);
    }
    next(PNew) = next(temp);
    next(temp) = PNew;
}

void Del_Mid(address *p, infotype *X)
{
    int mid = NbElmt(*p) / 2 - 1;
    address temp = *p;
    for (int i = 0; i < mid; i++)
    {
        temp = next(temp);
    }
    *X = info(next(temp));
    next(temp) = next(next(temp));
    free(next(temp));
}

infotype Min(address p)
{
    address temp;
    temp = p;
    infotype min = info(temp);
    while (temp != NULL)
    {
        if (info(temp) < min)
        {
            min = info(temp);
        }
        temp = next(temp);
    }
    return min;
}

infotype Rerata(address p)
{
    address temp;
    temp = p;
    infotype sum = 0, count = 0;
    while (temp != NULL)
    {
        sum += info(temp);
        count++;
        temp = next(temp);
    }
    return sum / count;
}

address BalikList(address p)
{
    address temp, temp2, temp3;
    temp = p;
    temp2 = NULL;
    while (temp != NULL)
    {
        temp3 = next(temp);
        next(temp) = temp2;
        temp2 = temp;
        temp = temp3;
    }
    return temp2;
}
