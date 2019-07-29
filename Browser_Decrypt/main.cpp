#include"Chrome(Opera)_Decrypt.h"
#include"Firefox_decrypt.h"
int main() {
	while (1) {
		cout << "\n****************************************" << endl
			 << "*  浏览器用户信息提取及密码解密程序    *" << endl
			 << "*  选择Chrome请输入：	1              *" << endl
			 << "*  选择Firefox请输入：	2              *" << endl
			 << "*  选择Opera请输入：	3              *" << endl
			 << "*  退出程序请输入：	0              *" << endl
			 << "****************************************\n" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "\nChrome用户信息提取及解密" << endl
				 << "------------------------" << endl;
			ChromeRun();
			break;
		case 2:
			cout << "\nFirefox用户信息提取及解密" << endl
				 << "-------------------------" << endl;
			FirefoxRun();
			break;
		case 3:
			cout << "\nOpera用户信息提取及解密" << endl
				 << "-----------------------" << endl;
			OperaRun();
			break;
		case 0:
			cout << "\n退出程序……" << endl
				 << "------------------------" << endl;
			return 0;
		default:
			cout << "\n输入有误，请重新输入……" << endl
				 << "------------------------" << endl;
			break;
		}
	}
}