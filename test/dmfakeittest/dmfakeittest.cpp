
#include "dmfakeit.h"

int main( int argc, char* argv[] ) {

    Idmfakeit* module = dmfakeitGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
