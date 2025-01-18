#include <utils/camera.hpp>
#include <utils/color.hpp>
#include <utils/constants.hpp>

#include <objects/world.hpp>
#include <geometry/ray.hpp>
#include <geometry/vector.hpp>

Camera::Camera() : Camera::Camera(100, 1.0) {}

Camera::Camera(int width, double aspect_ratio) {

    this->_width = width;
    this->_aspect_ratio = aspect_ratio;

    this->_height = int(this->_width / this->_aspect_ratio);
    this->_height = (this->_height < 1) ? 1 : this->_height;

    this->_center = Vector3(0, 0, 0);

    // Determine viewport dimensions.
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(this->_width) / this->_height);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = Vector3(viewport_width, 0, 0);
    auto viewport_v = Vector3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    this->_pixel_delta_u = viewport_u / this->_width;
    this->_pixel_delta_v = viewport_v / this->_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left =
        this->_center - Vector3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;

    this->_pixel00_loc = viewport_upper_left + 0.5 * (this->_pixel_delta_u + this->_pixel_delta_v);
}

Vector3 Camera::pixel_pos(int i, int j) {
    return this->_pixel00_loc + (i * this->_pixel_delta_u) + (j * this->_pixel_delta_v);
}

Point3 Camera::ray_color(const Ray& r, const World& world) const {
    HitRecord rec;

    if (world.hit_objects(r, Interval(0, INF), rec)) {
        return 0.5 * (rec.normal + Vector3(1,1,1));
    }

    Vector3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);

    return (1.0-a)*Vector3(1.0, 1.0, 1.0) + a*Vector3(0.5, 0.7, 1.0);
}

void Camera::render(const World& world) {
        std::cout << "P3\n" << this->_width << ' ' << this->_height << "\n255\n";

        for (int j = 0; j < this->_height; j++) {
            std::clog << "\rScanlines remaining: " << (this->_height - j) << ' ' << std::flush;
            for (int i = 0; i < this->_width; i++) {
                auto pixel_center = this->pixel_pos(i, j);
                auto ray_direction = pixel_center - this->_center;

                Ray r(this->_center, ray_direction);

                Point3 pixel_color = ray_color(r, world);
                write_color(std::cout, pixel_color);
            }
        }

        std::clog << "\rDone.                 \n";
    }
