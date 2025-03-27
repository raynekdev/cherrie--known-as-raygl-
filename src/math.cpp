#include "raygl_math.h"
#include <cmath>

Vec2 RayGL_Vec2(float x, float y) { return {x, y}; }
Vec3 RayGL_Vec3(float x, float y, float z) { return {x, y, z}; }

Mat4 RayGL_Identity() {
    Mat4 m = {};
    for (int i = 0; i < 4; ++i) m.m[i][i] = 1.0f;
    return m;
}

Mat4 RayGL_Translate(Vec3 v) {
    Mat4 m = RayGL_Identity();
    m.m[0][3] = v.x;
    m.m[1][3] = v.y;
    m.m[2][3] = v.z;
    return m;
}

Mat4 RayGL_RotateY(float angle) {
    Mat4 m = RayGL_Identity();
    float c = cosf(angle), s = sinf(angle);
    m.m[0][0] = c; m.m[0][2] = s;
    m.m[2][0] = -s; m.m[2][2] = c;
    return m;
}

float RayGL_Dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 RayGL_Cross(Vec3 a, Vec3 b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

Vec3 RayGL_Normalize(Vec3 v) {
    float len = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (len == 0.0f) return {0,0,0};
    return {v.x/len, v.y/len, v.z/len};
}

Mat4 RayGL_Perspective(float fov, float aspect, float znear, float zfar) {
    Mat4 m = {};
    float tanHalfFov = tanf(fov / 2.0f);
    m.m[0][0] = 1.0f / (aspect * tanHalfFov);
    m.m[1][1] = 1.0f / tanHalfFov;
    m.m[2][2] = -(zfar + znear) / (zfar - znear);
    m.m[2][3] = -(2.0f * zfar * znear) / (zfar - znear);
    m.m[3][2] = -1.0f;
    return m;
}
