# 简介
该项目可进行对Chrome，Firefox和Opera浏览器保存的用户登录信息进行解密。

**运行安装程序即可安装程序使用，适用于Chrome，Firefox，Opera的绝大部分版本。**

# 注：

1. 在编译时需要加入`sqlite3`的依赖，具体步骤见[C++ Basic use of sqlite3](https://www.shangzg.top/c++/C++-Basic-use-of-sqlite3.html)，并在64位的环境下编译。

2. 具体原理讲解见：

   Firefox：[Firefox browser login information extraction and decryption](https://www.shangzg.top/c++/technology/Firefox-browser-login-information-extraction-and-decryption.html)

   Chrome:[Chrome login information extraction and password decryption](https://www.shangzg.top/c++/technology/Chrome-login-information-extraction-and-password-decryption.html)

   Opera：[Opera login information extraction and password decryption](https://www.shangzg.top/c++/technology/Opera-login-information-extraction-and-password-decryption.html)

3. 此项目是针对之前分别对不同浏览器（Chrome，Opera，Firefox）进行用户登录信息解密的三个项目的整理集合，并对之前的代码进行了改进和完善，然后做成了可安装程序。改进方面及可安装程序实现方法见我的blog
[Browser user information Decrypt](https://www.shangzg.top/c++/technology/Browser-user-information-Decrypt.html)
