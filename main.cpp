#include <iostream>
#include <windows.h>
#include <shobjidl.h>

/**
 * https://stackoverflow.com/questions/16019650/hide-a-console-c-program-from-taskbar
 */
void HideInTaskbar() {
    ITaskbarList *pTaskList = nullptr;
    HRESULT initRet = CoInitialize(nullptr);
    if (initRet != S_OK) {
        std::cout << "Hide in taskbar failure, CoInitialize=" << initRet << std::endl;
        return;
    }
    HRESULT createRet = CoCreateInstance( CLSID_TaskbarList,
                                          nullptr,
                                          CLSCTX_INPROC_SERVER,
                                          IID_ITaskbarList,
                                          (LPVOID*)&pTaskList );
    if(createRet == S_OK) {
        pTaskList->DeleteTab(GetConsoleWindow());
        pTaskList->Release();
    } else {
        std::cout << "Hide in taskbar failure, CoCreateInstance=" << createRet << std::endl;
    }

    CoUninitialize();
}

int main() {
    HideInTaskbar();

    std::cout << "This is empty executable file" << std::endl;
    std::cout << "Press Enter to exit" << std::endl;

    getchar();
    return 0;
}
