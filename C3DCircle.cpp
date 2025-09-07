#include "C3DCircle.h"

#include <iostream>

void C3DCircle::PrintCoordsAndDerivative(const float t) const {
	std::cout << "\n3D_Circle point: " << '('
		<< A * std::cos(t) << "; "
		<< A * std::sin(t) << "; "
		<< C << ")\n";
	std::cout << "3D_Circle first derivative: \n" << '('
		<< "x' = " << -A * std::sin(t) << ";\n"
		<< "y' = " << A * std::cos(t) << ";\n"
		<< "z' = " << C << ")\n\n";
};
