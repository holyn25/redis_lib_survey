#include "pch.h"

#include "redis_test.h"


#include "redis_pub.h"

void test_0()
{
    redis_init();

    bool b = redis_key_exist("b");

    int i = -12;
    redis_key_set_i("a", -100, 5);
    redis_key_get_i("a", i);

    __int64 i64 = -12;
    redis_key_set_i64("b", -100000, 10);
    redis_key_get_i64("b", i64);

    b = redis_key_del("abc");
    
    redis_uninit();
}


void redis_test()
{
    test_0();
}