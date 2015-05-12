#ifndef UI_resume_button_H
#define UI_resume_button_H

namespace octet
{
  class resume_button : public UI_element
  {
    UI_element **prev_layer;
    int size;
    UI_sprite* pause_bg;
    quit_button* quit_b;
    bool paused = true;
  public:
    resume_button(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right, UI_sprite* _sprite, quit_button* _quit,UI_element *elements[], int size_ele) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {
      prev_layer=elements;
      size=size_ele;
      pause_bg = _sprite;
      quit_b = _quit;
    }

    bool ret_unpause()
    {
      return paused;
    }

    void set_unpaused(bool psd)
    {
      paused = psd;
    }
    void OnClick()
    {
     paused=false;
     Set_is_active(false);
     quit_b->Set_is_active(false);
     for (int i = 0; i<size; i++)
     {
       prev_layer[i]->Set_is_active(true);
     }
     Set_pos(vec2(Get_pos().x()*4,Get_pos().y()*4));
     quit_b->Set_pos(vec2(Get_pos().x() * 4, Get_pos().y() * 4));
     pause_bg->Set_pos(vec2(Get_pos().x() * 4, Get_pos().y() * 4));
    }

    void OnHover()
    {

    }
  };
}
#endif