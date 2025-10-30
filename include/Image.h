#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>
#include "Color.h"

namespace csci3081 {

class Image {
public:
    Image();
    Image(const std::string& filename);
    Image(int width, int height);

    Image(const Image& img);

    ~Image();
    
    void saveAs(const std::string& filename) const;
    int getWidth() const;
    int getHeight() const;
    Color getPixel(int x, int y) const;
    void setPixel(int x, int y, const Color& color);
    const unsigned char* getData() const { return pixels; }
    void operator=(const Image& image);

private:
    int width, height, channels;
    unsigned char* pixels;
};

}

#endif // IMAGE_H_
