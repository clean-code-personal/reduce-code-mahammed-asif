#include <cstdint>
#include "image.h"

class ImageBrightener {
    private:
        std::shared_ptr<Image> m_inputImage;
    public:
        ImageBrightener(std::shared_ptr<Image> inputImage);

        bool BrightenWholeImage(int& attenuatedPixelCount) const;
        bool AddBrighteningImage(const std::shared_ptr<const Image> imageToAdd, int& attenuatedCount) const;
};
