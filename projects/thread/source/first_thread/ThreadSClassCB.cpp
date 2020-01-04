
#include "GolDef.h"
#ifdef THREADSLCLASSCB

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

int main()
{
    CallBack* pCallBack = new CallBack();
    std::thread td(&CallBack::ThreadRun, pCallBack);
    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    delete pCallBack;
    pCallBack = NULL;
    return 1;
}

#endif // THREADSLCLASSCB
