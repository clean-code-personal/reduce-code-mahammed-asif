#include <iostream>
#include "brightener.h"

int main() {
	auto image = std::make_shared<Image>(512, 512);
	std::cout << "Brightening a 512 x 512 image\n";

	if (image->imageSizeIsValid()) {

		ImageBrightener brightener(image);
		int attenuatedCount = 0;
		brightener.BrightenWholeImage(attenuatedCount);
		std::cout << "Attenuated " << attenuatedCount << " pixels\n";
	}
	else {
		std::cout << "Not a valid image... did nothing\n";
		return 1;
	}

	
}
