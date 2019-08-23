#ifndef CALCULATE_H
#define CALCULATE_H
#include <QMainWindow>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QString>
#include<QStack>
#include<QTime>
//extern QStack<double>Data;
//extern QStack<char>Symb;
class calculate : public QMainWindow{
	Q_OBJECT

public:
	calculate(QWidget *parent = 0);
	~calculate();
	// static QStack<double>Data;
	// static QStack<char>Symb;
private:
	QLineEdit *inputLine;//��ʾ��
	QString input = "0"; //�����
	//0-9��ʮ����ť
	QPushButton *zeroButton;
	QPushButton *oneButton;
	QPushButton *twoButton;
	QPushButton *threeButton;
	QPushButton *fourButton;
	QPushButton *fiveButton;
	QPushButton *sixButton;
	QPushButton *sevenButton;
	QPushButton *eightButton;
	QPushButton *nineButton;
	//�����8�����������ܼ�
	QPushButton *addButton;// '+'
	QPushButton *subButton;// '-'
	QPushButton *mulButton;// '*'
	QPushButton *divButton;// '/ '
	QPushButton *equButton;// '='
	QPushButton *decButton;// '.'
	QPushButton *lefButton;// '('
	QPushButton *rigButton;// ')'
	QPushButton *CEButton; //���һ���ַ�
	QPushButton *ACButton; //ȫ�����
	private slots:
	void buttonZeroClicked();
	void buttonOneClicked();
	void buttonTwoClicked();
	void buttonThreeClicked();
	void buttonFourClicked();
	void buttonFiveClicked();
	void buttonSixClicked();
	void buttonSevenClicked();
	void buttonEightClicked();
	void buttonNineClicked();
	void buttonAddClicked();// +
	void buttonSubClicked();// -
	void buttonMulClicked();// *
	void buttonDivClicked();// /
	void buttonEquClicked();//���ں�
	void buttonDecClicked();//С����
	void buttonLefClicked();//������
	void buttonRigClicked();//������
	void buttonCEClicked();//CE
	void buttonACClicked();//AC
};
#endif // CALCULATE_H
