#ifndef UI_heal_button_H
#define UI_heal_button_H
namespace octet
{
  class heal_button : public UI_element
  {
    UI_bar *Player_hp_bar;
    UI_bar *Player_sp_bar;
  public:
    heal_button(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right, UI_bar* hp_bar,UI_bar* sp_bar) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {
      Player_hp_bar = hp_bar;
      Player_sp_bar = sp_bar;
    }

    void OnClick()
    {
      Player_hp_bar->p_added(0.1f);
      Player_sp_bar->remove_p(0.05f);
    }

    void OnHover()
    {

    }
  };
}
#endif