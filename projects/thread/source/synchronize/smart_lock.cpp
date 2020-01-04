
#include "GolDef.h"
#ifdef SMART_LOCK

#include <thread>
#include <mutex>

/** ������
*/
static std::recursive_timed_mutex s_mutex;

/** �����������̻߳ص�
*/
void ThreadCallBack()
{
    std::unique_lock<std::recursive_timed_mutex> lockGuard(s_mutex);

    // ��ȡ����Ȩ���ͷ�,��Ϊ1�������
    ::Sleep(1);
    ColorPrintf(Red, "ThreadCallBack\r\n");
}

int main()
{
    std::thread td(ThreadCallBack);

    {
        // ���߳��Ȼ�ȡ����Ȩ
        ::Sleep(1000);
        std::unique_lock<std::recursive_timed_mutex> 
            lockGuard(s_mutex, std::defer_lock_t());

        // ���ThreadCallBack�е�sleepʱ��С������ģ�tryRes��Ϊtrue������Ϊfalse 
        // ֤����try_lock_for����һ��ʱ���ڳ��Ի�ȡ����Ȩ�������ǻ�ȡ����Ȩһ��ʱ��
        bool tryRes = lockGuard.try_lock_for(std::chrono::milliseconds(5000));
        ::Sleep(999999999);
    }

    td.join();
    getchar();
    return 1;
}

#endif // MUTEX_TRYLOCK
