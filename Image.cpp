#include "Image.h"

#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "stb_image_write.h"

#include <iostream>

namespace csci3081 {

Image::Image() : width(0), height(0), channels(0), img(nullptr) {
}

Image::Image(const std::string& filename) {
	unsigned char *data = stbi_load(filename.c_str(), &width, &height, &channels, STBI_rgb_alpha);
    channels = 4;

	img = new unsigned char[width*height*channels];
	std::copy(data, data + width*height*channels, img);
	stbi_image_free(data);
}

Image::Image(int width, int height) : width(width), height(height), channels(4) {
    img = new unsigned char[width*height*channels];
}

Image::Image(const Image& img){

}

Image::~Image() {
    // delete[] img;
    stbi_image_free(img);
    stbi_image_free(buttonImg);
}

Image& Image::operator=(const Image& img) {
}


int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

Color Image::getPixel(int x, int y) const {
    unsigned char* img = &img[(x + width*y)*channels];
    return Color(img[0], img[1], img[2], img[3]);
}

void Image::setPixel(int x, int y, const Color& color) {
    unsigned char* img = &img[(x + width*y)*channels];
    img[0] = color[0];
    img[1] = color[1];
    img[2] = color[2];
    img[3] = color[3];
}

void Image::saveAs(const std::string& filename) const {
    stbi_write_png(filename.c_str(), width, height, channels, img, width*channels);
}

void Image::load_image(const std::string& fileName, int& width, int& height, int& channels){
    unsigned char *img = stbi_load(fileName.c_str(), &width, &height, &channels, 4);
    channels = 4;
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    return img;
}

}