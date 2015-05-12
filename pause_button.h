#ifndef pause_button_H
#define pause_button_H


namespace octet
{
  class pause_button : public UI_element
  {
  UI_element **prev_layer;
  int size;
  bool paused;

  resume_button* resume_b;
  UI_sprite* pause_bg;
  quit_button* quit_b;
 app *program;
  public:
    pause_button(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right, UI_element *elements[],int size_ele,UI_sprite* p_bg,resume_button* _res_b,quit_button* q_b,app *theapp) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {
      size = size_ele; 
      prev_layer = elements;

      resume_b=_res_b;
      pause_bg = p_bg;
      quit_b = q_b;
      program = theapp;
      paused = false;
    }

    
    void OnClick()
    {
      for (int i=0;i<size;i++)
      {
        prev_layer[i]->Set_is_active(false);
      }      
      paused = true;
      Set_is_active(false);
      resume_b->set_unpaused(true);

      int vx,vy;
      program->get_viewport_size(vx, vy);
      pause_bg->Set_pos(vec2(vx/2,vy/2));

      resume_b->Set_pos(vec2(vx/2,vy/4));
      resume_b->Set_is_active(true);
      quit_b->Set_pos(vec2(vx/2,vy/2));
      quit_b->Set_is_active(true);
    }

    bool ispaused()
    {
      return paused;
    }
    void setpaused(bool pds)
    {
      paused = pds;
    }

    void OnHover()
    {

    }
  };
}
#endif