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
    //1为开始
    //2为点读
    //3为导学开始为语音
    //4导学点击
    //5结束画图
    int type;
    int code[255];
    int codelen;
    double distation[2];//此节点绘画的起始位置
    int skip;//正确跳转超过1各位置，需要赋值
    CString text;
    int timeout;//输入点击事件时，超时的时间
    int cods;   //输入点击事件的码值
    int tips;   //开始时tips值
    int next;   //该节点的next的值
};
extern node dat[200];
//此数以下的id号不可用（不包括此数）
extern int id;
extern int datleng;
extern  CString begins;
extern  CString endss;
extern  CString voices;
extern  CString statgame;
extern  double enddistation[2];
extern string datas;
extern int endid;
//选择错误提示类型0默认提示1为自定义提示
extern int errortype;
//double 
extern vector <int > road;//存储所生成线路上的节点id

#endif