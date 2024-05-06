#include "brightener.h"

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage): m_inputImage(inputImage) {
    if (inputImage == nullptr)
    {
        std::cout << "Invalid input image provided to ImageBrightener" << std::endl;
    }
}

bool ImageBrightener::BrightenWholeImage(int& attenuatedPixelCount) const {

    m_inputImage->pixelRunner([&attenuatedPixelCount](uint8_t pixelGrayscale, int x, int y) {
        uint8_t outputGrayscale = pixelGrayscale;
        if (outputGrayscale > (255 - 25)) {
            ++attenuatedPixelCount;
            outputGrayscale = 255;
        }
        else {
            outputGrayscale += 25;
        }

        return outputGrayscale;
        });
    return true;
}

bool ImageBrightener::AddBrighteningImage(const std::shared_ptr<const Image> imageToAdd, int& attenuatedPixelCount) const {
    if (imageToAdd->m_rows != m_inputImage->m_rows || imageToAdd->m_columns != m_inputImage->m_columns) {
        return false;
    }

    m_inputImage->pixelRunner([imageToAdd , &attenuatedPixelCount](uint8_t pixelGrayscale, int x, int y) {
        uint8_t outputGrayscale = pixelGrayscale;
        int pixelIndex = x * imageToAdd->m_columns + y;
        if ((outputGrayscale + imageToAdd->m_pixels[pixelIndex]) > 255) {
            ++attenuatedPixelCount;
            outputGrayscale = 255;
        }
        else {
            outputGrayscale += imageToAdd->m_pixels[pixelIndex];
        }

        return outputGrayscale;
        });
    return true;
}
