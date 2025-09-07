#pragma once

class C3DObject {
protected:
	float A, B, C;

public:
	C3DObject(const float bigRadius, const float smallRadius, const float constZ) :
		A(bigRadius), B(smallRadius), C(constZ)
	{};

	float getRadii() const noexcept { return A; }

	virtual void PrintCoordsAndDerivative(const float) const = 0;
	virtual ~C3DObject() {};
};
