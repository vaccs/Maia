
#include <debug.h>

#include <quack/new.h>
#include <quack/append.h>
#include <quack/pop.h>
#include <quack/is_nonempty.h>
#include <quack/free.h>

#include <misc/break_and_open_path.h>

#include "skip.h"
#include "parser.h"
#include "driver.h"

struct file_descriptor
{
	int fd;
	unsigned refcount;
};

static struct file_descriptor* new_file_descriptor(int fd)
{
	ENTER;
	
	dpv(fd);
	
	struct file_descriptor* this = smalloc(sizeof(*this));
	
	this->fd = fd;
	this->refcount = 1;
	
	EXIT;
	return this;
}

static struct file_descriptor* inc_file_descriptor(struct file_descriptor* this)
{
	this->refcount++;
	return this;
}

static void free_file_descriptor(struct file_descriptor* this)
{
	ENTER;
	
	if (!--this->refcount)
	{
		TODO;
	}
	else
	{
		dpv(this->refcount);
	}
	
	EXIT;
}

struct file_info
{
	int fd;
	
	dev_t st_dev;
	ino_t st_ino;
	
	struct file_descriptor *abs_dirfd, *rel_dirfd;
};

static struct file_info* new_file_info(
	int fd,
	struct file_descriptor *abs_dirfd,
	struct file_descriptor *rel_dirfd)
{
	ENTER;
	
	struct file_info* this = smalloc(sizeof(*this));
	
	dpv(fd);
	
	this->fd = fd;
	
	this->abs_dirfd = inc_file_descriptor(abs_dirfd);
	this->rel_dirfd = inc_file_descriptor(rel_dirfd);
	
	EXIT;
	return this;
}

static int compare(const void* a, const void* b)
{
	TODO;
}

void parse_driver(const char* input_path)
{
	ENTER;
	
	dpvs(input_path);
	
	struct quack* todo = new_quack();
	
	struct avl_tree_t* queued = avl_alloc_tree(compare, free);
	
	// setup:
	{
		struct br_rettype bun = break_and_open_path(AT_FDCWD, input_path);
		
		struct file_descriptor* des = new_file_descriptor(bun.dirfd);
		
		struct file_info* info = new_file_info(bun.fd, des, des);
		
		avl_insert(queued, info);
		
		quack_append(todo, info);
		
		free_file_descriptor(des);
	}
	
	while (quack_is_nonempty(todo))
	{
		struct file_info* info = quack_pop(todo);
		
		dpv(info->fd);
		
		FILE* stream = fdopen(info->fd, "r");
		
		struct zebu_$start* start = zebu_parse(stream);
		
		for (unsigned i = 0, n = start->root->entries.n; i < n; i++)
		{
			struct zebu_entry* entry = start->root->entries.data[i];
			
			if (entry->using)
			{
				TODO;
			}
			else if (entry->skip)
			{
				process_skip(entry);
			}
			else if (entry->start)
			{
				TODO;
			}
			else if (entry->grammar)
			{
				TODO;
			}
			else if (entry->expression)
			{
				TODO;
			}
			else if (entry->assertion)
			{
				// maybe 'debug', 'note', 'warning', 'error'
				TODO;
			}
			else
			{
				TODO;
			}
		}
		
		TODO;
		
		free_zebu_$start_ptree(start);
		
		fclose(stream);
		
		free_file_descriptor(info->abs_dirfd);
		free_file_descriptor(info->rel_dirfd);
	}
	
	avl_free_tree(queued);
	
	free_quack(todo);
	
	EXIT;
}


















