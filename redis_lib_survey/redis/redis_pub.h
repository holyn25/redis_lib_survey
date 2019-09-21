#pragma once

//初始化
bool redis_init();

//结束
bool redis_uninit();

//数值操作
bool redis_key_set_i(const std::string& key, int value, int timeout = 0);
bool redis_key_get_i(const std::string& key, int& value);
bool redis_key_set_i64(const std::string& key, __int64 value, int timeout = 0);
bool redis_key_get_i64(const std::string& key, __int64& value);

//判断key是否存在
bool redis_key_exist(const std::string& key);

/*
* 判断key的剩余生存周期
*   > 0: 该 key 剩余的生存周期（秒）
*  -3：  出错
*  -2：  key 不存在
*  -1：  当 key 存在但没有设置剩余时间
*/
int redis_key_ttl(const std::string& key);

//删除key
bool redis_key_del(const std::string& key);
