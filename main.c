#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <json.h>
#include "todo.h"

todo *rtff(char *);
void json_set_todo(todo *, char *);
void print_todo(todo *t);

int main(void)
{
	// rtff = read todo from file
	todo *t = rtff("4bb99e38-52eb-4c3c-8dd7-a4b868a9748f");
	
	return 0;
}

todo *rtff(char *id)
{
	int fd;
	char buf[64] = "\0";
	char rbuf[256] = "\0";

	todo *t = (todo *)malloc(sizeof(todo));

	sprintf(buf, "%s.json", id);
	printf("buf = %s\n", buf);

	fd = open(buf, O_EXCL);

	read(fd, rbuf, sizeof(rbuf));
	json_set_todo(t, rbuf);

	printf("********************************\n");
	printf("After JSON Parsing\n");
	printf("********************************\n");
	print_todo(t);

	return t;
}

void print_todo(todo *t)
{
	printf("id = %s\n", t->id);
	printf("title = %s\n", t->title);
	printf("content = %s\n", t->content);
	printf("is_done = %s\n", t->is_done ? "true" : "false");
	printf("create_at = %ld\n", t->create_at);
}

void chk_todo_key_val(todo *t, char *key, const char *val)
{
	int len = strlen(val);

	if(!strncmp("id", key, len))
	{
		t->id = (char *)malloc(len + 1);
		strncpy(t->id, val, len);
	}
	else if(!strncmp("title", key, len))
	{
		t->title = (char *)malloc(len + 1);
		strncpy(t->title, val, len);
	}
	else if(!strncmp("content", key, len))
	{
		t->content = (char *)malloc(len + 1);
		strncpy(t->content, val, len);
	}
}

void json_set_todo(todo *t, char *buf)
{
	enum json_type type;
	json_object *jobj = json_tokener_parse(buf);

	json_object_object_foreach(jobj, key, val)
	{
		type = json_object_get_type(val);
		printf("type = ");

		switch(type)
		{
			case json_type_null:
				printf("json_type_null\n");
				break;
			case json_type_boolean:
				printf("json_type_bool\n");
				printf("key = %-15s : value = %s\n",
					key, json_object_get_boolean(val) ? "true" : "false");
				break;
			case json_type_double:
				printf("json_type_double\n");
				printf("key = %-15s : value = %lf\n", key, json_object_get_double(val));
				break;
			case json_type_int:
				printf("json_type_int\n");
				printf("key = %-15s : value = %d\n", key, json_object_get_int(val));
				t->create_at = json_object_get_int(val);
				break;
			case json_type_object:
				printf("json_type_object\n");
				printf("key = %-15s : value\n", key);
				break;
			case json_type_array:
				printf("json_type_array\n");
				printf("key = %-15s : value\n", key);
				break;
			case json_type_string:
				printf("json_type_string\n");
				printf("key = %-15s : value = %s\n", key, json_object_get_string(val));
				chk_todo_key_val(t, key, json_object_get_string(val));
				break;
		}
	}
}
