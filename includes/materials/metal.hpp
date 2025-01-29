#ifndef METAL_HPP
#define METAL_HPP

#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

#include <objects/hittable.hpp>

#include <materials/material.hpp>

class Metal : public Material {
    public:
        Metal(const Vector3& albdeo, double fuzz);
        bool scatter(const Ray& r_in, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const override;
    private:
        Vector3 _albedo;
        double _fuzz;
};

#endif
