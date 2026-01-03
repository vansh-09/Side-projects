#include<stdio.h>
#include "raylib.h"

#define FPS 120
#define WIDTH 900
#define HEIGHT 600
#define THICKNESS 5
#define MASS_WIDTH 100

#define FLOOR_Y (HEIGHT*0.6)

#define NUM_SPRING_ELEMENT 10
#define SPRING_ELEM_LENGTH 300
float x_mass;

void drawSpring(){
    float x_springdelta  = x_mass / NUM_SPRING_ELEMENT;
    for(int i=0; i<NUM_SPRING_ELEMENT; i++){
        Vector2 start = {x_springdelta * i , FLOOR_Y - MASS_WIDTH/2};


        float y_end = sqrt(pow(SPRING_ELEM_LENGTH, 2) - pow(x_springdelta , 2));
        Vector2 end = {start.x + x_springdelta ,y_end};
        DrawLineEx(start, end, THICKNESS, BLUE);
    }
}

void drawFloor(){   
    Vector2 start = {0  ,FLOOR_Y};
    Vector2 end = {WIDTH, FLOOR_Y}; 
    DrawLineEx(start, end,THICKNESS, GRAY);
}

void drawMass(){
    Rectangle rect = {x_mass, FLOOR_Y - MASS_WIDTH-THICKNESS/2, MASS_WIDTH, MASS_WIDTH};
    DrawRectangleRec(rect, RED );
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Spring on Mass Simulator");

    float x = 0;
    float v= 20;
    float dt;
    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
            dt = GetFrameTime();
            drawFloor();
            x_mass += v * dt;
            drawMass();
            drawSpring();
            DrawText("Spring on mass go brrrrr", WIDTH/10, 100, 30, GREEN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}