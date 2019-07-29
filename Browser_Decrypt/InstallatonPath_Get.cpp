#include"Firefox_decrypt.h"
#define MY_BUFSIZE 128 // Arbitrary initial value.
// Dynamic allocation will be used.
constexpr auto Get_failed = "get_InstallationPath Failed";
// 通过注册表获取软件的安装路径
string getInstallationPath() {
	HKEY hKey;
	TCHAR szProductType[MY_BUFSIZE];
	DWORD dwBufLen = MY_BUFSIZE;
	DWORD dwBufLen2 = MY_BUFSIZE;
	LONG lRet;
	// 下面是打开注册表, 只有打开后才能做其他操作
	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, // 要打开的根键
		TEXT("SOFTWARE\\Mozilla\\Mozilla Firefox"), // 要打开的子子键（火狐目录）
		0, // 这个一定要为0
		KEY_QUERY_VALUE,	// 指定打开方式,此为读
		//KEY_QUERY_VALUE|KEY_WOW64_64KEY, // 32位程序非要获取64位的注册表需要在打开键时，添加参数KEY_WOW64_64KEY
		&hKey); // 用来返回句柄

	if (lRet == ERROR_SUCCESS) // 判断是否打开成功
	{
		// 打开注册表成功
		// 开始查询火狐版本
		lRet = RegQueryValueEx(hKey, // 打开注册表时返回的句柄
			TEXT("CurrentVersion"), //要查询的名称,火狐版本记录在这里
			NULL, // 一定为NULL或者0
			NULL,
			(LPBYTE)szProductType, // 我们要的东西放在这里
			&dwBufLen);

		if (lRet == ERROR_SUCCESS) // 判断是否查询成功
		{
			string versionPath = szProductType;
			versionPath += "\\Main";
			lRet = RegOpenKeyEx(hKey, // 要打开的根键
				TEXT(versionPath.c_str()), // 要打开的子子键（火狐版本）
				0, // 这个一定要为0
				KEY_QUERY_VALUE,	// 指定打开方式,此为读
				//KEY_QUERY_VALUE|KEY_WOW64_64KEY, // 32位程序非要获取64位的注册表需要在打开键时，添加参数KEY_WOW64_64KEY
				&hKey); // 用来返回句柄

			if (lRet == ERROR_SUCCESS) // 判断是否打开成功
			{
				// 打开成功
				// 开始查询

				lRet = RegQueryValueEx(hKey, // 打开注册表火狐版本目录时返回的句柄
					TEXT("Install Directory"), //要查询的名称,火狐安装目录记录在这里
					NULL, // 一定为NULL或者0
					NULL,
					(LPBYTE)szProductType, // 我们要的东西放在这里
					&dwBufLen2);
				if (lRet == ERROR_SUCCESS) // 判断是否查询成功
				{
					RegCloseKey(hKey);
					return (char*)szProductType;
				}
				else
				{
					printf("获得安装目录失败\n");
					return Get_failed;
				}
			}
			else {
				printf("打开安装目录失败\n");
				return Get_failed;
			}
		}
		else {
			printf("打开火狐版本目录失败\n");
			return Get_failed;
		}
	}
	else {
		printf("打开注册表失败\n");
		return Get_failed;
	}
}