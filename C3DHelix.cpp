#include "C3DHelix.h"

#include <iostream>

void C3DHelix::PrintCoordsAndDerivative(const float t) const {
	std::cout << "\n3D_Helix point: " << '('
		<< A * std::cos(t) << "; "
		<< B * std::sin(t) << "; "
		<< C * t << ")\n";
	std::cout << "3D_Helix first derivative: \n" << '('
		<< "x' = " << -A * std::sin(t) << ";\n"
		<< "y' = " << B * std::cos(t) << ";\n"
		<< "z' = " << C << ")\n\n";
};
