#!/bin/sh
#
# getopt.sh: utiliza o programa getopt para interpretar os argumentos de linha
#            de comando
#
# Para utilizar:
# ./getopt.sh
#

help()
{
cat << EOF
getopt.sh v0.1
use: $0 [OPÇÃO]

OPÇÕES:
    -d            imprime data e hora do sistema
    -c            imprime caracteristicas da CPU
    -h            imprime esta tela
    -u            imprime versão do sistema operacional
    -e ARQUIVO    abre o editor de texto em ARQUIVO
    -l ARQUIVO    mostra informações de ARQUIVO [via stat]
EOF
}

# Caso não haja argumento na linha de comando, imprime o help
[ ! "$1" ] && help

# Caso haja interpreta cada um
while getopts "e:l:dchu" OPT; do
    case $OPT in
        d)
            date
            ;;

        c)
            cat /proc/cpuinfo
            ;;

        u)
            uname -a
            ;;
        e)
            [ ! "$EDITOR" ] && EDITOR=vi
            $EDITOR $OPTARG
            ;;

        l)
            ls -l $OPTARG
            ;;

        *)
            help
    esac
done
shift $[OPTIND-1]
