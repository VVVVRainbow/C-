#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

using namespace std;

class weuser
{
protected:
	int Ttime;//ע��ʱ��
public:
	int n;//��¼�ǵڼ���λ�û�
	vector <int> friends;//��¼friends��n
	vector <int> groups;
	int birthday[3];//�����¼��������
	string location;//���ڵ�
	string id;//�û���
	string name;//�ǳ�
	weuser(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation);
	weuser(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation, int);
	string PASSWORD;
	int QQn;//������еĻ�����ӦQQ��n��
};

