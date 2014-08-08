#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GL/glut.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../common/shader_utils.h"

#define GROUND_SIZE 20

int screen_width = 800;
int screen_height = 600;
GLuint program;
GLint attribute_v_coord = -1;
GLint attribute_v_normal = -1;
GLint uniform_m = -1;
GLint unifrom_v = -1;
GLint unifrom_p = -1;
GLint unifrom_m_3x3_inv_transp = -1;
GLint unifrom_v_inv = -1;
bool compute_arcball;
int last_mx = 0;
int last_my = 0;
int cur_mx = 0;
int cur_my = 0;
int arcball_on = false;

using namespace std;

enum MODES {
  MODE_OBJECT,
  MODE_CAMERA,
  MODE_LIGHT,
  MODE_LAST
} view_mode;
int rotY_direction = 0;
int rotX_direction = 0;
int transZ_direction = 0;
int strife = 0;
float speed_factor = 1;
glm::mat4 transforms[MODE_LAST];
int last_ticks = 0;

static unsigned int fps_start = glutGet(GLUT_ELAPSED_TIME);
static unsigned int fps_frame = 0;

class Mesh {
private:
  GLuint vbo_vertices;
  GLuint vbo_normals;
  GLuint ibo_elements;

public:
  vector<glm::vec4> vertices;
  vector<glm::vec3> normals;
  vector<GLushort> elements;
  glm::mat4 object2world;

  Mesh() : vbo_vertices(0), vbo_normals(0), ibo_elements(0), object2world(glm::mat4(1.0f)) {}
  ~Mesh() {
    if (0 != vbo_vertices) {
      glDeleteBuffers(1, &vbo_vertices);
    }
    
    if (0 != vbo_normals) {
      glDeleteBuffers(1, &vbo_normals);
    }

    if (0 != ibo_elements) {
      glDeleteBuffers(1, &ibo_elements);
    }
  }

  /**
   * Store object vertices, normals and/or elements in graphic card
   * buffers
   */
  void update() {
  }

  /**
   * Draw the object
   */
  void draw() {
  }

  /**
   * Draw object bounding box
   */
  void draw_bbox() {

  }
};

Mesh ground;
Mesh main_object;
Mesh light_bbox;
////////////////////////////////////////////////////////////////////////////////////////

void load_obj(const char* filename, Mesh* mesh)
{

}

int init_resources(char* model_filename, char* vshader_filename, char* fshader_filename)
{
return 1;
}


void init_view()
{

}


void onSpecial(int key, int x, int y)
{

}

void onSpecialUp(int key, int x, int y)
{
}

/**
 * Get a normalized vector from the center of the virtual ball O to a
 * point P on the virtual ball suface, such that P is aligned on
 * screen's (X,Y) coordinates. If (X, Y) is too far away from the
 * sphere, return the nearest point on the virtual ball surface.
 */
glm::vec3 get_arcball_vector(int x, int y) {

}


void logic() {

}

void draw()
{
}

void onDisplay()
{
}

void onMouse(int button, int state, int x, int y)
{
}

void onMotion(int x, int y)
{
}

void onReshape(int width, int height)
{
}

void free_resource()
{
glDeleteProgram(program);
}

int main(int argc, char** argv)
{

}
