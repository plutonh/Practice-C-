#include <iostream>
#include <cstring>
using namespace std;

namespace LEVEL
{
    enum{CLERK, SENIOR, ASSIST, MANAGER};

    void ShowLevelInfo(int lev)
    {
        switch(lev)
        {
        case CLERK:
            cout<<"���"<<endl;
            break;
        case SENIOR:
            cout<<"����"<<endl;
            break;
        case ASSIST:
            cout<<"�븮"<<endl;
            break;
        case MANAGER:
            cout<<"����"<<endl;
            break;
        }
    } 
}

class NameCard
{
private:
    char * name;
    char * comp;
    char * num;
    int level;

public:
    NameCard(char *myname, char *mycomp, char *mynum, int mylevel)
        : level(mylevel)
    {
        int len=strlen(myname)+1;
        name=new char[len];
        strcpy(name, myname);
        len=strlen(mycomp)+1;
        comp=new char[len];
        strcpy(comp, mycomp);
        len=strlen(mynum)+1;
        num=new char[len];
        strcpy(num, mynum);
    }
    void ShowNameCardInfo()
    {
        cout<<"�̸�: "<<name<<endl;
        cout<<"ȸ��: "<<comp<<endl;
        cout<<"��ȭ��ȣ: "<<num<<endl;
        cout<<"����: "; LEVEL::ShowLevelInfo(level);
        cout<<endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []comp;
        delete []num;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", LEVEL::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", LEVEL::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", LEVEL::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}