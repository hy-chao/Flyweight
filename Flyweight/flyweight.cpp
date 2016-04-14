#include "flyweight.h"
int main()
{
	WebSiteFactory * f = new WebSiteFactory();
	WebSite * fx = f->GetWebSiteCategory("产品展示");
	fx->Use(new User("小菜"));

	WebSite * fy = f->GetWebSiteCategory("产品展示");
	fy->Use(new User("大鸟"));

	WebSite * f1 = f->GetWebSiteCategory("博客");
	f1->Use(new User("娇娇"));

	WebSite * f2 = f->GetWebSiteCategory("博客");
	f2->Use(new User("老顽童"));

	WebSite * fa = f->GetWebSiteCategory("邮箱");
	fa->Use(new User("桃谷六仙"));

	cout << "网站分类总数为" << f->GetWebSiteCount() << endl;
}