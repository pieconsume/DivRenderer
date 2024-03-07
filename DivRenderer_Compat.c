//Defs
 #define windows
 #define uint unsigned int
 extern int    write(int fd, char* buffer, int count);
 extern int    printf(const char*, ...);
 extern void   exit(int error);
 extern float  sinf(float val);
 extern float  cosf(float val);
 extern int    glfwInit(void);
 extern void   glfwWindowHint(int hint, int value);
 extern void*  glfwCreateWindow(int width, int height, void* title, void* monitor, void* share);
 extern void   glfwMakeContextCurrent(void* window);
 extern void   glfwSwapBuffers(void* window);
 extern void   glfwPollEvents(void);
 extern int    glfwWindowShouldClose(void* window);
 extern void   glfwGetFramebufferSize(void* window,  int* width, int* height);
 extern int    glfwGetKey(void* window, uint key);
 extern int    glfwGetCursorPos(void* window, double* xpos, double* ypos);
 extern void*  glfwSetMouseButtonCallback(void* window, void* callback);
 extern void*  glfwSetKeyCallback(void* window, void* callback);
 extern void*  glfwSetCharCallback(void* window, void* callback);
 extern void   glfwTerminate(void);
 #ifndef windows
  //Todo - add new prototypes for linux
  extern void   glGenVertexArrays(int count, int* arrays);
  extern void   glGenBuffers(int count, int* buffers);
  extern void   glBindVertexArray(int array);
  extern void   glBindBuffer(uint target, int buf);
  extern void   glBufferData(uint target, int size, void* data, uint usage);
  extern void   glVertexAttribPointer(int index, int size, uint type, int normalized, int stride, void* pointer);
  extern void   glEnableVertexAttribArray(int index);
  extern int    glCreateShader(uint type);
  extern void   glShaderSource(int shader, int count, char** sources, int* lengths); //String is a double pointer to a string
  extern void   glCompileShader(int shader);
  extern void   glGetShaderiv(int shader, uint param, void* returnval);
  extern void   glGetShaderInfoLog(int shader, int bufsize, int* returnsz, void* buf);
  extern void   glDeleteShader(int shader);
  extern int    glCreateProgram(void);
  extern void   glAttachShader(int program, int shader);
  extern void   glLinkProgram(int program);
  extern void   glGetProgramiv(int program, uint param, void* returnval);
  extern void   glGetProgramInfoLog(int program, int bufsize, int* returnsz, void* buf);
  extern void   glDetachShader(int program, int shader);
  extern void   glDeleteProgram(int program);
  extern void   glUseProgram(int program);
  extern uint   glGetUniformLocation(int program, char* name);
  extern void   glClear(uint flags);
  extern void   glDrawArrays(int mode, int first, int count);
  extern void   glUniform2f(int uniform, float v1, float v2);
  extern void   glUniform2fv(int uniform, int count, float* values);
  extern void   glUniform3fv(int uniform, int count, float* values);
  extern void   glViewport(int x, int y, int width, int height);
  extern uint   glGetError(void);
  #endif
 #ifdef windows
  extern void* wglGetProcAddress(const char* name);
  //Todo - fix types. Shouldn't normally effect functionality, but should be done anyway
  int  (*glCreateShader)         (uint type);
  void (*glShaderSource)         (int shader, int count, char** sources, int* lengths);
  void (*glCompileShader)        (int shader);
  void (*glGetShaderiv)          (int shader, uint param, void* returnval);
  void (*glGetShaderInfoLog)     (int shader, int buffersz, void* returnsz, void* buffer);
  void (*glDeleteShader)         (int shader);
  int  (*glCreateProgram)        (void);
  void (*glAttachShader)         (int program, int shader);
  void (*glLinkProgram)          (int program);
  void (*glGetProgramiv)         (int program, uint param, void* returnval);
  void (*glGetProgramInfoLog)    (int program, int buffersz, void* returnval, void* buffer);
  void (*glDetachShader)         (int program, int shader);
  void (*glDeleteProgram)        (int program);
  void (*glUseProgram)           (int program);
  void (*glGenVertexArrays)      (int count, int* buffer);
  void (*glGenBuffers)           (int count, int* buffer);
  void (*glBindVertexArray)      (int array);
  void (*glBindBuffer)           (uint target, int buffer);
  void (*glBindBufferBase)       (uint target, int index, uint buffer);
  void (*glBindBufferRange)      (uint target, int index, uint buffer, int offset, int size);
  void (*glBufferData)           (uint target, int size, void* data, uint usage);
  void (*glBufferSubData)        (uint target, int offset, int size, void* data);
  int  (*glGetUniformLocation)   (int program, char* name);
  int  (*glGetUniformBlockIndex) (int program, char* name);
  void (*glUniformBlockBinding)  (int program, uint index, uint binding);
  void (*glActiveTexture)        (uint texture);
  void (*glTexParameteri)        (uint target, uint param, uint value);
  void (*glGenTextures)          (uint count, uint* textures);
  void (*glBindTexture)          (uint target, uint texture);
  void (*glTexImage2D)           (uint, uint, uint, uint, uint, uint, uint, uint, void*);
  void (*glClear)                (uint flags);
  void (*glDrawArrays)           (uint type, int first, int count);
  void (*glUniform1i)            (int uniform, int u1);
  void (*glUniform1ui)           (int uniform, uint u1);
  void (*glUniform2ui)           (int uniform, uint ui1, uint ui2);
  void (*glUniform4ui)           (int uniform, uint ui1, uint ui2, uint ui3, uint ui4);
  void (*glViewport)             (int x, int y, int width, int height);
  uint (*glGetError)             (void);
  void initgl(){
   glCreateShader         = (int(*)(uint))wglGetProcAddress("glCreateShader");
   glShaderSource         = (void(*)(int, int, char**, int*))wglGetProcAddress("glShaderSource");
   glCompileShader        = (void(*)(int))wglGetProcAddress("glCompileShader");
   glGetShaderiv          = (void(*)(int, uint, void*))wglGetProcAddress("glGetShaderiv");
   glGetShaderInfoLog     = (void(*)(int, int, void*, void*))wglGetProcAddress("glGetShaderInfoLog");
   glDeleteShader         = (void(*)(int))wglGetProcAddress("glDeleteShader");
   glCreateProgram        = (int(*)())wglGetProcAddress("glCreateProgram");
   glAttachShader         = (void(*)(int, int))wglGetProcAddress("glAttachShader");
   glLinkProgram          = (void(*)(int))wglGetProcAddress("glLinkProgram");
   glGetProgramiv         = (void(*)(int, uint, void*))wglGetProcAddress("glGetProgramiv");
   glGetProgramInfoLog    = (void(*)(int, int, void*, void*))wglGetProcAddress("glGetProgramInfoLog");
   glDetachShader         = (void(*)(int, int))wglGetProcAddress("glDetachShader");
   glDeleteProgram        = (void(*)(int))wglGetProcAddress("glDeleteProgram");
   glUseProgram           = (void(*)(int))wglGetProcAddress("glUseProgram");
   glGenVertexArrays      = (void(*)(int, int*))wglGetProcAddress("glGenVertexArrays");
   glGenBuffers           = (void(*)(int, int*))wglGetProcAddress("glGenBuffers");
   glBindVertexArray      = (void(*)(int array))wglGetProcAddress("glBindVertexArray");
   glBindBuffer           = (void(*)(uint, int))wglGetProcAddress("glBindBuffer");
   glBindBufferBase       = (void(*)(uint, int, uint))wglGetProcAddress("glBindBufferBase");
   glBindBufferRange      = (void(*)(uint, int, uint, int, int))wglGetProcAddress("glBindBufferRange");
   glBufferData           = (void(*)(uint, int, void*, uint))wglGetProcAddress("glBufferData");
   glBufferSubData        = (void(*)(uint, int, int, void*))wglGetProcAddress("glBufferSubData");
   glGetUniformLocation   = (int(*)(int, char*))wglGetProcAddress("glGetUniformLocation");
   glGetUniformBlockIndex = (int(*)(int, char*))wglGetProcAddress("glGetUniformBlockIndex");
   glUniformBlockBinding  = (void(*)(int, uint, uint))wglGetProcAddress("glUniformBlockBinding");
   glActiveTexture        = (void(*)(uint))wglGetProcAddress("glActiveTexture");
   glTexParameteri        = (void(*)(uint, uint, uint))wglGetProcAddress("glTexParameteri");
   glGenTextures          = (void(*)(uint, uint*))wglGetProcAddress("glGenTextures");
   glBindTexture          = (void(*)(uint, uint))wglGetProcAddress("glBindTexture");
   glTexImage2D           = (void(*)(uint, uint, uint, uint, uint, uint, uint, uint, void*))wglGetProcAddress("glTexImage2D");
   glClear                = (void(*)(uint))wglGetProcAddress("glClear");
   glDrawArrays           = (void(*)(uint, int, int))wglGetProcAddress("glDrawArrays");
   glUniform1i            = (void(*)(int, int))wglGetProcAddress("glUniform1i");
   glUniform1ui           = (void(*)(int, uint))wglGetProcAddress("glUniform1ui");
   glUniform2ui           = (void(*)(int, uint, uint))wglGetProcAddress("glUniform2ui");
   glUniform4ui           = (void(*)(int, uint, uint, uint, uint))wglGetProcAddress("glUniform4ui");
   glViewport             = (void(*)(int, int, int, int))wglGetProcAddress("glViewport");
   glGetError             = (uint(*)())wglGetProcAddress("glGetError");}
  #endif
//Vars
 int makeshader(int type, char** source);
 void setdiv(int, uint, uint, uint, uint);
 void setcolor(int, uint);
 void updatedivs();
 void updatecolors();
 void drawtext(uint, uint, char*);
 void onmousedown(void*, int, int, int);
 void ontextinput(void*, uint);
 void onkeydown(void*, int, int, int, int);
 void render();
 void done(); 
 void* window;
 int   program;
 int   vao, objs[3];
 char  buffer[0x1000];
 int   oldwidth = 0, oldheight = 0, width, height;
 int   divindex, colorindex, textindex, udiv, res, font, rendertype, textbase, idxoffset, textcolor;
 int   divcount;
 uint  divs[4096];
 uint  colors[256];
 int   focusedbox = -1;
 int   text1len = 0;
 char  text1[24];
 char* vertshaderstr = "#version 400\nvoid main() { gl_Position = vec4(1.0); }";
 char* geomshaderstr =
  //Flags
   //0x00000001 DockX
   //0x00000002 DockY
   //0x00000004 OffX
   //0x00000008 OffY
   //0x00000010 OffXDocks
   //0x00000020 OffYDocks
   //0x00000040 OffDockX
   //0x00000080 OffDockY
   //0x00000100 Hidden
   //0xFF000000 Outline
   //Color1Index div.y >> 16
   //Color2Index div.y &  0xFFFF
   //X1          div.z >> 16
   //Y1          div.z &  0xFFFF
   //X2          div.w >> 16
   //Y2          div.w &  0xFFFF
  "#version 400\n"
  "layout (points) in;"
  "layout (triangle_strip, max_vertices = 4) out;"
  "layout (std140) uniform divblock { uvec4 divs[1024]; };"
  "flat out uvec4 finaldiv;"
  "flat out uint charidx;"
  "uniform uvec4 udiv;"
  "uniform uvec2 res;"
  "uniform uint rendertype;"
  "uniform uint textbase;"
  "uniform uint idxoffset;"
  "void main(){"
    "uint bx, by, ox, oy;"
    "uint index = gl_PrimitiveIDIn + idxoffset;"
    "if ((divs[index].x & 0x100u) != 0 && rendertype == 0u) { return; }"
    "if      (rendertype == 0u || rendertype == 1u){"
     "uvec4 div;"
     "if (rendertype == 0u) { div = divs[index]; } else { div = udiv; }"
     "finaldiv.x = div.x;"
     "finaldiv.y = div.y;"
     "bx = div.z >> 16; by = div.z &  0xFFFFu;"
     "ox = div.w >> 16; oy = div.w &  0xFFFFu;"
     "if ((div.x & 0x01u) != 0) { bx = res.x - bx; }"
     "if ((div.x & 0x02u) != 0) { by = res.y - by; }"
     "if ((div.x & 0x10u) == 0) { if ((div.x & 0x04u) != 0) { ox = bx-ox; } else { ox = bx+ox; } } else { if ((div.x & 0x40u) != 0) { ox = res.x - ox; } }"
     "if ((div.x & 0x20u) == 0) { if ((div.x & 0x08u) != 0) { oy = by-oy; } else { oy = by+oy; } } else { if ((div.x & 0x80u) != 0) { oy = res.y - oy; } }"
     "if (bx < ox) { finaldiv.z =  bx<<16;   finaldiv.w = ox<<16; }     else { finaldiv.z = ox<<16;     finaldiv.w = bx<<16; }"
     "if (by < oy) { finaldiv.z += by&0xFFFF; finaldiv.w += oy&0xFFFF; } else { finaldiv.z += oy&0xFFFF; finaldiv.w += by&0xFFFF; } }"
    "else if (rendertype == 2u){"
     "charidx = index;"
     "bx = (textbase >> 16) + charidx * 6; by = textbase &  0xFFFFu;"
     "ox = bx + 5; oy = by + 7;"
     "finaldiv.z = (bx<<16)+(by&0xFFFF);}"
    "gl_Position = vec4(float(bx) / float(res.x) * 2.0 - 1.0, -float(by) / float(res.y) * 2.0 + 1.0, 0.0, 1.0); EmitVertex();"
    "gl_Position = vec4(float(bx) / float(res.x) * 2.0 - 1.0, -float(oy) / float(res.y) * 2.0 + 1.0, 0.0, 1.0); EmitVertex();"
    "gl_Position = vec4(float(ox) / float(res.x) * 2.0 - 1.0, -float(by) / float(res.y) * 2.0 + 1.0, 0.0, 1.0); EmitVertex();"
    "gl_Position = vec4(float(ox) / float(res.x) * 2.0 - 1.0, -float(oy) / float(res.y) * 2.0 + 1.0, 0.0, 1.0); EmitVertex();"
    "EndPrimitive();}";
 char* fragshaderstr =
  "#version 400\n"
  "out vec4 color;"
  "layout(origin_upper_left) in vec4 gl_FragCoord;"
  "flat in uvec4 finaldiv;"
  "flat in uint charidx;"
  "layout (std140) uniform colorblock { uvec4 colors[64]; };"
  "layout (std140) uniform charblock  { uvec4 chars[64]; };"
  "uniform usampler2D font;"
  "uniform uint textcolor;"
  "uniform uint rendertype;"
  "void main(){"
   "uint outline = finaldiv.x >> 24;"
   "uint color1  = finaldiv.y >> 16; uint color2  = finaldiv.y & 0xFF;"
   "uint basex   = finaldiv.z >> 16; uint basey   = finaldiv.z & 0xFFFF;"
   "uint offsetx = finaldiv.w >> 16; uint offsety = finaldiv.w & 0xFFFF;"
   "uint x = uint(gl_FragCoord.x - 0.5); uint y = uint(gl_FragCoord.y - 0.5);"
   "uint i1 = color1 / 4; uint o1 = uint(mod(color1, 4));"
   "uint i2 = color2 / 4; uint o2 = uint(mod(color2, 4));"
   "uint i3 = uint(float(textcolor) / 4); uint o3 = uint(mod(textcolor, 4));"
   "if      (rendertype == 0u || rendertype == 1u){"
    "float mr = (colors[i1][o1] >> 24 & 0xFFu) / 256.0; float mg = (colors[i1][o1] >> 16 & 0xFFu) / 256.0; float mb = (colors[i1][o1] >> 8  & 0xFFu) / 256.0; float ma = (colors[i1][o1] >> 0  & 0xFFu) / 256.0;"
    "float or = (colors[i2][o2] >> 24 & 0xFFu) / 256.0; float og = (colors[i2][o2] >> 16 & 0xFFu) / 256.0; float ob = (colors[i2][o2] >> 8  & 0xFFu) / 256.0; float oa = (colors[i2][o2] >> 0  & 0xFFu) / 256.0;"
    "if (x <= basex+outline-1 || y <= basey+outline-1 || x >= offsetx-outline || y >= offsety-outline) { color = vec4(or, og, ob, oa); }"
    "else { color = vec4(mr, mg, mb, ma); } }"
   "else if (rendertype == 2u){"
    "float tr = (colors[i3][o3] >> 24 & 0xFFu) / 256.0; float tg = (colors[i3][o3] >> 16 & 0xFFu) / 256.0; float tb = (colors[i3][o3] >> 8  & 0xFFu) / 256.0; float ta = (colors[i3][o3] >> 0  & 0xFFu) / 256.0;"
    "uint c1 = charidx / 16; uint c2 = uint(mod(charidx, 16) / 4); uint c3 = uint(mod(charidx, 4));"
    "uint char = chars[c1][c2] >> (8 * c3) & 0xFF;"
    "if (texelFetch(font, ivec2((x-basex)+char*5, y-basey), 0).r == 1u) { color = vec4(tr, tg, tb, ta); }"
    "else { discard; } } }";
int main(){
 #ifdef windows
  initgl();
  #endif
 //Window int
  glfwInit();
  window = glfwCreateWindow(1600, 900, "Div renderer", 0, 0);
  glfwMakeContextCurrent(window);
  glfwSetMouseButtonCallback(window, onmousedown);
  glfwSetCharCallback(window, ontextinput);
  glfwSetKeyCallback(window, onkeydown);
 //Shader init
  int result, size;
  program = glCreateProgram();
  uint vertshader = makeshader(0x8B31, &vertshaderstr), geomshader = makeshader(0x8DD9, &geomshaderstr), fragshader = makeshader(0x8B30, &fragshaderstr);
  glLinkProgram(program);
  glGetProgramiv(program, 0x8B82, &result); //0x8B82 is GL_LINK_STATUS
  if(result == 0) { glGetProgramInfoLog(program, 0xFFF, &size, buffer); write(1, buffer, size); done(); }
  glDetachShader(program, vertshader); glDetachShader(program, geomshader); glDetachShader(program, fragshader);
  glDeleteShader(vertshader); glDeleteShader(geomshader); glDeleteShader(fragshader);
  glUseProgram(program);
 //Uniforms
  divindex   = glGetUniformBlockIndex(program, "divblock");
  colorindex = glGetUniformBlockIndex(program, "colorblock");
  textindex  = glGetUniformBlockIndex(program, "charblock");
  udiv       = glGetUniformLocation(program, "udiv");
  res        = glGetUniformLocation(program, "res");
  font       = glGetUniformLocation(program, "font");
  rendertype = glGetUniformLocation(program, "rendertype");
  textbase   = glGetUniformLocation(program, "textbase");
  idxoffset  = glGetUniformLocation(program, "idxoffset");
  textcolor  = glGetUniformLocation(program, "textcolor");
 //Buffers
  //0x8A11 GL_UNIFORM_BUFFER, 0x88E8 GL_DYNAMIC_DRAW
  glGenVertexArrays(1, &vao);
  glGenBuffers(3, objs);
  glBindVertexArray(vao);
  glBindBuffer(0x8A11, objs[0]); glBufferData(0x8A11, 4096, 0, 0x88E8); glUniformBlockBinding(program, divindex, objs[0]);   glBindBufferBase(0x8A11, objs[0], objs[0]); //Divs
  glBindBuffer(0x8A11, objs[1]); glBufferData(0x8A11, 256,  0, 0x88E8); glUniformBlockBinding(program, colorindex, objs[1]); glBindBufferBase(0x8A11, objs[1], objs[1]); //Colors
  glBindBuffer(0x8A11, objs[2]); glBufferData(0x8A11, 1024, 0, 0x88E8); glUniformBlockBinding(program, textindex, objs[2]);  glBindBufferBase(0x8A11, objs[2], objs[2]); //Text
 //Textures
  glUniform1i(font, 0);
  uint textures[1];
  glGenTextures(1, textures);
  glActiveTexture(0x84C0);                 //GL_TEXTURE0
  glBindTexture(0x0DE1, textures[0]);      //GL_TEXTURE2D
  glTexParameteri(0x0DE1, 0x2800, 0x2600); //GL_TEXTURE_MAG_FILTER, GL_NEAREST
  glTexParameteri(0x0DE1, 0x2801, 0x2600); //GL_TEXTURE_MIN_FILTER, GL_NEAREST
  glTexParameteri(0x0DE1, 0x2802, 0x2901); //GL_TEXTURE_WRAP_S, GL_REPEAT
  glTexParameteri(0x0DE1, 0x2803, 0x2901); //GL_TEXTURE_WRAP_T, GL_REPEAT
  unsigned char font[] = {
   //?        ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?          ?                     !          "          #          $          %          &          '          (          )          *          +          ,          -          .          /          0          1          2          3          4          5          6          7          8          9          :          ;          <          =          >          ?          @          A          B          C          D          E          F          G          H          I          J          K          L          M          N          O           P         Q           R         S          T          U          V          W          X          Y          Z          [          \          ]          ^          _          `          a          b          c          d          e          f          g          h          i          j          k          l          m          n          o          p          q          r          s          t          u          v          w          x          y          z          {          |          }          ~          ?         
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 0,0,1,0,0, 1,1,0,0,1, 0,1,1,1,0, 1,0,0,0,0, 0,1,0,0,0, 1,0,0,0,0, 1,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 0,1,1,1,0, 0,1,1,0,0, 0,1,1,1,1, 1,1,1,1,0, 0,0,0,0,1, 1,1,1,1,1, 0,1,1,1,1, 1,1,1,1,1, 0,1,1,1,0, 0,1,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 0,0,0,0,0, 1,0,0,0,0, 0,1,1,1,0, 1,1,1,1,1, 0,1,1,1,0, 1,1,1,1,0, 0,1,1,1,1, 1,1,1,1,0, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1, 0,0,1,1,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,1, 1,1,1,0,0, 1,0,0,0,0, 1,1,1,0,0, 0,1,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 0,0,0,0,0, 0,0,1,1,1, 0,1,1,1,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 0,1,0,0,0, 0,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,1,0,1,0, 0,1,1,1,0, 1,1,0,1,0, 0,1,0,0,1, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 1,0,0,1,1, 0,0,1,0,0, 1,0,0,0,1, 0,0,0,0,1, 0,0,0,1,1, 1,0,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,1,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,1, 0,0,1,0,0, 0,0,0,0,1, 1,0,0,1,0, 1,0,0,0,0, 1,1,0,1,1, 1,1,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 0,1,0,1,0, 1,0,0,0,1, 0,0,0,0,1, 1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 1,0,1,0,0, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 0,0,0,0,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 1,0,1,0,0, 0,0,0,1,0, 0,1,0,0,1, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 1,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 1,0,1,0,1, 0,0,1,0,0, 0,0,0,1,0, 0,0,0,0,1, 0,0,1,0,1, 1,0,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 1,0,0,0,1, 1,0,0,0,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 1,1,1,1,1, 0,0,1,0,0, 0,0,0,1,0, 1,0,1,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,1, 0,0,1,0,0, 0,0,0,0,1, 1,0,1,0,0, 1,0,0,0,0, 1,1,0,1,0, 1,1,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 0,1,0,1,0, 1,0,0,0,1, 0,0,0,1,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,1,1,0, 1,0,0,0,0, 0,1,1,1,1, 0,0,0,0,1, 0,1,1,1,0, 0,1,1,1,0, 0,1,1,1,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,1,1,0, 0,1,0,1,0, 0,0,1,0,0, 0,1,0,1,0, 1,1,1,1,0, 0,1,1,1,0, 1,1,1,1,0, 0,1,1,1,1, 0,1,0,1,0, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,1,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,1, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 1,1,1,0,1, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,1,0,1,0, 0,1,1,1,0, 0,0,1,0,0, 0,0,1,1,0, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,0,0, 0,0,1,0,0, 1,0,1,0,1, 0,0,1,0,0, 0,0,1,0,0, 1,1,1,1,0, 0,1,0,0,1, 1,1,1,1,0, 1,1,1,1,0, 0,0,1,0,0, 1,1,1,1,1, 1,0,0,0,1, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,0,1,0, 0,0,1,0,0, 1,0,1,0,1, 1,1,1,1,1, 1,1,1,1,0, 1,0,0,0,0, 1,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,1,1,1, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 1,1,0,0,0, 1,0,0,0,0, 1,0,1,0,1, 1,0,1,0,1, 1,0,0,0,1, 1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 0,1,0,1,0, 1,0,1,0,1, 0,0,1,0,0, 0,1,0,1,0, 0,0,1,0,0, 1,0,0,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1,1,1,1,0, 1,0,0,0,0, 0,1,1,1,1, 1,0,0,0,1, 0,0,1,0,0, 1,0,0,0,0, 1,1,1,1,1, 0,1,1,0,0, 0,0,0,1,0, 0,1,1,0,0, 0,0,1,0,0, 1,0,1,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,1,0, 0,1,0,0,1, 0,1,1,0,1, 1,0,0,0,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,1,0,1, 0,1,0,1,0, 0,1,0,1,0, 0,0,0,1,0, 0,1,1,0,0, 0,0,1,0,0, 0,0,1,1,0, 1,0,1,1,1, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,1,0,1, 0,1,0,0,0, 1,1,0,1,1, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,0,0, 1,0,1,0,1, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,0,1, 1,1,1,1,1, 0,0,0,0,1, 1,0,0,0,1, 0,1,0,0,0, 1,0,0,0,1, 0,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 1,1,1,1,1, 0,0,1,0,0, 0,0,1,0,0, 1,0,1,1,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,1, 0,0,1,0,0, 1,0,0,0,1, 1,0,1,0,0, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,1,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,1,1,0,0, 0,0,0,0,1, 0,0,1,0,0, 1,0,0,0,1, 0,1,0,1,0, 1,1,0,1,1, 0,1,0,1,0, 0,1,0,1,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,1,1,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,1,1,1,0, 0,0,1,0,0, 0,1,1,1,0, 1,0,0,0,1, 0,0,1,0,0, 0,0,0,1,0, 0,1,1,0,0, 0,0,1,0,0, 1,0,1,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,0, 0,1,1,1,1, 0,1,0,0,0, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 0,1,0,1,0, 1,1,0,1,1, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,1,0, 0,1,1,1,0, 0,1,0,1,1, 1,0,0,1,0, 0,0,0,0,0, 1,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,0, 0,1,0,0,0, 1,1,0,0,1, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,0,1, 0,0,0,1,1, 0,0,0,0,1, 1,0,0,0,1, 0,1,0,0,0, 1,0,0,0,1, 0,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,1, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,1,0, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,1,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,1,0, 1,0,0,1,0, 0,0,0,0,1, 0,0,1,0,0, 1,0,0,0,1, 0,0,1,0,0, 1,1,0,1,1, 0,1,0,1,0, 0,0,1,0,0, 1,0,0,0,0, 1,0,0,0,0, 0,0,0,1,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 1,0,0,0,1, 1,0,0,0,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 0,0,1,0,0, 0,0,0,1,0, 0,1,0,1,0, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,0, 0,0,0,0,1, 0,1,0,0,0, 0,0,0,0,1, 0,0,1,0,0, 1,0,0,0,1, 0,1,0,1,0, 1,1,0,1,1, 0,1,0,1,0, 0,1,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0,
   0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,1,0,1,0, 0,0,1,0,0, 1,0,0,1,1, 0,1,1,1,1, 0,0,0,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 1,1,0,0,0, 1,0,0,0,0, 0,1,1,1,0, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,0, 0,0,0,1,1, 1,1,1,1,0, 1,1,1,1,0, 1,0,0,0,0, 0,1,1,1,0, 1,1,1,1,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,1, 0,0,0,0,0, 1,0,0,0,0, 0,0,1,0,0, 1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1, 0,1,1,1,1, 1,1,1,1,0, 1,1,1,1,1, 1,0,0,0,0, 1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1, 1,1,1,1,1, 1,0,0,0,1, 1,1,1,1,1, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,1, 1,0,0,0,0, 1,1,1,0,1, 1,0,0,0,1, 1,1,1,1,1, 0,0,1,0,0, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 0,0,1,0,0, 1,1,1,1,1, 1,1,1,0,0, 0,0,0,0,1, 1,1,1,0,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,0,0, 0,1,1,1,1, 1,1,1,1,0, 0,1,1,1,1, 0,1,1,1,1, 0,1,1,1,0, 0,0,1,0,0, 1,1,1,1,1, 1,0,0,0,1, 0,1,1,1,0, 0,1,1,0,0, 0,1,0,0,1, 0,1,1,1,0, 1,0,0,0,1, 1,0,0,0,1, 0,1,1,1,0, 1,0,0,0,0, 0,0,0,0,1, 0,1,0,0,0, 1,1,1,1,1, 0,0,1,1,0, 1,1,1,1,1, 0,0,1,0,0, 1,0,0,0,1, 1,0,0,0,1, 1,1,0,0,0, 1,1,1,1,1, 0,0,0,1,0, 0,0,1,0,0, 0,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0,};
  glTexImage2D(0x0DE1, 0, 0x8232, 128*5, 7, 0, 0x8D94, 0x1401, font); //0x8232 GL_R8UI, 0x8D94 GL_RED_INTEGER, 0x1401 GL_UNSIGNED_BYTE
 //State
  setdiv(0, 0x02000000, (0<<16)+1, (0<<16)+0,   (400<<16)+400);
  setdiv(1, 0x02000000, (2<<16)+3, (10<<16)+44, (160<<16)+16);
  setdiv(2, 0x00000100, (3<<16)+0, (12<<16)+48, (1<<16)+9);
  divcount = 3;
  setcolor(0, 0x202020FF);
  setcolor(1, 0x404040FF);
  setcolor(2, 0x606060FF);
  setcolor(3, 0x808080FF);
  setcolor(4, 0xA0A0A0FF);
  render();
  printf("%i\n", glGetError());
 while(!glfwWindowShouldClose(window)){
  glfwGetFramebufferSize(window, &width, &height);
  if (oldwidth != width || oldheight != height) { oldwidth = width; oldheight = height;  glViewport(0, 0, width, height); glUniform2ui(res, width, height); render(); }
  glfwPollEvents();}
  done();}
 int makeshader(int type, char** source){
  int result, size;
  uint shader = glCreateShader(type);
  glShaderSource(shader, 1, source, 0);
  glCompileShader(shader);
  glGetShaderiv(shader, 0x8B81, &result);
  if(result == 0) { glGetShaderInfoLog(shader, 0xFFF, &size, buffer); write(1, buffer, size); done(); }
  glAttachShader(program, shader);
  return shader;}
//Rendering
 void render(){
  glClear(0x4000); //0x4000 is GL_COLOR_BUFFER_BIT
  glUniform1ui(rendertype, 0);
  glUniform1ui(idxoffset, 0);
  glDrawArrays(0x0000, 0, divcount);
  drawtext((10<<16)+10,  2, "Example interface");
  drawtext((10<<16)+30,  2, "Example input");
  drawtext((14<<16)+48,  1, text1);
  glfwSwapBuffers(window);}
 void drawtext(uint location, uint color, char* str){
  int len; for (len = 0; str[len] != 0; len++){}
  glBindBuffer(0x8A11, objs[2]);
  glBufferSubData(0x8A11, 0, len, str);
  glUniform1ui(rendertype, 2);
  glUniform1ui(idxoffset, 0);
  glUniform1ui(textbase, location);
  glUniform1ui(textcolor, color);
  glDrawArrays(0x0000, 0, len);}
//Value setting
 void setdiv(int index, uint flags, uint colors, uint base, uint offset){
   divs[index*4+0] = flags;
   divs[index*4+1] = colors;
   divs[index*4+2] = base;
   divs[index*4+3] = offset;
   glBindBuffer(0x8A11, objs[0]);
   glBufferSubData(0x8A11, index*16, 16, divs+index*4);}
 void setcolor(int index, uint color){
  colors[index] = color;
  glBindBuffer(0x8A11, objs[1]);
  glBufferSubData(0x8A11, index*4, 4, colors+index);}
 void updatedivs(){
   glBindBuffer(0x8A11, objs[0]);
   glBufferSubData(0x8A11, 0, sizeof(divs) / 4, divs);}
 void updatecolors(){
  glBindBuffer(0x8A11, objs[1]);
  glBufferSubData(0x8A11, 0, sizeof(colors) / 4, colors);}
//Events
 void onmousedown(void* window, int button, int action, int mods){
  double mousexd, mouseyd;
  glfwGetCursorPos(window, &mousexd, &mouseyd);
  int mousex = (int)mousexd, mousey = (int)mouseyd;
  int pressed[16];
  for (int i = 0; i < divcount; i++){
   int basex, basey, offsetx, offsety;
   int flags = divs[i*4+0], base = divs[i*4+2], offs = divs[i*4+3];
   int bx = base >> 16, by = base &  0xFFFFu;
   int ox = offs >> 16, oy = offs &  0xFFFFu;
   if ((flags & 0x01u) != 0) { bx = width  - bx; }
   if ((flags & 0x02u) != 0) { by = height - by; }
   if ((flags & 0x10u) == 0) { if ((flags & 0x04u) != 0) { ox = bx-ox; } else { ox = bx+ox; } } else { if ((flags & 0x40u) != 0) { ox = width  - ox; } }
   if ((flags & 0x20u) == 0) { if ((flags & 0x08u) != 0) { oy = by-oy; } else { oy = by+oy; } } else { if ((flags & 0x80u) != 0) { oy = height - oy; } }
   if (bx < ox) { basex = bx; offsetx = ox; } else { basex = ox; offsetx = bx; }
   if (by < oy) { basey = by; offsety = oy; } else { basey = oy; offsety = by; }
   if (button == 0 && action == 1){
    if (mousex > basex && mousex < offsetx && mousey > basey && mousey < offsety) { pressed[i] = 1; }
    else { pressed[i] = 0; } } }
  if (button == 0 && action == 1){
   if (pressed[1] == 1) { focusedbox = 1; setdiv(2, 0x00000000, (3<<16)+0, ((15+text1len*6)<<16)+48, (1<<16)+9); } else { setdiv(2, 0x00000100, (3<<16)+0, (12<<16)+48, (1<<16)+9); focusedbox = -1; } 
   render();} }
 void ontextinput(void* window, uint codepoint){
  if (codepoint > 256) { return; }
  if (focusedbox == 1 && text1len < 24){
   text1[text1len] = (char)codepoint;
   text1len++;
   setdiv(2, 0x00000000, (3<<16)+0, ((15+text1len*6)<<16)+48, (1<<16)+9);}
  render();}
 void onkeydown(void* window, int key, int scancode, int action, int mods) {
  if (key == 259 && text1len > 0 && focusedbox == 1 && (action == 1 || action == 2)) { text1len--; text1[text1len] = 0; setdiv(2, 0x00000000, (3<<16)+0, ((15+text1len*6)<<16)+48, (1<<16)+9); render(); } }
 void done() { exit(0); }