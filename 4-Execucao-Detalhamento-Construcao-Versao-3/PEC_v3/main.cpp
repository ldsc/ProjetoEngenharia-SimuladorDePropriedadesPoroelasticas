#include "CSimulador.h"


#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char** argv) {
    
#ifdef _WIN32
    
    SetConsoleOutputCP(CP_UTF8);
#endif
   

    CSimulador app;
    app.Run();
    return 0;
}