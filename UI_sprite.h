#ifndef UI_sprite_H
#define UI_sprite_H
namespace octet
{
  class UI_sprite : public UI_element
  {
  public:
    UI_sprite(vec2 _pos, vec2 _size, float _depth, vec2 uv_bot_left, vec2 uv_top_right) : UI_element(_pos, _size, _depth, uv_bot_left, uv_top_right)
    {

    }

    void OnClick()
    {

    }

    void OnHover()
    {

    }
  };
}
#endif