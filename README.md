# vmod-jsonparser

## USAGE

In your VCL you could then use this vmod along the following lines:

    import jsonparser;

    sub vcl_deliver {
            set resp.http.hello = jsonparser.parseJson("user",{" { "user" : "osakech" , "role" : "admin" } "});
            # resp.http.hello -> is set to "osakech"
    }

## DESCRIPTION

jsonparser is a simple json parser for varnish that can do only one
thing: get you the value for your specified key out of a jsonstring. It
has ony one function \"jsonparse\" (which should probably be renamed to
getValue) , no bells and whistless whatsover.

It should also not be used for any production systems at this stage,
unless you know what you\'re doing and you have red and understood the
code and agree with what i am doing.

No memory or cpu profilling has been done, so I don\'t know how it
handles big json strings or if does it very efficiently. This module has
a very narrow and specific use case, without a lot of unknowns.

In other words, I just wanted to put it out there and slowly improve it.
:-)

## FUNCTIONS

parseJson

    parseJson(STRING key,STRING jsonString)

Return value

    STRING

Description

Parses the JSON string jsonString and returns the value associated
    to the key.

## INSTALLATION

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the `varnishtest` tool.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Usage:

    ./autogen.sh
    ./configure

If you have installed Varnish to a non-standard directory, call
`autogen.sh` and `configure` with `PKG_CONFIG_PATH` pointing to the
appropriate path. For instance, when varnishd configure was called with
`--prefix=$PREFIX`, use

    export PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
    export ACLOCAL_PATH=${PREFIX}/share/aclocal

The module will inherit its prefix from Varnish, unless you specify a
different `--prefix` when running the `configure` script for this
module.

Make targets:

-   make - builds the vmod.
-   make install - installs your vmod.
-   make check - runs the unit tests in `src/tests/*.vtc`.
-   make distcheck - run check and prepare a tarball of the vmod.

If you build a dist tarball, you don\'t need any of the autotools or
pkg-config. You can build the module simply by running:

    ./configure
    make

### Installation directories


By default, the vmod `configure` script installs the built vmod in the
directory relevant to the prefix. The vmod installation directory can be
overridden by passing the `vmoddir` variable to `make install`.

## COMMON PROBLEMS

-   configure: error: Need varnish.m4 \-- see README.rst

    Check whether `PKG_CONFIG_PATH` and `ACLOCAL_PATH` were set
    correctly before calling `autogen.sh` and `configure`
