#include "wegroups.h"

wegroups::wegroups(int i)
{
	master = i + 1;
	string app;
	cout << "��������Ҫ����Ⱥ���˺ţ�";
	cin >> app;
	id = app;
	cout << "��������Ҫ����Ⱥ�����ƣ�";
	cin >> app;
	name = app;
}

wegroups::wegroups(string aid, string aname)
{
	id = aid;
	name = aname;
	ng = 0; master = 1;
}

