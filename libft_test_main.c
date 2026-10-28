#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static int fails = 0;
#define CHECK(cond, name) do { if (!(cond)) { printf("FAIL: %s\n", name); fails++; } } while (0)
#define SIGN(x) ((x) > 0) - ((x) < 0)

static char up(unsigned int i, char c) { (void)i; return (char)toupper(c); }
static char idx(unsigned int i, char c) { (void)c; return (char)('a' + i); }
static void inc(unsigned int i, char *c) { (void)i; *c += 1; }
static void *dupint(void *p) { int *n = malloc(sizeof(int)); *n = *(int *)p * 2; return n; }
static void sum(void *p) { extern int g_sum; g_sum += *(int *)p; }
int g_sum = 0;

int main(void)
{
	/* ctype */
	for (int c = -1; c < 256; c++)
	{
		CHECK(!ft_isalpha(c) == !isalpha(c) || c < 0, "isalpha");
		CHECK(!ft_isdigit(c) == !isdigit(c) || c < 0, "isdigit");
		CHECK(!ft_isalnum(c) == !isalnum(c) || c < 0, "isalnum");
		CHECK(!ft_isprint(c) == !isprint(c) || c < 0, "isprint");
		CHECK(!ft_isascii(c) == !isascii(c), "isascii");
		if (c >= 0) {
			CHECK(ft_toupper(c) == toupper(c), "toupper");
			CHECK(ft_tolower(c) == tolower(c), "tolower");
		}
	}
	/* strlen / memset / bzero */
	CHECK(ft_strlen("") == 0 && ft_strlen("hello") == 5, "strlen");
	char a[20], b[20];
	memset(a, 'x', 20); memset(b, 'x', 20);
	ft_memset(a, 'z', 7); memset(b, 'z', 7);
	CHECK(!memcmp(a, b, 20), "memset");
	ft_bzero(a, 5); bzero(b, 5);
	CHECK(!memcmp(a, b, 20), "bzero");
	/* memcpy / memmove (overlap both directions) */
	char m1[30] = "abcdefghijklmnopqrstuvwxyz", m2[30] = "abcdefghijklmnopqrstuvwxyz";
	ft_memmove(m1 + 3, m1, 10); memmove(m2 + 3, m2, 10);
	CHECK(!memcmp(m1, m2, 30), "memmove fwd-overlap");
	ft_memmove(m1, m1 + 5, 10); memmove(m2, m2 + 5, 10);
	CHECK(!memcmp(m1, m2, 30), "memmove back-overlap");
	char c1[10] = {0}, c2[10] = {0};
	ft_memcpy(c1, "123456789", 10); memcpy(c2, "123456789", 10);
	CHECK(!memcmp(c1, c2, 10), "memcpy");
	/* strlcpy / strlcat (BSD semantics, reference computed by hand) */
	char d[10];
	CHECK(ft_strlcpy(d, "hello", 10) == 5 && !strcmp(d, "hello"), "strlcpy fits");
	CHECK(ft_strlcpy(d, "hello world!", 5) == 12 && !strcmp(d, "hell"), "strlcpy trunc");
	CHECK(ft_strlcpy(d, "abc", 0) == 3, "strlcpy size0");
	strcpy(d, "ab");
	CHECK(ft_strlcat(d, "cdef", 10) == 6 && !strcmp(d, "abcdef"), "strlcat fits");
	strcpy(d, "ab");
	CHECK(ft_strlcat(d, "cdefghijkl", 6) == 12 && !strcmp(d, "abcde"), "strlcat trunc");
	strcpy(d, "abcdef");
	CHECK(ft_strlcat(d, "xy", 3) == 5, "strlcat size<dlen");
	/* strchr / strrchr / strncmp */
	const char *s = "hello world";
	CHECK(ft_strchr(s, 'o') == strchr(s, 'o'), "strchr");
	CHECK(ft_strchr(s, 0) == strchr(s, 0), "strchr nul");
	CHECK(ft_strchr(s, 'z') == NULL, "strchr none");
	CHECK(ft_strrchr(s, 'o') == strrchr(s, 'o'), "strrchr");
	CHECK(ft_strrchr(s, 0) == strrchr(s, 0), "strrchr nul");
	CHECK(SIGN(ft_strncmp("abc", "abd", 3)) == SIGN(strncmp("abc", "abd", 3)), "strncmp");
	CHECK(ft_strncmp("abc", "abd", 2) == 0, "strncmp n");
	CHECK(SIGN(ft_strncmp("a\200", "a\100", 2)) == SIGN(strncmp("a\200", "a\100", 2)), "strncmp unsigned");
	/* memchr / memcmp */
	CHECK(ft_memchr(s, 'w', 11) == memchr(s, 'w', 11), "memchr");
	CHECK(ft_memchr(s, 'w', 3) == NULL, "memchr limit");
	CHECK(SIGN(ft_memcmp("abc", "abd", 3)) == SIGN(memcmp("abc", "abd", 3)), "memcmp");
	CHECK(ft_memcmp("a", "b", 0) == 0, "memcmp 0");
	/* strnstr */
	CHECK(ft_strnstr("lorem ipsum dolor", "ipsum", 17) != NULL, "strnstr find");
	CHECK(ft_strnstr("lorem ipsum dolor", "ipsum", 8) == NULL, "strnstr limit");
	CHECK(ft_strnstr("abc", "", 0) != NULL, "strnstr empty");
	CHECK(ft_strnstr("", "a", 5) == NULL, "strnstr empty hay");
	/* atoi */
	const char *tests[] = {"42", "  -42", "+7", "  \t\n12abc", "abc", "", "2147483647", "-2147483648", "--5", NULL};
	for (int i = 0; tests[i]; i++)
		CHECK(ft_atoi(tests[i]) == atoi(tests[i]), "atoi");
	/* calloc / strdup */
	int *z = ft_calloc(10, sizeof(int));
	int allz = 1; for (int i = 0; i < 10; i++) allz &= (z[i] == 0);
	CHECK(allz, "calloc zero"); free(z);
	CHECK(ft_calloc((size_t)-1, 2) == NULL, "calloc overflow");
	char *dd = ft_strdup("copy me"); CHECK(!strcmp(dd, "copy me"), "strdup"); free(dd);
	/* substr */
	char *r = ft_substr("hello world", 6, 5); CHECK(!strcmp(r, "world"), "substr"); free(r);
	r = ft_substr("hello", 10, 5); CHECK(r && !strcmp(r, ""), "substr start>len"); free(r);
	r = ft_substr("hello", 1, 100); CHECK(!strcmp(r, "ello"), "substr clamp"); free(r);
	/* strjoin / strtrim */
	r = ft_strjoin("foo", "bar"); CHECK(!strcmp(r, "foobar"), "strjoin"); free(r);
	r = ft_strjoin("", ""); CHECK(!strcmp(r, ""), "strjoin empty"); free(r);
	r = ft_strtrim("  \t hi there \t ", " \t"); CHECK(!strcmp(r, "hi there"), "strtrim"); free(r);
	r = ft_strtrim("xxxx", "x"); CHECK(!strcmp(r, ""), "strtrim all"); free(r);
	r = ft_strtrim("abc", ""); CHECK(!strcmp(r, "abc"), "strtrim empty set"); free(r);
	/* split */
	char **sp = ft_split("  a bb  ccc ", ' ');
	CHECK(!strcmp(sp[0], "a") && !strcmp(sp[1], "bb") && !strcmp(sp[2], "ccc") && sp[3] == NULL, "split");
	for (int i = 0; sp[i]; i++) free(sp[i]); free(sp);
	sp = ft_split("", ' '); CHECK(sp && sp[0] == NULL, "split empty"); free(sp);
	sp = ft_split("nodelim", ','); CHECK(!strcmp(sp[0], "nodelim") && !sp[1], "split nodelim"); free(sp[0]); free(sp);
	/* itoa */
	int vals[] = {0, 5, -5, 42, -42, 1000, INT_MAX, INT_MIN};
	for (int i = 0; i < 8; i++) {
		char exp[20]; sprintf(exp, "%d", vals[i]);
		r = ft_itoa(vals[i]); CHECK(!strcmp(r, exp), "itoa"); free(r);
	}
	/* strmapi / striteri */
	r = ft_strmapi("abc", up); CHECK(!strcmp(r, "ABC"), "strmapi"); free(r);
	r = ft_strmapi("zzz", idx); CHECK(!strcmp(r, "abc"), "strmapi idx"); free(r);
	char it[] = "abc"; ft_striteri(it, inc); CHECK(!strcmp(it, "bcd"), "striteri");
	/* put*_fd -> write into a temp file and read back */
	int fd = open("/tmp/work/out.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	ft_putchar_fd('A', fd); ft_putstr_fd("bc", fd); ft_putendl_fd("d", fd);
	ft_putnbr_fd(-2147483648, fd); ft_putnbr_fd(0, fd); ft_putnbr_fd(305, fd);
	lseek(fd, 0, SEEK_SET);
	char buf[100] = {0}; read(fd, buf, 99); close(fd);
	CHECK(!strcmp(buf, "Abcd\n-21474836480305"), "put*_fd");
	/* lists (bonus) */
	t_list *l = NULL;
	for (int i = 1; i <= 3; i++) { int *p = malloc(sizeof(int)); *p = i; ft_lstadd_back(&l, ft_lstnew(p)); }
	int *f = malloc(sizeof(int)); *f = 0; ft_lstadd_front(&l, ft_lstnew(f));
	CHECK(ft_lstsize(l) == 4, "lstsize");
	CHECK(*(int *)ft_lstlast(l)->content == 3, "lstlast");
	ft_lstiter(l, sum); CHECK(g_sum == 6, "lstiter");
	t_list *m = ft_lstmap(l, dupint, free);
	g_sum = 0; ft_lstiter(m, sum); CHECK(g_sum == 12, "lstmap");
	ft_lstclear(&l, free); CHECK(l == NULL, "lstclear");
	ft_lstclear(&m, free);
	t_list *one = ft_lstnew(strdup("x")); ft_lstdelone(one, free);

	printf(fails ? "\n%d test(s) FAILED\n" : "ALL TESTS PASSED\n", fails);
	return fails != 0;
}
