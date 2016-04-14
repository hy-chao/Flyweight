#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;
//�û�
class User
{
private:
	string name;
public:
	User(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return name;
	}
};
//��վ������
class WebSite
{
public:
	virtual void Use(User * user) = 0;
};
//������վ��
class ConcreteWebSite : public WebSite
{
private:
	string name = "";
public:
	ConcreteWebSite(string name)
	{
		this->name = name;
	}
	void Use(User * user)
	{
		cout << "��վ����:" << name << "\t�û�:" << user->GetName() << endl;
	}
};
//��վ������
class WebSiteFactory
{
private:
	std::map<string, ConcreteWebSite*> flyweight;
public:
	WebSite * GetWebSiteCategory(string key)
	{
		//�ж϶����Ƿ���ڣ��������ֱ�ӷ��أ�����ʵ�������ٷ���
		map<string, ConcreteWebSite*>::iterator it = flyweight.find(key);
		if (it != flyweight.end())
		{
			return ((ConcreteWebSite*)flyweight[key]);
		}
		flyweight.insert(map<string, ConcreteWebSite*>::value_type(key, new ConcreteWebSite(key)));
		return ((ConcreteWebSite*)flyweight[key]);
	}
	//�����վ��������
	int GetWebSiteCount()
	{
		map<string, ConcreteWebSite*>::iterator it;
		int n = 0;
		for (it = flyweight.begin(); it != flyweight.end(); ++it)
		{
			n++;
		}
		return n;
	}
};