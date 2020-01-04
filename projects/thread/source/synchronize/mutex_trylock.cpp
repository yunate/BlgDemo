
#include "GolDef.h"
#ifdef MUTEX_TRYLOCK

#include <thread>
#include <mutex>

/** ������
*/
static std::mutex s_mutex;

/** �����������̻߳ص�
*/
void ThreadCallBack()
{
    for (int i = 0; i < 100; ++i)
    {
        s_mutex.lock();
        ColorPrintf(Red, "ThreadCallBack\r\n");
        s_mutex.unlock();
        ::Sleep(1);
    }
}

void wait()
{
    while (!s_mutex.try_lock())
    {
        // do somethings
    }
}

int main()
{
    std::thread td(ThreadCallBack);

    for (int i = 0; i < 100; ++i)
    {
        s_mutex.lock();
        ColorPrintf(Green, "main\r\n");
        s_mutex.unlock();
        ::Sleep(1);
    }

    td.join();
    getchar();
    return 1;
}

#endif // MUTEX_TRYLOCK
