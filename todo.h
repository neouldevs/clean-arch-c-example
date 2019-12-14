#ifndef __TODO_H__
#define __TODO_H__

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _todo todo;

struct _todo {
        char *id;
        char *title;
        char *content;
        bool is_done;
        long create_at;
};

char *get_id(todo t);
void set_id(todo *t, char *id_in);
char *get_title(todo t);
void set_title(todo *t, char *title_in);
char *get_content(todo t);
void set_content(todo *t, char *content_in);
bool get_is_done(todo t);
void set_is_done(todo *t, bool is_done_in);
long get_create_at(todo t);
void set_create_at(todo *t, long create_at_in);

#endif
