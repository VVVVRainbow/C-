#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;
using namespace std;

class groups
{
public:
	vector<int> nums;//һ����ĳ�Ա��n�ļ�¼��
	int ng;//��¼�ǵڼ���Ⱥ
	int master;//Ⱥ��
	vector<int> adm;
	string name;//Ⱥ��
	string id;//Ⱥ�˺�
	groups(int);
	groups(int i, string,string aname);
	groups(string,string);
};

/*
Ⱥ��
����һ��Ⱥ�ģ�Ⱥ�˺ţ�Ⱥ�����м�����Ա��������Ա�� Ⱥ��n���м����������������n��\n
����
*/