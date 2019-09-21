#include "pch.h"

#include "redis_import.h"
#include "redis_cfg.h"
#include "redis_func.h"

acl::redis_client*      conn;
acl::redis_string*      conn_str;
acl::redis_key*         conn_key;

bool redis_init()
{
    if (conn_str)
    {
        return true;
    }

    acl::acl_cpp_init();

    conn = new acl::redis_client(redis_addr, redis_conn_timeout, redis_rw_timeout, false);
    conn_str = new acl::redis_string(conn);
    conn_key = new acl::redis_key(conn);

    return false;
}

bool redis_uninit()
{
    if (conn_str)
    {
        delete conn_str;
        conn_str = 0;
    }

    if (conn_key)
    {
        delete conn_key;
        conn_key = 0;
    }

    if (conn)
    {
        delete conn;
        conn = 0;
    }
    
    return true;
}

bool redis_key_set_i(const std::string& key, int value, int timeout)
{
    if (timeout <= 0)
    {
        if (conn_str->set(key.c_str(), i_2_str(value).c_str()))
        {
            return true;
        }
    }
    else
    {
        if (conn_str->setex(key.c_str(), i_2_str(value).c_str(), timeout))
        {
            return true;
        }
    }

    return false;
}

bool redis_key_get_i(const std::string& key, int& value)
{
    acl::string value_str;
    if (conn_str->get(key.c_str(), value_str))
    {
        value = atoi(value_str.c_str());

        return true;
    }

    return false;
}

bool redis_key_set_i64(const std::string& key, __int64 value, int timeout)
{
    if (timeout <= 0)
    {
        if (conn_str->set(key.c_str(), i64_2_str(value).c_str()))
        {
            return true;
        }
    }
    else
    {
        if (conn_str->setex(key.c_str(), i64_2_str(value).c_str(), timeout))
        {
            return true;
        }
    }

    return false;
}

bool redis_key_get_i64(const std::string& key, __int64& value)
{
    acl::string value_str;
    if (conn_str->get(key.c_str(), value_str))
    {
        value = _atoi64(value_str.c_str());

        return true;
    }

    return false;
}

bool redis_key_exist(const std::string& key)
{
    if (conn_key->exists(key.c_str()))
    {
        return true;
    }

    return false;
}

int redis_key_ttl(const std::string& key)
{
    return conn_key->ttl(key.c_str());
}

bool redis_key_del(const std::string& key)
{
    if (1 == conn_key->del(key.c_str()))
    {
        return true;
    }

    return false;
}