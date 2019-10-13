namespace ChimiEngine
{
class ChimiVector3
{
private:
public:
  float x;
  float y;
  float z;

  // Constructors
  ChimiVector3();
  ChimiVector3(float fX, float fY, float fZ);

  // Destructors
  ~ChimiVector3();

  // Copy Constructors
  ChimiVector3(const ChimiVector3 &v);
  ChimiVector3 &operator=(const ChimiVector3 &v);

  // Vector addition
  void operator+=(const ChimiVector3 &v);
  ChimiVector3 operator+(const ChimiVector3 &v) const;

  // Vector Substraction
  void operator-=(const ChimiVector3 &v);
  ChimiVector3 operator-(const ChimiVector3 &v) const;

  // Saclar Multiplication and Divison
  void operator*=(const float s);
  void operator/=(const float s);
  ChimiVector3 operator*(const float s) const;
  ChimiVector3 operator/(const float s) const;

  // Dot Product
  float operator*(const ChimiVector3 &v) const;
  float dot(const ChimiVector3 &v) const;

  // Cross Product
  ChimiVector3 cross(const ChimiVector3 &v) const;
  ChimiVector3 operator%(const ChimiVector3 &v) const;
  void operator%=(const ChimiVector3 &v);

  // Length (or Magnitude) of vector
  float length();
  float magnitude();

  // Normalize Vector
  ChimiVector3 normalize() const;
};
} // namespace ChimiEngine