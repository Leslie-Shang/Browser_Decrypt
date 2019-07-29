#include "Chrome(Opera)_Decrypt.h"
#include <ShlObj_core.h>
constexpr auto Get_failed = "get_ProfilePath Failed";
string getChromeProfilePath() {
	char* appDataPath = (char*)malloc(sizeof(char) * MAX_PATH);
	if (appDataPath != NULL) {
		//获取Chrome 保存登录信息文件Login Data的路径
		SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, appDataPath);	// 获取当前用户的文件系统目录C:\Users\username\AppData\Local
		string profilePath = appDataPath;
		//printf("%s\n", appDataPath);
		profilePath = profilePath + "\\Google\\Chrome\\User Data\\Default\\";

		/*
		//获取Opera 保存登录信息文件Login Data的路径
		SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, appDataPath);	// 获取当前用户的文件系统目录C:\Users\username\AppData\Roaming（CSIDL_APPDATA默认为AppData下的Roaming）
		string profilePath = appDataPath;
		profilePath = profilePath + "\\Opera Software\\Opera Stable\\";	// Opera的Login Data所在路径
		*/

		return profilePath;
	}
	else
		return Get_failed;
}
string getOperaProfilePath() {
	char* appDataPath = (char*)malloc(sizeof(char) * MAX_PATH);
	if (appDataPath != NULL) {
		//获取Opera 保存登录信息文件Login Data的路径
		SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, appDataPath);	// 获取当前用户的文件系统目录C:\Users\username\AppData\Roaming（CSIDL_APPDATA默认为AppData下的Roaming）
		string profilePath = appDataPath;
		profilePath = profilePath + "\\Opera Software\\Opera Stable\\";	// Opera的Login Data所在路径

		return profilePath;
	}
	else
		return Get_failed;
}
