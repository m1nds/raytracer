#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry/ray.hpp>
#include <objects/world.hpp>
#include <utils/point.hpp>

class Camera {
    public:
        Camera();
        Camera(int width, double aspect_ratio);
        void render(const World& world);
        Vector3 pixel_pos(int i, int j);

    private:
        Point3 ray_color(const Ray& r, const World& world) const;

        double _aspect_ratio = 1.0;
        int    _width  = 100;
        int    _height  = 100;

        Vector3 _center;
        Vector3 _pixel00_loc;
        Vector3 _pixel_delta_u;
        Vector3 _pixel_delta_v;
};

#endif
