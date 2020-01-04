
#include "GolDef.h"
#ifdef CONDITION_VARIABLE

#include <thread>
#include <condition_variable>

/** ������
*/
static std::mutex s_mutex;
static std::condition_variable s_con;

/** �����������̻߳ص�
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
        // �����߳��Ȼ�ȡ����Ȩ
        ::Sleep(1000);
        ColorPrintf(Green, "main\r\n");
        s_con.notify_all();
    }

    td.join();
    getchar();
    return 1;
}

#endif // MUTEX_TRYLOCK
