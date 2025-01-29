#include <objects/sphere.hpp>
#include <objects/world.hpp>

#include <geometry/vector.hpp>

#include <utils/camera.hpp>

#include <materials/lambertian.hpp>
#include <materials/metal.hpp>

#include <memory>

int main() {
    World world;

    auto material_ground = std::make_shared<Lambertian>(Vector3(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<Lambertian>(Vector3(0.1, 0.2, 0.5));
    auto material_left = std::make_shared<Metal>(Vector3(0.8, 0.8, 0.8));
    auto material_right = std::make_shared<Metal>(Vector3(0.8, 0.6, 0.2));

    world.add(std::make_unique<Sphere>(Vector3(0, -100.5, -1.0), 100, material_ground));
    world.add(std::make_unique<Sphere>(Vector3(0, 0, -1.2), 0.5, material_center));
    world.add(std::make_unique<Sphere>(Vector3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(std::make_unique<Sphere>(Vector3(1.0, 0.0, -1.0), 0.5, material_right));

    Camera cam = Camera(400, (16.0 / 9.0), 100, 50);
    cam.render(world);
}
