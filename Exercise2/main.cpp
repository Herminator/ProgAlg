#include <string>

int imageProcessing(int argc, const char* argv[]);
void summation();

int main(int argc, const char* argv[]) {
    const char * image[3];
    std::string loadImage = "../Tests/image.PNG";
    std::string saveImage = "../Tests/result.PNG";

    image[1] = loadImage.c_str();
    image[2] = saveImage.c_str();

	imageProcessing(3, image);
	summation();
}