#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;
//用户
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
//网站抽象类
class WebSite
{
public:
	virtual void Use(User * user) = 0;
};
//具体网站类
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
		cout << "网站分类:" << name << "\t用户:" << user->GetName() << endl;
	}
};
//网站工厂类
class WebSiteFactory
{
private:
	std::map<string, ConcreteWebSite*> flyweight;
public:
	WebSite * GetWebSiteCategory(string key)
	{
		//判断对象是否存在，如果存在直接返回，否则，实例化它再返回
		map<string, ConcreteWebSite*>::iterator it = flyweight.find(key);
		if (it != flyweight.end())
		{
			return ((ConcreteWebSite*)flyweight[key]);
		}
		flyweight.insert(map<string, ConcreteWebSite*>::value_type(key, new ConcreteWebSite(key)));
		return ((ConcreteWebSite*)flyweight[key]);
	}
	//获得网站分类总数
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