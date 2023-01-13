#include <iostream>
using namespace std;

class EquilateralTriangle {
    private:
        float a;
        float circumference;
        float area;
    public: 
        void setA(float length){
            a = length;
            circumference = a * 3;
            area = (1.72 * a * a) / 4;
        }

        friend void PrintResult(EquilateralTriangle);
};

void PrintResult(EquilateralTriangle et){
    cout << "Circumference = " << et.circumference << endl;
    cout << "Area = " << et.area << endl;
}

int main(){
    EquilateralTriangle triangle;
    triangle.setA(5);

    triangle.PrintResult(triangle);
}