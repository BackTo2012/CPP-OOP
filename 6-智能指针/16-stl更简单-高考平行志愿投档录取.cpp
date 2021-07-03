#include <bits/stdc++.h>
using namespace std;
/// <summary>
/// 头文件
/// </summary>
class student
{
private:
	int identify;		//编号
	int grade;			//成绩
	vector<char> plan;		//志愿计划
	char admission;		//最终录取学校
public:
	student();
	int getIdentify() const;
	int getGrade() const;
	int setProfile();				//设定学生档案。如果编号成绩不为0就录入，并返回1. 如果编号成绩为0就返回0，结束录入
	vector<char> getPlan() const;	//传递一份计划副本到被引处
	void setAdmission(char);
	char getAdmission() const;		//设定，读取最终录取学校
};
student::student()
{
	identify = 0;
	grade = 0;
	admission = '0';
}
int student::getIdentify() const
{
	return this->identify;
}
int student::getGrade() const
{
	return this->grade;
}
int student::setProfile()
{
	cin >> identify >> grade;		//学号，成绩

	for (size_t i = 0; i < 5; ++i)
	{
		char _plan = '0';
		cin >> _plan;
		plan.push_back(_plan);
	}//输入志愿

	if (identify == 0 && grade == 0)	return 0;		//结束输入的标记
	else
	{
		return 1;
	}
}
vector<char> student::getPlan() const
{
	return this->plan;
}

void student::setAdmission(char _admission)
{
	this->admission = _admission;
}

char student::getAdmission() const
{
	return this->admission;
}
/// <summary>
/// student类
/// </summary>
class college
{
private:
	char identify;					//学校编号
	int vacancy;					//招生名额
public:
	college(char _identify, int _vacancy);		//构造
	const char getIdentify() const;				//获取学校编号
	const int getVacancy() const;				//获取名额数
	void setVacancy();							//设定名额数
	void vacancyMinusOne();						//名额数减一操作
};
college::college(char _identify = '0', int _vacancy = 0) : identify(_identify), vacancy(_vacancy) {}
const char college::getIdentify() const
{
	return this->identify;
}
const int college::getVacancy() const
{
	return this->vacancy;
}
void college::setVacancy()
{
	cin >> vacancy;
}
void college::vacancyMinusOne()
{
	--this->vacancy;
}
/// <summary>
/// college类
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>

bool compByGrade(const student& a, const student& b);			//排位原则：高分优先
bool compByIdentify(const student& a, const student& b);		//排位原则：号数少的优先。投档后，按学号对学生重新排序

/// <summary>
/// 两个排序函数，用于sort上
/// </summary>
/// <returns></returns>
int main()
{
	college a('a', 0), b('b', 0), c('c', 0), d('d', 0), e('e', 0), f('f', 0), g('g', 0), h('h', 0), i('i', 0), j('j', 0);
	a.setVacancy();
	b.setVacancy();
	c.setVacancy();
	d.setVacancy();
	e.setVacancy();
	f.setVacancy();
	g.setVacancy();
	h.setVacancy();
	i.setVacancy();
	j.setVacancy();		//输入各校名额数


	vector<college> collegeList = { a, b, c, d, e, f, g, h, i, j };
	vector<student> studentList;
	while (1)
	{
		student* newStudent = new student;
		if (newStudent->setProfile() == 1)
		{
			studentList.push_back(*newStudent);
		}
		else
		{
			break;
		}
	}//	录入学生信息



	sort(studentList.begin(), studentList.end(), compByGrade);			//按分数高低排序学生


	vector<student>::iterator currentStudent = studentList.begin();
	void acception(student&, vector<college>&);
	for (; currentStudent != studentList.end(); ++currentStudent)
	{
		acception(*currentStudent, collegeList);	//接收学生档案，学校名单以进行投档（acception）
	}												//完成每位考生的投档后，将按照学生编号对学生名单重新排序


	sort(studentList.begin(), studentList.end(), compByIdentify);		//按学号排序学生
	for (vector<student>::const_iterator currentStudentAdmitted = studentList.begin(); currentStudentAdmitted != studentList.end(); ++currentStudentAdmitted)
	{
		cout << currentStudentAdmitted->getIdentify() << ' ' << currentStudentAdmitted->getAdmission() << endl;
	}																	//输出结果
}

bool compByGrade(const student& a, const student& b)
{
	return a.getGrade() > b.getGrade();
}

bool compByIdentify(const student& a, const student& b)
{
	return a.getIdentify() < b.getIdentify();
}

void acception(student& stu, vector<college>& list)
{
	for (size_t i = 0; i < 5; ++i)
	{
		vector<college>::iterator targetCollege = list.begin();
		while (targetCollege->getIdentify() != stu.getPlan()[i])
		{
			++targetCollege;
		}//targetCollege被定位到plan[i]院校

		if (targetCollege->getVacancy() > 0)
		{
			stu.setAdmission(stu.getPlan()[i]);
			targetCollege->vacancyMinusOne();
			break;
		}//若plan[i]名额未满，就录取到这所学校，该校名额数减一，退出该学生录取工作

		if (targetCollege->getVacancy() == 0 && i != 4)
		{
			continue;
		}//若plan[i]名额满了，名单还未看完，就看下一所院校

		if (targetCollege->getVacancy() == 0 && i == 4)
		{
			stu.setAdmission('x');
			break;
		}//若plan[i]名额满了，名单也看完了，就不作录取，等待征集志愿
	}
}
