#ifndef UI_quit_button_H
#define UI_quit_button_H
namespace octet
{
  class quit_button : public UI_element
  {
  public:
    quit_button(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {

    }

    void OnClick()
    {
      exit(0);
    }

    void OnHover()
    {

    }
  };
}
#endif