#ifndef UI_attack_button_H
#define UI_attack_button_H
namespace octet
{
  class attack_button : public UI_element
  {
    UI_bar *Player_sp_bar;
  public:
    attack_button(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right, UI_bar* sp_bar) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {
      Player_sp_bar = sp_bar;
    }

    void OnClick()
    {
      Player_sp_bar->remove_p(0.05f);
    }

    void OnHover()
    {

    }
  };
}
#endif