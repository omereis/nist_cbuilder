#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <CONIO.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
//-----------------------------------------------------------------------------
#include "common.h"
#include <assert.h>
//-----------------------------------------------------------------------------
enum print_options {
	SKIP = 1,
	VERBOSE = 2,
	UPDATE = 4,
};
//-----------------------------------------------------------------------------
struct print_payload {
	enum print_options options;
	git_repository *repo;
};
//-----------------------------------------------------------------------------
static void parse_opts(int *options, int *count, int argc, char *argv[]);
void init_array(git_strarray *array, int argc, char **argv);
int print_matched_cb(const char *path, const char *matched_pathspec, void *payload);
//-----------------------------------------------------------------------------
void print_usage(void)
{
	fprintf(stderr, "usage: add [options] [--] file-spec [file-spec] [...]\n\n");
	fprintf(stderr, "\t-n, --dry-run    dry run\n");
	fprintf(stderr, "\t-v, --verbose    be verbose\n");
	fprintf(stderr, "\t-u, --update     update tracked files\n");
	exit(1);
}
//-----------------------------------------------------------------------------
static void parse_opts(int *options, int *count, int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; ++i) {
		if (argv[i][0] != '-') {
			break;
		}
		else if(!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v")) {
			*options |= VERBOSE;
		}
		else if(!strcmp(argv[i], "--dry-run") || !strcmp(argv[i], "-n")) {
			*options |= SKIP;
		}
		else if(!strcmp(argv[i], "--update") || !strcmp(argv[i], "-u")) {
			*options |= UPDATE;
		}
		else if(!strcmp(argv[i], "-h")) {
			print_usage();
			break;
		}
		else if(!strcmp(argv[i], "--")) {
			i++;
			break;
		}
		else {
			fprintf(stderr, "Unsupported option %s.\n", argv[i]);
			print_usage();
		}
	}

	if (argc<=i)
		print_usage();

	*count = i;
}
//-----------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Hello, world!\n");
	git_index_matched_path_cb matched_cb = NULL;
	git_repository *repo = NULL;
	git_index *index;
	git_strarray array = {0};
	int options = 0, count = 0;
	struct print_payload payload = {0};
	printf("Ready to init Git\n");
	getch ();
	git_libgit2_init();
	printf("Git Initialiazed\n");
	git_libgit2_shutdown();
	printf("Git Shutdown\n");
	getch ();
}
