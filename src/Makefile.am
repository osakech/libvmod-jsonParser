AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS)

vmod_LTLIBRARIES = libvmod_jsonparser.la

libvmod_jsonparser_la_SOURCES = \
	vmod_jsonparser.c \
	cJSON.c

nodist_libvmod_jsonparser_la_SOURCES = \
	vcc_jsonparser_if.c \
	vcc_jsonparser_if.h

dist_man_MANS = vmod_jsonparser.3

@BUILD_VMOD_JSONPARSER@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_jsonparser="$(VMOD_JSONPARSER)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_jsonparser.vcc \
	$(VMOD_TESTS)
