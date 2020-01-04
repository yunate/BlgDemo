
#include "GolDef.h"
#ifdef FIRSTTHREAD

#include <thread>

/** 不带参数的线程回调
*/
void ThreadCallBack()
{
    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Red, "ThreadCallBack\r\n");
    }
}

int main()
{
    std::thread td(ThreadCallBack);

    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    return 1;
}

#endif // FIRSTTHREAD
