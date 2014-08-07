#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "../common/shader_utils.h"


GLuint vbo_triangle;
GLuint program;
GLint attribute_coord2d;

int init_resource()
{
  GLfloat triangle_vertices[] = {
    0.0, 0.8,
    -0.8, -0.8,
    0.8, -0.8,
  };

  glGenBuffers(1, &vbo_triangle);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

  GLint link_ok = GL_FALSE;
  
  GLuint vs, fs;
  if ((vs = create_shader("triangle.v.glsl", GL_VERTEX_SHADER)) == 0)
    return 0;
  if ((fs = create_shader("triangle.f.glsl", GL_FRAGMENT_SHADER)) == 0)
    return 0;

  program = glCreateProgram();
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
  if (!link_ok) {
    fprintf(stderr, "glinkProgram:");
    print_log(program);
    return 0;
  }

  const char* attribute_name = "coord2d";
  attribute_coord2d = glGetAttribLocation(program,  attribute_name);
  if (attribute_coord2d == -1) {
    fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
    return 0;
  }

  return 1;
}

void onDisplay()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  glUseProgram(program);
  glEnableVertexAttribArray(attribute_coord2d);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
  glVertexAttribPointer(attribute_coord2d,
			2,
			GL_FLOAT,
			GL_FALSE,
			0,
			0);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisableVertexAttribArray(attribute_coord2d);
  glutSwapBuffers();
}

void free_resource()
{
  glDeleteProgram(program);
  glDeleteBuffers(1, &vbo_triangle);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("My Second Triangle");

  GLenum glew_status = glewInit();
  if (glew_status != GLEW_OK) {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
    return 1;
  }

  if (!GLEW_VERSION_2_0) {
    fprintf(stderr, "Error: your graphic card does not support OpenGL 2.0\n");
    return 1;
  }

  if (init_resource()){
    glutDisplayFunc(onDisplay);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
  }

  free_resource();

  return 0;
}
