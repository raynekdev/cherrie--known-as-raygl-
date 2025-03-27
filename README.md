# The Repo of Ray's Graphic Library

## RayGL RC3 (Intel GPU Only)
this raygl version (latest version) is only for intel gpu's

raygl is a graphics API designed for minimalistic games and applications. the rc3 doesnt have the support for raytracing and more. you can easily create a game
 
## Code Example
```cpp
#include "raygl.h"

int main() {
    if (!RayGL_Init(800, 600, "Moja Prvá RayGL Hra")) {
        RayGL_Log("Nepodarilo sa inicializovať RayGL.");
        return 1;
    }

    while (RayGL_IsRunning()) {
        RayGL_PollEvents();

        RayGL_Clear(0, 0, 0);

        // Hráčov štvorec
        RayGL_DrawRect(100, 100, 50, 50, 255, 0, 0);

        // Myš ako kruh
        int mx = RayGL_GetMouseX();
        int my = RayGL_GetMouseY();
        RayGL_DrawCircle(mx, my, 10, 0, 255, 0);

        RayGL_Present();
        RayGL_Sleep(16); // ~60 FPS
    }

    RayGL_Shutdown();
