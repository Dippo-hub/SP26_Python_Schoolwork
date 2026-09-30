#include <iostream>

class Rectangle {
    private:
        double width, height;
    public:
        Rectangle() {
            this->width = 1;
            this->height = 1;
        }

        Rectangle(double height, double width) {
            this->width = width;
            this->height = height;
        }

        void setWidth(double width) {
            this->width = width;
        }

        void setHeight(double height) {
            this->height = height;
        }

        void getDims() {
            std::cout << "Width: " << width << " Height: " << height << std::endl;
        }

        double getArea() {
            return width*height;
        }

        double getPerim() {
            return 2*width + 2*height;
        }
};

int main(void) {

    Rectangle J;
    Rectangle K(3, 4);

    K.getDims();
    std::cout << K.getArea() << " " << K.getPerim() << std::endl;

}