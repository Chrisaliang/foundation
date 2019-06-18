typedef int semaphor;
int i = 3;

semaphor chopstick[5] = {1, 1, 1, 1, 1};

Pi()
{
    do
    {
        P(chopstick[i]);
        P(chopstick[(i + 1) % 5]);
        eat;
        V(chopstick[(i + 1) % 5]);
        V(chopstick[i]);
        think;
    } while (1);
}

semaphor mutex = 1;

Pi()
{
    do
    {
        P(mutex);
        P(chopstick[i]);
        P(chopstick[(i + 1) % 5]);
        V(mutex);
        eat;
        V(chopstick[(i + 1) % 5]);
        V(chopstick[i]);
        think;
    } while (1);
    
}
