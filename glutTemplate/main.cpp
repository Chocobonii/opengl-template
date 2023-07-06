/*
------------------------------------------------
- THESE ARE THE MAIN LIBRARIES FROM THE SYSTEM -
------------------------------------------------
*/

#include<GL/glut.h>
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>
#include<math.h>
/*
=====================================================
= LIB CALLS WILL OCCUR IN THIS PART OF THE CODE UWU =
=====================================================
*/

// MAIN GLOBAL VARIABLES INCLUDES FOR COMPILATION AND SIMULATION
#include "variables/LL_BUILD.h"
#include "variables/llGlobalVars.h"
/*
-------------------------------------------------------
- INCLUDE THE IMGUI LIBRARIES TO GET THE HUDS WORKING - 
------------------------------------------------------- 
*/
#include "lib/imgui/imgui.h"                       
#include "lib/imgui/backends/imgui_impl_opengl2.h" 
#include "lib/imgui/backends/imgui_impl_glut.h"    
#include "lib/style.h"                             
/*
-----------------------------------------------
- RENDERING AND SIMULATOR SET UP INCLUDES UWU -
-----------------------------------------------
*/
#include "indra/llRendering/llHud.h"
#include "indra/llRendering/llDisplay.h"
#include "indra/llRendering/llAuxiliar.h"
#include "indra/llControls/llUserInput.h"

int main(int argc, char **argv){
  IMGUI_CHECKVERSION();   // TEST VERSION OF IMGUI
  ImGui::CreateContext(); // CREATE AN IMGUI CONTEXT
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(BON_SCREEN_W,BON_SCREEN_H);
  glutCreateWindow(".:: Gemini Player ::.");
  ImGuiIO &io = ImGui::GetIO(); (void) io;                     // initialize input/output of the imgui API
  ImGui::StyleColorsDark();                                    // define dark color for the im gui api
  ImGui_ImplGLUT_Init();                                       // start the GLUT version of imgui
  ImGui_ImplGLUT_InstallFuncs();                               // install functions of imgui
  ImGui_ImplOpenGL2_Init();                                    // use opengl 2 on imgui (to avoid pipewire)
  glClearDepth(1.0f);
  glDepthFunc(GL_LEQUAL);
  LL_Gemini_start();
  glutIgnoreKeyRepeat(1);
  glutDisplayFunc(LL_Gemini_display);
  glutIdleFunc(LL_Gemini_stand);
  glutMainLoop();
  ImGui_ImplOpenGL2_Shutdown();               // end the OpenGL2 of ImGui
  ImGui_ImplGLUT_Shutdown();                  // shut down glut of imgui
  ImGui::DestroyContext();                    // destroy the context
  return 0;
}