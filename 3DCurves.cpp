#include <iostream>
#include <random>
#include <chrono>
#include <list>
#include <vector>
#include <algorithm>
#include <ranges>

#include "C3DCurve_Circle.h"
#include "C3DCurve_Ellipse.h"
#include "C3DCurve_Helix.h"

bool compareByRadii(const float& fRadii, const float& sRadii) {
	return fRadii < sRadii;
}

float circleToRadii(const std::shared_ptr<C3DObject>& circle) {
	// We know that the curvesCircles vector contains only 
	// std::shared_ptr<C3DCircle> objects, so use static_cast.
	return (std::static_pointer_cast<C3DCircle>(circle))->getRadii();
}

int main()
{
	std::vector<std::unique_ptr<C3DCurve>> curveCreators;
	curveCreators.push_back(std::move(std::make_unique<C3DCurve_Circle>()));
	curveCreators.push_back(std::move(std::make_unique<C3DCurve_Ellipse>()));
	curveCreators.push_back(std::move(std::make_unique<C3DCurve_Helix>()));

	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 engine(seed);
	std::uniform_int_distribution<int> range_distribution(0, 2);
	std::list<std::shared_ptr<C3DObject>> curves;

	int curvesEmount = 5;
	for (auto i = 0; i != curvesEmount; ++i)
		curves.push_back(curveCreators[range_distribution(engine)]->factoryMethod());

	for (const auto& curve : curves) {
		curve->PrintCoordsAndDerivative(3.14f / 4);
	}

	std::vector<std::shared_ptr<C3DObject>> curvesCircles;
	// Reserve some place to avoid reallocation.
	// Assume that circles are half of all curves amount.
	curvesCircles.reserve(curves.size() / 2);

	std::copy_if(curves.begin(), curves.end(), std::back_inserter(curvesCircles),
		[](const std::shared_ptr<C3DObject> p) -> bool
	{
		// Use dynamic_pointer_cast to test whether
		// element is a std::shared_ptr<C3DCircle>.
		std::shared_ptr<C3DCircle> temp = std::dynamic_pointer_cast<C3DCircle>(p);
		return temp.get() != nullptr;
	});

	curvesCircles.shrink_to_fit();

	std::cout << "Before sorting:\n";
	for (const auto& curve : curvesCircles) {
		curve->PrintCoordsAndDerivative(3.14f / 4);
	}

	if (curvesCircles.size() > 0)
		std::ranges::sort(curvesCircles, compareByRadii, circleToRadii);

	std::cout << "\nAfter sorting:\n";
	for (const auto& curve : curvesCircles) {
		curve->PrintCoordsAndDerivative(3.14f / 4);
	}

	float radiiSum = 0.f;
	for (const auto& curve : curvesCircles) {
		radiiSum += curve->getRadii();
	}

	std::cout << "Sum: " << radiiSum;
}
