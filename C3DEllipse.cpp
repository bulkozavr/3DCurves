#include "C3DEllipse.h"

#include <iostream>

void C3DEllipse::PrintCoordsAndDerivative(float t) const {
	std::cout << "\n3D_Ellipse point: " << '('
		<< A * std::cos(t) << "; "
		<< B * std::sin(t) << "; "
		<< C << ")\n";
	std::cout << "3D_Ellipse first derivative: \n" << '('
		<< "x' = " << -A * std::sin(t) << ";\n"
		<< "y' = " << B * std::cos(t) << ";\n"
		<< "z' = " << C << ")\n\n";
};
