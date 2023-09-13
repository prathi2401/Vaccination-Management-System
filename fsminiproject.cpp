#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;

class center
{
    string centerid,centername,centerstate,centercity,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search1(string);
    void modify(string);
}b;

void center::read()
{
    cout<<"Enter [center ID, center name, center state, center city]\n";
    cin>>centerid>>centername>>centerstate>>centercity;
}

void center::pack()
{
    buffer.erase();
    buffer+=centerid+"|"+centername+"|"+centerstate+"|"+centercity+"$\n";
}
void center::r_f()
{
    fstream fp;
    fp.open("center.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof() && buffer[0]!='*')
        display();
    }
    fp.close();
}

void center::unpack()
{
    int i=0;
    centerid.erase();
    while(buffer[i]!='|')
    centerid+=buffer[i++];
    i++;
    centername.erase();
    while(buffer[i]!='|')
    centername+=buffer[i++];
    i++;
    centerstate.erase();
    while(buffer[i]!='|')
    centerstate+=buffer[i++];
    i++;
    centercity.erase();
    while(buffer[i]!='$')
    centercity+=buffer[i++];
}

void center::display()
{
    cout<<"Center ID: "<<centerid<<"\t"<<"Center name: "<<centername<<"\t"<<"Center state: "<<centerstate<<"\t"<<"Center city: "<<centercity<<endl;
}

int center::search1(string num)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("center.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        if(buffer[0]!='*')
        recno++;
        unpack();
        if(centerid==num)
        {
            cout<<"\n record is "<<buffer;
            cout<<"\n record is found at position "<<recno;
            cout<<"\n";
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
        cout<<"record not found\n";
    return pos;
}

int center::del(string num)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(num);
    if(pos)
    {
        fp.open("center.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&& pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
        fp.seekp(pos+2,ios::beg);
        else
        fp.seekp(pos,ios::beg);
        fp.put(mark);
        flag=1;
    }
    fp.close();
    if(!flag)
    return 0;
    else
    return 1;
}

void center::modify(string num)
{
    if(del(num))
    {
        cout<<"\nEnter details[CenterId,CenterName,CenterState,CenterCity] to modify\n";
        cin>>centerid>>centername>>centerstate>>centercity;
        buffer.erase();
        pack();
        w_f();
    }
}

void center::w_f()
{
    fstream fp;
    fp.open("center.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
//2nd class
class registration
{
    string regid,pername,perphone,peremail,centerid,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search1(string);
    void modify(string);
}c;

void registration::read()
{
    cout<<"Enter details[Registratonid,Personname,Personphone,Personemail,Centerid]\n";
    cin>>regid>>pername>>perphone>>peremail>>centerid;
}

void registration::pack()
{
    buffer.erase();
    buffer+=regid+"|"+pername+"|"+perphone+"|"+peremail+"|"+centerid+"$\n";
}
void registration::r_f()
{
    fstream fp;
    fp.open("register.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof()&&buffer[0]!='*')
        display();
    }
    fp.close();
}
void registration::unpack()
{
    int i=0;
    regid.erase();
    while(buffer[i]!='|')
    regid+=buffer[i++];
    i++;
    pername.erase();
    while(buffer[i]!='|')
    pername+=buffer[i++];
    i++;
    perphone.erase();
    while(buffer[i]!='|')
    perphone+=buffer[i++];
    i++;
    peremail.erase();
    while(buffer[i]!='|')
    peremail+=buffer[i++];
    i++;
    centerid.erase();
    while(buffer[i]!='$')
    centerid+=buffer[i++];
    i++;
}

void registration::display()
{
    cout<<"RegistratonId:"<<regid<<"\n"<<"Person name:"<<pername<<"\n"<<"Person email:"<<peremail<<"\n"<<"Person phone:"<<perphone<<"\n"<<"Center Id:"<<centerid<<"\n"<<endl;
}

int registration::search1(string num)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("register.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        if(buffer[0]!='*')
        recno++;
        unpack();
        if(regid==num)
        {
            cout<<"\nrecord is "<<buffer;
            cout<<"\nRecord found at position "<<recno;
            cout<<"\n";
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
    cout<<"Record not found\n";
    return pos;
}

int registration::del(string num)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(num);
    if(pos)
    {
        fp.open("register.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&&pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
        fp.seekp(pos+2,ios::beg);
        else
        fp.seekp(pos,ios::beg);
        fp.put(mark);
        flag=1;
    }
    fp.close();
    if(!flag)
    return 0;
    else
    return 1;
}

void registration::modify(string num)
{
    if(del(num))
    {
        cout<<"\nEnter details[Registratonid,Personname,Personemail,Personphone,Centerid]\n";
        cin>>regid>>pername>>perphone>>peremail>>centerid;
        buffer.erase();
        pack();
        w_f();
    }
}
void registration::w_f()
{
    fstream fp;
    fp.open("register.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
//staff
class staff
{
    string staffid,staffname,staffphone,staffmail,centerid,staffsalary,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search1(string);
    void modify(string);
}e;

void staff::read()
{
    cout<<"Enter details[staffid staffname staffphone staffmail staffcenterid staffsalary]\n";
    cin>>staffid>>staffname>>staffphone>>staffmail>>centerid>>staffsalary;
}

void staff::pack()
{
    buffer.erase();
    buffer+=staffid+"|"+staffname+"|"+staffphone+"|"+staffmail+"|"+centerid+"|"+staffsalary+"$\n";
}

void staff::r_f()
{
    fstream fp;
    fp.open("staff.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof()&&buffer[0]!='*')
        display();
    }
    fp.close();
}

void staff::unpack()
{
    int i=0;
    staffid.erase();
    while(buffer[i]!='|')
    staffid+=buffer[i++];
    i++;
    staffname.erase();
    while(buffer[i]!='|')
    staffname+=buffer[i++];
    i++;
    staffphone.erase();
    while(buffer[i]!='|')
    staffphone+=buffer[i++];
    i++;
    staffmail.erase();
    while(buffer[i]!='|')
    staffmail+=buffer[i++];
    i++;
    centerid.erase();
    while(buffer[i]!='|')
    centerid+=buffer[i++];
    i++;
    staffsalary.erase();
    while(buffer[i]!='$')
    staffsalary+=buffer[i++];
    i++;
}

void staff::display()
{
    cout<<"staffid:"<<staffid<<"\n"<<"staffname:"<<staffname<<"\n"<<"staffphone:"<<staffphone<<"\n"<<"staffmail:"<<staffmail<<"\n"<<"centerid:"<<centerid<<"\n"<<"staffSalary:"<<staffsalary<<"\n"<<endl;
}

int staff::search1(string num)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("staff.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        if(buffer[0]!='*')
        recno++;
        unpack();
        if(staffid==num)
        {
            cout<<"\nrecord is"<<buffer;
            cout<<"\nRecord found at position"<<recno;
            cout<<"\n";
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
    cout<<"Record not found\n";
    return pos;
}

int staff::del(string num)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(num);
    if(pos)
    {
        fp.open("staff.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&&pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
        fp.seekp(pos+2,ios::beg);
        else
        fp.seekp(pos,ios::beg);
        fp.put(mark);
        flag=1;
    }
    fp.close();
    if(!flag)
    return 0;
    else
    return 1;
}

void staff::modify(string num)
{
    if(del(num))
    {
        cout<<"Enter details[staffid staffname staffphone staffmail staffcenterid staffsalary]\n";
        cin>>staffid>>staffname>>staffphone>>staffmail>>centerid>>staffsalary;
        buffer.erase();
        pack();
        w_f();
    }
}

void staff::w_f()
{
    fstream fp;
    fp.open("staff.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
//vaccine
class vaccine
{
    string regid,centerid,vacctype,vaccdate,nextdozedate,vaccstatus,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search1(string);
    void modify(string);
}a;

void vaccine::read()
{
    cout<<"Enter details[registratonid centerid vaccineType vaccdate nextdozedate vaccinestatus ]\n";
    cin>>regid>>centerid>>vacctype>>vaccdate>>nextdozedate>>vaccstatus;
}

void vaccine::pack()
{
    buffer.erase();
    buffer+=regid+"|"+centerid+"|"+vacctype+"|"+vaccdate+"|"+nextdozedate+"|"+vaccstatus+"$\n";
}
void vaccine::r_f()
{
    fstream fp;
    fp.open("vaccine.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof())
        display();
    }
    fp.close();
}

void vaccine::unpack()
{
    int i=0;
    regid.erase();
    while(buffer[i]!='|')
    regid+=buffer[i++];
    i++;
    centerid.erase();
    while(buffer[i]!='|')
    centerid+=buffer[i++];
    i++;
    vacctype.erase();
    while(buffer[i]!='|')
    vacctype+=buffer[i++];
    i++;
    vaccdate.erase();
    while(buffer[i]!='|')
    vaccdate+=buffer[i++];
    i++;
    nextdozedate.erase();
    while(buffer[i]!='|')
    nextdozedate+=buffer[i++];
    i++;
    vaccstatus.erase();
    while(buffer[i]!='$')
    vaccstatus+=buffer[i++];
    i++;
}

void vaccine::display()
{
    cout<<"registratonid:"<<regid<<"\n"<<"centerid:"<<centerid<<"\n"<<"vaccinetype:"<<vacctype<<"\n"<<"vaccdate:"<<vaccdate<<"\n"<<"nextdozedate:"<<nextdozedate<<"\n"<<"vaccinestatus:"<<vaccstatus<<"\n"<<endl;
}

int vaccine::search1(string num)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("vaccine.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        if(buffer[0]!='*')
        recno++;
        unpack();
        if(regid==num)
        {
            cout<<"\nrecord is"<<buffer;
            cout<<"\nRecord found at position"<<recno;
            cout<<"\n";
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
    cout<<"Record not found\n";
    return pos;
}

int vaccine::del(string num)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(num);
    if(pos)
    {
        fp.open("vaccine.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&&pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
        fp.seekp(pos+2,ios::beg);
        else
        fp.seekp(pos,ios::beg);
        fp.put(mark);
        flag=1;
    }
    fp.close();
    if(!flag)
    return 0;
    else
    return 1;
}

void vaccine::modify(string num)
{
    if(del(num))
    {
        cout<<"\n Enter details[registratonid centerid vaccineType vaccdate nextdozedate vaccinestatus]\n";
        cin>>regid>>centerid>>vacctype>>vaccdate>>nextdozedate>>vaccstatus;
        buffer.erase();
        pack();
        w_f();
    }
}

void vaccine::w_f()
{
    fstream fp;
    fp.open("vaccine.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
//availabilitys
class availability
{
    string regid,staffid,amount,vaccinationtype,doze,buffer;
    public:
    void unpack();
    void read();
    void r_f();
    void w_f();
    void display();
    void pack();
    int del(string);
    int search1(string);
    void modify(string);
}t;

void availability::read()
{
    cout<<"Enter details[registratonid staffid amount vaccinationtype,in_out]\n";
    cin>>regid>>staffid>>amount>>vaccinationtype>>doze;
}

void availability::pack()
{
    buffer.erase();
    buffer+=regid+"|"+staffid+"|"+amount+"|"+vaccinationtype+"|"+doze+"$\n";
}

void availability::r_f()
{
    fstream fp;
    fp.open("availability.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof()&&buffer[0]!='*')
        display();
    }
fp.close();
}

void availability::unpack()
{
    int i=0;
    regid.erase();
    while(buffer[i]!='|')
    regid+=buffer[i++];
    i++;
    staffid.erase();
    while(buffer[i]!='|')
    staffid+=buffer[i++];
    i++;
    amount.erase();
    while(buffer[i]!='|')
    amount+=buffer[i++];
    i++;
    vaccinationtype.erase();
    while(buffer[i]!='|')
    vaccinationtype+=buffer[i++];
    i++;
    doze.erase();
    while(buffer[i]!='$')
    doze+=buffer[i++];
    i++;
}

void availability::display()
{
    cout<<"registratonid:"<<regid<<"\n"<<"staffid:"<<staffid<<"\n"<<"Amount:"<<amount<<"\n"<<"vaccinationtype:"<<vaccinationtype<<"\n"<<"in_out:"<<doze<<"\n"<<endl;
}

int availability::search1(string num)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("availability.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        if(buffer[0]!='*')
        recno++;
        unpack();
        if(regid==num)
        {
            cout<<"\nrecord is"<<buffer;
            cout<<"\nRecord found at position"<<recno;
            cout<<"\n";
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
    cout<<"Record not found\n";
    return pos;
}

int availability::del(string num)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(num);
    if(pos)
    {
        fp.open("availability.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&&pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
        fp.seekp(pos+2,ios::beg);
        else
        fp.seekp(pos,ios::beg);
        fp.put(mark);
        flag=1;
    }
    fp.close();
    if(!flag)
    return 0;
    else
    return 1;
}

void availability::modify(string num)
{
    if(del(num))
    {
        cout<<"Enter details[registratonid staffid amount,vaccinationtype,doze]\n";
        cin>>regid>>staffid>>amount>>vaccinationtype>>doze;
        buffer.erase();
        pack();
        w_f();
    }
}

void availability::w_f()
{
    fstream fp;
    fp.open("availability.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}

main()
{
    string num;
    int ch,ch1,ch2,ch3,ch4,ch5;
    cout<<"######################################################################\n";
    cout<<"\n";
    cout<<"\t\t VACCINATION MANAGENMENT USING VARIABLE LENGTH RECORD\t\n";
    cout<<"\n";
    while(1)
    {
        cout<<"######################################################################\n";
        cout<<"1.Center\n2.Registration\n3.Staff\n4.Vaccine\n5.Availability\n6.Exit"<<endl;
        cout<<"\n";
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: do
                    {
                        cout<<"\n!!!!!!!!!!!!!!!!!!!!!!center Information!!!!!!!!!!!!!!!!!!!!!!!\n"<<endl;
                        cout<<"1.read records\n2.display record\n3.search record\n4.Modify record\n5.back to home\n";
                        cout<<"\n";
                        cout<<"enter your choice\n";
                        cin>>ch1;
                        switch(ch1)
                        {
                            case 1: b.read();
                                    b.pack();
                                    b.w_f();
                                    break;

                            case 2: b.r_f();
                                    break;
                            case 3: cout<<"enter center id number to search\n";
                                    cin>>num;
                                    b.search1(num);
                                    break;
                            case 4: cout<<"Enter center id to modify\n";
                                    cin>>num;
                                    b.modify(num);
                                    break;
                            default:break;
                        }
                    }while(ch1<5);
                    break;

            case 2: do
                    {
                        cout<<"!!!!!!!!!!!!!!!!!!!!!!! registration Information!!!!!!!!!!!!!!!!!!!!!"<<endl;
                        cout<<"1.read records\n2.display record\n3.search record\n4.Modify record\n5.back to home\n";
                        cout<<"\n";
                        cout<<"enter your choice\n";
                        cin>>ch2;
                        switch(ch2)
                        {
                            case 1: c.read();
                                    c.pack();
                                    c.w_f();
                                    break;
                            case 2: c.r_f();
                                    break;
                            case 3: cout<<"enter vaccine no number to search\n";
                                    cin>>num;
                                    c.search1(num);
                                    break;
                            case 4: cout<<"Enter vaccineno to modify\n";
                                    cin>>num;
                                    c.modify(num);
                                    break;
                            default:break;
                        }
                    }while(ch2<5);
                    break;

            case 3: do
                    {
                        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!staff Information!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                        cout<<"1.read records\n2.Display record\n3.Search record\n4.Modify record\n5.back to home\n";
                        cout<<"\n";
                        cout<<"enter your choice\n";
                        cin>>ch3;
                        switch(ch3)
                        {
                            case 1: e.read();
                                    e.pack();
                                    e.w_f();
                                    break;
                            case 2: e.r_f();
                                    break;
                            case 3: cout<<"enter staffid to search\n";
                                    cin>>num;
                                    e.search1(num);
                                    break;
                            case 4: cout<<"Enter staffid to modify\n";
                                    cin>>num;
                                    e.modify(num);
                                    break;
                            default:break;
                        }
                    }while(ch3<5);
                    break;

            case 4: do
                    {
                        cout<<"!!!!!!!!!!!!!!!!!!!!!!!! vaccine Information!!!!!!!!!!!!!!!!!!!!!"<<endl;
                        cout<<"1.Read records\n2.Display record\n3.Search record\n4.Modify record\n5.Back to home\n";
                        cout<<"\n";
                        cout<<"Enter your choice\n";
                        cin>>ch4;
                        switch(ch4)
                        {
                            case 1: a.read();
                                    a.pack();
                                    a.w_f();
                                    break;
                            case 2: a.r_f();
                                    break;
                            case 3: cout<<"Enter vaccineno number to search\n";
                                    cin>>num;
                                    a.search1(num);
                                    break;
                            case 4: cout<<"Enter vaccineno to modify\n";
                                    cin>>num;
                                    a.modify(num);
                                    break;
                            default:break;
                        }
                    }while(ch4<5);
                    break;

            case 5: do
                    {
                        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!! availability Information!!!!!!!!!!!!!!!!!!"<<endl;
                        cout<<"1.Read records\n2.Display record\n3.Search record\n4.Modify record\n5.Back to  home\n";
                        cout<<"\n";
                        cout<<"Enter your choice\n";
                        cin>>ch5;
                        switch(ch5)
                        {
                            case 1: t.read();
                                    t.pack();
                                    t.w_f();
                                    break;
                            case 2: t.r_f();
                                    break;
                            case 3: cout<<"Enter vaccineno number to search\n";
                                    cin>>num;
                                    t.search1(num);
                                    break;
                            case 4: cout<<"Enter vaccineno to modify\n";
                                    cin>>num;
                                    t.modify(num);
                                    break;
                            default:break;
                        }
                    }while(ch5<5);
                    break;

            default:exit(0);
                    break;
        }
    }
}
