
#include "GolDef.h"
#ifdef THREADPARAM

#include <thread>

/** ���������̻߳ص�
@param [in] pirntCount ѭ������
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
