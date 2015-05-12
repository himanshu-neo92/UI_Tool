////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014
//
// Modular Framework for OpenGLES2 rendering on multiple platforms.
//
namespace octet {
  /// Scene containing a box with octet.
  class UI_Tool : public app {
    // scene for drawing box
    ref<visual_scene> app_scene;    
    UI_sys GUI_sys;

    UI_bar* HP_Bar;
    vec2 HP_Bar_pos;
    vec2 HP_Bar_size;

    UI_bar* SP_Bar;
    vec2 SP_Bar_pos;
    vec2 SP_Bar_size;
    
    heal_button* Self_heal;
    vec2 heal_b_pos;
    vec2 heal_b_size;
    
    attack_button* Attack;
    vec2 attack_b_pos;
    vec2 attack_b_size;

    pause_button* pause;
    vec2 pause_b_pos;
    vec2 pause_b_size;
    UI_element *dissable_at_pause[2];

    UI_sprite* pause_background;
    vec2 pauseb_b_pos;
    vec2 pauseb_b_size;

    resume_button* resume;
    quit_button* quit;

    int regen_count = 0;
    int damage_count =0;
  public:
    /// this is called when we construct the class before everything is initialised.
    UI_Tool(int argc, char **argv) : app(argc, argv) {
      
    }

    ~UI_Tool()
    {
      delete Self_heal;
      delete Attack;
      delete SP_Bar;
      delete HP_Bar;
      delete pause;
      delete pause_background;
    }
    /// this is called once OpenGL is initialized
    void app_init() {
      app_scene =  new visual_scene();
      app_scene->create_default_camera_and_lights();
      int vx = 0, vy = 0;
      get_viewport_size(vx, vy);

      HP_Bar_pos = vec2(vx - vx / 8, 20);
      HP_Bar_size = vec2(100, 10);
      HP_Bar = new UI_bar(HP_Bar_pos, HP_Bar_size, 0.9f, vec2(0, 0.9677f), vec2(0.25f, 1));
      
      SP_Bar_pos = vec2(vx - vx / 8, 50);
      SP_Bar_size = vec2(100, 10);
      SP_Bar = new UI_bar(SP_Bar_pos, SP_Bar_size, 0.9f, vec2(0.25f, 0.9677f), vec2(0.5f, 1));

      heal_b_pos = vec2(120, vy - 100);
      heal_b_size = vec2(100,75);
      Self_heal = new heal_button(heal_b_pos, heal_b_size, 0.9f, vec2(0.3798f, 0.888f), vec2(0.6201f, 0.9677f), HP_Bar, SP_Bar);

      attack_b_pos = vec2(350, vy - 100);
      attack_b_size = vec2(100, 75);
      Attack = new attack_button(attack_b_pos, attack_b_size, 0.9f, vec2(0.1289f, 0.888f), vec2(0.3798f, 0.9677f), SP_Bar);

      pause_b_pos = vec2(vx/2, 100);
      pause_b_size = vec2(64, 64);
      dissable_at_pause[0] = Self_heal;
      dissable_at_pause[1] = Attack;     
      

      pauseb_b_pos = vec2(vx*2,vy*2);
      pauseb_b_size = vec2(300,500);
      pause_background = new UI_sprite(pauseb_b_pos, pauseb_b_size, 0.91f, vec2(0.255f,0.3349f), vec2(0.7558f, 0.8388f));
      quit = new quit_button(pauseb_b_pos, vec2(100, 50), 1.0f, vec2(0, 0.7080f), vec2(0.25f, 0.8388f));
      resume = new resume_button(pauseb_b_pos, vec2(100, 50), 1.0f, vec2(0.625f, 0.888f), vec2(0.8769f, 0.9677f), pause_background, quit, dissable_at_pause, 2);
      quit->Set_is_active(false);
      resume->Set_is_active(false);
      pause_background->Set_is_active(false);

      pause = new pause_button(pause_b_pos, pause_b_size, 0.9f, vec2(0, 0.8388f), vec2(0.127f, 0.9677f), dissable_at_pause, 2, pause_background, resume, quit, this);

      GUI_sys.init(vx, vy, this, "assets/UI_sprite_sheet.gif","assets/UI_sprite_sheet_mask.gif");
      GUI_sys.add_element(HP_Bar);
      GUI_sys.add_element(SP_Bar);
      GUI_sys.add_element(Self_heal);
      GUI_sys.add_element(Attack);
      GUI_sys.add_element(pause);
      GUI_sys.add_element(pause_background);
      GUI_sys.add_element(quit);
      GUI_sys.add_element(resume);
    }

    /// this is called to draw the world
    void draw_world(int x, int y, int w, int h) {
      int vx = 0, vy = 0;
      get_viewport_size(vx, vy);
      app_scene->begin_render(vx, vy);

      // update matrices. assume 30 fps.
      app_scene->update(1.0f/30);

      // draw the scene
      app_scene->render((float)vx / vy);
      bool paused = pause->ispaused();
      if (!paused)
     {
       pause->Set_is_active(true);
      if (get_frame_number() - regen_count > 60)
      {
        regen_count = get_frame_number();
        SP_Bar->p_added(0.1f);
      }

      if (get_frame_number() - damage_count > 90 )
      {
        damage_count = get_frame_number();
        HP_Bar->remove_p(0.1f);
      }
      }
      else
      {
        paused = resume->ret_unpause();
        pause->setpaused(paused);
      }
      GUI_sys.update(vx,vy);
    }
  };
}
