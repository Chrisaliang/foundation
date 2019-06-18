#include <stdlib.h>

typedef int semaphor;
int random;
semaphor offer1 = 0, offer2 = 0, offer3 = 0;
semaphor finish = 0;

process offer()
{
    while (1)
    {
        random = rand(); // 产生一个随机整数
        random = random % 3;
        if (random == 0)
        {
            V(offer1); // 提供烟草和纸
        }
        else if (random == 1)
        {
            V(offer2); // 提供烟草和胶水
        }
        else
        {
            V(offer3); // 提供纸和胶水
        }
        // 任意两种材料放在桌子上
        P(finish);
    }
}

process smoker1() /** 拥有烟草者 */
{
    while (1)
    {
        P(offer3);
        拿起纸和胶水，卷成烟，抽掉
        V(finish);
    }
}

process smoker2() /** 拥有纸者 */
{
    while (1)
    {
        P(offer2);
        拿起烟草和胶水，卷成烟，抽掉
        V(finish);
    }
}

process smoker3() /** 拥有胶水者 */
{
    while (1)
    {
        P(offer1);
        拿起烟草和纸，卷成烟，抽掉
        V(finish);
    }
}
