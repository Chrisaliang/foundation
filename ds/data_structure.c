#include <stdbool.h>
#include <stdio.h>
#define MaxSize 50 // 定义线性表的最大长度

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int length;
} SqList;

#define InitSize 100

typedef struct SeqList
{
    ElemType *data;
    int length;
} SeqList;

bool ListInsert(SqList L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList L, int i, ElemType e)
{
    // 本算法实现删除顺序表中的第i个元素，并用e返回元素值
    if (i < 0 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

bool remove_min(SqList L, ElemType e)
{
    if (L.length <= 0)
    {
        printf("empty list");
        return false;
    }
    e = L.data[0];
    int idx = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < e)
        {
            e = L.data[i];
            idx = i;
        }
    }
    L.data[idx] = L.data[L.length - 1];
    L.length--;
    return true;
}

int main()
{
    return 0;
}