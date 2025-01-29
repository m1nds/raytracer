#ifndef SPHERE_H
#define SPHERE_H

#include <utils/interval.hpp>

#include <objects/hittable.hpp>
#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

#include <materials/material.hpp>

class Sphere: public Hittable {
  public:
    Sphere(const Vector3& center, double radius, std::shared_ptr<Material> material);
    bool hit(const Ray& r, Interval in, HitRecord& rec) const override;

  private:
    Vector3 _center;
    double _radius;
};

#endif
