#pragma once


/****************************** pub ******************************/
//初始化
bool redis_init();

//结束
bool redis_uninit();
/****************************** pub ******************************/


/****************************** key ******************************/
//判断key是否存在
bool redis_exists(const std::string& key);

/*
* 判断key的剩余生存周期
*   > 0: 该 key 剩余的生存周期（秒）
*  -3：  出错
*  -2：  key 不存在
*  -1：  当 key 存在但没有设置剩余时间
*/
int redis_ttl(const std::string& key);

//删除key
bool redis_del(const std::string& key);
/****************************** key ******************************/


/****************************** string ******************************/
//string数值操作
bool redis_set_i(const std::string& key, int value, int timeout = 0);
bool redis_get_i(const std::string& key, int& value);
bool redis_set_i64(const std::string& key, __int64 value, int timeout = 0);
bool redis_get_i64(const std::string& key, __int64& value);
/****************************** string ******************************/


/****************************** hash ******************************/
//hash数值操作
bool redis_hset_i(const std::string& key, const std::string& name, int value);
bool redis_hget_i(const std::string& key, const std::string& name, int& value);
bool redis_hset_i64(const std::string& key, const std::string& name, __int64 value);
bool redis_hget_i64(const std::string& key, const std::string& name, __int64& value);
/****************************** hash ******************************/