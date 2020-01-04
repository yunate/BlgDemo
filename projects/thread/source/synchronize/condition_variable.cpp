
#include "GolDef.h"
#ifdef CONDITION_VARIABLE

#include <thread>
#include <condition_variable>

/** 互斥量
*/
static std::mutex s_mutex;
static std::condition_variable s_con;

/** 不带参数的线程回调
*/
void ThreadCallBack()
{
    std::unique_lock<std::mutex> lck(s_mutex);
    s_con.wait(lck);
    ColorPrintf(Red, "ThreadCallBack\r\n");
}

int main()
{
    std::thread td(ThreadCallBack);

    {
        // 让主线程先获取所有权
        ::Sleep(1000);
        ColorPrintf(Green, "main\r\n");
        s_con.notify_all();
    }

    td.join();
    getchar();
    return 1;
}

#endif // MUTEX_TRYLOCK
