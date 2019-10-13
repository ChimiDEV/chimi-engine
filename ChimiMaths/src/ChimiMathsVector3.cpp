#include <cmath>
#include "ChimiMathsVector3.hpp"

namespace ChimiEngine
{
// Constructors
ChimiVector3::ChimiVector3() : x(0.0), y(0.0), z(0.0){};
ChimiVector3::ChimiVector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ){};

// Destructor
ChimiVector3::~ChimiVector3() {}

// Copy constructor
ChimiVector3::ChimiVector3(const ChimiVector3 &v) : x(v.x), y(v.y), z(v.z){};
ChimiVector3 &ChimiVector3::operator=(const ChimiVector3 &v)
{
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
};

// Vector addition
void ChimiVector3::operator+=(const ChimiVector3 &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
};

ChimiVector3 ChimiVector3::operator+(const ChimiVector3 &v) const
{
  return ChimiVector3(x + v.x, y + v.y, z + v.z);
};

// Vector Substraction
void ChimiVector3::operator-=(const ChimiVector3 &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
};

ChimiVector3 ChimiVector3::operator-(const ChimiVector3 &v) const
{
  return ChimiVector3(x - v.x, y - v.y, z - v.z);
};

// Saclar Multiplication and Division
void ChimiVector3::operator*=(const float s)
{
  x *= s;
  y *= s;
  z *= s;
}

void ChimiVector3::operator/=(const float s)
{
  x = x / s;
  y = y / s;
  z = z / s;
}

ChimiVector3 ChimiVector3::operator*(const float s) const
{
  return ChimiVector3(x * s, y * s, z * s);
}

ChimiVector3 ChimiVector3::operator/(const float s) const
{
  return ChimiVector3(x / s, y / s, z / s);
}

// Dot product

float ChimiVector3::operator*(const ChimiVector3 &v) const
{
  return x * v.x + y * v.y + z * v.z;
}

float ChimiVector3::dot(const ChimiVector3 &v) const
{
  return x * v.x + y * v.y + z * v.z;
}

// Cross product
ChimiVector3 helperCrossProduct(const ChimiVector3 &a, const ChimiVector3 &b)
{
  /*
  * result.x = (a.y * b.z) - (a.z * b.y)
  * result.y = (a.z * b.x) - (a.x * b.z)
  * result.z = (a.x * b.y) - (a.y * b.x)
  */
  return ChimiVector3(
      a.y * b.z - a.z * b.y,
      a.z * b.x - a.x * b.z,
      a.x * b.y - a.y * b.x);
};

ChimiVector3 ChimiVector3::cross(const ChimiVector3 &v) const
{
  return helperCrossProduct(*this, v);
};

ChimiVector3 ChimiVector3::operator%(const ChimiVector3 &v) const
{
  return helperCrossProduct(*this, v);
};

void ChimiVector3::operator%=(const ChimiVector3 &v)
{
  *this = cross(v);
};

// Length (or Magnitude) of vector
float helperMagnitude(const ChimiVector3 &v)
{
  return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float ChimiVector3::length()
{
  return helperMagnitude(*this);
};

float ChimiVector3::magnitude()
{
  return helperMagnitude(*this);
};

// Normalized Vector
ChimiVector3 ChimiVector3::normalize() const
{
  float length = helperMagnitude(*this);
  if (length <= 0.0f)
  {
    throw "Division by zero";
  }

  float norm = 1.0f / length;
  return ChimiVector3(
      x * norm,
      y * norm,
      z * norm);
};
} // namespace ChimiEngine