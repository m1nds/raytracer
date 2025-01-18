#include <objects/sphere.hpp>
#include <objects/world.hpp>

#include <utils/camera.hpp>

#include <memory>

int main() {
    World world;

    world.add(std::make_unique<Sphere>(Vector3(0,0,-1), 0.5));
    world.add(std::make_unique<Sphere>(Vector3(0,-100.5,-1), 100));

    Camera cam = Camera(400, (16.0 / 9.0));
    cam.render(world);
}
