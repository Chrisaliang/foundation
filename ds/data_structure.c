#define MaxSize 50 // 定义线性表的最大长度

typedef int ElemType;

typedef struct SqList
{
    ElemType *data;
    int length;
};

#define InitSize 100

typedef struct SeqList
{
    ElemType *data;
    int MaxSize, length;
};
