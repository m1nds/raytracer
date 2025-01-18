#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry/ray.hpp>
#include <objects/world.hpp>
#include <utils/point.hpp>

class Camera {
    public:
        Camera();
        Camera(int width, double aspect_ratio, int samples_per_pixel);
        void render(const World& world);

    private:
        Vector3 ray_color(const Ray& r, const World& world) const;
        Ray current_ray(int i, int j) const;
        Vector3 sample_square() const;

        double _aspect_ratio = 1.0;
        int    _width  = 100;
        int    _height  = 100;
        int    _samples_per_pixel;

        Vector3 _center;
        Vector3 _pixel00_loc;
        Vector3 _pixel_delta_u;
        Vector3 _pixel_delta_v;
};

#endif
