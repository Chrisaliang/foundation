# 第二章 进程管理

## 2.3 进程同步

* 1, 何谓管程？管程由几部分组成？说明必要性

* 2，进程间有哪几种制约关系，各是什么原因引起的？

  > 进程间只有两种制约关系：<big>同步和互斥</big> 
  > 同步是由于并发进程之间需要协同完成同一任务时引起的一种关系，是一个进程等待另一个进程向它直接发送消息或数据时的一种制约关系。
  > 互斥时由于并发进程之间竞争系统的临界资源引起，是一个进程等等待另一个进程已经占有的必须互斥使用的资源时的一种制约关系。

* 3， 三个进程使用一个包含N个单元的缓冲区。P1每次使用produce()生成一个正整数并用put()放入缓冲区某一空单元；P2每次使用getodd()从该缓冲区中取出一个奇数并用countodd()统计奇数的个数；P3用geteven()从该缓冲区中取出一个偶数并用counteven()统计偶数个数。用信号量机制实现，并说明所定义的信号量的意义。

  > ~~~c
  > semaphore mutex = 1;  		// 互斥缓冲区信号量
  > semaphore empty = N;  		// 缓冲区剩余空单元个数信号量
  > semaphore odd = 0;    		// 
  > semaphore even = 0;   		// 奇偶数进程同步信号量
  > 
  > cobegin{
  > 
  >     process P1()
  >     {
  >         while(true)
  >         {
  >             x = produce();	// 生产一个正整数
  >             P(empty);      	// 缓冲区还有空闲单元
  >             P(mutex);      	// 获取缓冲区使用权
  >             put(x);        	// 将其放入缓冲区
  >             V(mutex);      	// 释放缓冲区
  >             if (x%2==0)
  >                 V(even);   	// 若是偶数，向p3发信号
  >             else
  >                 V(odd);    	// 若是奇数，向p2发信号
  >         }
  >     }
  >     
  >     process P2()
  >     {
  >         while(true){
  >             P(odd);			// 收到信号，缓冲区中有奇数
  >             P(mutex);		// 互斥使用缓冲区
  >             x = get0dd();
  >             V(mutex);		// 释放缓冲区
  >             V(empty);		// 释放空单元
  >             countodd();		// 统计奇数个数
  >         }
  >     }
  >     
  >     process P3()
  >     {
  >         while(true){
  >             P(even);
  >             P(mutex);
  >             x = geteven();
  >             V(mutex);
  >             V(empty);
  >             counteven();
  >         }
  >     }
  > }coend
  > ~~~

* 6, 一个仓库可以存放A和B两种产品，要求：
  ① 每次只能存入一种产品
  ② A产品数量 - B产品数量 < M
  ③ B产品数量 - A产品数量 < N
  其中M、N是正整数

  > 使用互斥信号量mutex 控制仓库的互斥访问，使用信号量Sa和Sb（分别代表产品A与B的还可容纳的数量差，以及产品B与A的还可容纳的数量差）
  >
  > ~~~c
  > semaphore Sa = M-1, Sb = N-1;
  > semaphore mutex = 1;
  > 
  > proess_A(){
  >     while(true){
  >         P(Sa);
  >         P(mutex);
  >         put_a2repository();
  >         V(mutex);
  >         V(Sb);
  >     }
  > }
  > 
  > process_B(){
  >     while(true){
  >         P(Sb);
  >         P(mutex);
  >         put_b2repository();
  >         V(mutex);
  >         V(Sa);
  >     }
  > }
  > ~~~

* 7，面包师和他的推销人员，顾客进店取号并等待，推销人员叫号

  > 顾客进店按序取号，销售人员空闲后按序叫号，故使用两个变量i和j记录当前叫号取号值，并使用各自互斥信号量
  >
  > ~~~c
  > int i = 0, j = 0;
  > semaphore mutex_i = 1, mutex_j = 1;
  > 
  > process customer(){
  >     get_into_shop();	// 进入面包店
  >     P(mutex_i);			// 使用叫号机
  >     get_a_number();		// 排队取号
  >     i++;
  >     V(mutex_i);
  >     wait_calling();		// 等待被叫
  > 
  > }
  > 
  > process seller(){
  >     while(true){
  >         P(mutex_j);		// 互斥访问
  >         if(j<i){
  >             calling_j();
  >             j++;
  >             V(mutex_j);	// 释放访问
  >             sell_bread();
  >         } else{
  >             V(mutex_j);
  >             have_a_rest();
  >         }
  >     }
  > }
  > ~~~

* > P、V操作题思路：首先确认共享变量，然后确认对于该共享变量的操作程序

* 9，某工厂两个生产车间和一个装配车间，两个生产车间分别生产A、B两种零件，装配车间的任务是把A、B两种零件组装成产品。两个生产车间每生产一个零件后，都要分别把它们送到装配车间的货架F1、F2上。F1存放零件A，F2存放零件B，F1和F2的容量均为10个零件。装配工人每次从货架上取一个零件A和零件B后组装产品。

  > * 思路：produce_a 生产A零件，生产后，将产品送到货架下，获取互斥使用权限，将产品上架，货架空间减一，释放使用权限，produce_b生产B零件，货架1，2分别互斥使用
  >
  > ~~~ c
  > semaphore mutex_f1 = 1, mutex_f2 = 1;		// 货架互斥信号量
  > semaphore empty_f1 = 10, empty_f2 = 10;		// 货架上剩余空位
  > semaphore full_f1 = 0, full_f2 = 0;			// 货架上的货物数量
  > 
  > process produce_a(){
  >     while(true){
  >         produce_a_product_A();					// 生产A零件
  >         send_A_2_f1();							// 将生产的A零件送到货架下
  >         P(empty_f1);							// 货架1还有空位可以存放零件
  >         P(mutex_f1);							// 互斥使用货架1
  >         put_A_on_f1();							// 将此产品放在货架1上
  >         V(mutex_f1);							// 释放货架1
  >         V(full_f1);								// 货架零件计数
  >     }
  > }
  > 
  > process produce_b(){
  >     while(true){
  >         produce_a_product_b();					// 生产B零件
  >         send_B_2_f2();							// 将生产的B零件
  >         P(empty_f2);							// 货架2还有空位可以存放产品
  >         P(mutex_f2);
  >         put_B_on_f2();
  >         V(mutex_f2);
  >         V(full_f2);
  >     }
  > }
  > 
  > process assemble_worker(){
  >     while(true){
  >         // 获取产品A
  >         P(full_f1);								// 货架1上有零件A
  >         P(mutex_f1);							// 获取货架1使用权
  >         get_a_from_f1();						// 取下零件A
  >         V(mutex_f1);							// 释放货架使用权
  >         V(empty_f1);							// 释放空位
  >         // 获取产品B
  >         P(full_f2);
  >         P(mutex_f2);
  >         get_b_fom_f2();
  >         V(mutex_f2);
  >         V(empty_f2);
  >         // 装配产品
  >         assemble_product();						// 装配产品
  >     }
  > }
  > ~~~
  >
  
* 10，寺庙有小和尚和老和尚若干，有一水缸，小和尚提水入缸，老和尚饮用。水缸容10桶水，水取自同一水井，每次只容去一桶水，水桶共有3个。每次入缸取水1桶，不可同时进行。

  > * 思路：水缸互斥使用，水桶为共享资源，仅有三个，水缸容量也为共享资源。
  >
  > ~~~c
  > semaphore mutex = 1;				// 互斥使用水缸信号量
  > semaphore bucket = 3;				// 水桶资源信号量
  > semaphore empty = 10;				// 水缸剩余容量
  > semaphore full = 0;					// 水缸当前水量
  > 
  > process little_monk(){
  >     while(true){
  >         P(bucket);					// 拿上桶子
  >         P(mutex);					// 互斥使用水井
  >         get_water();				// 打水
  >         V(mutex);					// 释放水井
  >         P(empty);					// 水缸还有容量盛水
  >         P(mutex);					// 互斥使用水缸
  >         put_into();					// 将水入缸
  >         V(mutex);					// 释放水缸
  >         V(full);					// 当前水量加
  >         V(bucket);					// 释放水桶
  >     }
  > }
  > 
  > process old_monk(){
  >     while(true){
  >         P(full);					// 水缸还有水
  >        	P(bucket);					// 拿上桶
  >         P(mutex);					// 等待水缸空闲
  >         drink_water();				// 老和尚喝水
  >         V(mutex);					// 释放水缸
  >         V(bucket);					// 放下水桶
  >         V(empty);					// 释放空闲水缸容量
  >     }
  > }
  > ~~~
  >
  
* 11，三个进程P1，P2，P3，他们需要通过同一设备输入各自的数据a，b，c，该输入设备必须互斥使用，而且第一个数必须由P1读取，第二个由P2读取，第三个由P3读取。然后三个进程分别对输入数据进行下列计算：
          P1: x = a + b;
          P2: y = a * b;
          P3: z = y + c - a;

  最后，P1进程通过所连接的打印机将结果x，y，z的值打印出来。用信号量实现同步。

  > 思路：使用两个信号量，让进程1，2，3按照先后顺序
  >
  > ~~~c
  > semaphore ab = 0, bc = 0, ca = 0;		// 控制进程执行顺序
  > semaphore count = -2;					// 输入计数
  > semaphore finish = 0;					// 运算结束信号量
  > int a, b, c;
  > int x, y, z;
  > 
  > proccess P1(){
  >     a = input();			// a 最先输入
  >     V(count);				// 计算输入次数
  >     V(ab);					// 唤醒b的输入进程
  >     P(count);				// 输入完成后
  >     x = a + b;				// 进行运算
  >     V(count);				// 唤醒下次运算
  >     P(finish);				// 所有输入都已结束
  >     print(x,y,z);			// 打印x，y，z的值
  > }
  > 
  > process P2(){
  >     P(ab);					// 输入被唤醒
  >     b = input();			// 输入b
  >     V(count);				// 输入次数计数
  >     V(bc);					// 唤醒c的输入进程
  >     P(count);				// 输入完成后，计算被唤醒
  >     y = a * b;				// 运算
  >     V(count);				// 运算结束，唤醒下次运算
  >     V(bc);					// 唤醒第三个进程，允许第三个进程进行运算
  > }
  > 
  > process P3(){
  >     P(bc);					// 输入被唤醒
  >     c = input();			// 输入c
  >     V(count);				// 输入次数计数
  >     P(bc);					// 第二个运算已经结束，被唤醒
  >     z = y + c - a;			// 进行运算
  >     V(finish);				// 运算结束
  > }
  > 
  > ~~~
  >
  > 

