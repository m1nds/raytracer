#include <objects/world.hpp>
#include <objects/hittable.hpp>
#include <geometry/ray.hpp>

#include <memory>

World::World() {}

void World::add(std::unique_ptr<Hittable> object) {
    this->_objects.push_back(std::move(object));
}

void World::clear() {
    this->_objects.clear();
}

bool World::hit_objects(const Ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) {
    HitRecord temp_rec;
    bool hit_anything = false;
    auto closest_so_far = ray_tmax;

    for (const auto& object : this->_objects) {
        if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}
