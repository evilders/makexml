#pragma once
#ifndef MAKEXML
#define MAKEXML
#include <iostream>
#include <vector>
#include <cstring>
#include <atlstr.h>

using namespace std;

const int  MAX = 50;
class node {
public:
    //1Ϊ��ʼ
    //2Ϊ���
    //3Ϊ��ѧ��ʼΪ����
    //4��ѧ���
    //5������ͼ
    int type;
    int code[255];
    int codelen;
    double distation[2];//�˽ڵ�滭����ʼλ��
    int skip;//��ȷ��ת����1��λ�ã���Ҫ��ֵ
    CString text;
    int timeout;//�������¼�ʱ����ʱ��ʱ��
    int cods;   //�������¼�����ֵ
    int tips;   //��ʼʱtipsֵ
    int next;   //�ýڵ��next��ֵ
};
extern node dat[200];
//�������µ�id�Ų����ã�������������
extern int id;
extern int datleng;
extern  CString begins;
extern  CString endss;
extern  CString voices;
extern  CString statgame;
extern  double enddistation[2];
extern string datas;
extern int endid;
//ѡ�������ʾ����0Ĭ����ʾ1Ϊ�Զ�����ʾ
extern int errortype;
//double 
extern vector <int > road;//�洢��������·�ϵĽڵ�id

#endif