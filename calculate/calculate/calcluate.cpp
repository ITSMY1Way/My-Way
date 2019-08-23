#include "calculate.h"
//QStack<double> Data;
//QStack<char> Symb;
double allocate(const char *S); //数和运算符分类
QStack<char> check(char c, QStack<double>* Data, QStack<char> Symb);//运算符分类处理
int  getPri(char c); //计算优先级
QStack<char> calcu(QStack<double>* Data, QStack<char> Symb);//计算栈顶元素
calculate::calculate(QWidget *parent) : QMainWindow(parent)
{
	QWidget *widget = new QWidget; //构建一个QWidget布局将设置的布局添加进这个QWidget
	this->setCentralWidget(widget);
	inputLine = new QLineEdit;
	inputLine->setText(input);
	zeroButton = new  QPushButton("0");
	oneButton = new   QPushButton("1");
	twoButton = new   QPushButton("2");
	threeButton = new QPushButton("3");
	fourButton = new  QPushButton("4");
	fiveButton = new  QPushButton("5");
	sixButton = new   QPushButton("6");
	sevenButton = new QPushButton("7");
	eightButton = new QPushButton("8");
	nineButton = new  QPushButton("9");
	decButton = new   QPushButton(".");
	addButton = new QPushButton("+");
	subButton = new QPushButton("-");
	mulButton = new QPushButton("*");
	divButton = new QPushButton("/");
	equButton = new QPushButton("=");
	lefButton = new QPushButton("(");
	rigButton = new QPushButton(")");
	CEButton = new QPushButton("CE");
	ACButton = new QPushButton("AC");
	QGridLayout *H = new QGridLayout(this); //声明了一个网格布局
	inputLine->setFixedHeight(50); //调整第一行宽度大小
	CEButton->setFixedHeight(50);
	ACButton->setFixedHeight(50);
	H->addWidget(inputLine, 0, 0, 1, 3);  //在（0，0）位置设置一行三列的区域
	H->setRowStretch(0, 100);//设置行宽
	H->addWidget(CEButton, 0, 3);
	H->addWidget(ACButton, 0, 4);
	H->addWidget(sevenButton, 1, 0);
	H->addWidget(eightButton, 1, 1);
	H->addWidget(nineButton, 1, 2);
	H->addWidget(addButton, 1, 3);
	H->addWidget(subButton, 1, 4);
	H->addWidget(fourButton, 2, 0);
	H->addWidget(fiveButton, 2, 1);
	H->addWidget(sixButton, 2, 2);
	H->addWidget(mulButton, 2, 3);
	H->addWidget(divButton, 2, 4);
	H->addWidget(oneButton, 3, 0);
	H->addWidget(twoButton, 3, 1);
	H->addWidget(threeButton, 3, 2);
	H->addWidget(lefButton, 3, 3);
	H->addWidget(rigButton, 3, 4);
	H->addWidget(zeroButton, 4, 0);
	H->addWidget(decButton, 4, 1, 1, 2);
	H->addWidget(equButton, 4, 3, 1, 2);
	widget->setLayout(H); //将布局显示出来
	//数字输入
	connect(zeroButton, SIGNAL(clicked()), this, SLOT(buttonZeroClicked()));//信号与槽函数
	connect(oneButton, SIGNAL(clicked()), this, SLOT(buttonOneClicked()));
	connect(twoButton, SIGNAL(clicked()), this, SLOT(buttonTwoClicked()));
	connect(threeButton, SIGNAL(clicked()), this, SLOT(buttonThreeClicked()));
	connect(fourButton, SIGNAL(clicked()), this, SLOT(buttonFourClicked()));
	connect(fiveButton, SIGNAL(clicked()), this, SLOT(buttonFiveClicked()));
	connect(sixButton, SIGNAL(clicked()), this, SLOT(buttonSixClicked()));
	connect(sevenButton, SIGNAL(clicked()), this, SLOT(buttonSevenClicked()));
	connect(eightButton, SIGNAL(clicked()), this, SLOT(buttonEightClicked()));
	connect(nineButton, SIGNAL(clicked()), this, SLOT(buttonNineClicked()));
	//加减乘除
	connect(addButton, SIGNAL(clicked()), this, SLOT(buttonAddClicked()));
	connect(subButton, SIGNAL(clicked()), this, SLOT(buttonSubClicked()));
	connect(mulButton, SIGNAL(clicked()), this, SLOT(buttonMulClicked()));
	connect(divButton, SIGNAL(clicked()), this, SLOT(buttonDivClicked()));
	connect(decButton, SIGNAL(clicked(bool)), this, SLOT(buttonDecClicked()));//点号
	connect(lefButton, SIGNAL(clicked(bool)), this, SLOT(buttonLefClicked()));//左括号
	connect(rigButton, SIGNAL(clicked(bool)), this, SLOT(buttonRigClicked()));//右括号
	connect(CEButton, SIGNAL(clicked()), this, SLOT(buttonCEClicked())); //清除一个字符
	connect(ACButton, SIGNAL(clicked()), this, SLOT(buttonACClicked()));//全部清除
	connect(equButton, SIGNAL(clicked()), this, SLOT(buttonEquClicked())); //等于号*/
}
void calculate::buttonZeroClicked()  //以下是实现相应的槽函数
{
	if (input == "0")
		input = '0';
	else input = input + '0';
	inputLine->setText(input);
}
void calculate::buttonOneClicked()
{
	if (input == "0")
		input = '1';
	else input = input + '1';
	inputLine->setText(input);
}
void calculate::buttonTwoClicked(){
	if (input == "0")
		input = '2';
	else input = input + '2';
	inputLine->setText(input);
}
void calculate::buttonThreeClicked()
{
	if (input == "0")
		input = '3';
	else input = input + '3';
	inputLine->setText(input);
}
void calculate::buttonFourClicked()
{
	if (input == "0")
		input = '4';
	else input = input + '4';
	inputLine->setText(input);
}
void calculate::buttonFiveClicked()
{
	if (input == "0")
		input = '5';
	else input = input + '5';
	inputLine->setText(input);
}
void calculate::buttonSixClicked()
{
	if (input == "0")
		input = '6';
	else input = input + '6';
	inputLine->setText(input);
}
void calculate::buttonSevenClicked(){
	if (input == "0")
		input = '7';
	else input = input + '7';
	inputLine->setText(input);
}
void calculate::buttonEightClicked(){
	if (input == "0")
		input = '8';
	else input = input + '8';
	inputLine->setText(input);
}
void calculate::buttonNineClicked(){
	if (input == "0")
		input = '9';
	else input = input + '9';
	inputLine->setText(input);
}
void calculate::buttonAddClicked(){
	if (input == "0")
		input = '+';
	else input = input + '+';
	inputLine->setText(input);
}
void calculate::buttonSubClicked(){
	if (input == "0")
		input = '-';
	else input = input + '-';
	inputLine->setText(input);
}
void calculate::buttonMulClicked(){
	if (input == "0")
		input = '*';
	else input = input + '*';
	inputLine->setText(input);
}
void calculate::buttonDivClicked(){
	if (input == "0")
		input = '/';
	else input = input + '/';
	inputLine->setText(input);
}
void calculate::buttonDecClicked() //小数点
{
	if (input == "0")
		input = '.';
	else input = input + '.';
	inputLine->setText(input);
}void calculate::buttonLefClicked()//左括号
{
	if (input == "0")
		input = '(';
	else input = input + '(';
	inputLine->setText(input);
}
void calculate::buttonRigClicked()//右括号
{
	if (input == "0")
		input = ')';
	else input = input + ')';
	inputLine->setText(input);
}
void calculate::buttonCEClicked(){
	input = input.left(input.length() - 1);
	//减去一字符
	inputLine->setText(input);
}
void calculate::buttonACClicked() //直接清空
{
	input = '0';
	inputLine->setText(input);
}
void calculate::buttonEquClicked()//等于号 ，输入等于号后开始运算，相当于原来的main
{
	std::string str = input.toStdString();
	const char *S = str.c_str();
	//QStack<double> Data;
	//QStack<char> Symb;
	double result;
	QString change;
	result = allocate(S); //数和运算符分类
	change = QString::number(result, 10, 6);
	//gcvt(result,10,change);
	input = input + "=" + change;
	inputLine->setText(input);
}
double allocate(const char *num){
	QStack<double> Data;
	QStack<char> Symb;
	char   tnsarr[30] = "0";//存放数字字符的临时字符串数组
	int    tnsarr_i = 0;//存放数字字符的临时字符串数组的的下标
	int  i = 0;
	while (i<strlen(num))    {
		char c = num[i];
		if ((c >= '0'&&c <= '9') || c == '.')//c是数字，放入tnsarr
		{
			tnsarr[tnsarr_i] = num[i];//分离出单个数字，字符串形式保存
			tnsarr_i++;//临时数组中字符数量
		}
		else//c不是数字
		{
			if (c != '('&&num[i - 1] != ')')//c不是左括号，且c之前不是右括号,防止转化两次，多出零
			{
				Data.push(atof(tnsarr));//数字存入数据栈
				tnsarr_i = 0;//分离数字重新计数
				memset(tnsarr, '\0', sizeof(tnsarr));//清空临时数组
			}
			Symb = check(c, &Data, Symb);//c 是运算符，进行运算符分类处理
		}

		i++;
	}
	if (num[i - 1] >= '0'&&num[i - 1] <= '9'&&num[i] == '\0')//解决最后一个数字无法录入问题
	{
		Data.push(atof(tnsarr));//数字存入数据栈
	}
	if (i == strlen(num))//字符已经遍历到最后
	{
		while (!Symb.empty())//计算符栈不是空的,说明栈顶向下运算符优先级递减。这应该是个循环的过程，保证计算所有的数
		{
			Symb = calcu(&Data, Symb);//取出Data栈顶向下两个数据，和Symb中栈顶运算符计算
		}

	}    return Data.top();
}
//c不是数字，进行运算符分类处理
QStack<char> check(char c, QStack<double>* Data, QStack<char> Symb)
//void check(char c,QStack<double>& Data,QStack<char>& Symb)
{
	if (Symb.empty())//运算符栈为空
	{
		Symb.push(c);
		return Symb;

	}    if (c == '(')//c是左括号，直接放入运算栈
	{
		Symb.push(c);
	}
	else if (c == ')')//c是右括号，则进行运算
	{
		if (Symb.top() == '(')
		{
			Symb.pop();
		}
		else
		{
			Symb = calcu(Data, Symb);//取出Data栈顶向下两个数据，和Symb中栈顶运算符计算
			Symb = check(c, Data, Symb);//重新代入检测程序
		}
	}
	else//c不是括号
	{
		char sym = Symb.top();
		if (sym == '(')//当前栈顶运算sym符为‘（’
		{
			Symb.push(c);
		}
		else//当前栈顶运算符sym不是‘（’，不会是）括号，有括号不会存入Symb中
		{
			if (getPri(c) <= getPri(sym))//c的优先级小于等于Symb栈顶运算符sym
			{
				Symb = calcu(Data, Symb);//取出Data栈顶向下两个数据，和Symb中栈顶运算符计算
				Symb = check(c, Data, Symb);//Symb 栈顶下移后，重新比较c和栈顶运算符
			}
			else//c的优先级大于当前运算符栈栈顶运算符sym
			{
				Symb.push(c);// 运算符c压入Sym栈顶
			}
		}
	}    return Symb;
}//获得符号的优先性
int getPri(char c){
	switch (c)
	{
	case '+':
		return 0;    //如果是加减，返回0
	case '-': return 0;  //如果是加减，返回0
	case '*': return 1;   //如果是乘除，返回1
	case '/': return 1;  //如果是乘除，返回1
	default: break;
	}
}
//计算Data栈顶两个元素
QStack<char> calcu(QStack<double>* Data, QStack<char> Symb)
//void calcu(QStack<double>& Data,QStack<char>& Symb)
{
	float op1 = 0, op2 = 0;
	if (!Symb.empty())//非空
	{
		char c = Symb.pop();//取出运算符栈顶的运算符放入c//栈顶向下移一位
		//取出数据栈栈顶元素和栈顶下一位，栈顶向下两位
		op1 = Data->pop();
		op2 = Data->pop();
		//Data->top--;
		switch (c)
		{
		case'+':Data->push(op2 + op1); break;
		case'-':Data->push(op2 - op1); break;
		case'*':Data->push(op2*op1); break;
		case'/':Data->push(op2 / op1); break;
		}
	}
	return Symb;
}
calculate::~calculate(){
}
