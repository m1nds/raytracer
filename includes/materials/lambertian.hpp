#ifndef LAMBERTIAN_HPP
#define LAMBERTIAN_HPP

#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

#include <objects/hittable.hpp>

#include <materials/material.hpp>

class Lambertian : public Material {
    public:
        Lambertian(const Vector3& albdeo);
        bool scatter(const Ray& r_in, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const override;
    private:
        Vector3 _albedo;
};

#endif
