#pragma once
#include <stdint.h>
#include "raygl_math.h" // obsahuje Vec2, Vec3, Mat4

#ifdef __cplusplus
extern "C" {
#endif

// 🎮 Inicializácia a základ
bool RayGL_Init(int width, int height, const char* title);
void RayGL_Shutdown();
void RayGL_RunMainLoop();
bool RayGL_IsRunning();
void RayGL_Quit();
void RayGL_SetTitle(const char* title);

// 🖱️ Vstup
void RayGL_PollEvents();
bool RayGL_KeyDown(int keycode);
bool RayGL_KeyPressed(int keycode);
bool RayGL_KeyReleased(int keycode);
bool RayGL_MouseDown(int button);
int  RayGL_GetMouseX();
int  RayGL_GetMouseY();
void RayGL_SetCursorVisible(bool visible);
bool RayGL_KeyCombo(const char* combo);
int  RayGL_GetScrollDelta();

// 🎨 2D grafika
void RayGL_Clear(int r, int g, int b);
void RayGL_SetPixel(int x, int y, int r, int g, int b);
void RayGL_DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b);
void RayGL_DrawRect(int x, int y, int w, int h, int r, int g, int b);
void RayGL_DrawCircle(int x, int y, int radius, int r, int g, int b);
void RayGL_DrawEllipse(); // TODO
void RayGL_DrawTriangle(); // TODO
void RayGL_FillRect(); // TODO
void RayGL_FillCircle(); // TODO
void RayGL_Present();

// 🧱 3D grafika
void RayGL_SetPerspective();
void RayGL_SetCamera();
void RayGL_BeginMesh();
void RayGL_AddVertex();
void RayGL_EndMesh();
void RayGL_RenderMesh();
void RayGL_LoadModel();
void RayGL_SetLighting();
void RayGL_SetShader();
void RayGL_EnableZBuffer(bool enable);
void RayGL_ClearZBuffer();
void RayGL_SetFog();
void RayGL_SetCulling();
void RayGL_RenderSkybox();
void RayGL_SetWireframe(bool enabled);

// 🌄 Textúry a obrázky
int  RayGL_LoadTexture(const char* path);
void RayGL_FreeTexture(int texID);
void RayGL_DrawTexture(int texID, int x, int y);
void RayGL_DrawTextureEx();
void RayGL_SetTextureFilter();
void RayGL_SetTextureWrap();
int  RayGL_GetTextureWidth(int texID);
int  RayGL_GetTextureHeight(int texID);
bool RayGL_SaveScreenshot(const char* path);

// ✏️ Text a fonty
int RayGL_LoadFont(const char* path, int size);
void RayGL_DrawText(int fontID, int x, int y, const char* text, int r, int g, int b);
int RayGL_TextWidth();
int RayGL_TextHeight();
void RayGL_UnloadFont();

// ☄️ Ray tracing
void RayGL_EnableRayTracing(bool enabled);
void RayGL_AddRaySphere();
void RayGL_AddRayPlane();
void RayGL_RenderRayScene();
void RayGL_ClearRayScene();

// 🧮 Matematika
Vec2 RayGL_Vec2(float x, float y);
Vec3 RayGL_Vec3(float x, float y, float z);
Mat4 RayGL_Identity();
Mat4 RayGL_Translate(Vec3 v);
Mat4 RayGL_RotateY(float angle);
Mat4 RayGL_Perspective(float fov, float aspect, float znear, float zfar);
float RayGL_Dot(Vec3 a, Vec3 b);
Vec3 RayGL_Cross(Vec3 a, Vec3 b);
Vec3 RayGL_Normalize(Vec3 v);

// ⏱️ Utility
double RayGL_GetTime();
void RayGL_Sleep(int ms);
void RayGL_Log(const char* msg);
void RayGL_SetFPSLimit(int fps);
void RayGL_ShowPerformanceOverlay(bool show);

// 🔍 Intel GPU detekcia
bool RayGL_CheckIntelGPU();

#ifdef __cplusplus
}
#endif
