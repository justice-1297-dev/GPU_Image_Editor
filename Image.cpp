#include "Image.h"

#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

namespace csci3081 {

Image::Image() : width(0), height(0), channels(0), pixels(nullptr) {
}

Image::Image(const std::string& filename) {
	unsigned char *data = stbi_load(filename.c_str(), &width, &height, &channels, STBI_rgb_alpha);
    channels = 4;

	pixels = new unsigned char[width*height*channels];
	std::copy(data, data + width*height*channels, pixels);
	stbi_image_free(data);
}

Image::Image(int width, int height) : width(width), height(height), channels(4) {
    pixels = new unsigned char[width*height*channels];
}

Image::Image(const Image& img){
    this->width = img.width;
    this->height = img.height;
    this->channels = img.channels;
    this->pixels = new unsigned char[width * height * channels];
    std::copy(img.pixels, img.pixels + width * height * channels, pixels);
}

Image::~Image() {
    // delete[] img;
    // stbi_image_free(img);
    delete[] pixels;
    // stbi_image_free(buttonImg);
}

void Image::operator=(const Image& image) {
    this->width = image.width;
    this->height = image.height;
    this->components = image.components;
    delete[] this->pixels;
    this->pixels = new unsigned char[width*height*components];
	std::copy(image.pixels, image.pixels + width*height*components, pixels);
}



int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

Color Image::getPixel(int x, int y) const {
    const unsigned char* p = &pixels[(x + width*y)*channels];
    return Color(p[0], p[1], p[2], p[3]);
}

void Image::setPixel(int x, int y, const Color& color) {
    unsigned char* p = &pixels[(x + width*y)*channels];
    p[0] = color[0];
    p[1] = color[1];
    p[2] = color[2];
    p[3] = color[3];
}

void Image::saveAs(const std::string& filename) const {
    stbi_write_png(filename.c_str(), width, height, channels, pixels, width*channels);
}


void Image::operator=(const Image& image) {
    this->width = image.width;
    this->height = image.height;
    this->channels = image.channels;
    delete[] this->pixels;
    this->pixels = new unsigned char[width*height*channels];
	std::copy(image.pixels, image.pixels + width*height*channels, pixels);
}

}