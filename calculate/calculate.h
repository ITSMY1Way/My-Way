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
    QLineEdit *inputLine;//显示框
    QString input = "0"; //输入框
    //0-9：十个按钮
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
    //运算符8个，两个功能键
    QPushButton *addButton;// '+'
    QPushButton *subButton;// '-'
    QPushButton *mulButton;// '*'
    QPushButton *divButton;// '/ '
    QPushButton *equButton;// '='
    QPushButton *decButton;// '.'
    QPushButton *lefButton;// '('
    QPushButton *rigButton;// ')'
    QPushButton *CEButton; //清除一个字符
    QPushButton *ACButton; //全部清除
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
    void buttonEquClicked();//等于号
    void buttonDecClicked();//小数点
    void buttonLefClicked();//左括号
    void buttonRigClicked();//右括号
    void buttonCEClicked();//CE
    void buttonACClicked();//AC
};
#endif // CALCULATE_H
