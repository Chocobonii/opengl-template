void LL_Gemini_stand(){
    usleep(33);
    glutPostRedisplay();
}

void LL_Gemini_start(){
 glClearColor(0.0,0.0,0.0,0.0);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_TEXTURE_2D);
 glEnable(GL_BLEND);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(60, 1,1,2000);
 //ImGui_ImplOpenGL2_Init();
}

/*
int gcd (int a, int b) {
  return a / b;
  //  return (b == 0) ? a : gcd (b, a%b);
}

void LL_Gemini_reshape_screen(int xs, int ys){
    const float ar = (float) xs / (float) ys; 
    BON_SCREEN_W = xs;
    BON_SCREEN_H = ys; 
    glViewport(0, 0, xs, ys);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(60, gcd(xs,ys), 0.1, 3000);
    //gluPerspective(60,1,0.1,3000);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity() 
}*/