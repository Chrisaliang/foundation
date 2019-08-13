# Data Structure

## 2.Sequence list

### Comprehension

### 2.2 Sequence List

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

  > 思路：获取第一个符合条件的元素所在位置，从当前位置进行删除操作，
  >
  > ~~~c
  > void remove_range(SqList L, int s, int t)
  > {
  >     if (L.length == 0 || s > t)
  >         return;
  >     int count = 0;
  >     for (int i = 0; i < L.length; i++)
  >     {
  >         L.data[i - count] = L.data[i];      // 将元素向前移动 count 个位置
  >         if (L.data[i] > s && L.data[i] < t) // 元素值位于s和t之间
  >             count++;                        // 计数器自增
  >     }
  >     L.length -= count;
  > }
  > ~~~

* 6，从有序顺序表中删除所有值重复的元素，使其值唯一

  > 思路：使用临时变量记录当前元素值，遇到下一个相同的值，将其删除
  >
  > ~~~c
  > void remove_duplicate(SqList L)
  > {
  >     if (L.length == 0)
  >         return;
  >     ElemType temp = L.data[0];
  >     int count = 0;
  >     for (int i = 0; i < L.length; ++i)
  >     {
  >         L.data[i - count] = L.data[i]; // 当前元素前移 count个位置
  >         if (L.data[i] == temp)
  >         {
  >             count++; // 重复元素计数加一
  >         }
  >         else
  >         {
  >             temp = L.data[i]; // 过滤不相等的元素
  >         }
  >     }
  > }
  > ~~~
  >
  
* 10，【2010】设将n（n > 1）个整数存放到一维数组R中，设计一个在时间和空间两方面都尽可能高效的算法，将R中保存的序列循环左移p个位置，即将R中的数据变为（X<sub>p</sub>,X<sub>p+1</sub>,...,X<sub>n-1</sub>,X<sub>0</sub>,...X<sub>p-1</sub>）。要求
  1）给出算法的基本设计思想。
  2）使用语言描述算法，关键之处给出注释。
  3）说明时间复杂度和空间复杂度。

  > * 1 设计思想：
  >
  >   使用一个变量记录当前移动的数据值，
  >
  > * 算法：
  >
  > ~~~c
  > 
  > ~~~
  >
  > * 时间空间复杂度



### 2.3 Link List

* 11，设C = {a<sub>1</sub>, b<sub>1</sub>, a<sub>2</sub>, b<sub>2</sub>, ... a<sub>n</sub>, b<sub>n</sub> } 为线性表，采用带头节点的hc单链表存放，设计一个就地算法，将其拆分成两个线性表，是的A = {a<sub>1</sub>, a<sub>2</sub>, ... a<sub>n</sub> }, B = {b<sub>n</sub>, ... b<sub>2</sub>, b<sub>1</sub> }。

  > 设计思想：
  >
  > 遍历链表C，取第一个节点，将其用尾插法插入链表A中，取之后一个节点，使用头插法，将其插入到链表B中。
  >
  > 算法
  >
  > ~~~c++
  > LinkList diverse_list(LinkList &A) {
  >     LinkList hb = (LinkList) malloc(sizeof(LNode));
  >     hb->next = null;
  >     LNode *p = A->next, *r = p->next;
  >     while (p) {
  >         p = r->next;        // 跳过第二个节点指向第三个节点
  >         r->next = hb->next; // 将第二个节点连接到B链表上
  >         hb->next = r;
  >         r = p->next;
  >     }
  >     return hb;
  > }
  > ~~~
  >
  > 

