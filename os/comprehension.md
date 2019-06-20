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

* 



