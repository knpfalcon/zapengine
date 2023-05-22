#ifndef SCENE_H
#define SCENE_H

#define SCENE_NAME_MAX 32

typedef struct s_scene
{
    char *name;
    void(*init)(void);
    void(*update)(void);
    void(*draw)(void);
    void(*destroy)(void);
    void(*on_key_down)(int keycode);
    void(*on_key_up)(int keycode);
}t_scene;

void change_scene(t_scene next_scene);

#endif