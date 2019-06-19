# 第二章：进程管理

## 2.3 进程同步

* 一个正在访问临界资源的进程由于申请IO操作而被中断时，它（<font color=red size=4>允许其他进程抢占处理器，但不得进入该进程的临界区</font>）
* 临界区是指并发进程访问共享变量段的（<font color=red size=4>代码程序</font>）
* 以下（<font color=red size=4>B</font>）属于临界资源
  A. 磁盘存储介质                       B. 公用队列
  C. 私用数据                               D. 可重入的程序代码
* 在操作系统中，要对并发程序进行同步的原因是（<font color=red size=4>并发进程是异步的</font>）
* 操作系统中P、V操作是一种（<font color=red size=4>低级进程通信原语</font>）
* 可以被多个进程在任意时刻共享的代码必须是（<font color=red size=4>不允许任何修改的代码</font>）
* 一个进程映像由程序、数据及PCB组成，其中（<font color=red size=4>共享程序段</font>）必须用可重入代码编写
* 以下关于管程的叙述中，错误的是（    ）。
  <font color=green size=4>A. 管程是进程同步工具，解决信号量机制大量同步操作分散的问题</font>
  <font color=green size=4>B. 管程每次只允许一个进程进入管程</font>
  <font color=red size=4>***C. 管程中signal操作的作用和信号量机制中的V操作相同（信号量机制中的V操作一定会改变信号量的值s =  s + 1。管程中的signal操作是针对某个条件变量的，若不存在因该条件而阻塞的进程，则signal操作不会产生任何影响）***</font>
  <font color=green size=4>***D. 管程是被进程调用的，管程是语法范围，无法创建和撤销***</font>
* 需要互斥操作的内容是<font color=red size=4>共享资源</font>
* 互斥信号量的初始值永远是<font color=red size=4> 1 </font>
* 管程中的x.wait()所作的是 <font color=red size=4>阻塞该进程，并将之插入x的阻塞队列中</font>

