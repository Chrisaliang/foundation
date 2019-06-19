typedef int boolean;
#define true 1
#define false 0

boolean flag[2] = {0, 0};
int turn = 0;
// flag[0] = false;
// flag[1] = false;

void P0()
{
    while (true)
    {
        flag[0] = true;
        turn = 1;
        while (flag[1] && (turn == 1));
        critical_section();
        flag[0] = false;
    }
}

void P1()
{
    while (true)
    {
        flag[1] = true;
        turn = 0;
        while (flag[0] && (turn == 0));
        critical_section();
        flag[1] = false;
    }
}
