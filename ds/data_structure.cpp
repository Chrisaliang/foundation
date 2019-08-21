#include <stdbool.h>
#include <stdio.h>

/**************** Define ****************/

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

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct BiNode
{
    ElemType data;
    struct BiNode *lChild, *rChild;
} BiTNode, *BiTree;

/**************** Atom operate ****************/
void InitStack(SqStack &s)
{
    s.top = -1;
}

bool IsEmpty(SqStack s)
{
    return s.top == -1;
}

bool Push(SqStack &s, ElemType x)
{
    if (s.top == MaxSize - 1)
        return false;
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top--];
    return true;
}

bool GetTop(SqStack &s, ElemType &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top];
    return true;
}

void visit(BiTree p)
{
    printf("%d", p->data);
}

/**************** Chapter 2 ****************/

LinkList List_previousInsert(LinkList L)
{
    // 从表尾到表头逆向建立单链表L，每次均在头节点之后插入元素
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; // r 为表尾指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LinkList *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

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
    if (L.length == 0)
        return;
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
    if (L.length == 0 || s > t)
        return;
    int count = 0;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i - count] = L.data[i];      // 将元素向前移动 count 个位置
        if (L.data[i] > s && L.data[i] < t) // 元素值位于s和t之间
            count++;                        // 计数器自增
    }
    L.length -= count;
}

void remove_duplicate(SqList L)
{
    if (L.length == 0)
        return;
    ElemType temp = L.data[0];
    int count = 0;
    for (int i = 0; i < L.length; ++i)
    {
        L.data[i - count] = L.data[i]; // 当前元素前移 count个位置
        if (L.data[i] == temp)
        {
            count++; // 重复元素计数加一
        }
        else
        {
            temp = L.data[i]; // 过滤不相等的元素
        }
    }
}

void cycle_move(SqList L, int p)
{
    SqList *temp;
    temp->length = p;
    for (int i = 0; i < L.length; i++)
    {
        if (i < p)
            temp->data[i] = L.data[i];
        L.data[i - p] = L.data[i];
        if (i >= L.length - p)
            L.data[i - p] = temp->data[i - p];
    }
}

LinkList diverse_list(LinkList &A)
{
    LinkList hb = (LinkList)malloc(sizeof(LNode));
    hb->next = null;
    LNode *p = A->next, *r = p->next;
    while (p)
    {
        p = r->next;        // 跳过第二个节点指向第三个节点
        r->next = hb->next; // 将第二个节点连接到B链表上
        hb->next = r;
        r = p->next;
    }
    return hb;
}

/**************** Chapter 4 ****************/
void InOrder(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S))
    {
        if (p)
        {
            Push(S, p);
            p = p->lChild;
        }
        else
        {
            Pop(S, p);
            printf("%d", p->data)
                p = p->rChild;
        }
    }
}

BiTree PreInCreate(ElemType A[], ElemType B[], int L1, int h1, int L2, int h2)
{
    // L1和h1为先序序列的第一个和最后一个节点下标，L2 和 h2 为中序的第一个和最后一个结点下标
    // 初始调用时，L1=L2=1；h1=h2=n
    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = A[L1];
    int i;
    for (i = L2; B[i] != root->data; i++)
        ;
    int lLen = i - L2;
    int rLen = h2 - i;
    if (lLen)
        root->lChild = PreInCreate(A, B, L1 + 1, L1 + lLen, L2, L2 + rLen - 1);
    else
        root->lChild = NULL;
    if (rLen)
        root->rChild = PreInCreate(A, B, h1 - rLen + 1, h1, h2 - rLen + 1, h2);
    else
        root->rChild = NULL;
    return root;
}

/**
 * todo post order traversing tree
 * not finished
 * @param T
 */
void PostOrder(BiTree &T)
{
    SqStack s;
    InitStack(s);
    BiTree p = T;
    Push(s, p);
    p = p->lChild while (!IsEmpty(s))
    {
        while (p)
        {
            Push(s, p);
            p = p->lChild;
        }
        Pop(s, p);
        if (p->rChild)
        {
            Push(s, p);
            p = p->rChild;
            Push(s, p);
            p = p->lChild;
        }
        else
        {
            visit(p);
            GetTop(s, p);
            p = p->rChild;
        }
    }
}

/**************** Test ****************/
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
