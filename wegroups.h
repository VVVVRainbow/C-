#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;
using namespace std;

class wegroups
{
public:
	vector<int> nums;//һ����ĳ�Ա��n�ļ�¼��
	int ng;//��¼�ǵڼ���Ⱥ
	int master;//Ⱥ��
	string name;//Ⱥ��
	string id;//Ⱥ�˺�
	wegroups(int);
	wegroups(string, string);
};
