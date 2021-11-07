#include "Windows.h"
using namespace std;
typedef long long ll;
void Btn01_cb(Fl_Widget* w, void* data) {
	((Fl_Button*)w)->label((char*)data);
	yeildPrime(p, q);//生成2个素数p和q
	sprintf_s(numBuf,"%lld",p);//数字转字符串
	showP->value(numBuf);
	sprintf_s(numBuf, "%lld", q);
	showQ->value(numBuf);
	sprintf_s(numBuf, "%lld", p*q);
	showN->value(numBuf);
	sprintf_s(numBuf, "%lld", (p-1) * (q-1));
	showFn->value(numBuf);
}
void Btn02_cb(Fl_Widget* w, void* data) {
	((Fl_Button*)w)->label((char*)data);
	e = yeildE((p - 1) * (q - 1));
	sprintf_s(numBuf, "%lld", e);
	showE->value(numBuf);
	d = getD(e, (p - 1) * (q - 1));
	sprintf_s(numBuf, "%lld", d);
	showD->value(numBuf);
}
void Btn03_cb(Fl_Widget* w, void* data) {//加密
	((Fl_Button*)w)->label((char*)data);
	plainText = atoll(plainText_IN->value());
	plainText = enCode(plainText, e, p * q);//加密后
	sprintf_s(numBuf, "%lld", plainText);
	showEnCodeText->value(numBuf);
}
void Btn04_cb(Fl_Widget* w, void* data) {//解密
	((Fl_Button*)w)->label((char*)data);
	cipherText = atoll(cipherText_IN->value());
	cipherText = deCode(cipherText, d, p * q);//加密后
	sprintf_s(numBuf, "%lld", cipherText);
	showDeCodeText->value(numBuf);
}
void setWindow() {
	Fl_Window* windows = new Fl_Window(300, 455);
	//生成素数按钮
	char buff1[] = "&生成成功";
	Fl_Button* Btn01 = new Fl_Button(15, 50, 65, 25, "&生成素数");
	//生成公钥按钮
	char buff2[] = "&生成成功";
	Fl_Button* Btn02 = new Fl_Button(15, 130, 65, 25, "&生成e和d");
	//加密解密按钮：
	char buff3[] = "&成功";
	Fl_Button* Btn03 = new Fl_Button(15, 230, 35, 25, "&加密");
	char buff4[] = "&成功";
	Fl_Button* Btn04 = new Fl_Button(15, 330, 35, 25, "&解密");
	
	//数字的文本框
	showP = new Fl_Output(95, 50, 65, 25,"p");
	showQ = new Fl_Output(185, 50, 65, 25,"q");
	showN = new Fl_Output(35, 80, 65, 25, "n");
	showFn = new Fl_Output(185, 80, 65, 25, "Euler n");
	showE = new Fl_Output(95, 130, 65, 25, "e");
	showD = new Fl_Output(185, 130, 65, 25, "d");
	
	//输入加密或解密信息
	plainText_IN = new Fl_Input(115, 180, 135, 25, "输入加密信息:");
	showEnCodeText = new Fl_Output(115, 230, 135, 25, "加密结果:");
	cipherText_IN = new Fl_Input(115, 280, 135, 25, "输入解密信息:");
	showDeCodeText = new Fl_Output(115, 330, 135, 25, "解密结果:");

	//启动按钮和窗口
	Btn01->callback((Fl_Callback*)Btn01_cb, buff1);
	Btn02->callback((Fl_Callback*)Btn02_cb, buff2);
	Btn03->callback((Fl_Callback*)Btn03_cb, buff3);
	Btn04->callback((Fl_Callback*)Btn04_cb, buff4);
	windows->end(); windows->show();
	Fl::run();
	printf("%lld*%lld,%lld\n", e, d, e * d % ((p - 1) * (q - 1)));
}