#include <iostream>
#include <string>
#include "user.h"
#include "wegroups.h"
#include "weuser.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "groups.h"

using std::cout;
using  std::cin;

//�ļ��ĵ�һ�����ǵ�ǰ�û�����

void QQ();//������½
void wechat();
void WEIBO();
void JRQQ(int i);//��½����
void CGdatas(int);
void CGgroups(int);
void newgroups(int);
void addgroups(int i);
void entergroups(int i);
void CJgroups(int i, int k1);
void changegroupsname(int i, int k1);
void quitgroups(int i, int i1, int k1);
void quitgroups(int i, int k1);
void delgroups(int i, int k1);
void CGfriends(int);
void ZCQQ();
void DLQQ();
void addfriend(int );
void delfriend(int );
void fresh_user();
void fresh_groups();
void readgroups();
void readusers();
void readfriends();
void addgroupnums(int);
void changegroupsname(int i, int k1);

void readweusers();
void readwefriends();
void readwegroups();
void ZCwechat();
void DLwechat();
void JRwechat(int i);
void BANGDINGQQ(int i);
void CGwedatas(int i);
void CGwefriends(int i);
void CGwegroups(int i);
void addwefriend(int i);
void delwefriend(int i);
void newwegroups(int i);
void enterwegroups(int i);
void changewegroupsname(int i, int k1);
void quitwegroups(int i, int i1, int k1);
void quitwegroups(int i, int k1);
void delwegroups(int i, int k1);
void addwegroupnums(int j);

void WEIBO();
void JRWB(int i);//��½����
void CGWBdatas(int);
void CGWBfriends(int);
void ZCWB();
void DLWB();
void addWBfriend(int);
void delWBfriend(int);
void fresh_WBuser();
void readWBusers();
void readWBfriends();


//3���ļ�����ʱ����1.user.txt �����������˺�7������  2.���� �������������������Ϣ��ֱ�ӷ��ǵڼ��������ˣ� 3.�������� Ⱥ��������Ⱥ����Ϣ
vector <user> v;
vector <groups> g;

vector <weuser> w;
vector <wegroups> wg;

int main() {
	
	/*
	Ⱥ��
	����һ��Ⱥ�ģ�Ⱥ�˺ţ�Ⱥ�����м�����Ա��������Ա�� Ⱥ��n���м����������������n��\n
	����
	*/
	readusers();
	readfriends();
	readgroups();
	readweusers();
	readwefriends();
	readWBusers();
	readWBfriends();	
	readwegroups();
	
	while (1)
	{
		system("cls");
		cout << "          ��ӭʹ��          \n\n"
			"��ѡ������Ҫ�ķ���\n"
			"1.QQ\n"
			"2.΢��\n"
			"3.΢��\n" << endl;
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			QQ(); break;
		case '2':
			wechat(); break;
		case '3':
			WEIBO(); break;
		default:
			cout << "������������" << endl;
		}
	}
}

void fresh_user()
{
	fstream suser("user.txt", ios::out);
	suser << (int)v.size() << endl;
	for (int i = 0; i <(int)v.size(); i++)
	{
		suser << v[i].id << " " << v[i].name << " " << v[i].PASSWORD << " " << v[i].birthday[0] << " " << v[i].birthday[1] << " " << v[i].birthday[2] << " " << v[i].location << endl;
	}
	suser.close();
}

void fresh_groups()
{
	fstream sgroups("groups.txt", ios::out);
	sgroups << (int)g.size() << endl;
	for (int i = 0; i <(int)g.size(); i++)
	{
		sgroups << g[i].id << " " << g[i].name << " " << (int)g[i].nums.size() << " ";
		for (int j = 0; j < (int)g[i].nums.size(); j++)
		{
			sgroups << g[i].nums[j] << " ";
		}
		sgroups << g[i].master << " " << (int)g[i].adm.size() << " ";
		for (int j = 0; j < (int)g[i].adm.size(); j++)
		{
			sgroups << g[i].adm[j] << " ";
		}
		sgroups << endl;
	}

	sgroups.close();
	/*v.~vector<user>();
	g.~vector<groups>();
	readusers();
	readfriends();
	readgroups();
*/
}

void fresh_friends()
{
	fstream sfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)v.size(); i++)
	{
		sfriends << (int)v[i].friends.size() << " ";
		for (int j = 0; j < (int)v[i].friends.size(); j++)
		{
			sfriends << v[i].friends[j] << " ";
		}
		sfriends << endl;
	}
	sfriends.close();
}

void readusers()
{
	//***************
	int num = 0;//��ȡ��һ�����֣���ʾ��ǰ�û�������
	string id; string name; string password; int y; int m; int d; string location;
	fstream vuser("user.txt");
	vuser >> num;
	for (int i = 0; i < num; i++)
	{
		vuser >> id >> name >> password >> y >> m >> d >> location;
		v.push_back(user(password, id, name, y, m, d, location));
	}
	vuser.close();
	for (int i = 0; i < (int)v.size(); i++)
	{
		v[i].n = i + 1;
	}
}

void readfriends()
{
	//********************
	fstream vfriends("friends.txt");
	//numf���������
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		vfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			vfriends >> k;
			v[i].friends.push_back(k);
		}
	}
	vfriends.close();
}

void readgroups()
{
	//************************
	//��ȡgroups�ļ�
	int gnum = 0;//��ȡ��һ�����֣���ʾ��ǰ�û�������
	string gid; string gname;  int pn;
	fstream vgroups("groups.txt");
	vgroups >> gnum;
	for (int i = 0; i < gnum; i++)
	{
		vgroups >> gid >> gname >> pn;//(��Ա����)
		g.push_back(groups(gid, gname));
		int kkk;
		for (int j = 0; j < pn; j++)
		{
			vgroups >> kkk;
			g[i].nums.push_back(kkk);
			v[kkk - 1].groups.push_back(i + 1);
		}
		vgroups >> g[i].master;
		vgroups >> pn;//�������
		int admins;
		for (int j = 0; j < pn; j++)
		{
			vgroups >> admins;
			g[i].adm.push_back(admins);
		}
		g[i].ng = i + 1;
	}
	vgroups.close();
	//***********************
}

void QQ()
{
	char a2 = 'r';
	while(1)
	{
		system("cls");
		cout << "1.ע�����û�\n"
			"2.��½" << endl;
		char p='0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCQQ(); return;
		case '2':
			DLQQ(); return;
		default:
			cout << "������������" << endl;
		}
	cout << "����r������һ���˵������������ַ���������\n" << endl;
	cin >> a2;
	if (a2 == 'r') { return; }
	}

}

void ZCQQ()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "ע��QQ��\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "�������˺ţ�";
		cin >> sid;
		for (; i <(int)v.size(); i++)
		{
			if (v[i].id == sid)
			{
				cout << "�˺��ѱ�ע�ᣡ���������룡";
				j = 1;
			}
			break;
		}
	}while(j);
	cout << "���룺";
		cin >> PAWO;
	cout << "�ǳƣ�";
		cin >> sname;
	cout << "�������ڣ� �꣺";
		cin >> s1;
	cout << "�£�";
		cin >> s2;
	cout << "�գ�";
		cin >> s3;
	cout << "���ڵأ�";
		cin >> slocation;
		v.push_back( user(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "ע��ɹ���\n";
	
	fresh_user();
	fresh_friends();

		cout <<
		"                      ********************************************             \n"
		"                      ע����Ϣ��                                               \n"
		"                      �˺ţ�"; cout << v.back().id << "                            \n"
		"                      �ǳƣ�"; cout << v.back().name << "                          \n"
		"                      ���룺"; cout << v.back().PASSWORD << "                          \n"
		"                      �������ڣ�" << v.back().birthday[0] << "��" << v.back().birthday[1] << "��" << v.back().birthday[2] << "��\n"
		"                      ���ڵأ�" << v.back().location << "                          \n"
		"                      *************�����������QQ�˵�*************             \n";
		system("pause");
		JRQQ((int)v.size() - 1);
}

void DLQQ()
{
	char a1='r';
	while (1)
	{
		system("cls");
		cout << "��ӭʹ��          \n\n"
			"�������û�����" << endl;
		string p;
		cin >> p;
		cout << "���������룺" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				JRQQ(i);
				return;
			}
		}
		i = 0;
		for (; i <= (int)w.size(); i++)
		{
			if (w[i].id == p&&w[i].PASSWORD == q)
			{
				char qqq;
				cout << "����δ��ͨQQ�����Ƿ���Ҫ��ͨ������1ȷ�Ͽ�ͨ" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					v.push_back(user(w[i].PASSWORD, w[i].id, w[i].name, w[i].birthday[0], w[i].birthday[1], w[i].birthday[2], w[i].location));
					JRQQ((int)v.size() - 1);
					return;
				}
			}
		}


		cout << "������������" << endl;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i�ǿ��Ե���0������

void JRQQ(int i)
{
		system("cls");
		cout <<
			"                      ********************************************             \n"
			"                      �ҵ���Ϣ��                                               \n"
			"                      �˺ţ�"; cout << v[i].id << "                            \n"
			"                      �ǳƣ�"; cout << v[i].name << "                          \n"
			"                      �������ڣ�" << v[i].birthday[0] << "��" << v[i].birthday[1] << "��" << v[i].birthday[2] << "��\n"
			"                      ���ڵأ�" << v[i].location << "                          \n"
			"                      *************�����������QQ�˵�*************             \n";
		system("pause");
		
		while (1)
		{

			system("cls");
			cout <<
				"1.�鿴/���� ����\n"
				"2.�鿴/���� Ⱥ��\n"
				"3.�鿴/���� ����\n"
				"4.�˳���¼\n"
				"��ѡ���ܣ�";
			char p;
			cin >> p;
			switch (p)
			{
			case '1':
				CGfriends(i); break;
			case '2':
				CGgroups(i); break;
			case '3':
				CGdatas(i); break;
			case '4':
				return;
			default:
				char a2;
				cout << "����������������r������һ���˵������������ַ���������\n" << endl;
				cin >> a2;
				if (a2 == 'r') { return; }
			}
		}
}

void CGfriends(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"�����б�\n" << endl;
		for (int j = 0; j < (int)v[i].friends.size(); j++)
		{
			cout <<
				"*******************����" << j + 1 << ":*******************\n"
				"�˺�:" << v[v[i].friends[j] - 1].id << "\n"
				"�ǳ�:" << v[v[i].friends[j] - 1].name << "\n"
				"�������ڣ�" << v[v[i].friends[j] - 1].birthday[0] << "��" << v[v[i].friends[j] - 1].birthday[1] << "��" << v[v[i].friends[j] - 1].birthday[2] << "��\n"
				"���ڵأ�" << v[v[i].friends[j] - 1].location << "\n"
				"********************************************\n";
		}
		cout <<
			"1.��Ӻ���\n"
			"2.ɾ������\n"
			"3.�����ϼ��˵�" << endl;
		char a3; cin >> a3;
		switch (a3)
		{
		case '1':
			addfriend(i); break;
		case '2':
			delfriend(i); break;
		case '3':
			return;
		}
	}
}

void addfriend(int i)
{
	while (1)
	{
		cout << "������������ӵĺ����˺ţ�";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)v.size(); y++)
		{
			if (v[y].id == a4)
			{
				v[i].friends.push_back(v[y].n);
				cout << "��ӳɹ���" << endl;
				fresh_friends();
				return;
			}
		}
			cout << "������������" << endl;
		char a2;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delfriend(int i)
{
	char a6='r';
	while(1)
	{
		cout << "����������ɾ���ĺ��ѱ�ţ������б�����ʾ����";
		int a6;
		cin >> a6;
		if (a6 <= (int)v[i].friends.size())
		{
			v[i].friends.erase(v[i].friends.begin() + a6 - 1);
			cout << "ɾ���ɹ���" << endl;
			fresh_friends();
			return;
		}
		else
		{
			cout << "������������";
		}
		
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	} 
}

void CGgroups(int i)
{
	system("cls");
	cout <<
		"Ⱥ�б�\n" << endl;
	for (int j = 0; j < (int)v[i].groups.size(); j++)
	{
		cout <<
			"*******************Ⱥ" << j + 1 << ":*******************\n"
			"�˺�:" << g[v[i].groups[j] - 1].id << "\n"
			"����:" << g[v[i].groups[j] - 1].name << "\n"
			"********************************************\n";
	}
	while (1)
	{
		char a6;
		cout << "1.����Ⱥ\n"
			"2.����Ⱥ\n"
			"3.������Ⱥ����\n";
		cin >> a6;
		switch (a6)
		{
		case '1':
			newgroups(i); return;
		case '2':
			addgroups(i); return;
		case '3':
			entergroups(i); return;
		default:
			char a2;
			cout << "����������������r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void newgroups(int i)
{
	g.push_back(groups(i));
	g[(int)g.size() - 1].ng = (int)g.size();
	g[(int)g.size() - 1].nums.push_back(i + 1);
	v[i].groups.push_back((int)g.size());
	cout << "�����ɹ���" << endl;
	fresh_groups();
}

void addgroups(int i)
{
	string a4;
	cout << "��������Ҫ��ӵ�Ⱥ�˺ţ�";
	cin >> a4;
	for (int a = 0; a < (int)g.size(); a++)
	{
		if (a4 == g[a].id)
		{
			g[a].nums.push_back(i + 1);
			v[i].groups.push_back(g[a].ng);
			cout << "��ӳɹ���" << endl;
			fresh_groups();
			return;
		}
	}
}

void entergroups(int i)
{
	cout << "��ѡ��Ҫ������Ⱥ��ţ�Ⱥ�б�����ʾ����\n";
	int k1;
	cin >> k1;
	system("cls");
	cout <<
		"Ⱥ��Ա�б�\n" << endl;
	for (int j = 0; j < (int)g[v[i].groups[k1 - 1] - 1].nums.size(); j++)
	{
		bool k8 = 0;
		//***
		for (int k2 = 0; k2 < (int)g[v[i].groups[k1 - 1] - 1].adm.size(); k2++)
		{
			if (v[g[v[i].groups[k1 - 1] - 1].nums[j] - 1].n == g[v[i].groups[k1 - 1] - 1].adm[k2])
				k8 = 1;
		}
		//***
		if (k8)
			cout << "****************Ⱥ��Ա" << j + 1 << "(����):****************\n";
		else
			cout << "*******************Ⱥ��Ա" << j + 1 << ":*******************\n";

		cout << "�˺�:" << v[g[v[i].groups[k1 - 1] - 1].nums[j] - 1].id << "\n"
			"�ǳ�:" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].name << "\n"
			"�������ڣ�" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[0] << "��" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[1] << "��" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].birthday[2] << "��\n"
			"���ڵأ�" << v[g[v[i].groups[k1 - 1]-1].nums[j]-1].location << "\n"
			"********************************************\n";
	}
	//��鱾���ǲ��ǹ���
	bool k3 = 0;
	for (int k2 = 0; k2 < (int)g[v[i].groups[k1 - 1]-1].adm.size(); k2++)
	{
		if (g[v[i].groups[k1 - 1]-1].adm[k2] == v[i].n)
			k3 = 1;
	}
	
	char k4;
	if (g[v[i].groups[k1 - 1]-1].master == v[i].n)//Ⱥ�� �˵��� ��� ���� ����Ϊ���� ��ɢ �޸�Ⱥ�ǳ�
	{
		cout <<
			"1.��ɢ��Ⱥ\n"
			"2.���Ⱥ��Ա\n"
			"3.�߳�Ⱥ��Ա\n"
			"4.�޸�Ⱥ����\n"
			"5.��������\n"
			"6.����������\n"
			"7.�����ϼ��˵�\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			delgroups(i, k1 - 1); break;
		case '2':
			addgroupnums(v[i].groups[k1 - 1]-1); break;
		case '3':
			int a5;
			cout << "������Ҫ�߳��ĳ�Ա��ţ�Ⱥ��Ա�б����У���";
			cin >> a5;
			quitgroups(i, g[v[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "ɾ���ɹ���" << endl;
			fresh_groups();
			break;
		case '4':
			changegroupsname(i, k1); break;
		case '5':
			int a8;
			cout << "������Ҫ��������ĳ�Ա��ţ�Ⱥ��Ա�б����У���";
			cin >> a8;
			g[v[i].groups[k1 - 1] - 1].adm.push_back(v[g[v[i].groups[k1 - 1] - 1].nums[a8 - 1] - 1].n);
			fresh_groups(); 
			break;
		case '6':
			CJgroups(i,k1-1);
		case '7':
			return;
		default:
			char a2;
			cout << "����r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
	else if (k3)//Ⱥ����Ĳ˵�   //��� ���� �˳� �޸�Ⱥ�ǳ�
	{
		cout <<
			"1.�˳�Ⱥ\n"
			"2.���Ⱥ��Ա\n"
			"3.�߳�Ⱥ��Ա\n"
			"4.�޸�Ⱥ����\n"
			"5.����������\n"
			"6.�����ϼ��˵�\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitgroups(i, k1 - 1); break;
		case '2':
			addgroupnums(v[i].groups[k1 - 1]-1); break;//Ⱥ�±�
		case '3':
			int a5;
			cout << "������Ҫ�߳��ĳ�Ա��ţ�Ⱥ��Ա�б����У���";
			cin >> a5;
			quitgroups(i,g[v[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "ɾ���ɹ���" << endl;
		case '4':
			changegroupsname(i, k1);
		case '5':
			CJgroups(i, k1 - 1);
		case '6':
			return;
		default:
			char a2;
			cout << "����r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}

	}
	else//��ͨ��Ա�˵���  �˳�  
	{
		cout <<
			"1.�˳�Ⱥ\n"
			"2.����������\n"
			"3.�����ϼ��˵�\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitgroups(i, k1 - 1);
		case '2':
			CJgroups(i, k1 - 1);
		case '3':
			return;
		default:
			char a2;
			cout << "����r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CJgroups(int i, int k1)
{
	string pad;
	int k = v[i].groups[k1] - 1;//k ��Ⱥ���±�
	cout << "��������Ⱥid��";
	cin >> pad;
	int iddd;
	g.push_back(groups(i,pad,g[k].name+"����Ⱥ"));
	v[i].groups.push_back((int)g.size() - 1);
	while (1)
	{
		cout << "��ѡ��Ҫ�����ԭȺ��Ա��ţ�";
		cin >> iddd;
		if (iddd >= 1 && iddd <= (int)g[k].nums.size())
		{
			g[(int)g.size() - 1].nums.push_back(g[k].nums[iddd - 1]);
			v[g[k].nums[iddd - 1] - 1].groups.push_back((int)g.size() - 1);
		}
		else
		{
			cout << "������������rֹͣ��ӣ����������ַ�������ӣ�" << endl;
			char c2;
			cin >> c2;
			if (c2 == 'r')
				return;
		}
	}
	fresh_groups();
}

void changegroupsname(int i, int k1)
{
	string a4;
	cout << "������Ⱥ�����ƣ�";
	cin >> a4;
	g[v[i].groups[k1 - 1] - 1].name = a4;
	fresh_groups();
}

void quitgroups(int i, int i1,int k1)
{
	int k = v[i].groups[k1] - 1;//k ��Ⱥ���±�
	int k2 = 0;
	for (; k2 < (int)v[i1].groups.size(); k2++)
	{
		if (v[i1].groups[k2] == k + 1)
			break;
	}
	v[i1].groups.erase(v[i1].groups.begin() + k2);				//�û��б������Ⱥ
	int a7;
	for (a7 = 0; a7 < (int)g[k].nums.size(); a7++)
	{
		if (g[k].nums[a7] == v[i1].n)
			break;
	}
	g[k].nums.erase(g[k].nums.begin() + a7);//Ⱥ�б�������û�
	fresh_groups();//�����ļ�
}

void quitgroups(int i, int k1)//n=i��user �뿪 ���û��б�groups[k1]    g[v[i].groups[k1]].ng ���Լ��ı��   
{
	int k = v[i].groups[k1] - 1;//k ��Ⱥ���±�
	v[i].groups.erase(v[i].groups.begin() + k1);//�û��б������Ⱥ
	int a7;
	for (a7 = 0; a7 < (int)g[k].nums.size(); a7++)
	{
		if (g[k].nums[a7] == v[i].n)
			break;
	}
	g[k].nums.erase(g[k].nums.begin()+ a7);//Ⱥ�б�������û�
	fresh_groups();//�����ļ�
}

void delgroups(int i,int k1)//ɾ��Ⱥ
{
	int k = v[i].groups[k1] - 1;//k���±�
	for (int k3 = 0; k3 < (int)g[k].nums.size(); k3++)//ͨ��ȺѰ���û�  ���û���ɾ��Ⱥ
	{
		int k4;
		for (k4 = 0; k4 < (int)v[g[k].nums[k3] - 1].groups.size(); k4++)
		{
			if (v[g[k].nums[k3] - 1].groups[k4] == g[k].ng)
				break;
		}
		v[g[k].nums[k3] - 1].groups.erase(v[g[k].nums[k3] - 1].groups.begin() + k4);
	}
	g.erase(g.begin() + g[k].ng - 1);
	/*for (int ax = k; ax < (int)g.size(); ax++)//Ϊÿһ�� ɾ����Ⱥ�� �����ÿ��Ⱥ
	{
		g[ax].ng--;   //��ż�һ
		for (int cx = 0; cx < (int)g[k].nums.size(); cx++)//Ϊ���Ⱥ��ÿһ����Ա
		{
			for (int zx = 0; zx < (int)v[g[k].nums[cx] - 1].groups.size(); zx++)//�ҵ������Ա�����Ⱥ ��ż�һ
			{
				if (v[g[k].nums[cx] - 1].groups[zx] == g[ax].ng + 1)
					v[g[k].nums[cx] - 1].groups[zx]--;
				break;
			}
		}
	}*/
	fresh_groups();
	v.~vector<user>();
	g.~vector<groups>();
	readusers();
	readfriends();
	readgroups();
}

void addgroupnums(int j)
{
	string c9;
	char a2;
	while (1)
	{
		cout << "��������Ҫ��ӵ��û��˺ţ�\n";
		cin >> c9;
		for (int x = 0; x < (int)v.size(); x++)
		{
			if (v[x].id == c9)
			{
				v[x].groups.push_back(g[j].ng);
				g[j].nums.push_back(v[x].n);
				fresh_groups();
				cout << "��ӳɹ���" << endl;
				system("pause");
				return;
			}
		}
			{
				cout << "������������r������һ���˵������������ַ���������\n" << endl;
				cin >> a2;
				if (a2 == 'r') { return; }
			}
	}
}

void CGdatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.�޸�����\n"
			"2.�޸��ǳ�\n"
			"3.�޸ĳ�������\n"
			"4.�޸����ڵ�\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "�����������룺";
			cin >> newx;
			v[i].PASSWORD = newx;
			cout << "�޸ĳɹ���";
			fresh_user();
			return;
		case '2':
			cout << "���������ǳƣ�";
			cin >> newx;
			v[i].name = newx;
			cout << "�޸ĳɹ���";
			fresh_user();
			return;
		case '3':
			cout << "�������³������ڣ�\n";
			int q[3];
			cout << "�������꣺";
			cin >> q[0];
			cout << "�������£�";
			cin >> q[1];
			cout << "�������գ�";
			cin >> q[2];
			v[i].birthday[0] = q[0];
			v[i].birthday[1] = q[1];
			v[i].birthday[2] = q[2];
			cout << "�޸ĳɹ���";
			fresh_user();
			return;
		case '4':
			cout << "���������ڵأ�";
			cin >> newx;
			v[i].location = newx;
			cout << "�޸ĳɹ���";
			fresh_user();
			return;
		default:
			cout << "����������������r������һ�������������ַ�����ѡ��" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}

//*******************************

void fresh_weuser()
{
	fstream sweuser("weuser.txt", ios::out);
	sweuser << (int)w.size() << endl;
	for (int i = 0; i <(int)w.size(); i++)
	{
		sweuser << w[i].id << " " << w[i].name << " " << w[i].PASSWORD << " " << w[i].birthday[0] << " " << w[i].birthday[1] << " " << w[i].birthday[2] << " " << w[i].location<<" "<< w[i].QQn << endl;
	}
	sweuser.close();
}

void fresh_wegroups()
{
	fstream swegroups("wegroups.txt", ios::out);
	swegroups << (int)wg.size() << endl;
	for (int i = 0; i <(int)wg.size(); i++)
	{
		swegroups << wg[i].id << " " << wg[i].name << " " << (int)wg[i].nums.size() << " ";
		for (int j = 0; j < (int)wg[i].nums.size(); j++)
		{
			swegroups << wg[i].nums[j] << " ";
		}
		swegroups << endl;
	}

	swegroups.close();
	/*w.~vector<weuser>();
	g.~vector<wegroups>();
	readweusers();
	readfriends();
	readwegroups();
	*/
}

void fresh_wefriends()
{
	fstream sfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)w.size(); i++)
	{
		sfriends << (int)w[i].friends.size() << " ";
		for (int j = 0; j < (int)w[i].friends.size(); j++)
		{
			sfriends << w[i].friends[j] << " ";
		}
		sfriends << endl;
	}
	sfriends.close();
}

void readweusers()//QQid�ĸ���
{
	//***************
	int num = 0;//��ȡ��һ�����֣���ʾ��ǰ�û�������
	string id; string name; string password; int y; int m; int d; string location; int QQn;
	fstream vweuser("weuser.txt");
	vweuser >> num;
	for (int i = 0; i < num; i++)
	{
		vweuser >> id >> name >> password >> y >> m >> d >> location>>QQn;
		w.push_back(weuser(password, id, name, y, m, d, location, QQn));
	}
	vweuser.close();
	for (int i = 0; i < (int)w.size(); i++)
	{
		w[i].n = i + 1;
	}
}

void readwefriends()
{
	//********************
	fstream wfriends("wefriends.txt");
	//numf���������
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)w.size(); i++)
	{
		wfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			wfriends >> k;
			w[i].friends.push_back(k);
		}
	}
	wfriends.close();
}

void readwegroups()
{
	//************************
	//��ȡwegroups�ļ�
	int gnum = 0;//��ȡ��һ�����֣���ʾ��ǰ�û�������
	string gid; string gname;  int pn;
	fstream vwegroups("wegroups.txt");
	vwegroups >> gnum;
	for (int i = 0; i < gnum; i++)
	{
		vwegroups >> gid >> gname >> pn;//(��Ա����)
		wg.push_back(wegroups(gid, gname));
		int kkk;
		for (int j = 0; j < pn; j++)
		{
			vwegroups >> kkk;
			wg[i].nums.push_back(kkk);
			w[kkk - 1].groups.push_back(i + 1);
		}
		vwegroups >> wg[i].master;
		wg[i].ng = i + 1;
	}
	vwegroups.close();
	//***********************
}

void wechat()
{
	char a2 = 'r';
	while (1)
	{
		system("cls");
		cout << "1.ע�����û�\n"
			"2.��½" << endl;
		char p = '0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCwechat(); return;
		case '2':
			DLwechat(); return;
		default:
			cout << "������������" << endl;
		}
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void ZCwechat()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "ע��wechat��\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "�������˺ţ�";
		cin >> sid;
		for (; i <(int)w.size(); i++)
		{
			if (w[i].id == sid)
			{
				cout << "�˺��ѱ�ע�ᣡ���������룡";
				j = 1;
			}
			break;
		}
	} while (j);
	cout << "���룺";
	cin >> PAWO;
	cout << "�ǳƣ�";
	cin >> sname;
	cout << "�������ڣ� �꣺";
	cin >> s1;
	cout << "�£�";
	cin >> s2;
	cout << "�գ�";
	cin >> s3;
	cout << "���ڵأ�";
	cin >> slocation;
	w.push_back(weuser(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "ע��ɹ���\n";

	fresh_weuser();
	fresh_wefriends();

	cout <<
		"                      ********************************************             \n"
		"                      ע����Ϣ��                                               \n"
		"                      �˺ţ�"; cout << w.back().id << "                            \n"
		"                      �ǳƣ�"; cout << w.back().name << "                          \n"
		"                      ���룺"; cout << w.back().PASSWORD << "                          \n"
		"                      �������ڣ�" << w.back().birthday[0] << "��" << w.back().birthday[1] << "��" << w.back().birthday[2] << "��\n"
		"                      ���ڵأ�" << w.back().location << "                          \n"
		"                      *************�����������wechat�˵�*************             \n";
	system("pause");
	JRwechat((int)w.size() - 1);
}

void DLwechat()
{
	char a1 = 'r';
	while (1)
	{
		system("cls");
		cout << "��ӭʹ��          \n\n"
			"�������û�����" << endl;
		string p;
		cin >> p;
		cout << "���������룺" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)w.size(); i++)
		{
			if (w[i].id == p&&w[i].PASSWORD == q)
			{
				JRwechat(i);
				return;
			}
		}
		i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				char qqq;
				cout << "����δ��ͨwechat�����Ƿ���Ҫ��ͨ������1ȷ�Ͽ�ͨ" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					string wechatid;
					cout << "����������΢�źţ�" << endl;
					cin >> wechatid;
					w.push_back(weuser(v[i].PASSWORD, wechatid, v[i].name, v[i].birthday[0], v[i].birthday[1], v[i].birthday[2], v[i].location, i + 1));
					fresh_weuser();
					JRwechat((int)w.size() - 1);
					return;
				}
			}
		}
		if (i = (int)w.size())
			cout << "������������" << endl;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i�ǿ��Ե���0������

void JRwechat(int i)
{
	system("cls");
	cout <<
		"                      ********************************************             \n"
		"                      �ҵ���Ϣ��                                               \n"
		"                      �˺ţ�"; cout << w[i].id << "                            \n"
		"                      �ǳƣ�"; cout << w[i].name << "                          \n"
		"                      �������ڣ�" << w[i].birthday[0] << "��" << w[i].birthday[1] << "��" << w[i].birthday[2] << "��\n"
		"                      ���ڵأ�" << w[i].location << "                          \n"
		"                      *************�����������wechat�˵�*************             \n";
	system("pause");

	while (1)
	{

		system("cls");
		cout <<
			"1.�鿴/���� ����\n"
			"2.�鿴/���� Ⱥ��\n"
			"3.�鿴/���� ����\n"
			"4.��QQ\n"
			"5.�˳���¼\n"
			"��ѡ���ܣ�";
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			CGwefriends(i); break;
		case '2':
			CGwegroups(i); break;
		case '3':
			CGwedatas(i); break;
		case '4':
			BANGDINGQQ(i); break;
				break;
		case '5':
			return;
		default:
			char a2;
			cout << "����������������r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void BANGDINGQQ(int i)
{

	if (w[i].QQn == -1) 
	{
		string QQQQ; string QQQQpass;
		cout << "����������󶨵�QQ�ţ�";
		cin >> QQQQ;
		cout << "���������룺";
		cin >> QQQQpass;
		for (int cad = 0; cad < (int)v.size(); cad++)
		{
			if (v[cad].id == QQQQ&&v[cad].PASSWORD == QQQQpass)
			{
				w[i].QQn = cad + 1;
				cout << "�󶨳ɹ���";
				fresh_weuser();
				system("pause");
				return;
			}
		}
		cout << "������������" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "����ʧ�ܣ����Ѱ���" << v[w[i].QQn - 1].id << "��" << endl;
		system("pause");
	}

}

void CGwefriends(int i)
{
	system("cls");
	cout <<
		"�����б�\n" << endl;
	for (int j = 0; j <(int)w[i].friends.size(); j++)
	{
		cout <<
			"*******************����" << j + 1 << ":*******************\n"
			"�˺�:" << w[w[i].friends[j] - 1].id << "\n"
			"�ǳ�:" << w[w[i].friends[j] - 1].name << "\n"
			"�������ڣ�" << w[w[i].friends[j] - 1].birthday[0] << "��" << w[w[i].friends[j] - 1].birthday[1] << "��" << w[w[i].friends[j] - 1].birthday[2] << "��\n"
			"���ڵأ�" << w[w[i].friends[j] - 1].location << "\n"
			"********************************************\n";
	}
	cout <<
		"1.��Ӻ���\n"
		"2.ɾ������\n"
		"3.�����ϼ��˵�" << endl;
	char a3; cin >> a3;
	switch (a3)
	{
	case '1':
		addwefriend(i);
	case '2':
		delwefriend(i);
	case '3':
		return;
	}
}

void addwefriend(int i)
{
	while (1)
	{
		bool q=0;
		int t = 0;
		vector<int> tt;
		cout << "�Ƽ����ѣ�\n";//����qq������ ע����΢�Ų�û�г�Ϊ�����ѵ�
		for (int kkkk = 0; kkkk < (int)v[w[i].QQn - 1].friends.size(); kkkk++)//��ÿһ������qq����
		{
			for (int ffff = 0; ffff < (int)w[i].friends.size(); ffff++)	//���Ȳ�������΢�ź���
			{
				if (w[w[i].friends[ffff] - 1].QQn != v[w[i].QQn - 1].friends[kkkk])
					q = 1;
			}
			if (q)
			{
				for (int wwww = 0; wwww < (int)w.size(); wwww++)//��ÿһ��΢���û�
					if (w[wwww].QQn == v[w[i].QQn - 1].friends[kkkk])
					{
						t++;
						tt.push_back(wwww);//wwww��΢�š����½Ǳ�
					}
				cout << t << ":" << "����QQ���ѣ�" << v[v[w[i].QQn - 1].friends[kkkk] - 1].name << endl;
			
			}
		}




		cout << "�����Ӧ�����Ӻ��ѣ��������������ֶ���������˺�\n";
		int o;
		cin >> o;
		if (1 <= o&&o <= t)
		{
			w[i].friends.push_back(w[tt[o - 1]].n);
			cout << "��ӳɹ���" << endl;
			fresh_wefriends();
		}

		cout << "������������ӵĺ����˺ţ�";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)w.size(); y++)
		{
			if (w[y].id == a4)
			{
				w[i].friends.push_back(w[y].n);
				cout << "��ӳɹ���" << endl;
				fresh_wefriends();
				return;
			}
		}
		cout << "������������" << endl;
		char a2;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delwefriend(int i)
{
	char a6 = 'r';
	while (1)
	{
		cout << "����������ɾ���ĺ��ѱ�ţ������б�����ʾ����";
		int a6;
		cin >> a6;
		if (a6 <= (int)w[i].friends.size())
		{
			w[i].friends.erase(w[i].friends.begin() + a6 - 1);
			cout << "ɾ���ɹ���" << endl;
			fresh_wefriends();
			return;
		}
		else
		{
			cout << "������������";
		}

		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	}
}

void CGwegroups(int i)
{
	system("cls");
	cout <<
		"Ⱥ�б�\n" << endl;
	for (int j = 0; j < (int)w[i].groups.size(); j++)
	{
		cout <<
			"*******************Ⱥ" << j + 1 << ":*******************\n"
			"�˺�:" << wg[w[i].groups[j] - 1].id << "\n"
			"����:" << wg[w[i].groups[j] - 1].name << "\n"
			"********************************************\n";
	}
	while (1)
	{
		char a6;
		cout << "1.����Ⱥ\n"
			"2.������Ⱥ����\n";
		cin >> a6;
		switch (a6)
		{
		case '1':
			newwegroups(i); return;
		case '2':
			enterwegroups(i); return;
		default:
			char a2;
			cout << "����������������r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void newwegroups(int i)
{
	wg.push_back(wegroups(i));
	wg[(int)wg.size() - 1].ng = (int)wg.size();
	wg[(int)wg.size() - 1].nums.push_back(i + 1);
	w[i].groups.push_back((int)wg.size());
	cout << "�����ɹ���" << endl;
	fresh_wegroups();
}

void enterwegroups(int i)
{
	cout << "��ѡ��Ҫ������Ⱥ��ţ�Ⱥ�б�����ʾ����\n";
	int k1;
	cin >> k1;
	system("cls");
	cout <<
		"Ⱥ��Ա�б�\n" << endl;
	for (int j = 0; j < (int)wg[w[i].groups[k1 - 1] - 1].nums.size(); j++)
	{

	
			cout << "*******************Ⱥ��Ա" << j + 1 << ":*******************\n";

		cout << "�˺�:" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].id << "\n"
			"�ǳ�:" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].name << "\n"
			"�������ڣ�" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[0] << "��" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[1] << "��" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].birthday[2] << "��\n"
			"���ڵأ�" << w[wg[w[i].groups[k1 - 1] - 1].nums[j] - 1].location << "\n"
			"********************************************\n";
	}
	//��鱾���ǲ��ǹ���
	char k4;
	if (wg[w[i].groups[k1 - 1] - 1].master == w[i].n)//Ⱥ�� �˵��� ��� ���� ����Ϊ���� ��ɢ �޸�Ⱥ�ǳ�
	{
		cout <<
			"1.��ɢ��Ⱥ\n"
			"2.���Ⱥ��Ա\n"
			"3.�߳�Ⱥ��Ա\n"
			"4.�޸�Ⱥ����\n"
			"5.�����ϼ��˵�\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			delwegroups(i, k1 - 1); break;
		case '2':
			addwegroupnums(w[i].groups[k1 - 1] - 1); break;
		case '3':
			int a5;
			cout << "������Ҫ�߳��ĳ�Ա��ţ�Ⱥ��Ա�б����У���";
			cin >> a5;
			quitwegroups(i, wg[w[i].groups[k1 - 1] - 1].nums[a5 - 1] - 1, k1 - 1);
			cout << "ɾ���ɹ���" << endl;
			fresh_wegroups();
			break;
		case '4':
			changewegroupsname(i, k1); break;
		case '5':
			return;
		default:
			char a2;
			cout << "����r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
	
	else//��ͨ��Ա�˵���  �˳�  
	{
		cout <<
			"1.�˳�Ⱥ\n"
			"2.�����ϼ��˵�\n";
		cin >> k4;
		switch (k4)
		{
		case '1':
			quitwegroups(i, k1 - 1);
		case '2':
			return;
		default:
			char a2;
			cout << "����r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void changewegroupsname(int i, int k1)
{
	string a4;
	cout << "������Ⱥ�����ƣ�";
	cin >> a4;
	wg[w[i].groups[k1 - 1] - 1].name = a4;
	fresh_wegroups();
}

void quitwegroups(int i, int i1, int k1)
{
	int k = w[i].groups[k1] - 1;//k ��Ⱥ���±�
	int k2 = 0;
	for (; k2 < (int)w[i1].groups.size(); k2++)
	{
		if (w[i1].groups[k2] == k + 1)
			break;
	}
	w[i1].groups.erase(w[i1].groups.begin() + k2);				//�û��б������Ⱥ
	int a7;
	for (a7 = 0; a7 < (int)wg[k].nums.size(); a7++)
	{
		if (wg[k].nums[a7] == w[i1].n)
			break;
	}
	wg[k].nums.erase(wg[k].nums.begin() + a7);//Ⱥ�б�������û�
	fresh_wegroups();//�����ļ�
}

void quitwegroups(int i, int k1)//n=i��weuser �뿪 ���û��б�wegroups[k1]    wg[w[i].groups[k1]].nwg ���Լ��ı��   
{
	int k = w[i].groups[k1] - 1;//k ��Ⱥ���±�
	w[i].groups.erase(w[i].groups.begin() + k1);//�û��б������Ⱥ
	int a7;
	for (a7 = 0; a7 < (int)wg[k].nums.size(); a7++)
	{
		if (wg[k].nums[a7] == w[i].n)
			break;
	}
	wg[k].nums.erase(wg[k].nums.begin() + a7);//Ⱥ�б�������û�
	fresh_wegroups();//�����ļ�
}

void delwegroups(int i, int k1)//ɾ��Ⱥ
{
	int k = w[i].groups[k1] - 1;//k���±�
	for (int k3 = 0; k3 < (int)wg[k].nums.size(); k3++)//ͨ��ȺѰ���û�  ���û���ɾ��Ⱥ
	{
		int k4;
		for (k4 = 0; k4 < (int)w[wg[k].nums[k3] - 1].groups.size(); k4++)
		{
			if (w[wg[k].nums[k3] - 1].groups[k4] == wg[k].ng)
				break;
		}
		w[wg[k].nums[k3] - 1].groups.erase(w[wg[k].nums[k3] - 1].groups.begin() + k4);
	}
	wg.erase(wg.begin() + wg[k].ng - 1);
	/*for (int ax = k; ax < (int)wg.size(); ax++)//Ϊÿһ�� ɾ����Ⱥ�� �����ÿ��Ⱥ
	{
	wg[ax].nwg--;   //��ż�һ
	for (int cx = 0; cx < (int)wg[k].nums.size(); cx++)//Ϊ���Ⱥ��ÿһ����Ա
	{
	for (int zx = 0; zx < (int)w[wg[k].nums[cx] - 1].groups.size(); zx++)//�ҵ������Ա�����Ⱥ ��ż�һ
	{
	if (w[wg[k].nums[cx] - 1].groups[zx] == wg[ax].nwg + 1)
	w[wg[k].nums[cx] - 1].groups[zx]--;
	break;
	}
	}
	}*/
	fresh_wegroups();
	w.~vector<weuser>();
	wg.~vector<wegroups>();
	readweusers();
	readwefriends();
	readwegroups();
}

void addwegroupnums(int j)
{
	string c9;
	char a2;
	while (1)
	{
		cout << "��������Ҫ��ӵ��û��˺ţ�\n";
		cin >> c9;
		for (int x = 0; x < (int)w.size(); x++)
		{
			if (w[x].id == c9)
			{
				w[x].groups.push_back(wg[j].ng);
				wg[j].nums.push_back(w[x].n);
				fresh_wegroups();
				cout << "��ӳɹ���" << endl;
				system("pause");
				return;
			}
		}
		{
			cout << "������������r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CGwedatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.�޸�����\n"
			"2.�޸��ǳ�\n"
			"3.�޸ĳ�������\n"
			"4.�޸����ڵ�\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "�����������룺";
			cin >> newx;
			w[i].PASSWORD = newx;
			cout << "�޸ĳɹ���";
			fresh_weuser();
			return;
		case '2':
			cout << "���������ǳƣ�";
			cin >> newx;
			w[i].name = newx;
			cout << "�޸ĳɹ���";
			fresh_weuser();
			return;
		case '3':
			cout << "�������³������ڣ�\n";
			int q[3];
			cout << "�������꣺";
			cin >> q[0];
			cout << "�������£�";
			cin >> q[1];
			cout << "�������գ�";
			cin >> q[2];
			w[i].birthday[0] = q[0];
			w[i].birthday[1] = q[1];
			w[i].birthday[2] = q[2];
			cout << "�޸ĳɹ���";
			fresh_weuser();
			return;
		case '4':
			cout << "���������ڵأ�";
			cin >> newx;
			w[i].location = newx;
			cout << "�޸ĳɹ���";
			fresh_weuser();
			return;
		default:
			cout << "����������������r������һ�������������ַ�����ѡ��" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}




vector <user> wb;

void fresh_WBuser()
{
	fstream swbuser("wbuser.txt", ios::out);
	swbuser << (int)wb.size() << endl;
	for (int i = 0; i <(int)wb.size(); i++)
	{
		swbuser << wb[i].id << " " << wb[i].name << " " << wb[i].PASSWORD << " " << wb[i].birthday[0] << " " << wb[i].birthday[1] << " " << wb[i].birthday[2] << " " << wb[i].location << endl;
	}
	swbuser.close();
}

void fresh_WBfriends()
{
	fstream swbfriends("friends.txt", ios::out);
	for (int i = 0; i < (int)wb.size(); i++)
	{
		swbfriends << (int)wb[i].friends.size() << " ";
		for (int j = 0; j < (int)wb[i].friends.size(); j++)
		{
			swbfriends << wb[i].friends[j] << " ";
		}
		swbfriends << endl;
	}
	swbfriends.close();
}

void readWBusers()
{
	//***************
	int num = 0;//��ȡ��һ�����֣���ʾ��ǰ�û�������
	string id; string name; string password; int y; int m; int d; string location;
	fstream vwbuser("wbuser.txt");
	vwbuser >> num;
	for (int i = 0; i < num; i++)
	{
		vwbuser >> id >> name >> password >> y >> m >> d >> location;
		wb.push_back(user(password, id, name, y, m, d, location));
	}
	vwbuser.close();
	for (int i = 0; i < (int)wb.size(); i++)
	{
		wb[i].n = i + 1;
	}
}

void readWBfriends()
{
	//********************
	fstream vwbfriends("friends.txt");
	//numf���������
	int  numf = 0;
	int k = 0;
	for (int i = 0; i < (int)wb.size(); i++)
	{
		vwbfriends >> numf;
		for (int j = 0; j < numf; j++)
		{
			vwbfriends >> k;
			wb[i].friends.push_back(k);
		}
	}
	vwbfriends.close();
}

void WEIBO()
{
	char a2 = 'r';
	while (1)
	{
		system("cls");
		cout << "1.ע�����û�\n"
			"2.��½" << endl;
		char p = '0';
		cin >> p;
		switch (p)
		{
		case '1':
			ZCWB(); return;
		case '2':
			DLWB(); return;
		default:
			cout << "������������" << endl;
		}
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}

}

void ZCWB()
{
	system("cls");
	string PAWO; string sid; string sname; int s1, s2, s3; string slocation;
	cout << "ע��QQ��\n";
	int i = 0; int j = 0;
	do {
		j = 0;
		cout << "�������˺ţ�";
		cin >> sid;
		for (; i <(int)wb.size(); i++)
		{
			if (wb[i].id == sid)
			{
				cout << "�˺��ѱ�ע�ᣡ���������룡";
				j = 1;
			}
			break;
		}
	} while (j);
	cout << "���룺";
	cin >> PAWO;
	cout << "�ǳƣ�";
	cin >> sname;
	cout << "�������ڣ� �꣺";
	cin >> s1;
	cout << "�£�";
	cin >> s2;
	cout << "�գ�";
	cin >> s3;
	cout << "���ڵأ�";
	cin >> slocation;
	wb.push_back(user(PAWO, sid, sname, s1, s2, s3, slocation));
	cout << "ע��ɹ���\n";

	fresh_WBuser();
	fresh_WBfriends();

	cout <<
		"                      ********************************************             \n"
		"                      ע����Ϣ��                                               \n"
		"                      �˺ţ�"; cout << wb.back().id << "                            \n"
		"                      �ǳƣ�"; cout << wb.back().name << "                          \n"
		"                      ���룺"; cout << wb.back().PASSWORD << "                          \n"
		"                      �������ڣ�" << wb.back().birthday[0] << "��" << wb.back().birthday[1] << "��" << wb.back().birthday[2] << "��\n"
		"                      ���ڵأ�" << wb.back().location << "                          \n"
		"                      *************�����������QQ�˵�*************             \n";
	system("pause");
	JRWB((int)wb.size() - 1);
}

void DLWB()
{
	char a1 = 'r';
	while (1)
	{
		system("cls");
		cout << "��ӭʹ��          \n\n"
			"�������û�����" << endl;
		string p;
		cin >> p;
		cout << "���������룺" << endl;
		string q;
		cin >> q;
		int i = 0;
		for (; i < (int)wb.size(); i++)
		{
			if (wb[i].id == p&&wb[i].PASSWORD == q)
			{
				JRWB(i);
				return;
			}
		}
		i = 0;
		for (; i < (int)v.size(); i++)
		{
			if (v[i].id == p&&v[i].PASSWORD == q)
			{
				char qqq;
				cout << "����δ��ͨ΢�������Ƿ���Ҫ��ͨ������1ȷ�Ͽ�ͨ" << endl;
				cin >> qqq;
				if (qqq = '1')
				{
					wb.push_back(user(v[i].PASSWORD, v[i].id, v[i].name, v[i].birthday[0], v[i].birthday[1], v[i].birthday[2], v[i].location));
					JRWB((int)wb.size() - 1);
					return;
				}
			}
		}
		cout << "������������" << endl;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		char a2;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

//i�ǿ��Ե���0������

void JRWB(int i)
{
	system("cls");
	cout <<
		"                      ********************************************             \n"
		"                      �ҵ���Ϣ��                                               \n"
		"                      �˺ţ�"; cout << wb[i].id << "                            \n"
		"                      �ǳƣ�"; cout << wb[i].name << "                          \n"
		"                      �������ڣ�" << wb[i].birthday[0] << "��" << wb[i].birthday[1] << "��" << wb[i].birthday[2] << "��\n"
		"                      ���ڵأ�" << wb[i].location << "                          \n"
		"                      *************�����������QQ�˵�*************             \n";
	system("pause");

	while (1)
	{

		system("cls");
		cout <<
			"1.�鿴/���� ����\n"
			"2.�鿴/���� Ⱥ��\n"
			"3.�鿴/���� ����\n"
			"4.�˳���¼\n"
			"��ѡ���ܣ�";
		char p;
		cin >> p;
		switch (p)
		{
		case '1':
			CGWBfriends(i); break;
		case '2':
			CGgroups(i); break;
		case '3':
			CGWBdatas(i); break;
		case '4':
			return;
		default:
			char a2;
			cout << "����������������r������һ���˵������������ַ���������\n" << endl;
			cin >> a2;
			if (a2 == 'r') { return; }
		}
	}
}

void CGWBfriends(int i)
{
	system("cls");
	cout <<
		"�����б�\n" << endl;
	for (int j = 0; j <(int)wb[i].friends.size(); j++)
	{
		cout <<
			"*******************����" << j + 1 << ":*******************\n"
			"�˺�:" << wb[wb[i].friends[j] - 1].id << "\n"
			"�ǳ�:" << wb[wb[i].friends[j] - 1].name << "\n"
			"�������ڣ�" << wb[wb[i].friends[j] - 1].birthday[0] << "��" << wb[wb[i].friends[j] - 1].birthday[1] << "��" << wb[wb[i].friends[j] - 1].birthday[2] << "��\n"
			"���ڵأ�" << wb[wb[i].friends[j] - 1].location << "\n"
			"********************************************\n";
	}
	cout <<
		"1.��Ӻ���\n"
		"2.ɾ������\n"
		"3.�����ϼ��˵�" << endl;
	char a3; cin >> a3;
	switch (a3)
	{
	case '1':
		addWBfriend(i);
	case '2':
		delWBfriend(i);
	case '3':
		return;
	}
}

void addWBfriend(int i)
{
	while (1)
	{
		cout << "������������ӵĺ����˺ţ�";
		string a4;
		cin >> a4;
		int y = 0;
		for (; y < (int)wb.size(); y++)
		{
			if (wb[y].id == a4)
			{
				wb[i].friends.push_back(wb[y].n);
				cout << "��ӳɹ���" << endl;
				fresh_WBfriends();
				return;
			}
		}
		cout << "������������" << endl;
		char a2;
		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a2;
		if (a2 == 'r') { return; }
	}
}

void delWBfriend(int i)
{
	char a6 = 'r';
	while (1)
	{
		cout << "����������ɾ���ĺ��ѱ�ţ������б�����ʾ����";
		int a6;
		cin >> a6;
		if (a6 <= (int)wb[i].friends.size())
		{
			wb[i].friends.erase(wb[i].friends.begin() + a6 - 1);
			cout << "ɾ���ɹ���" << endl;
			fresh_WBfriends();
			return;
		}
		else
		{
			cout << "������������";
		}

		cout << "����r������һ���˵������������ַ���������\n" << endl;
		cin >> a6;
		if (a6 == 'r') { return; }
	}
}

void CGWBdatas(int i)
{
	while (1)
	{
		system("cls");
		cout <<
			"1.�޸�����\n"
			"2.�޸��ǳ�\n"
			"3.�޸ĳ�������\n"
			"4.�޸����ڵ�\n";
		char a;
		cin >> a;
		string newx;
		switch (a)
		{
		case '1':
			cout << "�����������룺";
			cin >> newx;
			wb[i].PASSWORD = newx;
			cout << "�޸ĳɹ���";
			fresh_WBuser();
			return;
		case '2':
			cout << "���������ǳƣ�";
			cin >> newx;
			wb[i].name = newx;
			cout << "�޸ĳɹ���";
			fresh_WBuser();
			return;
		case '3':
			cout << "�������³������ڣ�\n";
			int q[3];
			cout << "�������꣺";
			cin >> q[0];
			cout << "�������£�";
			cin >> q[1];
			cout << "�������գ�";
			cin >> q[2];
			wb[i].birthday[0] = q[0];
			wb[i].birthday[1] = q[1];
			wb[i].birthday[2] = q[2];
			cout << "�޸ĳɹ���";
			fresh_WBuser();
			return;
		case '4':
			cout << "���������ڵأ�";
			cin >> newx;
			wb[i].location = newx;
			cout << "�޸ĳɹ���";
			fresh_WBuser();
			return;
		default:
			cout << "����������������r������һ�������������ַ�����ѡ��" << endl;
			char c;
			cin >> c;
			if (c == 'r') { return; }
		}
	}
}
