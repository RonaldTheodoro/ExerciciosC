#
# configure.ac: Utilizado por aclocal, automake e autoconf para gerar o script
#               configure
#
# Para utilizar:
#	automake
#

AC_INIT(pr2.h)
#AC_ARG_PROGRAM
#AC_PROG_INSTALL
AM_INIT_AUTOMAKE(pr2, 0.1)

dnl Checa o hostname e outras informações
AC_CANONICAL_HOST

dnl Checa alguns programas
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
#AC_CHECK_TOOL(AR, ar)
#AC_CHECK_TOOL(RANLIB, ranlib, :)

#dnl inicializa libtool
#AM_PROG_LIBTOOL

dnl Checa os arquivos de cabeçalho
AC_STDC_HEADERS

dnl Gera Makefile
AC_OUTPUT(Makefile)