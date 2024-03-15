//inherihtance 

#include <iostream>

class Rectangle{
    // protected: //only my children
    private: //only my children

    int length;
    int width;
    public:
    void setData(int l, int w){
        length = l;
        width = w;
    }
    void show()
    {
        std::cout<<"\nDimensions are "<<length<<" x "<<width;
    }
    void computeArea(){
        std::cout<<"\nArea = "<<length*width;
    }
};
class Block: public Rectangle{
private:
int height;
public:
void setData(int l, int w, int h)
{
    // length = l;
    // width = w;
    Rectangle::setData(l,w); //way no.2
    height = h;
}
void show(){
    Rectangle::show();
    std::cout<<" x "<<height;
}



};

int main(){
    Rectangle square;
    square.setData(10,10);
    square.computeArea();
    square.show();

    Block cube;
    cube.setData(10,10,10);
    cube.show();

    return 0;
}