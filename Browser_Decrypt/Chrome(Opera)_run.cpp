#include "Chrome(Opera)_Decrypt.h"
#include <Wincrypt.h>
#include "sqlite3.h"
#pragma comment(lib,"crypt32.lib")
#pragma warning(disable:4996)

void ChromeRun()
{
	sqlite3* DB = NULL; // 一个打开的数据库实例
	sqlite3_stmt* stmt = NULL;// sqlite3_stmt 预编译语句对象. 由sqlite3_prepare()创建，由sqlite3_finalize()销毁
	string LoginDataPath = getChromeProfilePath() + "Login Data";
	const char* path = LoginDataPath.c_str();	// Login Data sql文件的路径

	// 根据文件路径打开数据库连接。如果数据库不存在，则创建。
	// 数据库文件的路径必须以C字符串传入。
	int result = sqlite3_open(path, &DB);

	if (result == SQLITE_OK) {
		std::clog << "\n打开数据库连接成功\n";
		const char* sql = "Select origin_url,username_value,password_value from logins";
		int result1 = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
		if (result1 == SQLITE_OK)
		{
			//查询成功
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				cout << "URL	: " << U2G((const char*)sqlite3_column_text(stmt, 0)) << endl;
				cout << "Username: " << U2G((const char*)sqlite3_column_text(stmt, 1)) << endl;
				cout << "Password: " << U2G(Decrypt(sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2)).c_str()) << endl;
				printf("-----------------------------------------------------------------------------------------------------\n");
				Sleep(70);
			}
		}
		else {
			std::clog << "\n查询失败(浏览器可能未关闭)\n";
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
		//关闭数据库
		sqlite3_close(DB);
	}
	else {
		std::clog << "\n打开数据库连接失败\n";
	}
	return ;
}

void OperaRun()
{
	sqlite3* DB = NULL; // 一个打开的数据库实例
	sqlite3_stmt* stmt = NULL;// sqlite3_stmt 预编译语句对象. 由sqlite3_prepare()创建，由sqlite3_finalize()销毁
	string LoginDataPath = getOperaProfilePath() + "Login Data";
	const char* path = LoginDataPath.c_str();	// Login Data sql文件的路径

	// 根据文件路径打开数据库连接。如果数据库不存在，则创建。
	// 数据库文件的路径必须以C字符串传入。
	int result = sqlite3_open(path, &DB);

	if (result == SQLITE_OK) {
		std::clog << "打开数据库连接成功\n";
		const char* sql = "Select origin_url,username_value,password_value from logins";
		int result1 = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
		if (result1 == SQLITE_OK)
		{
			//查询成功
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				cout << "URL	: " << U2G((const char*)sqlite3_column_text(stmt, 0)) << endl;
				cout << "Username: " << U2G((const char*)sqlite3_column_text(stmt, 1)) << endl;
				cout << "Password: " << U2G(Decrypt(sqlite3_column_text(stmt, 2), sqlite3_column_bytes(stmt, 2)).c_str()) << endl;
				printf("--------------------------------------------------------------------------------\n");
				Sleep(70);
			}
		}
		else {
			std::clog << "查询失败(浏览器可能未关闭)\n";
		}
		//清理语句句柄，准备执行下一个语句
		sqlite3_finalize(stmt);
		//关闭数据库
		sqlite3_close(DB);
	}
	else {
		std::clog << "打开数据库连接失败\n";
	}
	return;
}