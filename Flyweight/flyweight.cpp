#include "flyweight.h"
int main()
{
	WebSiteFactory * f = new WebSiteFactory();
	WebSite * fx = f->GetWebSiteCategory("��Ʒչʾ");
	fx->Use(new User("С��"));

	WebSite * fy = f->GetWebSiteCategory("��Ʒչʾ");
	fy->Use(new User("����"));

	WebSite * f1 = f->GetWebSiteCategory("����");
	f1->Use(new User("����"));

	WebSite * f2 = f->GetWebSiteCategory("����");
	f2->Use(new User("����ͯ"));

	WebSite * fa = f->GetWebSiteCategory("����");
	fa->Use(new User("�ҹ�����"));

	cout << "��վ��������Ϊ" << f->GetWebSiteCount() << endl;
}