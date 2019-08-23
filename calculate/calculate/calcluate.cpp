#include "calculate.h"
//QStack<double> Data;
//QStack<char> Symb;
double allocate(const char *S); //�������������
QStack<char> check(char c, QStack<double>* Data, QStack<char> Symb);//��������ദ��
int  getPri(char c); //�������ȼ�
QStack<char> calcu(QStack<double>* Data, QStack<char> Symb);//����ջ��Ԫ��
calculate::calculate(QWidget *parent) : QMainWindow(parent)
{
	QWidget *widget = new QWidget; //����һ��QWidget���ֽ����õĲ�����ӽ����QWidget
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
	QGridLayout *H = new QGridLayout(this); //������һ�����񲼾�
	inputLine->setFixedHeight(50); //������һ�п�ȴ�С
	CEButton->setFixedHeight(50);
	ACButton->setFixedHeight(50);
	H->addWidget(inputLine, 0, 0, 1, 3);  //�ڣ�0��0��λ������һ�����е�����
	H->setRowStretch(0, 100);//�����п�
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
	widget->setLayout(H); //��������ʾ����
	//��������
	connect(zeroButton, SIGNAL(clicked()), this, SLOT(buttonZeroClicked()));//�ź���ۺ���
	connect(oneButton, SIGNAL(clicked()), this, SLOT(buttonOneClicked()));
	connect(twoButton, SIGNAL(clicked()), this, SLOT(buttonTwoClicked()));
	connect(threeButton, SIGNAL(clicked()), this, SLOT(buttonThreeClicked()));
	connect(fourButton, SIGNAL(clicked()), this, SLOT(buttonFourClicked()));
	connect(fiveButton, SIGNAL(clicked()), this, SLOT(buttonFiveClicked()));
	connect(sixButton, SIGNAL(clicked()), this, SLOT(buttonSixClicked()));
	connect(sevenButton, SIGNAL(clicked()), this, SLOT(buttonSevenClicked()));
	connect(eightButton, SIGNAL(clicked()), this, SLOT(buttonEightClicked()));
	connect(nineButton, SIGNAL(clicked()), this, SLOT(buttonNineClicked()));
	//�Ӽ��˳�
	connect(addButton, SIGNAL(clicked()), this, SLOT(buttonAddClicked()));
	connect(subButton, SIGNAL(clicked()), this, SLOT(buttonSubClicked()));
	connect(mulButton, SIGNAL(clicked()), this, SLOT(buttonMulClicked()));
	connect(divButton, SIGNAL(clicked()), this, SLOT(buttonDivClicked()));
	connect(decButton, SIGNAL(clicked(bool)), this, SLOT(buttonDecClicked()));//���
	connect(lefButton, SIGNAL(clicked(bool)), this, SLOT(buttonLefClicked()));//������
	connect(rigButton, SIGNAL(clicked(bool)), this, SLOT(buttonRigClicked()));//������
	connect(CEButton, SIGNAL(clicked()), this, SLOT(buttonCEClicked())); //���һ���ַ�
	connect(ACButton, SIGNAL(clicked()), this, SLOT(buttonACClicked()));//ȫ�����
	connect(equButton, SIGNAL(clicked()), this, SLOT(buttonEquClicked())); //���ں�*/
}
void calculate::buttonZeroClicked()  //������ʵ����Ӧ�Ĳۺ���
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
void calculate::buttonDecClicked() //С����
{
	if (input == "0")
		input = '.';
	else input = input + '.';
	inputLine->setText(input);
}void calculate::buttonLefClicked()//������
{
	if (input == "0")
		input = '(';
	else input = input + '(';
	inputLine->setText(input);
}
void calculate::buttonRigClicked()//������
{
	if (input == "0")
		input = ')';
	else input = input + ')';
	inputLine->setText(input);
}
void calculate::buttonCEClicked(){
	input = input.left(input.length() - 1);
	//��ȥһ�ַ�
	inputLine->setText(input);
}
void calculate::buttonACClicked() //ֱ�����
{
	input = '0';
	inputLine->setText(input);
}
void calculate::buttonEquClicked()//���ں� ��������ںź�ʼ���㣬�൱��ԭ����main
{
	std::string str = input.toStdString();
	const char *S = str.c_str();
	//QStack<double> Data;
	//QStack<char> Symb;
	double result;
	QString change;
	result = allocate(S); //�������������
	change = QString::number(result, 10, 6);
	//gcvt(result,10,change);
	input = input + "=" + change;
	inputLine->setText(input);
}
double allocate(const char *num){
	QStack<double> Data;
	QStack<char> Symb;
	char   tnsarr[30] = "0";//��������ַ�����ʱ�ַ�������
	int    tnsarr_i = 0;//��������ַ�����ʱ�ַ�������ĵ��±�
	int  i = 0;
	while (i<strlen(num))    {
		char c = num[i];
		if ((c >= '0'&&c <= '9') || c == '.')//c�����֣�����tnsarr
		{
			tnsarr[tnsarr_i] = num[i];//������������֣��ַ�����ʽ����
			tnsarr_i++;//��ʱ�������ַ�����
		}
		else//c��������
		{
			if (c != '('&&num[i - 1] != ')')//c���������ţ���c֮ǰ����������,��ֹת�����Σ������
			{
				Data.push(atof(tnsarr));//���ִ�������ջ
				tnsarr_i = 0;//�����������¼���
				memset(tnsarr, '\0', sizeof(tnsarr));//�����ʱ����
			}
			Symb = check(c, &Data, Symb);//c ���������������������ദ��
		}

		i++;
	}
	if (num[i - 1] >= '0'&&num[i - 1] <= '9'&&num[i] == '\0')//������һ�������޷�¼������
	{
		Data.push(atof(tnsarr));//���ִ�������ջ
	}
	if (i == strlen(num))//�ַ��Ѿ����������
	{
		while (!Symb.empty())//�����ջ���ǿյ�,˵��ջ��������������ȼ��ݼ�����Ӧ���Ǹ�ѭ���Ĺ��̣���֤�������е���
		{
			Symb = calcu(&Data, Symb);//ȡ��Dataջ�������������ݣ���Symb��ջ�����������
		}

	}    return Data.top();
}
//c�������֣�������������ദ��
QStack<char> check(char c, QStack<double>* Data, QStack<char> Symb)
//void check(char c,QStack<double>& Data,QStack<char>& Symb)
{
	if (Symb.empty())//�����ջΪ��
	{
		Symb.push(c);
		return Symb;

	}    if (c == '(')//c�������ţ�ֱ�ӷ�������ջ
	{
		Symb.push(c);
	}
	else if (c == ')')//c�������ţ����������
	{
		if (Symb.top() == '(')
		{
			Symb.pop();
		}
		else
		{
			Symb = calcu(Data, Symb);//ȡ��Dataջ�������������ݣ���Symb��ջ�����������
			Symb = check(c, Data, Symb);//���´��������
		}
	}
	else//c��������
	{
		char sym = Symb.top();
		if (sym == '(')//��ǰջ������sym��Ϊ������
		{
			Symb.push(c);
		}
		else//��ǰջ�������sym���ǡ������������ǣ����ţ������Ų������Symb��
		{
			if (getPri(c) <= getPri(sym))//c�����ȼ�С�ڵ���Symbջ�������sym
			{
				Symb = calcu(Data, Symb);//ȡ��Dataջ�������������ݣ���Symb��ջ�����������
				Symb = check(c, Data, Symb);//Symb ջ�����ƺ����±Ƚ�c��ջ�������
			}
			else//c�����ȼ����ڵ�ǰ�����ջջ�������sym
			{
				Symb.push(c);// �����cѹ��Symջ��
			}
		}
	}    return Symb;
}//��÷��ŵ�������
int getPri(char c){
	switch (c)
	{
	case '+':
		return 0;    //����ǼӼ�������0
	case '-': return 0;  //����ǼӼ�������0
	case '*': return 1;   //����ǳ˳�������1
	case '/': return 1;  //����ǳ˳�������1
	default: break;
	}
}
//����Dataջ������Ԫ��
QStack<char> calcu(QStack<double>* Data, QStack<char> Symb)
//void calcu(QStack<double>& Data,QStack<char>& Symb)
{
	float op1 = 0, op2 = 0;
	if (!Symb.empty())//�ǿ�
	{
		char c = Symb.pop();//ȡ�������ջ�������������c//ջ��������һλ
		//ȡ������ջջ��Ԫ�غ�ջ����һλ��ջ��������λ
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
