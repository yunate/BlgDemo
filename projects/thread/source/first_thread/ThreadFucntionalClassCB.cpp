
#include "GolDef.h"
#ifdef THREADFUNCTIONALCLASSCB

#include <thread>
#include <functional>

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
    std::function<void()> func = std::bind(&CallBack::ThreadRun, pCallBack);
    std::thread td(func);

    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    delete pCallBack;
    pCallBack = NULL;
    return 1;
}

#endif // THREADFUNCTIONALCLASSCB
