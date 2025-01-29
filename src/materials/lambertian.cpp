#include <materials/lambertian.hpp>
#include <geometry/vector.hpp>
#include <geometry/ray.hpp>
#include <objects/hittable.hpp>
#include <utils/constants.hpp>

Lambertian::Lambertian(const Vector3& albedo) : _albedo(albedo) {}

bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {
    auto scatter_direction = rec.normal + random_unit_vector();
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }

    scattered = Ray(rec.p, scatter_direction);
    attenuation = this->_albedo;
    return true;

}
