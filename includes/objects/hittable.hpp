#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

class HitRecord {
  public:
    Vector3 p;
    Vector3 normal;
    double t;
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const = 0;
};


#endif
