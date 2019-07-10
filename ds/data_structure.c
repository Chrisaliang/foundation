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
    int InitSize;
} SeqList;

int InitList(SqList *L)
{
    //    (*L).data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    //不知什么问题不能用LIST_INIT_SIZE，必须用100，下面的realloc函数也是一样？
    // if ((*L).data == NULL)
    // {
    //     exit(1);
    // }
    (*L).length = 0;
    //    (*L).listsize=LIST_INIT_SIZE;
    return 1;
}

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

void reverse_list(SqList L)
{
    ElemType temp;
    for (int i = 0; i < L.length - 1; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

void remove_x(SqList L, int x)
{
    int count = 0; // 记录符合条件的值的个数
    for (int i = 0; i < L.length; i++)
    {
        L.data[i - count] = L.data[i]; // 将元素向前移动 count 个位置
        if (L.data[i] == x)
        {            // 如果元素值等于指定值
            count++; // count计数器自增
        }
    }
    L.length -= count;
}

void remove_range(SqList L, int s, int t)
{
    int count = 0;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i - count] = L.data[i];      // 将元素向前移动 count 个位置
        if (L.data[i] > s && L.data[i] < t) // 元素值位于s和t之间
            count++;                        // 计数器自增
    }
    L.length -= count;
}

int main()
{
    SqList *list;
    // InitList(list);
    list->length = 5;
    for (int i = 0; i < list->length; ++i)
    {
        list->data[i] = i * 3;
    }
    remove_x(*list, 3);
    printf("list length: %d", list->length);
    return 0;
}