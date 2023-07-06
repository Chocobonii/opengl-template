#include "llEnvironment.h"

void LL_Gemini_display(){
ImGui_ImplOpenGL2_NewFrame();
 ImGui_ImplGLUT_NewFrame();
 // ----------------------------------------------------------
  LL_Imgui_interface();
 // ----------------------------------------------------------
 ImGui::Render();
 ImGuiIO& io = ImGui::GetIO();
 BON_SCREEN_W = io.DisplaySize.x;
 BON_SCREEN_H = io.DisplaySize.y;
 glViewport(0,0,(GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
 glMatrixMode(GL_PROJECTION); // CAMBIAR EL MODO A PROYECCION
 glLoadIdentity(); // CARGAR LOS OBJETOS
 gluPerspective(60, (float)BON_SCREEN_W/BON_SCREEN_H , 0.1, 3000);              
 glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); 
 glMatrixMode(GL_MODELVIEW);                        
 glEnable(GL_CULL_FACE);                            
 glCullFace(GL_BACK);                    
 glLoadIdentity();     
 gluLookAt(5,2,5,0,0,0,0,1,0);                 

 glPushMatrix();
    glutSolidCube(1);
 glPopMatrix();
                       
 LL_Gemini_environment();
 ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
 glFlush();                                        
 glutSwapBuffers();                             
}