#include "todo.h"

char *get_id(todo t)
{
	return t.id;
}

void set_id(todo *t, char *id_in)
{
	int len = strlen(id_in);
	t->id = (char *)malloc(sizeof(len + 1));
	strncpy(t->id, id_in, len);
}

char *get_title(todo t)
{
	return t.title;
}

void set_title(todo *t, char *title_in)
{
	int len = strlen(title_in);
	t->title = (char *)malloc(sizeof(len +1));
	strncpy(t->title, title_in, len);
}

char *get_content(todo t)
{
	return t.content;
}

void set_content(todo *t, char *content_in)
{
	int len = strlen(content_in);
	t->content = (char *)malloc(sizeof(len + 1));
	strncpy(t->content, content_in, len);
}

bool get_is_done(todo t)
{
	return t.is_done;
}

void set_is_done(todo *t, bool is_done_in)
{
	t->is_done = is_done_in;
}

long get_create_at(todo t)
{
	return t.create_at;
}

void set_create_at(todo *t, long create_at_in)
{
	t->create_at = create_at_in;
}
