#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <omp.h>

struct Vec3 {
    float x, y, z;
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
};

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vec3 operator*(float s, const Vec3& v) {
    return Vec3(s * v.x, s * v.y, s * v.z);
}

struct Ray {
    Vec3 origin, direction;
    Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {}
};

struct Sphere {
    Vec3 center;
    float radius;
    Sphere(const Vec3& center, float radius) : center(center), radius(radius) {}
    bool intersect(const Ray& ray, float& t) const {
        Vec3 oc = ray.origin - center;
        float a = dot(ray.direction, ray.direction);
        float b = 2.0 * dot(oc, ray.direction);
        float c = dot(oc, oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0) return false;
        float sqrt_discriminant = sqrt(discriminant);
        float t0 = (-b - sqrt_discriminant) / (2.0 * a);
        float t1 = (-b + sqrt_discriminant) / (2.0 * a);
        if (t0 > t1) std::swap(t0, t1);
        if (t0 < 0) {
            t0 = t1;
            if (t0 < 0) return false;
        }
        t = t0;
        return true;
    }
private:
    float dot(const Vec3& a, const Vec3& b) const {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
};

Vec3 trace(const Ray& ray, const std::vector<Sphere>& spheres) {
    float t;
    const Sphere* sphere = nullptr;
    for (const Sphere& s : spheres) {
        float t_sphere;
        if (s.intersect(ray, t_sphere)) {
            if (t_sphere < t || !sphere) {
                t = t_sphere;
                sphere = &s;
            }
        }
    }
    if (!sphere) return Vec3(0.2, 0.7, 0.8); // Background color
    return Vec3(0.4, 0.4, 0.3); // Sphere color
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <width> <height>\n";
        return 1;
    }

    int width = std::atoi(argv[1]);
    int height = std::atoi(argv[2]);

    std::vector<Sphere> spheres;
    spheres.push_back(Sphere(Vec3(0, 0, -3), 1));
    spheres.push_back(Sphere(Vec3(2, 0, -4), 1));

    std::vector<Vec3> image(width * height);

#pragma omp parallel for collapse(2) schedule(dynamic)
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            float u = float(i) / width;
            float v = float(j) / height;
            Ray ray(Vec3(0, 0, 0), Vec3(2 * u - 1, 2 * v - 1, -1));
            image[j * width + i] = trace(ray, spheres);
        }
    }

    // Output image data (for simplicity, just printing)
    // for (int j = 0; j < height; ++j) {
    //     for (int i = 0; i < width; ++i) {
    //         std::cout << "(" << image[j * width + i].x << ", " << image[j * width + i].y << ", " << image[j * width + i].z << ") ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
