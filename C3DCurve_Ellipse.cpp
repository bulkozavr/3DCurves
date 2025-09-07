#include "C3DCurve_Ellipse.h"
#include <random>

std::unique_ptr<C3DObject> C3DCurve_Ellipse::factoryMethod() {
	std::default_random_engine generator(std::random_device{}());
	std::uniform_real_distribution<float> distribution(1.0f, 10.0f);
	return std::make_unique<C3DEllipse>(distribution(generator), distribution(generator));
};
