#ifndef CONSTANTS_HH_
#define CONSTANTS_HH_

#include <cmath>

namespace gmes
{
  // physical constants

  // the ratio of the circumference of a circle to its diameter
  const double pi = 4 * atan(1);

  // speed of light in vacuum
  const double c0 = 299792458; // in Meter/Second

  // Vacuum permeability
  const double mu0 = 4 * pi * 1e-7; // in Henry/Meter

  // Vacuum permittivity
  const double eps0 = 1 / (c0 * c0 * mu0); // in Farad/Meter

  // vacuum impedance
  const double Z0 = sqrt(mu0 / eps0);

  // decimal factors
  const double PETA = 1e15;
  const double TERA = 1e12;
  const double GIGA = 1e9;
  const double MEGA = 1e6;
  const double KILO = 1e3;
  const double MILLI = 1e-3;
  const double MICRO = 1e-6;
  const double NANO = 1e-9;
  const double PICO = 1e-12;
  const double FEMTO = 1e-15;
  const double ATTO = 1e-18;

  class Component
  {
  public:
    Component();
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 0;
  };

  class Electric: public Component
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 1;
  };

  class Ex: public Electric
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 3;
  };

  class Ey: public Electric
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 4;
  };

  class Ez: public Electric
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 5;
  };

  class Magnetic: public Component
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 2;
  };

  class Hx: public Magnetic
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 6;
  };

  class Hy: public Magnetic
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 7;
  };

  class Hz: public Magnetic
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 8;
  };

  class Directional
  {
  public:
    Directional();
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 10;
  };

  class X: public Directional
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 11;
  };

  class Y: public Directional
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 12;
  };

  class Z: public Directional
  {
  public:
    static int get_tag()
    {
      return tag;
    }
  private:
    static const int tag = 13;
  };

  class PlusX: public X
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 14;
  };

  class MinusX: public X
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 15;
  };

  class PlusY: public Y
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 16;
  };

  class MinusY: public Y
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 17;
  };

  class PlusZ: public Z
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 18;
  };

  class MinusZ: public Z
  {
  public:
    static int get_tag()
    {
      return tag;
    }
    static void get_vector(double vector[3]);
  private:
    static const double vector[];
    static const int tag = 19;
  };

}

#endif /*CONSTANTS_HH_*/
