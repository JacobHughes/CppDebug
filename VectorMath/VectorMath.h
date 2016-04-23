/*=======================================================
	Code written by Jacob Hughes

	jacob.solomon.hughes@gmail.com
	https://github.com/JacobHughes/
=======================================================*/

#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

#include <cmath>




namespace VectorMath
{
	class Vector3D
	{
		/*=======================================================
			This class is used to represent a 3 dimensional 
			vector, with associated useful member methods, 
			operators
		=======================================================*/
	public:
		Vector3D() : x(0.0), y(0.0), z(0.0) {};
		
		//Initialise with values
		Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
		
		//Initialise with another Vector3D
		Vector3D(const Vector3D& vec) : x(vec.x), y(vec.y), z(vec.z) {}

		//Vector components
		double x, y, z;

		//Get the vector length
		double getLength() { return std::sqrt(x*x + y*y + z*z); }

	};

	const bool operator== (const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	const bool operator!= (const Vector3D& lhs, const Vector3D& rhs)
	{
		return !operator==(lhs, rhs);
	}

	//Multiplication by a scalar
	const Vector3D operator*(const double & scalar, Vector3D vec)
	{
		return Vector3D(scalar*vec.x, scalar*vec.y, scalar*vec.z);
	}

	const Vector3D operator+=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	}

	const Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) 
	{
		return Vector3D (lhs) += rhs;
	}

	const Vector3D operator-=(Vector3D& lhs, const Vector3D& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	}

	const Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D (lhs) -= rhs;
	}

	//Dot product of Lhs and rhs: LHS DOT RHS
	const double dotProduct(const Vector3D& lhs, const Vector3D &rhs)
	{
		return ((lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z));
	}

	//Cross producto of lhs and rhs: LHS CROSS RHS
	Vector3D crossProduct(const Vector3D& lhs, const Vector3D &rhs)
	{
		return Vector3D(lhs.y*rhs.z - lhs.z*rhs.y,
			lhs.z*rhs.x - lhs.x*rhs.z,
			lhs.x*rhs.y - lhs.y*rhs.x);
	}

	//Get the normalised Vector3D
	const Vector3D normaliseVector3D(Vector3D& vec)
	{
		return Vector3D(vec.x / vec.getLength(), vec.y / vec.getLength(), vec.z / vec.getLength());
	}

	//Rotate a Vector3D an angle around the X axis
	const Vector3D rotateAroundX(const Vector3D& vec, const double& angle)
	{
		double angleInRad = angle * M_PI / 180.0;
		return Vector3D(vec.x,
						std::cos(angleInRad)*vec.y + -std::sin(angleInRad)*vec.z,
						std::sin(angleInRad)*vec.y +  std::cos(angleInRad)*vec.z);
	}

	//Rotate a Vector3D an angle around the Y axis
	const Vector3D rotateAroundY(const Vector3D& vec, const double& angle)
	{
		double angleInRad = angle * M_PI / 180.0;
		return Vector3D(std::cos(angleInRad)*vec.x + std::sin(angleInRad)*vec.z,
						vec.y,
						-std::sin(angleInRad)*vec.x + std::cos(angleInRad)*vec.z);
	}

	//Rotate a Vector3D an angle around the Z axis
	const Vector3D rotateAroundZ(const Vector3D& vec, const double& angle)
	{
		double angleInRad = angle * M_PI / 180.0;
		return Vector3D(std::cos(angleInRad)*vec.x + -std::sin(angleInRad)*vec.y,
						std::sin(angleInRad)*vec.x + std::cos(angleInRad)*vec.y,
						vec.z);
	}

	
	class Vector2D
	{
		/*=======================================================
			This class is used to represent a 2 dimensional
			vector, with associated useful member methods,
			operators
		=======================================================*/
	public:

		Vector2D() : x(0.0), y(0.0) {}
		Vector2D(double x_, double y_) : x(x_), y(y_) {}
		//~Vector2D();

		//Component vector values
		double x, y;

		//Initialise with another Vector3D
		Vector2D(const Vector2D& vec) : x(vec.x), y(vec.y) {}

		//Get the vector length
		double getLength() { return std::sqrt(x*x + y*y); }
	};

	const bool operator== (const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	const bool operator!= (const Vector2D& lhs, const Vector2D& rhs)
	{
		return !operator==(lhs, rhs);
	}

	//Multiplication by a scalar
	const Vector2D operator*(const double & scalar, Vector2D vec)
	{
		return Vector2D(scalar*vec.x, scalar*vec.y);
	}

	const Vector2D operator+=(Vector2D& lhs, const Vector2D& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}

	const Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs) += rhs;
	}

	const Vector2D operator-=(Vector2D& lhs, const Vector2D& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}

	const Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs) -= rhs;
	}

	//Dot product of Lhs and rhs: LHS DOT RHS
	const double dotProduct(const Vector2D& lhs, const Vector2D &rhs)
	{
		return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
	}

	//Get the normalised Vector2D
	const Vector2D normaliseVector2D(Vector2D& vec)
	{
		return Vector2D(vec.x / vec.getLength(), vec.y / vec.getLength());
	}

}