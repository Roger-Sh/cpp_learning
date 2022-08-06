#include <iostream>

using namespace std;

#define MAX 1000    // max number of person

/*
通讯录是一个可以记录亲人、好友信息的工具。

本教程主要利用C++来实现一个通讯录管理系统

系统中需要实现的功能如下：

* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
* 显示联系人：显示通讯录中所有联系人信息
* 删除联系人：按照姓名进行删除指定联系人
* 查找联系人：按照姓名查看指定联系人信息
* 修改联系人：按照姓名重新修改指定联系人
* 清空联系人：清空通讯录中所有信息
* 退出通讯录：退出当前使用的通讯录

*/


/*
添加联系人实现步骤：
* 设计联系人结构体
* 设计通讯录结构体
* main函数中创建通讯录
* 封装添加联系人函数
* 测试添加联系人功能
*/


// person struct
struct Person
{
    string Name;
    int Gender;
    int Age;
    string Phone;
    string Address;
};

// contact_list struct
struct ContactList
{
    struct Person person_array[MAX];
    int size;
};







// menu
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


// add person
// 思路：添加联系人前先判断通讯录是否已满，如果满了就不再添加，
// 未满情况将新联系人信息逐个加入到通讯录
void addPerson(struct ContactList *contact_list)
{
    // 判断通讯录是否填满
    if (contact_list->size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        // init param
        string name;
        int gender = 0;
        int age = 0;
        string phone = "";
        string address = "";

        // 输入姓名
        cout << "请输入姓名： " << endl;
        cin >> name;
        contact_list->person_array[contact_list->size].Name = name;

        // 输入性别
        cout << "请输入性别： " << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while(true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                contact_list->person_array[contact_list->size].Gender= gender;
                break;
            } 
            else
            {
                cout << "性别输入有误，请重新输入" << endl;
            }
        }

        // 输入年龄
        cout << "请输入年龄(0-120)： " << endl;
        while(true)
        {
            cin >> age;
            if(age >= 0 && age <= 120)
            {
                contact_list->person_array[contact_list->size].Age = age;
                break;
            }
            else
            {
                cout << "年龄输入有误，请重新输入" << endl;
            }
        }

        // 输入电话
        cout << "请输入电话： " << endl;
        cin >> phone;
        contact_list->person_array[contact_list->size].Phone = phone;

        // 输入地址
        cout << "请输入地址： " << endl;
        cin >> address;
        contact_list->person_array[contact_list->size].Address = address;

        // 更新人数
        contact_list->size++;

        cout << "添加成功" << endl;
        // system("clear");

    }
}



// show person
// 思路：判断如果当前通讯录中没有人员，就提示记录为空，人数大于0，显示通讯录中信息
void showPerson(struct ContactList *contact_list)
{
    if (contact_list->size == 0)
    {
        cout << "当前记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < contact_list->size; i++)
        {
            cout << "姓名：" << contact_list->person_array[i].Name << endl;
            if(contact_list->person_array[i].Gender == 1)
            {
                cout << "性别：男" << endl;
            }
            else if(contact_list->person_array[i].Gender == 2)
            {
                cout << "性别：女" << endl;
            }

            cout << "年龄：" << contact_list->person_array[i].Age << endl;
            cout << "电话：" << contact_list->person_array[i].Phone << endl;
            cout << "地址：" << contact_list->person_array[i].Address << endl;
        }       
    }
}

// 检查联系人是否存在，存在则返回编号，不存在则返回-1
int checkPerson(struct ContactList *contact_list, string name)
{
    for (int i = 0; i < contact_list->size; i++)
    {
        if (contact_list->person_array[i].Name == name)
        {
            return i;
        }
    }
    return -1;    
}

// 删除联系人
void deletePerson(struct ContactList *contact_list)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int personID = checkPerson(contact_list, name);
    if(personID != -1)
    {
        for (int i = personID; i < contact_list->size-1; i++)
        {
            contact_list->person_array[i] = contact_list->person_array[i+1];
        }
        contact_list->size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;

    }
}


// 查找联系人
// 判断用户指定的联系人是否存在，如果存在显示信息，不存在则提示查无此人。
void findPerson(struct ContactList *contact_list)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name;
    cin >> name;

    int personID = checkPerson(contact_list, name);
    if(personID != -1)
    {
        cout << "姓名：" << contact_list->person_array[personID].Name << endl;
        if(contact_list->person_array[personID].Gender == 1)
        {
            cout << "性别：男" << endl;
        }
        else if(contact_list->person_array[personID].Gender == 2)
        {
            cout << "性别：女" << endl;
        }

        cout << "年龄：" << contact_list->person_array[personID].Age << endl;
        cout << "电话：" << contact_list->person_array[personID].Phone << endl;
        cout << "地址：" << contact_list->person_array[personID].Address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

}

// 修改联系人
// 实现思路：查找用户输入的联系人，如果查找成功进行修改操作，查找失败提示查无此人
void modifyPerson(struct ContactList * contact_list)
{
    cout << "请输入您想要修改的联系人姓名" << endl;
    string name;
    cin >> name;

    int personID = checkPerson(contact_list, name);
    if (personID != -1)
    {
        // init param
        string name;
        int gender = 0;
        int age = 0;
        string phone = "";
        string address = "";

        // 输入姓名
        cout << "请输入姓名： " << endl;
        cin >> name;
        contact_list->person_array[personID].Name = name;

        // 输入性别
        cout << "请输入性别： " << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while(true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                contact_list->person_array[personID].Gender= gender;
                break;
            } 
            else
            {
                cout << "性别输入有误，请重新输入" << endl;
            }
        }

        // 输入年龄
        cout << "请输入年龄(0-120)： " << endl;
        while(true)
        {
            cin >> age;
            if(age >= 0 && age <= 120)
            {
                contact_list->person_array[personID].Age = age;
                break;
            }
            else
            {
                cout << "年龄输入有误，请重新输入" << endl;
            }
        }

        // 输入电话
        cout << "请输入电话： " << endl;
        cin >> phone;
        contact_list->person_array[personID].Phone = phone;

        // 输入地址
        cout << "请输入地址： " << endl;
        cin >> address;
        contact_list->person_array[personID].Address = address;

        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
}


// 清空联系人
void clearPerson(struct ContactList * contact_list)
{
    contact_list->size = 0;
    cout << "通讯录已清空" << endl;
}

int main() 
{
    // init contact list
    struct ContactList contact_list;
    contact_list.size = 0;



    int select = 0;

    while (true)
    {
        showMenu();
        
        cin >> select;

        switch (select)
        {
            case 1:         // 添加联系人
                addPerson(&contact_list);
                break;
            case 2:         // 显示联系人
                showPerson(&contact_list);
                break;
            case 3:         // 删除联系人
                deletePerson(&contact_list);
                break;
            case 4:         // 查找联系人
                findPerson(&contact_list);
                break;
            case 5:         // 修改联系人
                modifyPerson(&contact_list);
                break;
            case 6:         // 清空联系人
                clearPerson(&contact_list);
                break;
            case 0:         // 推出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                break;
        }
    }
    
    return 0;
}