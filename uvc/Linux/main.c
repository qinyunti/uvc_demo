#include "test.h"

int main(void)
{
    #ifdef TEST
        test_main(0, 0);
    #endif
    #ifdef TEST_IAD
    test_iad_main(0, 0);
    #endif
    #ifdef TEST_SAMEVIDPID
    test_samevidpid_main(0, 0);
    #endif
}