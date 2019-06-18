typedef semaphore
{
    int value;
};

semaphore mutex = 1;
semaphore empty = n;
semaphore full = 0;

producer()
{
    while (1)
    {
        produce an item in nextp;        // 生产数据
        P(empty);
        P(mutex);
        add nextp to buffer;
        V(mutex);
        V(full);
    }
}

consumer()
{
    while (1)
    {
        P(full);
        P(mutex);
        remove an item from buffer;
        V(mutex);
        V(empty);
        consume the item;
    }
}
