#version 330 core

/* default camera matrices (do not modify) */
layout(std140) uniform camera {
    mat4 projection;	/* camera's projection matrix */
    mat4 view;			/* camera's view matrix */
    mat4 pvm;			/* camera's projection*view*model matrix */
    mat4 ortho;			/* camera's ortho projection matrix */
    vec4 position;		/* camera's position in world space */
};

/* uniform variables that you can use to create dynamic lighting effects */
uniform float iTime;    /* time */

/* uniform variables for the object's material propreties */
/* you may use these variables in any functions in this shader */
uniform vec3 ka;            /* object material ambient */
uniform vec3 kd;            /* object material diffuse */
uniform vec3 ks;            /* object material specular */
uniform float shininess;    /* object material shininess */

/* input variables */
in vec4 vtx_color;          /* vertex color, not used in this assignment */
in vec3 vtx_normal;         /* vertex normal (in world space) */
in vec3 vtx_position;       /* vertex position (in world space) */

/* output variables */
out vec4 frag_color;        /* fragment color */

/* this struct define the properties of a point light source */
struct Light 
{
    vec3 position;          /* light position */
    vec3 Ia;                /* ambient intensity */
    vec3 Id;                /* diffuse intensity */
    vec3 Is;                /* specular intensity */     
};

/////////////////////////////////////////////////////
//// Step 1 Function: Visualize the normal vectors as color
//// In this function, you will implement the conversion from a normal vector to a color
//// For each component of the input, you need to map its value from [-1, 1] to [0, 1] in the output 

vec4 shading_normal() 
{
    vec3 _normal = normalize(vtx_normal);
    
    /* your implementation starts */

    // Map x-component from [-1, 1] to [0, 1]
    float r = (_normal.x + 1.0) / 2.0;
    
    // Map y-component from [-1, 1] to [0, 1]
    float g = (_normal.y + 1.0) / 2.0;
    
    // Map z-component from [-1, 1] to [0, 1]
    float b = (_normal.z + 1.0) / 2.0;
    
    return vec4(r, g, b, 1.0);
    /* your implementation ends */
}

/////////////////////////////////////////////////////
//// Step 2 Function: Ambient Shading
//// In this function, you will implement the ambient shading model
//// The inputs of the function are specified as below, and the output is the shaded color

/////////////////////////////////////////////////////
//// input variables for shading_lambertian
/////////////////////////////////////////////////////
//// light: the light struct
/////////////////////////////////////////////////////

vec4 shading_ambient(Light light) 
{
    /* your implementation starts */
    
    // Ambient light intensity
    vec3 ambientLight = light.Ia;
    
    // Ambient material coefficient
    vec3 ambientMaterial = ka;
    
    // Calculate ambient lighting
    vec3 ambient = ambientMaterial * ambientLight;
    
    return vec4(ambient, 1.0);
    /* your implementation ends */
}

/////////////////////////////////////////////////////
//// Step 3 Function: Lambertian Shading
//// In this function, you will implement the Lambertian shading model
//// The inputs of the function are specified as below, and the output is the shaded color

/////////////////////////////////////////////////////
//// input variables for shading_lambertian
/////////////////////////////////////////////////////
//// light: the light struct
//// p: position of the point
//// s: light source position (you may also use light.position)
//// n: normal at the point
/////////////////////////////////////////////////////

vec4 shading_lambertian(Light light, vec3 p, vec3 s, vec3 n) 
{
    /* your implementation starts */

    // Ambient material coefficient
    vec3 ambientMaterial = ka;
    
    // Ambient light intensity
    vec3 ambientLight = light.Ia;
    
    // Diffuse material coefficient
    vec3 diffuseMaterial = kd;
    
    // Diffuse light intensity
    vec3 diffuseLight = light.Id;
    
    // Normalize vectors
    vec3 lightDirection = normalize(s - p);
    vec3 normal = normalize(n);
    
    // Calculate diffuse component
    float diffuseIntensity = max(dot(lightDirection, normal), 0.0);
    vec3 diffuse = diffuseMaterial * diffuseLight * diffuseIntensity;
    
    // Calculate Lambertian lighting
    vec3 lambertian = ambientMaterial * ambientLight + diffuse;
    
    return vec4(lambertian, 1.0);
    /* your implementation ends */
}

/////////////////////////////////////////////////////
//// Step 4 Function: Phong Shading
//// In this function, you will implement the Phong shading model
//// The inputs of the function are specified as below, and the output is the shaded color

/////////////////////////////////////////////////////
//// input variables for shading_phong
/////////////////////////////////////////////////////
//// light: the light struct
//// e: eye position
//// p: position of the point
//// s: light source position (you may also use light.position)
//// n: normal at the point
/////////////////////////////////////////////////////

vec4 shading_phong(Light light, vec3 e, vec3 p, vec3 s, vec3 n) 
{
    /* your implementation starts */
    // Ambient material coefficient
    vec3 ambientMaterial = ka;
    
    // Ambient light intensity
    vec3 ambientLight = light.Ia;
    
    // Diffuse material coefficient
    vec3 diffuseMaterial = kd;
    
    // Diffuse light intensity
    vec3 diffuseLight = light.Id;
    
    // Specular material coefficient
    vec3 specularMaterial = ks;
    
    // Specular light intensity
    vec3 specularLight = light.Is;
    
    // Normalize vectors
    vec3 lightDirection = normalize(s - p);
    vec3 viewDirection = normalize(e - p);
    vec3 normal = normalize(n);
    
    // Calculate reflection vector
    vec3 reflectionVector = reflect(-lightDirection, normal);
    
    // Calculate diffuse component
    float diffuseIntensity = max(dot(lightDirection, normal), 0.0);
    vec3 diffuse = diffuseMaterial * diffuseLight * diffuseIntensity;
    
    // Calculate specular component
    float specularIntensity = pow(max(dot(reflectionVector, viewDirection), 0.0), shininess);
    vec3 specular = specularMaterial * specularLight * specularIntensity;
    
    // Calculate Phong lighting
    vec3 phong = ambientMaterial * ambientLight + diffuse + specular;
    
    return vec4(phong, 1.0);
    
    /* your implementation ends */
}

/////////////////////////////////////////////////////
//// Step 6 Function: dynamic light source
//// In this function, you will implement the rotation of the light source around Z axis, by angle theta
//// Modify the transform matrix to specify the rotation
//// Keep in mind that a GLSL matrix is column major by default
/////////////////////////////////////////////////////

Light get_spinny_light(Light light) 
{
    float theta = iTime * .8;

    /* modify the following matrix to create a counterclockwise rotation with angle theta */
    /* notice that in GLSL the matrix is column-major by default! */
    
    /* your implementation starts */

    mat4 light_model_mtx = 
        mat4(cos(theta), -sin(theta), 0., 0., 
             sin(theta), cos(theta), 0., 0., 
             0., 0., 1., 0., 
             0., 0., 0., 1.);
    
    /* your implementation ends */


    return Light((light_model_mtx * vec4(light.position, 1)).xyz, light.Ia, light.Id, light.Is);
}
vec4 custom_shading(Light light, vec3 e, vec3 p, vec3 s, vec3 n) {
    vec3 ambientMaterial = vec3(0.3, 0.3, 0.1);
    vec3 ambientLight = light.Ia;
    
    vec3 diffuseMaterial = vec3(0.8, 0.6, 0.2);
    vec3 diffuseLight = light.Id;
    
    vec3 specularMaterial = vec3(0.5, 0.5, 0.3);
    vec3 specularLight = light.Is;
    
    vec3 lightDirection = normalize(s - p);
    vec3 viewDirection = normalize(e - p);
    vec3 normal = normalize(n);
    
    vec3 reflectionVector = reflect(-lightDirection, normal);
    
    float diffuseIntensity = max(dot(lightDirection, normal), 0.0);
    vec3 diffuse = diffuseMaterial * diffuseLight * diffuseIntensity;

    float specularIntensity = pow(max(dot(reflectionVector, viewDirection), 0.0), shininess);
    vec3 specular = specularMaterial * specularLight * specularIntensity;
    
    
    vec3 phong = ambientMaterial * ambientLight + + diffuse + specular;
    
    return vec4(phong, 1.0);

}


void main() 
{
    //// we have one light source in the scene by default
    const Light light1 = Light(/*position*/ vec3(3, 1, 3), 
                                /*Ia*/ vec3(0.1, 0.1, 0.1), 
                                /*Id*/ vec3(1.0, 1.0, 1.0), 
                                /*Is*/ vec3(0.5, 0.5, 0.5));
    const Light light2 = Light(/*position*/ vec3(-3, 1, 3), 
                                /*Ia*/ vec3(0.05, 0.02, 0.03), 
                                /*Id*/ vec3(0.4, 0.2, 0.3), 
                                /*Is*/ vec3(0.4, 0.2, 0.3));
    const Light darkGreenLight = Light(/*position*/ vec3(3, 1, 3), 
                                /*Ia*/ vec3(0.05, 0.5, 0.05), 
                                /*Id*/ vec3(0.2, 0.7, 0.2), 
                                /*Is*/ vec3(0.1, 0.5, 0.1));
    
    const Light greyLight = Light(/*position*/ vec3(-3, -2, 3), 
                                /*Ia*/ vec3(0.1, 0.1, 0.1), 
                                /*Id*/ vec3(0.3, 0.3, 0.3), 
                                /*Is*/ vec3(0.2, 0.2, 0.3));
    

    

    //// variables that you may find useful for your implementation
    vec3 n = normalize(vtx_normal);     //// normal vector
    vec3 e = position.xyz;              //// eye position
    vec3 p = vtx_position;              //// surface position
    vec3 s1 = light1.position;          //// light position
    vec3 s2 = light2.position;
    vec3 s3 = darkGreenLight.position;
    vec3 s4 = greyLight.position;

    //// Step 1: visualize normal vectors as colors
    //// Your task is to implement the shading_normal function

    //frag_color = shading_normal();

    //// Step 2: ambient shading
    //// Your task is to implement the shading_normal function 
    //// Your implementation will be in the function shading_normal
    //// Uncomment the following line to call the function

    //frag_color = shading_ambient(light1);

    //// Step 3: Lambertian shading
    //// Your task is to implement the Lambertian shading function
    //// Your implementation will be in the function shading_lambertian
    //// Uncomment the following line to call the function

    //frag_color = shading_lambertian(light1, p, s1, n);

    //// Step 4: Phong shading
    //// Your task is to implement the Phong shading function
    //// Your implementation will be in the function shading_phong
    //// Uncomment the following line to call the function

    //frag_color = shading_phong(light1, e, p, s1, n);

    //// Step 5: multiple lights
    //// By default we calculate the contribution from light1. 
    //// Your task is to declare one additional light (light2) and add its contribution to the fragment color
    //// The additional light source is a point light, with its position in (-3, 1, 3), 
    //// ambient coefficient (0.05, 0.02, 0.03), both diffuse and specular coefficients (0.4, 0.2, 0.3)
    //// Uncomment the following line, declare a new light, and add its contribution to frag_color.

    /* Your implementation starts here */
    
    //vec4 color_light1 = shading_phong(light1, e, p, s1, n);
    //vec4 color_light2 = shading_phong(light2, e, p, s2, n);
    
    //frag_color = color_light1 + color_light2;
    /* Your implementation ends here */

    //// Step 6: dynamic light source
    //// Your task is to calculate the rotation of the light source around the z axis, with the specified angular velocity 
    //// Your implementation will take place in the function get_spinny_light
    //// After implementing rotation in get_spinny_light, uncomment the following two lines and press key 'p' to start the animation
    
    //Light spinnyLight = get_spinny_light(light1);
    //frag_color = shading_phong(spinnyLight, e, p, spinnyLight.position, n);

    //// Step 7: your customized lighting effect
    //// Implement your customized lighting effects on your customized mesh objects 
    //// You may reuse any functions you have implemented above
    //// Here we provide the phong shading model as the default implementation
    //// Customize it with your own lighting model

    vec4 color_light1 = custom_shading(darkGreenLight, e, p, s1, n);
    vec4 color_light2 = custom_shading(light2, e, p, s2, n);
    vec4 color_light3 = custom_shading(greyLight, e, p, s3, n);

    frag_color = color_light1 + color_light2 + color_light3;

    
}