#pragma once
class Material
{
private:
	float r_a;
	float r_d;
	float r_s;
public:
	Material(float r_a, float r_d, float r_s);
	float getR_a();
	float getR_d();
	float getR_s();
	void setR_a(float r_a);
	void setR_d(float r_d);
	void setR_s(float r_s);
};

