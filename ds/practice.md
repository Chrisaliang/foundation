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
  > void reverse_list(SqList L)
  > {
  >     ElemType temp;
  >     for (int i = 0; i < L.length - 1; i++)
  >     {
  >         temp = L.data[i];
  >         L.data[i] = L.data[L.length - i - 1];
  >         L.data[L.length - i - 1] = temp;
  >     }
  > }
  > ~~~

* 3，对长度为n的顺序表，删除所有的值为x的数据元素，要求时间复杂度O(n)，空间复杂度O(1)

  > 思路：遍历顺序表，将当前元素向前移动count个位置，当遇到符合条件的元素时，count自增
  >
  > ~~~c
  > void remove_x(SqList L, int x)
  > {
  >     int count = 0; // 记录符合条件的值的个数
  >     for (int i = 0; i < L.length; i++)
  >     {
  >         L.data[i - k] = L.data[i]; // 将元素向前移动 count 个位置
  >         if (L.data[i] == x)
  >         {            // 如果元素值等于指定值
  >             count++; // count计数器自增
  >         }
  >     }
  >     L.length -= count;
  > }
  > ~~~

* 4，从有序顺序表中删除其值在给定的值s和t之间的所有元素，如果s和t不合理或顺序表空，显示错误信息并退出。

  > 思路：
  >
  > ~~~c
  > 
  > ~~~
  >
  > 