////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014
//
// Modular Framework for OpenGLES2 rendering on multiple platforms.
//
////

#include "../../octet.h"
#include "UI_element.h"
#include "UI_button.h"
#include "UI_bar.h"
#include "Attack_button.h"
#include "Heal_button.h"
#include "UI_sprite.h"
#include "quit_button.h"
#include "resume_button.h"
#include "pause_button.h"
#include "UI_sys.h"
#include "UI_Tool.h"

/// Create a box with octet
int main(int argc, char **argv) {
  // set up the platform.
  octet::app::init_all(argc, argv);

  // our application.
  octet::UI_Tool app(argc, argv);
  app.init();

  // open windows
  octet::app::run_all_apps();
}


