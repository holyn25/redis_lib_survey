#include "pch.h"

#include "redis_test.h"


#include "redis_pub.h"

void test_0()
{
    redis_init();

    bool b = redis_exists("b");    

    int i = -12;
    redis_set_i("a", -100, 5);
    redis_get_i("a", i);

    __int64 i64 = -12;
    redis_set_i64("b", -100000, 10);
    redis_get_i64("b", i64);

    
    redis_hset_i("h", "a", 0);
    redis_hset_i64("h", "b", 123456789012345678L);

    redis_hget_i("h", "a", i);
    redis_hget_i64("h", "b", i64);
    
    redis_uninit();
}


void redis_test()
{
    test_0();
}