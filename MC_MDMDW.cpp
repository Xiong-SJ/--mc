/*
author:XiongSJ
time : 25 - 7 - 25
aim;以四个点计算交点
*/

#include <iostream>

using namespace std;

 //用于记录一个坐标
 struct coor {
     double x;
     double y;
     coor(double x, double y):
         x(x),y(y){ }
 };

// 用于计录一个两个坐标
struct function_coor {
    double x1, x2, y1, y2;
    function_coor(double x_1, double y_1, double x_2, double y_2):
        x1(x_1),x2(x_2),y1(y_1),y2(y_2){}
};

coor f(const function_coor &funn);    // 计算出一次函数
coor count_f(const function_coor &f1, const function_coor &f2);    // 计算出两个函数的交点


static int run() {
    double x1, x2, y1, y2;

    cout << "*********************" << endl;
    cout << "请输入两个坐标" << endl;
    cout << "例如；\n" << "1 2\n7 8\n" << ">>>";
    cin >> x1 >> y1;
    cout << ">>>";
    cin >> x2 >> y2;
    struct function_coor funn1(x1, y1, x2, y2);


    cout << "请输入另外两个坐标\n" << endl << ">>>";
    cin >> x1 >> y1;
    cout << ">>>";
    cin >> x2 >> y2;
    struct function_coor funn2(x1, y1, x2, y2);

    struct coor coor1 = count_f(funn1, funn2);

    cout << "\n\n交点坐标为：(" << (int)coor1.x << "," << (int)coor1.y << ")";

    return 0;
}


int main() {
    while (true) {
        try {
            run();

            char ans =' ';
            cout << "\n是否继续(y or n)->";
            cin >> ans;
            if (ans == 'n') {
                break;
            }
        }
        catch (...) {
            cout << "\a发生异常请重试。。。" << endl;
        }
    }
    return 0;
}




coor f(const function_coor& funn) {
    double k, b;
    
    k = (funn.y1 - funn.y2) / (funn.x1 - funn.x2);
    b = funn.y1 - k * funn.x1;

    struct coor co(k, b);   //把斜率和截距视为坐标
    return co;  //C++无法同时返回俩变量所以用结构体代替
}

coor count_f(const function_coor& f1, const function_coor& f2) {
    double x, y;
    struct coor co1 = f(f1);
    struct coor co2 = f(f2);

    x = (co2.y - co1.y) / (co1.x - co2.x);
    y = co1.x * x + co1.y;

    struct coor co(x, y);
    return co;
}
