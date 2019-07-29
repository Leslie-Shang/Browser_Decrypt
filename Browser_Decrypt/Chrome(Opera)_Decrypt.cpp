#include"Chrome(Opera)_Decrypt.h"
constexpr auto Decryption_error = "Decryption error!";
string Decrypt(const unsigned char* password, int len) {
	DATA_BLOB DataOut;
	DATA_BLOB Dataput;
	LPWSTR pbtest = NULL;
	//初始化加密结构DataOut
	BYTE* pbDataInput = (BYTE*)password;
	DWORD cbDataInput = len;
	DataOut.pbData = pbDataInput;
	DataOut.cbData = cbDataInput;

	if (CryptUnprotectData(&DataOut, &pbtest, NULL, NULL, NULL, 0, &Dataput))
	{
		string s = Password_Handle((char*)Dataput.pbData);//解密后的密码处理
		return s;
	}
	else
	{
		printf("Decryption error!\n");
		return Decryption_error;
	}
}