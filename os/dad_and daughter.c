typedef int semaphor;

semaphor plate = 1, apple = 0, orange = 0;

dad() // 父亲进程
{
    while (1)
    {
        // pseudocode
        prepare an apple;
        P(plate);                   // 互斥向盘子中取放水果
        put the apple on the plate; // 向盘中放苹果
        V(apple);                   // 允许取苹果
    }
}

mom()
{
    while (1)
    {
        // psuedocode
        prepare an orange;
        P(plate);
        put the orange on the plate;
        V(orange);
    }
}

son()
{
    while (1)
    {
        // psuedocode
        P(orange);
        take an orange from the plate;
        V(plate);
        eat the orange;
    }
}

daughter()
{
    while (1)
    {
        // psuedocode
        P(apple);
        take an apple from the plate;
        V(plate);
        eat the apple;
    }
}
