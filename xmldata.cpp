
#include "pch.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <atlstr.h>
#include "xmldata.h"



node dat[200];
int datleng = 0;
//�������µ�id�Ų����ã�������������
int id = 0;
CString begins = _T("begin");
CString endss = _T("End");
CString voices = _T("voices");
CString statgame = _T("Say : <@����Ϸ��ʼ��@>");
string datas = "<?xml version = \"1.0\" encoding = \"gbk\"?>\n<tasks>\n  ";
double enddistation[2] = { 0.0 , 0.0 };
int endid=0;
int errortype = 0;
vector <int > road;