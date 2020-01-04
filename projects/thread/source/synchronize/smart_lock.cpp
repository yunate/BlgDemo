
#include "GolDef.h"
#ifdef SMART_LOCK

#include <thread>
#include <mutex>

/** 互斥量
*/
static std::recursive_timed_mutex s_mutex;

/** 不带参数的线程回调
*/
void ThreadCallBack()
{
    std::unique_lock<std::recursive_timed_mutex> lockGuard(s_mutex);

    // 获取所有权后不释放,改为1的情况下
    ::Sleep(1);
    ColorPrintf(Red, "ThreadCallBack\r\n");
}

int main()
{
    std::thread td(ThreadCallBack);

    {
        // 让线程先获取所有权
        ::Sleep(1000);
        std::unique_lock<std::recursive_timed_mutex> 
            lockGuard(s_mutex, std::defer_lock_t());

        // 如果ThreadCallBack中的sleep时间小于下面的，tryRes就为true，否重为false 
        // 证明了try_lock_for是在一段时间内尝试获取所有权，而不是获取所有权一段时间
        bool tryRes = lockGuard.try_lock_for(std::chrono::milliseconds(5000));
        ::Sleep(999999999);
    }

    td.join();
    getchar();
    return 1;
}

#endif // MUTEX_TRYLOCK
