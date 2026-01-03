#include<stdio.h>
#include<math.h>

#include "raylib.h"

#define FPS 120
#define WIDTH 900
#define HEIGHT 600
#define THICKNESS 5
#define MASS_WIDTH 100

#define FLOOR_Y (HEIGHT*0.6)

#define NUM_SPRING_ELEMENT 16
#define SPRING_ELEM_LENGTH 60
float x_mass;

void drawSpring(){
    float x_springdelta  = x_mass / NUM_SPRING_ELEMENT;
    for(int i=0; i<NUM_SPRING_ELEMENT; i+=2){
        float y_end = sqrt(pow(SPRING_ELEM_LENGTH, 2) - pow(x_springdelta , 2));
        Vector2 start = {x_springdelta * i , FLOOR_Y - MASS_WIDTH/2+SPRING_ELEM_LENGTH/2};
        Vector2 end = {start.x + x_springdelta ,start.y-y_end};
        DrawLineEx(start, end, THICKNESS/2, GRAY);

        
    }

    for(int i=1; i<NUM_SPRING_ELEMENT; i+=2){
        float y_end = sqrt(pow(SPRING_ELEM_LENGTH, 2) - pow(x_springdelta , 2));
        Vector2 start = {x_springdelta * i , FLOOR_Y - MASS_WIDTH/2-SPRING_ELEM_LENGTH/2};
        Vector2 end = {start.x + x_springdelta ,start.y+y_end};
        DrawLineEx(start, end, THICKNESS/2, LIGHTGRAY);

        
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
    float v= 40;
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