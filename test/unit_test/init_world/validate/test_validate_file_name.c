#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "syscall_mock.h"
#include "util_rt.h"

int	validate_file_name(const char *argv_one);

int	test_validate_file_name(void)
{
	fprintf(stderr, "\n===== test_validate_file_name =====\n");
	alarm(2);
	{
		fprintf(stderr, "--- normal case ---\n");
		assert(validate_file_name("test.rt") == SUCCESS);
		assert(validate_file_name("a.rt") == SUCCESS);
		assert(validate_file_name(" .rt") == SUCCESS);
		assert(validate_file_name("テストテスト.rt") == SUCCESS);
		assert(validate_file_name("a..rt") == SUCCESS);
		assert(validate_file_name("a.txt.rt") == SUCCESS);
	}
	return (0);
}
