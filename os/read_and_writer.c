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
        P(mutex);
        if (count == 0)
        {
            P(rw);
        }
        count++;
        V(mutex);
        reading;
        P(mutex);
        count--;
        if (count == 0)
        {
            V(rw);
        }
        V(mutex);
    }
}
