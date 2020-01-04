
#include "GolDef.h"
#ifdef THREADCLASSCALLBACK

#include <thread>

class CallBack
{
public:
    /** 线程中运行
    */
    void ThreadRun()
    {
        ColorPrintf(Green, "ThreadRun\r\n");
    }
};

void ThreadCallBack(CallBack* p)
{
    if (p != nullptr)
    {
        p->ThreadRun();
    }
}

int main()
{
    CallBack* pCallBack = new CallBack();
    std::thread td(ThreadCallBack, pCallBack);

    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    delete pCallBack;
    pCallBack = NULL;
    return 1;
}

#endif // THREADPARAM
