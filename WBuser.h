#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

using namespace std;

class wbuser
{
protected:
	int Ttime;//ע��ʱ��
public:
	int n;//��¼�ǵڼ���λ�û�
	vector <int> friends;//��¼friends��n
	int birthday[3];//�����¼��������
	string location;//���ڵ�
	string id;//�û���
	string name;//�ǳ�
	wbuser(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation);
	string PASSWORD;
};

