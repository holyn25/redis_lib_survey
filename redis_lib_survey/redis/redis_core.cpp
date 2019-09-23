#include "pch.h"

#include "redis_import.h"
#include "redis_cfg.h"
#include "redis_func.h"

static acl::redis_client*      conn;
static acl::redis_key*         key_cmd;
static acl::redis_string*      str_cmd;
static acl::redis_hash*        hash_cmd;

bool redis_init()
{
    if (str_cmd)
    {
        return true;
    }

    acl::acl_cpp_init();

    conn = new acl::redis_client(redis_addr, redis_conn_timeout, redis_rw_timeout, false);
    key_cmd = new acl::redis_key(conn);
    str_cmd = new acl::redis_string(conn);
    hash_cmd = new acl::redis_hash(conn);

    return false;
}

bool redis_uninit()
{
    release_point(str_cmd);
    release_point(key_cmd);
    release_point(hash_cmd);
    release_point(conn);
    
    return true;
}

bool redis_exists(const std::string& key)
{
    if (key_cmd->exists(key.c_str()))
    {
        return true;
    }

    return false;
}

int redis_ttl(const std::string& key)
{
    return key_cmd->ttl(key.c_str());
}

bool redis_del(const std::string& key)
{
    if (1 == key_cmd->del(key.c_str()))
    {
        return true;
    }

    return false;
}

bool redis_set_i(const std::string& key, int value, int timeout)
{
    if (timeout <= 0)
    {
        if (str_cmd->set(key.c_str(), i_2_str(value).c_str()))
        {
            return true;
        }
    }
    else
    {
        if (str_cmd->setex(key.c_str(), i_2_str(value).c_str(), timeout))
        {
            return true;
        }
    }

    return false;
}

bool redis_get_i(const std::string& key, int& value)
{
    acl::string value_str;
    if (str_cmd->get(key.c_str(), value_str))
    {
        value = atoi(value_str.c_str());

        return true;
    }

    return false;
}

bool redis_set_i64(const std::string& key, __int64 value, int timeout)
{
    if (timeout <= 0)
    {
        if (str_cmd->set(key.c_str(), i64_2_str(value).c_str()))
        {
            return true;
        }
    }
    else
    {
        if (str_cmd->setex(key.c_str(), i64_2_str(value).c_str(), timeout))
        {
            return true;
        }
    }

    return false;
}

bool redis_get_i64(const std::string& key, __int64& value)
{
    acl::string value_str;
    if (str_cmd->get(key.c_str(), value_str))
    {
        value = _atoi64(value_str.c_str());

        return true;
    }

    return false;
}

bool redis_hset_i(const std::string& key, const std::string& name, int value)
{
    if (hash_cmd->hset(key.c_str(), name.c_str(), i_2_str(value).c_str()))
    {
        return true;
    }

    return false;
}

bool redis_hset_i64(const std::string& key, const std::string& name, __int64 value)
{
    if (hash_cmd->hset(key.c_str(), name.c_str(), i64_2_str(value).c_str()))
    {
        return true;
    }

    return false;
}

bool redis_hget_i(const std::string& key, const std::string& name, int& value)
{
    acl::string value_str;
    if (hash_cmd->hget(key.c_str(), name.c_str(), value_str))
    {
        value = atoi(value_str.c_str());

        return true;
    }

    return false;
}

bool redis_hget_i64(const std::string& key, const std::string& name, __int64& value)
{
    acl::string value_str;
    if (hash_cmd->hget(key.c_str(), name.c_str(), value_str))
    {
        value = _atoi64(value_str.c_str());

        return true;
    }

    return false;
}