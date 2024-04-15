//#####################################################################
// Main
// CS3451 Computer Graphics Starter Code
// Contact: Bo Zhu (bo.zhu@gatech.edu)
//#####################################################################
#include <iostream>
#include <random>

#include "OpenGLMesh.h"
#include "OpenGLCommon.h"
#include "OpenGLWindow.h"
#include "OpenGLViewer.h"

/////////////////////////////////////////////////////////////////////
//// TODO: put your name in the string               
/////////////////////////////////////////////////////////////////////

const std::string author="Anqi Zheng";

/////////////////////////////////////////////////////////////////////
//// These are helper functions we created to generate circles and triangles by testing whether a point is inside the shape or not.
//// They can be used in the paintGrid function as "if the pixel is inside, draw some color; else skip."
//// You may create your own functions to draw your own shapes

//// The paintGrid function is implemented as a GLSL fragment shader. 
//// The GLSL grammar is C-style, and if you are curious about its full picture (which we will start to learn the details in Week 3), 
//// you may find more information on https://www.khronos.org/files/opengl43-quick-reference-card.pdf (Page 6 - 7 would probably be helpful!)
//// You don't need advanced GLSL features for this assignment (reading the starter code should be enough).
//// You can also test it (copy the whole string) in Shadertoy: https://www.shadertoy.com/new    
/////////////////////////////////////////////////////////////////////

const std::string draw_pixels=To_String(
const float M_PI=3.1415926535; 

// The side length of the minimum unit (or the new "pixels")
const float PIXEL_SIZE=10.; 

// To check if a point is inside a circle
bool inCircle(vec2 p, vec2 center, float radius) {
	vec2 to_center=p - center;
	if (dot(to_center, to_center) < radius * radius) {
		return true;
	}
	return false;
}

// To check if a point is inside a triangle
bool inTriangle(vec2 p, vec2 p1, vec2 p2, vec2 p3) {
	if (dot(cross(vec3(p2 - p1, 0), vec3(p - p1, 0)), cross(vec3(p2 - p1, 0), vec3(p3 - p1, 0))) >= 0. &&
		dot(cross(vec3(p3 - p2, 0), vec3(p - p2, 0)), cross(vec3(p3 - p2, 0), vec3(p1 - p2, 0))) >= 0. &&
		dot(cross(vec3(p1 - p3, 0), vec3(p - p3, 0)), cross(vec3(p1 - p3, 0), vec3(p2 - p3, 0))) >= 0.) {
		return true;
	}
	return false;
}

// To check if a point is below a sine wave
bool belowSine(vec2 p, float amplitude, float period, float horizontalOffset, float verticalOffset) {
	if (p.y < amplitude * sin(p.x / period + horizontalOffset) + verticalOffset) {
		return true;
	}
	return false;
}

// vec4 paint_circle(float x, float y, vec3 color) {
// 	vec2 center = vec2(iResolution / PIXEL_SIZE / 2.);
// 	float radoius = 100.f/PIXEL_SIZE;
// 	if (pow(x - center.x, 2) + pow(y-center.y, 2) < radius * radius)
// 		return vec4(color/255., 1.);
// 	else return vec4(vec3(150, 240, 200) / 255., 1.);
// }



// To convert from Polar Coordinates to Cartesian coordinates
vec2 polar2cart(float angle, float length) {
	return vec2(cos(angle) * length, sin(angle) * length);
}

/////////////////////////////////////////////////////////////////////////
// Feel free to add more functions if needed!                          
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// TODO: replace the code below with your own code                 //
// Useful variables:											   //
// iTime: the passed seconds from the start of the program         //
// iResolution: the size of the window (default: 1280*960)         //
/////////////////////////////////////////////////////////////////////

// Return the rgba color of the grid at position (x, y) 
vec4 paintGrid(float x, float y) {
	vec2 center=vec2(iResolution / PIXEL_SIZE / 2.); // window center
	// vec2 p1=polar2cart(iTime, 16.) + center;
	// vec2 p2=polar2cart(iTime + 2. * M_PI / 3., 16.) + center;
	// vec2 p3=polar2cart(iTime + 4. * M_PI / 3., 16.) + center;
	// vec2 p4=polar2cart(iTime + M_PI / 3., 16.) + center;
	// vec2 p5=polar2cart(iTime + M_PI, 16.) + center;
	// vec2 p6=polar2cart(iTime + 5. * M_PI / 3., 16.) + center;

//mushroom graphic1
	vec2 circleCenter1 = vec2(30, 30);
	float circleRadius1 = 10.0;
	vec3 circleColor1 = vec3(100, 10, 200);

	vec2 circleCenter2 = vec2(15, 25);
	float circleRadius2 = 5.0;
	vec3 circleColor2 = vec3(200, 150, 0);

	vec2 circleCenter3 = vec2(25, 33);
	float circleRadius3 = 4.0;

	vec2 circleCenter4 = vec2(40, 20);
	float circleRadius4 = 5.0;

	vec2 circleCenter5 = vec2(30, 12);
	float circleRadius5 = 13.0;
	vec3 circleColor5 = vec3(210, 210, 210);

	vec2 p1 = vec2(10, 20);
	vec2 p2 = vec2(25, 38);
	vec2 p3 = vec2(30, 20);
	vec2 p4 = vec2(35, 20);
	vec2 p5 = vec2(35, 38);
	vec2 p6 = vec2(50, 20);

//mushroom graphic2
	vec2 circleCenter6 = vec2(90, 30);
	float circleRadius6 = 15.0;
	vec3 circleColor6 = vec3(230, 10, 10);

	vec2 circleCenter7 = vec2(75, 25);
	float circleRadius7 = 4.0;
	vec3 circleColor7 = vec3(250, 250, 250);

	vec2 circleCenter8 = vec2(85, 33);
	float circleRadius8 = 4.0;

	vec2 circleCenter9 = vec2(100, 30);
	float circleRadius9 = 4.0;

	vec2 circleCenter10 = vec2(90, 12);
	float circleRadius10 = 10.0;
	vec3 circleColor10 = vec3(250, 250, 230);

	vec2 circleCenter11 = vec2(90, 15);
	float circleRadius11 = 5;

	vec2 p16 = vec2(70, 20);
	vec2 p17 = vec2(85, 40);
	vec2 p18 = vec2(90, 20);
	vec2 p19 = vec2(95, 20);
	vec2 p20 = vec2(95, 38);
	vec2 p21 = vec2(110, 20);



	bool inTriangle1 = inTriangle(vec2(x, y),p1, p2, p3);
	bool inTriangle2 = inTriangle(vec2(x, y), p4, p5, p6);
	bool inCircle1 = inCircle(vec2(x, y), circleCenter1, circleRadius1);
	bool inCircle2 = inCircle(vec2(x, y), circleCenter2, circleRadius2);
	bool inCircle3 = inCircle(vec2(x, y), circleCenter3, circleRadius3);
	bool inCircle4 = inCircle(vec2(x, y), circleCenter4, circleRadius4);
	bool inCircle5 = inCircle(vec2(x, y), circleCenter5, circleRadius5);
	bool inWater = belowSine(vec2(x, y), 3., 5., 3 + iTime * 4, 3.);

	bool inTriangle6 = inTriangle(vec2(x, y),p16, p17, p18);
	bool inTriangle7 = inTriangle(vec2(x, y), p19, p20, p21);
	bool inCircle6 = inCircle(vec2(x, y), circleCenter6, circleRadius6);
	bool inCircle7 = inCircle(vec2(x, y), circleCenter7, circleRadius7);
	bool inCircle8 = inCircle(vec2(x, y), circleCenter8, circleRadius8);
	bool inCircle9 = inCircle(vec2(x, y), circleCenter9, circleRadius9);
	bool inCircle10 = inCircle(vec2(x, y), circleCenter10, circleRadius10);
	bool inCircle11 = inCircle(vec2(x, y), circleCenter11, circleRadius11);
//mushroom graphic ends

//water drops graphics
	//water drop1
	float dropRadius1 = 4.0;
	float dropRadius2 = 3.0;
	vec3 waterColor = vec3(100, 100, 250);

	vec2 dropCenter1 = vec2(40, 80);
	vec2 p7 = vec2(37, 82);
	vec2 p8 = vec2(43, 82);
	vec2 p9 = vec2(40, 86);

	bool inDrop1 = inCircle(vec2(x, y), dropCenter1, dropRadius1);
	bool inTriangle3 = inTriangle(vec2(x, y), p7, p8, p9);

	//water drop2
	vec2 dropCenter2 = vec2(100, 60);
	vec2 p10 = vec2(97, 62);
	vec2 p11 = vec2(103, 62);
	vec2 p12 = vec2(100, 66);
	bool inDrop2 = inCircle(vec2(x, y), dropCenter2, dropRadius1);
	bool inTriangle4 = inTriangle(vec2(x, y), p10, p11, p12);

	//water drop3
	vec2 dropCenter3 = vec2(10, 70);
	vec2 p13 = vec2(7, 72);
	vec2 p14 = vec2(13, 72);
	vec2 p15 = vec2(10, 76);
	bool inDrop3 = inCircle(vec2(x, y), dropCenter3, dropRadius1);
	bool inTriangle5 = inTriangle(vec2(x, y), p13, p14, p15);

	//water drop4
	vec2 dropCenter4 = vec2(60, 50);
	vec2 p22 = vec2(57, 52);
	vec2 p23 = vec2(63, 52);
	vec2 p24 = vec2(60, 56);
	bool inDrop4 = inCircle(vec2(x, y), dropCenter4, dropRadius1);
	bool inTriangle8 = inTriangle(vec2(x, y), p22, p23, p24);

	vec2 dropCenter5 = vec2(115, 40);
	vec2 p25 = vec2(112, 42);
	vec2 p26 = vec2(118, 42);
	vec2 p27 = vec2(115, 46);
	bool inDrop5 = inCircle(vec2(x, y), dropCenter5, dropRadius1);
	bool inTriangle9 = inTriangle(vec2(x, y), p25, p26, p27);


//coloring logic
	
	//mushroom coloring logic
    if (inWater) {
		return vec4(vec3(0, 0, 255)/255., 1.);
	}
	if (inCircle4 && inTriangle2) {
		return vec4(circleColor2/255., 1.);
	}
	if (inCircle3) {
		return vec4(circleColor2/255., 1.);
	}
	if (inCircle2 && inTriangle1) {
		return vec4(circleColor2/255., 1.);
	}
	if (inTriangle2 || inTriangle1) {
		return vec4(circleColor1/255., 1.);
	} if (inCircle1) {
		return vec4(circleColor1/255., 1.);
	} if (inCircle5) {
		return vec4(circleColor5/255., 1.);
	}
	//second mushroom
	if (inCircle11 && inCircle6) {
		return vec4(circleColor7/255., 1.);
	}
	if (inCircle9) {
		return vec4(circleColor7/255., 1.);
	}
	if (inCircle8) {
		return vec4(circleColor7/255., 1.);
	}
	if (inCircle7 && inTriangle6) {
		return vec4(circleColor7/255., 1.);
	}
	if (inTriangle7 || inTriangle6) {
		return vec4(circleColor6/255., 1.);
	} if (inCircle6) {
		return vec4(circleColor6/255., 1.);
	} if (inCircle10) {
		return vec4(circleColor10/255., 1.);
	}
	//water drops coloring logic
	if (inDrop1 || inTriangle3) {
		return vec4(waterColor/255., 1.);
	} if (inDrop2 || inTriangle4) {
		return vec4(waterColor/255., 1.);
	} if (inDrop3 || inTriangle5) {
		return vec4(waterColor/255., 1.);
	} if (inDrop4 || inTriangle8) {
		return vec4(waterColor/255., 1.);
	} if (inDrop5 || inTriangle9) {
		return vec4(waterColor/255., 1.);
	} 
	
	//paint background
	else {
		return vec4(vec3(150, 240, 200) / 255., 1.);
	}
}

// The function called in the fragment shader
void mainImage(out vec4 fragColor, in vec2 fragCoord)
{
	// To divide the screen into the grids for painting!
	fragColor=paintGrid(floor(fragCoord.x / PIXEL_SIZE), floor(fragCoord.y / PIXEL_SIZE));
}

);

class ScreenDriver : public OpenGLViewer
{
	OpenGLScreenCover* screen_cover=nullptr;
	clock_t startTime=clock();

public:
	virtual void Initialize()
	{
		OpenGLViewer::Initialize();
	}

	//// Initialize the screen covering mesh and shaders
	virtual void Initialize_Data()
	{
		OpenGLShaderLibrary::Instance()->Create_Screen_Shader(draw_pixels, "shaderToy");
		screen_cover=Add_Interactive_Object<OpenGLScreenCover>();
		Set_Polygon_Mode(screen_cover, PolygonMode::Fill);
		Uniform_Update();

		screen_cover->Set_Data_Refreshed();
		screen_cover->Initialize();
		screen_cover->Add_Shader_Program(OpenGLShaderLibrary::Get_Shader("shaderToy"));
	}

	//// Update the uniformed variables used in shader
	void Uniform_Update()
	{
		screen_cover->setResolution((float)Win_Width(), (float)Win_Height());
		screen_cover->setTime(GLfloat(clock() - startTime) / CLOCKS_PER_SEC);
	}

	//// Go to next frame 
	virtual void Toggle_Next_Frame()
	{
		Uniform_Update();
		OpenGLViewer::Toggle_Next_Frame();
	}

	////Keyboard interaction
	virtual void Initialize_Common_Callback_Keys()
	{
		OpenGLViewer::Initialize_Common_Callback_Keys();
	}

	virtual void Run()
	{
		OpenGLViewer::Run();
	}
};

int main(int argc,char* argv[])
{
	if(author==""){std::cerr<<"***** The author name is not specified. Please put your name in the author string first. *****"<<std::endl;return 0;}
	else std::cout<<"Assignment 1 demo by "<<author<<" started"<<std::endl;
	
	ScreenDriver driver;
	driver.Initialize();
	driver.Run();	
}

