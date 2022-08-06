#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"




// constructor
WorkerManager::WorkerManager()
{
	// 打开保存的数据文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "File does not exist!" << endl;	

		// init
		this->m_workerNum = 0;			
		this->m_FileIsEmpty = true;		
		this->m_workerArray = NULL;
		
		ifs.close();
		return;
	}

	// 文件存在，并且没有记录的情况
	char ch;
	ifs >> ch;
	if(ifs.eof())	// 检查是否为文件末尾
	{
		cout << "File is empty!" << endl;
		this->m_workerNum = 0;
		this->m_FileIsEmpty = true;
		this->m_workerArray = NULL;
		ifs.close();
		return;
	}

	// 文件存在，并且有记录的情况
	// 得到员工数量
	int num = this->get_WorkerNum();
	cout << "Worker number: " << num << endl;	// test 
	this->m_workerNum = num;
	// 根据职工数量创建职工数组
	this->m_workerArray = new Worker *[this->m_workerNum];
	init_Worker();

	// 输出读取的职工数组
	for (int i = 0; i < m_workerNum; i++)
	{
		cout << "Worker ID: " << this->m_workerArray[i]->m_ID
			 << " Worker name: " << this->m_workerArray[i]->m_Name
			 << " Worker department ID: " << this->m_workerArray[i]->m_DeptID << endl;
	}
	
	this->m_FileIsEmpty = false;
	
}

// deconstructor
WorkerManager::~WorkerManager()
{
	if (this->m_workerArray != NULL)
	{
		delete[] this->m_workerArray;
	}
}

// show menu
void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


// exit system
void WorkerManager::exit_system()
{
    cout << "See you next time!" << endl;
    exit(0);
}

// add worker
// 分析：
// 用户在批量创建时，可能会创建不同种类的职工
// 如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里
// 如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker **的指针维护
void WorkerManager::add_worker()
{
	// 输入要添加的人数
	cout << "Please enter the number of the new worker: " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// 计算新空间大小
		int newSize = this->m_workerNum + addNum;

		// 开辟新空间
		Worker ** newSpace = new Worker*[newSize];

		// 将原空间下内容存放到新空间
		if (this->m_workerArray != NULL)
		{
			for (int i = 0; i < this->m_workerNum; i++)
			{
				newSpace[i] = this->m_workerArray[i];
			}
		}

		// 输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int ID;
			string name;
			int dSelect;

			cout << "Please enter the ID of the new worker: " << endl;
			cin >> ID;
			cout << "Please enter the name of the new worker: " << endl;
			cin >> name;
			
			while(true)
			{
				cout << "Please enter the position of the new worker: " << endl;
				cout << "1 - employee" << endl;
				cout << "2 - manager" << endl;
				cout << "3 - boss" << endl;
				cin >> dSelect;
				if(dSelect == 1 || dSelect == 2 || dSelect == 3)
				{
					break;
				}
				else
				{
					cout << "Wrong enter!" << endl;
				}
			}

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:			// employee
				worker = new Employee(ID, name, 1);
				break;
			case 2:			// manager
				worker = new Manager(ID, name, 2);
				break;
			case 3:			// boss
				worker = new Boss(ID, name, 3);
				break;
			
			default:
				break;
			}


			newSpace[this->m_workerNum + i] = worker;
		}

		// 释放原有空间
		delete[] this->m_workerArray;

		// 更新新空间指向
		this->m_workerArray = newSpace;

		// 更新人数
		this->m_workerNum = newSize;

		// 更新职工不为空的标记
		this->m_FileIsEmpty = false;

		// 提示信息
		cout << "Successfully added worker number: " << addNum << endl;		
	
		// 保存到文件
		this->save();
	}

	else
	{
		cout << "Wrong number!" << endl;
	}

}


// 保存数据
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_workerNum; i++)
	{
		ofs << this->m_workerArray[i]->m_ID << " "
			<< this->m_workerArray[i]->m_Name << " "
			<< this->m_workerArray[i]->m_DeptID << endl;
	}

	ofs.close();
	
}


// 获取记录的职工人数
int WorkerManager::get_WorkerNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// worker attribution
	int ID;
	string name;
	int dID;

	// number of worker
	int num = 0;

	while (ifs >> ID && ifs >> name && ifs >>dID)
	{
		num++;
	}

	ifs.close();

	return num;
	
}


// 初始化职工数组
void WorkerManager::init_Worker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int index = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker * worker = NULL;

		// 根据不同部门ID 创建不同对象
		if (dID = 1)		
		{
			worker = new Employee(ID, name, dID);
		}
		else if (dID = 2)
		{
			worker = new Manager(ID, name, dID);
		}
		else if (dID = 3)
		{
			worker = new Boss(ID, name, dID);
		}

		// 存放在数组
		this->m_workerArray[index] = worker;
		index++;
	}
}


// 显示职工信息
void WorkerManager::show_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "File empty or not exist!" << endl;
	}
	else
	{

		cout << "Worker number: " << m_workerNum << endl;		
		for (int i = 0; i < m_workerNum; i++)
		{
			// 利用多态调用接口
			this->m_workerArray[i]->show_info();
		}
	}
}


// 检查职工是否存在
int WorkerManager::isExit(int ID)
{
	int index = -1;

	// 遍历查找
	for (int i = 0; i < this->m_workerNum; i++)
	{
		if (this->m_workerArray[i]->m_ID == ID)
		{
			index = i;

			break;
		}
	}

	return index;	
}


// 删除职工
void WorkerManager::del_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "File is empty or not exist!" << endl;
	}
	else
	{
		// 按职工编号删除
		cout << "Please enter the ID to be deleted: " << endl;

		int ID = 0;
		cin >> ID;

		// 检查是否存在ID, 如果是，返回该ID, 如果不是，返回-1
		int index = this->isExit(ID);

		if (index != -1)	// 说明存在该ID的员工
		{
			// 将后面的数据保存到前面，覆盖这个要删除的ID
			for (int i = index; i < this->m_workerNum - 1; i++)
			{
				this->m_workerArray[i] = this->m_workerArray[i + 1];
			}
			
			//人数减一
			this->m_workerNum--;	
			
			// 输出成功删除的提示
			cout << "Deleted successfully!\n" << endl;
			
			// 删除后数据保存到文件
			this->save();	
		}
		else
		{
			cout << "Delete failed, there is no worker with this ID！\n" << endl;
		}	
	}
}


// 修改职工信息
void WorkerManager::mod_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "File not exist or empty!" << endl;
	}
	else
	{
		cout << "Please enter the worker ID you want to modify: " << endl;
		int id;
		cin >> id;

		int index = this->isExit(id);
		if (index != -1)
		{
			// 查找该编号的员工
			delete this->m_workerArray[index];

			// init
			int newID = 0;
			string newName = "";
			int newDID = 0;

			// 输入员工属性
			cout << "Found the worker with ID " << id <<endl;

			cout << "Please enter the new ID: " << endl;
			cin >> newID;

			cout << "Please enter the new Name: " << endl;
			cin >> newName;
			
			while (true)
			{
				cout << "Please enter the new department ID: " << endl;
				cout << "1 - Employee" << endl;
				cout << "2 - Manager" << endl;
				cout << "3 - Boss" << endl;
				cin >> newDID;
				if (newDID == 1 || newDID == 2 || newDID == 3) 
				{
					break;
				}
				else
				{
					cout << "Wrong enter!" << endl;
				}
			}

			Worker * worker = NULL;
			switch (newDID)
			{
			case 1:
				worker = new Employee(newID, newName, newDID);
				break;
			case 2:
				worker = new Manager(newID, newName, newDID);
				break;
			case 3:
				worker = new Boss(newID, newName, newDID);
				break;
			default:
				break;
			}

			this->m_workerArray[index] = worker;
			cout << "Modify successfully!" << endl;

			// 保存到文件
			this->save();
		}
		else
		{
			cout << "There is no worker with ID: " << id << endl;
		}
	}
}


// 查找员工，通过职工编号或者通过名字
void WorkerManager::find_worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "File empty or not exist!" << endl;
	}
	else
	{
		int select = 0;
		while(true)
		{
			cout << "Please select the way to find worker: " << endl;
			cout << "1 - find by worker ID" << endl;
			cout << "2 - find by worker name" << endl;

			cin >> select;
			if (select == 1 || select == 2)
			{
				break;
			}
			else
			{
				cout << "Wrong select!" << endl;
			}
		}


		if (select == 1) 	// find by worker ID
		{
			int id;
			cout << "Please enter the worker ID: " << endl;
			cin >> id;

			int index = isExit(id);
			if (index != -1)
			{
				cout << "Found the worker with ID " << id << endl;
				this->m_workerArray[index]->show_info();
			}
			else
			{
				cout << "There is no worker with ID " << id << endl;
			}
		}
		else if (select == 2) // find by worker name
		{
			string name;
			cout << "Please enter the worker name: " << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_workerNum; i++)
			{
				if (m_workerArray[i]->m_Name == name)
				{
					cout << "Found the worker with name " << name << endl;
					flag = true;
					this->m_workerArray[i]->show_info();
				}			
			}

			if (flag = false)
			{
				cout << "There is no worker with name " << name << endl;
			}
		}
		else
		{
			cout << "Wrong select!" << endl;
		}
	}
}


// 排序
void WorkerManager::sort_worker()
{
	if(this->m_FileIsEmpty)
	{
		cout << "File empty or not exist!" << endl;
	}
	else
	{
		int select = 0;
		while(true)
		{
			cout << "Please select the way to sort: " << endl;
			cout << " 1 - Sorted by employee ID in ascending order" << endl;
			cout << " 2 - Sorted by employee ID in descending order" << endl;
		
			cin >> select;

			if (select == 1 || select == 2)
			{
				break;
			}
			else
			{
				cout << "Wrong select" << endl;
			}
		}

		for (int i = 0; i < m_workerNum; i++)
		{
			int min_max = i;
			for (int j = i + 1; j < m_workerNum; j++)
			{
				if (select == 1) 	// ascending order 升序
				{
					if (m_workerArray[min_max]->m_ID > m_workerArray[j]->m_ID)
					{
						min_max = j;
					}
				}
				else				// descending order 降序
				{
					if (m_workerArray[min_max]->m_ID < m_workerArray[j]->m_ID)
					{
						min_max = j;
					}
				}			
			}

			if (i != min_max)
			{
				Worker * tmp = m_workerArray[i];
				m_workerArray[i] = m_workerArray[min_max];
				m_workerArray[min_max] = tmp;
			}
		}

		cout << "Sort successfully!" << endl;
		this->save();
		this->show_worker();
	}
}

// 清空
void WorkerManager::clean_file()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if(select == 1)
	{
		// 打开模式 ios::trunc 如果存在，删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_workerArray !=NULL)
		{
			// delete every element in m_workerArray
			for (int i = 0; i < this->m_workerNum; i++)
			{
				if (this->m_workerArray[i] != NULL)
				{
					delete this->m_workerArray[i];
				}
			}

			// init
			this->m_workerNum = 0;
			delete[] this->m_workerArray;
			this->m_workerArray = NULL;
			this->m_FileIsEmpty = true;
		}

		cout << "Clean successfully!" << endl;
	}
	else if(select == 2)
	{
		cout << "Cancel clean, back to menu!" << endl;
	}
}