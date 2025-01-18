#ifndef WORLD_HPP
#define WORLD_HPP

#include <objects/hittable.hpp>
#include <geometry/ray.hpp>

#include <memory>
#include <vector>

class World {
    public:
        World();
        void add(std::unique_ptr<Hittable> object);
        void clear();
        bool hit_objects(const Ray& r, Interval in, HitRecord& rec) const;

    private:
        std::vector<std::unique_ptr<Hittable>> _objects;
};

#endif
