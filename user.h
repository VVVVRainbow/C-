#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

using namespace std;

class user
{
protected:
	int Ttime;//注册时间
public:
	int n;//记录是第几个位用户
	vector <int> friends;//记录friends的n
	vector <int> groups;
	int birthday[3];//数组记录出生日期
	string location;//所在地
	string id;//用户名
	string name;//昵称
	user(string PAWO, string sid, string sname, int s1, int s2, int s3, string slocation);
	string PASSWORD;
};

