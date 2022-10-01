$input v_uv, v_textureArea

#include <bgfx_shader.sh>
#include "shaderlib.sh"

SAMPLER2D(s_Texture, 0);

void main()
{
    vec2 uv = vec2(v_uv.x * v_textureArea.z + v_textureArea.x, v_uv.y * v_textureArea.w + v_textureArea.y);
    gl_FragColor = texture2D(s_Texture, uv);
}
