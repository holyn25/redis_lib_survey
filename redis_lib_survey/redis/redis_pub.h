#pragma once


/****************************** pub ******************************/
//��ʼ��
bool redis_init();

//����
bool redis_uninit();
/****************************** pub ******************************/


/****************************** key ******************************/
//�ж�key�Ƿ����
bool redis_exists(const std::string& key);

/*
* �ж�key��ʣ����������
*   > 0: �� key ʣ����������ڣ��룩
*  -3��  ����
*  -2��  key ������
*  -1��  �� key ���ڵ�û������ʣ��ʱ��
*/
int redis_ttl(const std::string& key);

//ɾ��key
bool redis_del(const std::string& key);
/****************************** key ******************************/


/****************************** string ******************************/
//string��ֵ����
bool redis_set_i(const std::string& key, int value, int timeout = 0);
bool redis_get_i(const std::string& key, int& value);
bool redis_set_i64(const std::string& key, __int64 value, int timeout = 0);
bool redis_get_i64(const std::string& key, __int64& value);
/****************************** string ******************************/


/****************************** hash ******************************/
//hash��ֵ����
bool redis_hset_i(const std::string& key, const std::string& name, int value);
bool redis_hget_i(const std::string& key, const std::string& name, int& value);
bool redis_hset_i64(const std::string& key, const std::string& name, __int64 value);
bool redis_hget_i64(const std::string& key, const std::string& name, __int64& value);
/****************************** hash ******************************/