#ifndef SPHERE_H
#define SPHERE_H

#include <objects/hittable.hpp>
#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

class Sphere: public Hittable {
  public:
    Sphere(const Vector3& center, double radius);
    bool hit(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override;

  private:
    Vector3 _center;
    double _radius;
};

#endif
