# Data Structure

## 2.Sequence list

### Comprehension

* 1，从顺序表中删除具有最小值的元素（唯一），并由函数返回被删元素的值，空出的位置由最后一个元素填补，若顺序表为空，显示错误信息并退出运行

  > 思路：输入顺序表，使用一个空元素记录最小值
  >
  > ~~~c
  > bool remove_min(SqList L, ElemType e)
  > {
  >     if (L.length <= 0)
  >     {
  >         printf("empty list");
  >         return false;
  >     }
  >     e = L.data[0];
  >     int idx = 0;
  >     for (int i = 0; i < L.length; i++)
  >     {
  >         if (L.data[i] < e)
  >         {
  >             e = L.data[i];
  >             idx = i;
  >         }
  >     }
  >     L.data[idx] = L.data[L.length - 1];
  >     L.length--;								// 顺序表长度减一，释放最后一个元素
  >     return true;
  > }
  > ~~~

* 2，设计一个高校算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为o(1)。

  > 思路：将第一个元素和最后一个元素对换，使用一个空元素，记录当前元素索引，和表长
  >
  > ~~~c
  > 
  > ~~~
  >
  > 