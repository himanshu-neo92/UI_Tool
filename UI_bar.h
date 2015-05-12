#ifndef UI_hp_bar_H
#define UI_hp_bar_H
namespace octet
{
  class UI_bar : public UI_element
  {
   
    float UI_Bar_percent_left = 1.0f;
    
  public:
    UI_bar(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {
      
    }

    void OnClick()
    {
      
    }

    void OnHover()
    {

    }
    

    void remove_p(float percent_removed)
    {
      float orignal_size_x = Get_size().x() / UI_Bar_percent_left;
      float orignal_pos_x = Get_pos().x() - Get_size().x() + orignal_size_x;
      if (UI_Bar_percent_left - percent_removed > 0.0f)
      {
        UI_Bar_percent_left -= percent_removed;
        
      }
      else
      {
        UI_Bar_percent_left=0.01f;
      }
      vec2 new_size = vec2(UI_Bar_percent_left*orignal_size_x,Get_size().y());
      vec2 new_pos = vec2(orignal_pos_x - orignal_size_x + new_size.x(),Get_pos().y());
      Set_pos(new_pos);
      Set_size(new_size);
    }

    void p_added(float percent_added)
    {
      float orignal_size_x = Get_size().x() / UI_Bar_percent_left;
      float orignal_pos_x = Get_pos().x() - Get_size().x() + orignal_size_x;
      if (UI_Bar_percent_left + percent_added < 1.0f)
      {
        UI_Bar_percent_left += percent_added;       
      }
      else
      {
        UI_Bar_percent_left=1.0f;
      }
      vec2 new_size = vec2(UI_Bar_percent_left*orignal_size_x, Get_size().y());
      vec2 new_pos = vec2(orignal_pos_x - orignal_size_x + new_size.x(), Get_pos().y());
      Set_pos(new_pos);
      Set_size(new_size);
    }
   
  };
}
#endif