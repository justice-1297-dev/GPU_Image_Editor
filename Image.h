#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include "Color.h"
#include "Application.h"

namespace csci3081 {

class Image {
public:
    // constructors
    Image();
    Image(const std::string& filename);
    Image(int width, int height);

    // copy constructor
    Image(const Image& img);

    // Destructor
    ~Image();

    //assignement operator
    Image& operator=(const Image& img); 

    // methods
    void saveAs(const std::string& filename) const;
    int getWidth() const;
    int getHeight() const;
    Color getPixel(int x, int y) const;
    void setPixel(int x, int y, const Color& color);
    const unsigned char* getData() { return img; }

private:
    // int width;
    // int height;
    // int components;
    // unsigned char* pixels;
    
    int width, height, channels;
    unsigned char *img = load_image("img_small.jpeg", width, height, channels);
    app.imgWidth = width;
    app.imgHeight = height;
    app.img = img;
};

}

#endif // IMAGE_H_
