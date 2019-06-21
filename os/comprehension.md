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

* 

