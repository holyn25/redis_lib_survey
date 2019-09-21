#pragma once

//��ʼ��
bool redis_init();

//����
bool redis_uninit();

//��ֵ����
bool redis_key_set_i(const std::string& key, int value, int timeout = 0);
bool redis_key_get_i(const std::string& key, int& value);
bool redis_key_set_i64(const std::string& key, __int64 value, int timeout = 0);
bool redis_key_get_i64(const std::string& key, __int64& value);

//�ж�key�Ƿ����
bool redis_key_exist(const std::string& key);

/*
* �ж�key��ʣ����������
*   > 0: �� key ʣ����������ڣ��룩
*  -3��  ����
*  -2��  key ������
*  -1��  �� key ���ڵ�û������ʣ��ʱ��
*/
int redis_key_ttl(const std::string& key);

//ɾ��key
bool redis_key_del(const std::string& key);
