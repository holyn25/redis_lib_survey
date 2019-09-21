#pragma once

std::string i_2_str(int i)
{
    char buf[32] = { 0 };
    _itoa_s(i, buf, ARRAYSIZE(buf), 10);

    return buf;
}

std::string i64_2_str(__int64 i64)
{
    char buf[32] = { 0 };
    _i64toa_s(i64, buf, ARRAYSIZE(buf), 10);
                
    return buf;
}