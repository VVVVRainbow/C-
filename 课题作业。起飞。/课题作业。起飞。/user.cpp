#include "user.h"
using namespace std;




user::user(string PAWO,string sid,string sname,int s1,int s2,int s3,string slocation)
{
	id = sid;
	PASSWORD = PAWO;
	name = sname;//��ʼ���ǳ�
	birthday[0] = s1; birthday[1] = s2; birthday[2] = s3;//��ʼ������
	location = slocation;//��ʼ�����ڵ�
}
