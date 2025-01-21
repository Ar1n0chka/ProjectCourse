#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize2.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    // Путь к исходному изображению
    const char* inputImagePath = "input.jpg";
    const char* outputImagePath = "output.jpg";

    // Загружаем изображение
    int width, height, channels;
    unsigned char* image = stbi_load(inputImagePath, &width, &height, &channels, 0);
    int a;
    std::cout<<"Введите коэффициент уменьшения: ";
    std::cin>>a;
    int newWidth = width/a;
    int newHeight = height/a;
    unsigned char* resizedImage = new unsigned char[newWidth * newHeight * channels];

    stbir_pixel_layout layouts = stbir_pixel_layout(channels);
    stbir_resize_uint8_srgb(image, width, height, 0, resizedImage, newWidth, newHeight, 0, layouts);
    stbi_write_jpg(outputImagePath, newWidth, newHeight, channels, resizedImage, newWidth * channels);
}