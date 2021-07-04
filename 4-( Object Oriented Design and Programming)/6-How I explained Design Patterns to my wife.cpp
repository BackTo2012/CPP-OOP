//StudybarCommentBegin
#include <iostream>
using namespace std;

class IElectricalEquipment {
public:
	virtual void PowerOn() = 0; //每种电器都能打开
	virtual void PowerOff() = 0; //每种电器都能关闭
	virtual ~IElectricalEquipment() { cout << "\nThis is Virtual ~IElectricalEquipment()"; };
};

class Switch {
public:
	IElectricalEquipment *Elec;
	virtual void On() = 0;
	virtual void Off() = 0;
	virtual ~Switch() { cout << "\nThis is Virtual ~Switch()"; }
};
//StudybarCommentEnd

class Fan: public IElectricalEquipment {
public:
	void PowerOn() {cout << "风扇打开" << endl;}
	void PowerOff() {cout << "风扇关闭" << endl;}
};
class Light : public IElectricalEquipment {
public:
	void PowerOn() { cout << "电灯打开" << endl;}
	void PowerOff() {cout << "电灯关闭" << endl;}
};
class FancySwitch: public Switch {
public:
	void On() {cout << "Fancy Switch On" << endl; Elec->PowerOn();      }
	void Off() {cout << "Fancy Switch Off" << endl; Elec->PowerOff();    }
};
class NormalSwitch: public Switch {
public:
	void On() {cout << "Normal Switch On" << endl;  Elec->PowerOn();    }
	void Off() {cout << "Normal Switch Off" << endl; Elec->PowerOff();     }
};
//StudybarCommentBegin
int main(int argc, char** argv) {
	//构造电器设备:风扇,开关
	IElectricalEquipment *fan = new Fan();
	IElectricalEquipment *light = new Light();
	//构造开关
	Switch * fancySwitch = new FancySwitch();
	Switch * normalSwitch = new NormalSwitch();
	//把风扇连接到时尚开关
	fancySwitch->Elec = fan;
	//开关连接到电器,那么当开关打开或关闭时电器应该打开/关闭
	fancySwitch->On();
	fancySwitch->Off();
	//把电灯连接到普通开关
	normalSwitch->Elec = light;
	normalSwitch->On(); //打开电灯
	normalSwitch->Off(); //关闭电灯
	//把电灯连接到时尚开关
	fancySwitch->Elec = light;
	fancySwitch->On();
	fancySwitch->Off();
	delete fan;
	delete light;
	delete fancySwitch;
	delete normalSwitch;
	return 0;
}
//StudybarCommentEnd
