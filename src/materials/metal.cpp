#include <materials/metal.hpp>
#include <geometry/vector.hpp>
#include <geometry/ray.hpp>
#include <objects/hittable.hpp>
#include <utils/constants.hpp>

Metal::Metal(const Vector3& albedo, double fuzz) : _albedo(albedo), _fuzz(fuzz < 1 ? fuzz : 1) {}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {
    auto reflected = reflect(r_in.direction(), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = this->_albedo;
    return true;
}
