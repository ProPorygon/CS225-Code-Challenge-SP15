#include "png.h"
#include "rgbapixel.h"
#include <vector>

using namespace std;

int main() {
PNG image("static.png");
PNG image2("image.png");
PNG out(image.width(), image.height());
//Just comment out whichever part you don't need
//Part 1: Outputs hidden message from pixel series in the image
RGBAPixel* current = out(image.width()-1,image.height()-1);
while(true) {
    cout << current->red;
    current = out(current->green, current->blue);
    if (current->red == 0)
        break;
}
cout << endl;
//Part 2: Adds new image to original 17 times to get the final image
for(size_t i = 0; i < image.width(); i++) {
    for(size_t j = 0; j < image.height(); j++) {
        out(i,j)->red = image2(i,j)->red + 17* image(i,j)->red;
        out(i,j)->blue = image2(i,j)->blue + 17* image(i,j)->blue;
        out(i,j)->green = image2(i,j)->green + 17*image(i,j)->green;
    }
}
out.writeToFile("out.png");
return 0;
}
