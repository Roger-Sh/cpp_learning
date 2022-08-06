#include <iostream>
using namespace std;

#include <vector>

/*

#### string子串

**功能描述：**
* 从字符串中获取想要的子串

**函数原型：**
* `string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串


**总结：**灵活的运用求子串功能，可以在实际开发中获取有效的信息
*/


//子串
void test01()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);           //返回由1开始的3个字符组成的字符串
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}

int main() {

	test01();

	return 0;
}