#define CATCH_CONFIG_MAIN
#include "catch.h"

#include "ChimiMathsVector3.hpp"

// https://noobtuts.com/cpp/compare-float-values
bool cmpf(float A, float B, float epsilon = 0.005f)
{
  return (fabs(A - B) < epsilon);
}

TEST_CASE("ChimiMaths: 3D-Vector", "[ChimiMaths]")
{
  SECTION("Vector Operation: Addition")
  {
    ChimiEngine::ChimiVector3 v1(1, 1, 1);
    ChimiEngine::ChimiVector3 v2(2, 1, 3);

    ChimiEngine::ChimiVector3 res = v1 + v2;

    REQUIRE(res.x == 3);
    REQUIRE(res.y == 2);
    REQUIRE(res.z == 4);

    ChimiEngine::ChimiVector3 v3;
    v3 += v2;

    REQUIRE(v3.x == 2);
    REQUIRE(v3.y == 1);
    REQUIRE(v3.z == 3);
  }

  SECTION("Vector Operation: Subtraction")
  {
    ChimiEngine::ChimiVector3 v1(1, 1, 1);
    ChimiEngine::ChimiVector3 v2(2, 1, 3);

    ChimiEngine::ChimiVector3 res = v1 - v2;

    REQUIRE(res.x == -1);
    REQUIRE(res.y == 0);
    REQUIRE(res.z == -2);

    ChimiEngine::ChimiVector3 v3;
    v3 -= v2;

    REQUIRE(v3.x == -2);
    REQUIRE(v3.y == -1);
    REQUIRE(v3.z == -3);
  }

  SECTION("Vector Operation: Scalar Multiplication")
  {
    ChimiEngine::ChimiVector3 v1(1, 2, 3);

    ChimiEngine::ChimiVector3 res = v1 * 2;

    REQUIRE(res.x == 2);
    REQUIRE(res.y == 4);
    REQUIRE(res.z == 6);

    ChimiEngine::ChimiVector3 v2(3, 4, 5);
    v2 *= 5;

    REQUIRE(v2.x == 15);
    REQUIRE(v2.y == 20);
    REQUIRE(v2.z == 25);
  }

  SECTION("Vector Operation: Scalar Division")
  {
    ChimiEngine::ChimiVector3 v1(1, 2, 3);

    ChimiEngine::ChimiVector3 res = v1 / 2;

    REQUIRE(res.x == .5);
    REQUIRE(res.y == 1);
    REQUIRE(res.z == 1.5);

    ChimiEngine::ChimiVector3 v2(15, 20, 25);
    v2 /= 5;

    REQUIRE(v2.x == 3);
    REQUIRE(v2.y == 4);
    REQUIRE(v2.z == 5);
  }

  SECTION("Vector Operation: Dot Product")
  {
    ChimiEngine::ChimiVector3 v1(1, 1, 1);
    ChimiEngine::ChimiVector3 v2(2, 1, 3);

    float resOperator = v1 * v2;
    REQUIRE(resOperator == 6);

    float resMethod = v1.dot(v2);
    REQUIRE(resMethod == 6);
  }

  SECTION("Vector Operation: Cross Product")
  {
    ChimiEngine::ChimiVector3 v1(1, 1, 1);
    ChimiEngine::ChimiVector3 v2(2, 1, 3);

    ChimiEngine::ChimiVector3 resOperator = v1 % v2;
    ChimiEngine::ChimiVector3 resMethod = v1.cross(v2);
    REQUIRE(resOperator.x == 2);
    REQUIRE(resOperator.y == -1);
    REQUIRE(resOperator.z == -1);

    REQUIRE(resMethod.x == 2);
    REQUIRE(resMethod.y == -1);
    REQUIRE(resMethod.z == -1);

    v1 %= v2;

    REQUIRE(v1.x == 2);
    REQUIRE(v1.y == -1);
    REQUIRE(v1.z == -1);
  }

  SECTION("Vector Operation: Length (Magnitude)")
  {
    ChimiEngine::ChimiVector3 v1(2, 2, 1);
    ChimiEngine::ChimiVector3 v2(5, 5, 5);

    float resLength = v1.length();
    float resMagnitude = v2.magnitude();

    REQUIRE(resLength == 3);
    REQUIRE(cmpf(resMagnitude, std::sqrt(25 + 25 + 25)));
  }

  SECTION("Vector Operation: Normalize")
  {

    ChimiEngine::ChimiVector3 v1(0, 0, 0);
    ChimiEngine::ChimiVector3 v2(2, 2, 2);

    ChimiEngine::ChimiVector3 normalied = v2.normalize();

    REQUIRE(cmpf(v2.x, 0.577350259));
    REQUIRE(cmpf(v2.y, 0.577350259));
    REQUIRE(cmpf(v2.z, 0.577350259));

    REQUIRE_THROWS_WITH(v1.normalize(), "Division by zero");
    // try
    // {
    //   ChimiEngine::ChimiVector3 v2 = v1.normalize();
    // }
    // catch (const char *msg)
    // {
    //   std::cout << msg << std::endl;
    // }
  }
}
