
#include "GolDef.h"
#ifdef THREADLAMBDACLASSCB

#include <thread>

class CallBack
{
public:
    /** �߳�������
    */
    void ThreadRun()
    {
        ColorPrintf(Green, "ThreadRun\r\n");
    }
};

int main()
{
    CallBack* pCallBack = new CallBack();
    std::thread td([](CallBack* p) 
        {
            if (p != nullptr)
            {
                p->ThreadRun();
            }
        }, pCallBack);

    for (int i = 0; i < 100; ++i)
    {
        ColorPrintf(Green, "main\r\n");
    }

    td.join();
    delete pCallBack;
    pCallBack = NULL;
    return 1;
}

#endif // THREADLAMBDACLASSCB
