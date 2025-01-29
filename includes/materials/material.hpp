#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <geometry/vector.hpp>
#include <geometry/ray.hpp>

#include <objects/hittable.hpp>

class HitRecord;

class Material {
    public:
        virtual ~Material() = default;
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {
            return false;
        }
};

#endif
