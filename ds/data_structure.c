#include <stdbool.h>
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
};

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
