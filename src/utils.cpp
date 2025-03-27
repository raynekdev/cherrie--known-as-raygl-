#include "raygl.h"
#include <windows.h>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono;

static auto start_time = steady_clock::now();

double RayGL_GetTime() {
    auto now = steady_clock::now();
    return duration_cast<duration<double>>(now - start_time).count();
}

void RayGL_Sleep(int ms) {
    std::this_thread::sleep_for(milliseconds(ms));
}

void RayGL_Log(const char* msg) {
    std::cout << "[RayGL] " << msg << std::endl;
}

void RayGL_SetFPSLimit(int fps) {
    // TODO: integrate with loop
}

void RayGL_ShowPerformanceOverlay(bool show) {
    // TODO
}
