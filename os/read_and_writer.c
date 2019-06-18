typedef int semaphor;

int count = 0;
semaphor mutex = 1;
semaphor rw = 1;

writer()
{
    while (1)
    {
        // psuedocode
        P(rw);
        writing;
        V(rw);
    }
}

reader()
{
    while (1)
    {
        // psuedocode
        P(mutex);           // 互斥访问count变量
        if (count == 0)     // 当第一个读进程读共享文件时
        {
            P(rw);          // 阻止写进程写
        }
        count++;            // 读者计数器加一
        V(mutex);           // 释放互斥变量count
        reading;
        P(mutex);           // 互斥访问count变量
        count--;            // 读者计数器减一
        if (count == 0)     // 当最后一个读进程读完共享文件
        {
            V(rw);          // 允许写进程写
        }
        V(mutex);           // 释放互斥变量
    }
}
