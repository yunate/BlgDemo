
#include "GolDef.h"
#ifdef THREADPARAM

#include <thread>

/** 带参数的线程回调
@param [in] pirntCount 循环次数
*/
void ThreadCallBack(int pirntCount)
{
    for (int i = 0; i < pirntCount; ++i)
    {
        ColorPrintf(Red, "ThreadCallBack\r\n");
    }
}

int main()
{
    std::thread td(ThreadCallBack, 10);

    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    return 1;
}

#endif // THREADPARAM
