/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 30 "core/cfg.y"


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include "route_struct.h"
#include "globals.h"
#include "shm_init.h"
#include "route.h"
#include "switch.h"
#include "dprint.h"
#include "sr_module.h"
#include "modparam.h"
#include "ip_addr.h"
#include "resolve.h"
#include "socket_info.h"
#include "name_alias.h"
#include "ut.h"
#include "dset.h"
#include "select.h"
#include "flags.h"
#include "tcp_init.h"
#include "tcp_options.h"
#include "sctp_core.h"
#include "pvar.h"
#include "lvalue.h"
#include "rvalue.h"
#include "sr_compat.h"
#include "msg_translator.h"
#include "async_task.h"

#include "kemi.h"
#include "ppcfg.h"
#include "pvapi.h"
#include "config.h"
#include "daemonize.h"
#include "cfg_core.h"
#include "cfg/cfg.h"
#ifdef CORE_TLS
#include "tls/tls_config.h"
#endif
#include "timer_ticks.h"

#ifdef DEBUG_DMALLOC
#include <dmalloc.h>
#endif

/* hack to avoid alloca usage in the generated C file (needed for compiler
 with no built in alloca, like icc*/
#undef _ALLOCA_H

#define onsend_check(s) \
	do{\
		if (rt!=ONSEND_ROUTE) yyerror( s " allowed only in onsend_routes");\
	}while(0)

	#define IF_AUTO_BIND_IPV6(x) x

#ifdef USE_DNS_CACHE
	#define IF_DNS_CACHE(x) x
#else
	#define IF_DNS_CACHE(x) warn("dns cache support not compiled in")
#endif

#ifdef USE_DNS_FAILOVER
	#define IF_DNS_FAILOVER(x) x
#else
	#define IF_DNS_FAILOVER(x) warn("dns failover support not compiled in")
#endif

#ifdef USE_NAPTR
	#define IF_NAPTR(x) x
#else
	#define IF_NAPTR(x) warn("dns naptr support not compiled in")
#endif

#ifdef USE_DST_BLOCKLIST
	#define IF_DST_BLOCKLIST(x) x
#else
	#define IF_DST_BLOCKLIST(x) warn("dst blocklist support not compiled in")
#endif

#ifdef USE_SCTP
	#define IF_SCTP(x) x
#else
	#define IF_SCTP(x) warn("sctp support not compiled in")
#endif

#ifdef USE_RAW_SOCKS
	#define IF_RAW_SOCKS(x) x
#else
	#define IF_RAW_SOCKS(x) warn("raw socket support not compiled in")
#endif


extern int yylex();
/* safer than using yytext which can be array or pointer */
extern char* yy_number_str;

static void yyerror(char* s, ...);
static void yyerror_at(struct cfg_pos* pos, char* s, ...);
static char* tmp = NULL;
static int i_tmp = 0;
static struct socket_id* lst_tmp = NULL;
static struct name_lst* nl_tmp = NULL;
static int rt = 0;  /* Type of route block for find_export */
static str* str_tmp = NULL;
static str s_tmp = STR_NULL;
static struct ip_addr* ip_tmp = NULL;
static struct avp_spec* s_attr = NULL;
static select_t sel;
static select_t* sel_ptr = NULL;
static pv_spec_t* pv_spec = NULL;
static struct action *mod_func_action = NULL;
static struct lvalue* lval_tmp = NULL;
static struct rvalue* rval_tmp = NULL;
static struct rval_expr* rve_tmp = NULL;
static socket_attrs_t tmp_sa;

static void warn(char* s, ...);
static void warn_at(struct cfg_pos* pos, char* s, ...);
static void get_cpos(struct cfg_pos* pos);
static struct rval_expr* mk_rve_rval(enum rval_type, void* v);
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1);
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2);
static int rval_expr_int_check(struct rval_expr *rve);
static int warn_ct_rve(struct rval_expr *rve, char* name);
static struct socket_id* mk_listen_id(char*, int, int);
static struct name_lst* mk_name_lst(char* name, int flags);
static struct socket_id* mk_listen_id2(struct name_lst*, int, int);
static void free_name_lst(struct name_lst* lst);
static void free_socket_id_lst(struct socket_id* i);

static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re,
									struct action* a, int* err);
static int case_check_type(struct case_stms* stms);
static int case_check_default(struct case_stms* stms);
static int mod_f_params_pre_fixup(struct action* a);
static void free_mod_func_action(struct action* a);


extern int line;
extern int column;
extern int startcolumn;
extern int startline;
extern char *finame;
extern char *routename;
extern char *default_routename;

#define set_cfg_pos(x) \
	do{\
		if(x) {\
		(x)->cline = line;\
		(x)->cfile = (finame!=0)?finame:((cfg_file!=0)?cfg_file:"default");\
		(x)->rname = (routename!=0)?routename:((default_routename!=0)?default_routename:"DEFAULT");\
		}\
	}while(0)



#line 240 "core/cfg.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cfg.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FORWARD = 3,                    /* FORWARD  */
  YYSYMBOL_FORWARD_TCP = 4,                /* FORWARD_TCP  */
  YYSYMBOL_FORWARD_TLS = 5,                /* FORWARD_TLS  */
  YYSYMBOL_FORWARD_SCTP = 6,               /* FORWARD_SCTP  */
  YYSYMBOL_FORWARD_UDP = 7,                /* FORWARD_UDP  */
  YYSYMBOL_EXIT = 8,                       /* EXIT  */
  YYSYMBOL_DROP = 9,                       /* DROP  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_RETURN_MODE = 11,               /* RETURN_MODE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_LOG_TOK = 13,                   /* LOG_TOK  */
  YYSYMBOL_ERROR = 14,                     /* ERROR  */
  YYSYMBOL_ROUTE = 15,                     /* ROUTE  */
  YYSYMBOL_ROUTE_REQUEST = 16,             /* ROUTE_REQUEST  */
  YYSYMBOL_ROUTE_FAILURE = 17,             /* ROUTE_FAILURE  */
  YYSYMBOL_ROUTE_ONREPLY = 18,             /* ROUTE_ONREPLY  */
  YYSYMBOL_ROUTE_REPLY = 19,               /* ROUTE_REPLY  */
  YYSYMBOL_ROUTE_BRANCH = 20,              /* ROUTE_BRANCH  */
  YYSYMBOL_ROUTE_SEND = 21,                /* ROUTE_SEND  */
  YYSYMBOL_ROUTE_EVENT = 22,               /* ROUTE_EVENT  */
  YYSYMBOL_EXEC = 23,                      /* EXEC  */
  YYSYMBOL_SET_HOST = 24,                  /* SET_HOST  */
  YYSYMBOL_SET_HOSTPORT = 25,              /* SET_HOSTPORT  */
  YYSYMBOL_SET_HOSTPORTTRANS = 26,         /* SET_HOSTPORTTRANS  */
  YYSYMBOL_PREFIX = 27,                    /* PREFIX  */
  YYSYMBOL_STRIP = 28,                     /* STRIP  */
  YYSYMBOL_STRIP_TAIL = 29,                /* STRIP_TAIL  */
  YYSYMBOL_SET_USERPHONE = 30,             /* SET_USERPHONE  */
  YYSYMBOL_APPEND_BRANCH = 31,             /* APPEND_BRANCH  */
  YYSYMBOL_REMOVE_BRANCH = 32,             /* REMOVE_BRANCH  */
  YYSYMBOL_CLEAR_BRANCHES = 33,            /* CLEAR_BRANCHES  */
  YYSYMBOL_SET_USER = 34,                  /* SET_USER  */
  YYSYMBOL_SET_USERPASS = 35,              /* SET_USERPASS  */
  YYSYMBOL_SET_PORT = 36,                  /* SET_PORT  */
  YYSYMBOL_SET_URI = 37,                   /* SET_URI  */
  YYSYMBOL_REVERT_URI = 38,                /* REVERT_URI  */
  YYSYMBOL_FORCE_RPORT = 39,               /* FORCE_RPORT  */
  YYSYMBOL_ADD_LOCAL_RPORT = 40,           /* ADD_LOCAL_RPORT  */
  YYSYMBOL_LOCAL_RPORT = 41,               /* LOCAL_RPORT  */
  YYSYMBOL_FORCE_TCP_ALIAS = 42,           /* FORCE_TCP_ALIAS  */
  YYSYMBOL_UDP_MTU = 43,                   /* UDP_MTU  */
  YYSYMBOL_UDP_MTU_TRY_PROTO = 44,         /* UDP_MTU_TRY_PROTO  */
  YYSYMBOL_UDP4_RAW = 45,                  /* UDP4_RAW  */
  YYSYMBOL_UDP4_RAW_MTU = 46,              /* UDP4_RAW_MTU  */
  YYSYMBOL_UDP4_RAW_TTL = 47,              /* UDP4_RAW_TTL  */
  YYSYMBOL_IF = 48,                        /* IF  */
  YYSYMBOL_ELSE = 49,                      /* ELSE  */
  YYSYMBOL_SET_ADV_ADDRESS = 50,           /* SET_ADV_ADDRESS  */
  YYSYMBOL_SET_ADV_PORT = 51,              /* SET_ADV_PORT  */
  YYSYMBOL_FORCE_SEND_SOCKET = 52,         /* FORCE_SEND_SOCKET  */
  YYSYMBOL_SET_FWD_NO_CONNECT = 53,        /* SET_FWD_NO_CONNECT  */
  YYSYMBOL_SET_RPL_NO_CONNECT = 54,        /* SET_RPL_NO_CONNECT  */
  YYSYMBOL_SET_FWD_CLOSE = 55,             /* SET_FWD_CLOSE  */
  YYSYMBOL_SET_RPL_CLOSE = 56,             /* SET_RPL_CLOSE  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_CASE = 58,                      /* CASE  */
  YYSYMBOL_DEFAULT = 59,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 60,                     /* WHILE  */
  YYSYMBOL_CFG_SELECT = 61,                /* CFG_SELECT  */
  YYSYMBOL_CFG_RESET = 62,                 /* CFG_RESET  */
  YYSYMBOL_URIHOST = 63,                   /* URIHOST  */
  YYSYMBOL_URIPORT = 64,                   /* URIPORT  */
  YYSYMBOL_MAX_LEN = 65,                   /* MAX_LEN  */
  YYSYMBOL_SETFLAG = 66,                   /* SETFLAG  */
  YYSYMBOL_RESETFLAG = 67,                 /* RESETFLAG  */
  YYSYMBOL_ISFLAGSET = 68,                 /* ISFLAGSET  */
  YYSYMBOL_SETAVPFLAG = 69,                /* SETAVPFLAG  */
  YYSYMBOL_RESETAVPFLAG = 70,              /* RESETAVPFLAG  */
  YYSYMBOL_ISAVPFLAGSET = 71,              /* ISAVPFLAGSET  */
  YYSYMBOL_METHOD = 72,                    /* METHOD  */
  YYSYMBOL_URI = 73,                       /* URI  */
  YYSYMBOL_FROM_URI = 74,                  /* FROM_URI  */
  YYSYMBOL_TO_URI = 75,                    /* TO_URI  */
  YYSYMBOL_SRCIP = 76,                     /* SRCIP  */
  YYSYMBOL_SRCPORT = 77,                   /* SRCPORT  */
  YYSYMBOL_DSTIP = 78,                     /* DSTIP  */
  YYSYMBOL_DSTPORT = 79,                   /* DSTPORT  */
  YYSYMBOL_TOIP = 80,                      /* TOIP  */
  YYSYMBOL_TOPORT = 81,                    /* TOPORT  */
  YYSYMBOL_SNDIP = 82,                     /* SNDIP  */
  YYSYMBOL_SNDPORT = 83,                   /* SNDPORT  */
  YYSYMBOL_SNDPROTO = 84,                  /* SNDPROTO  */
  YYSYMBOL_SNDAF = 85,                     /* SNDAF  */
  YYSYMBOL_PROTO = 86,                     /* PROTO  */
  YYSYMBOL_AF = 87,                        /* AF  */
  YYSYMBOL_MYSELF = 88,                    /* MYSELF  */
  YYSYMBOL_MSGLEN = 89,                    /* MSGLEN  */
  YYSYMBOL_UDP = 90,                       /* UDP  */
  YYSYMBOL_TCP = 91,                       /* TCP  */
  YYSYMBOL_TLS = 92,                       /* TLS  */
  YYSYMBOL_SCTP = 93,                      /* SCTP  */
  YYSYMBOL_WS = 94,                        /* WS  */
  YYSYMBOL_WSS = 95,                       /* WSS  */
  YYSYMBOL_DEBUG_V = 96,                   /* DEBUG_V  */
  YYSYMBOL_FORK = 97,                      /* FORK  */
  YYSYMBOL_FORK_DELAY = 98,                /* FORK_DELAY  */
  YYSYMBOL_MODINIT_DELAY = 99,             /* MODINIT_DELAY  */
  YYSYMBOL_LOGSTDERROR = 100,              /* LOGSTDERROR  */
  YYSYMBOL_LOGFACILITY = 101,              /* LOGFACILITY  */
  YYSYMBOL_LOGNAME = 102,                  /* LOGNAME  */
  YYSYMBOL_LOGCOLOR = 103,                 /* LOGCOLOR  */
  YYSYMBOL_LOGPREFIX = 104,                /* LOGPREFIX  */
  YYSYMBOL_LOGPREFIXMODE = 105,            /* LOGPREFIXMODE  */
  YYSYMBOL_LOGENGINETYPE = 106,            /* LOGENGINETYPE  */
  YYSYMBOL_LOGENGINEDATA = 107,            /* LOGENGINEDATA  */
  YYSYMBOL_XAVPVIAPARAMS = 108,            /* XAVPVIAPARAMS  */
  YYSYMBOL_XAVPVIAFIELDS = 109,            /* XAVPVIAFIELDS  */
  YYSYMBOL_XAVPVIAREPLYPARAMS = 110,       /* XAVPVIAREPLYPARAMS  */
  YYSYMBOL_LISTEN = 111,                   /* LISTEN  */
  YYSYMBOL_ADVERTISE = 112,                /* ADVERTISE  */
  YYSYMBOL_VIRTUAL = 113,                  /* VIRTUAL  */
  YYSYMBOL_STRNAME = 114,                  /* STRNAME  */
  YYSYMBOL_ALIAS = 115,                    /* ALIAS  */
  YYSYMBOL_SR_AUTO_ALIASES = 116,          /* SR_AUTO_ALIASES  */
  YYSYMBOL_DOMAIN = 117,                   /* DOMAIN  */
  YYSYMBOL_SR_AUTO_DOMAINS = 118,          /* SR_AUTO_DOMAINS  */
  YYSYMBOL_DNS = 119,                      /* DNS  */
  YYSYMBOL_REV_DNS = 120,                  /* REV_DNS  */
  YYSYMBOL_DNS_TRY_IPV6 = 121,             /* DNS_TRY_IPV6  */
  YYSYMBOL_DNS_TRY_NAPTR = 122,            /* DNS_TRY_NAPTR  */
  YYSYMBOL_DNS_SRV_LB = 123,               /* DNS_SRV_LB  */
  YYSYMBOL_DNS_UDP_PREF = 124,             /* DNS_UDP_PREF  */
  YYSYMBOL_DNS_TCP_PREF = 125,             /* DNS_TCP_PREF  */
  YYSYMBOL_DNS_TLS_PREF = 126,             /* DNS_TLS_PREF  */
  YYSYMBOL_DNS_SCTP_PREF = 127,            /* DNS_SCTP_PREF  */
  YYSYMBOL_DNS_RETR_TIME = 128,            /* DNS_RETR_TIME  */
  YYSYMBOL_DNS_SLOW_QUERY_MS = 129,        /* DNS_SLOW_QUERY_MS  */
  YYSYMBOL_DNS_RETR_NO = 130,              /* DNS_RETR_NO  */
  YYSYMBOL_DNS_SERVERS_NO = 131,           /* DNS_SERVERS_NO  */
  YYSYMBOL_DNS_USE_SEARCH = 132,           /* DNS_USE_SEARCH  */
  YYSYMBOL_DNS_SEARCH_FMATCH = 133,        /* DNS_SEARCH_FMATCH  */
  YYSYMBOL_DNS_NAPTR_IGNORE_RFC = 134,     /* DNS_NAPTR_IGNORE_RFC  */
  YYSYMBOL_DNS_CACHE_INIT = 135,           /* DNS_CACHE_INIT  */
  YYSYMBOL_DNS_USE_CACHE = 136,            /* DNS_USE_CACHE  */
  YYSYMBOL_DNS_USE_FAILOVER = 137,         /* DNS_USE_FAILOVER  */
  YYSYMBOL_DNS_CACHE_FLAGS = 138,          /* DNS_CACHE_FLAGS  */
  YYSYMBOL_DNS_CACHE_NEG_TTL = 139,        /* DNS_CACHE_NEG_TTL  */
  YYSYMBOL_DNS_CACHE_MIN_TTL = 140,        /* DNS_CACHE_MIN_TTL  */
  YYSYMBOL_DNS_CACHE_MAX_TTL = 141,        /* DNS_CACHE_MAX_TTL  */
  YYSYMBOL_DNS_CACHE_MEM = 142,            /* DNS_CACHE_MEM  */
  YYSYMBOL_DNS_CACHE_GC_INT = 143,         /* DNS_CACHE_GC_INT  */
  YYSYMBOL_DNS_CACHE_DEL_NONEXP = 144,     /* DNS_CACHE_DEL_NONEXP  */
  YYSYMBOL_DNS_CACHE_REC_PREF = 145,       /* DNS_CACHE_REC_PREF  */
  YYSYMBOL_AUTO_BIND_IPV6 = 146,           /* AUTO_BIND_IPV6  */
  YYSYMBOL_BIND_IPV6_LINK_LOCAL = 147,     /* BIND_IPV6_LINK_LOCAL  */
  YYSYMBOL_IPV6_HEX_STYLE = 148,           /* IPV6_HEX_STYLE  */
  YYSYMBOL_DST_BLST_INIT = 149,            /* DST_BLST_INIT  */
  YYSYMBOL_USE_DST_BLST = 150,             /* USE_DST_BLST  */
  YYSYMBOL_DST_BLST_MEM = 151,             /* DST_BLST_MEM  */
  YYSYMBOL_DST_BLST_TTL = 152,             /* DST_BLST_TTL  */
  YYSYMBOL_DST_BLST_GC_INT = 153,          /* DST_BLST_GC_INT  */
  YYSYMBOL_DST_BLST_UDP_IMASK = 154,       /* DST_BLST_UDP_IMASK  */
  YYSYMBOL_DST_BLST_TCP_IMASK = 155,       /* DST_BLST_TCP_IMASK  */
  YYSYMBOL_DST_BLST_TLS_IMASK = 156,       /* DST_BLST_TLS_IMASK  */
  YYSYMBOL_DST_BLST_SCTP_IMASK = 157,      /* DST_BLST_SCTP_IMASK  */
  YYSYMBOL_IP_FREE_BIND = 158,             /* IP_FREE_BIND  */
  YYSYMBOL_PORT = 159,                     /* PORT  */
  YYSYMBOL_STAT = 160,                     /* STAT  */
  YYSYMBOL_STATS_NAMESEP = 161,            /* STATS_NAMESEP  */
  YYSYMBOL_CHILDREN = 162,                 /* CHILDREN  */
  YYSYMBOL_SOCKET = 163,                   /* SOCKET  */
  YYSYMBOL_BIND = 164,                     /* BIND  */
  YYSYMBOL_WORKERS = 165,                  /* WORKERS  */
  YYSYMBOL_SOCKET_WORKERS = 166,           /* SOCKET_WORKERS  */
  YYSYMBOL_ASYNC_WORKERS = 167,            /* ASYNC_WORKERS  */
  YYSYMBOL_ASYNC_USLEEP = 168,             /* ASYNC_USLEEP  */
  YYSYMBOL_ASYNC_NONBLOCK = 169,           /* ASYNC_NONBLOCK  */
  YYSYMBOL_ASYNC_WORKERS_GROUP = 170,      /* ASYNC_WORKERS_GROUP  */
  YYSYMBOL_CHECK_VIA = 171,                /* CHECK_VIA  */
  YYSYMBOL_PHONE2TEL = 172,                /* PHONE2TEL  */
  YYSYMBOL_MEMLOG = 173,                   /* MEMLOG  */
  YYSYMBOL_MEMDBG = 174,                   /* MEMDBG  */
  YYSYMBOL_MEMSUM = 175,                   /* MEMSUM  */
  YYSYMBOL_MEMSAFETY = 176,                /* MEMSAFETY  */
  YYSYMBOL_MEMADDSIZE = 177,               /* MEMADDSIZE  */
  YYSYMBOL_MEMJOIN = 178,                  /* MEMJOIN  */
  YYSYMBOL_MEMSTATUSMODE = 179,            /* MEMSTATUSMODE  */
  YYSYMBOL_SIP_PARSER_LOG_ONELINE = 180,   /* SIP_PARSER_LOG_ONELINE  */
  YYSYMBOL_SIP_PARSER_LOG = 181,           /* SIP_PARSER_LOG  */
  YYSYMBOL_SIP_PARSER_MODE = 182,          /* SIP_PARSER_MODE  */
  YYSYMBOL_CORELOG = 183,                  /* CORELOG  */
  YYSYMBOL_SIP_WARNING = 184,              /* SIP_WARNING  */
  YYSYMBOL_SERVER_SIGNATURE = 185,         /* SERVER_SIGNATURE  */
  YYSYMBOL_SERVER_HEADER = 186,            /* SERVER_HEADER  */
  YYSYMBOL_USER_AGENT_HEADER = 187,        /* USER_AGENT_HEADER  */
  YYSYMBOL_REPLY_TO_VIA = 188,             /* REPLY_TO_VIA  */
  YYSYMBOL_LOADMODULE = 189,               /* LOADMODULE  */
  YYSYMBOL_LOADMODULEX = 190,              /* LOADMODULEX  */
  YYSYMBOL_LOADPATH = 191,                 /* LOADPATH  */
  YYSYMBOL_MODPARAM = 192,                 /* MODPARAM  */
  YYSYMBOL_MODPARAMX = 193,                /* MODPARAMX  */
  YYSYMBOL_CFGENGINE = 194,                /* CFGENGINE  */
  YYSYMBOL_MAXBUFFER = 195,                /* MAXBUFFER  */
  YYSYMBOL_MAXSNDBUFFER = 196,             /* MAXSNDBUFFER  */
  YYSYMBOL_SQL_BUFFER_SIZE = 197,          /* SQL_BUFFER_SIZE  */
  YYSYMBOL_MSG_RECV_MAX_SIZE = 198,        /* MSG_RECV_MAX_SIZE  */
  YYSYMBOL_TCP_MSG_READ_TIMEOUT = 199,     /* TCP_MSG_READ_TIMEOUT  */
  YYSYMBOL_TCP_MSG_DATA_TIMEOUT = 200,     /* TCP_MSG_DATA_TIMEOUT  */
  YYSYMBOL_TCP_ACCEPT_IPLIMIT = 201,       /* TCP_ACCEPT_IPLIMIT  */
  YYSYMBOL_TCP_CHECK_TIMER = 202,          /* TCP_CHECK_TIMER  */
  YYSYMBOL_USER = 203,                     /* USER  */
  YYSYMBOL_GROUP = 204,                    /* GROUP  */
  YYSYMBOL_CHROOT = 205,                   /* CHROOT  */
  YYSYMBOL_WDIR = 206,                     /* WDIR  */
  YYSYMBOL_RUNDIR = 207,                   /* RUNDIR  */
  YYSYMBOL_MHOMED = 208,                   /* MHOMED  */
  YYSYMBOL_DISABLE_TCP = 209,              /* DISABLE_TCP  */
  YYSYMBOL_TCP_ACCEPT_ALIASES = 210,       /* TCP_ACCEPT_ALIASES  */
  YYSYMBOL_TCP_ACCEPT_UNIQUE = 211,        /* TCP_ACCEPT_UNIQUE  */
  YYSYMBOL_TCP_CONNECTION_MATCH = 212,     /* TCP_CONNECTION_MATCH  */
  YYSYMBOL_TCP_CHILDREN = 213,             /* TCP_CHILDREN  */
  YYSYMBOL_TCP_CONNECT_TIMEOUT = 214,      /* TCP_CONNECT_TIMEOUT  */
  YYSYMBOL_TCP_SEND_TIMEOUT = 215,         /* TCP_SEND_TIMEOUT  */
  YYSYMBOL_TCP_CON_LIFETIME = 216,         /* TCP_CON_LIFETIME  */
  YYSYMBOL_TCP_POLL_METHOD = 217,          /* TCP_POLL_METHOD  */
  YYSYMBOL_TCP_MAX_CONNECTIONS = 218,      /* TCP_MAX_CONNECTIONS  */
  YYSYMBOL_TLS_MAX_CONNECTIONS = 219,      /* TLS_MAX_CONNECTIONS  */
  YYSYMBOL_TCP_NO_CONNECT = 220,           /* TCP_NO_CONNECT  */
  YYSYMBOL_TCP_SOURCE_IPV4 = 221,          /* TCP_SOURCE_IPV4  */
  YYSYMBOL_TCP_SOURCE_IPV6 = 222,          /* TCP_SOURCE_IPV6  */
  YYSYMBOL_TCP_OPT_FD_CACHE = 223,         /* TCP_OPT_FD_CACHE  */
  YYSYMBOL_TCP_OPT_BUF_WRITE = 224,        /* TCP_OPT_BUF_WRITE  */
  YYSYMBOL_TCP_OPT_CONN_WQ_MAX = 225,      /* TCP_OPT_CONN_WQ_MAX  */
  YYSYMBOL_TCP_OPT_WQ_MAX = 226,           /* TCP_OPT_WQ_MAX  */
  YYSYMBOL_TCP_OPT_RD_BUF = 227,           /* TCP_OPT_RD_BUF  */
  YYSYMBOL_TCP_OPT_WQ_BLK = 228,           /* TCP_OPT_WQ_BLK  */
  YYSYMBOL_TCP_OPT_DEFER_ACCEPT = 229,     /* TCP_OPT_DEFER_ACCEPT  */
  YYSYMBOL_TCP_OPT_DELAYED_ACK = 230,      /* TCP_OPT_DELAYED_ACK  */
  YYSYMBOL_TCP_OPT_SYNCNT = 231,           /* TCP_OPT_SYNCNT  */
  YYSYMBOL_TCP_OPT_LINGER2 = 232,          /* TCP_OPT_LINGER2  */
  YYSYMBOL_TCP_OPT_KEEPALIVE = 233,        /* TCP_OPT_KEEPALIVE  */
  YYSYMBOL_TCP_OPT_KEEPIDLE = 234,         /* TCP_OPT_KEEPIDLE  */
  YYSYMBOL_TCP_OPT_KEEPINTVL = 235,        /* TCP_OPT_KEEPINTVL  */
  YYSYMBOL_TCP_OPT_KEEPCNT = 236,          /* TCP_OPT_KEEPCNT  */
  YYSYMBOL_TCP_OPT_CRLF_PING = 237,        /* TCP_OPT_CRLF_PING  */
  YYSYMBOL_TCP_OPT_ACCEPT_NO_CL = 238,     /* TCP_OPT_ACCEPT_NO_CL  */
  YYSYMBOL_TCP_OPT_ACCEPT_HEP3 = 239,      /* TCP_OPT_ACCEPT_HEP3  */
  YYSYMBOL_TCP_OPT_ACCEPT_HAPROXY = 240,   /* TCP_OPT_ACCEPT_HAPROXY  */
  YYSYMBOL_TCP_OPT_CLOSE_RST = 241,        /* TCP_OPT_CLOSE_RST  */
  YYSYMBOL_TCP_CLONE_RCVBUF = 242,         /* TCP_CLONE_RCVBUF  */
  YYSYMBOL_TCP_REUSE_PORT = 243,           /* TCP_REUSE_PORT  */
  YYSYMBOL_TCP_WAIT_DATA = 244,            /* TCP_WAIT_DATA  */
  YYSYMBOL_TCP_SCRIPT_MODE = 245,          /* TCP_SCRIPT_MODE  */
  YYSYMBOL_DISABLE_TLS = 246,              /* DISABLE_TLS  */
  YYSYMBOL_ENABLE_TLS = 247,               /* ENABLE_TLS  */
  YYSYMBOL_TLS_THREADS_MODE = 248,         /* TLS_THREADS_MODE  */
  YYSYMBOL_TLSLOG = 249,                   /* TLSLOG  */
  YYSYMBOL_TLS_PORT_NO = 250,              /* TLS_PORT_NO  */
  YYSYMBOL_TLS_METHOD = 251,               /* TLS_METHOD  */
  YYSYMBOL_TLS_HANDSHAKE_TIMEOUT = 252,    /* TLS_HANDSHAKE_TIMEOUT  */
  YYSYMBOL_TLS_SEND_TIMEOUT = 253,         /* TLS_SEND_TIMEOUT  */
  YYSYMBOL_SSLv23 = 254,                   /* SSLv23  */
  YYSYMBOL_SSLv2 = 255,                    /* SSLv2  */
  YYSYMBOL_SSLv3 = 256,                    /* SSLv3  */
  YYSYMBOL_TLSv1 = 257,                    /* TLSv1  */
  YYSYMBOL_TLS_VERIFY = 258,               /* TLS_VERIFY  */
  YYSYMBOL_TLS_REQUIRE_CERTIFICATE = 259,  /* TLS_REQUIRE_CERTIFICATE  */
  YYSYMBOL_TLS_CERTIFICATE = 260,          /* TLS_CERTIFICATE  */
  YYSYMBOL_TLS_PRIVATE_KEY = 261,          /* TLS_PRIVATE_KEY  */
  YYSYMBOL_TLS_CA_LIST = 262,              /* TLS_CA_LIST  */
  YYSYMBOL_DISABLE_SCTP = 263,             /* DISABLE_SCTP  */
  YYSYMBOL_ENABLE_SCTP = 264,              /* ENABLE_SCTP  */
  YYSYMBOL_SCTP_CHILDREN = 265,            /* SCTP_CHILDREN  */
  YYSYMBOL_ADVERTISED_ADDRESS = 266,       /* ADVERTISED_ADDRESS  */
  YYSYMBOL_ADVERTISED_PORT = 267,          /* ADVERTISED_PORT  */
  YYSYMBOL_DISABLE_CORE = 268,             /* DISABLE_CORE  */
  YYSYMBOL_OPEN_FD_LIMIT = 269,            /* OPEN_FD_LIMIT  */
  YYSYMBOL_SHM_MEM_SZ = 270,               /* SHM_MEM_SZ  */
  YYSYMBOL_SHM_FORCE_ALLOC = 271,          /* SHM_FORCE_ALLOC  */
  YYSYMBOL_MLOCK_PAGES = 272,              /* MLOCK_PAGES  */
  YYSYMBOL_REAL_TIME = 273,                /* REAL_TIME  */
  YYSYMBOL_RT_PRIO = 274,                  /* RT_PRIO  */
  YYSYMBOL_RT_POLICY = 275,                /* RT_POLICY  */
  YYSYMBOL_RT_TIMER1_PRIO = 276,           /* RT_TIMER1_PRIO  */
  YYSYMBOL_RT_TIMER1_POLICY = 277,         /* RT_TIMER1_POLICY  */
  YYSYMBOL_RT_TIMER2_PRIO = 278,           /* RT_TIMER2_PRIO  */
  YYSYMBOL_RT_TIMER2_POLICY = 279,         /* RT_TIMER2_POLICY  */
  YYSYMBOL_MCAST_LOOPBACK = 280,           /* MCAST_LOOPBACK  */
  YYSYMBOL_MCAST_TTL = 281,                /* MCAST_TTL  */
  YYSYMBOL_MCAST = 282,                    /* MCAST  */
  YYSYMBOL_TOS = 283,                      /* TOS  */
  YYSYMBOL_PMTU_DISCOVERY = 284,           /* PMTU_DISCOVERY  */
  YYSYMBOL_KILL_TIMEOUT = 285,             /* KILL_TIMEOUT  */
  YYSYMBOL_MAX_WLOOPS = 286,               /* MAX_WLOOPS  */
  YYSYMBOL_PVBUFSIZE = 287,                /* PVBUFSIZE  */
  YYSYMBOL_PVBUFSLOTS = 288,               /* PVBUFSLOTS  */
  YYSYMBOL_PVCACHELIMIT = 289,             /* PVCACHELIMIT  */
  YYSYMBOL_PVCACHEACTION = 290,            /* PVCACHEACTION  */
  YYSYMBOL_HTTP_REPLY_PARSE = 291,         /* HTTP_REPLY_PARSE  */
  YYSYMBOL_VERSION_TABLE_CFG = 292,        /* VERSION_TABLE_CFG  */
  YYSYMBOL_VERBOSE_STARTUP = 293,          /* VERBOSE_STARTUP  */
  YYSYMBOL_ROUTE_LOCKS_SIZE = 294,         /* ROUTE_LOCKS_SIZE  */
  YYSYMBOL_WAIT_WORKER1_MODE = 295,        /* WAIT_WORKER1_MODE  */
  YYSYMBOL_WAIT_WORKER1_TIME = 296,        /* WAIT_WORKER1_TIME  */
  YYSYMBOL_WAIT_WORKER1_USLEEP = 297,      /* WAIT_WORKER1_USLEEP  */
  YYSYMBOL_CFG_DESCRIPTION = 298,          /* CFG_DESCRIPTION  */
  YYSYMBOL_SERVER_ID = 299,                /* SERVER_ID  */
  YYSYMBOL_KEMI = 300,                     /* KEMI  */
  YYSYMBOL_REQUEST_ROUTE_CALLBACK = 301,   /* REQUEST_ROUTE_CALLBACK  */
  YYSYMBOL_ONSEND_ROUTE_CALLBACK = 302,    /* ONSEND_ROUTE_CALLBACK  */
  YYSYMBOL_REPLY_ROUTE_CALLBACK = 303,     /* REPLY_ROUTE_CALLBACK  */
  YYSYMBOL_EVENT_ROUTE_CALLBACK = 304,     /* EVENT_ROUTE_CALLBACK  */
  YYSYMBOL_RECEIVED_ROUTE_CALLBACK = 305,  /* RECEIVED_ROUTE_CALLBACK  */
  YYSYMBOL_RECEIVED_ROUTE_MODE = 306,      /* RECEIVED_ROUTE_MODE  */
  YYSYMBOL_PRE_ROUTING_CALLBACK = 307,     /* PRE_ROUTING_CALLBACK  */
  YYSYMBOL_MAX_RECURSIVE_LEVEL = 308,      /* MAX_RECURSIVE_LEVEL  */
  YYSYMBOL_MAX_BRANCHES_PARAM = 309,       /* MAX_BRANCHES_PARAM  */
  YYSYMBOL_LATENCY_CFG_LOG = 310,          /* LATENCY_CFG_LOG  */
  YYSYMBOL_LATENCY_LOG = 311,              /* LATENCY_LOG  */
  YYSYMBOL_LATENCY_LIMIT_DB = 312,         /* LATENCY_LIMIT_DB  */
  YYSYMBOL_LATENCY_LIMIT_ACTION = 313,     /* LATENCY_LIMIT_ACTION  */
  YYSYMBOL_LATENCY_LIMIT_CFG = 314,        /* LATENCY_LIMIT_CFG  */
  YYSYMBOL_RPC_EXEC_DELTA_CFG = 315,       /* RPC_EXEC_DELTA_CFG  */
  YYSYMBOL_MSG_TIME = 316,                 /* MSG_TIME  */
  YYSYMBOL_ONSEND_RT_REPLY = 317,          /* ONSEND_RT_REPLY  */
  YYSYMBOL_URI_HOST_EXTRA_CHARS = 318,     /* URI_HOST_EXTRA_CHARS  */
  YYSYMBOL_HDR_NAME_EXTRA_CHARS = 319,     /* HDR_NAME_EXTRA_CHARS  */
  YYSYMBOL_FLAGS_DECL = 320,               /* FLAGS_DECL  */
  YYSYMBOL_AVPFLAGS_DECL = 321,            /* AVPFLAGS_DECL  */
  YYSYMBOL_ATTR_MARK = 322,                /* ATTR_MARK  */
  YYSYMBOL_SELECT_MARK = 323,              /* SELECT_MARK  */
  YYSYMBOL_ATTR_FROM = 324,                /* ATTR_FROM  */
  YYSYMBOL_ATTR_TO = 325,                  /* ATTR_TO  */
  YYSYMBOL_ATTR_FROMURI = 326,             /* ATTR_FROMURI  */
  YYSYMBOL_ATTR_TOURI = 327,               /* ATTR_TOURI  */
  YYSYMBOL_ATTR_FROMUSER = 328,            /* ATTR_FROMUSER  */
  YYSYMBOL_ATTR_TOUSER = 329,              /* ATTR_TOUSER  */
  YYSYMBOL_ATTR_FROMDOMAIN = 330,          /* ATTR_FROMDOMAIN  */
  YYSYMBOL_ATTR_TODOMAIN = 331,            /* ATTR_TODOMAIN  */
  YYSYMBOL_ATTR_GLOBAL = 332,              /* ATTR_GLOBAL  */
  YYSYMBOL_ADDEQ = 333,                    /* ADDEQ  */
  YYSYMBOL_SUBST = 334,                    /* SUBST  */
  YYSYMBOL_SUBSTDEF = 335,                 /* SUBSTDEF  */
  YYSYMBOL_SUBSTDEFS = 336,                /* SUBSTDEFS  */
  YYSYMBOL_EQUAL = 337,                    /* EQUAL  */
  YYSYMBOL_LOG_OR = 338,                   /* LOG_OR  */
  YYSYMBOL_LOG_AND = 339,                  /* LOG_AND  */
  YYSYMBOL_BIN_OR = 340,                   /* BIN_OR  */
  YYSYMBOL_BIN_AND = 341,                  /* BIN_AND  */
  YYSYMBOL_BIN_XOR = 342,                  /* BIN_XOR  */
  YYSYMBOL_BIN_LSHIFT = 343,               /* BIN_LSHIFT  */
  YYSYMBOL_BIN_RSHIFT = 344,               /* BIN_RSHIFT  */
  YYSYMBOL_EQUAL_T = 345,                  /* EQUAL_T  */
  YYSYMBOL_DIFF = 346,                     /* DIFF  */
  YYSYMBOL_MATCH = 347,                    /* MATCH  */
  YYSYMBOL_INTEQ = 348,                    /* INTEQ  */
  YYSYMBOL_INTDIFF = 349,                  /* INTDIFF  */
  YYSYMBOL_STREQ = 350,                    /* STREQ  */
  YYSYMBOL_STRDIFF = 351,                  /* STRDIFF  */
  YYSYMBOL_GT = 352,                       /* GT  */
  YYSYMBOL_LT = 353,                       /* LT  */
  YYSYMBOL_GTE = 354,                      /* GTE  */
  YYSYMBOL_LTE = 355,                      /* LTE  */
  YYSYMBOL_PLUS = 356,                     /* PLUS  */
  YYSYMBOL_MINUS = 357,                    /* MINUS  */
  YYSYMBOL_STAR = 358,                     /* STAR  */
  YYSYMBOL_SLASH = 359,                    /* SLASH  */
  YYSYMBOL_MODULO = 360,                   /* MODULO  */
  YYSYMBOL_NOT = 361,                      /* NOT  */
  YYSYMBOL_UNARY = 362,                    /* UNARY  */
  YYSYMBOL_BIN_NOT = 363,                  /* BIN_NOT  */
  YYSYMBOL_DEFINED = 364,                  /* DEFINED  */
  YYSYMBOL_INTCAST = 365,                  /* INTCAST  */
  YYSYMBOL_STRCAST = 366,                  /* STRCAST  */
  YYSYMBOL_DOT = 367,                      /* DOT  */
  YYSYMBOL_STRLEN = 368,                   /* STRLEN  */
  YYSYMBOL_STREMPTY = 369,                 /* STREMPTY  */
  YYSYMBOL_SELVAL = 370,                   /* SELVAL  */
  YYSYMBOL_NUMBER = 371,                   /* NUMBER  */
  YYSYMBOL_ID = 372,                       /* ID  */
  YYSYMBOL_NUM_ID = 373,                   /* NUM_ID  */
  YYSYMBOL_STRING = 374,                   /* STRING  */
  YYSYMBOL_IPV6ADDR = 375,                 /* IPV6ADDR  */
  YYSYMBOL_PVAR = 376,                     /* PVAR  */
  YYSYMBOL_AVP_OR_PVAR = 377,              /* AVP_OR_PVAR  */
  YYSYMBOL_EVENT_RT_NAME = 378,            /* EVENT_RT_NAME  */
  YYSYMBOL_COMMA = 379,                    /* COMMA  */
  YYSYMBOL_SEMICOLON = 380,                /* SEMICOLON  */
  YYSYMBOL_RPAREN = 381,                   /* RPAREN  */
  YYSYMBOL_LPAREN = 382,                   /* LPAREN  */
  YYSYMBOL_LBRACE = 383,                   /* LBRACE  */
  YYSYMBOL_RBRACE = 384,                   /* RBRACE  */
  YYSYMBOL_LBRACK = 385,                   /* LBRACK  */
  YYSYMBOL_RBRACK = 386,                   /* RBRACK  */
  YYSYMBOL_CR = 387,                       /* CR  */
  YYSYMBOL_COLON = 388,                    /* COLON  */
  YYSYMBOL_YYACCEPT = 389,                 /* $accept  */
  YYSYMBOL_cfg = 390,                      /* cfg  */
  YYSYMBOL_statements = 391,               /* statements  */
  YYSYMBOL_statement = 392,                /* statement  */
  YYSYMBOL_393_1 = 393,                    /* $@1  */
  YYSYMBOL_394_2 = 394,                    /* $@2  */
  YYSYMBOL_395_3 = 395,                    /* $@3  */
  YYSYMBOL_396_4 = 396,                    /* $@4  */
  YYSYMBOL_397_5 = 397,                    /* $@5  */
  YYSYMBOL_listen_id = 398,                /* listen_id  */
  YYSYMBOL_listen_id_lst = 399,            /* listen_id_lst  */
  YYSYMBOL_listen_id2 = 400,               /* listen_id2  */
  YYSYMBOL_proto = 401,                    /* proto  */
  YYSYMBOL_eqproto = 402,                  /* eqproto  */
  YYSYMBOL_xproto = 403,                   /* xproto  */
  YYSYMBOL_port = 404,                     /* port  */
  YYSYMBOL_phostport = 405,                /* phostport  */
  YYSYMBOL_listen_phostport = 406,         /* listen_phostport  */
  YYSYMBOL_id_lst = 407,                   /* id_lst  */
  YYSYMBOL_intno = 408,                    /* intno  */
  YYSYMBOL_flags_decl = 409,               /* flags_decl  */
  YYSYMBOL_flag_list = 410,                /* flag_list  */
  YYSYMBOL_flag_spec = 411,                /* flag_spec  */
  YYSYMBOL_flag_name = 412,                /* flag_name  */
  YYSYMBOL_avpflags_decl = 413,            /* avpflags_decl  */
  YYSYMBOL_avpflag_list = 414,             /* avpflag_list  */
  YYSYMBOL_avpflag_spec = 415,             /* avpflag_spec  */
  YYSYMBOL_socket_lattr = 416,             /* socket_lattr  */
  YYSYMBOL_socket_lattrs = 417,            /* socket_lattrs  */
  YYSYMBOL_assign_stm = 418,               /* assign_stm  */
  YYSYMBOL_419_6 = 419,                    /* $@6  */
  YYSYMBOL_cfg_var_id = 420,               /* cfg_var_id  */
  YYSYMBOL_cfg_var_idn = 421,              /* cfg_var_idn  */
  YYSYMBOL_cfg_var = 422,                  /* cfg_var  */
  YYSYMBOL_module_stm = 423,               /* module_stm  */
  YYSYMBOL_ip = 424,                       /* ip  */
  YYSYMBOL_ipv4 = 425,                     /* ipv4  */
  YYSYMBOL_ipv6addr = 426,                 /* ipv6addr  */
  YYSYMBOL_ipv6 = 427,                     /* ipv6  */
  YYSYMBOL_route_name = 428,               /* route_name  */
  YYSYMBOL_route_main = 429,               /* route_main  */
  YYSYMBOL_route_stm = 430,                /* route_stm  */
  YYSYMBOL_failure_route_main = 431,       /* failure_route_main  */
  YYSYMBOL_failure_route_stm = 432,        /* failure_route_stm  */
  YYSYMBOL_route_reply_main = 433,         /* route_reply_main  */
  YYSYMBOL_onreply_route_stm = 434,        /* onreply_route_stm  */
  YYSYMBOL_435_7 = 435,                    /* $@7  */
  YYSYMBOL_436_8 = 436,                    /* $@8  */
  YYSYMBOL_branch_route_main = 437,        /* branch_route_main  */
  YYSYMBOL_branch_route_stm = 438,         /* branch_route_stm  */
  YYSYMBOL_send_route_main = 439,          /* send_route_main  */
  YYSYMBOL_send_route_stm = 440,           /* send_route_stm  */
  YYSYMBOL_event_route_main = 441,         /* event_route_main  */
  YYSYMBOL_event_route_stm = 442,          /* event_route_stm  */
  YYSYMBOL_preprocess_stm = 443,           /* preprocess_stm  */
  YYSYMBOL_equalop = 444,                  /* equalop  */
  YYSYMBOL_cmpop = 445,                    /* cmpop  */
  YYSYMBOL_strop = 446,                    /* strop  */
  YYSYMBOL_rve_equalop = 447,              /* rve_equalop  */
  YYSYMBOL_rve_cmpop = 448,                /* rve_cmpop  */
  YYSYMBOL_uri_type = 449,                 /* uri_type  */
  YYSYMBOL_eint_op_onsend = 450,           /* eint_op_onsend  */
  YYSYMBOL_eint_op = 451,                  /* eint_op  */
  YYSYMBOL_eip_op_onsend = 452,            /* eip_op_onsend  */
  YYSYMBOL_eip_op = 453,                   /* eip_op  */
  YYSYMBOL_exp_elem = 454,                 /* exp_elem  */
  YYSYMBOL_ipnet = 455,                    /* ipnet  */
  YYSYMBOL_host = 456,                     /* host  */
  YYSYMBOL_host_if_id = 457,               /* host_if_id  */
  YYSYMBOL_host_or_if = 458,               /* host_or_if  */
  YYSYMBOL_fcmd = 459,                     /* fcmd  */
  YYSYMBOL_stm = 460,                      /* stm  */
  YYSYMBOL_actions = 461,                  /* actions  */
  YYSYMBOL_action = 462,                   /* action  */
  YYSYMBOL_if_cmd = 463,                   /* if_cmd  */
  YYSYMBOL_ct_rval = 464,                  /* ct_rval  */
  YYSYMBOL_single_case = 465,              /* single_case  */
  YYSYMBOL_case_stms = 466,                /* case_stms  */
  YYSYMBOL_switch_cmd = 467,               /* switch_cmd  */
  YYSYMBOL_while_cmd = 468,                /* while_cmd  */
  YYSYMBOL_select_param = 469,             /* select_param  */
  YYSYMBOL_select_params = 470,            /* select_params  */
  YYSYMBOL_select_id = 471,                /* select_id  */
  YYSYMBOL_472_9 = 472,                    /* $@9  */
  YYSYMBOL_attr_class_spec = 473,          /* attr_class_spec  */
  YYSYMBOL_attr_name_spec = 474,           /* attr_name_spec  */
  YYSYMBOL_attr_spec = 475,                /* attr_spec  */
  YYSYMBOL_attr_mark = 476,                /* attr_mark  */
  YYSYMBOL_attr_id = 477,                  /* attr_id  */
  YYSYMBOL_attr_id_num_idx = 478,          /* attr_id_num_idx  */
  YYSYMBOL_attr_id_no_idx = 479,           /* attr_id_no_idx  */
  YYSYMBOL_attr_id_ass = 480,              /* attr_id_ass  */
  YYSYMBOL_attr_id_any = 481,              /* attr_id_any  */
  YYSYMBOL_attr_id_any_str = 482,          /* attr_id_any_str  */
  YYSYMBOL_pvar = 483,                     /* pvar  */
  YYSYMBOL_avp_pvar = 484,                 /* avp_pvar  */
  YYSYMBOL_assign_op = 485,                /* assign_op  */
  YYSYMBOL_lval = 486,                     /* lval  */
  YYSYMBOL_rval = 487,                     /* rval  */
  YYSYMBOL_rve_un_op = 488,                /* rve_un_op  */
  YYSYMBOL_rval_expr = 489,                /* rval_expr  */
  YYSYMBOL_assign_action = 490,            /* assign_action  */
  YYSYMBOL_avpflag_oper = 491,             /* avpflag_oper  */
  YYSYMBOL_cmd = 492,                      /* cmd  */
  YYSYMBOL_493_10 = 493,                   /* $@10  */
  YYSYMBOL_func_params = 494,              /* func_params  */
  YYSYMBOL_func_param = 495,               /* func_param  */
  YYSYMBOL_ret_cmd = 496                   /* ret_cmd  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  532
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   13022

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  389
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1013
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1915

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   643


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   667,   667,   670,   671,   672,   675,   676,   677,   678,
     679,   680,   680,   681,   681,   682,   683,   683,   684,   684,
     685,   685,   686,   687,   690,   707,   716,   731,   732,   738,
     739,   743,   744,   745,   746,   747,   750,   751,   752,   753,
     754,   755,   756,   759,   760,   761,   762,   763,   764,   768,
     769,   772,   773,   774,   775,   776,   780,   781,   782,   783,
     784,   788,   789,   792,   793,   796,   797,   799,   800,   803,
     806,   812,   813,   817,   818,   821,   822,   825,   831,   837,
     842,   847,   851,   852,   856,   857,   862,   868,   869,   870,
     871,   872,   875,   876,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   890,   891,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   913,
     914,   917,   918,   921,   922,   923,   924,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   987,   988,   995,   996,   997,   998,  1001,  1002,  1005,
    1006,  1009,  1010,  1011,  1012,  1015,  1016,  1019,  1020,  1023,
    1024,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1052,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1102,  1103,  1110,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1139,  1140,  1147,  1148,
    1155,  1156,  1163,  1164,  1171,  1172,  1179,  1180,  1187,  1188,
    1198,  1199,  1213,  1227,  1228,  1235,  1236,  1243,  1244,  1251,
    1252,  1261,  1262,  1271,  1272,  1279,  1280,  1287,  1288,  1295,
    1296,  1303,  1304,  1311,  1312,  1319,  1320,  1327,  1328,  1335,
    1336,  1343,  1344,  1351,  1352,  1359,  1360,  1367,  1368,  1375,
    1376,  1383,  1384,  1391,  1392,  1399,  1400,  1407,  1408,  1415,
    1416,  1423,  1425,  1432,  1433,  1444,  1445,  1452,  1453,  1460,
    1461,  1468,  1469,  1476,  1477,  1484,  1485,  1492,  1493,  1500,
    1501,  1508,  1515,  1522,  1529,  1536,  1543,  1544,  1551,  1552,
    1559,  1560,  1567,  1568,  1575,  1576,  1583,  1584,  1591,  1592,
    1599,  1600,  1607,  1608,  1615,  1616,  1617,  1618,  1621,  1622,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1644,  1657,
    1669,  1682,  1695,  1708,  1722,  1735,  1748,  1762,  1776,  1789,
    1803,  1816,  1830,  1832,  1843,  1844,  1855,  1856,  1857,  1858,
    1859,  1860,  1866,  1867,  1877,  1878,  1879,  1880,  1881,  1882,
    1896,  1897,  1904,  1905,  1906,  1907,  1908,  1909,  1910,  1911,
    1912,  1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,
    1928,  1929,  1936,  1937,  1944,  1951,  1952,  1953,  1980,  1981,
    1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,
    1992,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,
    2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    2018,  2019,  2028,  2029,  2038,  2039,  2048,  2049,  2058,  2059,
    2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,  2077,
    2078,  2079,  2080,  2081,  2082,  2083,  2084,  2085,  2086,  2087,
    2088,  2089,  2090,  2091,  2093,  2094,  2095,  2096,  2098,  2100,
    2101,  2102,  2105,  2106,  2109,  2110,  2111,  2114,  2115,  2118,
    2119,  2120,  2128,  2133,  2138,  2143,  2148,  2151,  2156,  2164,
    2170,  2176,  2182,  2183,  2189,  2195,  2201,  2202,  2212,  2213,
    2223,  2224,  2233,  2242,  2243,  2252,  2261,  2270,  2271,  2277,
    2278,  2284,  2288,  2289,  2292,  2321,  2336,  2337,  2341,  2352,
    2353,  2357,  2358,  2362,  2369,  2385,  2386,  2389,  2392,  2399,
    2415,  2419,  2420,  2425,  2425,  2432,  2433,  2435,  2434,  2457,
    2462,  2465,  2472,  2488,  2491,  2494,  2501,  2517,  2520,  2523,
    2540,  2543,  2544,  2545,  2546,  2547,  2548,  2570,  2571,  2572,
    2573,  2576,  2577,  2578,  2579,  2582,  2583,  2589,  2590,  2591,
    2592,  2593,  2594,  2595,  2598,  2599,  2600,  2601,  2608,  2609,
    2610,  2617,  2618,  2619,  2623,  2624,  2625,  2626,  2627,  2632,
    2633,  2636,  2637,  2638,  2644,  2646,  2648,  2649,  2651,  2653,
    2655,  2657,  2659,  2660,  2662,  2663,  2664,  2665,  2667,  2669,
    2671,  2673,  2675,  2677,  2678,  2714,  2716,  2718,  2720,  2723,
    2725,  2727,  2729,  2733,  2734,  2745,  2746,  2750,  2751,  2766,
    2781,  2782,  2785,  2786,  2787,  2801,  2802,  2817,  2832,  2834,
    2841,  2883,  2884,  2887,  2888,  2889,  2892,  2893,  2894,  2895,
    2896,  2897,  2898,  2899,  2902,  2910,  2920,  2937,  2944,  2951,
    2958,  2965,  2970,  2975,  2976,  2977,  2978,  2979,  2982,  2991,
    2998,  3023,  3039,  3040,  3045,  3064,  3073,  3085,  3100,  3101,
    3104,  3104,  3114,  3115,  3116,  3117,  3118,  3119,  3120,  3121,
    3122,  3125,  3128,  3129,  3132,  3139,  3142,  3149,  3155,  3156,
    3165,  3166,  3167,  3170,  3171,  3183,  3207,  3218,  3249,  3253,
    3263,  3277,  3289,  3290,  3292,  3293,  3294,  3308,  3309,  3310,
    3311,  3312,  3313,  3314,  3318,  3319,  3320,  3333,  3339,  3340,
    3341,  3342,  3343,  3344,  3345,  3346,  3347,  3348,  3349,  3350,
    3351,  3352,  3353,  3371,  3372,  3373,  3374,  3375,  3376,  3377,
    3385,  3386,  3387,  3388,  3389,  3390,  3391,  3392,  3393,  3394,
    3395,  3397,  3399,  3400,  3401,  3402,  3403,  3404,  3407,  3425,
    3426,  3427,  3430,  3431,  3432,  3433,  3434,  3435,  3436,  3437,
    3438,  3439,  3440,  3441,  3442,  3443,  3444,  3445,  3446,  3447,
    3448,  3449,  3450,  3451,  3452,  3453,  3454,  3455,  3456,  3457,
    3458,  3459,  3460,  3461,  3462,  3463,  3464,  3472,  3480,  3488,
    3496,  3504,  3512,  3520,  3528,  3536,  3537,  3539,  3547,  3555,
    3563,  3572,  3581,  3590,  3598,  3607,  3615,  3616,  3618,  3621,
    3622,  3623,  3624,  3631,  3638,  3639,  3645,  3652,  3653,  3659,
    3666,  3667,  3673,  3676,  3679,  3680,  3681,  3684,  3685,  3686,
    3695,  3704,  3705,  3706,  3707,  3708,  3709,  3710,  3711,  3712,
    3713,  3714,  3715,  3716,  3717,  3718,  3719,  3720,  3721,  3725,
    3729,  3730,  3731,  3732,  3733,  3734,  3735,  3736,  3737,  3738,
    3739,  3740,  3741,  3742,  3743,  3744,  3745,  3746,  3747,  3748,
    3749,  3750,  3751,  3752,  3753,  3754,  3755,  3756,  3764,  3772,
    3780,  3781,  3783,  3785,  3796,  3797,  3798,  3814,  3815,  3816,
    3820,  3823,  3824,  3827,  3830,  3833,  3836,  3839,  3842,  3845,
    3848,  3851,  3854,  3855,  3856,  3859,  3860,  3861,  3861,  3894,
    3896,  3898,  3899,  3902,  3919,  3923,  3927,  3931,  3936,  3940,
    3945,  3949,  3953,  3957
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FORWARD",
  "FORWARD_TCP", "FORWARD_TLS", "FORWARD_SCTP", "FORWARD_UDP", "EXIT",
  "DROP", "RETURN", "RETURN_MODE", "BREAK", "LOG_TOK", "ERROR", "ROUTE",
  "ROUTE_REQUEST", "ROUTE_FAILURE", "ROUTE_ONREPLY", "ROUTE_REPLY",
  "ROUTE_BRANCH", "ROUTE_SEND", "ROUTE_EVENT", "EXEC", "SET_HOST",
  "SET_HOSTPORT", "SET_HOSTPORTTRANS", "PREFIX", "STRIP", "STRIP_TAIL",
  "SET_USERPHONE", "APPEND_BRANCH", "REMOVE_BRANCH", "CLEAR_BRANCHES",
  "SET_USER", "SET_USERPASS", "SET_PORT", "SET_URI", "REVERT_URI",
  "FORCE_RPORT", "ADD_LOCAL_RPORT", "LOCAL_RPORT", "FORCE_TCP_ALIAS",
  "UDP_MTU", "UDP_MTU_TRY_PROTO", "UDP4_RAW", "UDP4_RAW_MTU",
  "UDP4_RAW_TTL", "IF", "ELSE", "SET_ADV_ADDRESS", "SET_ADV_PORT",
  "FORCE_SEND_SOCKET", "SET_FWD_NO_CONNECT", "SET_RPL_NO_CONNECT",
  "SET_FWD_CLOSE", "SET_RPL_CLOSE", "SWITCH", "CASE", "DEFAULT", "WHILE",
  "CFG_SELECT", "CFG_RESET", "URIHOST", "URIPORT", "MAX_LEN", "SETFLAG",
  "RESETFLAG", "ISFLAGSET", "SETAVPFLAG", "RESETAVPFLAG", "ISAVPFLAGSET",
  "METHOD", "URI", "FROM_URI", "TO_URI", "SRCIP", "SRCPORT", "DSTIP",
  "DSTPORT", "TOIP", "TOPORT", "SNDIP", "SNDPORT", "SNDPROTO", "SNDAF",
  "PROTO", "AF", "MYSELF", "MSGLEN", "UDP", "TCP", "TLS", "SCTP", "WS",
  "WSS", "DEBUG_V", "FORK", "FORK_DELAY", "MODINIT_DELAY", "LOGSTDERROR",
  "LOGFACILITY", "LOGNAME", "LOGCOLOR", "LOGPREFIX", "LOGPREFIXMODE",
  "LOGENGINETYPE", "LOGENGINEDATA", "XAVPVIAPARAMS", "XAVPVIAFIELDS",
  "XAVPVIAREPLYPARAMS", "LISTEN", "ADVERTISE", "VIRTUAL", "STRNAME",
  "ALIAS", "SR_AUTO_ALIASES", "DOMAIN", "SR_AUTO_DOMAINS", "DNS",
  "REV_DNS", "DNS_TRY_IPV6", "DNS_TRY_NAPTR", "DNS_SRV_LB", "DNS_UDP_PREF",
  "DNS_TCP_PREF", "DNS_TLS_PREF", "DNS_SCTP_PREF", "DNS_RETR_TIME",
  "DNS_SLOW_QUERY_MS", "DNS_RETR_NO", "DNS_SERVERS_NO", "DNS_USE_SEARCH",
  "DNS_SEARCH_FMATCH", "DNS_NAPTR_IGNORE_RFC", "DNS_CACHE_INIT",
  "DNS_USE_CACHE", "DNS_USE_FAILOVER", "DNS_CACHE_FLAGS",
  "DNS_CACHE_NEG_TTL", "DNS_CACHE_MIN_TTL", "DNS_CACHE_MAX_TTL",
  "DNS_CACHE_MEM", "DNS_CACHE_GC_INT", "DNS_CACHE_DEL_NONEXP",
  "DNS_CACHE_REC_PREF", "AUTO_BIND_IPV6", "BIND_IPV6_LINK_LOCAL",
  "IPV6_HEX_STYLE", "DST_BLST_INIT", "USE_DST_BLST", "DST_BLST_MEM",
  "DST_BLST_TTL", "DST_BLST_GC_INT", "DST_BLST_UDP_IMASK",
  "DST_BLST_TCP_IMASK", "DST_BLST_TLS_IMASK", "DST_BLST_SCTP_IMASK",
  "IP_FREE_BIND", "PORT", "STAT", "STATS_NAMESEP", "CHILDREN", "SOCKET",
  "BIND", "WORKERS", "SOCKET_WORKERS", "ASYNC_WORKERS", "ASYNC_USLEEP",
  "ASYNC_NONBLOCK", "ASYNC_WORKERS_GROUP", "CHECK_VIA", "PHONE2TEL",
  "MEMLOG", "MEMDBG", "MEMSUM", "MEMSAFETY", "MEMADDSIZE", "MEMJOIN",
  "MEMSTATUSMODE", "SIP_PARSER_LOG_ONELINE", "SIP_PARSER_LOG",
  "SIP_PARSER_MODE", "CORELOG", "SIP_WARNING", "SERVER_SIGNATURE",
  "SERVER_HEADER", "USER_AGENT_HEADER", "REPLY_TO_VIA", "LOADMODULE",
  "LOADMODULEX", "LOADPATH", "MODPARAM", "MODPARAMX", "CFGENGINE",
  "MAXBUFFER", "MAXSNDBUFFER", "SQL_BUFFER_SIZE", "MSG_RECV_MAX_SIZE",
  "TCP_MSG_READ_TIMEOUT", "TCP_MSG_DATA_TIMEOUT", "TCP_ACCEPT_IPLIMIT",
  "TCP_CHECK_TIMER", "USER", "GROUP", "CHROOT", "WDIR", "RUNDIR", "MHOMED",
  "DISABLE_TCP", "TCP_ACCEPT_ALIASES", "TCP_ACCEPT_UNIQUE",
  "TCP_CONNECTION_MATCH", "TCP_CHILDREN", "TCP_CONNECT_TIMEOUT",
  "TCP_SEND_TIMEOUT", "TCP_CON_LIFETIME", "TCP_POLL_METHOD",
  "TCP_MAX_CONNECTIONS", "TLS_MAX_CONNECTIONS", "TCP_NO_CONNECT",
  "TCP_SOURCE_IPV4", "TCP_SOURCE_IPV6", "TCP_OPT_FD_CACHE",
  "TCP_OPT_BUF_WRITE", "TCP_OPT_CONN_WQ_MAX", "TCP_OPT_WQ_MAX",
  "TCP_OPT_RD_BUF", "TCP_OPT_WQ_BLK", "TCP_OPT_DEFER_ACCEPT",
  "TCP_OPT_DELAYED_ACK", "TCP_OPT_SYNCNT", "TCP_OPT_LINGER2",
  "TCP_OPT_KEEPALIVE", "TCP_OPT_KEEPIDLE", "TCP_OPT_KEEPINTVL",
  "TCP_OPT_KEEPCNT", "TCP_OPT_CRLF_PING", "TCP_OPT_ACCEPT_NO_CL",
  "TCP_OPT_ACCEPT_HEP3", "TCP_OPT_ACCEPT_HAPROXY", "TCP_OPT_CLOSE_RST",
  "TCP_CLONE_RCVBUF", "TCP_REUSE_PORT", "TCP_WAIT_DATA", "TCP_SCRIPT_MODE",
  "DISABLE_TLS", "ENABLE_TLS", "TLS_THREADS_MODE", "TLSLOG", "TLS_PORT_NO",
  "TLS_METHOD", "TLS_HANDSHAKE_TIMEOUT", "TLS_SEND_TIMEOUT", "SSLv23",
  "SSLv2", "SSLv3", "TLSv1", "TLS_VERIFY", "TLS_REQUIRE_CERTIFICATE",
  "TLS_CERTIFICATE", "TLS_PRIVATE_KEY", "TLS_CA_LIST", "DISABLE_SCTP",
  "ENABLE_SCTP", "SCTP_CHILDREN", "ADVERTISED_ADDRESS", "ADVERTISED_PORT",
  "DISABLE_CORE", "OPEN_FD_LIMIT", "SHM_MEM_SZ", "SHM_FORCE_ALLOC",
  "MLOCK_PAGES", "REAL_TIME", "RT_PRIO", "RT_POLICY", "RT_TIMER1_PRIO",
  "RT_TIMER1_POLICY", "RT_TIMER2_PRIO", "RT_TIMER2_POLICY",
  "MCAST_LOOPBACK", "MCAST_TTL", "MCAST", "TOS", "PMTU_DISCOVERY",
  "KILL_TIMEOUT", "MAX_WLOOPS", "PVBUFSIZE", "PVBUFSLOTS", "PVCACHELIMIT",
  "PVCACHEACTION", "HTTP_REPLY_PARSE", "VERSION_TABLE_CFG",
  "VERBOSE_STARTUP", "ROUTE_LOCKS_SIZE", "WAIT_WORKER1_MODE",
  "WAIT_WORKER1_TIME", "WAIT_WORKER1_USLEEP", "CFG_DESCRIPTION",
  "SERVER_ID", "KEMI", "REQUEST_ROUTE_CALLBACK", "ONSEND_ROUTE_CALLBACK",
  "REPLY_ROUTE_CALLBACK", "EVENT_ROUTE_CALLBACK",
  "RECEIVED_ROUTE_CALLBACK", "RECEIVED_ROUTE_MODE", "PRE_ROUTING_CALLBACK",
  "MAX_RECURSIVE_LEVEL", "MAX_BRANCHES_PARAM", "LATENCY_CFG_LOG",
  "LATENCY_LOG", "LATENCY_LIMIT_DB", "LATENCY_LIMIT_ACTION",
  "LATENCY_LIMIT_CFG", "RPC_EXEC_DELTA_CFG", "MSG_TIME", "ONSEND_RT_REPLY",
  "URI_HOST_EXTRA_CHARS", "HDR_NAME_EXTRA_CHARS", "FLAGS_DECL",
  "AVPFLAGS_DECL", "ATTR_MARK", "SELECT_MARK", "ATTR_FROM", "ATTR_TO",
  "ATTR_FROMURI", "ATTR_TOURI", "ATTR_FROMUSER", "ATTR_TOUSER",
  "ATTR_FROMDOMAIN", "ATTR_TODOMAIN", "ATTR_GLOBAL", "ADDEQ", "SUBST",
  "SUBSTDEF", "SUBSTDEFS", "EQUAL", "LOG_OR", "LOG_AND", "BIN_OR",
  "BIN_AND", "BIN_XOR", "BIN_LSHIFT", "BIN_RSHIFT", "EQUAL_T", "DIFF",
  "MATCH", "INTEQ", "INTDIFF", "STREQ", "STRDIFF", "GT", "LT", "GTE",
  "LTE", "PLUS", "MINUS", "STAR", "SLASH", "MODULO", "NOT", "UNARY",
  "BIN_NOT", "DEFINED", "INTCAST", "STRCAST", "DOT", "STRLEN", "STREMPTY",
  "SELVAL", "NUMBER", "ID", "NUM_ID", "STRING", "IPV6ADDR", "PVAR",
  "AVP_OR_PVAR", "EVENT_RT_NAME", "COMMA", "SEMICOLON", "RPAREN", "LPAREN",
  "LBRACE", "RBRACE", "LBRACK", "RBRACK", "CR", "COLON", "$accept", "cfg",
  "statements", "statement", "$@1", "$@2", "$@3", "$@4", "$@5",
  "listen_id", "listen_id_lst", "listen_id2", "proto", "eqproto", "xproto",
  "port", "phostport", "listen_phostport", "id_lst", "intno", "flags_decl",
  "flag_list", "flag_spec", "flag_name", "avpflags_decl", "avpflag_list",
  "avpflag_spec", "socket_lattr", "socket_lattrs", "assign_stm", "$@6",
  "cfg_var_id", "cfg_var_idn", "cfg_var", "module_stm", "ip", "ipv4",
  "ipv6addr", "ipv6", "route_name", "route_main", "route_stm",
  "failure_route_main", "failure_route_stm", "route_reply_main",
  "onreply_route_stm", "$@7", "$@8", "branch_route_main",
  "branch_route_stm", "send_route_main", "send_route_stm",
  "event_route_main", "event_route_stm", "preprocess_stm", "equalop",
  "cmpop", "strop", "rve_equalop", "rve_cmpop", "uri_type",
  "eint_op_onsend", "eint_op", "eip_op_onsend", "eip_op", "exp_elem",
  "ipnet", "host", "host_if_id", "host_or_if", "fcmd", "stm", "actions",
  "action", "if_cmd", "ct_rval", "single_case", "case_stms", "switch_cmd",
  "while_cmd", "select_param", "select_params", "select_id", "$@9",
  "attr_class_spec", "attr_name_spec", "attr_spec", "attr_mark", "attr_id",
  "attr_id_num_idx", "attr_id_no_idx", "attr_id_ass", "attr_id_any",
  "attr_id_any_str", "pvar", "avp_pvar", "assign_op", "lval", "rval",
  "rve_un_op", "rval_expr", "assign_action", "avpflag_oper", "cmd", "$@10",
  "func_params", "func_param", "ret_cmd", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-998)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2771,  -285,  -251,     8,    17,  -245,  -198,  -190,  -178,  -153,
    -126,   -68, -1326,   -64,   -58,   -53,   168,   346,   402,   405,
     498,   555,   597,   601,   605,   608,   625,   626,   642,   645,
     704,   722,   723,   728,   754,    19,    25,   326,   718,   747,
     899,   903,   939,   943,   946,   947,   950,   952,   971,   972,
     979,   982,   983,   984,   985,   986,   987,   989,   990,   997,
     998,  1005,  1006,  1010,  1012,  1021,  1022,  1031,  1033,  1035,
    1036,  1037,   758,   770,   777,   806, -1326,   847,   848,   849,
     886,   889,   890,   894,   922,   927,   930,   936,   940,   948,
     977,   995,  1003,  1008,  1011,  1019,  1020,  1034,  1038,  1047,
      27,    75,   159,    38,    54,   233,  1052,  1057,  1065,  1074,
    1078,  1096,  1097,  1102,  1122,  1125,  1138,  1139,  1148,  1149,
    1154,  1158,  1173,  1175,  1176,  1178,  1179,  1180,  1181,  1188,
    1190,  1191,  1258,  1269,  1270,  1271,  1045,  1050,  1051,  1055,
    1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1287,
    1288,  1289,  1290,  1292,  1293,  1299,  1300,  1301,  1302,  1305,
    1306,  1307,  1309,  1311,  1312,  1313,  1315,  1316,  1317,  1318,
    1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1329,
    1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1365,  1366,
    1367,  1056,  1368,  1370,  1371,  1372,  1373,  1374,  1376,  1377,
    1378,  1379,  1380,  1381,  1382,  1383,  -145,  1384,  1409,  1410,
    1411,  1451,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
      82,   130,   101,   202,   245, -1326, -1326, -1326,   360,  1799,
   -1326,   473,   300,   620,   639,   301, -1326, -1326, -1326,  -336,
   -1326, -1326,   -37, -1326, -1326, -1326,   247, -1326,  -328, -1326,
     249,   270,   290,   935,   347,   350,   351,   366,   357,   358,
     367,   369,    46,   254,   378,   269,   387,   275,   276,   280,
     281,   288,    32,    52,   388,   145,   589,   610,   672, -1326,
       0, -1326,   706, -1326,   712, -1326,  -270, -1326,  -270, -1326,
    -270, -1326,  -270, -1326,   729, -1326,   757, -1326,   771, -1326,
     778, -1326,   790, -1326,   802, -1326,   845, -1326,   861, -1326,
     864, -1326,   878, -1326,   923, -1326,   926, -1326,   933, -1326,
     954, -1326,   970, -1326,  1015, -1326,  1100, -1326,  1431, -1326,
    1432, -1326,  1433, -1326,   310, -1326,  1434, -1326,  1435, -1326,
    1436, -1326,  1442, -1326,  1452, -1326,  1461, -1326,  1462, -1326,
    1463, -1326,  1464,   373,   702,   291,   705,  1485,   716,   719,
     733,   749,   292,   752,   753,   374,   375,   376,   384,   386,
     394,   452,   489,   491,   492,   493,   755,   761,   293,   294,
     762, -1326, -1326,   725, -1326, -1326,  1424, -1326,   295, -1326,
   -1326,  1450, -1326,  1465, -1326,   296, -1326,   763,   765,   767,
     768,   774,   775,   776,   779,   134,   209,   217,   242,   243,
     780,   781,   782,   783,   784,   785,   522,   557,   584,   250,
     786,   787,   788,   789,    23,   791,   792, -1326,  1470, -1326,
    1476, -1326,  1477, -1326,  1478,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   803,   804,   805,   809,   810,   811,
     586,   607,   816,   817,   818,   819,   823,   807,   824,   825,
     826,   827,   297,   298,   302,   828,   829,   830,    58,   831,
     833,   835,   836,   837,   838,   839,   840,   841,   842,   844,
     846,   853,   854,   866,   255,   344, -1326,  1479,   867,   868,
     870,   872,   873,   876,   877,   303,   881,   882,   895,   897,
     898,   901,  1177,   658,  1480,  1481,   673,   701,   904,   907,
     908,   910,   911,   917,   304,   305, -1326, -1326, -1326, -1326,
    1446,   760, -1326, -1326, -1326,  1447, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326,  -285, -1326,    28,    55,  1471, -1326,    36,
    1472, -1326,    61,  1473, -1326,    67,  1474, -1326,    11,  1445,
   -1326,   -17,  1482, -1326, -1326, -1326, -1326, -1326, -1326,   832,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  1508, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,  1514, -1326, -1326, -1326, -1326,  1134,   766, -1326,
    1494,  1495,  1129,   116, -1326, -1326, -1326, -1326, -1326,  -219,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1501, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  -175,  -139, -1326, -1326,  1506,  1507,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,  1514, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1550,
    1551,  1552,  1553,  1554,  1555, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  -115,
    1522,  -115, -1326,  -328, -1326, 12642, -1326,  -328, 12642, -1326,
    -328, 12642, -1326,  -328, 12642, -1326,  1516, -1326, -1326, -1326,
    1574,  1526, 12642,    68, -1326,  1542,  1580,  1582,  1578,   494,
    1092, -1326,  1260, -1326,  1679,   189,   341,  1248,  1680, -1326,
    1681, -1326,  1682,  1723,   306,   307,   308,   311,   312,   313,
   -1326, -1326, -1326,  1714,    57,    59,    76,    77,    84, 11461,
   11548, 11637, -1326,    88,   102,   103,  1719,   104,   105,   131,
     139,   140,   149,   152,   153,  1720,   155,   156,   160,   165,
    1721,  1722,  1724,  1739,  1740, 12018,   166,   171,   177,  1741,
    1742,  1743,  1744,  6503, 12018,   184,   185,   186,   187,   191,
   -1326, -1326, -1326, -1326,   193, -1326, -1326, -1326,    65,  3912,
   -1326, -1326, -1326, -1326,  1121, -1326, -1326, -1326, -1326, -1326,
    1790,  1748,   197, -1326,  1749,  1745,  3983,  1746,  4054,  1750,
    4212,  1751,   226,  1763,  4436, -1326,  1778,  1795,  1134, -1326,
   -1326, -1326, -1326, -1326, -1326,  1775, -1326, -1326, -1326, -1326,
   -1326, -1326,   -73,  1776,  2052, -1326, -1326, -1326, -1326, -1326,
    1829,  1830,  1831,  1832,  1833, -1326, -1326,  1267,  1791,  1792,
    1796,  1797, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  1794, -1326,   126, -1326,     9, -1326,
     154, -1326,   169, -1326,   238,   751, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326,   905, -1326,   905,
   -1326,   967, -1326, -1326,  1508, -1326, -1326,  6886,  6975,  7064,
    1798,  1801,  1802, -1326,  5853, 12561, -1326,   883, -1326,   650,
   -1326,   960, -1326, -1326, -1326,  1121, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326,  7447,  3357,  5942,  3357,  6325,  3357, -1326,
     259, -1326,   317, -1326,  7536,  1804, -1326,   319, -1326,   321,
   -1326,   323, -1326,   324, -1326,   919, -1326,   920, -1326,  1793,
   -1326,   225,  1814, -1326,   325, -1326,   327, -1326,   331, -1326,
     333,  1819,  1820,  1821,   128,   957,  7625, 12105, -1326,   106,
   -1326,   924, -1326,    89,  1822,  1823,  1824,  1825, -1326,  1211,
   12105, -1326,   335, -1326,   336, -1326,   708, -1326,   714, -1326,
     734, -1326,  1843, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1815, -1326,
    1842, -1326, 12018, -1326, -1326,   279, -1326,  1846, -1326,  1847,
   -1326,  1848, -1326,  1850, -1326,  1917,  1944,   -17, -1326, 12642,
    1872, -1326,  -222, -1326,  1873,  1877,  1134, -1326,  1238,   928,
     337,   273,   932, -1326, -1326, -1326, -1326,  -278,   -55, 12642,
    1868,   -96, -1326,   -40, -1326,   573,  -174,  1876,   661,   690,
     740,  -166,  1885,   750,   756,   812,  -148,  1890,   879,   965,
     988,   746,  1891,  1004,  1049,  1079,  1062, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  8008,  5375,  5758, -1326,  1362,  1901,
   -1326, -1326, -1326, -1326, -1326, -1326,  8097,  8186,  8569,  1893,
   -1326,  1938,  1939,  1940,  1949,  1341,  1915,  1914,  4512, -1326,
    8658, -1326, -1326, -1326, -1326, -1326,  8747,  9130, -1326,  3141,
    1916, -1326, -1326,  9219,  9308,  9691,  9780, 12018, 12018, 12018,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,  9869, 10252, 10341, 10430, 10813, 10902, 10991, -1326, -1326,
    1919,  1923,  1932,  1933,  1925,  1937,    34,  1385,  1947,  1956,
    1961,  1962,  1963,  1964,  1965,  1966,  1967,  1976,  1986,  1988,
    1990, -1326,  1991, -1326,  1992, -1326,  1994,  2003,  2004,  2008,
    2009,  2010,  2018,  2027, -1326, -1326, -1326,  2032,  2033, -1326,
    2034,  2035, 12642,  2270, -1326,  2036,  2037,  2038,  2047,  2057,
    2054,  2055,  2059, -1326, -1326, -1326, -1326,    15, -1326,  2063,
    1941,  2065,  2074,  2075,  2079,  2080,  2081,  2111,  2112, 12018,
    2122,  2109,  3357,  1089, -1326,  1121, -1326,  2117, -1326, 12642,
   12642, 12642, 12642,  2123,  2124,  2162,  4594,  2133, -1326,  2388,
     -43,  2114,  2115,  2116, -1326, -1326, -1326, -1326, -1326,  2119,
    2120, -1326, -1326,  2128,  2129,  2130,  2132,  2134,  4665, -1326,
     -14, -1326,  2143, -1326,  2145, -1326,   164,   173,  2146, -1326,
   -1326,   144, -1326,  2147, -1326,  2148, -1326,  2149, -1326, -1326,
     696, -1326,  2150, -1326,  2174, -1326,  2175, -1326, -1326,   710,
   -1326,  2176, -1326,  2177, -1326,  2178, -1326, -1326,   769, -1326,
    2179, -1326,  2181, -1326,  2182, -1326, -1326,  2255,  1245, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1245, -1326,
   -1326,  1245, -1326, -1326, -1326,  2169, -1326,  2138,  2187,  1800,
    2188,  2131,  2189,  3129, -1326, -1326, -1326, -1326, -1326, -1326,
    2326,  1245, -1326,  1245, -1326,  1164, -1326,  2397,  1514,  2184,
    2196, -1326,  -199,  1245,  -276, -1326,  1233, -1326,  1427, -1326,
    1518, -1326,  3102,  1187,  3303,  1405, -1326,   -95, -1326,   -95,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1245, -1326,  1164,
   -1326,  2183, -1326, -1326,  2185, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326,  4736, 12261, -1326, -1326, -1326,
   -1326, -1326,   523,  1134, -1326,  2190,  6414,  2170, -1326, -1326,
     912, -1326, 12174, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,  3357,  1115, -1326, -1326, -1326,  -115, -1326, -1326,   260,
    4894,  5118,  5194,  5276, -1326, -1326,  -172, -1326,  2191, -1326,
   -1326,  2197,  2202,  2204,  1134,  -222,  1134, -1326, -1326, -1326,
   -1326, -1326, -1326,  2195,  2198,  2199,  2200, -1326, -1326, -1326,
   -1326,  2201,  2203,  2205,  2206,  2207,  2208,  2209,  2210,  2211,
    2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2247,   -99,  1901, -1326, -1326, -1326, -1326, -1326, 12018,
      97,  2192,  2248,  2249, -1326, -1326, -1326, -1326,  2251, -1326,
    2252, 11374,  2253,  3357, 12642, -1326, -1326,  2261,  2502, 12018,
   -1326,  2263,  2264,  2265, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,  2470,  2471, -1326,  2259, -1326,  2262, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,  2266,  2267, -1326,  3286, -1326,  1514, -1326, -1326,
   -1326, -1326,  -222, 12642,  2268,  2269,  3230,  3301, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326,  2275,  2280,  -222, -1326, -1326,
   12018, -1326,  3372, 12642, 12642, -1326,  3530,  2520, -1326, -1326,
    2772,  3754,  3830, -1326, -1326
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,    22,    23,     0,     0,
       4,     0,     0,     0,     0,     0,     8,     9,     6,     0,
     545,    10,     0,    15,     7,   546,     0,   605,     0,   606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   131,     0,   133,     0,   135,     0,   137,     0,   139,
       0,   141,     0,   143,     0,   145,     0,   147,     0,   149,
       0,   151,     0,   153,     0,   155,     0,   157,     0,   159,
       0,   161,     0,   163,     0,   165,     0,   169,     0,   167,
       0,   171,     0,   173,     0,   175,     0,   177,     0,   179,
       0,   183,     0,   181,     0,   185,     0,   187,     0,   189,
       0,   191,     0,   193,     0,   195,     0,   197,     0,   199,
       0,   201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   562,   559,     0,   566,   563,     0,   568,     0,   567,
     573,     0,   577,     0,   579,     0,   578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,   321,
       0,   323,     0,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    72,    71,    65,
      67,    69,    74,    77,    73,    75,   622,   621,   624,   623,
     626,   625,     1,     5,     3,     0,     0,     0,    12,     0,
       0,    14,     0,     0,    17,     0,     0,    19,     0,     0,
      21,     0,     0,   603,   498,   497,   588,   589,   590,     0,
     534,   533,   536,   535,   532,   531,   538,    31,    32,    33,
      34,    35,   537,   540,     0,    63,   539,   542,   541,   544,
     543,    95,    94,    97,    96,    99,    98,   101,   100,   103,
     102,   105,   104,   107,   106,   109,   108,   111,   110,   113,
     112,   115,   114,   117,   116,   119,   118,   121,   120,   123,
     122,   422,   704,   702,   703,    25,   585,     0,     0,    30,
      56,     0,    61,   407,    24,   582,   586,   583,   705,    26,
     424,   423,   428,   427,   426,   425,   430,   429,   125,   124,
     127,   126,   128,   130,   132,   134,   136,   138,   140,   142,
     144,   146,   148,   150,   152,   154,   156,   158,   160,   162,
     164,   168,   166,   170,   172,   174,   176,   178,   182,   180,
     184,   186,   188,   190,   192,   194,   196,   198,   200,   203,
     202,   205,   204,   225,   224,   223,   222,     0,   229,   228,
     231,   230,   233,   232,   235,   234,   237,   236,   239,   238,
     241,   240,   243,   242,   245,   244,   247,   246,   249,   248,
     251,   250,   253,   252,   255,   254,   257,   256,   259,   258,
     261,   260,   263,   262,   265,   264,   396,   395,   398,   397,
     400,   399,   406,   405,     0,     0,   570,   569,     0,     0,
     581,   580,   207,   206,   209,   208,   211,   210,   213,   212,
     215,   214,   217,   216,   219,   218,   221,   220,   270,   269,
     268,   273,   272,   271,   276,   275,   274,   279,   278,   277,
     282,   281,   280,   284,   283,   286,   285,   288,   287,   290,
     289,   292,   291,   294,   293,   296,   295,   298,   297,   300,
     299,   303,   301,   302,   305,   304,   307,   306,   309,   308,
     311,     0,   310,   313,   312,   315,   314,   317,   316,   318,
     320,   322,   324,   327,   326,   329,   328,   331,   330,   333,
     332,   335,   334,   337,   336,   339,   338,   341,   340,   343,
     342,   345,   344,   347,   346,   349,   348,   351,   350,   353,
     352,   355,   354,   357,   356,   359,   358,   361,   360,   363,
     362,   365,   364,   367,   366,   369,   368,   374,   370,   371,
     372,   373,   386,   385,   388,   387,   376,   375,   378,   377,
     380,   379,   382,   381,   384,   383,   390,   389,   392,   391,
     394,   393,   432,   431,   434,   433,   436,   435,   438,   437,
     440,   439,   442,   441,   444,   443,   446,   445,   448,   447,
     450,   449,   452,   451,   454,   453,   456,   455,   458,   457,
     460,   459,   462,   461,   465,   463,   464,   468,   466,   467,
     469,   472,   471,   474,   473,   476,   475,   478,   477,   480,
     479,   482,   481,   484,   483,   267,   266,   486,   485,   488,
     487,   490,   489,   492,   491,   494,   493,   496,   495,     0,
       0,     0,     0,     0,     0,   512,   511,   513,   514,   518,
     517,   516,   515,   520,   519,   522,   521,   524,   523,   526,
     525,   528,   527,   530,   529,   402,   401,   404,   403,     0,
       0,     0,   595,     0,   596,     0,   600,     0,     0,   613,
       0,     0,   617,     0,     0,   620,     0,   550,   551,   549,
       0,     0,     0,     0,    64,     0,    27,     0,     0,     0,
       0,    62,     0,   408,     0,     0,     0,     0,     0,   560,
       0,   564,     0,     0,     0,     0,     0,     0,     0,     0,
      68,    70,    76,     0,     0,     0,     0,     0,     0,  1009,
    1006,  1010,  1013,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,   964,   966,   969,     0,     0,     0,     0,     0,   983,
     985,   987,   989,     0,     0,     0,     0,     0,     0,     0,
     839,   840,   841,   764,     0,   776,   777,   722,     0,     0,
     714,   717,   718,   719,     0,   768,   769,   779,   780,   781,
       0,     0,     0,   710,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   609,     0,     0,     0,    29,
     587,    60,    50,    49,    57,    58,    43,    44,    45,    46,
      47,    48,   418,     0,   409,   709,   704,   707,   708,   706,
       0,     0,     0,     0,     0,    91,    93,     0,     0,     0,
       0,     0,   500,   499,   502,   501,   504,   503,   506,   505,
     508,   507,   510,   509,     0,   852,     0,   874,     0,   885,
       0,   896,     0,   863,     0,     0,   648,   649,   650,   661,
     654,   662,   655,   660,   652,   659,   651,     0,   653,     0,
     656,     0,   657,   750,   796,   794,   795,     0,     0,     0,
       0,     0,     0,   783,     0,     0,   782,     0,   658,     0,
     663,     0,   789,   788,   787,     0,   770,   772,   771,   784,
     785,   786,   797,     0,  1008,     0,  1005,     0,  1012,   900,
       0,   917,     0,   921,     0,     0,   925,     0,   944,     0,
     947,     0,   928,     0,   934,     0,   931,     0,   937,     0,
     940,     0,     0,   953,     0,   956,     0,   950,     0,   959,
       0,     0,     0,     0,     0,     0,     0,     0,   975,     0,
     978,     0,   981,     0,     0,     0,     0,     0,   742,     0,
       0,   992,     0,   995,     0,   904,     0,   907,     0,   910,
       0,   999,     0,   723,   716,   715,   593,   713,   752,   753,
     754,   755,   756,   757,   758,   759,   760,   761,     0,   762,
     765,   778,     0,   721,   915,     0,   720,     0,   598,     0,
     611,     0,   615,     0,   556,   552,   553,     0,   604,     0,
       0,    28,     0,   419,     0,     0,     0,   410,     0,     0,
       0,     0,     0,   227,    92,   561,   565,     0,     0,     0,
       0,     0,   697,     0,   842,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   667,   627,   628,
     636,   629,   630,   635,     0,     0,     0,   692,     0,     0,
     837,   818,   821,   799,   822,   800,     0,     0,     0,     0,
    1007,   770,   771,   785,   786,     0,     0,     0,     0,   671,
       0,   676,   631,   632,   633,   634,     0,     0,   688,     0,
     765,   820,   798,     0,     0,     0,     0,     0,     0,     0,
     637,   638,   643,   639,   640,   641,   642,   644,   645,   646,
     647,     0,     0,     0,     0,     0,     0,     0,  1004,  1011,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   936,     0,   939,     0,   942,     0,     0,     0,     0,
       0,     0,     0,     0,   961,   963,   965,     0,     0,   968,
       0,     0,     0,   724,   711,     0,     0,     0,     0,     0,
      51,     0,     0,   982,   984,   986,   988,     0,   744,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1000,
       0,     0,   838,     0,   775,     0,   773,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,   420,
     411,     0,     0,     0,    90,    89,    84,    83,    82,    81,
       0,    88,    87,     0,     0,     0,     0,     0,     0,   853,
       0,   851,     0,   844,     0,   845,     0,     0,     0,   843,
     875,     0,   873,     0,   866,     0,   867,     0,   865,   886,
       0,   884,     0,   877,     0,   878,     0,   876,   897,     0,
     895,     0,   888,     0,   889,     0,   887,   864,     0,   862,
       0,   855,     0,   856,     0,   854,   666,     0,   664,   682,
      36,    37,    38,    39,    40,    41,    42,   680,   681,   679,
     677,   678,   691,   689,   690,   745,   749,   751,     0,     0,
       0,     0,     0,     0,   793,   815,   792,   791,   790,   670,
       0,   668,   675,   673,   674,   672,   687,     0,    63,     0,
     695,   683,   685,   684,     0,   833,   814,   832,   813,   828,
     806,   829,   807,   808,   809,   810,   823,   801,   824,   802,
     825,   803,   826,   804,   827,   805,   831,   812,   830,   811,
     901,     0,   898,   918,     0,   922,   920,   919,   923,   926,
     924,   945,   943,   948,   946,   929,   927,   935,   933,   932,
     930,   941,   938,   954,   952,   957,   955,   951,   949,   960,
     958,   970,   967,   972,   971,     0,     0,   974,   973,   977,
     976,   980,     0,     0,   979,     0,     0,     0,   741,   739,
       0,   993,     0,   996,   994,   902,   903,   905,   906,   908,
     909,  1003,     0,  1002,   763,   767,     0,   914,   765,     0,
       0,     0,     0,     0,   554,   555,     0,   608,     0,   421,
     413,     0,     0,     0,     0,     0,     0,   571,   572,   574,
     576,   575,   594,     0,     0,     0,     0,   701,   699,   700,
     698,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   834,   816,   835,   817,   836,     0,
       0,     0,     0,     0,   712,   725,    55,    52,    53,   743,
       0,     0,     0,   726,   732,   740,   738,    63,     0,     0,
     998,     0,     0,     0,   599,   612,   616,   619,   557,   558,
     584,   414,   412,    85,     0,    79,    80,   849,   850,   847,
     848,   846,   871,   872,   869,   870,   868,   882,   883,   880,
     881,   879,   893,   894,   891,   892,   890,   860,   861,   858,
     859,   857,     0,     0,   748,     0,   696,   694,   693,   766,
     899,   916,     0,   735,     0,     0,     0,     0,   990,   991,
    1001,   913,   912,   911,   416,     0,     0,     0,   747,   746,
       0,    54,     0,   736,   730,   737,     0,   415,    86,    78,
       0,     0,     0,   417,   819
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1326, -1326, -1326,  2425, -1326, -1326, -1326, -1326, -1326,  -466,
    1537,  1648,  -249,  1273, -1326, -1325, -1326, -1326,   664,  -254,
   -1326,  1683, -1326,  -220, -1326,  1706, -1326,  1513, -1326, -1326,
   -1326, -1326,  1361, -1326, -1326, -1153,  2271,  2043,  2272,   408,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1164, -1326, -1074, -1326, -1326,
    1275, -1326, -1326, -1326,  1303, -1326, -1326,   246,  -840, -1326,
     -75, -1274,  -927, -1026, -1326,   869,   959, -1326, -1326, -1326,
     892, -1326, -1326, -1326, -1326,  1172, -1185,  -414,  -980, -1326,
    -894, -1326, -1326, -1326,  -641,  -937, -1326, -1326, -1326, -1326,
     -20, -1004, -1326, -1326, -1326, -1326,   871, -1326
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   228,   229,   230,   231,   232,   233,   234,   235,   619,
    1007,   620,   621,  1617,  1133,  1124,  1502,   622,   623,  1206,
     236,   519,   520,   521,   237,   524,   525,  1146,  1147,   238,
     357,   239,  1000,   240,   241,   624,   625,   626,   627,   559,
     537,   538,   540,   541,   242,   243,  1002,  1116,   543,   544,
     546,   547,   549,   550,   244,  1383,  1417,  1384,  1446,  1447,
    1207,  1208,  1209,  1210,  1211,  1212,  1651,  1356,   628,   629,
    1213,  1493,  1089,  1090,  1091,  1822,  1729,  1730,  1092,  1093,
    1626,  1627,  1214,  1389,  1308,  1309,  1310,  1215,  1216,  1217,
    1218,  1097,  1219,  1527,  1220,  1221,  1312,  1100,  1222,  1223,
    1405,  1101,  1102,  1103,  1292,  1742,  1743,  1104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     576,   523,   883,   582,   572,  1095,  1508,  1538,  1095,   247,
    1357,  1095,   995,  1355,  1095,  1360,  1725,  1365,   249,  1370,
     279,  1375,  1095,  1385,   803,  1386,   281,  1388,   381,   982,
    1420,   551,   645,   611,   646,  1291,   647,   986,   648,   390,
    1333,  1334,   997,   556,   557,  1416,   558,   591,  1099,   552,
    1773,  1099,   245,   630,  1099,   392,   984,  1099,  1165,   882,
    1167,  1106,   989,  1297,  1108,  1099,  1293,  1110,   992,  1115,
    1760,  1761,  1358,  1726,  1727,  1114,   384,  1169,  1171,   574,
    1297,   574,  1297,   516,  1297,  1173,   246,   574,  1297,  1229,
    1499,  1096,   250,   575,  1096,   575,  1553,  1096,  1876,   680,
    1096,   575,   526,  1231,  1233,  1236,  1238,  1495,  1096,  1095,
    1745,   703,   705,   707,   709,   711,   713,   715,   717,   719,
     721,   723,   567,   568,   569,   570,  1095,  1350,  1095,  1487,
    1095,   522,  1240,  1410,  1095,   758,  1122,  1419,  1015,   251,
    1242,  1244,   567,   568,   569,   570,   634,   252,  1016,  1123,
    1246,  1006,  1099,  1248,  1250,  1362,  1253,  1255,  1566,   253,
     387,  1257,   786,   788,   790,  1777,  1259,  1268,  1567,  1099,
    1367,  1099,  1270,  1099,  1779,  1137,  1139,  1099,  1272,   567,
     568,   569,   570,  1566,   254,  1281,  1283,  1285,  1287,  1351,
    1135,  1566,  1289,  1567,  1291,  1096,   844,   846,  1314,  1838,
    1406,  1567,  1839,   528,  1018,  1568,  1019,  1569,  1782,  1566,
     761,   255,  1096,  1577,  1096,  1578,  1096,  1363,   764,  1567,
    1096,  1406,   502,  1406,  1401,  1095,  1472,  1324,  1012,  1013,
    1014,  1586,  1368,  1587,   394,   567,   568,   569,   570,  1372,
    1020,  1494,  1021,   767,   770,  1401,   530,  1401,   554,   956,
     560,   791,   960,   962,  1494,   593,   914,   517,   574,   518,
    1450,  1832,  1406,  1443,  1444,  1445,  1650,  1404,  1099,   256,
     597,   562,   575,   257,  1548,  1872,   601,   603,  1408,   258,
    1523,   605,   607,  1560,   259,  1561,  1401,  1095,  1404,   609,
    1404,   564,   683,   696,   728,   730,   736,   740,   870,   872,
    1095,  1373,   574,   874,   935,   975,   977,  1152,  1154,  1156,
    1402,  1096,  1158,  1160,  1162,  1335,   575,   539,  1453,  1555,
    1459,  1556,  1461,   548,  1463,  1465,  1476,   283,  1478,  1404,
    1099,  1402,  1480,  1402,  1482,  1526,  1509,  1511,  1546,  1562,
    1748,  1563,  1138,  1099,  1098,   917,   553,  1098,   573,  1095,
    1098,   577,   579,  1098,   998,   999,   280,  1774,   583,   585,
     532,  1098,   282,   567,   568,   569,   570,   581,   587,  1095,
     589,   642,  1402,  1096,   679,   702,   704,   706,  1528,   595,
     801,  1352,  1297,  1359,   616,   708,  1096,   710,   599,   632,
     571,  -601,  1099,   248,   618,   712,  -618,  1817,   616,  1728,
    -602,   382,  1536,   612,   613,   614,   615,   616,   618,   383,
     571,  -591,  1099,   983,   617,  1686,  -997,   618,   592,  -597,
     391,   987,  1558,   612,   613,   614,   615,   616,  1095,   612,
     613,   614,   615,   616,   617,  1096,   393,   618,  -592,  1166,
    1845,  1168,  1815,   618,  -610,  1294,   990,   571,  1098,   385,
    -614,  -607,   993,   714,   517,  1096,   518,   386,  1170,  1172,
     612,   613,   614,   615,   616,  1098,  1174,  1098,  1877,  1098,
    1230,  1099,   616,  1098,   618,   527,  1388,   612,   613,   614,
     615,   616,   618,  1388,  1232,  1234,  1237,  1239,   535,   536,
     716,   618,   718,   720,   722,  1121,   388,   801,  1352,  1488,
    1353,   616,   517,   571,   518,   260,   759,  1354,   760,  1489,
    1297,   618,  1095,  1241,  1096,  1783,   612,   613,   614,   615,
     616,  1243,  1245,   785,  1816,   801,  1352,   617,  1364,   616,
     618,  1247,  1297,   389,  1249,  1251,  1778,  1254,  1256,   618,
     801,  1352,  1258,  1369,   616,  1780,  1132,  1260,  1269,  1095,
    1095,  1095,  1095,  1271,   618,  1099,  1095,  1901,   787,  1273,
    1136,   613,   614,  1403,  1098,  1715,  1282,  1284,  1286,  1288,
     395,  1094,  1909,  1290,  1094,  -997,   529,  1094,  1095,  1315,
    1094,   762,   574,   763,  1403,   789,  1403,   843,  1094,   765,
     636,   766,  1099,  1099,  1099,  1099,   575,  1325,  1096,  1099,
    1326,  1083,  1750,  1751,  1752,  1753,  1473,   396,   845,   801,
    1352,   638,  1374,   616,   768,   771,   769,   772,   555,   531,
     561,  1099,   792,   618,   793,  1403,  1098,   915,   594,   916,
    1451,   571,   517,  1452,   518,  1096,  1096,  1096,  1096,  1098,
     542,   563,  1096,   598,   612,   613,   614,   615,   616,   602,
     604,  1411,  1006,  1524,   606,   608,  1086,  1878,   618,   955,
     545,   565,   610,   284,  1096,   684,   697,   729,   731,   737,
     741,   871,   873,   640,   959,  1094,   875,   936,   976,   978,
    1153,  1155,  1157,   261,   669,  1159,  1161,  1163,  1098,  1297,
    1494,  1454,  1094,  1460,  1094,  1462,  1094,  1464,  1466,  1477,
    1094,  1479,   961,   681,   574,  1481,   685,  1483,  1098,  1510,
    1512,  1547,  1136,   613,   614,   918,   919,   688,   575,   285,
     690,   578,   580,   574,  1297,  1297,  1297,  1297,   584,   586,
     574,   574,   574,   574,   692,  1095,  1095,   575,   588,   262,
     590,   574,   263,   574,   575,   575,   575,   575,   287,   596,
     694,   574,  1377,   698,   700,   575,   724,   575,   600,   633,
    1787,   523,   726,   732,   742,   575,   744,  1098,   746,   748,
    1095,  1095,  1095,  1095,  1792,   750,   752,   754,  1099,  1099,
     756,   773,   775,   777,   779,   781,   783,   794,   796,   798,
     800,  1094,   805,   807,   813,   815,   817,   819,   821,   823,
     825,   827,   829,  1496,   831,   833,   835,  1500,   857,   574,
     837,   839,   841,  1099,  1099,  1099,  1099,   847,   849,   851,
     853,  1096,  1096,   575,   855,   862,   864,   866,   868,   876,
     878,   880,   884,  1797,   886,   264,   888,   890,   892,   894,
     896,   898,   900,   902,  1095,   904,   574,   906,   574,   574,
     574,  1098,  1122,  1094,   908,   910,  1096,  1096,  1096,  1096,
     575,  1297,   575,   575,   575,  1123,  1094,   912,   921,   923,
    1541,   925,  1542,   927,   929,  1549,  1297,   931,   933,   574,
    1297,  1122,   937,   939,  1409,  1297,  1297,  1099,  1098,  1098,
    1098,  1098,   265,   575,  1123,  1098,   941,  1887,   943,   945,
     289,  1525,   947,  1095,   291,   963,  1095,  1095,   965,   967,
    1088,   969,   971,  1088,   574,  1094,  1088,  1098,   973,  1088,
    1467,  1469,  1095,  1095,  1095,  1497,  1095,  1088,   575,  1544,
    1096,  1095,  1095,  1551,   266,  1094,   566,   631,   267,   635,
     293,   574,   268,   574,   295,   269,  1099,   297,   299,  1099,
    1099,   301,  1564,   303,  1565,   575,  1902,   575,  1490,  1906,
     637,  1418,   270,   271,   574,  1099,  1099,  1099,  1387,  1099,
    1726,  1727,   305,   307,  1099,  1099,  1911,  1912,   575,   272,
     309,   639,   273,   311,   313,   315,   317,   319,   321,  1096,
     323,   325,  1096,  1096,  1094,  1378,  1379,  1474,   327,   329,
    1381,  1382,  1412,  1413,  1414,  1415,   331,   333,  1096,  1096,
    1096,   335,  1096,   337,  1088,   574,  1491,  1096,  1096,  1224,
    1226,  1228,   339,   341,  1501,   567,   568,   569,   570,   575,
     574,  1088,   343,  1088,   345,  1088,   347,   349,   351,  1088,
    1571,   274,  1572,   641,   575,  1267,   427,   567,   568,   569,
     570,   429,   431,  1279,  1280,   286,   433,   486,   574,   275,
     276,   858,   859,   860,   861,   277,  1514,  1788,  1516,  1573,
    1518,  1574,   575,   682,  1098,  1098,   686,   643,  1094,  1513,
     517,  1793,   518,   644,   288,  1515,   517,   689,   518,  1543,
     691,   278,  1550,  1554,  1557,   353,  1378,  1379,  1380,   734,
     649,  1381,  1382,  1566,   693,  1517,   517,   354,   518,  1098,
    1098,  1098,  1098,  1567,   355,  1094,  1094,  1094,  1094,  1575,
     695,  1576,  1094,   699,   701,  1595,   725,  1596,   650,  1580,
    1088,  1581,   727,   733,   743,  1582,   745,  1583,   747,   749,
    1798,   616,   651,   356,  1094,   751,   753,   755,   980,   652,
     757,   774,   776,   778,   780,   782,   784,   795,   797,   799,
     801,   653,   806,   808,   814,   816,   818,   820,   822,   824,
     826,   828,   830,   654,   832,   834,   836,  1391,  1393,  1395,
     838,   840,   842,  1098,   358,   359,   360,   848,   850,   852,
     854,  1584,  1088,  1585,   856,   863,   865,   867,   869,   877,
     879,   881,   885,  1422,   887,  1088,   889,   891,   893,   895,
     897,   899,   901,   903,  1457,   905,   655,   907,  1003,   567,
     568,   569,   570,   361,   909,   911,   362,   363,  1378,  1379,
    1380,   364,   656,  1381,  1382,   657,   290,   913,   922,   924,
     292,   926,  1098,   928,   930,  1098,  1098,   932,   934,   658,
    1378,  1379,   938,   940,  1088,  1381,  1382,  1818,  1589,   365,
    1590,  1098,  1098,  1098,   366,  1098,   942,   367,   944,   946,
    1098,  1098,   948,   368,  1088,   964,   294,   369,   966,   968,
     296,   970,   972,   298,   300,   370,  1011,   302,   974,   304,
    1468,  1470,  1522,   571,   659,  1498,  1825,   660,  1844,  1545,
    1846,  1094,  1094,  1552,   661,  1378,  1379,  1380,   306,   308,
    1381,  1382,  1378,  1379,   371,   571,   310,  1381,  1382,   312,
     314,   316,   318,   320,   322,   662,   324,   326,   567,   568,
     569,   570,   372,  1088,   328,   330,  1094,  1094,  1094,  1094,
     373,   663,   332,   334,  1591,   374,  1592,   336,   375,   338,
    1126,  1127,  1128,  1129,  1130,  1131,   376,   377,   340,   342,
    1140,  1141,  1142,  1622,  1608,  1618,  1621,  1593,   344,  1594,
     346,   378,   348,   350,   352,   379,  1629,  1631,  1633,  1140,
    1141,  1142,   428,  1598,   380,  1599,   664,   430,   432,   397,
    1641,  1033,   434,   487,   398,  1105,  1643,  1645,  1107,  1653,
    1811,  1109,   399,  1656,  1658,  1660,  1662,  1663,  1664,  1665,
    1094,   400,  1143,  1144,  1361,   401,  1366,  1088,  1371,  1566,
    1376,  1667,  1669,  1671,  1673,  1675,  1677,  1679,  1600,  1567,
    1601,  1143,  1144,   402,   403,  1176,  1177,  1178,  1179,   404,
    1181,  1604,  1183,  1605,  1185,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1088,  1088,  1088,  1088,  1602,   405,
    1603,  1088,   406,   612,   613,   614,   615,   616,  1746,  1094,
    1747,   665,  1094,  1094,   617,   407,   408,   618,   949,   950,
     951,   952,   953,  1088,   954,   409,   410,   571,  1094,  1094,
    1094,   411,  1094,  1307,  1829,   412,  1830,  1094,  1094,  1741,
     612,   613,   614,   615,   616,   612,   613,   614,   615,   616,
     413,   617,   414,   415,   618,   416,   417,   418,   419,   618,
    1441,  1442,  1443,  1444,  1445,   420,  1831,   421,   422,  1833,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1873,  1423,
    1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1445,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1507,   423,   571,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,   424,   425,   426,   612,
     613,   614,   615,   616,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   618,   444,   445,   446,   447,  1145,   448,
     449,   612,   613,   614,   615,   616,   450,   451,   452,   453,
    1088,  1088,   454,   455,   456,   618,   457,  1145,   458,   459,
     460,  1343,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,  1652,   474,   475,   476,   477,
     478,   479,   480,   481,   482,  1088,  1088,  1088,  1088,  1423,
    1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1445,   483,   484,   485,   488,  1823,   489,   490,   491,
     492,   493,  1828,   494,   495,   496,   497,   498,   499,   500,
     501,   503,  1635,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,   504,   505,   506,  1088,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1687,  1425,  1426,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,   507,  1875,
     508,   509,   510,   511,   512,   513,   514,   515,   735,    -2,
     533,  1823,   666,   667,   668,   670,   671,   672,  1088,  1741,
       2,  1088,  1088,   673,   -11,   -11,   -13,     3,     4,   -16,
     -18,   -20,   687,   674,   738,   979,   981,  1088,  1088,  1088,
     996,  1088,   675,   676,   677,   678,  1088,  1088,     5,   739,
       6,   809,     7,     8,     9,    10,    11,   810,   811,   812,
     920,   957,   958,  1001,   985,   988,   991,   994,    12,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1004,
    1910,  1005,  1009,  1010,  1017,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1031,  1111,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,  1112,  1113,  1117,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,  1118,
      74,    75,    76,  1119,  1120,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,  1134,  1148,  1149,  1150,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,  1151,   205,   206,
    1164,  1235,  1252,  1261,  1262,   207,  1263,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,  1264,  1265,  1274,  1275,  1276,  1277,  1311,  1313,  1316,
    1327,  1317,  1319,   222,   223,   224,  1321,  1323,  1423,  1424,
    1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,
    1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,
    1445,  1329,  1330,  1332,  1336,  1337,  1338,  1339,  1340,  1341,
    1342,   225,  1345,  1346,  1471,  1347,  1348,  1349,  1458,   226,
    1396,  1805,  1520,  1397,  1398,  1291,   227,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  1475,  -697,  -697,  -697,  -697,
    1484,  1485,  1486,  1503,  1504,  1505,  1506,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  1533,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  1519,  -697,  1521,  -697,  1529,
    1530,  1531,  -697,  1532,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  1534,  1537,  -697,  -697,  -697,  1539,  1540,  1559,
    -697,  -697,  -697,  -697,  -697,  -697,  1291,  1570,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  1579,  -665,  -665,  -665,
    -665,  1588,  1597,  1625,  1634,  -768,  -769,  -780,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -781,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  1636,  -665,  1637,  -665,
    1680,  1654,  1681,  -665,  1684,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  1682,  1683,  -665,  -665,  -665,  1685,  1716,
    1732,  -665,  -665,  -665,  -665,  -665,  -665,  1387,  1688,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  1689,  -669,  -669,
    -669,  -669,  1690,  1691,  1692,  1693,  1694,  1695,  1696,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  1697,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  1698,  -669,  1699,
    -669,  1700,  1701,  1702,  -669,  1703,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  1704,  1705,  -669,  -669,  -669,  1706,
    1707,  1708,  -669,  -669,  -669,  -669,  -669,  -669,  1387,  1709,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  1710,  -686,
    -686,  -686,  -686,  1711,  1712,  1713,  1714,  1717,  1718,  1719,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  1720,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  1721,  -686,
    1724,  -686,  1722,  1723,  1731,  -686,  1733,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  1734,  1735,  -686,  -686,  -686,
    1736,  1737,  1738,  -686,  -686,  -686,  -686,  -686,  -686,  1423,
    1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1445,  1739,  1740,  1307,  1745,  1749,  1754,  1755,  1756,
    1758,  1759,  1762,  1763,  1764,  1803,  -697,  1765,  1766,  1767,
    1768,  1769,  1807,  1770,  1775,  1771,  1776,  1781,  1784,  1785,
    1786,  1789,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,  -697,
    -697,  -697,  -697,  -697,  -697,  1790,  1791,  1794,  1795,  1796,
    1799,  -697,  1800,  1801,  1802,  1810,  -697,  1812,  1824,  1813,
    -697,  -697,  1840,  -697,  -697,  -697,  -997,  -697,  1804,  1806,
    1808,  1841,  -697,  1842,  1819,  1843,  1847,  -665,  1879,  1848,
    1849,  1850,  1851,  1894,  1852,  1895,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  1860,  1861,  1862,  1863,
    1864,  1865,  1866,  1867,  1868,  1869,  1870,  -665,  1871,  1880,
    1881,  -665,  -665,  1913,  -665,  -665,  -665,  -997,  -665,  1882,
    1883,  1886,  1888,  -665,  1891,  1892,  1893,  1896,  -669,  1907,
    1897,  1908,  1898,  1899,   534,  1331,  1903,  1904,  1125,  1620,
    1344,  1008,  1030,  1623,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  1032,  1535,  1826,
    1885,  1624,  1744,     0,   802,  1874,   804,     0,  -669,     0,
    1890,     0,  -669,  -669,     0,  -669,  -669,  -669,     0,  -669,
       0,     0,     0,     0,  -669,     0,     0,     0,     0,  -686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -686,
       0,     0,     1,  -686,  -686,     0,  -686,  -686,  -686,     0,
    -686,     0,     2,     0,     0,  -686,   -11,   -11,   -13,     3,
       4,   -16,   -18,   -20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     6,     0,     7,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,  1889,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,     0,
     205,   206,     0,     0,     0,     0,     0,   207,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,     0,     0,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1646,   225,  1034,  1035,  1036,  1037,  1038,     0,
       0,   226,     0,  1914,  1043,  1044,  1045,     0,   227,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,     0,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,
       0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1647,
    1192,  1905,     0,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  -729,  -729,
    1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1295,     0,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  -731,
    -731,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1295,     0,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
    1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    -733,  -733,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1083,  1193,     0,     0,  1423,  1424,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
       0,     0,  1195,     0,  1196,  1197,  1198,  1199,  1809,  1200,
    1201,  1202,  1648,  1649,     0,  1203,   616,  1085,  1086,     0,
       0,     0,     0,  1266,  1205,     0,   618,     0,     0,     0,
       0,  1295,     0,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,  1083,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  -727,  -727,
    1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1084,     0,     0,     0,  1085,  1086,     0,     0,
    1087,     0,     0,     0,  -729,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1423,  1424,  1425,  1426,  1427,  1428,
    1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1443,  1444,  1445,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,     0,  1900,     0,     0,     0,     0,
       0,     0,     0,  1084,     0,     0,     0,  1085,  1086,     0,
       0,  1087,     0,     0,     0,  -731,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,  1423,  1424,  1425,  1426,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,     0,     0,     0,  1085,  1086,
       0,     0,  1087,     0,     0,  1295,  -733,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,  -734,  -734,  1074,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,     0,     0,     0,     0,
       0,  1295,     0,  1034,  1035,  1036,  1037,  1038,  1039,  1040,
    1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,  1083,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  -728,  -728,
    1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1084,     0,     0,     0,  1085,  1086,     0,     0,
    1087,     0,     0,  1295,  -727,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
    1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
       0,     0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1295,     0,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,
       0,     0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,
       0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,     0,     0,  1074,  1075,  1076,     0,     0,     0,  1077,
    1078,  1079,  1080,  1081,  1082,  1295,     0,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,  1083,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1084,     0,     0,     0,
    1085,  1086,     0,     0,  1087,     0,     0,     0,  -734,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1084,     0,     0,     0,  1085,  1086,     0,     0,
    1087,     0,     0,  1295,  -728,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,  1083,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
    1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
       0,     0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1084,     0,     0,     0,  1085,  1086,
       0,     0,  1087,     0,     0,     0,  1296,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1084,     0,     0,     0,  1085,
    1086,     0,     0,  1087,     0,     0,     0,  1318,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
    1085,  1086,     0,     0,  1087,     0,     0,  1295,  1320,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,  1065,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,     0,     0,  1074,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,     0,     0,
       0,     0,     0,  1295,     0,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,  1083,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
    1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
       0,     0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1084,     0,     0,     0,  1085,  1086,
       0,     0,  1087,     0,     0,  1295,  1322,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1295,     0,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,
       0,  1077,  1078,  1079,  1080,  1081,  1082,  1295,     0,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,  1083,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,  1065,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,     0,     0,  1074,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1084,     0,
       0,     0,  1085,  1086,     0,     0,  1087,     0,     0,     0,
    1328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,     0,     0,     0,  1085,  1086,
       0,     0,  1087,     0,     0,  1295,  1638,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,  1083,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1084,     0,     0,     0,
    1085,  1086,     0,     0,  1087,     0,     0,     0,  1757,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1084,     0,     0,
       0,  1085,  1086,     0,     0,  1087,     0,     0,     0,  1772,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1084,     0,
       0,     0,  1085,  1086,     0,     0,  1087,     0,     0,  1295,
    1814,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,     0,
    1042,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,  1065,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,     0,     0,  1074,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
       0,     0,     0,     0,     0,  1295,     0,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,  1083,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1084,     0,     0,     0,
    1085,  1086,     0,     0,  1087,     0,     0,  1295,  1834,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,  1065,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,     0,     0,  1074,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1609,     0,  1034,  1035,
    1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,     0,
    1083,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1610,  1611,  1612,  1613,  1614,
    1615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1084,     0,     0,     0,  1085,  1086,     0,     0,  1087,     0,
       0,     0,  1835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1084,     0,     0,     0,
    1085,  1086,     0,     0,  1087,     0,     0,     0,  1836,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1084,     0,
       0,     0,  1085,  1086,     0,     0,  1087,     0,     0,     0,
    1837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,  1193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1194,  1616,     0,     0,  1195,     0,  1196,  1197,
    1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,
       0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,  1619,
       0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1610,  1611,
    1612,  1613,  1614,  1615,  1399,     0,  1034,  1035,  1036,  1037,
    1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,     0,
       0,     0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,
       0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
       0,     0,     0,     0,  1075,  1076,     0,     0,     0,  1077,
    1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1399,     0,  1034,  1035,  1036,  1037,  1038,
       0,     0,     0,     0,     0,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
       0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,
       0,     0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,  1616,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1266,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,  1193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,
       0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,
    1086,     0,     0,     0,  1400,  1266,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,  1193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,
    1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,
       0,     0,     0,  1448,  1266,  1205,  1399,     0,  1034,  1035,
    1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,     0,
       0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1820,     0,  1034,  1035,  1036,
    1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,     0,     0,     0,     0,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1278,     0,  1034,  1035,  1036,  1037,
    1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,     0,
       0,     0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,
       0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
       0,     0,     0,     0,  1075,  1076,     0,     0,     0,  1077,
    1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,  1193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,
    1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,
       0,  1085,  1086,     0,     0,     0,  1449,  1266,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,  1193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1194,     0,  1821,     0,  1195,     0,  1196,  1197,  1198,
    1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,
    1085,  1086,     0,     0,     0,     0,  1266,  1205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,  1193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,
       0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,
    1086,     0,     0,     0,     0,  1266,  1205,  1390,     0,  1034,
    1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1392,     0,  1034,  1035,
    1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,     0,
       0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1394,     0,  1034,  1035,  1036,
    1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,     0,     0,     0,     0,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,  1193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,     0,     0,     0,  1195,     0,  1196,
    1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,
    1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,  1193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,
    1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,
       0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1083,  1193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,
    1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,
    1085,  1086,     0,     0,     0,     0,  1266,  1205,  1421,     0,
    1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,
    1043,  1044,  1045,     0,     0,     0,     0,     0,     0,     0,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,
       0,  1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,
       0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1455,     0,  1034,
    1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1399,     0,  1034,  1035,
    1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,     0,
       0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,     0,  1195,     0,
    1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,
       0,  1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,
    1205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,  1193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,     0,     0,     0,  1195,     0,  1196,
    1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1456,     0,
    1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,  1193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,
    1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,
       0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,  1606,
       0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1628,     0,
    1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,
    1043,  1044,  1045,     0,     0,     0,     0,     0,     0,     0,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,
       0,  1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,
       0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1630,     0,  1034,
    1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,  1043,
    1044,  1045,     0,     0,     0,     0,     0,     0,     0,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,
    1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,     0,
       0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1607,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1266,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,     0,  1195,     0,
    1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,
       0,  1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,
    1205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1083,  1193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,     0,     0,     0,  1195,     0,  1196,
    1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,     0,
    1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,  1205,
    1632,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,
       0,     0,  1043,  1044,  1045,     0,     0,     0,     0,     0,
       0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
       0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
       0,  1063,     0,  1064,     0,     0,     0,     0,     0,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,
    1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,
    1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1639,
       0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1640,  1192,  1642,     0,
    1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,
    1043,  1044,  1045,     0,     0,     0,     0,     0,     0,     0,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,
       0,  1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,  1076,
       0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1083,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,     0,     0,
    1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,
     575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,
       0,  1266,  1205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1266,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,     0,  1195,     0,
    1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,
       0,  1203,     0,  1085,  1086,     0,     0,     0,     0,  1266,
    1205,  1644,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,
       0,     0,     0,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,     0,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,
       0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1655,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,
       0,     0,  1043,  1044,  1045,     0,     0,     0,     0,     0,
       0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
       0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
       0,  1063,     0,  1064,     0,     0,     0,     0,     0,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,
    1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,
    1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1657,
       0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,  1193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1194,     0,     0,
       0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,
    1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,
       0,     0,  1266,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1083,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,     0,     0,
    1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,
     575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,
       0,  1266,  1205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1266,  1205,  1659,     0,  1034,  1035,  1036,  1037,  1038,     0,
       0,     0,     0,     0,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,     0,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,
       0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1661,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,
       0,     0,     0,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,     0,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,
       0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1666,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,
       0,     0,  1043,  1044,  1045,     0,     0,     0,     0,     0,
       0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
       0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
       0,  1063,     0,  1064,     0,     0,     0,     0,     0,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,
    1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,
    1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
       0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,
    1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,
       0,     0,     0,  1266,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,  1193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1194,     0,     0,
       0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,
    1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,
       0,     0,  1266,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1083,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,     0,     0,
    1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,
     575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,
       0,  1266,  1205,  1668,     0,  1034,  1035,  1036,  1037,  1038,
       0,     0,     0,     0,     0,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
       0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,
       0,     0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1670,     0,  1034,  1035,  1036,  1037,  1038,     0,
       0,     0,     0,     0,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,     0,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,
       0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1672,     0,  1034,  1035,  1036,  1037,  1038,     0,     0,
       0,     0,     0,  1043,  1044,  1045,     0,     0,     0,     0,
       0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,     0,  1063,     0,  1064,     0,     0,     0,     0,     0,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,     0,
       0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,  1193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,
    1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,
       0,     0,     0,     0,  1266,  1205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
       0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,
    1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,
       0,     0,     0,  1266,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1083,  1193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1194,     0,     0,
       0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,  1201,
    1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,     0,
       0,     0,  1266,  1205,  1674,     0,  1034,  1035,  1036,  1037,
    1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,     0,
       0,     0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,
       0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,
       0,     0,     0,     0,  1075,  1076,     0,     0,     0,  1077,
    1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1676,     0,  1034,  1035,  1036,  1037,  1038,
       0,     0,     0,     0,     0,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
       0,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,
       0,     0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1678,     0,  1034,  1035,  1036,  1037,  1038,     0,
       0,     0,     0,     0,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,     0,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,
       0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,  1193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,
       0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,
    1086,     0,     0,     0,     0,  1266,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,  1193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,
    1200,  1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,
       0,     0,     0,     0,  1266,  1205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
       0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,
    1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,
       0,     0,     0,  1266,  1205,  1884,     0,  1034,  1035,  1036,
    1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,     0,     0,     0,     0,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1034,  1035,  1036,  1037,  1038,     0,
       0,     0,     0,     0,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,     0,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,     0,     0,
       0,     0,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,     0,     0,
    1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,     0,
    1043,  1044,  1045,     0,     0,     0,     0,     0,     0,     0,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,
       0,  1064,     0,     0,     0,     0,     0,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,     0,     0,  1083,  1193,  1075,  1076,
       0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,     0,     0,     0,
       0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,
    1199,     0,  1200,  1201,  1202,   575,  1084,     0,  1203,     0,
    1085,  1086,     0,     0,     0,     0,  1266,  1205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1194,     0,
       0,     0,  1195,     0,  1196,  1197,  1198,  1199,     0,  1200,
    1201,  1202,   575,  1084,     0,  1203,     0,  1085,  1086,     0,
       0,     0,     0,  1204,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1225,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1083,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1194,     0,     0,     0,  1195,     0,
    1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,  1084,
       0,  1203,     0,  1085,  1086,     0,     0,     0,     0,  1227,
    1205,  1034,  1035,  1036,  1037,  1038,     0,     0,     0,     0,
       0,  1043,  1044,  1045,     0,     0,     0,     0,     0,     0,
       0,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,     0,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,     0,
    1063,     0,  1064,     0,     0,     0,     0,     0,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,     0,     0,     0,     0,  1075,
    1076,     0,     0,     0,  1077,  1078,  1079,  1080,  1081,  1082,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,     0,  1042,  1043,  1044,
    1045,     0,     0,     0,     0,     0,     0,     0,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,
       0,     0,     0,  1065,     0,  1066,  1067,  1068,  1069,  1070,
    1071,  1072,  1073,     0,     0,  1074,  1075,  1076,     0,     0,
       0,  1077,  1078,  1079,  1080,  1081,  1082,  1034,  1035,  1036,
    1037,  1038,     0,     0,     0,     0,     0,  1043,  1044,  1045,
       0,     0,     0,     0,     0,     0,     0,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,     0,  1063,     0,  1064,     0,
       0,     0,     0,     0,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,     0,     0,     0,     0,  1075,  1076,     0,     0,     0,
    1077,  1078,  1079,  1080,  1081,  1082,  1175,  1176,  1177,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1191,  1192,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,     0,
       0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,     0,     0,     0,     0,     0,     0,     0,
    1083,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,  1195,
       0,  1196,  1197,  1198,  1199,     0,  1200,  1201,  1202,   575,
    1084,     0,  1203,     0,  1085,  1086,     0,     0,     0,     0,
    1266,  1205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1083,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1084,     0,     0,
       0,  1085,  1086,     0,     0,  1087,     0,     0,  1492,     0,
       0,     0,     0,     0,     0,     0,  1083,  1193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1194,     0,     0,     0,  1195,     0,  1196,  1197,  1198,
    1199,     0,  1200,  1201,  1202,  1827,  1084,     0,  1203,     0,
    1085,  1086,     0,     0,     0,     0,  1266,  1205,     0,     0,
       0,     0,  1407,     0,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,     0,
       0,     0,     0,  1083,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,  1065,
       0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,     0,
       0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,  1079,
    1080,  1081,  1082,  1084,     0,     0,     0,  1085,  1086,     0,
       0,  1087,     0,     0,  1492,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,     0,  1042,  1043,  1044,  1045,     0,     0,
       0,     0,     0,     0,     0,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,     0,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,     0,  1063,     0,  1064,     0,     0,     0,
    1065,     0,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
       0,     0,  1074,  1075,  1076,     0,     0,     0,  1077,  1078,
    1079,  1080,  1081,  1082,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1083,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1084,     0,     0,     0,  1085,  1086,     0,
       0,  1087,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1083,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1084,     0,     0,     0,  1085,  1086,
       0,     0,  1087
};

static const yytype_int16 yycheck[] =
{
     254,   221,   468,   257,   253,   985,  1280,  1332,   988,     1,
       1,   991,     1,  1166,   994,  1168,     1,  1170,     1,  1172,
       1,  1174,  1002,  1187,     1,  1189,     1,  1191,     1,     1,
    1215,   367,   286,     1,   288,     1,   290,     1,   292,     1,
     113,   114,    59,   371,   372,  1209,   374,     1,   985,   385,
      64,   988,   337,     1,   991,     1,     1,   994,     1,     1,
       1,   988,     1,  1089,   991,  1002,     1,   994,     1,     1,
     113,   114,    63,    58,    59,  1002,     1,     1,     1,   357,
    1106,   357,  1108,     1,  1110,     1,   337,   357,  1114,     1,
       1,   985,   337,   371,   988,   371,   374,   991,     1,   353,
     994,   371,     1,     1,     1,     1,     1,     1,  1002,  1089,
     386,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,    90,    91,    92,    93,  1106,     1,  1108,     1,
    1110,     1,     1,  1207,  1114,     1,   358,  1211,   357,   337,
       1,     1,    90,    91,    92,    93,     1,   337,   367,   371,
       1,   617,  1089,     1,     1,     1,     1,     1,   357,   337,
       1,     1,   416,   417,   418,     1,     1,     1,   367,  1106,
       1,  1108,     1,  1110,     1,  1015,  1016,  1114,     1,    90,
      91,    92,    93,   357,   337,     1,     1,     1,     1,    63,
       1,   357,     1,   367,     1,  1089,   450,   451,     1,   371,
    1204,   367,   374,     1,   379,   379,   381,   381,    64,   357,
       1,   337,  1106,   379,  1108,   381,  1110,    63,     1,   367,
    1114,  1225,   367,  1227,  1204,  1205,     1,     1,   112,   113,
     114,   379,    63,   381,     1,    90,    91,    92,    93,     1,
     379,  1267,   381,     1,     1,  1225,     1,  1227,     1,   503,
       1,     1,   506,   507,  1280,     1,     1,   372,   357,   374,
       1,     1,  1266,   358,   359,   360,  1419,  1204,  1205,   337,
       1,     1,   371,   337,     1,   374,     1,     1,  1205,   337,
       1,     1,     1,   379,   337,   381,  1266,  1267,  1225,     1,
    1227,     1,     1,     1,     1,     1,     1,     1,     1,     1,
    1280,    63,   357,     1,     1,     1,     1,     1,     1,     1,
    1204,  1205,     1,     1,     1,   388,   371,    17,     1,   374,
       1,   376,     1,    22,     1,     1,     1,     1,     1,  1266,
    1267,  1225,     1,  1227,     1,  1315,     1,     1,     1,   379,
    1525,   381,     1,  1280,   985,     1,   383,   988,     1,  1329,
     991,     1,     1,   994,   371,   372,   337,   371,     1,     1,
       0,  1002,   337,    90,    91,    92,    93,     1,     1,  1349,
       1,   371,  1266,  1267,     1,     1,     1,     1,  1315,     1,
     371,   372,  1408,   374,   375,     1,  1280,     1,     1,     1,
     358,   383,  1329,   385,   385,     1,   385,  1722,   375,   384,
     383,   374,  1329,   371,   372,   373,   374,   375,   385,   382,
     358,   383,  1349,   385,   382,   381,   382,   385,   372,   383,
     382,   385,  1349,   371,   372,   373,   374,   375,  1408,   371,
     372,   373,   374,   375,   382,  1329,   382,   385,   383,   382,
    1765,   382,  1716,   385,   383,   380,   385,   358,  1089,   374,
     383,   383,   385,     1,   372,  1349,   374,   382,   382,   382,
     371,   372,   373,   374,   375,  1106,   382,  1108,   371,  1110,
     382,  1408,   375,  1114,   385,   374,  1640,   371,   372,   373,
     374,   375,   385,  1647,   382,   382,   382,   382,    15,    16,
       1,   385,     1,     1,     1,     1,   337,   371,   372,   371,
     374,   375,   372,   358,   374,   337,   372,   381,   374,   381,
    1536,   385,  1492,   382,  1408,   371,   371,   372,   373,   374,
     375,   382,   382,     1,     1,   371,   372,   382,   374,   375,
     385,   382,  1558,   374,   382,   382,   372,   382,   382,   385,
     371,   372,   382,   374,   375,   372,  1012,   382,   382,  1529,
    1530,  1531,  1532,   382,   385,  1492,  1536,  1882,     1,   382,
     371,   372,   373,  1204,  1205,  1492,   382,   382,   382,   382,
     337,   985,  1897,   382,   988,   382,   374,   991,  1558,   382,
     994,   372,   357,   374,  1225,     1,  1227,     1,  1002,   372,
       1,   374,  1529,  1530,  1531,  1532,   371,   371,  1492,  1536,
     374,   322,  1529,  1530,  1531,  1532,   381,   374,     1,   371,
     372,     1,   374,   375,   372,   372,   374,   374,   371,   374,
     371,  1558,   372,   385,   374,  1266,  1267,   372,   374,   374,
     371,   358,   372,   374,   374,  1529,  1530,  1531,  1532,  1280,
      20,   371,  1536,   374,   371,   372,   373,   374,   375,   374,
     374,     1,  1118,   374,   374,   374,   377,  1810,   385,     1,
      21,   371,   374,   337,  1558,   374,   374,   374,   374,   374,
     374,   374,   374,     1,     1,  1089,   374,   374,   374,   374,
     374,   374,   374,   337,   374,   374,   374,   374,  1329,  1715,
    1716,   374,  1106,   374,  1108,   374,  1110,   374,   374,   374,
    1114,   374,     1,     1,   357,   374,     1,   374,  1349,   374,
     374,   374,   371,   372,   373,   371,   372,     1,   371,     1,
       1,   371,   371,   357,  1750,  1751,  1752,  1753,   371,   371,
     357,   357,   357,   357,     1,  1715,  1716,   371,   371,   337,
     371,   357,   337,   357,   371,   371,   371,   371,     1,   371,
       1,   357,     1,     1,     1,   371,     1,   371,   371,   371,
      64,   981,     1,     1,     1,   371,     1,  1408,     1,     1,
    1750,  1751,  1752,  1753,    64,     1,     1,     1,  1715,  1716,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,  1205,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,  1269,     1,     1,     1,  1273,     1,   357,
       1,     1,     1,  1750,  1751,  1752,  1753,     1,     1,     1,
       1,  1715,  1716,   371,     1,     1,     1,     1,     1,     1,
       1,     1,     1,    64,     1,   337,     1,     1,     1,     1,
       1,     1,     1,     1,  1824,     1,   357,     1,   357,   357,
     357,  1492,   358,  1267,     1,     1,  1750,  1751,  1752,  1753,
     371,  1887,   371,   371,   371,   371,  1280,     1,     1,     1,
    1336,     1,  1338,     1,     1,  1341,  1902,     1,     1,   357,
    1906,   358,     1,     1,     1,  1911,  1912,  1824,  1529,  1530,
    1531,  1532,   337,   371,   371,  1536,     1,  1824,     1,     1,
       1,  1315,     1,  1883,     1,     1,  1886,  1887,     1,     1,
     985,     1,     1,   988,   357,  1329,   991,  1558,     1,   994,
       1,     1,  1902,  1903,  1904,     1,  1906,  1002,   371,     1,
    1824,  1911,  1912,     1,   337,  1349,     1,   273,   337,   275,
       1,   357,   337,   357,     1,   337,  1883,     1,     1,  1886,
    1887,     1,   379,     1,   381,   371,  1883,   371,     1,  1886,
     371,     1,   337,   337,   357,  1902,  1903,  1904,     1,  1906,
      58,    59,     1,     1,  1911,  1912,  1903,  1904,   371,   337,
       1,   371,   337,     1,     1,     1,     1,     1,     1,  1883,
       1,     1,  1886,  1887,  1408,   345,   346,  1251,     1,     1,
     350,   351,   352,   353,   354,   355,     1,     1,  1902,  1903,
    1904,     1,  1906,     1,  1089,   357,  1265,  1911,  1912,  1039,
    1040,  1041,     1,     1,  1273,    90,    91,    92,    93,   371,
     357,  1106,     1,  1108,     1,  1110,     1,     1,     1,  1114,
     379,   337,   381,   371,   371,  1065,     1,    90,    91,    92,
      93,     1,     1,  1073,  1074,   337,     1,     1,   357,   337,
     337,   254,   255,   256,   257,   337,  1286,   371,  1288,   379,
    1290,   381,   371,   371,  1715,  1716,   371,   371,  1492,   371,
     372,   371,   374,   371,   337,   371,   372,   371,   374,  1338,
     371,   337,  1341,  1347,  1348,   337,   345,   346,   347,   374,
     371,   350,   351,   357,   371,   371,   372,   337,   374,  1750,
    1751,  1752,  1753,   367,   337,  1529,  1530,  1531,  1532,   379,
     371,   381,  1536,   371,   371,   379,   371,   381,   371,   379,
    1205,   381,   371,   371,   371,   379,   371,   381,   371,   371,
     371,   375,   371,   337,  1558,   371,   371,   371,   388,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,  1197,  1198,  1199,
     371,   371,   371,  1824,   337,   337,   337,   371,   371,   371,
     371,   379,  1267,   381,   371,   371,   371,   371,   371,   371,
     371,   371,   371,  1223,   371,  1280,   371,   371,   371,   371,
     371,   371,   371,   371,  1234,   371,   371,   371,   386,    90,
      91,    92,    93,   337,   371,   371,   337,   337,   345,   346,
     347,   337,   371,   350,   351,   371,   337,   371,   371,   371,
     337,   371,  1883,   371,   371,  1886,  1887,   371,   371,   371,
     345,   346,   371,   371,  1329,   350,   351,  1723,   379,   337,
     381,  1902,  1903,  1904,   337,  1906,   371,   337,   371,   371,
    1911,  1912,   371,   337,  1349,   371,   337,   337,   371,   371,
     337,   371,   371,   337,   337,   337,   622,   337,   371,   337,
     371,   371,  1312,   358,   371,   371,   384,   371,  1764,   371,
    1766,  1715,  1716,   371,   371,   345,   346,   347,   337,   337,
     350,   351,   345,   346,   337,   358,   337,   350,   351,   337,
     337,   337,   337,   337,   337,   371,   337,   337,    90,    91,
      92,    93,   337,  1408,   337,   337,  1750,  1751,  1752,  1753,
     337,   371,   337,   337,   379,   337,   381,   337,   337,   337,
      90,    91,    92,    93,    94,    95,   337,   337,   337,   337,
     112,   113,   114,     1,  1384,  1385,  1386,   379,   337,   381,
     337,   337,   337,   337,   337,   337,  1396,  1397,  1398,   112,
     113,   114,   337,   379,   337,   381,   371,   337,   337,   337,
    1410,   983,   337,   337,   337,   987,  1416,  1417,   990,  1419,
    1654,   993,   337,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1824,   337,   164,   165,  1168,   337,  1170,  1492,  1172,   357,
    1174,  1441,  1442,  1443,  1444,  1445,  1446,  1447,   379,   367,
     381,   164,   165,   337,   337,    73,    74,    75,    76,   337,
      78,   379,    80,   381,    82,   324,   325,   326,   327,   328,
     329,   330,   331,   332,  1529,  1530,  1531,  1532,   379,   337,
     381,  1536,   337,   371,   372,   373,   374,   375,   379,  1883,
     381,   371,  1886,  1887,   382,   337,   337,   385,   301,   302,
     303,   304,   305,  1558,   307,   337,   337,   358,  1902,  1903,
    1904,   337,  1906,   372,   379,   337,   381,  1911,  1912,  1519,
     371,   372,   373,   374,   375,   371,   372,   373,   374,   375,
     337,   382,   337,   337,   385,   337,   337,   337,   337,   385,
     356,   357,   358,   359,   360,   337,  1746,   337,   337,  1749,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,  1802,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   383,   337,   358,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   337,   337,   337,   371,
     372,   373,   374,   375,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   385,   337,   337,   337,   337,   380,   337,
     337,   371,   372,   373,   374,   375,   337,   337,   337,   337,
    1715,  1716,   337,   337,   337,   385,   337,   380,   337,   337,
     337,   384,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,  1419,   337,   337,   337,   337,
     337,   337,   337,   337,   337,  1750,  1751,  1752,  1753,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   337,   337,   337,   337,  1726,   337,   337,   337,
     337,   337,  1732,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   381,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   337,   337,   337,  1824,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   381,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   337,  1809,
     337,   337,   337,   337,   337,   337,   337,   337,   374,     0,
       1,  1821,   371,   371,   371,   371,   371,   371,  1883,  1829,
      11,  1886,  1887,   371,    15,    16,    17,    18,    19,    20,
      21,    22,   337,   371,   374,   379,   379,  1902,  1903,  1904,
     385,  1906,   371,   371,   371,   371,  1911,  1912,    39,   374,
      41,   371,    43,    44,    45,    46,    47,   371,   371,   371,
     371,   371,   371,   371,   383,   383,   383,   383,    59,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   371,
    1900,   367,   388,   388,   383,   379,   379,   337,   337,   337,
     337,   337,   337,   371,   378,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   337,   386,   371,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   379,
     161,   162,   163,   381,   386,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   374,   374,   374,   374,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   374,   299,   300,
     386,   382,   382,   382,   382,   306,   382,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   382,   382,   382,   382,   382,   382,   337,   380,   380,
     367,   386,   386,   334,   335,   336,   386,   386,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   383,   367,   388,   388,   113,   337,   337,   337,   337,
     337,   372,   381,   381,   381,   379,   379,   383,   374,   380,
     382,   381,   367,   382,   382,     1,   387,     3,     4,     5,
       6,     7,     8,     9,    10,   381,    12,    13,    14,    15,
     381,   381,   381,   381,   381,   381,   381,    23,    24,    25,
      26,    27,    28,    29,    30,   298,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   382,    42,   385,    44,   383,
     383,   383,    48,   383,    50,    51,    52,    53,    54,    55,
      56,    57,   298,   371,    60,    61,    62,   374,   371,   381,
      66,    67,    68,    69,    70,    71,     1,   381,     3,     4,
       5,     6,     7,     8,     9,    10,   381,    12,    13,    14,
      15,   381,   381,   372,   381,   337,   337,   337,    23,    24,
      25,    26,    27,    28,    29,    30,   337,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   381,    42,   384,    44,
     381,   385,   379,    48,   379,    50,    51,    52,    53,    54,
      55,    56,    57,   381,   381,    60,    61,    62,   381,    49,
     379,    66,    67,    68,    69,    70,    71,     1,   381,     3,
       4,     5,     6,     7,     8,     9,    10,   381,    12,    13,
      14,    15,   381,   381,   381,   381,   381,   381,   381,    23,
      24,    25,    26,    27,    28,    29,    30,   381,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   381,    42,   381,
      44,   381,   381,   381,    48,   381,    50,    51,    52,    53,
      54,    55,    56,    57,   381,   381,    60,    61,    62,   381,
     381,   381,    66,    67,    68,    69,    70,    71,     1,   381,
       3,     4,     5,     6,     7,     8,     9,    10,   381,    12,
      13,    14,    15,   381,   381,   381,   381,   381,   381,   381,
      23,    24,    25,    26,    27,    28,    29,    30,   381,    32,
      33,    34,    35,    36,    37,    38,    39,    40,   381,    42,
     381,    44,   388,   388,   381,    48,   381,    50,    51,    52,
      53,    54,    55,    56,    57,   381,   381,    60,    61,    62,
     381,   381,   381,    66,    67,    68,    69,    70,    71,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   381,   381,   372,   386,   379,   374,   374,   337,
     367,   113,   388,   388,   388,   367,   322,   388,   388,   381,
     381,   381,   381,   381,   371,   381,   371,   371,   371,   371,
     371,   371,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   371,   371,   371,   371,   371,
     371,   367,   371,   371,   385,   359,   372,   374,   388,   374,
     376,   377,   371,   379,   380,   381,   382,   383,   381,   381,
     381,   374,   388,   371,   384,   371,   381,   322,   386,   381,
     381,   381,   381,   113,   381,   114,   381,   381,   381,   381,
     381,   381,   381,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   372,   381,   381,
     381,   376,   377,   113,   379,   380,   381,   382,   383,   388,
     388,   388,   381,   388,   381,   381,   381,   388,   322,   374,
     388,   371,   386,   386,   229,  1118,   388,   388,  1010,  1386,
    1147,   618,   979,  1388,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   981,  1327,  1730,
    1821,  1388,  1520,    -1,   423,  1803,   424,    -1,   372,    -1,
    1829,    -1,   376,   377,    -1,   379,   380,   381,    -1,   383,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,
      -1,    -1,     1,   376,   377,    -1,   379,   380,   381,    -1,
     383,    -1,    11,    -1,    -1,   388,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   381,    -1,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    -1,
     299,   300,    -1,    -1,    -1,    -1,    -1,   306,    -1,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,   335,   336,    -1,    -1,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,   372,     3,     4,     5,     6,     7,    -1,
      -1,   380,    -1,   381,    13,    14,    15,    -1,   387,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   322,   323,    -1,    -1,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,   361,    -1,   363,   364,   365,   366,   379,   368,
     369,   370,   371,   372,    -1,   374,   375,   376,   377,    -1,
      -1,    -1,    -1,   382,   383,    -1,   385,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,   372,    -1,    -1,    -1,   376,   377,    -1,    -1,
     380,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,    -1,   379,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,    -1,
      -1,   380,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,   380,    -1,    -1,     1,   384,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,   372,    -1,    -1,    -1,   376,   377,    -1,    -1,
     380,    -1,    -1,     1,   384,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,   380,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,   376,   377,    -1,    -1,
     380,    -1,    -1,     1,   384,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,   380,    -1,    -1,    -1,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,
     377,    -1,    -1,   380,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,   380,    -1,    -1,     1,   384,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,   380,    -1,    -1,     1,   384,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,   322,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,   372,    -1,
      -1,    -1,   376,   377,    -1,    -1,   380,    -1,    -1,    -1,
     384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,   380,    -1,    -1,     1,   384,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,   380,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,   376,   377,    -1,    -1,   380,    -1,    -1,    -1,   384,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,   376,   377,    -1,    -1,   380,    -1,    -1,     1,
     384,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,   380,    -1,    -1,     1,   384,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
     322,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     372,    -1,    -1,    -1,   376,   377,    -1,    -1,   380,    -1,
      -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,   380,    -1,    -1,    -1,   384,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,   376,   377,    -1,    -1,   380,    -1,    -1,    -1,
     384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,   358,    -1,    -1,   361,    -1,   363,   364,
     365,   366,    -1,   368,   369,   370,   371,   372,    -1,   374,
      -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,   358,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,
      -1,   368,   369,   370,   371,   372,    -1,   374,    -1,   376,
     377,    -1,    -1,    -1,   381,   382,   383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,
      -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,
     368,   369,   370,   371,   372,    -1,   374,    -1,   376,   377,
      -1,    -1,    -1,   381,   382,   383,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,
     365,   366,    -1,   368,   369,   370,   371,   372,    -1,   374,
      -1,   376,   377,    -1,    -1,    -1,   381,   382,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,   359,    -1,   361,    -1,   363,   364,   365,
     366,    -1,   368,   369,   370,   371,   372,    -1,   374,    -1,
     376,   377,    -1,    -1,    -1,    -1,   382,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,
      -1,   368,   369,   370,   371,   372,    -1,   374,    -1,   376,
     377,    -1,    -1,    -1,    -1,   382,   383,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,
     364,   365,   366,    -1,   368,   369,   370,   371,   372,    -1,
     374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,
     365,   366,    -1,   368,   369,   370,   371,   372,    -1,   374,
      -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,
     366,    -1,   368,   369,   370,   371,   372,    -1,   374,    -1,
     376,   377,    -1,    -1,    -1,    -1,   382,   383,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,
     363,   364,   365,   366,    -1,   368,   369,   370,   371,   372,
      -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,
     383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,
     364,   365,   366,    -1,   368,   369,   370,   371,   372,    -1,
     374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,
     365,   366,    -1,   368,   369,   370,   371,   372,    -1,   374,
      -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,
     363,   364,   365,   366,    -1,   368,   369,   370,   371,   372,
      -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,
     383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,   363,
     364,   365,   366,    -1,   368,   369,   370,   371,   372,    -1,
     374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,   383,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
     361,    -1,   363,   364,   365,   366,    -1,   368,   369,   370,
     371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,
      -1,   382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,
     363,   364,   365,   366,    -1,   368,   369,   370,   371,   372,
      -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,
     383,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,   361,    -1,   363,   364,   365,   366,    -1,   368,   369,
     370,   371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,
      -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
     361,    -1,   363,   364,   365,   366,    -1,   368,   369,   370,
     371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,
      -1,   382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,   368,
     369,   370,   371,   372,    -1,   374,    -1,   376,   377,    -1,
      -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,   361,    -1,   363,   364,   365,   366,    -1,   368,   369,
     370,   371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,
      -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
     361,    -1,   363,   364,   365,   366,    -1,   368,   369,   370,
     371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,
      -1,   382,   383,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,
      -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,
     368,   369,   370,   371,   372,    -1,   374,    -1,   376,   377,
      -1,    -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,   368,
     369,   370,   371,   372,    -1,   374,    -1,   376,   377,    -1,
      -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,   361,    -1,   363,   364,   365,   366,    -1,   368,   369,
     370,   371,   372,    -1,   374,    -1,   376,   377,    -1,    -1,
      -1,    -1,   382,   383,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,
      -1,   368,   369,   370,   371,   372,    -1,   374,    -1,   376,
     377,    -1,    -1,    -1,    -1,   382,   383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,
      -1,    -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,
     368,   369,   370,   371,   372,    -1,   374,    -1,   376,   377,
      -1,    -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,   368,
     369,   370,   371,   372,    -1,   374,    -1,   376,   377,    -1,
      -1,    -1,    -1,   382,   383,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,   322,   323,    61,    62,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,
     366,    -1,   368,   369,   370,   371,   372,    -1,   374,    -1,
     376,   377,    -1,    -1,    -1,    -1,   382,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,   361,    -1,   363,   364,   365,   366,    -1,   368,
     369,   370,   371,   372,    -1,   374,    -1,   376,   377,    -1,
      -1,    -1,    -1,   382,   383,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,    -1,
     363,   364,   365,   366,    -1,   368,   369,   370,   371,   372,
      -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,   382,
     383,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   361,
      -1,   363,   364,   365,   366,    -1,   368,   369,   370,   371,
     372,    -1,   374,    -1,   376,   377,    -1,    -1,    -1,    -1,
     382,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,   376,   377,    -1,    -1,   380,    -1,    -1,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,   323,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,    -1,    -1,   361,    -1,   363,   364,   365,
     366,    -1,   368,   369,   370,   371,   372,    -1,   374,    -1,
     376,   377,    -1,    -1,    -1,    -1,   382,   383,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,   372,    -1,    -1,    -1,   376,   377,    -1,
      -1,   380,    -1,    -1,   383,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,    -1,
      -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,   380
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    11,    18,    19,    39,    41,    43,    44,    45,
      46,    47,    59,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   161,   162,   163,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   299,   300,   306,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   334,   335,   336,   372,   380,   387,   390,   391,
     392,   393,   394,   395,   396,   397,   409,   413,   418,   420,
     422,   423,   433,   434,   443,   337,   337,     1,   385,     1,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,     1,   337,     1,   337,     1,   337,     1,
     337,     1,   337,   337,   337,   337,   337,   419,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,     1,   374,   382,     1,   374,   382,     1,   337,   374,
       1,   382,     1,   382,     1,   337,   374,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,     1,   337,     1,
     337,     1,   337,     1,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,     1,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   367,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,     1,   372,   374,   410,
     411,   412,     1,   412,   414,   415,     1,   374,     1,   374,
       1,   374,     0,     1,   392,    15,    16,   429,   430,    17,
     431,   432,    20,   437,   438,    21,   439,   440,    22,   441,
     442,   367,   385,   383,     1,   371,   371,   372,   374,   428,
       1,   371,     1,   371,     1,   371,     1,    90,    91,    92,
      93,   358,   401,     1,   357,   371,   408,     1,   371,     1,
     371,     1,   408,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   372,     1,   374,     1,   371,     1,   374,     1,
     371,     1,   374,     1,   374,     1,   374,     1,   374,     1,
     374,     1,   371,   372,   373,   374,   375,   382,   385,   398,
     400,   401,   406,   407,   424,   425,   426,   427,   457,   458,
       1,   407,     1,   371,     1,   407,     1,   371,     1,   371,
       1,   371,   371,   371,   371,   408,   408,   408,   408,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   374,
     371,   371,   371,   371,   371,   371,   371,   371,   371,     1,
     408,     1,   371,     1,   374,     1,   371,   337,     1,   371,
       1,   371,     1,   371,     1,   371,     1,   374,     1,   371,
       1,   371,     1,   408,     1,   408,     1,   408,     1,   408,
       1,   408,     1,   408,     1,   408,     1,   408,     1,   408,
       1,   408,     1,   408,     1,   371,     1,   371,     1,   374,
       1,   374,     1,   371,   374,   374,     1,   374,   374,   374,
       1,   374,     1,   371,     1,   371,     1,   371,     1,   371,
       1,   371,     1,   371,     1,   371,     1,   371,     1,   372,
     374,     1,   372,   374,     1,   372,   374,     1,   372,   374,
       1,   372,   374,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   408,     1,   408,     1,
     408,     1,   372,   374,     1,   371,     1,   371,     1,   371,
       1,   371,   425,     1,   427,     1,   371,     1,   371,   371,
     371,   371,   371,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   408,     1,   408,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   371,     1,   254,   255,
     256,   257,     1,   371,     1,   371,     1,   371,     1,   371,
       1,   374,     1,   374,     1,   374,     1,   371,     1,   371,
       1,   371,     1,   398,     1,   371,     1,   371,     1,   371,
       1,   371,     1,   371,     1,   371,     1,   371,     1,   371,
       1,   371,     1,   371,     1,   371,     1,   371,     1,   371,
       1,   371,     1,   371,     1,   372,   374,     1,   371,   372,
     371,     1,   371,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   374,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   371,     1,   371,   301,
     302,   303,   304,   305,   307,     1,   408,   371,   371,     1,
     408,     1,   408,     1,   371,     1,   371,     1,   371,     1,
     371,     1,   371,     1,   371,     1,   374,     1,   374,   379,
     388,   379,     1,   385,     1,   383,     1,   385,   383,     1,
     385,   383,     1,   385,   383,     1,   385,    59,   371,   372,
     421,   371,   435,   386,   371,   367,   398,   399,   426,   388,
     388,   407,   112,   113,   114,   357,   367,   383,   379,   381,
     379,   381,   379,   379,   337,   337,   337,   337,   337,   337,
     410,   371,   414,   428,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    13,    14,    15,    23,    24,    25,    26,
      27,    28,    29,    30,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    44,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    60,    61,    62,    66,    67,    68,
      69,    70,    71,   322,   372,   376,   377,   380,   459,   461,
     462,   463,   467,   468,   476,   477,   479,   480,   483,   484,
     486,   490,   491,   492,   496,   428,   461,   428,   461,   428,
     461,   378,   337,   386,   461,     1,   436,   371,   379,   381,
     386,     1,   358,   371,   404,   400,    90,    91,    92,    93,
      94,    95,   398,   403,   374,     1,   371,   457,     1,   457,
     112,   113,   114,   164,   165,   380,   416,   417,   374,   374,
     374,   374,     1,   374,     1,   374,     1,   374,     1,   374,
       1,   374,     1,   374,   386,     1,   382,     1,   382,     1,
     382,     1,   382,     1,   382,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   323,   357,   361,   363,   364,   365,   366,
     368,   369,   370,   374,   382,   383,   408,   449,   450,   451,
     452,   453,   454,   459,   471,   476,   477,   478,   479,   481,
     483,   484,   487,   488,   489,   382,   489,   382,   489,     1,
     382,     1,   382,     1,   382,   382,     1,   382,     1,   382,
       1,   382,     1,   382,     1,   382,     1,   382,     1,   382,
       1,   382,   382,     1,   382,     1,   382,     1,   382,     1,
     382,   382,   382,   382,   382,   382,   382,   489,     1,   382,
       1,   382,     1,   382,   382,   382,   382,   382,     1,   489,
     489,     1,   382,     1,   382,     1,   382,     1,   382,     1,
     382,     1,   493,     1,   380,     1,   384,   462,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   372,   473,   474,
     475,   337,   485,   380,     1,   382,   380,   386,   384,   386,
     384,   386,   384,   386,     1,   371,   374,   367,   384,   383,
     367,   399,   388,   113,   114,   388,   388,   113,   337,   337,
     337,   337,   337,   384,   416,   381,   381,   379,   379,   383,
       1,    63,   372,   374,   381,   424,   456,     1,    63,   374,
     424,   456,     1,    63,   374,   424,   456,     1,    63,   374,
     424,   456,     1,    63,   374,   424,   456,     1,   345,   346,
     347,   350,   351,   444,   446,   444,   444,     1,   444,   472,
       1,   489,     1,   489,     1,   489,   382,   382,   382,     1,
     381,   477,   479,   483,   484,   489,   490,     1,   461,     1,
     446,     1,   352,   353,   354,   355,   444,   445,     1,   446,
     475,     1,   489,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   447,   448,   381,   381,
       1,   371,   374,     1,   374,     1,   372,   489,   374,     1,
     374,     1,   374,     1,   374,     1,   374,     1,   371,     1,
     371,   381,     1,   381,   408,   381,     1,   374,     1,   374,
       1,   374,     1,   374,   381,   381,   381,     1,   371,   381,
       1,   401,   383,   460,   462,     1,   398,     1,   371,     1,
     398,   401,   405,   381,   381,   381,   381,   383,   460,     1,
     374,     1,   374,   371,   412,   371,   412,   371,   412,   382,
     367,   385,   489,     1,   374,   476,   477,   482,   484,   383,
     383,   383,   383,   298,   298,   421,   461,   371,   404,   374,
     371,   398,   398,   401,     1,   371,     1,   374,     1,   398,
     401,     1,   371,   374,   408,   374,   376,   408,   461,   381,
     379,   381,   379,   381,   379,   381,   357,   367,   379,   381,
     381,   379,   381,   379,   381,   379,   381,   379,   381,   381,
     379,   381,   379,   381,   379,   381,   379,   381,   381,   379,
     381,   379,   381,   379,   381,   379,   381,   381,   379,   381,
     379,   381,   379,   381,   379,   381,     1,   372,   489,     1,
      90,    91,    92,    93,    94,    95,   358,   402,   489,     1,
     402,   489,     1,   449,   453,   372,   469,   470,     1,   489,
       1,   489,     1,   489,   381,   381,   381,   384,   384,     1,
      88,   489,     1,   489,     1,   489,     1,    88,   371,   372,
     424,   455,   456,   489,   385,     1,   489,     1,   489,     1,
     489,     1,   489,   489,   489,   489,     1,   489,     1,   489,
       1,   489,     1,   489,     1,   489,     1,   489,     1,   489,
     381,   379,   381,   381,   379,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   461,    49,   381,   381,   381,
     381,   381,   388,   388,   381,     1,    58,    59,   384,   465,
     466,   381,   379,   381,   381,   381,   381,   381,   381,   381,
     381,   489,   494,   495,   474,   386,   379,   381,   475,   379,
     461,   461,   461,   461,   374,   374,   337,   384,   367,   113,
     113,   114,   388,   388,   388,   388,   388,   381,   381,   381,
     381,   381,   384,    64,   371,   371,   371,     1,   372,     1,
     372,   371,    64,   371,   371,   371,   371,    64,   371,   371,
     371,   371,    64,   371,   371,   371,   371,    64,   371,   371,
     371,   371,   385,   367,   381,   381,   381,   381,   381,   379,
     359,   408,   374,   374,   384,   460,     1,   404,   398,   384,
       1,   359,   464,   489,   388,   384,   465,   371,   489,   379,
     381,   412,     1,   412,   384,   384,   384,   384,   371,   374,
     371,   374,   371,   371,   398,   404,   398,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   374,   408,   469,   489,     1,   371,   424,   386,
     381,   381,   388,   388,     1,   464,   388,   461,   381,   381,
     495,   381,   381,   381,   113,   114,   388,   388,   386,   386,
     379,   404,   461,   388,   388,     1,   461,   374,   371,   404,
     489,   461,   461,   113,   381
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   389,   390,   391,   391,   391,   392,   392,   392,   392,
     392,   393,   392,   394,   392,   392,   395,   392,   396,   392,
     397,   392,   392,   392,   398,   398,   398,   399,   399,   400,
     400,   401,   401,   401,   401,   401,   402,   402,   402,   402,
     402,   402,   402,   403,   403,   403,   403,   403,   403,   404,
     404,   405,   405,   405,   405,   405,   406,   406,   406,   406,
     406,   407,   407,   408,   408,   409,   409,   410,   410,   411,
     411,   412,   412,   413,   413,   414,   414,   415,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   417,   417,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   419,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   420,   420,   421,
     421,   421,   422,   422,   422,   422,   422,   422,   422,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   424,   424,   425,   426,   427,   427,   428,   428,
     428,   429,   429,   430,   430,   430,   430,   431,   432,   432,
     432,   433,   433,   435,   434,   434,   434,   436,   434,   434,
     437,   438,   438,   438,   439,   440,   440,   440,   441,   442,
     442,   443,   443,   443,   443,   443,   443,   444,   444,   444,
     444,   445,   445,   445,   445,   446,   446,   447,   447,   447,
     447,   447,   447,   447,   448,   448,   448,   448,   449,   449,
     449,   450,   450,   450,   451,   451,   451,   451,   451,   452,
     452,   453,   453,   453,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   455,   455,   455,   455,   456,   456,   456,
     456,   456,   457,   457,   457,   458,   458,   458,   458,   458,
     459,   460,   460,   461,   461,   461,   462,   462,   462,   462,
     462,   462,   462,   462,   463,   463,   464,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   466,   466,
     467,   467,   467,   467,   468,   469,   469,   469,   470,   470,
     472,   471,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   474,   475,   475,   476,   477,   478,   479,   480,   480,
     481,   481,   481,   482,   482,   482,   483,   484,   485,   486,
     486,   486,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   488,   488,   488,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   490,   491,
     491,   491,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   493,   492,   492,
     494,   494,   494,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     5,     3,     1,     3,     3,     5,
       3,     1,     2,     1,     2,     2,     2,     1,     3,     1,
       3,     1,     1,     2,     2,     1,     3,     1,     7,     5,
       5,     3,     3,     3,     3,     5,     7,     3,     3,     3,
       3,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     5,
       6,     7,     9,     8,     9,    11,    10,    12,     5,     6,
       7,     8,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     5,     5,     7,     7,     5,     8,     8,     2,
       4,     6,     2,     2,     4,     6,     2,     2,     2,     3,
       3,     8,     8,     2,     8,     8,     8,     2,     2,     2,
       3,     3,     1,     1,     7,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     7,     2,     2,     1,     4,     7,
       2,     1,     1,     0,     5,     2,     2,     0,     8,     5,
       1,     4,     7,     2,     1,     4,     7,     2,     1,     7,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
       2,     2,     1,     2,     3,     5,     1,     4,     5,     3,
       4,     3,     2,     4,     5,     3,     4,     4,     2,     1,
       5,     4,     2,     5,     3,     1,     4,     4,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     5,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     2,     8,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     2,     3,     1,
       1,     1,     3,     4,     4,     4,     6,     6,     6,     6,
       6,     4,     2,     4,     4,     4,     4,     6,     6,     6,
       6,     6,     4,     2,     4,     4,     4,     4,     6,     6,
       6,     6,     6,     4,     2,     4,     4,     4,     4,     6,
       6,     6,     6,     6,     4,     2,     4,     4,     4,     4,
       6,     6,     6,     6,     6,     4,     2,     4,     4,     6,
       2,     4,     4,     4,     2,     4,     4,     2,     4,     4,
       2,     6,     6,     6,     4,     2,     6,     2,     4,     4,
       4,     2,     4,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     4,     4,     2,     4,     3,     2,     4,     3,
       2,     4,     3,     4,     2,     4,     4,     2,     4,     4,
       2,     4,     4,     2,     4,     4,     2,     4,     4,     2,
       4,     3,     1,     3,     1,     3,     1,     4,     3,     1,
       4,     4,     4,     4,     4,     2,     4,     4,     2,     4,
       4,     2,     3,     1,     3,     1,     3,     1,     3,     1,
       6,     6,     2,     4,     4,     2,     4,     0,     5,     2,
       0,     3,     1,     1,     3,     2,     1,     3,     2,     1,
       1,     3,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* statements: statements statement  */
#line 670 "core/cfg.y"
                             {}
#line 5355 "core/cfg.tab.c"
    break;

  case 4: /* statements: statement  */
#line 671 "core/cfg.y"
                    {}
#line 5361 "core/cfg.tab.c"
    break;

  case 5: /* statements: statements error  */
#line 672 "core/cfg.y"
                           { yyerror(""); YYABORT;}
#line 5367 "core/cfg.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 680 "core/cfg.y"
          {rt=REQUEST_ROUTE;}
#line 5373 "core/cfg.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 681 "core/cfg.y"
          {rt=FAILURE_ROUTE;}
#line 5379 "core/cfg.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 683 "core/cfg.y"
          {rt=BRANCH_ROUTE;}
#line 5385 "core/cfg.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 684 "core/cfg.y"
          {rt=ONSEND_ROUTE;}
#line 5391 "core/cfg.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 685 "core/cfg.y"
          {rt=EVENT_ROUTE;}
#line 5397 "core/cfg.tab.c"
    break;

  case 24: /* listen_id: ip  */
#line 690 "core/cfg.y"
           {
		if ((yyvsp[0].ipaddr)){
			tmp=ip_addr2a((yyvsp[0].ipaddr));
			if (tmp==0) {
				LM_CRIT("cfg. parser: bad ip address.\n");
				(yyval.strval)=0;
			} else {
				i_tmp=strlen(tmp)+1;
				(yyval.strval)=pkg_malloc(i_tmp);
				if ((yyval.strval)==0) {
					PKG_MEM_CRITICAL;
				} else {
					strncpy((yyval.strval), tmp, i_tmp);
				}
			}
		}
	}
#line 5419 "core/cfg.tab.c"
    break;

  case 25: /* listen_id: STRING  */
#line 707 "core/cfg.y"
                 {
		(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
		if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
		} else {
				i_tmp=strlen((yyvsp[0].strval))+1;
				strncpy((yyval.strval), (yyvsp[0].strval), i_tmp);
		}
	}
#line 5433 "core/cfg.tab.c"
    break;

  case 26: /* listen_id: host_or_if  */
#line 716 "core/cfg.y"
                     {
		if ((yyvsp[0].strval)){
			(yyval.strval)=pkg_malloc(strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
					PKG_MEM_CRITICAL;
			} else {
					i_tmp=strlen((yyvsp[0].strval))+1;
					strncpy((yyval.strval), (yyvsp[0].strval), i_tmp);
			}
		}
	}
#line 5449 "core/cfg.tab.c"
    break;

  case 27: /* listen_id_lst: listen_id  */
#line 731 "core/cfg.y"
                        { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), SI_IS_MHOMED); }
#line 5455 "core/cfg.tab.c"
    break;

  case 28: /* listen_id_lst: listen_id COMMA listen_id_lst  */
#line 732 "core/cfg.y"
                                        { (yyval.name_l)=mk_name_lst((yyvsp[-2].strval), SI_IS_MHOMED);
										if ((yyval.name_l)) (yyval.name_l)->next=(yyvsp[0].name_l);
									}
#line 5463 "core/cfg.tab.c"
    break;

  case 29: /* listen_id2: LPAREN listen_id_lst RPAREN  */
#line 738 "core/cfg.y"
                                    { (yyval.name_l)=(yyvsp[-1].name_l); }
#line 5469 "core/cfg.tab.c"
    break;

  case 30: /* listen_id2: listen_id  */
#line 739 "core/cfg.y"
                        { (yyval.name_l)=mk_name_lst((yyvsp[0].strval), 0); }
#line 5475 "core/cfg.tab.c"
    break;

  case 31: /* proto: UDP  */
#line 743 "core/cfg.y"
                { (yyval.intval)=PROTO_UDP; }
#line 5481 "core/cfg.tab.c"
    break;

  case 32: /* proto: TCP  */
#line 744 "core/cfg.y"
                { (yyval.intval)=PROTO_TCP; }
#line 5487 "core/cfg.tab.c"
    break;

  case 33: /* proto: TLS  */
#line 745 "core/cfg.y"
                { (yyval.intval)=PROTO_TLS; }
#line 5493 "core/cfg.tab.c"
    break;

  case 34: /* proto: SCTP  */
#line 746 "core/cfg.y"
                { (yyval.intval)=PROTO_SCTP; }
#line 5499 "core/cfg.tab.c"
    break;

  case 35: /* proto: STAR  */
#line 747 "core/cfg.y"
                { (yyval.intval)=0; }
#line 5505 "core/cfg.tab.c"
    break;

  case 36: /* eqproto: UDP  */
#line 750 "core/cfg.y"
                { (yyval.intval)=PROTO_UDP; }
#line 5511 "core/cfg.tab.c"
    break;

  case 37: /* eqproto: TCP  */
#line 751 "core/cfg.y"
                { (yyval.intval)=PROTO_TCP; }
#line 5517 "core/cfg.tab.c"
    break;

  case 38: /* eqproto: TLS  */
#line 752 "core/cfg.y"
                { (yyval.intval)=PROTO_TLS; }
#line 5523 "core/cfg.tab.c"
    break;

  case 39: /* eqproto: SCTP  */
#line 753 "core/cfg.y"
                { (yyval.intval)=PROTO_SCTP; }
#line 5529 "core/cfg.tab.c"
    break;

  case 40: /* eqproto: WS  */
#line 754 "core/cfg.y"
                { (yyval.intval)=PROTO_WS; }
#line 5535 "core/cfg.tab.c"
    break;

  case 41: /* eqproto: WSS  */
#line 755 "core/cfg.y"
                { (yyval.intval)=PROTO_WSS; }
#line 5541 "core/cfg.tab.c"
    break;

  case 42: /* eqproto: STAR  */
#line 756 "core/cfg.y"
                { (yyval.intval)=0; }
#line 5547 "core/cfg.tab.c"
    break;

  case 43: /* xproto: UDP  */
#line 759 "core/cfg.y"
                { (yyval.intval)=PROTO_UDP; }
#line 5553 "core/cfg.tab.c"
    break;

  case 44: /* xproto: TCP  */
#line 760 "core/cfg.y"
                { (yyval.intval)=PROTO_TCP; }
#line 5559 "core/cfg.tab.c"
    break;

  case 45: /* xproto: TLS  */
#line 761 "core/cfg.y"
                { (yyval.intval)=PROTO_TLS; }
#line 5565 "core/cfg.tab.c"
    break;

  case 46: /* xproto: SCTP  */
#line 762 "core/cfg.y"
                { (yyval.intval)=PROTO_SCTP; }
#line 5571 "core/cfg.tab.c"
    break;

  case 47: /* xproto: WS  */
#line 763 "core/cfg.y"
                { (yyval.intval)=PROTO_WS; }
#line 5577 "core/cfg.tab.c"
    break;

  case 48: /* xproto: WSS  */
#line 764 "core/cfg.y"
                { (yyval.intval)=PROTO_WSS; }
#line 5583 "core/cfg.tab.c"
    break;

  case 49: /* port: NUMBER  */
#line 768 "core/cfg.y"
                { (yyval.intval)=(yyvsp[0].intval); }
#line 5589 "core/cfg.tab.c"
    break;

  case 50: /* port: STAR  */
#line 769 "core/cfg.y"
                { (yyval.intval)=0; }
#line 5595 "core/cfg.tab.c"
    break;

  case 51: /* phostport: listen_id  */
#line 772 "core/cfg.y"
                                { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), 0, 0); }
#line 5601 "core/cfg.tab.c"
    break;

  case 52: /* phostport: listen_id COLON port  */
#line 773 "core/cfg.y"
                                { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), 0, (yyvsp[0].intval)); }
#line 5607 "core/cfg.tab.c"
    break;

  case 53: /* phostport: proto COLON listen_id  */
#line 774 "core/cfg.y"
                                { (yyval.sockid)=mk_listen_id((yyvsp[0].strval), (yyvsp[-2].intval), 0); }
#line 5613 "core/cfg.tab.c"
    break;

  case 54: /* phostport: proto COLON listen_id COLON port  */
#line 775 "core/cfg.y"
                                                { (yyval.sockid)=mk_listen_id((yyvsp[-2].strval), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5619 "core/cfg.tab.c"
    break;

  case 55: /* phostport: listen_id COLON error  */
#line 776 "core/cfg.y"
                                { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5625 "core/cfg.tab.c"
    break;

  case 56: /* listen_phostport: listen_id2  */
#line 780 "core/cfg.y"
                                { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), 0, 0); }
#line 5631 "core/cfg.tab.c"
    break;

  case 57: /* listen_phostport: listen_id2 COLON port  */
#line 781 "core/cfg.y"
                                { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), 0, (yyvsp[0].intval)); }
#line 5637 "core/cfg.tab.c"
    break;

  case 58: /* listen_phostport: proto COLON listen_id2  */
#line 782 "core/cfg.y"
                                        { (yyval.sockid)=mk_listen_id2((yyvsp[0].name_l), (yyvsp[-2].intval), 0); }
#line 5643 "core/cfg.tab.c"
    break;

  case 59: /* listen_phostport: proto COLON listen_id2 COLON port  */
#line 783 "core/cfg.y"
                                                { (yyval.sockid)=mk_listen_id2((yyvsp[-2].name_l), (yyvsp[-4].intval), (yyvsp[0].intval));}
#line 5649 "core/cfg.tab.c"
    break;

  case 60: /* listen_phostport: listen_id2 COLON error  */
#line 784 "core/cfg.y"
                                 { (yyval.sockid)=0; yyerror("port number expected"); }
#line 5655 "core/cfg.tab.c"
    break;

  case 61: /* id_lst: listen_phostport  */
#line 788 "core/cfg.y"
                                        {  (yyval.sockid)=(yyvsp[0].sockid) ; }
#line 5661 "core/cfg.tab.c"
    break;

  case 62: /* id_lst: listen_phostport id_lst  */
#line 789 "core/cfg.y"
                                        { (yyval.sockid)=(yyvsp[-1].sockid);  if ((yyval.sockid)) (yyval.sockid)->next=(yyvsp[0].sockid); }
#line 5667 "core/cfg.tab.c"
    break;

  case 64: /* intno: MINUS NUMBER  */
#line 793 "core/cfg.y"
                                    { (yyval.intval)=-(yyvsp[0].intval); }
#line 5673 "core/cfg.tab.c"
    break;

  case 66: /* flags_decl: FLAGS_DECL error  */
#line 797 "core/cfg.y"
                                                 { yyerror("flag list expected\n"); }
#line 5679 "core/cfg.tab.c"
    break;

  case 69: /* flag_spec: flag_name  */
#line 803 "core/cfg.y"
                                        { if (register_flag((yyvsp[0].strval),-1)<0)
								yyerror("register flag failed");
						}
#line 5687 "core/cfg.tab.c"
    break;

  case 70: /* flag_spec: flag_name COLON NUMBER  */
#line 806 "core/cfg.y"
                                                       {
						if (register_flag((yyvsp[-2].strval), (yyvsp[0].intval))<0)
								yyerror("register flag failed");
										}
#line 5696 "core/cfg.tab.c"
    break;

  case 71: /* flag_name: STRING  */
#line 812 "core/cfg.y"
                                { (yyval.strval)=(yyvsp[0].strval); }
#line 5702 "core/cfg.tab.c"
    break;

  case 72: /* flag_name: ID  */
#line 813 "core/cfg.y"
                                                { (yyval.strval)=(yyvsp[0].strval); }
#line 5708 "core/cfg.tab.c"
    break;

  case 74: /* avpflags_decl: AVPFLAGS_DECL error  */
#line 818 "core/cfg.y"
                              { yyerror("avpflag list expected\n"); }
#line 5714 "core/cfg.tab.c"
    break;

  case 77: /* avpflag_spec: flag_name  */
#line 825 "core/cfg.y"
                  {
		if (register_avpflag((yyvsp[0].strval))==0)
			yyerror("cannot declare avpflag");
	}
#line 5723 "core/cfg.tab.c"
    break;

  case 78: /* socket_lattr: BIND EQUAL proto COLON listen_id COLON port  */
#line 831 "core/cfg.y"
                                                        {
			tmp_sa.bindproto = (yyvsp[-4].intval);
			tmp_sa.bindaddr.s = (yyvsp[-2].strval);
			tmp_sa.bindaddr.len = strlen(tmp_sa.bindaddr.s);
			tmp_sa.bindport = (yyvsp[0].intval);
		}
#line 5734 "core/cfg.tab.c"
    break;

  case 79: /* socket_lattr: BIND EQUAL listen_id COLON port  */
#line 837 "core/cfg.y"
                                                {
			tmp_sa.bindaddr.s = (yyvsp[-2].strval);
			tmp_sa.bindaddr.len = strlen(tmp_sa.bindaddr.s);
			tmp_sa.bindport = (yyvsp[0].intval);
		}
#line 5744 "core/cfg.tab.c"
    break;

  case 80: /* socket_lattr: BIND EQUAL proto COLON listen_id  */
#line 842 "core/cfg.y"
                                                {
			tmp_sa.bindproto = (yyvsp[-2].intval);
			tmp_sa.bindaddr.s = (yyvsp[0].strval);
			tmp_sa.bindaddr.len = strlen(tmp_sa.bindaddr.s);
		}
#line 5754 "core/cfg.tab.c"
    break;

  case 81: /* socket_lattr: BIND EQUAL listen_id  */
#line 847 "core/cfg.y"
                                {
			tmp_sa.bindaddr.s = (yyvsp[0].strval);
			tmp_sa.bindaddr.len = strlen(tmp_sa.bindaddr.s);
		}
#line 5763 "core/cfg.tab.c"
    break;

  case 82: /* socket_lattr: BIND EQUAL error  */
#line 851 "core/cfg.y"
                           { yyerror("string value expected"); }
#line 5769 "core/cfg.tab.c"
    break;

  case 83: /* socket_lattr: STRNAME EQUAL STRING  */
#line 852 "core/cfg.y"
                               {
			tmp_sa.sockname.s = (yyvsp[0].strval);
			tmp_sa.sockname.len = strlen(tmp_sa.sockname.s);
		}
#line 5778 "core/cfg.tab.c"
    break;

  case 84: /* socket_lattr: STRNAME EQUAL error  */
#line 856 "core/cfg.y"
                              { yyerror("string value expected"); }
#line 5784 "core/cfg.tab.c"
    break;

  case 85: /* socket_lattr: ADVERTISE EQUAL listen_id COLON NUMBER  */
#line 857 "core/cfg.y"
                                                 {
			tmp_sa.useaddr.s = (yyvsp[-2].strval);
			tmp_sa.useaddr.len = strlen(tmp_sa.useaddr.s);
			tmp_sa.useport = (yyvsp[0].intval);
		}
#line 5794 "core/cfg.tab.c"
    break;

  case 86: /* socket_lattr: ADVERTISE EQUAL proto COLON listen_id COLON NUMBER  */
#line 862 "core/cfg.y"
                                                             {
			tmp_sa.useproto = (yyvsp[-4].intval);
			tmp_sa.useaddr.s = (yyvsp[-2].strval);
			tmp_sa.useaddr.len = strlen(tmp_sa.useaddr.s);
			tmp_sa.useport = (yyvsp[0].intval);
		}
#line 5805 "core/cfg.tab.c"
    break;

  case 87: /* socket_lattr: WORKERS EQUAL NUMBER  */
#line 868 "core/cfg.y"
                               { tmp_sa.workers=(yyvsp[0].intval); }
#line 5811 "core/cfg.tab.c"
    break;

  case 88: /* socket_lattr: WORKERS EQUAL error  */
#line 869 "core/cfg.y"
                              { yyerror("number expected"); }
#line 5817 "core/cfg.tab.c"
    break;

  case 89: /* socket_lattr: VIRTUAL EQUAL NUMBER  */
#line 870 "core/cfg.y"
                               { if((yyvsp[0].intval)!=0) { tmp_sa.sflags |= SI_IS_VIRTUAL; } }
#line 5823 "core/cfg.tab.c"
    break;

  case 90: /* socket_lattr: VIRTUAL EQUAL error  */
#line 871 "core/cfg.y"
                              { yyerror("number expected"); }
#line 5829 "core/cfg.tab.c"
    break;

  case 91: /* socket_lattr: SEMICOLON  */
#line 872 "core/cfg.y"
                    {}
#line 5835 "core/cfg.tab.c"
    break;

  case 92: /* socket_lattrs: socket_lattrs socket_lattr  */
#line 875 "core/cfg.y"
                                   {}
#line 5841 "core/cfg.tab.c"
    break;

  case 93: /* socket_lattrs: socket_lattr  */
#line 876 "core/cfg.y"
                       {}
#line 5847 "core/cfg.tab.c"
    break;

  case 94: /* assign_stm: DEBUG_V EQUAL intno  */
#line 879 "core/cfg.y"
                            { default_core_cfg.debug=(yyvsp[0].intval); }
#line 5853 "core/cfg.tab.c"
    break;

  case 95: /* assign_stm: DEBUG_V EQUAL error  */
#line 880 "core/cfg.y"
                               { yyerror("number  expected"); }
#line 5859 "core/cfg.tab.c"
    break;

  case 96: /* assign_stm: FORK EQUAL NUMBER  */
#line 881 "core/cfg.y"
                             { dont_fork= ! (yyvsp[0].intval); }
#line 5865 "core/cfg.tab.c"
    break;

  case 97: /* assign_stm: FORK EQUAL error  */
#line 882 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 5871 "core/cfg.tab.c"
    break;

  case 98: /* assign_stm: FORK_DELAY EQUAL NUMBER  */
#line 883 "core/cfg.y"
                                   { set_fork_delay((yyvsp[0].intval)); }
#line 5877 "core/cfg.tab.c"
    break;

  case 99: /* assign_stm: FORK_DELAY EQUAL error  */
#line 884 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 5883 "core/cfg.tab.c"
    break;

  case 100: /* assign_stm: MODINIT_DELAY EQUAL NUMBER  */
#line 885 "core/cfg.y"
                                      { set_modinit_delay((yyvsp[0].intval)); }
#line 5889 "core/cfg.tab.c"
    break;

  case 101: /* assign_stm: MODINIT_DELAY EQUAL error  */
#line 886 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 5895 "core/cfg.tab.c"
    break;

  case 102: /* assign_stm: LOGSTDERROR EQUAL NUMBER  */
#line 887 "core/cfg.y"
                                   { if (!config_check)  /* if set from cmd line, don't overwrite from yyparse()*/
					if(log_stderr == 0) log_stderr=(yyvsp[0].intval);
				   }
#line 5903 "core/cfg.tab.c"
    break;

  case 103: /* assign_stm: LOGSTDERROR EQUAL error  */
#line 890 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 5909 "core/cfg.tab.c"
    break;

  case 104: /* assign_stm: LOGFACILITY EQUAL ID  */
#line 891 "core/cfg.y"
                               {
		if ( (i_tmp=str2facility((yyvsp[0].strval)))==-1)
			yyerror("bad facility (see syslog(3) man page)");
		if (!config_check)
			default_core_cfg.log_facility=i_tmp;
	}
#line 5920 "core/cfg.tab.c"
    break;

  case 105: /* assign_stm: LOGFACILITY EQUAL error  */
#line 897 "core/cfg.y"
                                  { yyerror("ID expected"); }
#line 5926 "core/cfg.tab.c"
    break;

  case 106: /* assign_stm: LOGNAME EQUAL STRING  */
#line 898 "core/cfg.y"
                               { log_name=(yyvsp[0].strval); }
#line 5932 "core/cfg.tab.c"
    break;

  case 107: /* assign_stm: LOGNAME EQUAL error  */
#line 899 "core/cfg.y"
                              { yyerror("string value expected"); }
#line 5938 "core/cfg.tab.c"
    break;

  case 108: /* assign_stm: LOGCOLOR EQUAL NUMBER  */
#line 900 "core/cfg.y"
                                { log_color=(yyvsp[0].intval); }
#line 5944 "core/cfg.tab.c"
    break;

  case 109: /* assign_stm: LOGCOLOR EQUAL error  */
#line 901 "core/cfg.y"
                               { yyerror("boolean value expected"); }
#line 5950 "core/cfg.tab.c"
    break;

  case 110: /* assign_stm: LOGPREFIX EQUAL STRING  */
#line 902 "core/cfg.y"
                                 { log_prefix_fmt=(yyvsp[0].strval); }
#line 5956 "core/cfg.tab.c"
    break;

  case 111: /* assign_stm: LOGPREFIX EQUAL error  */
#line 903 "core/cfg.y"
                                { yyerror("string value expected"); }
#line 5962 "core/cfg.tab.c"
    break;

  case 112: /* assign_stm: LOGPREFIXMODE EQUAL NUMBER  */
#line 904 "core/cfg.y"
                                     { log_prefix_mode=(yyvsp[0].intval); }
#line 5968 "core/cfg.tab.c"
    break;

  case 113: /* assign_stm: LOGPREFIXMODE EQUAL error  */
#line 905 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 5974 "core/cfg.tab.c"
    break;

  case 114: /* assign_stm: LOGENGINETYPE EQUAL STRING  */
#line 906 "core/cfg.y"
                                     { _km_log_engine_type=(yyvsp[0].strval); }
#line 5980 "core/cfg.tab.c"
    break;

  case 115: /* assign_stm: LOGENGINETYPE EQUAL error  */
#line 907 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 5986 "core/cfg.tab.c"
    break;

  case 116: /* assign_stm: LOGENGINEDATA EQUAL STRING  */
#line 908 "core/cfg.y"
                                     { _km_log_engine_data=(yyvsp[0].strval); }
#line 5992 "core/cfg.tab.c"
    break;

  case 117: /* assign_stm: LOGENGINEDATA EQUAL error  */
#line 909 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 5998 "core/cfg.tab.c"
    break;

  case 118: /* assign_stm: XAVPVIAPARAMS EQUAL STRING  */
#line 910 "core/cfg.y"
                                     { _ksr_xavp_via_params.s=(yyvsp[0].strval);
			_ksr_xavp_via_params.len=strlen((yyvsp[0].strval));
		}
#line 6006 "core/cfg.tab.c"
    break;

  case 119: /* assign_stm: XAVPVIAPARAMS EQUAL error  */
#line 913 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 6012 "core/cfg.tab.c"
    break;

  case 120: /* assign_stm: XAVPVIAFIELDS EQUAL STRING  */
#line 914 "core/cfg.y"
                                     { _ksr_xavp_via_fields.s=(yyvsp[0].strval);
			_ksr_xavp_via_fields.len=strlen((yyvsp[0].strval));
		}
#line 6020 "core/cfg.tab.c"
    break;

  case 121: /* assign_stm: XAVPVIAFIELDS EQUAL error  */
#line 917 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 6026 "core/cfg.tab.c"
    break;

  case 122: /* assign_stm: XAVPVIAREPLYPARAMS EQUAL STRING  */
#line 918 "core/cfg.y"
                                          { _ksr_xavp_via_reply_params.s=(yyvsp[0].strval);
			_ksr_xavp_via_reply_params.len=strlen((yyvsp[0].strval));
		}
#line 6034 "core/cfg.tab.c"
    break;

  case 123: /* assign_stm: XAVPVIAREPLYPARAMS EQUAL error  */
#line 921 "core/cfg.y"
                                         { yyerror("string value expected"); }
#line 6040 "core/cfg.tab.c"
    break;

  case 124: /* assign_stm: DNS EQUAL NUMBER  */
#line 922 "core/cfg.y"
                             { received_dns|= ((yyvsp[0].intval))?DO_DNS:0; }
#line 6046 "core/cfg.tab.c"
    break;

  case 125: /* assign_stm: DNS EQUAL error  */
#line 923 "core/cfg.y"
                          { yyerror("boolean value expected"); }
#line 6052 "core/cfg.tab.c"
    break;

  case 126: /* assign_stm: REV_DNS EQUAL NUMBER  */
#line 924 "core/cfg.y"
                               { received_dns|= ((yyvsp[0].intval))?DO_REV_DNS:0; }
#line 6058 "core/cfg.tab.c"
    break;

  case 127: /* assign_stm: REV_DNS EQUAL error  */
#line 925 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 6064 "core/cfg.tab.c"
    break;

  case 128: /* assign_stm: DNS_TRY_IPV6 EQUAL NUMBER  */
#line 926 "core/cfg.y"
                                      { default_core_cfg.dns_try_ipv6=(yyvsp[0].intval); }
#line 6070 "core/cfg.tab.c"
    break;

  case 129: /* assign_stm: DNS_TRY_IPV6 error  */
#line 927 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 6076 "core/cfg.tab.c"
    break;

  case 130: /* assign_stm: DNS_TRY_NAPTR EQUAL NUMBER  */
#line 928 "core/cfg.y"
                                       { IF_NAPTR(default_core_cfg.dns_try_naptr=(yyvsp[0].intval)); }
#line 6082 "core/cfg.tab.c"
    break;

  case 131: /* assign_stm: DNS_TRY_NAPTR error  */
#line 929 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 6088 "core/cfg.tab.c"
    break;

  case 132: /* assign_stm: DNS_SRV_LB EQUAL NUMBER  */
#line 930 "core/cfg.y"
                                    { IF_DNS_FAILOVER(default_core_cfg.dns_srv_lb=(yyvsp[0].intval)); }
#line 6094 "core/cfg.tab.c"
    break;

  case 133: /* assign_stm: DNS_SRV_LB error  */
#line 931 "core/cfg.y"
                           { yyerror("boolean value expected"); }
#line 6100 "core/cfg.tab.c"
    break;

  case 134: /* assign_stm: DNS_UDP_PREF EQUAL intno  */
#line 932 "core/cfg.y"
                                   { IF_NAPTR(default_core_cfg.dns_udp_pref=(yyvsp[0].intval));}
#line 6106 "core/cfg.tab.c"
    break;

  case 135: /* assign_stm: DNS_UDP_PREF error  */
#line 933 "core/cfg.y"
                             { yyerror("number expected"); }
#line 6112 "core/cfg.tab.c"
    break;

  case 136: /* assign_stm: DNS_TCP_PREF EQUAL intno  */
#line 934 "core/cfg.y"
                                   { IF_NAPTR(default_core_cfg.dns_tcp_pref=(yyvsp[0].intval));}
#line 6118 "core/cfg.tab.c"
    break;

  case 137: /* assign_stm: DNS_TCP_PREF error  */
#line 935 "core/cfg.y"
                             { yyerror("number expected"); }
#line 6124 "core/cfg.tab.c"
    break;

  case 138: /* assign_stm: DNS_TLS_PREF EQUAL intno  */
#line 936 "core/cfg.y"
                                   { IF_NAPTR(default_core_cfg.dns_tls_pref=(yyvsp[0].intval));}
#line 6130 "core/cfg.tab.c"
    break;

  case 139: /* assign_stm: DNS_TLS_PREF error  */
#line 937 "core/cfg.y"
                             { yyerror("number expected"); }
#line 6136 "core/cfg.tab.c"
    break;

  case 140: /* assign_stm: DNS_SCTP_PREF EQUAL intno  */
#line 938 "core/cfg.y"
                                    {
								IF_NAPTR(default_core_cfg.dns_sctp_pref=(yyvsp[0].intval)); }
#line 6143 "core/cfg.tab.c"
    break;

  case 141: /* assign_stm: DNS_SCTP_PREF error  */
#line 940 "core/cfg.y"
                              { yyerror("number expected"); }
#line 6149 "core/cfg.tab.c"
    break;

  case 142: /* assign_stm: DNS_RETR_TIME EQUAL NUMBER  */
#line 941 "core/cfg.y"
                                       { default_core_cfg.dns_retr_time=(yyvsp[0].intval); }
#line 6155 "core/cfg.tab.c"
    break;

  case 143: /* assign_stm: DNS_RETR_TIME error  */
#line 942 "core/cfg.y"
                              { yyerror("number expected"); }
#line 6161 "core/cfg.tab.c"
    break;

  case 144: /* assign_stm: DNS_SLOW_QUERY_MS EQUAL NUMBER  */
#line 943 "core/cfg.y"
                                           { default_core_cfg.dns_slow_query_ms=(yyvsp[0].intval); }
#line 6167 "core/cfg.tab.c"
    break;

  case 145: /* assign_stm: DNS_SLOW_QUERY_MS error  */
#line 944 "core/cfg.y"
                                  { yyerror("number expected"); }
#line 6173 "core/cfg.tab.c"
    break;

  case 146: /* assign_stm: DNS_RETR_NO EQUAL NUMBER  */
#line 945 "core/cfg.y"
                                     { default_core_cfg.dns_retr_no=(yyvsp[0].intval); }
#line 6179 "core/cfg.tab.c"
    break;

  case 147: /* assign_stm: DNS_RETR_NO error  */
#line 946 "core/cfg.y"
                            { yyerror("number expected"); }
#line 6185 "core/cfg.tab.c"
    break;

  case 148: /* assign_stm: DNS_SERVERS_NO EQUAL NUMBER  */
#line 947 "core/cfg.y"
                                        { default_core_cfg.dns_servers_no=(yyvsp[0].intval); }
#line 6191 "core/cfg.tab.c"
    break;

  case 149: /* assign_stm: DNS_SERVERS_NO error  */
#line 948 "core/cfg.y"
                               { yyerror("number expected"); }
#line 6197 "core/cfg.tab.c"
    break;

  case 150: /* assign_stm: DNS_USE_SEARCH EQUAL NUMBER  */
#line 949 "core/cfg.y"
                                        { default_core_cfg.dns_search_list=(yyvsp[0].intval); }
#line 6203 "core/cfg.tab.c"
    break;

  case 151: /* assign_stm: DNS_USE_SEARCH error  */
#line 950 "core/cfg.y"
                               { yyerror("boolean value expected"); }
#line 6209 "core/cfg.tab.c"
    break;

  case 152: /* assign_stm: DNS_SEARCH_FMATCH EQUAL NUMBER  */
#line 951 "core/cfg.y"
                                           { default_core_cfg.dns_search_fmatch=(yyvsp[0].intval); }
#line 6215 "core/cfg.tab.c"
    break;

  case 153: /* assign_stm: DNS_SEARCH_FMATCH error  */
#line 952 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 6221 "core/cfg.tab.c"
    break;

  case 154: /* assign_stm: DNS_NAPTR_IGNORE_RFC EQUAL NUMBER  */
#line 953 "core/cfg.y"
                                              { default_core_cfg.dns_naptr_ignore_rfc=(yyvsp[0].intval); }
#line 6227 "core/cfg.tab.c"
    break;

  case 155: /* assign_stm: DNS_NAPTR_IGNORE_RFC error  */
#line 954 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 6233 "core/cfg.tab.c"
    break;

  case 156: /* assign_stm: DNS_CACHE_INIT EQUAL NUMBER  */
#line 955 "core/cfg.y"
                                        { IF_DNS_CACHE(dns_cache_init=(yyvsp[0].intval)); }
#line 6239 "core/cfg.tab.c"
    break;

  case 157: /* assign_stm: DNS_CACHE_INIT error  */
#line 956 "core/cfg.y"
                               { yyerror("boolean value expected"); }
#line 6245 "core/cfg.tab.c"
    break;

  case 158: /* assign_stm: DNS_USE_CACHE EQUAL NUMBER  */
#line 957 "core/cfg.y"
                                       { IF_DNS_CACHE(default_core_cfg.use_dns_cache=(yyvsp[0].intval)); }
#line 6251 "core/cfg.tab.c"
    break;

  case 159: /* assign_stm: DNS_USE_CACHE error  */
#line 958 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 6257 "core/cfg.tab.c"
    break;

  case 160: /* assign_stm: DNS_USE_FAILOVER EQUAL NUMBER  */
#line 959 "core/cfg.y"
                                          { IF_DNS_FAILOVER(default_core_cfg.use_dns_failover=(yyvsp[0].intval));}
#line 6263 "core/cfg.tab.c"
    break;

  case 161: /* assign_stm: DNS_USE_FAILOVER error  */
#line 960 "core/cfg.y"
                                 { yyerror("boolean value expected"); }
#line 6269 "core/cfg.tab.c"
    break;

  case 162: /* assign_stm: DNS_CACHE_FLAGS EQUAL NUMBER  */
#line 961 "core/cfg.y"
                                         { IF_DNS_CACHE(default_core_cfg.dns_cache_flags=(yyvsp[0].intval)); }
#line 6275 "core/cfg.tab.c"
    break;

  case 163: /* assign_stm: DNS_CACHE_FLAGS error  */
#line 962 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 6281 "core/cfg.tab.c"
    break;

  case 164: /* assign_stm: DNS_CACHE_NEG_TTL EQUAL NUMBER  */
#line 963 "core/cfg.y"
                                           { IF_DNS_CACHE(default_core_cfg.dns_neg_cache_ttl=(yyvsp[0].intval)); }
#line 6287 "core/cfg.tab.c"
    break;

  case 165: /* assign_stm: DNS_CACHE_NEG_TTL error  */
#line 964 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 6293 "core/cfg.tab.c"
    break;

  case 166: /* assign_stm: DNS_CACHE_MAX_TTL EQUAL NUMBER  */
#line 965 "core/cfg.y"
                                           { IF_DNS_CACHE(default_core_cfg.dns_cache_max_ttl=(yyvsp[0].intval)); }
#line 6299 "core/cfg.tab.c"
    break;

  case 167: /* assign_stm: DNS_CACHE_MAX_TTL error  */
#line 966 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 6305 "core/cfg.tab.c"
    break;

  case 168: /* assign_stm: DNS_CACHE_MIN_TTL EQUAL NUMBER  */
#line 967 "core/cfg.y"
                                           { IF_DNS_CACHE(default_core_cfg.dns_cache_min_ttl=(yyvsp[0].intval)); }
#line 6311 "core/cfg.tab.c"
    break;

  case 169: /* assign_stm: DNS_CACHE_MIN_TTL error  */
#line 968 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 6317 "core/cfg.tab.c"
    break;

  case 170: /* assign_stm: DNS_CACHE_MEM EQUAL NUMBER  */
#line 969 "core/cfg.y"
                                       { IF_DNS_CACHE(default_core_cfg.dns_cache_max_mem=(yyvsp[0].intval)); }
#line 6323 "core/cfg.tab.c"
    break;

  case 171: /* assign_stm: DNS_CACHE_MEM error  */
#line 970 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 6329 "core/cfg.tab.c"
    break;

  case 172: /* assign_stm: DNS_CACHE_GC_INT EQUAL NUMBER  */
#line 971 "core/cfg.y"
                                          { IF_DNS_CACHE(dns_timer_interval=(yyvsp[0].intval)); }
#line 6335 "core/cfg.tab.c"
    break;

  case 173: /* assign_stm: DNS_CACHE_GC_INT error  */
#line 972 "core/cfg.y"
                                 { yyerror("boolean value expected"); }
#line 6341 "core/cfg.tab.c"
    break;

  case 174: /* assign_stm: DNS_CACHE_DEL_NONEXP EQUAL NUMBER  */
#line 973 "core/cfg.y"
                                              { IF_DNS_CACHE(default_core_cfg.dns_cache_del_nonexp=(yyvsp[0].intval)); }
#line 6347 "core/cfg.tab.c"
    break;

  case 175: /* assign_stm: DNS_CACHE_DEL_NONEXP error  */
#line 974 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 6353 "core/cfg.tab.c"
    break;

  case 176: /* assign_stm: DNS_CACHE_REC_PREF EQUAL NUMBER  */
#line 975 "core/cfg.y"
                                            { IF_DNS_CACHE(default_core_cfg.dns_cache_rec_pref=(yyvsp[0].intval)); }
#line 6359 "core/cfg.tab.c"
    break;

  case 177: /* assign_stm: DNS_CACHE_REC_PREF error  */
#line 976 "core/cfg.y"
                                   { yyerror("boolean value expected"); }
#line 6365 "core/cfg.tab.c"
    break;

  case 178: /* assign_stm: AUTO_BIND_IPV6 EQUAL NUMBER  */
#line 977 "core/cfg.y"
                                      {IF_AUTO_BIND_IPV6(auto_bind_ipv6 = (yyvsp[0].intval));}
#line 6371 "core/cfg.tab.c"
    break;

  case 179: /* assign_stm: AUTO_BIND_IPV6 error  */
#line 978 "core/cfg.y"
                               { yyerror("boolean value expected"); }
#line 6377 "core/cfg.tab.c"
    break;

  case 180: /* assign_stm: IPV6_HEX_STYLE EQUAL STRING  */
#line 979 "core/cfg.y"
                                      {
		ksr_ipv6_hex_style.s = (yyvsp[0].strval);
		if(ksr_ipv6_hex_style.s[0]!='a' && ksr_ipv6_hex_style.s[0]!='A'
				&& ksr_ipv6_hex_style.s[0]!='c') {
			yyerror("expected \"a\", \"A\" or \"c\" value");
		}
		ksr_ipv6_hex_style.len = strlen(ksr_ipv6_hex_style.s);
	}
#line 6390 "core/cfg.tab.c"
    break;

  case 181: /* assign_stm: IPV6_HEX_STYLE error  */
#line 987 "core/cfg.y"
                               { yyerror("string value expected"); }
#line 6396 "core/cfg.tab.c"
    break;

  case 182: /* assign_stm: BIND_IPV6_LINK_LOCAL EQUAL NUMBER  */
#line 988 "core/cfg.y"
                                            {
		sr_bind_ipv6_link_local = (yyvsp[0].intval);
		if((sr_bind_ipv6_link_local & KSR_IPV6_LINK_LOCAL_BIND)
				&& (sr_bind_ipv6_link_local & KSR_IPV6_LINK_LOCAL_SKIP)) {
			yyerror("incompatible modes set");
		}
	}
#line 6408 "core/cfg.tab.c"
    break;

  case 183: /* assign_stm: BIND_IPV6_LINK_LOCAL error  */
#line 995 "core/cfg.y"
                                     { yyerror("number expected"); }
#line 6414 "core/cfg.tab.c"
    break;

  case 184: /* assign_stm: DST_BLST_INIT EQUAL NUMBER  */
#line 996 "core/cfg.y"
                                       { IF_DST_BLOCKLIST(dst_blocklist_init=(yyvsp[0].intval)); }
#line 6420 "core/cfg.tab.c"
    break;

  case 185: /* assign_stm: DST_BLST_INIT error  */
#line 997 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 6426 "core/cfg.tab.c"
    break;

  case 186: /* assign_stm: USE_DST_BLST EQUAL NUMBER  */
#line 998 "core/cfg.y"
                                    {
		IF_DST_BLOCKLIST(default_core_cfg.use_dst_blocklist=(yyvsp[0].intval));
	}
#line 6434 "core/cfg.tab.c"
    break;

  case 187: /* assign_stm: USE_DST_BLST error  */
#line 1001 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 6440 "core/cfg.tab.c"
    break;

  case 188: /* assign_stm: DST_BLST_MEM EQUAL NUMBER  */
#line 1002 "core/cfg.y"
                                    {
		IF_DST_BLOCKLIST(default_core_cfg.blst_max_mem=(yyvsp[0].intval));
	}
#line 6448 "core/cfg.tab.c"
    break;

  case 189: /* assign_stm: DST_BLST_MEM error  */
#line 1005 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 6454 "core/cfg.tab.c"
    break;

  case 190: /* assign_stm: DST_BLST_TTL EQUAL NUMBER  */
#line 1006 "core/cfg.y"
                                    {
		IF_DST_BLOCKLIST(default_core_cfg.blst_timeout=(yyvsp[0].intval));
	}
#line 6462 "core/cfg.tab.c"
    break;

  case 191: /* assign_stm: DST_BLST_TTL error  */
#line 1009 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 6468 "core/cfg.tab.c"
    break;

  case 192: /* assign_stm: DST_BLST_GC_INT EQUAL NUMBER  */
#line 1010 "core/cfg.y"
                                       { IF_DST_BLOCKLIST(blst_timer_interval=(yyvsp[0].intval));}
#line 6474 "core/cfg.tab.c"
    break;

  case 193: /* assign_stm: DST_BLST_GC_INT error  */
#line 1011 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 6480 "core/cfg.tab.c"
    break;

  case 194: /* assign_stm: DST_BLST_UDP_IMASK EQUAL NUMBER  */
#line 1012 "core/cfg.y"
                                          {
		IF_DST_BLOCKLIST(default_core_cfg.blst_udp_imask=(yyvsp[0].intval));
	}
#line 6488 "core/cfg.tab.c"
    break;

  case 195: /* assign_stm: DST_BLST_UDP_IMASK error  */
#line 1015 "core/cfg.y"
                                   { yyerror("number(flags) expected"); }
#line 6494 "core/cfg.tab.c"
    break;

  case 196: /* assign_stm: DST_BLST_TCP_IMASK EQUAL NUMBER  */
#line 1016 "core/cfg.y"
                                          {
		IF_DST_BLOCKLIST(default_core_cfg.blst_tcp_imask=(yyvsp[0].intval));
	}
#line 6502 "core/cfg.tab.c"
    break;

  case 197: /* assign_stm: DST_BLST_TCP_IMASK error  */
#line 1019 "core/cfg.y"
                                   { yyerror("number(flags) expected"); }
#line 6508 "core/cfg.tab.c"
    break;

  case 198: /* assign_stm: DST_BLST_TLS_IMASK EQUAL NUMBER  */
#line 1020 "core/cfg.y"
                                          {
		IF_DST_BLOCKLIST(default_core_cfg.blst_tls_imask=(yyvsp[0].intval));
	}
#line 6516 "core/cfg.tab.c"
    break;

  case 199: /* assign_stm: DST_BLST_TLS_IMASK error  */
#line 1023 "core/cfg.y"
                                   { yyerror("number(flags) expected"); }
#line 6522 "core/cfg.tab.c"
    break;

  case 200: /* assign_stm: DST_BLST_SCTP_IMASK EQUAL NUMBER  */
#line 1024 "core/cfg.y"
                                           {
		IF_DST_BLOCKLIST(default_core_cfg.blst_sctp_imask=(yyvsp[0].intval));
	}
#line 6530 "core/cfg.tab.c"
    break;

  case 201: /* assign_stm: DST_BLST_SCTP_IMASK error  */
#line 1027 "core/cfg.y"
                                    { yyerror("number(flags) expected"); }
#line 6536 "core/cfg.tab.c"
    break;

  case 202: /* assign_stm: IP_FREE_BIND EQUAL intno  */
#line 1028 "core/cfg.y"
                                   { _sr_ip_free_bind=(yyvsp[0].intval); }
#line 6542 "core/cfg.tab.c"
    break;

  case 203: /* assign_stm: IP_FREE_BIND EQUAL error  */
#line 1029 "core/cfg.y"
                                   { yyerror("int value expected"); }
#line 6548 "core/cfg.tab.c"
    break;

  case 204: /* assign_stm: PORT EQUAL NUMBER  */
#line 1030 "core/cfg.y"
                              { port_no=(yyvsp[0].intval); }
#line 6554 "core/cfg.tab.c"
    break;

  case 205: /* assign_stm: PORT EQUAL error  */
#line 1031 "core/cfg.y"
                              { yyerror("number expected"); }
#line 6560 "core/cfg.tab.c"
    break;

  case 206: /* assign_stm: MAXBUFFER EQUAL NUMBER  */
#line 1032 "core/cfg.y"
                                 { maxbuffer=(yyvsp[0].intval); }
#line 6566 "core/cfg.tab.c"
    break;

  case 207: /* assign_stm: MAXBUFFER EQUAL error  */
#line 1033 "core/cfg.y"
                                { yyerror("number expected"); }
#line 6572 "core/cfg.tab.c"
    break;

  case 208: /* assign_stm: MAXSNDBUFFER EQUAL NUMBER  */
#line 1034 "core/cfg.y"
                                    { maxsndbuffer=(yyvsp[0].intval); }
#line 6578 "core/cfg.tab.c"
    break;

  case 209: /* assign_stm: MAXSNDBUFFER EQUAL error  */
#line 1035 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 6584 "core/cfg.tab.c"
    break;

  case 210: /* assign_stm: SQL_BUFFER_SIZE EQUAL NUMBER  */
#line 1036 "core/cfg.y"
                                       { sql_buffer_size=(yyvsp[0].intval); }
#line 6590 "core/cfg.tab.c"
    break;

  case 211: /* assign_stm: SQL_BUFFER_SIZE EQUAL error  */
#line 1037 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 6596 "core/cfg.tab.c"
    break;

  case 212: /* assign_stm: MSG_RECV_MAX_SIZE EQUAL NUMBER  */
#line 1038 "core/cfg.y"
                                         { ksr_msg_recv_max_size=(yyvsp[0].intval); }
#line 6602 "core/cfg.tab.c"
    break;

  case 213: /* assign_stm: MSG_RECV_MAX_SIZE EQUAL error  */
#line 1039 "core/cfg.y"
                                        { yyerror("number expected"); }
#line 6608 "core/cfg.tab.c"
    break;

  case 214: /* assign_stm: TCP_MSG_READ_TIMEOUT EQUAL NUMBER  */
#line 1040 "core/cfg.y"
                                            { ksr_tcp_msg_read_timeout=(yyvsp[0].intval); }
#line 6614 "core/cfg.tab.c"
    break;

  case 215: /* assign_stm: TCP_MSG_READ_TIMEOUT EQUAL error  */
#line 1041 "core/cfg.y"
                                           { yyerror("number expected"); }
#line 6620 "core/cfg.tab.c"
    break;

  case 216: /* assign_stm: TCP_MSG_DATA_TIMEOUT EQUAL NUMBER  */
#line 1042 "core/cfg.y"
                                            { ksr_tcp_msg_data_timeout=(yyvsp[0].intval); }
#line 6626 "core/cfg.tab.c"
    break;

  case 217: /* assign_stm: TCP_MSG_DATA_TIMEOUT EQUAL error  */
#line 1043 "core/cfg.y"
                                           { yyerror("number expected"); }
#line 6632 "core/cfg.tab.c"
    break;

  case 218: /* assign_stm: TCP_ACCEPT_IPLIMIT EQUAL NUMBER  */
#line 1044 "core/cfg.y"
                                          { ksr_tcp_accept_iplimit=(yyvsp[0].intval); }
#line 6638 "core/cfg.tab.c"
    break;

  case 219: /* assign_stm: TCP_ACCEPT_IPLIMIT EQUAL error  */
#line 1045 "core/cfg.y"
                                         { yyerror("number expected"); }
#line 6644 "core/cfg.tab.c"
    break;

  case 220: /* assign_stm: TCP_CHECK_TIMER EQUAL NUMBER  */
#line 1046 "core/cfg.y"
                                       { ksr_tcp_check_timer=(yyvsp[0].intval); }
#line 6650 "core/cfg.tab.c"
    break;

  case 221: /* assign_stm: TCP_CHECK_TIMER EQUAL error  */
#line 1047 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 6656 "core/cfg.tab.c"
    break;

  case 222: /* assign_stm: CHILDREN EQUAL NUMBER  */
#line 1048 "core/cfg.y"
                                { children_no=(yyvsp[0].intval); }
#line 6662 "core/cfg.tab.c"
    break;

  case 223: /* assign_stm: CHILDREN EQUAL error  */
#line 1049 "core/cfg.y"
                               { yyerror("number expected"); }
#line 6668 "core/cfg.tab.c"
    break;

  case 224: /* assign_stm: STATS_NAMESEP EQUAL STRING  */
#line 1050 "core/cfg.y"
                                     { ksr_stats_namesep=(yyvsp[0].strval); }
#line 6674 "core/cfg.tab.c"
    break;

  case 225: /* assign_stm: STATS_NAMESEP EQUAL error  */
#line 1051 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 6680 "core/cfg.tab.c"
    break;

  case 226: /* $@6: %empty  */
#line 1052 "core/cfg.y"
                 {
				memset(&tmp_sa, 0, sizeof(socket_attrs_t));
			}
#line 6688 "core/cfg.tab.c"
    break;

  case 227: /* assign_stm: SOCKET $@6 EQUAL LBRACE socket_lattrs RBRACE  */
#line 1054 "core/cfg.y"
                                                            {
				if(add_listen_socket(&tmp_sa)<0) {
					LM_ERR("failed to add listen socket\n");
					yyerror("failed to add listen socket");
					ksr_exit(-1);
				}
	}
#line 6700 "core/cfg.tab.c"
    break;

  case 228: /* assign_stm: SOCKET_WORKERS EQUAL NUMBER  */
#line 1061 "core/cfg.y"
                                      { socket_workers=(yyvsp[0].intval); }
#line 6706 "core/cfg.tab.c"
    break;

  case 229: /* assign_stm: SOCKET_WORKERS EQUAL error  */
#line 1062 "core/cfg.y"
                                     { yyerror("number expected"); }
#line 6712 "core/cfg.tab.c"
    break;

  case 230: /* assign_stm: ASYNC_WORKERS EQUAL NUMBER  */
#line 1063 "core/cfg.y"
                                     { async_task_set_workers((yyvsp[0].intval)); }
#line 6718 "core/cfg.tab.c"
    break;

  case 231: /* assign_stm: ASYNC_WORKERS EQUAL error  */
#line 1064 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 6724 "core/cfg.tab.c"
    break;

  case 232: /* assign_stm: ASYNC_USLEEP EQUAL NUMBER  */
#line 1065 "core/cfg.y"
                                    { async_task_set_usleep((yyvsp[0].intval)); }
#line 6730 "core/cfg.tab.c"
    break;

  case 233: /* assign_stm: ASYNC_USLEEP EQUAL error  */
#line 1066 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 6736 "core/cfg.tab.c"
    break;

  case 234: /* assign_stm: ASYNC_NONBLOCK EQUAL NUMBER  */
#line 1067 "core/cfg.y"
                                      { async_task_set_nonblock((yyvsp[0].intval)); }
#line 6742 "core/cfg.tab.c"
    break;

  case 235: /* assign_stm: ASYNC_NONBLOCK EQUAL error  */
#line 1068 "core/cfg.y"
                                     { yyerror("number expected"); }
#line 6748 "core/cfg.tab.c"
    break;

  case 236: /* assign_stm: ASYNC_WORKERS_GROUP EQUAL STRING  */
#line 1069 "core/cfg.y"
                                           { async_task_set_workers_group((yyvsp[0].strval)); }
#line 6754 "core/cfg.tab.c"
    break;

  case 237: /* assign_stm: ASYNC_WORKERS_GROUP EQUAL error  */
#line 1070 "core/cfg.y"
                                          { yyerror("string expected"); }
#line 6760 "core/cfg.tab.c"
    break;

  case 238: /* assign_stm: CHECK_VIA EQUAL NUMBER  */
#line 1071 "core/cfg.y"
                                 { check_via=(yyvsp[0].intval); }
#line 6766 "core/cfg.tab.c"
    break;

  case 239: /* assign_stm: CHECK_VIA EQUAL error  */
#line 1072 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 6772 "core/cfg.tab.c"
    break;

  case 240: /* assign_stm: PHONE2TEL EQUAL NUMBER  */
#line 1073 "core/cfg.y"
                                 { phone2tel=(yyvsp[0].intval); }
#line 6778 "core/cfg.tab.c"
    break;

  case 241: /* assign_stm: PHONE2TEL EQUAL error  */
#line 1074 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 6784 "core/cfg.tab.c"
    break;

  case 242: /* assign_stm: MEMLOG EQUAL intno  */
#line 1075 "core/cfg.y"
                             { default_core_cfg.memlog=(yyvsp[0].intval); }
#line 6790 "core/cfg.tab.c"
    break;

  case 243: /* assign_stm: MEMLOG EQUAL error  */
#line 1076 "core/cfg.y"
                             { yyerror("int value expected"); }
#line 6796 "core/cfg.tab.c"
    break;

  case 244: /* assign_stm: MEMDBG EQUAL intno  */
#line 1077 "core/cfg.y"
                             { default_core_cfg.memdbg=(yyvsp[0].intval); }
#line 6802 "core/cfg.tab.c"
    break;

  case 245: /* assign_stm: MEMDBG EQUAL error  */
#line 1078 "core/cfg.y"
                             { yyerror("int value expected"); }
#line 6808 "core/cfg.tab.c"
    break;

  case 246: /* assign_stm: MEMSUM EQUAL intno  */
#line 1079 "core/cfg.y"
                             { default_core_cfg.mem_summary=(yyvsp[0].intval); }
#line 6814 "core/cfg.tab.c"
    break;

  case 247: /* assign_stm: MEMSUM EQUAL error  */
#line 1080 "core/cfg.y"
                             { yyerror("int value expected"); }
#line 6820 "core/cfg.tab.c"
    break;

  case 248: /* assign_stm: MEMSAFETY EQUAL intno  */
#line 1081 "core/cfg.y"
                                { default_core_cfg.mem_safety=(yyvsp[0].intval); }
#line 6826 "core/cfg.tab.c"
    break;

  case 249: /* assign_stm: MEMSAFETY EQUAL error  */
#line 1082 "core/cfg.y"
                                { yyerror("int value expected"); }
#line 6832 "core/cfg.tab.c"
    break;

  case 250: /* assign_stm: MEMADDSIZE EQUAL intno  */
#line 1083 "core/cfg.y"
                                 { ksr_mem_add_size=(yyvsp[0].intval); }
#line 6838 "core/cfg.tab.c"
    break;

  case 251: /* assign_stm: MEMADDSIZE EQUAL error  */
#line 1084 "core/cfg.y"
                                 { yyerror("int value expected"); }
#line 6844 "core/cfg.tab.c"
    break;

  case 252: /* assign_stm: MEMJOIN EQUAL intno  */
#line 1085 "core/cfg.y"
                              { default_core_cfg.mem_join=(yyvsp[0].intval); }
#line 6850 "core/cfg.tab.c"
    break;

  case 253: /* assign_stm: MEMJOIN EQUAL error  */
#line 1086 "core/cfg.y"
                              { yyerror("int value expected"); }
#line 6856 "core/cfg.tab.c"
    break;

  case 254: /* assign_stm: MEMSTATUSMODE EQUAL intno  */
#line 1087 "core/cfg.y"
                                    { default_core_cfg.mem_status_mode=(yyvsp[0].intval); }
#line 6862 "core/cfg.tab.c"
    break;

  case 255: /* assign_stm: MEMSTATUSMODE EQUAL error  */
#line 1088 "core/cfg.y"
                                    { yyerror("int value expected"); }
#line 6868 "core/cfg.tab.c"
    break;

  case 256: /* assign_stm: SIP_PARSER_LOG_ONELINE EQUAL intno  */
#line 1089 "core/cfg.y"
                                             { default_core_cfg.sip_parser_log_oneline=(yyvsp[0].intval); }
#line 6874 "core/cfg.tab.c"
    break;

  case 257: /* assign_stm: SIP_PARSER_LOG_ONELINE EQUAL error  */
#line 1090 "core/cfg.y"
                                             { yyerror("int value expected"); }
#line 6880 "core/cfg.tab.c"
    break;

  case 258: /* assign_stm: SIP_PARSER_LOG EQUAL intno  */
#line 1091 "core/cfg.y"
                                     { default_core_cfg.sip_parser_log=(yyvsp[0].intval); }
#line 6886 "core/cfg.tab.c"
    break;

  case 259: /* assign_stm: SIP_PARSER_LOG EQUAL error  */
#line 1092 "core/cfg.y"
                                     { yyerror("int value expected"); }
#line 6892 "core/cfg.tab.c"
    break;

  case 260: /* assign_stm: SIP_PARSER_MODE EQUAL intno  */
#line 1093 "core/cfg.y"
                                      { ksr_sip_parser_mode=(yyvsp[0].intval); }
#line 6898 "core/cfg.tab.c"
    break;

  case 261: /* assign_stm: SIP_PARSER_MODE EQUAL error  */
#line 1094 "core/cfg.y"
                                      { yyerror("int value expected"); }
#line 6904 "core/cfg.tab.c"
    break;

  case 262: /* assign_stm: CORELOG EQUAL intno  */
#line 1095 "core/cfg.y"
                              { default_core_cfg.corelog=(yyvsp[0].intval); }
#line 6910 "core/cfg.tab.c"
    break;

  case 263: /* assign_stm: CORELOG EQUAL error  */
#line 1096 "core/cfg.y"
                              { yyerror("int value expected"); }
#line 6916 "core/cfg.tab.c"
    break;

  case 264: /* assign_stm: SIP_WARNING EQUAL NUMBER  */
#line 1097 "core/cfg.y"
                                   { sip_warning=(yyvsp[0].intval); }
#line 6922 "core/cfg.tab.c"
    break;

  case 265: /* assign_stm: SIP_WARNING EQUAL error  */
#line 1098 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 6928 "core/cfg.tab.c"
    break;

  case 266: /* assign_stm: VERSION_TABLE_CFG EQUAL STRING  */
#line 1099 "core/cfg.y"
                                         { version_table.s=(yyvsp[0].strval);
			version_table.len=strlen(version_table.s);
	}
#line 6936 "core/cfg.tab.c"
    break;

  case 267: /* assign_stm: VERSION_TABLE_CFG EQUAL error  */
#line 1102 "core/cfg.y"
                                        { yyerror("string value expected"); }
#line 6942 "core/cfg.tab.c"
    break;

  case 268: /* assign_stm: USER EQUAL STRING  */
#line 1103 "core/cfg.y"
                                {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6954 "core/cfg.tab.c"
    break;

  case 269: /* assign_stm: USER EQUAL ID  */
#line 1110 "core/cfg.y"
                                {
		if (shm_initialized())
			yyerror("user must be before any modparam or the"
					" route blocks");
		else if (user==0)
			user=(yyvsp[0].strval);
	}
#line 6966 "core/cfg.tab.c"
    break;

  case 270: /* assign_stm: USER EQUAL error  */
#line 1117 "core/cfg.y"
                                { yyerror("string value expected"); }
#line 6972 "core/cfg.tab.c"
    break;

  case 271: /* assign_stm: GROUP EQUAL STRING  */
#line 1118 "core/cfg.y"
                                 { group=(yyvsp[0].strval); }
#line 6978 "core/cfg.tab.c"
    break;

  case 272: /* assign_stm: GROUP EQUAL ID  */
#line 1119 "core/cfg.y"
                                 { group=(yyvsp[0].strval); }
#line 6984 "core/cfg.tab.c"
    break;

  case 273: /* assign_stm: GROUP EQUAL error  */
#line 1120 "core/cfg.y"
                                 { yyerror("string value expected"); }
#line 6990 "core/cfg.tab.c"
    break;

  case 274: /* assign_stm: CHROOT EQUAL STRING  */
#line 1121 "core/cfg.y"
                                  { chroot_dir=(yyvsp[0].strval); }
#line 6996 "core/cfg.tab.c"
    break;

  case 275: /* assign_stm: CHROOT EQUAL ID  */
#line 1122 "core/cfg.y"
                                  { chroot_dir=(yyvsp[0].strval); }
#line 7002 "core/cfg.tab.c"
    break;

  case 276: /* assign_stm: CHROOT EQUAL error  */
#line 1123 "core/cfg.y"
                                  { yyerror("string value expected"); }
#line 7008 "core/cfg.tab.c"
    break;

  case 277: /* assign_stm: WDIR EQUAL STRING  */
#line 1124 "core/cfg.y"
                                { working_dir=(yyvsp[0].strval); }
#line 7014 "core/cfg.tab.c"
    break;

  case 278: /* assign_stm: WDIR EQUAL ID  */
#line 1125 "core/cfg.y"
                                { working_dir=(yyvsp[0].strval); }
#line 7020 "core/cfg.tab.c"
    break;

  case 279: /* assign_stm: WDIR EQUAL error  */
#line 1126 "core/cfg.y"
                                { yyerror("string value expected"); }
#line 7026 "core/cfg.tab.c"
    break;

  case 280: /* assign_stm: RUNDIR EQUAL STRING  */
#line 1127 "core/cfg.y"
                                  { runtime_dir=(yyvsp[0].strval); }
#line 7032 "core/cfg.tab.c"
    break;

  case 281: /* assign_stm: RUNDIR EQUAL ID  */
#line 1128 "core/cfg.y"
                                  { runtime_dir=(yyvsp[0].strval); }
#line 7038 "core/cfg.tab.c"
    break;

  case 282: /* assign_stm: RUNDIR EQUAL error  */
#line 1129 "core/cfg.y"
                                  { yyerror("string value expected"); }
#line 7044 "core/cfg.tab.c"
    break;

  case 283: /* assign_stm: MHOMED EQUAL NUMBER  */
#line 1130 "core/cfg.y"
                              { mhomed=(yyvsp[0].intval); }
#line 7050 "core/cfg.tab.c"
    break;

  case 284: /* assign_stm: MHOMED EQUAL error  */
#line 1131 "core/cfg.y"
                             { yyerror("boolean value expected"); }
#line 7056 "core/cfg.tab.c"
    break;

  case 285: /* assign_stm: DISABLE_TCP EQUAL NUMBER  */
#line 1132 "core/cfg.y"
                                   {
		#ifdef USE_TCP
			tcp_disable=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7068 "core/cfg.tab.c"
    break;

  case 286: /* assign_stm: DISABLE_TCP EQUAL error  */
#line 1139 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 7074 "core/cfg.tab.c"
    break;

  case 287: /* assign_stm: TCP_ACCEPT_ALIASES EQUAL NUMBER  */
#line 1140 "core/cfg.y"
                                          {
		#ifdef USE_TCP
			tcp_default_cfg.accept_aliases=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7086 "core/cfg.tab.c"
    break;

  case 288: /* assign_stm: TCP_ACCEPT_ALIASES EQUAL error  */
#line 1147 "core/cfg.y"
                                         { yyerror("boolean value expected"); }
#line 7092 "core/cfg.tab.c"
    break;

  case 289: /* assign_stm: TCP_ACCEPT_UNIQUE EQUAL NUMBER  */
#line 1148 "core/cfg.y"
                                         {
		#ifdef USE_TCP
			tcp_accept_unique=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7104 "core/cfg.tab.c"
    break;

  case 290: /* assign_stm: TCP_ACCEPT_UNIQUE EQUAL error  */
#line 1155 "core/cfg.y"
                                        { yyerror("number expected"); }
#line 7110 "core/cfg.tab.c"
    break;

  case 291: /* assign_stm: TCP_CONNECTION_MATCH EQUAL NUMBER  */
#line 1156 "core/cfg.y"
                                            {
		#ifdef USE_TCP
			tcp_connection_match=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7122 "core/cfg.tab.c"
    break;

  case 292: /* assign_stm: TCP_CONNECTION_MATCH EQUAL error  */
#line 1163 "core/cfg.y"
                                           { yyerror("number expected"); }
#line 7128 "core/cfg.tab.c"
    break;

  case 293: /* assign_stm: TCP_CHILDREN EQUAL NUMBER  */
#line 1164 "core/cfg.y"
                                    {
		#ifdef USE_TCP
			tcp_cfg_children_no=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7140 "core/cfg.tab.c"
    break;

  case 294: /* assign_stm: TCP_CHILDREN EQUAL error  */
#line 1171 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 7146 "core/cfg.tab.c"
    break;

  case 295: /* assign_stm: TCP_CONNECT_TIMEOUT EQUAL intno  */
#line 1172 "core/cfg.y"
                                          {
		#ifdef USE_TCP
			tcp_default_cfg.connect_timeout_s=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7158 "core/cfg.tab.c"
    break;

  case 296: /* assign_stm: TCP_CONNECT_TIMEOUT EQUAL error  */
#line 1179 "core/cfg.y"
                                          { yyerror("number expected"); }
#line 7164 "core/cfg.tab.c"
    break;

  case 297: /* assign_stm: TCP_SEND_TIMEOUT EQUAL intno  */
#line 1180 "core/cfg.y"
                                       {
		#ifdef USE_TCP
			tcp_default_cfg.send_timeout=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7176 "core/cfg.tab.c"
    break;

  case 298: /* assign_stm: TCP_SEND_TIMEOUT EQUAL error  */
#line 1187 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 7182 "core/cfg.tab.c"
    break;

  case 299: /* assign_stm: TCP_CON_LIFETIME EQUAL intno  */
#line 1188 "core/cfg.y"
                                       {
		#ifdef USE_TCP
			if ((yyvsp[0].intval)<0)
				tcp_default_cfg.con_lifetime=-1;
			else
				tcp_default_cfg.con_lifetime=S_TO_TICKS((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7197 "core/cfg.tab.c"
    break;

  case 300: /* assign_stm: TCP_CON_LIFETIME EQUAL error  */
#line 1198 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 7203 "core/cfg.tab.c"
    break;

  case 301: /* assign_stm: TCP_POLL_METHOD EQUAL ID  */
#line 1199 "core/cfg.y"
                                   {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7222 "core/cfg.tab.c"
    break;

  case 302: /* assign_stm: TCP_POLL_METHOD EQUAL STRING  */
#line 1213 "core/cfg.y"
                                       {
		#ifdef USE_TCP
			tcp_poll_method=get_poll_type((yyvsp[0].strval));
			if (tcp_poll_method==POLL_NONE) {
				LOG(L_CRIT, "bad poll method name:"
						" %s\n, try one of %s.\n",
						(yyvsp[0].strval), poll_support);
				yyerror("bad tcp_poll_method "
						"value");
			}
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7241 "core/cfg.tab.c"
    break;

  case 303: /* assign_stm: TCP_POLL_METHOD EQUAL error  */
#line 1227 "core/cfg.y"
                                      { yyerror("poll method name expected"); }
#line 7247 "core/cfg.tab.c"
    break;

  case 304: /* assign_stm: TCP_MAX_CONNECTIONS EQUAL NUMBER  */
#line 1228 "core/cfg.y"
                                           {
		#ifdef USE_TCP
			tcp_max_connections=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7259 "core/cfg.tab.c"
    break;

  case 305: /* assign_stm: TCP_MAX_CONNECTIONS EQUAL error  */
#line 1235 "core/cfg.y"
                                          { yyerror("number expected"); }
#line 7265 "core/cfg.tab.c"
    break;

  case 306: /* assign_stm: TLS_MAX_CONNECTIONS EQUAL NUMBER  */
#line 1236 "core/cfg.y"
                                           {
		#ifdef USE_TLS
			tls_max_connections=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7277 "core/cfg.tab.c"
    break;

  case 307: /* assign_stm: TLS_MAX_CONNECTIONS EQUAL error  */
#line 1243 "core/cfg.y"
                                          { yyerror("number expected"); }
#line 7283 "core/cfg.tab.c"
    break;

  case 308: /* assign_stm: TCP_NO_CONNECT EQUAL NUMBER  */
#line 1244 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			tcp_default_cfg.no_connect=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7295 "core/cfg.tab.c"
    break;

  case 309: /* assign_stm: TCP_NO_CONNECT EQUAL error  */
#line 1251 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 7301 "core/cfg.tab.c"
    break;

  case 310: /* assign_stm: TCP_SOURCE_IPV4 EQUAL ipv4  */
#line 1252 "core/cfg.y"
                                     {
		#ifdef USE_TCP
			if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
				warn("tcp_source_ipv4 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 7315 "core/cfg.tab.c"
    break;

  case 311: /* assign_stm: TCP_SOURCE_IPV4 EQUAL error  */
#line 1261 "core/cfg.y"
                                      { yyerror("IPv4 address expected"); }
#line 7321 "core/cfg.tab.c"
    break;

  case 312: /* assign_stm: TCP_SOURCE_IPV6 EQUAL ipv6  */
#line 1262 "core/cfg.y"
                                     {
		#ifdef USE_TCP
				if (tcp_set_src_addr((yyvsp[0].ipaddr))<0)
					warn("tcp_source_ipv6 failed");
		#else
			warn("tcp support not compiled in");
		#endif
		pkg_free((yyvsp[0].ipaddr));
	}
#line 7335 "core/cfg.tab.c"
    break;

  case 313: /* assign_stm: TCP_SOURCE_IPV6 EQUAL error  */
#line 1271 "core/cfg.y"
                                      { yyerror("IPv6 address expected"); }
#line 7341 "core/cfg.tab.c"
    break;

  case 314: /* assign_stm: TCP_OPT_FD_CACHE EQUAL NUMBER  */
#line 1272 "core/cfg.y"
                                        {
		#ifdef USE_TCP
			tcp_default_cfg.fd_cache=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7353 "core/cfg.tab.c"
    break;

  case 315: /* assign_stm: TCP_OPT_FD_CACHE EQUAL error  */
#line 1279 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 7359 "core/cfg.tab.c"
    break;

  case 316: /* assign_stm: TCP_OPT_BUF_WRITE EQUAL NUMBER  */
#line 1280 "core/cfg.y"
                                         {
		#ifdef USE_TCP
			tcp_default_cfg.async=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7371 "core/cfg.tab.c"
    break;

  case 317: /* assign_stm: TCP_OPT_BUF_WRITE EQUAL error  */
#line 1287 "core/cfg.y"
                                        { yyerror("boolean value expected"); }
#line 7377 "core/cfg.tab.c"
    break;

  case 318: /* assign_stm: TCP_OPT_CONN_WQ_MAX EQUAL NUMBER  */
#line 1288 "core/cfg.y"
                                           {
		#ifdef USE_TCP
			tcp_default_cfg.tcpconn_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7389 "core/cfg.tab.c"
    break;

  case 319: /* assign_stm: TCP_OPT_CONN_WQ_MAX error  */
#line 1295 "core/cfg.y"
                                    { yyerror("boolean value expected"); }
#line 7395 "core/cfg.tab.c"
    break;

  case 320: /* assign_stm: TCP_OPT_WQ_MAX EQUAL NUMBER  */
#line 1296 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			tcp_default_cfg.tcp_wq_max=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7407 "core/cfg.tab.c"
    break;

  case 321: /* assign_stm: TCP_OPT_WQ_MAX error  */
#line 1303 "core/cfg.y"
                               { yyerror("number expected"); }
#line 7413 "core/cfg.tab.c"
    break;

  case 322: /* assign_stm: TCP_OPT_RD_BUF EQUAL NUMBER  */
#line 1304 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			tcp_default_cfg.rd_buf_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7425 "core/cfg.tab.c"
    break;

  case 323: /* assign_stm: TCP_OPT_RD_BUF error  */
#line 1311 "core/cfg.y"
                               { yyerror("number expected"); }
#line 7431 "core/cfg.tab.c"
    break;

  case 324: /* assign_stm: TCP_OPT_WQ_BLK EQUAL NUMBER  */
#line 1312 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			tcp_default_cfg.wq_blk_size=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7443 "core/cfg.tab.c"
    break;

  case 325: /* assign_stm: TCP_OPT_WQ_BLK error  */
#line 1319 "core/cfg.y"
                               { yyerror("number expected"); }
#line 7449 "core/cfg.tab.c"
    break;

  case 326: /* assign_stm: TCP_OPT_DEFER_ACCEPT EQUAL NUMBER  */
#line 1320 "core/cfg.y"
                                            {
		#ifdef USE_TCP
			tcp_default_cfg.defer_accept=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7461 "core/cfg.tab.c"
    break;

  case 327: /* assign_stm: TCP_OPT_DEFER_ACCEPT EQUAL error  */
#line 1327 "core/cfg.y"
                                           { yyerror("boolean value expected"); }
#line 7467 "core/cfg.tab.c"
    break;

  case 328: /* assign_stm: TCP_OPT_DELAYED_ACK EQUAL NUMBER  */
#line 1328 "core/cfg.y"
                                           {
		#ifdef USE_TCP
			tcp_default_cfg.delayed_ack=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7479 "core/cfg.tab.c"
    break;

  case 329: /* assign_stm: TCP_OPT_DELAYED_ACK EQUAL error  */
#line 1335 "core/cfg.y"
                                          { yyerror("boolean value expected"); }
#line 7485 "core/cfg.tab.c"
    break;

  case 330: /* assign_stm: TCP_OPT_SYNCNT EQUAL NUMBER  */
#line 1336 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			tcp_default_cfg.syncnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7497 "core/cfg.tab.c"
    break;

  case 331: /* assign_stm: TCP_OPT_SYNCNT EQUAL error  */
#line 1343 "core/cfg.y"
                                     { yyerror("number expected"); }
#line 7503 "core/cfg.tab.c"
    break;

  case 332: /* assign_stm: TCP_OPT_LINGER2 EQUAL NUMBER  */
#line 1344 "core/cfg.y"
                                       {
		#ifdef USE_TCP
			tcp_default_cfg.linger2=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7515 "core/cfg.tab.c"
    break;

  case 333: /* assign_stm: TCP_OPT_LINGER2 EQUAL error  */
#line 1351 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 7521 "core/cfg.tab.c"
    break;

  case 334: /* assign_stm: TCP_OPT_KEEPALIVE EQUAL NUMBER  */
#line 1352 "core/cfg.y"
                                         {
		#ifdef USE_TCP
			tcp_default_cfg.keepalive=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7533 "core/cfg.tab.c"
    break;

  case 335: /* assign_stm: TCP_OPT_KEEPALIVE EQUAL error  */
#line 1359 "core/cfg.y"
                                        { yyerror("boolean value expected");}
#line 7539 "core/cfg.tab.c"
    break;

  case 336: /* assign_stm: TCP_OPT_KEEPIDLE EQUAL NUMBER  */
#line 1360 "core/cfg.y"
                                        {
		#ifdef USE_TCP
			tcp_default_cfg.keepidle=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7551 "core/cfg.tab.c"
    break;

  case 337: /* assign_stm: TCP_OPT_KEEPIDLE EQUAL error  */
#line 1367 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 7557 "core/cfg.tab.c"
    break;

  case 338: /* assign_stm: TCP_OPT_KEEPINTVL EQUAL NUMBER  */
#line 1368 "core/cfg.y"
                                         {
		#ifdef USE_TCP
			tcp_default_cfg.keepintvl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7569 "core/cfg.tab.c"
    break;

  case 339: /* assign_stm: TCP_OPT_KEEPINTVL EQUAL error  */
#line 1375 "core/cfg.y"
                                        { yyerror("number expected"); }
#line 7575 "core/cfg.tab.c"
    break;

  case 340: /* assign_stm: TCP_OPT_KEEPCNT EQUAL NUMBER  */
#line 1376 "core/cfg.y"
                                       {
		#ifdef USE_TCP
			tcp_default_cfg.keepcnt=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7587 "core/cfg.tab.c"
    break;

  case 341: /* assign_stm: TCP_OPT_KEEPCNT EQUAL error  */
#line 1383 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 7593 "core/cfg.tab.c"
    break;

  case 342: /* assign_stm: TCP_OPT_CRLF_PING EQUAL NUMBER  */
#line 1384 "core/cfg.y"
                                         {
		#ifdef USE_TCP
			tcp_default_cfg.crlf_ping=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7605 "core/cfg.tab.c"
    break;

  case 343: /* assign_stm: TCP_OPT_CRLF_PING EQUAL error  */
#line 1391 "core/cfg.y"
                                        { yyerror("boolean value expected"); }
#line 7611 "core/cfg.tab.c"
    break;

  case 344: /* assign_stm: TCP_OPT_ACCEPT_NO_CL EQUAL NUMBER  */
#line 1392 "core/cfg.y"
                                            {
		#ifdef USE_TCP
			tcp_default_cfg.accept_no_cl=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7623 "core/cfg.tab.c"
    break;

  case 345: /* assign_stm: TCP_OPT_ACCEPT_NO_CL EQUAL error  */
#line 1399 "core/cfg.y"
                                           { yyerror("boolean value expected"); }
#line 7629 "core/cfg.tab.c"
    break;

  case 346: /* assign_stm: TCP_OPT_ACCEPT_HEP3 EQUAL NUMBER  */
#line 1400 "core/cfg.y"
                                           {
		#ifdef USE_TCP
			ksr_tcp_accept_hep3=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7641 "core/cfg.tab.c"
    break;

  case 347: /* assign_stm: TCP_OPT_ACCEPT_HEP3 EQUAL error  */
#line 1407 "core/cfg.y"
                                          { yyerror("boolean value expected"); }
#line 7647 "core/cfg.tab.c"
    break;

  case 348: /* assign_stm: TCP_OPT_ACCEPT_HAPROXY EQUAL NUMBER  */
#line 1408 "core/cfg.y"
                                              {
		#ifdef USE_TCP
			ksr_tcp_accept_haproxy=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7659 "core/cfg.tab.c"
    break;

  case 349: /* assign_stm: TCP_OPT_ACCEPT_HAPROXY EQUAL error  */
#line 1415 "core/cfg.y"
                                             { yyerror("boolean value expected"); }
#line 7665 "core/cfg.tab.c"
    break;

  case 350: /* assign_stm: TCP_OPT_CLOSE_RST EQUAL NUMBER  */
#line 1416 "core/cfg.y"
                                         {
         #ifdef USE_TCP
             tcp_default_cfg.close_rst=(yyvsp[0].intval);
         #else
             warn("tcp support not compiled in");
         #endif
     }
#line 7677 "core/cfg.tab.c"
    break;

  case 351: /* assign_stm: TCP_OPT_CLOSE_RST EQUAL error  */
#line 1423 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 7683 "core/cfg.tab.c"
    break;

  case 352: /* assign_stm: TCP_CLONE_RCVBUF EQUAL NUMBER  */
#line 1425 "core/cfg.y"
                                        {
		#ifdef USE_TCP
			tcp_set_clone_rcvbuf((yyvsp[0].intval));
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7695 "core/cfg.tab.c"
    break;

  case 353: /* assign_stm: TCP_CLONE_RCVBUF EQUAL error  */
#line 1432 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 7701 "core/cfg.tab.c"
    break;

  case 354: /* assign_stm: TCP_REUSE_PORT EQUAL NUMBER  */
#line 1433 "core/cfg.y"
                                      {
		#ifdef USE_TCP
		#ifdef SO_REUSEPORT
			tcp_default_cfg.reuse_port=(yyvsp[0].intval);
		#else
			warn("support for SO_REUSEPORT not compiled in");
		#endif
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7717 "core/cfg.tab.c"
    break;

  case 355: /* assign_stm: TCP_REUSE_PORT EQUAL error  */
#line 1444 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 7723 "core/cfg.tab.c"
    break;

  case 356: /* assign_stm: TCP_WAIT_DATA EQUAL intno  */
#line 1445 "core/cfg.y"
                                    {
		#ifdef USE_TCP
			tcp_default_cfg.wait_data_ms=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7735 "core/cfg.tab.c"
    break;

  case 357: /* assign_stm: TCP_WAIT_DATA EQUAL error  */
#line 1452 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 7741 "core/cfg.tab.c"
    break;

  case 358: /* assign_stm: TCP_SCRIPT_MODE EQUAL intno  */
#line 1453 "core/cfg.y"
                                      {
		#ifdef USE_TCP
			ksr_tcp_script_mode=(yyvsp[0].intval);
		#else
			warn("tcp support not compiled in");
		#endif
	}
#line 7753 "core/cfg.tab.c"
    break;

  case 359: /* assign_stm: TCP_SCRIPT_MODE EQUAL error  */
#line 1460 "core/cfg.y"
                                      { yyerror("number expected"); }
#line 7759 "core/cfg.tab.c"
    break;

  case 360: /* assign_stm: DISABLE_TLS EQUAL NUMBER  */
#line 1461 "core/cfg.y"
                                   {
		#ifdef USE_TLS
			tls_disable=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7771 "core/cfg.tab.c"
    break;

  case 361: /* assign_stm: DISABLE_TLS EQUAL error  */
#line 1468 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 7777 "core/cfg.tab.c"
    break;

  case 362: /* assign_stm: ENABLE_TLS EQUAL NUMBER  */
#line 1469 "core/cfg.y"
                                  {
		#ifdef USE_TLS
			tls_disable=!((yyvsp[0].intval));
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7789 "core/cfg.tab.c"
    break;

  case 363: /* assign_stm: ENABLE_TLS EQUAL error  */
#line 1476 "core/cfg.y"
                                 { yyerror("boolean value expected"); }
#line 7795 "core/cfg.tab.c"
    break;

  case 364: /* assign_stm: TLS_THREADS_MODE EQUAL NUMBER  */
#line 1477 "core/cfg.y"
                                        {
		#ifdef USE_TLS
			ksr_tls_threads_mode = (yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7807 "core/cfg.tab.c"
    break;

  case 365: /* assign_stm: TLS_THREADS_MODE EQUAL error  */
#line 1484 "core/cfg.y"
                                       { yyerror("int value expected"); }
#line 7813 "core/cfg.tab.c"
    break;

  case 366: /* assign_stm: TLSLOG EQUAL NUMBER  */
#line 1485 "core/cfg.y"
                              {
		#ifdef CORE_TLS
			tls_log=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7825 "core/cfg.tab.c"
    break;

  case 367: /* assign_stm: TLSLOG EQUAL error  */
#line 1492 "core/cfg.y"
                             { yyerror("int value expected"); }
#line 7831 "core/cfg.tab.c"
    break;

  case 368: /* assign_stm: TLS_PORT_NO EQUAL NUMBER  */
#line 1493 "core/cfg.y"
                                   {
		#ifdef USE_TLS
			tls_port_no=(yyvsp[0].intval);
		#else
			warn("tls support not compiled in");
		#endif
	}
#line 7843 "core/cfg.tab.c"
    break;

  case 369: /* assign_stm: TLS_PORT_NO EQUAL error  */
#line 1500 "core/cfg.y"
                                  { yyerror("number expected"); }
#line 7849 "core/cfg.tab.c"
    break;

  case 370: /* assign_stm: TLS_METHOD EQUAL SSLv23  */
#line 1501 "core/cfg.y"
                                  {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv23;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7861 "core/cfg.tab.c"
    break;

  case 371: /* assign_stm: TLS_METHOD EQUAL SSLv2  */
#line 1508 "core/cfg.y"
                                 {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv2;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7873 "core/cfg.tab.c"
    break;

  case 372: /* assign_stm: TLS_METHOD EQUAL SSLv3  */
#line 1515 "core/cfg.y"
                                 {
		#ifdef CORE_TLS
			tls_method=TLS_USE_SSLv3;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7885 "core/cfg.tab.c"
    break;

  case 373: /* assign_stm: TLS_METHOD EQUAL TLSv1  */
#line 1522 "core/cfg.y"
                                 {
		#ifdef CORE_TLS
			tls_method=TLS_USE_TLSv1;
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7897 "core/cfg.tab.c"
    break;

  case 374: /* assign_stm: TLS_METHOD EQUAL error  */
#line 1529 "core/cfg.y"
                                 {
		#ifdef CORE_TLS
			yyerror("SSLv23, SSLv2, SSLv3 or TLSv1 expected");
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7909 "core/cfg.tab.c"
    break;

  case 375: /* assign_stm: TLS_VERIFY EQUAL NUMBER  */
#line 1536 "core/cfg.y"
                                  {
		#ifdef CORE_TLS
			tls_verify_cert=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7921 "core/cfg.tab.c"
    break;

  case 376: /* assign_stm: TLS_VERIFY EQUAL error  */
#line 1543 "core/cfg.y"
                                 { yyerror("boolean value expected"); }
#line 7927 "core/cfg.tab.c"
    break;

  case 377: /* assign_stm: TLS_REQUIRE_CERTIFICATE EQUAL NUMBER  */
#line 1544 "core/cfg.y"
                                               {
		#ifdef CORE_TLS
			tls_require_cert=(yyvsp[0].intval);
		#else
			warn( "tls-in-core support not compiled in");
		#endif
	}
#line 7939 "core/cfg.tab.c"
    break;

  case 378: /* assign_stm: TLS_REQUIRE_CERTIFICATE EQUAL error  */
#line 1551 "core/cfg.y"
                                              { yyerror("boolean value expected"); }
#line 7945 "core/cfg.tab.c"
    break;

  case 379: /* assign_stm: TLS_CERTIFICATE EQUAL STRING  */
#line 1552 "core/cfg.y"
                                       {
		#ifdef CORE_TLS
			tls_cert_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7957 "core/cfg.tab.c"
    break;

  case 380: /* assign_stm: TLS_CERTIFICATE EQUAL error  */
#line 1559 "core/cfg.y"
                                      { yyerror("string value expected"); }
#line 7963 "core/cfg.tab.c"
    break;

  case 381: /* assign_stm: TLS_PRIVATE_KEY EQUAL STRING  */
#line 1560 "core/cfg.y"
                                       {
		#ifdef CORE_TLS
			tls_pkey_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7975 "core/cfg.tab.c"
    break;

  case 382: /* assign_stm: TLS_PRIVATE_KEY EQUAL error  */
#line 1567 "core/cfg.y"
                                      { yyerror("string value expected"); }
#line 7981 "core/cfg.tab.c"
    break;

  case 383: /* assign_stm: TLS_CA_LIST EQUAL STRING  */
#line 1568 "core/cfg.y"
                                   {
		#ifdef CORE_TLS
			tls_ca_file=(yyvsp[0].strval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 7993 "core/cfg.tab.c"
    break;

  case 384: /* assign_stm: TLS_CA_LIST EQUAL error  */
#line 1575 "core/cfg.y"
                                  { yyerror("string value expected"); }
#line 7999 "core/cfg.tab.c"
    break;

  case 385: /* assign_stm: TLS_HANDSHAKE_TIMEOUT EQUAL NUMBER  */
#line 1576 "core/cfg.y"
                                             {
		#ifdef CORE_TLS
			tls_handshake_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 8011 "core/cfg.tab.c"
    break;

  case 386: /* assign_stm: TLS_HANDSHAKE_TIMEOUT EQUAL error  */
#line 1583 "core/cfg.y"
                                            { yyerror("number expected"); }
#line 8017 "core/cfg.tab.c"
    break;

  case 387: /* assign_stm: TLS_SEND_TIMEOUT EQUAL NUMBER  */
#line 1584 "core/cfg.y"
                                        {
		#ifdef CORE_TLS
			tls_send_timeout=(yyvsp[0].intval);
		#else
			warn("tls-in-core support not compiled in");
		#endif
	}
#line 8029 "core/cfg.tab.c"
    break;

  case 388: /* assign_stm: TLS_SEND_TIMEOUT EQUAL error  */
#line 1591 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 8035 "core/cfg.tab.c"
    break;

  case 389: /* assign_stm: DISABLE_SCTP EQUAL NUMBER  */
#line 1592 "core/cfg.y"
                                    {
		#ifdef USE_SCTP
			sctp_disable=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 8047 "core/cfg.tab.c"
    break;

  case 390: /* assign_stm: DISABLE_SCTP EQUAL error  */
#line 1599 "core/cfg.y"
                                   { yyerror("boolean value expected"); }
#line 8053 "core/cfg.tab.c"
    break;

  case 391: /* assign_stm: ENABLE_SCTP EQUAL NUMBER  */
#line 1600 "core/cfg.y"
                                   {
		#ifdef USE_SCTP
			sctp_disable=((yyvsp[0].intval)<=1)?!(yyvsp[0].intval):(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 8065 "core/cfg.tab.c"
    break;

  case 392: /* assign_stm: ENABLE_SCTP EQUAL error  */
#line 1607 "core/cfg.y"
                                  { yyerror("boolean or number expected"); }
#line 8071 "core/cfg.tab.c"
    break;

  case 393: /* assign_stm: SCTP_CHILDREN EQUAL NUMBER  */
#line 1608 "core/cfg.y"
                                     {
		#ifdef USE_SCTP
			sctp_children_no=(yyvsp[0].intval);
		#else
			warn("sctp support not compiled in");
		#endif
	}
#line 8083 "core/cfg.tab.c"
    break;

  case 394: /* assign_stm: SCTP_CHILDREN EQUAL error  */
#line 1615 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 8089 "core/cfg.tab.c"
    break;

  case 395: /* assign_stm: SERVER_SIGNATURE EQUAL NUMBER  */
#line 1616 "core/cfg.y"
                                        { server_signature=(yyvsp[0].intval); }
#line 8095 "core/cfg.tab.c"
    break;

  case 396: /* assign_stm: SERVER_SIGNATURE EQUAL error  */
#line 1617 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8101 "core/cfg.tab.c"
    break;

  case 397: /* assign_stm: SERVER_HEADER EQUAL STRING  */
#line 1618 "core/cfg.y"
                                     { server_hdr.s=(yyvsp[0].strval);
			server_hdr.len=strlen(server_hdr.s);
	}
#line 8109 "core/cfg.tab.c"
    break;

  case 398: /* assign_stm: SERVER_HEADER EQUAL error  */
#line 1621 "core/cfg.y"
                                    { yyerror("string value expected"); }
#line 8115 "core/cfg.tab.c"
    break;

  case 399: /* assign_stm: USER_AGENT_HEADER EQUAL STRING  */
#line 1622 "core/cfg.y"
                                         { user_agent_hdr.s=(yyvsp[0].strval);
			user_agent_hdr.len=strlen(user_agent_hdr.s);
	}
#line 8123 "core/cfg.tab.c"
    break;

  case 400: /* assign_stm: USER_AGENT_HEADER EQUAL error  */
#line 1625 "core/cfg.y"
                                        { yyerror("string value expected"); }
#line 8129 "core/cfg.tab.c"
    break;

  case 401: /* assign_stm: URI_HOST_EXTRA_CHARS EQUAL STRING  */
#line 1626 "core/cfg.y"
                                            { _sr_uri_host_extra_chars=(yyvsp[0].strval); }
#line 8135 "core/cfg.tab.c"
    break;

  case 402: /* assign_stm: URI_HOST_EXTRA_CHARS EQUAL error  */
#line 1627 "core/cfg.y"
                                           { yyerror("string value expected"); }
#line 8141 "core/cfg.tab.c"
    break;

  case 403: /* assign_stm: HDR_NAME_EXTRA_CHARS EQUAL STRING  */
#line 1628 "core/cfg.y"
                                            { _ksr_hname_extra_chars=(unsigned char*)(yyvsp[0].strval); }
#line 8147 "core/cfg.tab.c"
    break;

  case 404: /* assign_stm: HDR_NAME_EXTRA_CHARS EQUAL error  */
#line 1629 "core/cfg.y"
                                           { yyerror("string value expected"); }
#line 8153 "core/cfg.tab.c"
    break;

  case 405: /* assign_stm: REPLY_TO_VIA EQUAL NUMBER  */
#line 1630 "core/cfg.y"
                                    { reply_to_via=(yyvsp[0].intval); }
#line 8159 "core/cfg.tab.c"
    break;

  case 406: /* assign_stm: REPLY_TO_VIA EQUAL error  */
#line 1631 "core/cfg.y"
                                   { yyerror("boolean value expected"); }
#line 8165 "core/cfg.tab.c"
    break;

  case 407: /* assign_stm: LISTEN EQUAL id_lst  */
#line 1632 "core/cfg.y"
                              {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 8182 "core/cfg.tab.c"
    break;

  case 408: /* assign_stm: LISTEN EQUAL id_lst VIRTUAL  */
#line 1644 "core/cfg.y"
                                      {
                for(lst_tmp=(yyvsp[-1].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_iface(   lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-1].sockid));
        }
#line 8200 "core/cfg.tab.c"
    break;

  case 409: /* assign_stm: LISTEN EQUAL id_lst STRNAME STRING  */
#line 1657 "core/cfg.y"
                                             {
		for(lst_tmp=(yyvsp[-2].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_iface_name(lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto, (yyvsp[0].strval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-2].sockid));
	}
#line 8217 "core/cfg.tab.c"
    break;

  case 410: /* assign_stm: LISTEN EQUAL id_lst STRNAME STRING VIRTUAL  */
#line 1669 "core/cfg.y"
                                                     {
                for(lst_tmp=(yyvsp[-3].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
                        lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_iface_name(lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto, (yyvsp[-1].strval),
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-3].sockid));
        }
#line 8235 "core/cfg.tab.c"
    break;

  case 411: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id COLON NUMBER  */
#line 1682 "core/cfg.y"
                                                               {
		for(lst_tmp=(yyvsp[-4].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									PROTO_NONE, (yyvsp[-2].strval), (yyvsp[0].intval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-4].sockid));
	}
#line 8253 "core/cfg.tab.c"
    break;

  case 412: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE xproto COLON listen_id COLON NUMBER  */
#line 1695 "core/cfg.y"
                                                                            {
		for(lst_tmp=(yyvsp[-6].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[-4].intval), (yyvsp[-2].strval), (yyvsp[0].intval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-6].sockid));
	}
#line 8271 "core/cfg.tab.c"
    break;

  case 413: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id COLON NUMBER VIRTUAL  */
#line 1708 "core/cfg.y"
                                                                       {
                for(lst_tmp=(yyvsp[-5].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_advertise_iface( lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        PROTO_NONE, (yyvsp[-3].strval), (yyvsp[-1].intval),
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-5].sockid));
        }
#line 8290 "core/cfg.tab.c"
    break;

  case 414: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id COLON NUMBER STRNAME STRING  */
#line 1722 "core/cfg.y"
                                                                              {
		for(lst_tmp=(yyvsp[-6].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									PROTO_NONE, (yyvsp[-4].strval), (yyvsp[-2].intval), (yyvsp[0].strval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-6].sockid));
	}
#line 8308 "core/cfg.tab.c"
    break;

  case 415: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE xproto COLON listen_id COLON NUMBER STRNAME STRING  */
#line 1735 "core/cfg.y"
                                                                                           {
		for(lst_tmp=(yyvsp[-8].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									(yyvsp[-6].intval), (yyvsp[-4].strval), (yyvsp[-2].intval), (yyvsp[0].strval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-8].sockid));
	}
#line 8326 "core/cfg.tab.c"
    break;

  case 416: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id COLON NUMBER STRNAME STRING VIRTUAL  */
#line 1748 "core/cfg.y"
                                                                                      {
                for(lst_tmp=(yyvsp[-7].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        PROTO_NONE, (yyvsp[-5].strval), (yyvsp[-3].intval), (yyvsp[-1].strval),
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-7].sockid));
        }
#line 8345 "core/cfg.tab.c"
    break;

  case 417: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE xproto COLON listen_id COLON NUMBER STRNAME STRING VIRTUAL  */
#line 1762 "core/cfg.y"
                                                                                                   {
                for(lst_tmp=(yyvsp[-9].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        (yyvsp[-7].intval), (yyvsp[-5].strval), (yyvsp[-3].intval), (yyvsp[-1].strval),
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-9].sockid));
        }
#line 8364 "core/cfg.tab.c"
    break;

  case 418: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id  */
#line 1776 "core/cfg.y"
                                                  {
		for(lst_tmp=(yyvsp[-2].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface(	lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									PROTO_NONE, (yyvsp[0].strval), 0,
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-2].sockid));
	}
#line 8382 "core/cfg.tab.c"
    break;

  case 419: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id VIRTUAL  */
#line 1789 "core/cfg.y"
                                                          {
                for(lst_tmp=(yyvsp[-3].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_advertise_iface( lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        PROTO_NONE, (yyvsp[-1].strval), 0,
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-3].sockid));
        }
#line 8401 "core/cfg.tab.c"
    break;

  case 420: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id STRNAME STRING  */
#line 1803 "core/cfg.y"
                                                                 {
		for(lst_tmp=(yyvsp[-4].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
									lst_tmp->addr_lst->next,
									lst_tmp->port, lst_tmp->proto,
									PROTO_NONE, (yyvsp[-2].strval), 0, (yyvsp[0].strval),
									lst_tmp->flags)!=0) {
				LM_CRIT("cfg. parser: failed to add listen address\n");
				break;
			}
		}
		free_socket_id_lst((yyvsp[-4].sockid));
	}
#line 8419 "core/cfg.tab.c"
    break;

  case 421: /* assign_stm: LISTEN EQUAL id_lst ADVERTISE listen_id STRNAME STRING VIRTUAL  */
#line 1816 "core/cfg.y"
                                                                         {
                for(lst_tmp=(yyvsp[-5].sockid); lst_tmp; lst_tmp=lst_tmp->next) {
			lst_tmp->flags |= SI_IS_VIRTUAL;
                        if (add_listen_advertise_iface_name(lst_tmp->addr_lst->name,
                                                                        lst_tmp->addr_lst->next,
                                                                        lst_tmp->port, lst_tmp->proto,
                                                                        PROTO_NONE, (yyvsp[-3].strval), 0, (yyvsp[-1].strval),
                                                                        lst_tmp->flags)!=0) {
                                LM_CRIT("cfg. parser: failed to add listen address\n");
                                break;
                        }
                }
                free_socket_id_lst((yyvsp[-5].sockid));
        }
#line 8438 "core/cfg.tab.c"
    break;

  case 422: /* assign_stm: LISTEN EQUAL error  */
#line 1830 "core/cfg.y"
                              { yyerror("ip address, interface name or"
									" hostname expected"); }
#line 8445 "core/cfg.tab.c"
    break;

  case 423: /* assign_stm: ALIAS EQUAL id_lst  */
#line 1832 "core/cfg.y"
                              {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next){
			add_alias(	lst_tmp->addr_lst->name,
						strlen(lst_tmp->addr_lst->name),
						lst_tmp->port, lst_tmp->proto);
			for (nl_tmp=lst_tmp->addr_lst->next; nl_tmp; nl_tmp=nl_tmp->next)
				add_alias(nl_tmp->name, strlen(nl_tmp->name),
							lst_tmp->port, lst_tmp->proto);
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 8461 "core/cfg.tab.c"
    break;

  case 424: /* assign_stm: ALIAS EQUAL error  */
#line 1843 "core/cfg.y"
                              { yyerror("hostname expected"); }
#line 8467 "core/cfg.tab.c"
    break;

  case 425: /* assign_stm: DOMAIN EQUAL id_lst  */
#line 1844 "core/cfg.y"
                               {
		for(lst_tmp=(yyvsp[0].sockid); lst_tmp; lst_tmp=lst_tmp->next){
			add_alias(	lst_tmp->addr_lst->name,
						strlen(lst_tmp->addr_lst->name),
						lst_tmp->port, lst_tmp->proto);
			for (nl_tmp=lst_tmp->addr_lst->next; nl_tmp; nl_tmp=nl_tmp->next)
				add_alias(nl_tmp->name, strlen(nl_tmp->name),
							lst_tmp->port, lst_tmp->proto);
		}
		free_socket_id_lst((yyvsp[0].sockid));
	}
#line 8483 "core/cfg.tab.c"
    break;

  case 426: /* assign_stm: DOMAIN EQUAL error  */
#line 1855 "core/cfg.y"
                               { yyerror("hostname expected"); }
#line 8489 "core/cfg.tab.c"
    break;

  case 427: /* assign_stm: SR_AUTO_ALIASES EQUAL NUMBER  */
#line 1856 "core/cfg.y"
                                       { sr_auto_aliases=(yyvsp[0].intval); }
#line 8495 "core/cfg.tab.c"
    break;

  case 428: /* assign_stm: SR_AUTO_ALIASES EQUAL error  */
#line 1857 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8501 "core/cfg.tab.c"
    break;

  case 429: /* assign_stm: SR_AUTO_DOMAINS EQUAL NUMBER  */
#line 1858 "core/cfg.y"
                                       { sr_auto_aliases=(yyvsp[0].intval); }
#line 8507 "core/cfg.tab.c"
    break;

  case 430: /* assign_stm: SR_AUTO_DOMAINS EQUAL error  */
#line 1859 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8513 "core/cfg.tab.c"
    break;

  case 431: /* assign_stm: ADVERTISED_ADDRESS EQUAL listen_id  */
#line 1860 "core/cfg.y"
                                             {
		if ((yyvsp[0].strval)){
			default_global_address.s=(yyvsp[0].strval);
			default_global_address.len=strlen((yyvsp[0].strval));
		}
	}
#line 8524 "core/cfg.tab.c"
    break;

  case 432: /* assign_stm: ADVERTISED_ADDRESS EQUAL error  */
#line 1866 "core/cfg.y"
                                         {yyerror("ip address or hostname expected"); }
#line 8530 "core/cfg.tab.c"
    break;

  case 433: /* assign_stm: ADVERTISED_PORT EQUAL NUMBER  */
#line 1867 "core/cfg.y"
                                       {
		tmp=int2str((yyvsp[0].intval), &i_tmp);
		if ((default_global_port.s=pkg_malloc(i_tmp))==0) {
			PKG_MEM_CRITICAL;
			default_global_port.len=0;
		} else {
			default_global_port.len=i_tmp;
			memcpy(default_global_port.s, tmp, default_global_port.len);
		};
	}
#line 8545 "core/cfg.tab.c"
    break;

  case 434: /* assign_stm: ADVERTISED_PORT EQUAL error  */
#line 1877 "core/cfg.y"
                                     {yyerror("ip address or hostname expected"); }
#line 8551 "core/cfg.tab.c"
    break;

  case 435: /* assign_stm: DISABLE_CORE EQUAL NUMBER  */
#line 1878 "core/cfg.y"
                                    { disable_core_dump=(yyvsp[0].intval); }
#line 8557 "core/cfg.tab.c"
    break;

  case 436: /* assign_stm: DISABLE_CORE EQUAL error  */
#line 1879 "core/cfg.y"
                                   { yyerror("boolean value expected"); }
#line 8563 "core/cfg.tab.c"
    break;

  case 437: /* assign_stm: OPEN_FD_LIMIT EQUAL NUMBER  */
#line 1880 "core/cfg.y"
                                     { open_files_limit=(yyvsp[0].intval); }
#line 8569 "core/cfg.tab.c"
    break;

  case 438: /* assign_stm: OPEN_FD_LIMIT EQUAL error  */
#line 1881 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 8575 "core/cfg.tab.c"
    break;

  case 439: /* assign_stm: SHM_MEM_SZ EQUAL NUMBER  */
#line 1882 "core/cfg.y"
                                  {
		if (shm_initialized()) {
			yyerror("shm/shm_mem_size must be before any modparam or the"
					" route blocks");
		} else if (shm_mem_size == 0 || shm_mem_size == SHM_MEM_POOL_SIZE) {
			/* safety check for upper limit of 16TB */
			if((yyvsp[0].intval) <= 0 || (yyvsp[0].intval) > 16L * 1024 * 1024) {
				LM_ERR("out of limits shmem size number: %ld\n", (long int)(yyvsp[0].intval));
				yyerror("invalid config option");
				YYABORT;
			}
			shm_mem_size=(yyvsp[0].intval) * 1024 * 1024;
		}
	}
#line 8594 "core/cfg.tab.c"
    break;

  case 440: /* assign_stm: SHM_MEM_SZ EQUAL error  */
#line 1896 "core/cfg.y"
                                 { yyerror("number expected"); }
#line 8600 "core/cfg.tab.c"
    break;

  case 441: /* assign_stm: SHM_FORCE_ALLOC EQUAL NUMBER  */
#line 1897 "core/cfg.y"
                                       {
		if (shm_initialized())
			yyerror("shm_force_alloc must be before any modparam or the"
					" route blocks");
		else
			shm_force_alloc=(yyvsp[0].intval);
	}
#line 8612 "core/cfg.tab.c"
    break;

  case 442: /* assign_stm: SHM_FORCE_ALLOC EQUAL error  */
#line 1904 "core/cfg.y"
                                      { yyerror("boolean value expected"); }
#line 8618 "core/cfg.tab.c"
    break;

  case 443: /* assign_stm: MLOCK_PAGES EQUAL NUMBER  */
#line 1905 "core/cfg.y"
                                   { mlock_pages=(yyvsp[0].intval); }
#line 8624 "core/cfg.tab.c"
    break;

  case 444: /* assign_stm: MLOCK_PAGES EQUAL error  */
#line 1906 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 8630 "core/cfg.tab.c"
    break;

  case 445: /* assign_stm: REAL_TIME EQUAL NUMBER  */
#line 1907 "core/cfg.y"
                                 { real_time=(yyvsp[0].intval); }
#line 8636 "core/cfg.tab.c"
    break;

  case 446: /* assign_stm: REAL_TIME EQUAL error  */
#line 1908 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 8642 "core/cfg.tab.c"
    break;

  case 447: /* assign_stm: RT_PRIO EQUAL NUMBER  */
#line 1909 "core/cfg.y"
                               { rt_prio=(yyvsp[0].intval); }
#line 8648 "core/cfg.tab.c"
    break;

  case 448: /* assign_stm: RT_PRIO EQUAL error  */
#line 1910 "core/cfg.y"
                              { yyerror("boolean value expected"); }
#line 8654 "core/cfg.tab.c"
    break;

  case 449: /* assign_stm: RT_POLICY EQUAL NUMBER  */
#line 1911 "core/cfg.y"
                                 { rt_policy=(yyvsp[0].intval); }
#line 8660 "core/cfg.tab.c"
    break;

  case 450: /* assign_stm: RT_POLICY EQUAL error  */
#line 1912 "core/cfg.y"
                                { yyerror("boolean value expected"); }
#line 8666 "core/cfg.tab.c"
    break;

  case 451: /* assign_stm: RT_TIMER1_PRIO EQUAL NUMBER  */
#line 1913 "core/cfg.y"
                                      { rt_timer1_prio=(yyvsp[0].intval); }
#line 8672 "core/cfg.tab.c"
    break;

  case 452: /* assign_stm: RT_TIMER1_PRIO EQUAL error  */
#line 1914 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 8678 "core/cfg.tab.c"
    break;

  case 453: /* assign_stm: RT_TIMER1_POLICY EQUAL NUMBER  */
#line 1915 "core/cfg.y"
                                        { rt_timer1_policy=(yyvsp[0].intval); }
#line 8684 "core/cfg.tab.c"
    break;

  case 454: /* assign_stm: RT_TIMER1_POLICY EQUAL error  */
#line 1916 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8690 "core/cfg.tab.c"
    break;

  case 455: /* assign_stm: RT_TIMER2_PRIO EQUAL NUMBER  */
#line 1917 "core/cfg.y"
                                      { rt_timer2_prio=(yyvsp[0].intval); }
#line 8696 "core/cfg.tab.c"
    break;

  case 456: /* assign_stm: RT_TIMER2_PRIO EQUAL error  */
#line 1918 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 8702 "core/cfg.tab.c"
    break;

  case 457: /* assign_stm: RT_TIMER2_POLICY EQUAL NUMBER  */
#line 1919 "core/cfg.y"
                                        { rt_timer2_policy=(yyvsp[0].intval); }
#line 8708 "core/cfg.tab.c"
    break;

  case 458: /* assign_stm: RT_TIMER2_POLICY EQUAL error  */
#line 1920 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8714 "core/cfg.tab.c"
    break;

  case 459: /* assign_stm: MCAST_LOOPBACK EQUAL NUMBER  */
#line 1921 "core/cfg.y"
                                      {
		#ifdef USE_MCAST
			mcast_loopback=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 8726 "core/cfg.tab.c"
    break;

  case 460: /* assign_stm: MCAST_LOOPBACK EQUAL error  */
#line 1928 "core/cfg.y"
                                     { yyerror("boolean value expected"); }
#line 8732 "core/cfg.tab.c"
    break;

  case 461: /* assign_stm: MCAST_TTL EQUAL NUMBER  */
#line 1929 "core/cfg.y"
                                 {
		#ifdef USE_MCAST
			mcast_ttl=(yyvsp[0].intval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 8744 "core/cfg.tab.c"
    break;

  case 462: /* assign_stm: MCAST_TTL EQUAL error  */
#line 1936 "core/cfg.y"
                                { yyerror("number expected"); }
#line 8750 "core/cfg.tab.c"
    break;

  case 463: /* assign_stm: MCAST EQUAL ID  */
#line 1937 "core/cfg.y"
                         {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 8762 "core/cfg.tab.c"
    break;

  case 464: /* assign_stm: MCAST EQUAL STRING  */
#line 1944 "core/cfg.y"
                             {
		#ifdef USE_MCAST
			mcast=(yyvsp[0].strval);
		#else
			warn("no multicast support compiled in");
		#endif
	}
#line 8774 "core/cfg.tab.c"
    break;

  case 465: /* assign_stm: MCAST EQUAL error  */
#line 1951 "core/cfg.y"
                            { yyerror("string expected"); }
#line 8780 "core/cfg.tab.c"
    break;

  case 466: /* assign_stm: TOS EQUAL NUMBER  */
#line 1952 "core/cfg.y"
                           { tos=(yyvsp[0].intval); }
#line 8786 "core/cfg.tab.c"
    break;

  case 467: /* assign_stm: TOS EQUAL ID  */
#line 1953 "core/cfg.y"
                       { if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWDELAY")) {
			tos=IPTOS_LOWDELAY;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_THROUGHPUT")) {
			tos=IPTOS_THROUGHPUT;
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_RELIABILITY")) {
			tos=IPTOS_RELIABILITY;
#if defined(IPTOS_MINCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_MINCOST")) {
			tos=IPTOS_MINCOST;
#endif
#if defined(IPTOS_LOWCOST)
		} else if (strcasecmp((yyvsp[0].strval),"IPTOS_LOWCOST")) {
			tos=IPTOS_LOWCOST;
#endif
		} else {
			yyerror("invalid tos value - allowed: "
				"IPTOS_LOWDELAY,IPTOS_THROUGHPUT,"
				"IPTOS_RELIABILITY"
#if defined(IPTOS_LOWCOST)
				",IPTOS_LOWCOST"
#endif
#if !defined(IPTOS_MINCOST)
				",IPTOS_MINCOST"
#endif
				"\n");
		}
	}
#line 8818 "core/cfg.tab.c"
    break;

  case 468: /* assign_stm: TOS EQUAL error  */
#line 1980 "core/cfg.y"
                          { yyerror("number expected"); }
#line 8824 "core/cfg.tab.c"
    break;

  case 469: /* assign_stm: PMTU_DISCOVERY EQUAL NUMBER  */
#line 1981 "core/cfg.y"
                                      { pmtu_discovery=(yyvsp[0].intval); }
#line 8830 "core/cfg.tab.c"
    break;

  case 470: /* assign_stm: PMTU_DISCOVERY error  */
#line 1982 "core/cfg.y"
                               { yyerror("number expected"); }
#line 8836 "core/cfg.tab.c"
    break;

  case 471: /* assign_stm: KILL_TIMEOUT EQUAL NUMBER  */
#line 1983 "core/cfg.y"
                                    { ser_kill_timeout=(yyvsp[0].intval); }
#line 8842 "core/cfg.tab.c"
    break;

  case 472: /* assign_stm: KILL_TIMEOUT EQUAL error  */
#line 1984 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 8848 "core/cfg.tab.c"
    break;

  case 473: /* assign_stm: MAX_WLOOPS EQUAL NUMBER  */
#line 1985 "core/cfg.y"
                                  { default_core_cfg.max_while_loops=(yyvsp[0].intval); }
#line 8854 "core/cfg.tab.c"
    break;

  case 474: /* assign_stm: MAX_WLOOPS EQUAL error  */
#line 1986 "core/cfg.y"
                                 { yyerror("number expected"); }
#line 8860 "core/cfg.tab.c"
    break;

  case 475: /* assign_stm: PVBUFSIZE EQUAL NUMBER  */
#line 1987 "core/cfg.y"
                                 { pv_set_buffer_size((yyvsp[0].intval)); }
#line 8866 "core/cfg.tab.c"
    break;

  case 476: /* assign_stm: PVBUFSIZE EQUAL error  */
#line 1988 "core/cfg.y"
                                { yyerror("number expected"); }
#line 8872 "core/cfg.tab.c"
    break;

  case 477: /* assign_stm: PVBUFSLOTS EQUAL NUMBER  */
#line 1989 "core/cfg.y"
                                  { pv_set_buffer_slots((yyvsp[0].intval)); }
#line 8878 "core/cfg.tab.c"
    break;

  case 478: /* assign_stm: PVBUFSLOTS EQUAL error  */
#line 1990 "core/cfg.y"
                                 { yyerror("number expected"); }
#line 8884 "core/cfg.tab.c"
    break;

  case 479: /* assign_stm: PVCACHELIMIT EQUAL NUMBER  */
#line 1991 "core/cfg.y"
                                    { default_core_cfg.pv_cache_limit=(yyvsp[0].intval); }
#line 8890 "core/cfg.tab.c"
    break;

  case 480: /* assign_stm: PVCACHELIMIT EQUAL error  */
#line 1992 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 8896 "core/cfg.tab.c"
    break;

  case 481: /* assign_stm: PVCACHEACTION EQUAL NUMBER  */
#line 1993 "core/cfg.y"
                                     { default_core_cfg.pv_cache_action=(yyvsp[0].intval); }
#line 8902 "core/cfg.tab.c"
    break;

  case 482: /* assign_stm: PVCACHEACTION EQUAL error  */
#line 1994 "core/cfg.y"
                                    { yyerror("number expected"); }
#line 8908 "core/cfg.tab.c"
    break;

  case 483: /* assign_stm: HTTP_REPLY_PARSE EQUAL NUMBER  */
#line 1995 "core/cfg.y"
                                        { http_reply_parse=(yyvsp[0].intval); }
#line 8914 "core/cfg.tab.c"
    break;

  case 484: /* assign_stm: HTTP_REPLY_PARSE EQUAL error  */
#line 1996 "core/cfg.y"
                                       { yyerror("boolean value expected"); }
#line 8920 "core/cfg.tab.c"
    break;

  case 485: /* assign_stm: VERBOSE_STARTUP EQUAL NUMBER  */
#line 1997 "core/cfg.y"
                                       { ksr_verbose_startup=(yyvsp[0].intval); }
#line 8926 "core/cfg.tab.c"
    break;

  case 486: /* assign_stm: VERBOSE_STARTUP EQUAL error  */
#line 1998 "core/cfg.y"
                                      { yyerror("boolean value expected"); }
#line 8932 "core/cfg.tab.c"
    break;

  case 487: /* assign_stm: ROUTE_LOCKS_SIZE EQUAL NUMBER  */
#line 1999 "core/cfg.y"
                                        { ksr_route_locks_size=(yyvsp[0].intval); }
#line 8938 "core/cfg.tab.c"
    break;

  case 488: /* assign_stm: ROUTE_LOCKS_SIZE EQUAL error  */
#line 2000 "core/cfg.y"
                                       { yyerror("number expected"); }
#line 8944 "core/cfg.tab.c"
    break;

  case 489: /* assign_stm: WAIT_WORKER1_MODE EQUAL NUMBER  */
#line 2001 "core/cfg.y"
                                         { ksr_wait_worker1_mode=(yyvsp[0].intval); }
#line 8950 "core/cfg.tab.c"
    break;

  case 490: /* assign_stm: WAIT_WORKER1_MODE EQUAL error  */
#line 2002 "core/cfg.y"
                                        { yyerror("number expected"); }
#line 8956 "core/cfg.tab.c"
    break;

  case 491: /* assign_stm: WAIT_WORKER1_TIME EQUAL NUMBER  */
#line 2003 "core/cfg.y"
                                         { ksr_wait_worker1_time=(yyvsp[0].intval); }
#line 8962 "core/cfg.tab.c"
    break;

  case 492: /* assign_stm: WAIT_WORKER1_TIME EQUAL error  */
#line 2004 "core/cfg.y"
                                        { yyerror("number expected"); }
#line 8968 "core/cfg.tab.c"
    break;

  case 493: /* assign_stm: WAIT_WORKER1_USLEEP EQUAL NUMBER  */
#line 2005 "core/cfg.y"
                                           { ksr_wait_worker1_usleep=(yyvsp[0].intval); }
#line 8974 "core/cfg.tab.c"
    break;

  case 494: /* assign_stm: WAIT_WORKER1_USLEEP EQUAL error  */
#line 2006 "core/cfg.y"
                                          { yyerror("number expected"); }
#line 8980 "core/cfg.tab.c"
    break;

  case 495: /* assign_stm: SERVER_ID EQUAL NUMBER  */
#line 2007 "core/cfg.y"
                             { server_id=(yyvsp[0].intval); }
#line 8986 "core/cfg.tab.c"
    break;

  case 496: /* assign_stm: SERVER_ID EQUAL error  */
#line 2008 "core/cfg.y"
                                 { yyerror("number expected"); }
#line 8992 "core/cfg.tab.c"
    break;

  case 497: /* assign_stm: RETURN_MODE EQUAL NUMBER  */
#line 2009 "core/cfg.y"
                               { ksr_return_mode=(yyvsp[0].intval); }
#line 8998 "core/cfg.tab.c"
    break;

  case 498: /* assign_stm: RETURN_MODE EQUAL error  */
#line 2010 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 9004 "core/cfg.tab.c"
    break;

  case 499: /* assign_stm: KEMI DOT REQUEST_ROUTE_CALLBACK EQUAL STRING  */
#line 2011 "core/cfg.y"
                                                       {
			kemi_request_route_callback.s = (yyvsp[0].strval);
			kemi_request_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_request_route_callback.len==0) {
				yyerror("empty name for request route callback function");
			}
		}
#line 9016 "core/cfg.tab.c"
    break;

  case 500: /* assign_stm: KEMI DOT REQUEST_ROUTE_CALLBACK EQUAL error  */
#line 2018 "core/cfg.y"
                                                      { yyerror("string expected"); }
#line 9022 "core/cfg.tab.c"
    break;

  case 501: /* assign_stm: KEMI DOT ONSEND_ROUTE_CALLBACK EQUAL STRING  */
#line 2019 "core/cfg.y"
                                                      {
			kemi_onsend_route_callback.s = (yyvsp[0].strval);
			kemi_onsend_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_onsend_route_callback.len==4
					&& strcasecmp(kemi_onsend_route_callback.s, "none")==0) {
				kemi_onsend_route_callback.s = "";
				kemi_onsend_route_callback.len = 0;
			}
		}
#line 9036 "core/cfg.tab.c"
    break;

  case 502: /* assign_stm: KEMI DOT ONSEND_ROUTE_CALLBACK EQUAL error  */
#line 2028 "core/cfg.y"
                                                     { yyerror("string expected"); }
#line 9042 "core/cfg.tab.c"
    break;

  case 503: /* assign_stm: KEMI DOT REPLY_ROUTE_CALLBACK EQUAL STRING  */
#line 2029 "core/cfg.y"
                                                     {
			kemi_reply_route_callback.s = (yyvsp[0].strval);
			kemi_reply_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_reply_route_callback.len==4
					&& strcasecmp(kemi_reply_route_callback.s, "none")==0) {
				kemi_reply_route_callback.s = "";
				kemi_reply_route_callback.len = 0;
			}
		}
#line 9056 "core/cfg.tab.c"
    break;

  case 504: /* assign_stm: KEMI DOT REPLY_ROUTE_CALLBACK EQUAL error  */
#line 2038 "core/cfg.y"
                                                    { yyerror("string expected"); }
#line 9062 "core/cfg.tab.c"
    break;

  case 505: /* assign_stm: KEMI DOT EVENT_ROUTE_CALLBACK EQUAL STRING  */
#line 2039 "core/cfg.y"
                                                     {
			kemi_event_route_callback.s = (yyvsp[0].strval);
			kemi_event_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_event_route_callback.len==4
					&& strcasecmp(kemi_event_route_callback.s, "none")==0) {
				kemi_event_route_callback.s = "";
				kemi_event_route_callback.len = 0;
			}
		}
#line 9076 "core/cfg.tab.c"
    break;

  case 506: /* assign_stm: KEMI DOT EVENT_ROUTE_CALLBACK EQUAL error  */
#line 2048 "core/cfg.y"
                                                    { yyerror("string expected"); }
#line 9082 "core/cfg.tab.c"
    break;

  case 507: /* assign_stm: KEMI DOT RECEIVED_ROUTE_CALLBACK EQUAL STRING  */
#line 2049 "core/cfg.y"
                                                        {
			kemi_received_route_callback.s = (yyvsp[0].strval);
			kemi_received_route_callback.len = strlen((yyvsp[0].strval));
			if(kemi_received_route_callback.len==4
					&& strcasecmp(kemi_received_route_callback.s, "none")==0) {
				kemi_received_route_callback.s = "";
				kemi_received_route_callback.len = 0;
			}
		}
#line 9096 "core/cfg.tab.c"
    break;

  case 508: /* assign_stm: KEMI DOT RECEIVED_ROUTE_CALLBACK EQUAL error  */
#line 2058 "core/cfg.y"
                                                       { yyerror("string expected"); }
#line 9102 "core/cfg.tab.c"
    break;

  case 509: /* assign_stm: KEMI DOT PRE_ROUTING_CALLBACK EQUAL STRING  */
#line 2059 "core/cfg.y"
                                                     {
			kemi_pre_routing_callback.s = (yyvsp[0].strval);
			kemi_pre_routing_callback.len = strlen((yyvsp[0].strval));
			if(kemi_pre_routing_callback.len==4
					&& strcasecmp(kemi_pre_routing_callback.s, "none")==0) {
				kemi_pre_routing_callback.s = "";
				kemi_pre_routing_callback.len = 0;
			}
		}
#line 9116 "core/cfg.tab.c"
    break;

  case 510: /* assign_stm: KEMI DOT PRE_ROUTING_CALLBACK EQUAL error  */
#line 2068 "core/cfg.y"
                                                    { yyerror("string expected"); }
#line 9122 "core/cfg.tab.c"
    break;

  case 511: /* assign_stm: RECEIVED_ROUTE_MODE EQUAL intno  */
#line 2069 "core/cfg.y"
                                      { ksr_evrt_received_mode=(yyvsp[0].intval); }
#line 9128 "core/cfg.tab.c"
    break;

  case 512: /* assign_stm: RECEIVED_ROUTE_MODE EQUAL error  */
#line 2070 "core/cfg.y"
                                           { yyerror("number  expected"); }
#line 9134 "core/cfg.tab.c"
    break;

  case 513: /* assign_stm: MAX_RECURSIVE_LEVEL EQUAL NUMBER  */
#line 2071 "core/cfg.y"
                                       { set_max_recursive_level((yyvsp[0].intval)); }
#line 9140 "core/cfg.tab.c"
    break;

  case 514: /* assign_stm: MAX_BRANCHES_PARAM EQUAL NUMBER  */
#line 2072 "core/cfg.y"
                                      { sr_dst_max_branches = (yyvsp[0].intval); }
#line 9146 "core/cfg.tab.c"
    break;

  case 515: /* assign_stm: LATENCY_LOG EQUAL intno  */
#line 2073 "core/cfg.y"
                              { default_core_cfg.latency_log=(yyvsp[0].intval); }
#line 9152 "core/cfg.tab.c"
    break;

  case 516: /* assign_stm: LATENCY_LOG EQUAL error  */
#line 2074 "core/cfg.y"
                                   { yyerror("number  expected"); }
#line 9158 "core/cfg.tab.c"
    break;

  case 517: /* assign_stm: LATENCY_CFG_LOG EQUAL intno  */
#line 2075 "core/cfg.y"
                                  { default_core_cfg.latency_cfg_log=(yyvsp[0].intval); }
#line 9164 "core/cfg.tab.c"
    break;

  case 518: /* assign_stm: LATENCY_CFG_LOG EQUAL error  */
#line 2076 "core/cfg.y"
                                       { yyerror("number  expected"); }
#line 9170 "core/cfg.tab.c"
    break;

  case 519: /* assign_stm: LATENCY_LIMIT_DB EQUAL NUMBER  */
#line 2077 "core/cfg.y"
                                    { default_core_cfg.latency_limit_db=(yyvsp[0].intval); }
#line 9176 "core/cfg.tab.c"
    break;

  case 520: /* assign_stm: LATENCY_LIMIT_DB EQUAL error  */
#line 2078 "core/cfg.y"
                                        { yyerror("number  expected"); }
#line 9182 "core/cfg.tab.c"
    break;

  case 521: /* assign_stm: LATENCY_LIMIT_ACTION EQUAL NUMBER  */
#line 2079 "core/cfg.y"
                                        { default_core_cfg.latency_limit_action=(yyvsp[0].intval); }
#line 9188 "core/cfg.tab.c"
    break;

  case 522: /* assign_stm: LATENCY_LIMIT_ACTION EQUAL error  */
#line 2080 "core/cfg.y"
                                            { yyerror("number  expected"); }
#line 9194 "core/cfg.tab.c"
    break;

  case 523: /* assign_stm: LATENCY_LIMIT_CFG EQUAL NUMBER  */
#line 2081 "core/cfg.y"
                                     { default_core_cfg.latency_limit_cfg=(yyvsp[0].intval); }
#line 9200 "core/cfg.tab.c"
    break;

  case 524: /* assign_stm: LATENCY_LIMIT_CFG EQUAL error  */
#line 2082 "core/cfg.y"
                                         { yyerror("number  expected"); }
#line 9206 "core/cfg.tab.c"
    break;

  case 525: /* assign_stm: RPC_EXEC_DELTA_CFG EQUAL NUMBER  */
#line 2083 "core/cfg.y"
                                      { ksr_rpc_exec_delta=(yyvsp[0].intval); }
#line 9212 "core/cfg.tab.c"
    break;

  case 526: /* assign_stm: RPC_EXEC_DELTA_CFG EQUAL error  */
#line 2084 "core/cfg.y"
                                          { yyerror("number  expected"); }
#line 9218 "core/cfg.tab.c"
    break;

  case 527: /* assign_stm: MSG_TIME EQUAL NUMBER  */
#line 2085 "core/cfg.y"
                            { sr_msg_time=(yyvsp[0].intval); }
#line 9224 "core/cfg.tab.c"
    break;

  case 528: /* assign_stm: MSG_TIME EQUAL error  */
#line 2086 "core/cfg.y"
                                { yyerror("number  expected"); }
#line 9230 "core/cfg.tab.c"
    break;

  case 529: /* assign_stm: ONSEND_RT_REPLY EQUAL NUMBER  */
#line 2087 "core/cfg.y"
                                       { onsend_route_reply=(yyvsp[0].intval); }
#line 9236 "core/cfg.tab.c"
    break;

  case 530: /* assign_stm: ONSEND_RT_REPLY EQUAL error  */
#line 2088 "core/cfg.y"
                                      { yyerror("int value expected"); }
#line 9242 "core/cfg.tab.c"
    break;

  case 531: /* assign_stm: UDP_MTU EQUAL NUMBER  */
#line 2089 "core/cfg.y"
                               { default_core_cfg.udp_mtu=(yyvsp[0].intval); }
#line 9248 "core/cfg.tab.c"
    break;

  case 532: /* assign_stm: UDP_MTU EQUAL error  */
#line 2090 "core/cfg.y"
                              { yyerror("number expected"); }
#line 9254 "core/cfg.tab.c"
    break;

  case 533: /* assign_stm: FORCE_RPORT EQUAL NUMBER  */
#line 2092 "core/cfg.y"
                { default_core_cfg.force_rport=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 9260 "core/cfg.tab.c"
    break;

  case 534: /* assign_stm: FORCE_RPORT EQUAL error  */
#line 2093 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 9266 "core/cfg.tab.c"
    break;

  case 535: /* assign_stm: LOCAL_RPORT EQUAL NUMBER  */
#line 2094 "core/cfg.y"
                                   { ksr_local_rport=(yyvsp[0].intval); }
#line 9272 "core/cfg.tab.c"
    break;

  case 536: /* assign_stm: LOCAL_RPORT EQUAL error  */
#line 2095 "core/cfg.y"
                                  { yyerror("boolean value expected"); }
#line 9278 "core/cfg.tab.c"
    break;

  case 537: /* assign_stm: UDP_MTU_TRY_PROTO EQUAL proto  */
#line 2097 "core/cfg.y"
                { default_core_cfg.udp_mtu_try_proto=(yyvsp[0].intval); fix_global_req_flags(0, 0); }
#line 9284 "core/cfg.tab.c"
    break;

  case 538: /* assign_stm: UDP_MTU_TRY_PROTO EQUAL error  */
#line 2099 "core/cfg.y"
                { yyerror("TCP, TLS, SCTP or UDP expected"); }
#line 9290 "core/cfg.tab.c"
    break;

  case 539: /* assign_stm: UDP4_RAW EQUAL intno  */
#line 2100 "core/cfg.y"
                               { IF_RAW_SOCKS(default_core_cfg.udp4_raw=(yyvsp[0].intval)); }
#line 9296 "core/cfg.tab.c"
    break;

  case 540: /* assign_stm: UDP4_RAW EQUAL error  */
#line 2101 "core/cfg.y"
                               { yyerror("number expected"); }
#line 9302 "core/cfg.tab.c"
    break;

  case 541: /* assign_stm: UDP4_RAW_MTU EQUAL NUMBER  */
#line 2102 "core/cfg.y"
                                    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_mtu=(yyvsp[0].intval));
	}
#line 9310 "core/cfg.tab.c"
    break;

  case 542: /* assign_stm: UDP4_RAW_MTU EQUAL error  */
#line 2105 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 9316 "core/cfg.tab.c"
    break;

  case 543: /* assign_stm: UDP4_RAW_TTL EQUAL NUMBER  */
#line 2106 "core/cfg.y"
                                    {
		IF_RAW_SOCKS(default_core_cfg.udp4_raw_ttl=(yyvsp[0].intval));
	}
#line 9324 "core/cfg.tab.c"
    break;

  case 544: /* assign_stm: UDP4_RAW_TTL EQUAL error  */
#line 2109 "core/cfg.y"
                                   { yyerror("number expected"); }
#line 9330 "core/cfg.tab.c"
    break;

  case 546: /* assign_stm: error EQUAL  */
#line 2111 "core/cfg.y"
                      { yyerror("unknown config variable"); }
#line 9336 "core/cfg.tab.c"
    break;

  case 548: /* cfg_var_id: DEFAULT  */
#line 2115 "core/cfg.y"
                  { (yyval.strval)="default" ; }
#line 9342 "core/cfg.tab.c"
    break;

  case 550: /* cfg_var_idn: DEFAULT  */
#line 2119 "core/cfg.y"
                  { (yyval.strval)="default" ; }
#line 9348 "core/cfg.tab.c"
    break;

  case 551: /* cfg_var_idn: NUMBER  */
#line 2120 "core/cfg.y"
                 {
		yyerror("cfg var field name - use of number or reserved token not allowed: %s",
				yy_number_str);
		YYERROR;
	}
#line 9358 "core/cfg.tab.c"
    break;

  case 552: /* cfg_var: cfg_var_id DOT cfg_var_idn EQUAL NUMBER  */
#line 2128 "core/cfg.y"
                                                {
		if (cfg_declare_int((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].intval), 0, 0, NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 9368 "core/cfg.tab.c"
    break;

  case 553: /* cfg_var: cfg_var_id DOT cfg_var_idn EQUAL STRING  */
#line 2133 "core/cfg.y"
                                                  {
		if (cfg_declare_str((yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval), NULL)) {
			yyerror("variable cannot be declared");
		}
	}
#line 9378 "core/cfg.tab.c"
    break;

  case 554: /* cfg_var: cfg_var_id DOT cfg_var_idn EQUAL NUMBER CFG_DESCRIPTION STRING  */
#line 2138 "core/cfg.y"
                                                                         {
		if (cfg_declare_int((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].intval), 0, 0, (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 9388 "core/cfg.tab.c"
    break;

  case 555: /* cfg_var: cfg_var_id DOT cfg_var_idn EQUAL STRING CFG_DESCRIPTION STRING  */
#line 2143 "core/cfg.y"
                                                                         {
		if (cfg_declare_str((yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be declared");
		}
	}
#line 9398 "core/cfg.tab.c"
    break;

  case 556: /* cfg_var: cfg_var_id DOT cfg_var_idn EQUAL error  */
#line 2148 "core/cfg.y"
                                                 {
		yyerror("number or string expected");
	}
#line 9406 "core/cfg.tab.c"
    break;

  case 557: /* cfg_var: cfg_var_id LBRACK NUMBER RBRACK DOT cfg_var_idn EQUAL NUMBER  */
#line 2151 "core/cfg.y"
                                                                       {
		if (cfg_ginst_var_int((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].intval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 9416 "core/cfg.tab.c"
    break;

  case 558: /* cfg_var: cfg_var_id LBRACK NUMBER RBRACK DOT cfg_var_idn EQUAL STRING  */
#line 2156 "core/cfg.y"
                                                                       {
		if (cfg_ginst_var_string((yyvsp[-7].strval), (yyvsp[-5].intval), (yyvsp[-2].strval), (yyvsp[0].strval))) {
			yyerror("variable cannot be added to the group instance");
		}
	}
#line 9426 "core/cfg.tab.c"
    break;

  case 559: /* module_stm: LOADMODULE STRING  */
#line 2164 "core/cfg.y"
                          {
		LM_DBG("loading module %s\n", (yyvsp[0].strval));
			if (ksr_load_module((yyvsp[0].strval), NULL)!=0) {
				yyerror("failed to load module");
			}
	}
#line 9437 "core/cfg.tab.c"
    break;

  case 560: /* module_stm: LOADMODULE LPAREN STRING RPAREN  */
#line 2170 "core/cfg.y"
                                          {
		LM_DBG("loading module %s\n", (yyvsp[-1].strval));
			if (ksr_load_module((yyvsp[-1].strval), NULL)!=0) {
				yyerror("failed to load module");
			}
	}
#line 9448 "core/cfg.tab.c"
    break;

  case 561: /* module_stm: LOADMODULE LPAREN STRING COMMA STRING RPAREN  */
#line 2176 "core/cfg.y"
                                                       {
		LM_DBG("loading module %s opts %s\n", (yyvsp[-3].strval), (yyvsp[-1].strval));
			if (ksr_load_module((yyvsp[-3].strval), (yyvsp[-1].strval))!=0) {
				yyerror("failed to load module");
			}
	}
#line 9459 "core/cfg.tab.c"
    break;

  case 562: /* module_stm: LOADMODULE error  */
#line 2182 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9465 "core/cfg.tab.c"
    break;

  case 563: /* module_stm: LOADMODULEX STRING  */
#line 2183 "core/cfg.y"
                             {
		LM_DBG("loading module %s\n", (yyvsp[0].strval));
			if (ksr_load_modulex((yyvsp[0].strval), NULL)!=0) {
				yyerror("failed to load module");
			}
	}
#line 9476 "core/cfg.tab.c"
    break;

  case 564: /* module_stm: LOADMODULEX LPAREN STRING RPAREN  */
#line 2189 "core/cfg.y"
                                           {
		LM_DBG("loading module %s\n", (yyvsp[-1].strval));
			if (ksr_load_modulex((yyvsp[-1].strval), NULL)!=0) {
				yyerror("failed to load module");
			}
	}
#line 9487 "core/cfg.tab.c"
    break;

  case 565: /* module_stm: LOADMODULEX LPAREN STRING COMMA STRING RPAREN  */
#line 2195 "core/cfg.y"
                                                        {
		LM_DBG("loading module %s opts %s\n", (yyvsp[-3].strval), (yyvsp[-1].strval));
			if (ksr_load_modulex((yyvsp[-3].strval), (yyvsp[-1].strval))!=0) {
				yyerror("failed to load module");
			}
	}
#line 9498 "core/cfg.tab.c"
    break;

  case 566: /* module_stm: LOADMODULEX error  */
#line 2201 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9504 "core/cfg.tab.c"
    break;

  case 567: /* module_stm: LOADPATH STRING  */
#line 2202 "core/cfg.y"
                          {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 9519 "core/cfg.tab.c"
    break;

  case 568: /* module_stm: LOADPATH error  */
#line 2212 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9525 "core/cfg.tab.c"
    break;

  case 569: /* module_stm: LOADPATH EQUAL STRING  */
#line 2213 "core/cfg.y"
                                {
		if(mods_dir_cmd==0) {
			LM_DBG("loading modules under %s\n", (yyvsp[0].strval));
			printf("loading modules under config path: %s\n", (yyvsp[0].strval));
			mods_dir = (yyvsp[0].strval);
		} else {
			LM_DBG("ignoring mod path given in config: %s\n", (yyvsp[0].strval));
			printf("loading modules under command line path: %s\n", mods_dir);
		}
	}
#line 9540 "core/cfg.tab.c"
    break;

  case 570: /* module_stm: LOADPATH EQUAL error  */
#line 2223 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9546 "core/cfg.tab.c"
    break;

  case 571: /* module_stm: MODPARAM LPAREN STRING COMMA STRING COMMA STRING RPAREN  */
#line 2224 "core/cfg.y"
                                                                  {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_STRING, (yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 9560 "core/cfg.tab.c"
    break;

  case 572: /* module_stm: MODPARAM LPAREN STRING COMMA STRING COMMA intno RPAREN  */
#line 2233 "core/cfg.y"
                                                                 {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (set_mod_param_regex((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_INT, (void*)(yyvsp[-1].intval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 9574 "core/cfg.tab.c"
    break;

  case 573: /* module_stm: MODPARAM error  */
#line 2242 "core/cfg.y"
                         { yyerror("Invalid arguments"); }
#line 9580 "core/cfg.tab.c"
    break;

  case 574: /* module_stm: MODPARAMX LPAREN STRING COMMA STRING COMMA STRING RPAREN  */
#line 2243 "core/cfg.y"
                                                                   {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (modparamx_set((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_STRING, (yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 9594 "core/cfg.tab.c"
    break;

  case 575: /* module_stm: MODPARAMX LPAREN STRING COMMA STRING COMMA intno RPAREN  */
#line 2252 "core/cfg.y"
                                                                  {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (modparamx_set((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_INT, (void*)(yyvsp[-1].intval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 9608 "core/cfg.tab.c"
    break;

  case 576: /* module_stm: MODPARAMX LPAREN STRING COMMA STRING COMMA PVAR RPAREN  */
#line 2261 "core/cfg.y"
                                                                 {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (modparamx_set((yyvsp[-5].strval), (yyvsp[-3].strval), PARAM_VAR, (void*)(yyvsp[-1].strval)) != 0) {
			 yyerror("Can't set module parameter");
		}
	}
#line 9622 "core/cfg.tab.c"
    break;

  case 577: /* module_stm: MODPARAMX error  */
#line 2270 "core/cfg.y"
                          { yyerror("Invalid arguments"); }
#line 9628 "core/cfg.tab.c"
    break;

  case 578: /* module_stm: CFGENGINE STRING  */
#line 2271 "core/cfg.y"
                           {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 9639 "core/cfg.tab.c"
    break;

  case 579: /* module_stm: CFGENGINE error  */
#line 2277 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9645 "core/cfg.tab.c"
    break;

  case 580: /* module_stm: CFGENGINE EQUAL STRING  */
#line 2278 "core/cfg.y"
                                 {
		if(sr_kemi_eng_setz((yyvsp[0].strval), NULL)) {
			yyerror("Can't set config routing engine");
			YYABORT;
		}
	}
#line 9656 "core/cfg.tab.c"
    break;

  case 581: /* module_stm: CFGENGINE EQUAL error  */
#line 2284 "core/cfg.y"
                                { yyerror("string expected"); }
#line 9662 "core/cfg.tab.c"
    break;

  case 582: /* ip: ipv4  */
#line 2288 "core/cfg.y"
              { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 9668 "core/cfg.tab.c"
    break;

  case 583: /* ip: ipv6  */
#line 2289 "core/cfg.y"
                { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 9674 "core/cfg.tab.c"
    break;

  case 584: /* ipv4: NUMBER DOT NUMBER DOT NUMBER DOT NUMBER  */
#line 2292 "core/cfg.y"
                                                {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			PKG_MEM_CRITICAL;
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET;
			(yyval.ipaddr)->len=4;
			if (((yyvsp[-6].intval)>255) || ((yyvsp[-6].intval)<0) ||
				((yyvsp[-4].intval)>255) || ((yyvsp[-4].intval)<0) ||
				((yyvsp[-2].intval)>255) || ((yyvsp[-2].intval)<0) ||
				((yyvsp[0].intval)>255) || ((yyvsp[0].intval)<0)) {
				yyerror("invalid ipv4 address");
				(yyval.ipaddr)->u.addr32[0]=0;
				/* $$=0; */
			} else {
				(yyval.ipaddr)->u.addr[0]=(yyvsp[-6].intval);
				(yyval.ipaddr)->u.addr[1]=(yyvsp[-4].intval);
				(yyval.ipaddr)->u.addr[2]=(yyvsp[-2].intval);
				(yyval.ipaddr)->u.addr[3]=(yyvsp[0].intval);
				/*
				$$=htonl( ($1<<24)|
				($3<<16)| ($5<<8)|$7 );
				*/
			}
		}
	}
#line 9706 "core/cfg.tab.c"
    break;

  case 585: /* ipv6addr: IPV6ADDR  */
#line 2321 "core/cfg.y"
                 {
		(yyval.ipaddr)=pkg_malloc(sizeof(struct ip_addr));
		if ((yyval.ipaddr)==0) {
			PKG_MEM_CRITICAL;
		} else {
			memset((yyval.ipaddr), 0, sizeof(struct ip_addr));
			(yyval.ipaddr)->af=AF_INET6;
			(yyval.ipaddr)->len=16;
			if (inet_pton(AF_INET6, (yyvsp[0].strval), (yyval.ipaddr)->u.addr)<=0) {
				yyerror("bad ipv6 address");
			}
		}
	}
#line 9724 "core/cfg.tab.c"
    break;

  case 586: /* ipv6: ipv6addr  */
#line 2336 "core/cfg.y"
                 { (yyval.ipaddr)=(yyvsp[0].ipaddr); }
#line 9730 "core/cfg.tab.c"
    break;

  case 587: /* ipv6: LBRACK ipv6addr RBRACK  */
#line 2337 "core/cfg.y"
                                 {(yyval.ipaddr)=(yyvsp[-1].ipaddr); }
#line 9736 "core/cfg.tab.c"
    break;

  case 588: /* route_name: NUMBER  */
#line 2341 "core/cfg.y"
                                {
					tmp=int2str((yyvsp[0].intval), &i_tmp);
					if (((yyval.strval)=pkg_malloc(i_tmp+1))==0) {
						yyerror("out of  memory");
						YYABORT;
					} else {
						memcpy((yyval.strval), tmp, i_tmp);
						(yyval.strval)[i_tmp]=0;
					}
					routename = tmp;
						}
#line 9752 "core/cfg.tab.c"
    break;

  case 589: /* route_name: ID  */
#line 2352 "core/cfg.y"
                                                { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 9758 "core/cfg.tab.c"
    break;

  case 590: /* route_name: STRING  */
#line 2353 "core/cfg.y"
                                        { routename = (yyvsp[0].strval); (yyval.strval)=(yyvsp[0].strval); }
#line 9764 "core/cfg.tab.c"
    break;

  case 591: /* route_main: ROUTE  */
#line 2357 "core/cfg.y"
                      { routename=NULL; }
#line 9770 "core/cfg.tab.c"
    break;

  case 592: /* route_main: ROUTE_REQUEST  */
#line 2358 "core/cfg.y"
                                  { routename=NULL; }
#line 9776 "core/cfg.tab.c"
    break;

  case 593: /* route_stm: route_main LBRACE actions RBRACE  */
#line 2362 "core/cfg.y"
                                         {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[DEFAULT_RT]);
	}
#line 9788 "core/cfg.tab.c"
    break;

  case 594: /* route_stm: ROUTE LBRACK route_name RBRACK LBRACE actions RBRACE  */
#line 2369 "core/cfg.y"
                                                               {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&main_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (main_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &main_rt.rlist[i_tmp]);
	}
#line 9809 "core/cfg.tab.c"
    break;

  case 595: /* route_stm: ROUTE error  */
#line 2385 "core/cfg.y"
                      { yyerror("invalid  route  statement"); }
#line 9815 "core/cfg.tab.c"
    break;

  case 596: /* route_stm: ROUTE_REQUEST error  */
#line 2386 "core/cfg.y"
                              { yyerror("invalid  request_route  statement"); }
#line 9821 "core/cfg.tab.c"
    break;

  case 597: /* failure_route_main: ROUTE_FAILURE  */
#line 2389 "core/cfg.y"
                                  { routename=NULL; }
#line 9827 "core/cfg.tab.c"
    break;

  case 598: /* failure_route_stm: failure_route_main LBRACE actions RBRACE  */
#line 2392 "core/cfg.y"
                                                 {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[DEFAULT_RT]);
	}
#line 9839 "core/cfg.tab.c"
    break;

  case 599: /* failure_route_stm: ROUTE_FAILURE LBRACK route_name RBRACK LBRACE actions RBRACE  */
#line 2399 "core/cfg.y"
                                                                       {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&failure_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (failure_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &failure_rt.rlist[i_tmp]);
	}
#line 9860 "core/cfg.tab.c"
    break;

  case 600: /* failure_route_stm: ROUTE_FAILURE error  */
#line 2415 "core/cfg.y"
                              { yyerror("invalid failure_route statement"); }
#line 9866 "core/cfg.tab.c"
    break;

  case 601: /* route_reply_main: ROUTE_ONREPLY  */
#line 2419 "core/cfg.y"
                                      { routename=NULL; }
#line 9872 "core/cfg.tab.c"
    break;

  case 602: /* route_reply_main: ROUTE_REPLY  */
#line 2420 "core/cfg.y"
                                { routename=NULL; }
#line 9878 "core/cfg.tab.c"
    break;

  case 603: /* $@7: %empty  */
#line 2425 "core/cfg.y"
                                {rt=CORE_ONREPLY_ROUTE;}
#line 9884 "core/cfg.tab.c"
    break;

  case 604: /* onreply_route_stm: route_reply_main LBRACE $@7 actions RBRACE  */
#line 2425 "core/cfg.y"
                                                                        {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
	}
#line 9896 "core/cfg.tab.c"
    break;

  case 605: /* onreply_route_stm: ROUTE_ONREPLY error  */
#line 2432 "core/cfg.y"
                              { yyerror("invalid onreply_route statement"); }
#line 9902 "core/cfg.tab.c"
    break;

  case 606: /* onreply_route_stm: ROUTE_REPLY error  */
#line 2433 "core/cfg.y"
                            { yyerror("invalid onreply_route statement"); }
#line 9908 "core/cfg.tab.c"
    break;

  case 607: /* $@8: %empty  */
#line 2435 "core/cfg.y"
                {rt=(*(yyvsp[-1].strval)=='0' && (yyvsp[-1].strval)[1]==0)?CORE_ONREPLY_ROUTE:TM_ONREPLY_ROUTE;}
#line 9914 "core/cfg.tab.c"
    break;

  case 608: /* onreply_route_stm: ROUTE_ONREPLY LBRACK route_name RBRACK $@8 LBRACE actions RBRACE  */
#line 2436 "core/cfg.y"
                                      {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		if (*(yyvsp[-5].strval)=='0' && (yyvsp[-5].strval)[1]==0){
			/* onreply_route[0] {} is equivalent with onreply_route {}*/
			push((yyvsp[-1].action), &onreply_rt.rlist[DEFAULT_RT]);
		}else{
			i_tmp=route_get(&onreply_rt, (yyvsp[-5].strval));
			if (i_tmp==-1){
				yyerror("internal error");
				YYABORT;
			}
			if (onreply_rt.rlist[i_tmp]){
				yyerror("duplicate route");
				YYABORT;
			}
			push((yyvsp[-1].action), &onreply_rt.rlist[i_tmp]);
		}
	}
#line 9940 "core/cfg.tab.c"
    break;

  case 609: /* onreply_route_stm: ROUTE_ONREPLY LBRACK route_name RBRACK error  */
#line 2457 "core/cfg.y"
                                                       {
		yyerror("invalid onreply_route statement");
	}
#line 9948 "core/cfg.tab.c"
    break;

  case 610: /* branch_route_main: ROUTE_BRANCH  */
#line 2462 "core/cfg.y"
                                { routename=NULL; }
#line 9954 "core/cfg.tab.c"
    break;

  case 611: /* branch_route_stm: branch_route_main LBRACE actions RBRACE  */
#line 2465 "core/cfg.y"
                                                {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[DEFAULT_RT]);
	}
#line 9966 "core/cfg.tab.c"
    break;

  case 612: /* branch_route_stm: ROUTE_BRANCH LBRACK route_name RBRACK LBRACE actions RBRACE  */
#line 2472 "core/cfg.y"
                                                                      {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&branch_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (branch_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &branch_rt.rlist[i_tmp]);
	}
#line 9987 "core/cfg.tab.c"
    break;

  case 613: /* branch_route_stm: ROUTE_BRANCH error  */
#line 2488 "core/cfg.y"
                             { yyerror("invalid branch_route statement"); }
#line 9993 "core/cfg.tab.c"
    break;

  case 614: /* send_route_main: ROUTE_SEND  */
#line 2491 "core/cfg.y"
                            { routename=NULL; }
#line 9999 "core/cfg.tab.c"
    break;

  case 615: /* send_route_stm: send_route_main LBRACE actions RBRACE  */
#line 2494 "core/cfg.y"
                                              {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[DEFAULT_RT]);
	}
#line 10011 "core/cfg.tab.c"
    break;

  case 616: /* send_route_stm: ROUTE_SEND LBRACK route_name RBRACK LBRACE actions RBRACE  */
#line 2501 "core/cfg.y"
                                                                    {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&onsend_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (onsend_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &onsend_rt.rlist[i_tmp]);
	}
#line 10032 "core/cfg.tab.c"
    break;

  case 617: /* send_route_stm: ROUTE_SEND error  */
#line 2517 "core/cfg.y"
                           { yyerror("invalid onsend_route statement"); }
#line 10038 "core/cfg.tab.c"
    break;

  case 618: /* event_route_main: ROUTE_EVENT  */
#line 2520 "core/cfg.y"
                              { routename=NULL; }
#line 10044 "core/cfg.tab.c"
    break;

  case 619: /* event_route_stm: event_route_main LBRACK EVENT_RT_NAME RBRACK LBRACE actions RBRACE  */
#line 2523 "core/cfg.y"
                                                                           {
		if (!shm_initialized() && init_shm()<0) {
			yyerror("Can't initialize shared memory");
			YYABORT;
		}
		i_tmp=route_get(&event_rt, (yyvsp[-4].strval));
		if (i_tmp==-1){
			yyerror("internal error");
			YYABORT;
		}
		if (event_rt.rlist[i_tmp]){
			yyerror("duplicate route");
			YYABORT;
		}
		push((yyvsp[-1].action), &event_rt.rlist[i_tmp]);
	}
#line 10065 "core/cfg.tab.c"
    break;

  case 620: /* event_route_stm: ROUTE_EVENT error  */
#line 2540 "core/cfg.y"
                            { yyerror("invalid event_route statement"); }
#line 10071 "core/cfg.tab.c"
    break;

  case 621: /* preprocess_stm: SUBST STRING  */
#line 2543 "core/cfg.y"
                     { if(pp_subst_add((yyvsp[0].strval))<0) YYERROR; }
#line 10077 "core/cfg.tab.c"
    break;

  case 622: /* preprocess_stm: SUBST error  */
#line 2544 "core/cfg.y"
                      { yyerror("invalid subst preprocess statement"); }
#line 10083 "core/cfg.tab.c"
    break;

  case 623: /* preprocess_stm: SUBSTDEF STRING  */
#line 2545 "core/cfg.y"
                          { if(pp_substdef_add((yyvsp[0].strval), KSR_PPDEF_NORMAL)<0) YYERROR; }
#line 10089 "core/cfg.tab.c"
    break;

  case 624: /* preprocess_stm: SUBSTDEF error  */
#line 2546 "core/cfg.y"
                         { yyerror("invalid substdef preprocess statement"); }
#line 10095 "core/cfg.tab.c"
    break;

  case 625: /* preprocess_stm: SUBSTDEFS STRING  */
#line 2547 "core/cfg.y"
                           { if(pp_substdef_add((yyvsp[0].strval), KSR_PPDEF_QUOTED)<0) YYERROR; }
#line 10101 "core/cfg.tab.c"
    break;

  case 626: /* preprocess_stm: SUBSTDEFS error  */
#line 2548 "core/cfg.y"
                          { yyerror("invalid substdefs preprocess statement"); }
#line 10107 "core/cfg.tab.c"
    break;

  case 627: /* equalop: EQUAL_T  */
#line 2570 "core/cfg.y"
                {(yyval.intval)=EQUAL_OP; }
#line 10113 "core/cfg.tab.c"
    break;

  case 628: /* equalop: DIFF  */
#line 2571 "core/cfg.y"
                {(yyval.intval)=DIFF_OP; }
#line 10119 "core/cfg.tab.c"
    break;

  case 629: /* equalop: STREQ  */
#line 2572 "core/cfg.y"
                {(yyval.intval)=EQUAL_OP; }
#line 10125 "core/cfg.tab.c"
    break;

  case 630: /* equalop: STRDIFF  */
#line 2573 "core/cfg.y"
                  {(yyval.intval)=DIFF_OP; }
#line 10131 "core/cfg.tab.c"
    break;

  case 631: /* cmpop: GT  */
#line 2576 "core/cfg.y"
                {(yyval.intval)=GT_OP; }
#line 10137 "core/cfg.tab.c"
    break;

  case 632: /* cmpop: LT  */
#line 2577 "core/cfg.y"
                {(yyval.intval)=LT_OP; }
#line 10143 "core/cfg.tab.c"
    break;

  case 633: /* cmpop: GTE  */
#line 2578 "core/cfg.y"
                {(yyval.intval)=GTE_OP; }
#line 10149 "core/cfg.tab.c"
    break;

  case 634: /* cmpop: LTE  */
#line 2579 "core/cfg.y"
                {(yyval.intval)=LTE_OP; }
#line 10155 "core/cfg.tab.c"
    break;

  case 635: /* strop: equalop  */
#line 2582 "core/cfg.y"
                {(yyval.intval)=(yyvsp[0].intval); }
#line 10161 "core/cfg.tab.c"
    break;

  case 636: /* strop: MATCH  */
#line 2583 "core/cfg.y"
                {(yyval.intval)=MATCH_OP; }
#line 10167 "core/cfg.tab.c"
    break;

  case 637: /* rve_equalop: EQUAL_T  */
#line 2589 "core/cfg.y"
                {(yyval.intval)=RVE_EQ_OP; }
#line 10173 "core/cfg.tab.c"
    break;

  case 638: /* rve_equalop: DIFF  */
#line 2590 "core/cfg.y"
                {(yyval.intval)=RVE_DIFF_OP; }
#line 10179 "core/cfg.tab.c"
    break;

  case 639: /* rve_equalop: INTEQ  */
#line 2591 "core/cfg.y"
                {(yyval.intval)=RVE_IEQ_OP; }
#line 10185 "core/cfg.tab.c"
    break;

  case 640: /* rve_equalop: INTDIFF  */
#line 2592 "core/cfg.y"
                  {(yyval.intval)=RVE_IDIFF_OP; }
#line 10191 "core/cfg.tab.c"
    break;

  case 641: /* rve_equalop: STREQ  */
#line 2593 "core/cfg.y"
                {(yyval.intval)=RVE_STREQ_OP; }
#line 10197 "core/cfg.tab.c"
    break;

  case 642: /* rve_equalop: STRDIFF  */
#line 2594 "core/cfg.y"
                  {(yyval.intval)=RVE_STRDIFF_OP; }
#line 10203 "core/cfg.tab.c"
    break;

  case 643: /* rve_equalop: MATCH  */
#line 2595 "core/cfg.y"
                {(yyval.intval)=RVE_MATCH_OP; }
#line 10209 "core/cfg.tab.c"
    break;

  case 644: /* rve_cmpop: GT  */
#line 2598 "core/cfg.y"
                {(yyval.intval)=RVE_GT_OP; }
#line 10215 "core/cfg.tab.c"
    break;

  case 645: /* rve_cmpop: LT  */
#line 2599 "core/cfg.y"
                {(yyval.intval)=RVE_LT_OP; }
#line 10221 "core/cfg.tab.c"
    break;

  case 646: /* rve_cmpop: GTE  */
#line 2600 "core/cfg.y"
                {(yyval.intval)=RVE_GTE_OP; }
#line 10227 "core/cfg.tab.c"
    break;

  case 647: /* rve_cmpop: LTE  */
#line 2601 "core/cfg.y"
                {(yyval.intval)=RVE_LTE_OP; }
#line 10233 "core/cfg.tab.c"
    break;

  case 648: /* uri_type: URI  */
#line 2608 "core/cfg.y"
                        {(yyval.intval)=URI_O;}
#line 10239 "core/cfg.tab.c"
    break;

  case 649: /* uri_type: FROM_URI  */
#line 2609 "core/cfg.y"
                        {(yyval.intval)=FROM_URI_O;}
#line 10245 "core/cfg.tab.c"
    break;

  case 650: /* uri_type: TO_URI  */
#line 2610 "core/cfg.y"
                        {(yyval.intval)=TO_URI_O;}
#line 10251 "core/cfg.tab.c"
    break;

  case 651: /* eint_op_onsend: SNDPORT  */
#line 2617 "core/cfg.y"
                                        { (yyval.intval)=SNDPORT_O; }
#line 10257 "core/cfg.tab.c"
    break;

  case 652: /* eint_op_onsend: TOPORT  */
#line 2618 "core/cfg.y"
                                        { (yyval.intval)=TOPORT_O; }
#line 10263 "core/cfg.tab.c"
    break;

  case 653: /* eint_op_onsend: SNDAF  */
#line 2619 "core/cfg.y"
                                        { (yyval.intval)=SNDAF_O; }
#line 10269 "core/cfg.tab.c"
    break;

  case 654: /* eint_op: SRCPORT  */
#line 2623 "core/cfg.y"
                                { (yyval.intval)=SRCPORT_O; }
#line 10275 "core/cfg.tab.c"
    break;

  case 655: /* eint_op: DSTPORT  */
#line 2624 "core/cfg.y"
                                        { (yyval.intval)=DSTPORT_O; }
#line 10281 "core/cfg.tab.c"
    break;

  case 656: /* eint_op: AF  */
#line 2625 "core/cfg.y"
                                                { (yyval.intval)=AF_O; }
#line 10287 "core/cfg.tab.c"
    break;

  case 657: /* eint_op: MSGLEN  */
#line 2626 "core/cfg.y"
                                        { (yyval.intval)=MSGLEN_O; }
#line 10293 "core/cfg.tab.c"
    break;

  case 659: /* eip_op_onsend: SNDIP  */
#line 2632 "core/cfg.y"
                                        { onsend_check("snd_ip"); (yyval.intval)=SNDIP_O; }
#line 10299 "core/cfg.tab.c"
    break;

  case 660: /* eip_op_onsend: TOIP  */
#line 2633 "core/cfg.y"
                                        { onsend_check("to_ip");  (yyval.intval)=TOIP_O; }
#line 10305 "core/cfg.tab.c"
    break;

  case 661: /* eip_op: SRCIP  */
#line 2636 "core/cfg.y"
                                { (yyval.intval)=SRCIP_O; }
#line 10311 "core/cfg.tab.c"
    break;

  case 662: /* eip_op: DSTIP  */
#line 2637 "core/cfg.y"
                                        { (yyval.intval)=DSTIP_O; }
#line 10317 "core/cfg.tab.c"
    break;

  case 664: /* exp_elem: METHOD strop rval_expr  */
#line 2645 "core/cfg.y"
                {(yyval.expr)= mk_elem((yyvsp[-1].intval), METHOD_O, 0, RVE_ST, (yyvsp[0].rv_expr));}
#line 10323 "core/cfg.tab.c"
    break;

  case 665: /* exp_elem: METHOD strop ID  */
#line 2647 "core/cfg.y"
                {(yyval.expr) = mk_elem((yyvsp[-1].intval), METHOD_O, 0, STRING_ST,(yyvsp[0].strval)); }
#line 10329 "core/cfg.tab.c"
    break;

  case 666: /* exp_elem: METHOD strop error  */
#line 2648 "core/cfg.y"
                             { (yyval.expr)=0; yyerror("string expected"); }
#line 10335 "core/cfg.tab.c"
    break;

  case 667: /* exp_elem: METHOD error  */
#line 2650 "core/cfg.y"
                { (yyval.expr)=0; yyerror("invalid operator,== , !=, or =~ expected"); }
#line 10341 "core/cfg.tab.c"
    break;

  case 668: /* exp_elem: uri_type strop rval_expr  */
#line 2652 "core/cfg.y"
                {(yyval.expr) = mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr)); }
#line 10347 "core/cfg.tab.c"
    break;

  case 669: /* exp_elem: uri_type strop MYSELF  */
#line 2654 "core/cfg.y"
                {(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 10353 "core/cfg.tab.c"
    break;

  case 670: /* exp_elem: uri_type strop error  */
#line 2656 "core/cfg.y"
                { (yyval.expr)=0; yyerror("string or MYSELF expected"); }
#line 10359 "core/cfg.tab.c"
    break;

  case 671: /* exp_elem: uri_type error  */
#line 2658 "core/cfg.y"
                { (yyval.expr)=0; yyerror("invalid operator, == , != or =~ expected"); }
#line 10365 "core/cfg.tab.c"
    break;

  case 672: /* exp_elem: eint_op cmpop rval_expr  */
#line 2659 "core/cfg.y"
                                           { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 10371 "core/cfg.tab.c"
    break;

  case 673: /* exp_elem: eint_op equalop rval_expr  */
#line 2661 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 10377 "core/cfg.tab.c"
    break;

  case 674: /* exp_elem: eint_op cmpop error  */
#line 2662 "core/cfg.y"
                                { (yyval.expr)=0; yyerror("number expected"); }
#line 10383 "core/cfg.tab.c"
    break;

  case 675: /* exp_elem: eint_op equalop error  */
#line 2663 "core/cfg.y"
                                { (yyval.expr)=0; yyerror("number expected"); }
#line 10389 "core/cfg.tab.c"
    break;

  case 676: /* exp_elem: eint_op error  */
#line 2664 "core/cfg.y"
                        { (yyval.expr)=0; yyerror("==, !=, <,>, >= or <=  expected"); }
#line 10395 "core/cfg.tab.c"
    break;

  case 677: /* exp_elem: PROTO equalop eqproto  */
#line 2666 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 10401 "core/cfg.tab.c"
    break;

  case 678: /* exp_elem: PROTO equalop rval_expr  */
#line 2668 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), PROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 10407 "core/cfg.tab.c"
    break;

  case 679: /* exp_elem: PROTO equalop error  */
#line 2670 "core/cfg.y"
                { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 10413 "core/cfg.tab.c"
    break;

  case 680: /* exp_elem: SNDPROTO equalop eqproto  */
#line 2672 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, NUMBER_ST, (void*)(yyvsp[0].intval) ); }
#line 10419 "core/cfg.tab.c"
    break;

  case 681: /* exp_elem: SNDPROTO equalop rval_expr  */
#line 2674 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), SNDPROTO_O, 0, RVE_ST, (yyvsp[0].rv_expr) ); }
#line 10425 "core/cfg.tab.c"
    break;

  case 682: /* exp_elem: SNDPROTO equalop error  */
#line 2676 "core/cfg.y"
                { (yyval.expr)=0; yyerror("protocol expected (udp, tcp, tls, sctp, ws, or wss)"); }
#line 10431 "core/cfg.tab.c"
    break;

  case 683: /* exp_elem: eip_op strop ipnet  */
#line 2677 "core/cfg.y"
                                           { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST, (yyvsp[0].ipnet)); }
#line 10437 "core/cfg.tab.c"
    break;

  case 684: /* exp_elem: eip_op strop rval_expr  */
#line 2678 "core/cfg.y"
                                               {
			s_tmp.s=0;
			(yyval.expr)=0;
			if (rve_is_constant((yyvsp[0].rv_expr))){
				i_tmp=rve_guess_type((yyvsp[0].rv_expr));
				if (i_tmp==RV_LONG)
					yyerror("string expected");
				else if (i_tmp==RV_STR){
					if (((rval_tmp=rval_expr_eval(0, 0, (yyvsp[0].rv_expr)))==0) ||
								(rval_get_str(0, 0, &s_tmp, rval_tmp, 0)<0)){
						rval_destroy(rval_tmp);
						yyerror("bad rvalue expression");
					}else{
						rval_destroy(rval_tmp);
					}
				}else{
					yyerror("BUG: unexpected dynamic type");
				}
			}else{
					/* warn("non constant rvalue in ip comparison") */;
			}
			if (s_tmp.s){
				ip_tmp=str2ip(&s_tmp);
				if (ip_tmp==0)
					ip_tmp=str2ip6(&s_tmp);
				pkg_free(s_tmp.s);
				if (ip_tmp) {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, NET_ST,
								mk_new_net_bitlen(ip_tmp, ip_tmp->len*8) );
				} else {
					(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
				}
			}else{
				(yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, RVE_ST, (yyvsp[0].rv_expr));
			}
		}
#line 10478 "core/cfg.tab.c"
    break;

  case 685: /* exp_elem: eip_op strop host  */
#line 2715 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, STRING_ST, (yyvsp[0].strval)); }
#line 10484 "core/cfg.tab.c"
    break;

  case 686: /* exp_elem: eip_op strop MYSELF  */
#line 2717 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[-2].intval), 0, MYSELF_ST, 0); }
#line 10490 "core/cfg.tab.c"
    break;

  case 687: /* exp_elem: eip_op strop error  */
#line 2719 "core/cfg.y"
                { (yyval.expr)=0; yyerror( "ip address or hostname expected" ); }
#line 10496 "core/cfg.tab.c"
    break;

  case 688: /* exp_elem: eip_op error  */
#line 2721 "core/cfg.y"
                { (yyval.expr)=0; yyerror("invalid operator, ==, != or =~ expected");}
#line 10502 "core/cfg.tab.c"
    break;

  case 689: /* exp_elem: MYSELF equalop uri_type  */
#line 2724 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 10508 "core/cfg.tab.c"
    break;

  case 690: /* exp_elem: MYSELF equalop eip_op  */
#line 2726 "core/cfg.y"
                { (yyval.expr)=mk_elem((yyvsp[-1].intval), (yyvsp[0].intval), 0, MYSELF_ST, 0); }
#line 10514 "core/cfg.tab.c"
    break;

  case 691: /* exp_elem: MYSELF equalop error  */
#line 2728 "core/cfg.y"
                { (yyval.expr)=0; yyerror("URI, SRCIP or DSTIP expected"); }
#line 10520 "core/cfg.tab.c"
    break;

  case 692: /* exp_elem: MYSELF error  */
#line 2729 "core/cfg.y"
                        { (yyval.expr)=0; yyerror ("invalid operator, == or != expected"); }
#line 10526 "core/cfg.tab.c"
    break;

  case 693: /* ipnet: ip SLASH ip  */
#line 2733 "core/cfg.y"
                        { (yyval.ipnet)=mk_new_net((yyvsp[-2].ipaddr), (yyvsp[0].ipaddr)); }
#line 10532 "core/cfg.tab.c"
    break;

  case 694: /* ipnet: ip SLASH NUMBER  */
#line 2734 "core/cfg.y"
                          {
		if (((yyvsp[0].intval)<0) || ((yyvsp[0].intval)>(yyvsp[-2].ipaddr)->len*8)) {
			yyerror("invalid bit number in netmask");
			(yyval.ipnet)=0;
		} else {
			(yyval.ipnet)=mk_new_net_bitlen((yyvsp[-2].ipaddr), (yyvsp[0].intval));
		/*
			$$=mk_new_net($1, htonl( ($3)?~( (1<<(32-$3))-1 ):0 ) );
		*/
		}
	}
#line 10548 "core/cfg.tab.c"
    break;

  case 695: /* ipnet: ip  */
#line 2745 "core/cfg.y"
                { (yyval.ipnet)=mk_new_net_bitlen((yyvsp[0].ipaddr), (yyvsp[0].ipaddr)->len*8); }
#line 10554 "core/cfg.tab.c"
    break;

  case 696: /* ipnet: ip SLASH error  */
#line 2746 "core/cfg.y"
                         { (yyval.ipnet)=0; yyerror("netmask (eg:255.0.0.0 or 8) expected"); }
#line 10560 "core/cfg.tab.c"
    break;

  case 697: /* host: ID  */
#line 2750 "core/cfg.y"
           { (yyval.strval)=(yyvsp[0].strval); }
#line 10566 "core/cfg.tab.c"
    break;

  case 698: /* host: host DOT ID  */
#line 2751 "core/cfg.y"
                      {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 10586 "core/cfg.tab.c"
    break;

  case 699: /* host: host MINUS ID  */
#line 2766 "core/cfg.y"
                        {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 10606 "core/cfg.tab.c"
    break;

  case 700: /* host: host DOT error  */
#line 2781 "core/cfg.y"
                         { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 10612 "core/cfg.tab.c"
    break;

  case 701: /* host: host MINUS error  */
#line 2782 "core/cfg.y"
                           { (yyval.strval)=0; pkg_free((yyvsp[-2].strval)); yyerror("invalid hostname"); }
#line 10618 "core/cfg.tab.c"
    break;

  case 704: /* host_if_id: NUMBER  */
#line 2787 "core/cfg.y"
                         {
			/* get string version */
			i_tmp = strlen(yy_number_str);
			(yyval.strval)=pkg_malloc(i_tmp + 1);
			if ((yyval.strval)==0) {
				PKG_MEM_ERROR;
			} else {
				memcpy((yyval.strval), yy_number_str, i_tmp);
				(yyval.strval)[i_tmp] = '\0';
			}
		}
#line 10634 "core/cfg.tab.c"
    break;

  case 705: /* host_or_if: host_if_id  */
#line 2801 "core/cfg.y"
                   { (yyval.strval)=(yyvsp[0].strval); }
#line 10640 "core/cfg.tab.c"
    break;

  case 706: /* host_or_if: host_or_if DOT host_if_id  */
#line 2802 "core/cfg.y"
                                    {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='.';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 10660 "core/cfg.tab.c"
    break;

  case 707: /* host_or_if: host_or_if MINUS host_if_id  */
#line 2817 "core/cfg.y"
                                      {
		if ((yyvsp[-2].strval)){
			(yyval.strval)=(char*)pkg_malloc(strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))+1);
			if ((yyval.strval)==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy((yyval.strval), (yyvsp[-2].strval), strlen((yyvsp[-2].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))]='-';
				memcpy((yyval.strval)+strlen((yyvsp[-2].strval))+1, (yyvsp[0].strval), strlen((yyvsp[0].strval)));
				(yyval.strval)[strlen((yyvsp[-2].strval))+1+strlen((yyvsp[0].strval))]=0;
			}
			pkg_free((yyvsp[-2].strval));
		}
		if ((yyvsp[0].strval)) pkg_free((yyvsp[0].strval));
	}
#line 10680 "core/cfg.tab.c"
    break;

  case 708: /* host_or_if: host_or_if DOT error  */
#line 2832 "core/cfg.y"
                               { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 10687 "core/cfg.tab.c"
    break;

  case 709: /* host_or_if: host_or_if MINUS error  */
#line 2834 "core/cfg.y"
                                 { (yyval.strval)=0; pkg_free((yyvsp[-2].strval));
								yyerror("invalid host or interface name"); }
#line 10694 "core/cfg.tab.c"
    break;

  case 710: /* fcmd: cmd  */
#line 2841 "core/cfg.y"
            {
		/* check if allowed */
		if ((yyvsp[0].action) && rt==ONSEND_ROUTE) {
			switch((yyvsp[0].action)->type) {
				case DROP_T:
				case LOG_T:
				case SETFLAG_T:
				case RESETFLAG_T:
				case ISFLAGSET_T:
				case IF_T:
				case MODULE0_T:
				case MODULE1_T:
				case MODULE2_T:
				case MODULE3_T:
				case MODULE4_T:
				case MODULE5_T:
				case MODULE6_T:
				case MODULEX_T:
				case SET_FWD_NO_CONNECT_T:
				case SET_RPL_NO_CONNECT_T:
				case SET_FWD_CLOSE_T:
				case SET_RPL_CLOSE_T:
					(yyval.action)=(yyvsp[0].action);
					break;
				default:
					(yyval.action)=0;
					yyerror("command not allowed in onsend_route\n");
			}
		} else {
			(yyval.action)=(yyvsp[0].action);
		}
	}
#line 10731 "core/cfg.tab.c"
    break;

  case 711: /* stm: action  */
#line 2883 "core/cfg.y"
                { (yyval.action)=(yyvsp[0].action); }
#line 10737 "core/cfg.tab.c"
    break;

  case 712: /* stm: LBRACE actions RBRACE  */
#line 2884 "core/cfg.y"
                                { (yyval.action)=(yyvsp[-1].action); }
#line 10743 "core/cfg.tab.c"
    break;

  case 713: /* actions: actions action  */
#line 2887 "core/cfg.y"
                        {(yyval.action)=append_action((yyvsp[-1].action), (yyvsp[0].action)); }
#line 10749 "core/cfg.tab.c"
    break;

  case 714: /* actions: action  */
#line 2888 "core/cfg.y"
                        {(yyval.action)=(yyvsp[0].action);}
#line 10755 "core/cfg.tab.c"
    break;

  case 715: /* actions: actions error  */
#line 2889 "core/cfg.y"
                        { (yyval.action)=0; yyerror("bad command"); }
#line 10761 "core/cfg.tab.c"
    break;

  case 716: /* action: fcmd SEMICOLON  */
#line 2892 "core/cfg.y"
                       {(yyval.action)=(yyvsp[-1].action);}
#line 10767 "core/cfg.tab.c"
    break;

  case 717: /* action: if_cmd  */
#line 2893 "core/cfg.y"
                 {(yyval.action)=(yyvsp[0].action);}
#line 10773 "core/cfg.tab.c"
    break;

  case 718: /* action: switch_cmd  */
#line 2894 "core/cfg.y"
                     {(yyval.action)=(yyvsp[0].action);}
#line 10779 "core/cfg.tab.c"
    break;

  case 719: /* action: while_cmd  */
#line 2895 "core/cfg.y"
                    { (yyval.action)=(yyvsp[0].action); }
#line 10785 "core/cfg.tab.c"
    break;

  case 720: /* action: ret_cmd SEMICOLON  */
#line 2896 "core/cfg.y"
                            { (yyval.action)=(yyvsp[-1].action); }
#line 10791 "core/cfg.tab.c"
    break;

  case 721: /* action: assign_action SEMICOLON  */
#line 2897 "core/cfg.y"
                                  {(yyval.action)=(yyvsp[-1].action);}
#line 10797 "core/cfg.tab.c"
    break;

  case 722: /* action: SEMICOLON  */
#line 2898 "core/cfg.y"
                                      {(yyval.action)=0;}
#line 10803 "core/cfg.tab.c"
    break;

  case 723: /* action: fcmd error  */
#line 2899 "core/cfg.y"
                     { (yyval.action)=0; yyerror("bad command: missing ';'?"); }
#line 10809 "core/cfg.tab.c"
    break;

  case 724: /* if_cmd: IF rval_expr stm  */
#line 2902 "core/cfg.y"
                                {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action), NOSUBTYPE, 0);
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 10822 "core/cfg.tab.c"
    break;

  case 725: /* if_cmd: IF rval_expr stm ELSE stm  */
#line 2910 "core/cfg.y"
                                        {
		if ((yyvsp[-3].rv_expr) && rval_expr_int_check((yyvsp[-3].rv_expr))>=0){
			warn_ct_rve((yyvsp[-3].rv_expr), "if");
			(yyval.action)=mk_action( IF_T, 3, RVE_ST, (yyvsp[-3].rv_expr), ACTIONS_ST, (yyvsp[-2].action), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else
			YYERROR;
	}
#line 10835 "core/cfg.tab.c"
    break;

  case 726: /* ct_rval: rval_expr  */
#line 2920 "core/cfg.y"
                   {
			(yyval.rv_expr)=0;
			if ((yyvsp[0].rv_expr) && !rve_is_constant((yyvsp[0].rv_expr))){
				yyerror("constant expected");
				YYERROR;
			/*
			} else if ($1 &&
						!rve_check_type((enum rval_type*)&i_tmp, $1, 0, 0 ,0)){
				yyerror("invalid expression (bad type)");
			}else if ($1 && i_tmp!=RV_LONG){
				yyerror("invalid expression type, int expected\n");
			*/
			}else
				(yyval.rv_expr)=(yyvsp[0].rv_expr);
		}
#line 10855 "core/cfg.tab.c"
    break;

  case 727: /* single_case: CASE ct_rval COLON actions  */
#line 2937 "core/cfg.y"
                                   {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10867 "core/cfg.tab.c"
    break;

  case 728: /* single_case: CASE SLASH ct_rval COLON actions  */
#line 2944 "core/cfg.y"
                                   {
		(yyval.case_stms)=0;
		if ((yyvsp[-2].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-2].rv_expr), 1, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10879 "core/cfg.tab.c"
    break;

  case 729: /* single_case: CASE ct_rval COLON  */
#line 2951 "core/cfg.y"
                             {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10891 "core/cfg.tab.c"
    break;

  case 730: /* single_case: CASE SLASH ct_rval COLON  */
#line 2958 "core/cfg.y"
                                   {
		(yyval.case_stms)=0;
		if ((yyvsp[-1].rv_expr)==0) { yyerror ("bad regex case label"); YYERROR; }
		else if ((((yyval.case_stms)=mk_case_stm((yyvsp[-1].rv_expr), 1, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10903 "core/cfg.tab.c"
    break;

  case 731: /* single_case: DEFAULT COLON actions  */
#line 2965 "core/cfg.y"
                                {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, (yyvsp[0].action), &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10913 "core/cfg.tab.c"
    break;

  case 732: /* single_case: DEFAULT COLON  */
#line 2970 "core/cfg.y"
                        {
		if ((((yyval.case_stms)=mk_case_stm(0, 0, 0, &i_tmp))==0) && (i_tmp==-10)){
				YYABORT;
		}
	}
#line 10923 "core/cfg.tab.c"
    break;

  case 733: /* single_case: CASE error COLON actions  */
#line 2975 "core/cfg.y"
                                   { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 10929 "core/cfg.tab.c"
    break;

  case 734: /* single_case: CASE SLASH error COLON actions  */
#line 2976 "core/cfg.y"
                                         { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 10935 "core/cfg.tab.c"
    break;

  case 735: /* single_case: CASE error COLON  */
#line 2977 "core/cfg.y"
                           { (yyval.case_stms)=0; yyerror("bad case label"); }
#line 10941 "core/cfg.tab.c"
    break;

  case 736: /* single_case: CASE SLASH error COLON  */
#line 2978 "core/cfg.y"
                                 { (yyval.case_stms)=0; yyerror("bad case regex label"); }
#line 10947 "core/cfg.tab.c"
    break;

  case 737: /* single_case: CASE ct_rval COLON error  */
#line 2979 "core/cfg.y"
                                   { (yyval.case_stms)=0; yyerror ("bad case body"); }
#line 10953 "core/cfg.tab.c"
    break;

  case 738: /* case_stms: case_stms single_case  */
#line 2982 "core/cfg.y"
                              {
		(yyval.case_stms)=(yyvsp[-1].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		if ((yyval.case_stms)){
			*((yyval.case_stms)->append)=(yyvsp[0].case_stms);
			if (*((yyval.case_stms)->append)!=0)
				(yyval.case_stms)->append=&((*((yyval.case_stms)->append))->next);
		}
	}
#line 10967 "core/cfg.tab.c"
    break;

  case 739: /* case_stms: single_case  */
#line 2991 "core/cfg.y"
                      {
		(yyval.case_stms)=(yyvsp[0].case_stms);
		if ((yyvsp[0].case_stms)==0) yyerror ("bad case");
		else (yyval.case_stms)->append=&((yyval.case_stms)->next);
	}
#line 10977 "core/cfg.tab.c"
    break;

  case 740: /* switch_cmd: SWITCH rval_expr LBRACE case_stms RBRACE  */
#line 2998 "core/cfg.y"
                                                   {
		(yyval.action)=0;
		if ((yyvsp[-3].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else if ((yyvsp[-1].case_stms)==0){
			yyerror ("bad switch body");
			YYERROR;
		}else if (case_check_default((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): too many "
							"\"default:\" labels\n");
			YYERROR;
		}else if (case_check_type((yyvsp[-1].case_stms))!=0){
			yyerror_at(&(yyvsp[-3].rv_expr)->fpos, "bad switch(): mixed integer and"
							" string/RE cases not allowed\n");
			YYERROR;
		}else{
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-3].rv_expr), CASE_ST, (yyvsp[-1].case_stms));
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 11007 "core/cfg.tab.c"
    break;

  case 741: /* switch_cmd: SWITCH rval_expr LBRACE RBRACE  */
#line 3023 "core/cfg.y"
                                         {
		(yyval.action)=0;
		warn("empty switch()");
		if ((yyvsp[-2].rv_expr)==0){
			yyerror("bad expression in switch(...)");
			YYERROR;
		}else{
			/* it might have sideffects, so leave it for the optimizer */
			(yyval.action)=mk_action(SWITCH_T, 2, RVE_ST, (yyvsp[-2].rv_expr), CASE_ST, 0);
			if ((yyval.action)==0) {
				yyerror("internal error");
				YYABORT;
			}
			set_cfg_pos((yyval.action));
		}
	}
#line 11028 "core/cfg.tab.c"
    break;

  case 742: /* switch_cmd: SWITCH error  */
#line 3039 "core/cfg.y"
                       { (yyval.action)=0; yyerror ("bad expression in switch(...)"); }
#line 11034 "core/cfg.tab.c"
    break;

  case 743: /* switch_cmd: SWITCH rval_expr LBRACE error RBRACE  */
#line 3041 "core/cfg.y"
                {(yyval.action)=0; yyerror ("bad switch body"); }
#line 11040 "core/cfg.tab.c"
    break;

  case 744: /* while_cmd: WHILE rval_expr stm  */
#line 3045 "core/cfg.y"
                            {
		if ((yyvsp[-1].rv_expr) && rval_expr_int_check((yyvsp[-1].rv_expr))>=0){
			warn_ct_rve((yyvsp[-1].rv_expr), "while");
			(yyval.action)=mk_action( WHILE_T, 2, RVE_ST, (yyvsp[-1].rv_expr), ACTIONS_ST, (yyvsp[0].action));
			set_cfg_pos((yyval.action));
		}else{
			yyerror_at(&(yyvsp[-1].rv_expr)->fpos, "bad while(...) expression");
			YYERROR;
		}
	}
#line 11055 "core/cfg.tab.c"
    break;

  case 745: /* select_param: ID  */
#line 3064 "core/cfg.y"
           {
		if (sel.n >= MAX_SELECT_PARAMS-1) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[0].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[0].strval));
		sel.n++;
	}
#line 11069 "core/cfg.tab.c"
    break;

  case 746: /* select_param: ID LBRACK intno RBRACK  */
#line 3073 "core/cfg.y"
                                 {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_INT;
		sel.params[sel.n].v.i = (yyvsp[-1].intval);
		sel.n++;
	}
#line 11086 "core/cfg.tab.c"
    break;

  case 747: /* select_param: ID LBRACK STRING RBRACK  */
#line 3085 "core/cfg.y"
                                  {
		if (sel.n >= MAX_SELECT_PARAMS-2) {
			yyerror("Select identifier too long\n");
		}
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-3].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-3].strval));
		sel.n++;
		sel.params[sel.n].type = SEL_PARAM_STR;
		sel.params[sel.n].v.s.s = (yyvsp[-1].strval);
		sel.params[sel.n].v.s.len = strlen((yyvsp[-1].strval));
		sel.n++;
	}
#line 11104 "core/cfg.tab.c"
    break;

  case 750: /* $@9: %empty  */
#line 3104 "core/cfg.y"
                    { sel.n = 0; sel.f[0] = 0; }
#line 11110 "core/cfg.tab.c"
    break;

  case 751: /* select_id: SELECT_MARK $@9 select_params  */
#line 3104 "core/cfg.y"
                                                               {
		sel_ptr = (select_t*)pkg_malloc(sizeof(select_t));
		if (!sel_ptr) {
			yyerror("No memory left to allocate select structure\n");
		}
		memcpy(sel_ptr, &sel, sizeof(select_t));
		(yyval.select) = sel_ptr;
	}
#line 11123 "core/cfg.tab.c"
    break;

  case 752: /* attr_class_spec: ATTR_FROM  */
#line 3114 "core/cfg.y"
                  { s_attr->type |= AVP_TRACK_FROM; }
#line 11129 "core/cfg.tab.c"
    break;

  case 753: /* attr_class_spec: ATTR_TO  */
#line 3115 "core/cfg.y"
                  { s_attr->type |= AVP_TRACK_TO; }
#line 11135 "core/cfg.tab.c"
    break;

  case 754: /* attr_class_spec: ATTR_FROMURI  */
#line 3116 "core/cfg.y"
                       { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_URI; }
#line 11141 "core/cfg.tab.c"
    break;

  case 755: /* attr_class_spec: ATTR_TOURI  */
#line 3117 "core/cfg.y"
                     { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_URI; }
#line 11147 "core/cfg.tab.c"
    break;

  case 756: /* attr_class_spec: ATTR_FROMUSER  */
#line 3118 "core/cfg.y"
                        { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_USER; }
#line 11153 "core/cfg.tab.c"
    break;

  case 757: /* attr_class_spec: ATTR_TOUSER  */
#line 3119 "core/cfg.y"
                      { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_USER; }
#line 11159 "core/cfg.tab.c"
    break;

  case 758: /* attr_class_spec: ATTR_FROMDOMAIN  */
#line 3120 "core/cfg.y"
                          { s_attr->type |= AVP_TRACK_FROM | AVP_CLASS_DOMAIN; }
#line 11165 "core/cfg.tab.c"
    break;

  case 759: /* attr_class_spec: ATTR_TODOMAIN  */
#line 3121 "core/cfg.y"
                        { s_attr->type |= AVP_TRACK_TO | AVP_CLASS_DOMAIN; }
#line 11171 "core/cfg.tab.c"
    break;

  case 760: /* attr_class_spec: ATTR_GLOBAL  */
#line 3122 "core/cfg.y"
                      { s_attr->type |= AVP_TRACK_ALL | AVP_CLASS_GLOBAL; }
#line 11177 "core/cfg.tab.c"
    break;

  case 761: /* attr_name_spec: ID  */
#line 3125 "core/cfg.y"
           { s_attr->type |= AVP_NAME_STR; s_attr->name.s.s = (yyvsp[0].strval); s_attr->name.s.len = strlen ((yyvsp[0].strval)); }
#line 11183 "core/cfg.tab.c"
    break;

  case 764: /* attr_mark: ATTR_MARK  */
#line 3132 "core/cfg.y"
                  {
		s_attr = (struct avp_spec*)pkg_malloc(sizeof(struct avp_spec));
		if (!s_attr) { yyerror("No memory left"); YYABORT; }
		else { memset(s_attr, 0, (sizeof(struct avp_spec))); }
	}
#line 11193 "core/cfg.tab.c"
    break;

  case 765: /* attr_id: attr_mark attr_spec  */
#line 3139 "core/cfg.y"
                            { (yyval.attr) = s_attr; }
#line 11199 "core/cfg.tab.c"
    break;

  case 766: /* attr_id_num_idx: attr_mark attr_spec LBRACK intno RBRACK  */
#line 3142 "core/cfg.y"
                                                {
		s_attr->type|= (AVP_NAME_STR | ((yyvsp[-1].intval)<0?AVP_INDEX_BACKWARD:AVP_INDEX_FORWARD));
		s_attr->index = ((yyvsp[-1].intval)<0?-(yyvsp[-1].intval):(yyvsp[-1].intval));
		(yyval.attr) = s_attr;
	}
#line 11209 "core/cfg.tab.c"
    break;

  case 767: /* attr_id_no_idx: attr_mark attr_spec LBRACK RBRACK  */
#line 3149 "core/cfg.y"
                                          {
		s_attr->type|= AVP_INDEX_ALL;
		(yyval.attr) = s_attr;
	}
#line 11218 "core/cfg.tab.c"
    break;

  case 774: /* attr_id_any_str: avp_pvar  */
#line 3171 "core/cfg.y"
                   {
		if ((yyvsp[0].lval)->type==LV_AVP){
			s_attr = pkg_malloc(sizeof(struct avp_spec));
			if (!s_attr) { yyerror("No memory left"); YYABORT; }
			else{
				*s_attr=(yyvsp[0].lval)->lv.avps;
			}
			(yyval.attr)=s_attr;
		}else
			(yyval.attr)=0; /* not an avp, a pvar */
		pkg_free((yyvsp[0].lval));
	}
#line 11235 "core/cfg.tab.c"
    break;

  case 775: /* attr_id_any_str: STRING  */
#line 3183 "core/cfg.y"
                 {
		avp_spec_t *avp_spec;
		str s;
		int type, idx;
		avp_spec = pkg_malloc(sizeof(*avp_spec));
		if (!avp_spec) {
			yyerror("Not enough memory");
			YYABORT;
		}
		s.s = (yyvsp[0].strval);
		if (s.s[0] == '$')
			s.s++;
		s.len = strlen(s.s);
		if (parse_avp_name(&s, &type, &avp_spec->name, &idx)) {
			yyerror("error when parsing AVP");
			pkg_free(avp_spec);
			YYABORT;
		}
		avp_spec->type = type;
		avp_spec->index = idx;
		(yyval.attr) = avp_spec;
	}
#line 11262 "core/cfg.tab.c"
    break;

  case 776: /* pvar: PVAR  */
#line 3207 "core/cfg.y"
             {
			s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
			pv_spec=pv_cache_get(&s_tmp);
			if (!pv_spec) {
				yyerror("Can't get from cache: %s", (yyvsp[0].strval));
				YYABORT;
			}
			(yyval.pvar)=pv_spec;
		}
#line 11276 "core/cfg.tab.c"
    break;

  case 777: /* avp_pvar: AVP_OR_PVAR  */
#line 3218 "core/cfg.y"
                            {
				lval_tmp=pkg_malloc(sizeof(*lval_tmp));
				if (!lval_tmp) {
					yyerror("Not enough memory");
					YYABORT;
				}
				memset(lval_tmp, 0, sizeof(*lval_tmp));
				s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen(s_tmp.s);
				lval_tmp->lv.pvs = pv_cache_get(&s_tmp);
				if (lval_tmp->lv.pvs==NULL){
					lval_tmp->lv.avps.type|= AVP_NAME_STR;
					lval_tmp->lv.avps.name.s.s = s_tmp.s+1;
					lval_tmp->lv.avps.name.s.len = s_tmp.len-1;
					lval_tmp->type=LV_AVP;
				}else{
					lval_tmp->type=LV_PVAR;
				}
				(yyval.lval) = lval_tmp;
				DBG("parsed ambiguous avp/pvar \"%.*s\" to %d\n",
							s_tmp.len, s_tmp.s, lval_tmp->type);
			}
#line 11302 "core/cfg.tab.c"
    break;

  case 778: /* assign_op: EQUAL  */
#line 3249 "core/cfg.y"
              { (yyval.intval) = ASSIGN_T; }
#line 11308 "core/cfg.tab.c"
    break;

  case 779: /* lval: attr_id_ass  */
#line 3253 "core/cfg.y"
                  {
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_AVP; lval_tmp->lv.avps=*(yyvsp[0].attr);
					pkg_free((yyvsp[0].attr)); /* free the avp spec we just copied */
					(yyval.lval)=lval_tmp;
				}
#line 11323 "core/cfg.tab.c"
    break;

  case 780: /* lval: pvar  */
#line 3263 "core/cfg.y"
                      {
					if (!pv_is_w((yyvsp[0].pvar)))
						yyerror("read only pvar in assignment left side");
					if ((yyvsp[0].pvar)->trans!=0)
						yyerror("pvar with transformations in assignment"
								" left side");
					lval_tmp=pkg_malloc(sizeof(*lval_tmp));
					if (!lval_tmp) {
						yyerror("Not enough memory");
						YYABORT;
					}
					lval_tmp->type=LV_PVAR; lval_tmp->lv.pvs=(yyvsp[0].pvar);
					(yyval.lval)=lval_tmp;
				}
#line 11342 "core/cfg.tab.c"
    break;

  case 781: /* lval: avp_pvar  */
#line 3277 "core/cfg.y"
                      {
					if (((yyvsp[0].lval))->type==LV_PVAR){
						if (!pv_is_w((yyvsp[0].lval)->lv.pvs))
							yyerror("read only pvar in assignment left side");
						if ((yyvsp[0].lval)->lv.pvs->trans!=0)
							yyerror("pvar with transformations in assignment"
									" left side");
					}
					(yyval.lval)=(yyvsp[0].lval);
				}
#line 11357 "core/cfg.tab.c"
    break;

  case 782: /* rval: intno  */
#line 3289 "core/cfg.y"
                                {(yyval.rv_expr)=mk_rve_rval(RV_LONG, (void*)(yyvsp[0].intval)); }
#line 11363 "core/cfg.tab.c"
    break;

  case 783: /* rval: STRING  */
#line 3290 "core/cfg.y"
                                        {	s_tmp.s=(yyvsp[0].strval); s_tmp.len=strlen((yyvsp[0].strval));
							(yyval.rv_expr)=mk_rve_rval(RV_STR, &s_tmp); }
#line 11370 "core/cfg.tab.c"
    break;

  case 784: /* rval: attr_id_any  */
#line 3292 "core/cfg.y"
                                {(yyval.rv_expr)=mk_rve_rval(RV_AVP, (yyvsp[0].attr)); pkg_free((yyvsp[0].attr)); }
#line 11376 "core/cfg.tab.c"
    break;

  case 785: /* rval: pvar  */
#line 3293 "core/cfg.y"
                                        {(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].pvar)); }
#line 11382 "core/cfg.tab.c"
    break;

  case 786: /* rval: avp_pvar  */
#line 3294 "core/cfg.y"
                                        {
							switch((yyvsp[0].lval)->type){
								case LV_AVP:
									(yyval.rv_expr)=mk_rve_rval(RV_AVP, &(yyvsp[0].lval)->lv.avps);
									break;
								case LV_PVAR:
									(yyval.rv_expr)=mk_rve_rval(RV_PVAR, (yyvsp[0].lval)->lv.pvs);
									break;
								default:
									yyerror("BUG: invalid lvalue type ");
									YYABORT;
							}
							pkg_free((yyvsp[0].lval)); /* not needed anymore */
						}
#line 11401 "core/cfg.tab.c"
    break;

  case 787: /* rval: select_id  */
#line 3308 "core/cfg.y"
                                        {(yyval.rv_expr)=mk_rve_rval(RV_SEL, (yyvsp[0].select)); pkg_free((yyvsp[0].select)); }
#line 11407 "core/cfg.tab.c"
    break;

  case 788: /* rval: fcmd  */
#line 3309 "core/cfg.y"
                                        {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[0].action)); }
#line 11413 "core/cfg.tab.c"
    break;

  case 789: /* rval: exp_elem  */
#line 3310 "core/cfg.y"
                   { (yyval.rv_expr)=mk_rve_rval(RV_BEXPR, (yyvsp[0].expr)); }
#line 11419 "core/cfg.tab.c"
    break;

  case 790: /* rval: LBRACE actions RBRACE  */
#line 3311 "core/cfg.y"
                                {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 11425 "core/cfg.tab.c"
    break;

  case 791: /* rval: LBRACE error RBRACE  */
#line 3312 "core/cfg.y"
                                { (yyval.rv_expr)=0; yyerror("bad command block"); }
#line 11431 "core/cfg.tab.c"
    break;

  case 792: /* rval: LPAREN assign_action RPAREN  */
#line 3313 "core/cfg.y"
                                        {(yyval.rv_expr)=mk_rve_rval(RV_ACTION_ST, (yyvsp[-1].action)); }
#line 11437 "core/cfg.tab.c"
    break;

  case 793: /* rval: LPAREN error RPAREN  */
#line 3314 "core/cfg.y"
                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11443 "core/cfg.tab.c"
    break;

  case 794: /* rve_un_op: NOT  */
#line 3318 "core/cfg.y"
                { (yyval.intval)=RVE_LNOT_OP; }
#line 11449 "core/cfg.tab.c"
    break;

  case 795: /* rve_un_op: BIN_NOT  */
#line 3319 "core/cfg.y"
                                { (yyval.intval)=RVE_BNOT_OP; }
#line 11455 "core/cfg.tab.c"
    break;

  case 796: /* rve_un_op: MINUS  */
#line 3320 "core/cfg.y"
                                        { (yyval.intval)=RVE_UMINUS_OP; }
#line 11461 "core/cfg.tab.c"
    break;

  case 797: /* rval_expr: rval  */
#line 3333 "core/cfg.y"
                                                        { (yyval.rv_expr)=(yyvsp[0].rv_expr);
										if ((yyval.rv_expr)==0){
											/*yyerror("out of memory\n");*/
											YYERROR;
										}
									}
#line 11472 "core/cfg.tab.c"
    break;

  case 798: /* rval_expr: rve_un_op rval_expr  */
#line 3339 "core/cfg.y"
                                                        {(yyval.rv_expr)=mk_rve1((yyvsp[-1].intval), (yyvsp[0].rv_expr)); }
#line 11478 "core/cfg.tab.c"
    break;

  case 799: /* rval_expr: INTCAST rval_expr  */
#line 3340 "core/cfg.y"
                                                                {(yyval.rv_expr)=mk_rve1(RVE_LONG_OP, (yyvsp[0].rv_expr)); }
#line 11484 "core/cfg.tab.c"
    break;

  case 800: /* rval_expr: STRCAST rval_expr  */
#line 3341 "core/cfg.y"
                                                                {(yyval.rv_expr)=mk_rve1(RVE_STR_OP, (yyvsp[0].rv_expr)); }
#line 11490 "core/cfg.tab.c"
    break;

  case 801: /* rval_expr: rval_expr PLUS rval_expr  */
#line 3342 "core/cfg.y"
                                                        {(yyval.rv_expr)=mk_rve2(RVE_PLUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 11496 "core/cfg.tab.c"
    break;

  case 802: /* rval_expr: rval_expr MINUS rval_expr  */
#line 3343 "core/cfg.y"
                                                        {(yyval.rv_expr)=mk_rve2(RVE_MINUS_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 11502 "core/cfg.tab.c"
    break;

  case 803: /* rval_expr: rval_expr STAR rval_expr  */
#line 3344 "core/cfg.y"
                                                        {(yyval.rv_expr)=mk_rve2(RVE_MUL_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 11508 "core/cfg.tab.c"
    break;

  case 804: /* rval_expr: rval_expr SLASH rval_expr  */
#line 3345 "core/cfg.y"
                                                        {(yyval.rv_expr)=mk_rve2(RVE_DIV_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 11514 "core/cfg.tab.c"
    break;

  case 805: /* rval_expr: rval_expr MODULO rval_expr  */
#line 3346 "core/cfg.y"
                                                {(yyval.rv_expr)=mk_rve2(RVE_MOD_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr)); }
#line 11520 "core/cfg.tab.c"
    break;

  case 806: /* rval_expr: rval_expr BIN_OR rval_expr  */
#line 3347 "core/cfg.y"
                                                {(yyval.rv_expr)=mk_rve2(RVE_BOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr)); }
#line 11526 "core/cfg.tab.c"
    break;

  case 807: /* rval_expr: rval_expr BIN_AND rval_expr  */
#line 3348 "core/cfg.y"
                                                {(yyval.rv_expr)=mk_rve2(RVE_BAND_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 11532 "core/cfg.tab.c"
    break;

  case 808: /* rval_expr: rval_expr BIN_XOR rval_expr  */
#line 3349 "core/cfg.y"
                                                {(yyval.rv_expr)=mk_rve2(RVE_BXOR_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 11538 "core/cfg.tab.c"
    break;

  case 809: /* rval_expr: rval_expr BIN_LSHIFT rval_expr  */
#line 3350 "core/cfg.y"
                                                 {(yyval.rv_expr)=mk_rve2(RVE_BLSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 11544 "core/cfg.tab.c"
    break;

  case 810: /* rval_expr: rval_expr BIN_RSHIFT rval_expr  */
#line 3351 "core/cfg.y"
                                                 {(yyval.rv_expr)=mk_rve2(RVE_BRSHIFT_OP, (yyvsp[-2].rv_expr),  (yyvsp[0].rv_expr));}
#line 11550 "core/cfg.tab.c"
    break;

  case 811: /* rval_expr: rval_expr rve_cmpop rval_expr  */
#line 3352 "core/cfg.y"
                                                         { (yyval.rv_expr)=mk_rve2( (yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 11556 "core/cfg.tab.c"
    break;

  case 812: /* rval_expr: rval_expr rve_equalop rval_expr  */
#line 3353 "core/cfg.y"
                                                                {
			/* comparing with $null => treat as defined or !defined */
			if((yyvsp[0].rv_expr) != NULL && (yyvsp[0].rv_expr)->op==RVE_RVAL_OP && (yyvsp[0].rv_expr)->left.rval.type==RV_PVAR
					&& (yyvsp[0].rv_expr)->left.rval.v.pvs.type==PVT_NULL) {
				if((yyvsp[-1].intval)==RVE_DIFF_OP || (yyvsp[-1].intval)==RVE_IDIFF_OP
						|| (yyvsp[-1].intval)==RVE_STRDIFF_OP) {
					DBG("comparison with $null switched to notdefined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[-2].rv_expr));
				} else {
					DBG("comparison with $null switched to defined operator\n");
					(yyval.rv_expr)=mk_rve1(RVE_NOTDEFINED_OP, (yyvsp[-2].rv_expr));
				}
				/* free rve struct for $null */
				rve_destroy((yyvsp[0].rv_expr));
			} else {
				(yyval.rv_expr)=mk_rve2((yyvsp[-1].intval), (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));
			}
		}
#line 11579 "core/cfg.tab.c"
    break;

  case 813: /* rval_expr: rval_expr LOG_AND rval_expr  */
#line 3371 "core/cfg.y"
                                                { (yyval.rv_expr)=mk_rve2(RVE_LAND_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 11585 "core/cfg.tab.c"
    break;

  case 814: /* rval_expr: rval_expr LOG_OR rval_expr  */
#line 3372 "core/cfg.y"
                                                { (yyval.rv_expr)=mk_rve2(RVE_LOR_OP, (yyvsp[-2].rv_expr), (yyvsp[0].rv_expr));}
#line 11591 "core/cfg.tab.c"
    break;

  case 815: /* rval_expr: LPAREN rval_expr RPAREN  */
#line 3373 "core/cfg.y"
                                                        { (yyval.rv_expr)=(yyvsp[-1].rv_expr);}
#line 11597 "core/cfg.tab.c"
    break;

  case 816: /* rval_expr: STRLEN LPAREN rval_expr RPAREN  */
#line 3374 "core/cfg.y"
                                                 { (yyval.rv_expr)=mk_rve1(RVE_STRLEN_OP, (yyvsp[-1].rv_expr));}
#line 11603 "core/cfg.tab.c"
    break;

  case 817: /* rval_expr: STREMPTY LPAREN rval_expr RPAREN  */
#line 3375 "core/cfg.y"
                                                   {(yyval.rv_expr)=mk_rve1(RVE_STREMPTY_OP, (yyvsp[-1].rv_expr));}
#line 11609 "core/cfg.tab.c"
    break;

  case 818: /* rval_expr: DEFINED rval_expr  */
#line 3376 "core/cfg.y"
                                                                { (yyval.rv_expr)=mk_rve1(RVE_DEFINED_OP, (yyvsp[0].rv_expr));}
#line 11615 "core/cfg.tab.c"
    break;

  case 819: /* rval_expr: SELVAL LPAREN rval_expr COMMA rval_expr COMMA rval_expr RPAREN  */
#line 3377 "core/cfg.y"
                                                                                 {
				rve_tmp=mk_rve2(RVE_SELVALOPT_OP, (yyvsp[-3].rv_expr), (yyvsp[-1].rv_expr));
				if(rve_tmp == NULL) {
					(yyval.rv_expr)=0;
					yyerror("failed to create tenary target expression");
				}
				(yyval.rv_expr)=mk_rve2(RVE_SELVALEXP_OP, (yyvsp[-5].rv_expr), rve_tmp);
		}
#line 11628 "core/cfg.tab.c"
    break;

  case 820: /* rval_expr: rve_un_op error  */
#line 3385 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11634 "core/cfg.tab.c"
    break;

  case 821: /* rval_expr: INTCAST error  */
#line 3386 "core/cfg.y"
                                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11640 "core/cfg.tab.c"
    break;

  case 822: /* rval_expr: STRCAST error  */
#line 3387 "core/cfg.y"
                                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11646 "core/cfg.tab.c"
    break;

  case 823: /* rval_expr: rval_expr PLUS error  */
#line 3388 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11652 "core/cfg.tab.c"
    break;

  case 824: /* rval_expr: rval_expr MINUS error  */
#line 3389 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11658 "core/cfg.tab.c"
    break;

  case 825: /* rval_expr: rval_expr STAR error  */
#line 3390 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11664 "core/cfg.tab.c"
    break;

  case 826: /* rval_expr: rval_expr SLASH error  */
#line 3391 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11670 "core/cfg.tab.c"
    break;

  case 827: /* rval_expr: rval_expr MODULO error  */
#line 3392 "core/cfg.y"
                                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11676 "core/cfg.tab.c"
    break;

  case 828: /* rval_expr: rval_expr BIN_OR error  */
#line 3393 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11682 "core/cfg.tab.c"
    break;

  case 829: /* rval_expr: rval_expr BIN_AND error  */
#line 3394 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11688 "core/cfg.tab.c"
    break;

  case 830: /* rval_expr: rval_expr rve_cmpop error  */
#line 3396 "core/cfg.y"
                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11694 "core/cfg.tab.c"
    break;

  case 831: /* rval_expr: rval_expr rve_equalop error  */
#line 3398 "core/cfg.y"
                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11700 "core/cfg.tab.c"
    break;

  case 832: /* rval_expr: rval_expr LOG_AND error  */
#line 3399 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11706 "core/cfg.tab.c"
    break;

  case 833: /* rval_expr: rval_expr LOG_OR error  */
#line 3400 "core/cfg.y"
                                                        { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11712 "core/cfg.tab.c"
    break;

  case 834: /* rval_expr: STRLEN LPAREN error RPAREN  */
#line 3401 "core/cfg.y"
                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11718 "core/cfg.tab.c"
    break;

  case 835: /* rval_expr: STREMPTY LPAREN error RPAREN  */
#line 3402 "core/cfg.y"
                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11724 "core/cfg.tab.c"
    break;

  case 836: /* rval_expr: SELVAL LPAREN error RPAREN  */
#line 3403 "core/cfg.y"
                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11730 "core/cfg.tab.c"
    break;

  case 837: /* rval_expr: DEFINED error  */
#line 3404 "core/cfg.y"
                                                                { (yyval.rv_expr)=0; yyerror("bad expression"); }
#line 11736 "core/cfg.tab.c"
    break;

  case 838: /* assign_action: lval assign_op rval_expr  */
#line 3407 "core/cfg.y"
                                                { (yyval.action)=mk_action((yyvsp[-1].intval), 2, LVAL_ST, (yyvsp[-2].lval),
														 	  RVE_ST, (yyvsp[0].rv_expr));
											set_cfg_pos((yyval.action));
										}
#line 11745 "core/cfg.tab.c"
    break;

  case 839: /* avpflag_oper: SETAVPFLAG  */
#line 3425 "core/cfg.y"
                   { (yyval.intval) = 1; }
#line 11751 "core/cfg.tab.c"
    break;

  case 840: /* avpflag_oper: RESETAVPFLAG  */
#line 3426 "core/cfg.y"
                       { (yyval.intval) = 0; }
#line 11757 "core/cfg.tab.c"
    break;

  case 841: /* avpflag_oper: ISAVPFLAGSET  */
#line 3427 "core/cfg.y"
                       { (yyval.intval) = -1; }
#line 11763 "core/cfg.tab.c"
    break;

  case 842: /* cmd: FORWARD LPAREN RPAREN  */
#line 3430 "core/cfg.y"
                              { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 11769 "core/cfg.tab.c"
    break;

  case 843: /* cmd: FORWARD LPAREN host RPAREN  */
#line 3431 "core/cfg.y"
                                        { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11775 "core/cfg.tab.c"
    break;

  case 844: /* cmd: FORWARD LPAREN STRING RPAREN  */
#line 3432 "core/cfg.y"
                                        { (yyval.action)=mk_action(	FORWARD_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11781 "core/cfg.tab.c"
    break;

  case 845: /* cmd: FORWARD LPAREN ip RPAREN  */
#line 3433 "core/cfg.y"
                                        { (yyval.action)=mk_action(	FORWARD_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11787 "core/cfg.tab.c"
    break;

  case 846: /* cmd: FORWARD LPAREN host COMMA NUMBER RPAREN  */
#line 3434 "core/cfg.y"
                                                  { (yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11793 "core/cfg.tab.c"
    break;

  case 847: /* cmd: FORWARD LPAREN STRING COMMA NUMBER RPAREN  */
#line 3435 "core/cfg.y"
                                                    {(yyval.action)=mk_action(FORWARD_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11799 "core/cfg.tab.c"
    break;

  case 848: /* cmd: FORWARD LPAREN ip COMMA NUMBER RPAREN  */
#line 3436 "core/cfg.y"
                                                { (yyval.action)=mk_action(FORWARD_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11805 "core/cfg.tab.c"
    break;

  case 849: /* cmd: FORWARD LPAREN URIHOST COMMA URIPORT RPAREN  */
#line 3437 "core/cfg.y"
                                                      { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 11811 "core/cfg.tab.c"
    break;

  case 850: /* cmd: FORWARD LPAREN URIHOST COMMA NUMBER RPAREN  */
#line 3438 "core/cfg.y"
                                                     {(yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11817 "core/cfg.tab.c"
    break;

  case 851: /* cmd: FORWARD LPAREN URIHOST RPAREN  */
#line 3439 "core/cfg.y"
                                        { (yyval.action)=mk_action(FORWARD_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11823 "core/cfg.tab.c"
    break;

  case 852: /* cmd: FORWARD error  */
#line 3440 "core/cfg.y"
                        { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11829 "core/cfg.tab.c"
    break;

  case 853: /* cmd: FORWARD LPAREN error RPAREN  */
#line 3441 "core/cfg.y"
                                      { (yyval.action)=0; yyerror("bad forward argument"); }
#line 11835 "core/cfg.tab.c"
    break;

  case 854: /* cmd: FORWARD_UDP LPAREN host RPAREN  */
#line 3442 "core/cfg.y"
                                                { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11841 "core/cfg.tab.c"
    break;

  case 855: /* cmd: FORWARD_UDP LPAREN STRING RPAREN  */
#line 3443 "core/cfg.y"
                                                { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11847 "core/cfg.tab.c"
    break;

  case 856: /* cmd: FORWARD_UDP LPAREN ip RPAREN  */
#line 3444 "core/cfg.y"
                                        { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11853 "core/cfg.tab.c"
    break;

  case 857: /* cmd: FORWARD_UDP LPAREN host COMMA NUMBER RPAREN  */
#line 3445 "core/cfg.y"
                                                      { (yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11859 "core/cfg.tab.c"
    break;

  case 858: /* cmd: FORWARD_UDP LPAREN STRING COMMA NUMBER RPAREN  */
#line 3446 "core/cfg.y"
                                                        {(yyval.action)=mk_action(FORWARD_UDP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11865 "core/cfg.tab.c"
    break;

  case 859: /* cmd: FORWARD_UDP LPAREN ip COMMA NUMBER RPAREN  */
#line 3447 "core/cfg.y"
                                                    { (yyval.action)=mk_action(FORWARD_UDP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11871 "core/cfg.tab.c"
    break;

  case 860: /* cmd: FORWARD_UDP LPAREN URIHOST COMMA URIPORT RPAREN  */
#line 3448 "core/cfg.y"
                                                          {(yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 11877 "core/cfg.tab.c"
    break;

  case 861: /* cmd: FORWARD_UDP LPAREN URIHOST COMMA NUMBER RPAREN  */
#line 3449 "core/cfg.y"
                                                         { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11883 "core/cfg.tab.c"
    break;

  case 862: /* cmd: FORWARD_UDP LPAREN URIHOST RPAREN  */
#line 3450 "core/cfg.y"
                                            { (yyval.action)=mk_action(FORWARD_UDP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11889 "core/cfg.tab.c"
    break;

  case 863: /* cmd: FORWARD_UDP error  */
#line 3451 "core/cfg.y"
                            { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11895 "core/cfg.tab.c"
    break;

  case 864: /* cmd: FORWARD_UDP LPAREN error RPAREN  */
#line 3452 "core/cfg.y"
                                          { (yyval.action)=0; yyerror("bad forward_udp argument"); }
#line 11901 "core/cfg.tab.c"
    break;

  case 865: /* cmd: FORWARD_TCP LPAREN host RPAREN  */
#line 3453 "core/cfg.y"
                                                { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11907 "core/cfg.tab.c"
    break;

  case 866: /* cmd: FORWARD_TCP LPAREN STRING RPAREN  */
#line 3454 "core/cfg.y"
                                                { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11913 "core/cfg.tab.c"
    break;

  case 867: /* cmd: FORWARD_TCP LPAREN ip RPAREN  */
#line 3455 "core/cfg.y"
                                        { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11919 "core/cfg.tab.c"
    break;

  case 868: /* cmd: FORWARD_TCP LPAREN host COMMA NUMBER RPAREN  */
#line 3456 "core/cfg.y"
                                                      { (yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11925 "core/cfg.tab.c"
    break;

  case 869: /* cmd: FORWARD_TCP LPAREN STRING COMMA NUMBER RPAREN  */
#line 3457 "core/cfg.y"
                                                        {(yyval.action)=mk_action(FORWARD_TCP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11931 "core/cfg.tab.c"
    break;

  case 870: /* cmd: FORWARD_TCP LPAREN ip COMMA NUMBER RPAREN  */
#line 3458 "core/cfg.y"
                                                    { (yyval.action)=mk_action(FORWARD_TCP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11937 "core/cfg.tab.c"
    break;

  case 871: /* cmd: FORWARD_TCP LPAREN URIHOST COMMA URIPORT RPAREN  */
#line 3459 "core/cfg.y"
                                                          {(yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action)); }
#line 11943 "core/cfg.tab.c"
    break;

  case 872: /* cmd: FORWARD_TCP LPAREN URIHOST COMMA NUMBER RPAREN  */
#line 3460 "core/cfg.y"
                                                         { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 11949 "core/cfg.tab.c"
    break;

  case 873: /* cmd: FORWARD_TCP LPAREN URIHOST RPAREN  */
#line 3461 "core/cfg.y"
                                            { (yyval.action)=mk_action(FORWARD_TCP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action)); }
#line 11955 "core/cfg.tab.c"
    break;

  case 874: /* cmd: FORWARD_TCP error  */
#line 3462 "core/cfg.y"
                            { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 11961 "core/cfg.tab.c"
    break;

  case 875: /* cmd: FORWARD_TCP LPAREN error RPAREN  */
#line 3463 "core/cfg.y"
                                          { (yyval.action)=0; yyerror("bad forward_tcp argument"); }
#line 11967 "core/cfg.tab.c"
    break;

  case 876: /* cmd: FORWARD_TLS LPAREN host RPAREN  */
#line 3464 "core/cfg.y"
                                         {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 11980 "core/cfg.tab.c"
    break;

  case 877: /* cmd: FORWARD_TLS LPAREN STRING RPAREN  */
#line 3472 "core/cfg.y"
                                           {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 11993 "core/cfg.tab.c"
    break;

  case 878: /* cmd: FORWARD_TLS LPAREN ip RPAREN  */
#line 3480 "core/cfg.y"
                                        {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12006 "core/cfg.tab.c"
    break;

  case 879: /* cmd: FORWARD_TLS LPAREN host COMMA NUMBER RPAREN  */
#line 3488 "core/cfg.y"
                                                      {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12019 "core/cfg.tab.c"
    break;

  case 880: /* cmd: FORWARD_TLS LPAREN STRING COMMA NUMBER RPAREN  */
#line 3496 "core/cfg.y"
                                                        {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12032 "core/cfg.tab.c"
    break;

  case 881: /* cmd: FORWARD_TLS LPAREN ip COMMA NUMBER RPAREN  */
#line 3504 "core/cfg.y"
                                                    {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
					}
#line 12045 "core/cfg.tab.c"
    break;

  case 882: /* cmd: FORWARD_TLS LPAREN URIHOST COMMA URIPORT RPAREN  */
#line 3512 "core/cfg.y"
                                                          {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12058 "core/cfg.tab.c"
    break;

  case 883: /* cmd: FORWARD_TLS LPAREN URIHOST COMMA NUMBER RPAREN  */
#line 3520 "core/cfg.y"
                                                         {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12071 "core/cfg.tab.c"
    break;

  case 884: /* cmd: FORWARD_TLS LPAREN URIHOST RPAREN  */
#line 3528 "core/cfg.y"
                                            {
		#ifdef USE_TLS
			(yyval.action)=mk_action(FORWARD_TLS_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12084 "core/cfg.tab.c"
    break;

  case 885: /* cmd: FORWARD_TLS error  */
#line 3536 "core/cfg.y"
                            { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12090 "core/cfg.tab.c"
    break;

  case 886: /* cmd: FORWARD_TLS LPAREN error RPAREN  */
#line 3537 "core/cfg.y"
                                          { (yyval.action)=0;
									yyerror("bad forward_tls argument"); }
#line 12097 "core/cfg.tab.c"
    break;

  case 887: /* cmd: FORWARD_SCTP LPAREN host RPAREN  */
#line 3539 "core/cfg.y"
                                          {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12110 "core/cfg.tab.c"
    break;

  case 888: /* cmd: FORWARD_SCTP LPAREN STRING RPAREN  */
#line 3547 "core/cfg.y"
                                            {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-1].strval), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12123 "core/cfg.tab.c"
    break;

  case 889: /* cmd: FORWARD_SCTP LPAREN ip RPAREN  */
#line 3555 "core/cfg.y"
                                        {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-1].ipaddr), NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12136 "core/cfg.tab.c"
    break;

  case 890: /* cmd: FORWARD_SCTP LPAREN host COMMA NUMBER RPAREN  */
#line 3563 "core/cfg.y"
                                                       {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12150 "core/cfg.tab.c"
    break;

  case 891: /* cmd: FORWARD_SCTP LPAREN STRING COMMA NUMBER RPAREN  */
#line 3572 "core/cfg.y"
                                                         {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12164 "core/cfg.tab.c"
    break;

  case 892: /* cmd: FORWARD_SCTP LPAREN ip COMMA NUMBER RPAREN  */
#line 3581 "core/cfg.y"
                                                     {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, IP_ST, (void*)(yyvsp[-3].ipaddr), NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
					}
#line 12178 "core/cfg.tab.c"
    break;

  case 893: /* cmd: FORWARD_SCTP LPAREN URIHOST COMMA URIPORT RPAREN  */
#line 3590 "core/cfg.y"
                                                           {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, URIPORT_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12191 "core/cfg.tab.c"
    break;

  case 894: /* cmd: FORWARD_SCTP LPAREN URIHOST COMMA NUMBER RPAREN  */
#line 3598 "core/cfg.y"
                                                          {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST,
							(void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("sctp support not compiled in");
		#endif
	}
#line 12205 "core/cfg.tab.c"
    break;

  case 895: /* cmd: FORWARD_SCTP LPAREN URIHOST RPAREN  */
#line 3607 "core/cfg.y"
                                             {
		#ifdef USE_SCTP
			(yyval.action)=mk_action(FORWARD_SCTP_T, 2, URIHOST_ST, 0, NUMBER_ST, 0); set_cfg_pos((yyval.action));
		#else
			(yyval.action)=0;
			yyerror("tls support not compiled in");
		#endif
	}
#line 12218 "core/cfg.tab.c"
    break;

  case 896: /* cmd: FORWARD_SCTP error  */
#line 3615 "core/cfg.y"
                             { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12224 "core/cfg.tab.c"
    break;

  case 897: /* cmd: FORWARD_SCTP LPAREN error RPAREN  */
#line 3616 "core/cfg.y"
                                           { (yyval.action)=0;
									yyerror("bad forward_sctp argument"); }
#line 12231 "core/cfg.tab.c"
    break;

  case 898: /* cmd: LOG_TOK LPAREN STRING RPAREN  */
#line 3618 "core/cfg.y"
                                        {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST,
										(void*)(L_DBG+1), STRING_ST, (yyvsp[-1].strval));
									set_cfg_pos((yyval.action)); }
#line 12239 "core/cfg.tab.c"
    break;

  case 899: /* cmd: LOG_TOK LPAREN NUMBER COMMA STRING RPAREN  */
#line 3621 "core/cfg.y"
                                                        {(yyval.action)=mk_action(LOG_T, 2, NUMBER_ST, (void*)(yyvsp[-3].intval), STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12245 "core/cfg.tab.c"
    break;

  case 900: /* cmd: LOG_TOK error  */
#line 3622 "core/cfg.y"
                                        { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12251 "core/cfg.tab.c"
    break;

  case 901: /* cmd: LOG_TOK LPAREN error RPAREN  */
#line 3623 "core/cfg.y"
                                        { (yyval.action)=0; yyerror("bad log argument"); }
#line 12257 "core/cfg.tab.c"
    break;

  case 902: /* cmd: SETFLAG LPAREN NUMBER RPAREN  */
#line 3624 "core/cfg.y"
                                        {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
													(void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 12269 "core/cfg.tab.c"
    break;

  case 903: /* cmd: SETFLAG LPAREN flag_name RPAREN  */
#line 3631 "core/cfg.y"
                                                {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(SETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 12281 "core/cfg.tab.c"
    break;

  case 904: /* cmd: SETFLAG error  */
#line 3638 "core/cfg.y"
                                        { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 12287 "core/cfg.tab.c"
    break;

  case 905: /* cmd: RESETFLAG LPAREN NUMBER RPAREN  */
#line 3639 "core/cfg.y"
                                         {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 12298 "core/cfg.tab.c"
    break;

  case 906: /* cmd: RESETFLAG LPAREN flag_name RPAREN  */
#line 3645 "core/cfg.y"
                                                {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(RESETFLAG_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 12310 "core/cfg.tab.c"
    break;

  case 907: /* cmd: RESETFLAG error  */
#line 3652 "core/cfg.y"
                                        { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 12316 "core/cfg.tab.c"
    break;

  case 908: /* cmd: ISFLAGSET LPAREN NUMBER RPAREN  */
#line 3653 "core/cfg.y"
                                         {
							if (check_flag((yyvsp[-1].intval))==-1)
								yyerror("bad flag value");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
							set_cfg_pos((yyval.action));
									}
#line 12327 "core/cfg.tab.c"
    break;

  case 909: /* cmd: ISFLAGSET LPAREN flag_name RPAREN  */
#line 3659 "core/cfg.y"
                                                {
							i_tmp=get_flag_no((yyvsp[-1].strval), strlen((yyvsp[-1].strval)));
							if (i_tmp<0) yyerror("flag not declared");
							(yyval.action)=mk_action(ISFLAGSET_T, 1, NUMBER_ST,
										(void*)(long)i_tmp);
							set_cfg_pos((yyval.action));
									}
#line 12339 "core/cfg.tab.c"
    break;

  case 910: /* cmd: ISFLAGSET error  */
#line 3666 "core/cfg.y"
                          { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 12345 "core/cfg.tab.c"
    break;

  case 911: /* cmd: avpflag_oper LPAREN attr_id_any_str COMMA flag_name RPAREN  */
#line 3667 "core/cfg.y"
                                                                     {
		i_tmp=get_avpflag_no((yyvsp[-1].strval));
		if (i_tmp==0) yyerror("avpflag not declared");
		(yyval.action)=mk_action(AVPFLAG_OPER_T, 3, AVP_ST, (yyvsp[-3].attr), NUMBER_ST, (void*)(long)i_tmp, NUMBER_ST, (void*)(yyvsp[-5].intval));
		set_cfg_pos((yyval.action));
	}
#line 12356 "core/cfg.tab.c"
    break;

  case 912: /* cmd: avpflag_oper LPAREN attr_id_any_str COMMA error RPAREN  */
#line 3673 "core/cfg.y"
                                                                 {
		(yyval.action)=0; yyerror("error parsing flag name");
	}
#line 12364 "core/cfg.tab.c"
    break;

  case 913: /* cmd: avpflag_oper LPAREN error COMMA flag_name RPAREN  */
#line 3676 "core/cfg.y"
                                                           {
		(yyval.action)=0; yyerror("error parsing first parameter (avp or string)");
	}
#line 12372 "core/cfg.tab.c"
    break;

  case 914: /* cmd: avpflag_oper LPAREN error RPAREN  */
#line 3679 "core/cfg.y"
                                           { (yyval.action)=0; yyerror("bad parameters"); }
#line 12378 "core/cfg.tab.c"
    break;

  case 915: /* cmd: avpflag_oper error  */
#line 3680 "core/cfg.y"
                             { (yyval.action)=0; yyerror("missing '(' or ')'?"); }
#line 12384 "core/cfg.tab.c"
    break;

  case 916: /* cmd: ERROR LPAREN STRING COMMA STRING RPAREN  */
#line 3681 "core/cfg.y"
                                                  {(yyval.action)=mk_action(ERROR_T, 2, STRING_ST, (yyvsp[-3].strval), STRING_ST, (yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
	}
#line 12392 "core/cfg.tab.c"
    break;

  case 917: /* cmd: ERROR error  */
#line 3684 "core/cfg.y"
                      { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12398 "core/cfg.tab.c"
    break;

  case 918: /* cmd: ERROR LPAREN error RPAREN  */
#line 3685 "core/cfg.y"
                                    { (yyval.action)=0; yyerror("bad error argument"); }
#line 12404 "core/cfg.tab.c"
    break;

  case 919: /* cmd: ROUTE LPAREN rval_expr RPAREN  */
#line 3686 "core/cfg.y"
                                        {
		if ((yyvsp[-1].rv_expr)) {
			(yyval.action) = mk_action(ROUTE_T, 1, RVE_ST, (void*)(yyvsp[-1].rv_expr));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 12418 "core/cfg.tab.c"
    break;

  case 920: /* cmd: ROUTE LPAREN ID RPAREN  */
#line 3695 "core/cfg.y"
                                        {
		if ((yyvsp[-1].strval)) {
			(yyval.action) = mk_action(ROUTE_T, 1, STRING_ST, (void*)(yyvsp[-1].strval));
			set_cfg_pos((yyval.action));
		} else {
			(yyval.action) = 0;
			YYERROR;
		}
	}
#line 12432 "core/cfg.tab.c"
    break;

  case 921: /* cmd: ROUTE error  */
#line 3704 "core/cfg.y"
                      { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12438 "core/cfg.tab.c"
    break;

  case 922: /* cmd: ROUTE LPAREN error RPAREN  */
#line 3705 "core/cfg.y"
                                    { (yyval.action)=0; yyerror("bad route argument"); }
#line 12444 "core/cfg.tab.c"
    break;

  case 923: /* cmd: EXEC LPAREN STRING RPAREN  */
#line 3706 "core/cfg.y"
                                        { (yyval.action)=mk_action(EXEC_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12450 "core/cfg.tab.c"
    break;

  case 924: /* cmd: SET_HOST LPAREN STRING RPAREN  */
#line 3707 "core/cfg.y"
                                        { (yyval.action)=mk_action(SET_HOST_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12456 "core/cfg.tab.c"
    break;

  case 925: /* cmd: SET_HOST error  */
#line 3708 "core/cfg.y"
                         { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12462 "core/cfg.tab.c"
    break;

  case 926: /* cmd: SET_HOST LPAREN error RPAREN  */
#line 3709 "core/cfg.y"
                                       { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12468 "core/cfg.tab.c"
    break;

  case 927: /* cmd: PREFIX LPAREN STRING RPAREN  */
#line 3710 "core/cfg.y"
                                      { (yyval.action)=mk_action(PREFIX_T, 1, STRING_ST,  (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12474 "core/cfg.tab.c"
    break;

  case 928: /* cmd: PREFIX error  */
#line 3711 "core/cfg.y"
                       { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12480 "core/cfg.tab.c"
    break;

  case 929: /* cmd: PREFIX LPAREN error RPAREN  */
#line 3712 "core/cfg.y"
                                     { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12486 "core/cfg.tab.c"
    break;

  case 930: /* cmd: STRIP_TAIL LPAREN NUMBER RPAREN  */
#line 3713 "core/cfg.y"
                                          { (yyval.action)=mk_action(STRIP_TAIL_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 12492 "core/cfg.tab.c"
    break;

  case 931: /* cmd: STRIP_TAIL error  */
#line 3714 "core/cfg.y"
                           { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12498 "core/cfg.tab.c"
    break;

  case 932: /* cmd: STRIP_TAIL LPAREN error RPAREN  */
#line 3715 "core/cfg.y"
                                         { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 12504 "core/cfg.tab.c"
    break;

  case 933: /* cmd: STRIP LPAREN NUMBER RPAREN  */
#line 3716 "core/cfg.y"
                                     { (yyval.action)=mk_action(STRIP_T, 1, NUMBER_ST, (void*) (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 12510 "core/cfg.tab.c"
    break;

  case 934: /* cmd: STRIP error  */
#line 3717 "core/cfg.y"
                      { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12516 "core/cfg.tab.c"
    break;

  case 935: /* cmd: STRIP LPAREN error RPAREN  */
#line 3718 "core/cfg.y"
                                    { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 12522 "core/cfg.tab.c"
    break;

  case 936: /* cmd: SET_USERPHONE LPAREN RPAREN  */
#line 3719 "core/cfg.y"
                                      { (yyval.action)=mk_action(SET_USERPHONE_T, 0); set_cfg_pos((yyval.action)); }
#line 12528 "core/cfg.tab.c"
    break;

  case 937: /* cmd: SET_USERPHONE error  */
#line 3720 "core/cfg.y"
                              { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12534 "core/cfg.tab.c"
    break;

  case 938: /* cmd: REMOVE_BRANCH LPAREN intno RPAREN  */
#line 3721 "core/cfg.y"
                                            {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
	}
#line 12543 "core/cfg.tab.c"
    break;

  case 939: /* cmd: REMOVE_BRANCH LPAREN RPAREN  */
#line 3725 "core/cfg.y"
                                      {
			(yyval.action)=mk_action(REMOVE_BRANCH_T, 0);
			set_cfg_pos((yyval.action));
	}
#line 12552 "core/cfg.tab.c"
    break;

  case 940: /* cmd: REMOVE_BRANCH error  */
#line 3729 "core/cfg.y"
                              { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12558 "core/cfg.tab.c"
    break;

  case 941: /* cmd: REMOVE_BRANCH LPAREN error RPAREN  */
#line 3730 "core/cfg.y"
                                            { (yyval.action)=0; yyerror("bad argument, number expected"); }
#line 12564 "core/cfg.tab.c"
    break;

  case 942: /* cmd: CLEAR_BRANCHES LPAREN RPAREN  */
#line 3731 "core/cfg.y"
                                       { (yyval.action)=mk_action(CLEAR_BRANCHES_T, 0); set_cfg_pos((yyval.action)); }
#line 12570 "core/cfg.tab.c"
    break;

  case 943: /* cmd: SET_HOSTPORT LPAREN STRING RPAREN  */
#line 3732 "core/cfg.y"
                                            { (yyval.action)=mk_action(SET_HOSTPORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12576 "core/cfg.tab.c"
    break;

  case 944: /* cmd: SET_HOSTPORT error  */
#line 3733 "core/cfg.y"
                             { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12582 "core/cfg.tab.c"
    break;

  case 945: /* cmd: SET_HOSTPORT LPAREN error RPAREN  */
#line 3734 "core/cfg.y"
                                           { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12588 "core/cfg.tab.c"
    break;

  case 946: /* cmd: SET_HOSTPORTTRANS LPAREN STRING RPAREN  */
#line 3735 "core/cfg.y"
                                                 { (yyval.action)=mk_action(SET_HOSTPORTTRANS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12594 "core/cfg.tab.c"
    break;

  case 947: /* cmd: SET_HOSTPORTTRANS error  */
#line 3736 "core/cfg.y"
                                  { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12600 "core/cfg.tab.c"
    break;

  case 948: /* cmd: SET_HOSTPORTTRANS LPAREN error RPAREN  */
#line 3737 "core/cfg.y"
                                                { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12606 "core/cfg.tab.c"
    break;

  case 949: /* cmd: SET_PORT LPAREN STRING RPAREN  */
#line 3738 "core/cfg.y"
                                        { (yyval.action)=mk_action(SET_PORT_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12612 "core/cfg.tab.c"
    break;

  case 950: /* cmd: SET_PORT error  */
#line 3739 "core/cfg.y"
                         { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12618 "core/cfg.tab.c"
    break;

  case 951: /* cmd: SET_PORT LPAREN error RPAREN  */
#line 3740 "core/cfg.y"
                                       { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12624 "core/cfg.tab.c"
    break;

  case 952: /* cmd: SET_USER LPAREN STRING RPAREN  */
#line 3741 "core/cfg.y"
                                        { (yyval.action)=mk_action(SET_USER_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12630 "core/cfg.tab.c"
    break;

  case 953: /* cmd: SET_USER error  */
#line 3742 "core/cfg.y"
                         { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12636 "core/cfg.tab.c"
    break;

  case 954: /* cmd: SET_USER LPAREN error RPAREN  */
#line 3743 "core/cfg.y"
                                       { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12642 "core/cfg.tab.c"
    break;

  case 955: /* cmd: SET_USERPASS LPAREN STRING RPAREN  */
#line 3744 "core/cfg.y"
                                            { (yyval.action)=mk_action(SET_USERPASS_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12648 "core/cfg.tab.c"
    break;

  case 956: /* cmd: SET_USERPASS error  */
#line 3745 "core/cfg.y"
                             { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12654 "core/cfg.tab.c"
    break;

  case 957: /* cmd: SET_USERPASS LPAREN error RPAREN  */
#line 3746 "core/cfg.y"
                                           { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12660 "core/cfg.tab.c"
    break;

  case 958: /* cmd: SET_URI LPAREN STRING RPAREN  */
#line 3747 "core/cfg.y"
                                       { (yyval.action)=mk_action(SET_URI_T, 1, STRING_ST,(yyvsp[-1].strval)); set_cfg_pos((yyval.action)); }
#line 12666 "core/cfg.tab.c"
    break;

  case 959: /* cmd: SET_URI error  */
#line 3748 "core/cfg.y"
                        { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12672 "core/cfg.tab.c"
    break;

  case 960: /* cmd: SET_URI LPAREN error RPAREN  */
#line 3749 "core/cfg.y"
                                      { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12678 "core/cfg.tab.c"
    break;

  case 961: /* cmd: REVERT_URI LPAREN RPAREN  */
#line 3750 "core/cfg.y"
                                   { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 12684 "core/cfg.tab.c"
    break;

  case 962: /* cmd: REVERT_URI  */
#line 3751 "core/cfg.y"
                     { (yyval.action)=mk_action(REVERT_URI_T, 0); set_cfg_pos((yyval.action)); }
#line 12690 "core/cfg.tab.c"
    break;

  case 963: /* cmd: FORCE_RPORT LPAREN RPAREN  */
#line 3752 "core/cfg.y"
                                        { (yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 12696 "core/cfg.tab.c"
    break;

  case 964: /* cmd: FORCE_RPORT  */
#line 3753 "core/cfg.y"
                        {(yyval.action)=mk_action(FORCE_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 12702 "core/cfg.tab.c"
    break;

  case 965: /* cmd: ADD_LOCAL_RPORT LPAREN RPAREN  */
#line 3754 "core/cfg.y"
                                        { (yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 12708 "core/cfg.tab.c"
    break;

  case 966: /* cmd: ADD_LOCAL_RPORT  */
#line 3755 "core/cfg.y"
                                {(yyval.action)=mk_action(ADD_LOCAL_RPORT_T, 0); set_cfg_pos((yyval.action)); }
#line 12714 "core/cfg.tab.c"
    break;

  case 967: /* cmd: FORCE_TCP_ALIAS LPAREN NUMBER RPAREN  */
#line 3756 "core/cfg.y"
                                                {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 1, NUMBER_ST, (void*)(yyvsp[-1].intval));
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 12727 "core/cfg.tab.c"
    break;

  case 968: /* cmd: FORCE_TCP_ALIAS LPAREN RPAREN  */
#line 3764 "core/cfg.y"
                                        {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 12740 "core/cfg.tab.c"
    break;

  case 969: /* cmd: FORCE_TCP_ALIAS  */
#line 3772 "core/cfg.y"
                                                        {
		#ifdef USE_TCP
			(yyval.action)=mk_action(FORCE_TCP_ALIAS_T, 0);
			set_cfg_pos((yyval.action));
		#else
			yyerror("tcp support not compiled in");
		#endif
	}
#line 12753 "core/cfg.tab.c"
    break;

  case 970: /* cmd: FORCE_TCP_ALIAS LPAREN error RPAREN  */
#line 3780 "core/cfg.y"
                                                {(yyval.action)=0; yyerror("bad argument, number expected"); }
#line 12759 "core/cfg.tab.c"
    break;

  case 971: /* cmd: UDP_MTU_TRY_PROTO LPAREN proto RPAREN  */
#line 3782 "core/cfg.y"
                { (yyval.action)=mk_action(UDP_MTU_TRY_PROTO_T, 1, NUMBER_ST, (yyvsp[-1].intval)); set_cfg_pos((yyval.action)); }
#line 12765 "core/cfg.tab.c"
    break;

  case 972: /* cmd: UDP_MTU_TRY_PROTO LPAREN error RPAREN  */
#line 3784 "core/cfg.y"
                { (yyval.action)=0; yyerror("bad argument, UDP, TCP, TLS or SCTP expected"); }
#line 12771 "core/cfg.tab.c"
    break;

  case 973: /* cmd: SET_ADV_ADDRESS LPAREN listen_id RPAREN  */
#line 3785 "core/cfg.y"
                                                  {
		(yyval.action)=0;
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			PKG_MEM_CRITICAL;
		} else {
			str_tmp->s=(yyvsp[-1].strval);
			str_tmp->len=(yyvsp[-1].strval)?strlen((yyvsp[-1].strval)):0;
			(yyval.action)=mk_action(SET_ADV_ADDR_T, 1, STR_ST, str_tmp);
			set_cfg_pos((yyval.action));
		}
	}
#line 12787 "core/cfg.tab.c"
    break;

  case 974: /* cmd: SET_ADV_ADDRESS LPAREN error RPAREN  */
#line 3796 "core/cfg.y"
                                              { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12793 "core/cfg.tab.c"
    break;

  case 975: /* cmd: SET_ADV_ADDRESS error  */
#line 3797 "core/cfg.y"
                                {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12799 "core/cfg.tab.c"
    break;

  case 976: /* cmd: SET_ADV_PORT LPAREN NUMBER RPAREN  */
#line 3798 "core/cfg.y"
                                            {
		(yyval.action)=0;
		tmp=int2str((yyvsp[-1].intval), &i_tmp);
		if ((str_tmp=pkg_malloc(sizeof(str)))==0) {
			PKG_MEM_CRITICAL;
		} else {
			if ((str_tmp->s=pkg_malloc(i_tmp))==0) {
				PKG_MEM_CRITICAL;
			} else {
				memcpy(str_tmp->s, tmp, i_tmp);
				str_tmp->len=i_tmp;
				(yyval.action)=mk_action(SET_ADV_PORT_T, 1, STR_ST, str_tmp);
				set_cfg_pos((yyval.action));
			}
		}
	}
#line 12820 "core/cfg.tab.c"
    break;

  case 977: /* cmd: SET_ADV_PORT LPAREN error RPAREN  */
#line 3814 "core/cfg.y"
                                           { (yyval.action)=0; yyerror("bad argument, string expected"); }
#line 12826 "core/cfg.tab.c"
    break;

  case 978: /* cmd: SET_ADV_PORT error  */
#line 3815 "core/cfg.y"
                              {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12832 "core/cfg.tab.c"
    break;

  case 979: /* cmd: FORCE_SEND_SOCKET LPAREN phostport RPAREN  */
#line 3816 "core/cfg.y"
                                                    {
		(yyval.action)=mk_action(FORCE_SEND_SOCKET_T, 1, SOCKID_ST, (yyvsp[-1].sockid));
		set_cfg_pos((yyval.action));
	}
#line 12841 "core/cfg.tab.c"
    break;

  case 980: /* cmd: FORCE_SEND_SOCKET LPAREN error RPAREN  */
#line 3820 "core/cfg.y"
                                                {
		(yyval.action)=0; yyerror("bad argument, [proto:]host[:port] expected");
	}
#line 12849 "core/cfg.tab.c"
    break;

  case 981: /* cmd: FORCE_SEND_SOCKET error  */
#line 3823 "core/cfg.y"
                                  {(yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12855 "core/cfg.tab.c"
    break;

  case 982: /* cmd: SET_FWD_NO_CONNECT LPAREN RPAREN  */
#line 3824 "core/cfg.y"
                                                {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 12863 "core/cfg.tab.c"
    break;

  case 983: /* cmd: SET_FWD_NO_CONNECT  */
#line 3827 "core/cfg.y"
                                {
		(yyval.action)=mk_action(SET_FWD_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 12871 "core/cfg.tab.c"
    break;

  case 984: /* cmd: SET_RPL_NO_CONNECT LPAREN RPAREN  */
#line 3830 "core/cfg.y"
                                                {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 12879 "core/cfg.tab.c"
    break;

  case 985: /* cmd: SET_RPL_NO_CONNECT  */
#line 3833 "core/cfg.y"
                                {
		(yyval.action)=mk_action(SET_RPL_NO_CONNECT_T, 0); set_cfg_pos((yyval.action));
	}
#line 12887 "core/cfg.tab.c"
    break;

  case 986: /* cmd: SET_FWD_CLOSE LPAREN RPAREN  */
#line 3836 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 12895 "core/cfg.tab.c"
    break;

  case 987: /* cmd: SET_FWD_CLOSE  */
#line 3839 "core/cfg.y"
                        {
		(yyval.action)=mk_action(SET_FWD_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 12903 "core/cfg.tab.c"
    break;

  case 988: /* cmd: SET_RPL_CLOSE LPAREN RPAREN  */
#line 3842 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 12911 "core/cfg.tab.c"
    break;

  case 989: /* cmd: SET_RPL_CLOSE  */
#line 3845 "core/cfg.y"
                        {
		(yyval.action)=mk_action(SET_RPL_CLOSE_T, 0); set_cfg_pos((yyval.action));
	}
#line 12919 "core/cfg.tab.c"
    break;

  case 990: /* cmd: CFG_SELECT LPAREN STRING COMMA NUMBER RPAREN  */
#line 3848 "core/cfg.y"
                                                       {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), NUMBER_ST, (void*)(yyvsp[-1].intval)); set_cfg_pos((yyval.action));
	}
#line 12927 "core/cfg.tab.c"
    break;

  case 991: /* cmd: CFG_SELECT LPAREN STRING COMMA rval_expr RPAREN  */
#line 3851 "core/cfg.y"
                                                          {
		(yyval.action)=mk_action(CFG_SELECT_T, 2, STRING_ST, (yyvsp[-3].strval), RVE_ST, (yyvsp[-1].rv_expr)); set_cfg_pos((yyval.action));
	}
#line 12935 "core/cfg.tab.c"
    break;

  case 992: /* cmd: CFG_SELECT error  */
#line 3854 "core/cfg.y"
                           { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12941 "core/cfg.tab.c"
    break;

  case 993: /* cmd: CFG_SELECT LPAREN error RPAREN  */
#line 3855 "core/cfg.y"
                                         { (yyval.action)=0; yyerror("bad arguments, string and number expected"); }
#line 12947 "core/cfg.tab.c"
    break;

  case 994: /* cmd: CFG_RESET LPAREN STRING RPAREN  */
#line 3856 "core/cfg.y"
                                         {
		(yyval.action)=mk_action(CFG_RESET_T, 1, STRING_ST, (yyvsp[-1].strval)); set_cfg_pos((yyval.action));
	}
#line 12955 "core/cfg.tab.c"
    break;

  case 995: /* cmd: CFG_RESET error  */
#line 3859 "core/cfg.y"
                          { (yyval.action)=0; yyerror("missing '(' or ')' ?"); }
#line 12961 "core/cfg.tab.c"
    break;

  case 996: /* cmd: CFG_RESET LPAREN error RPAREN  */
#line 3860 "core/cfg.y"
                                        { (yyval.action)=0; yyerror("bad arguments, string expected"); }
#line 12967 "core/cfg.tab.c"
    break;

  case 997: /* $@10: %empty  */
#line 3861 "core/cfg.y"
             {
		if (mod_func_action != NULL) {
			LM_ERR("function used inside params of another function: %s\n", (yyvsp[0].strval));
			yyerror("use of function execution inside params not allowed\n");
			ksr_exit(-1);
		}
		mod_func_action = mk_action(MODULE0_T, 2, MODEXP_ST, NULL, NUMBER_ST, 0);
		}
#line 12980 "core/cfg.tab.c"
    break;

  case 998: /* cmd: ID $@10 LPAREN func_params RPAREN  */
#line 3868 "core/cfg.y"
                                                {
		mod_func_action->val[0].u.data =
			find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, rt);
		if (mod_func_action->val[0].u.data == 0) {
			if (find_export_record((yyvsp[-4].strval), mod_func_action->val[1].u.number, 0) ) {
					LM_ERR("misused command %s\n", (yyvsp[-4].strval));
					yyerror("Command cannot be used in the block\n");
			} else {
				LM_ERR("cfg. parser: failed to find command %s (params %ld)\n",
						(yyvsp[-4].strval), mod_func_action->val[1].u.number);
				yyerror("unknown command, missing loadmodule?\n");
			}
			free_mod_func_action(mod_func_action);
			mod_func_action=0;
		}else{
			if (mod_func_action && mod_f_params_pre_fixup(mod_func_action)<0) {
				/* error messages are printed inside the function */
				/* free_mod_func_action(mod_func_action); */
				mod_func_action = 0;
				YYERROR;
			}
		}
		(yyval.action) = mod_func_action;
		set_cfg_pos((yyval.action));
		mod_func_action = NULL;
	}
#line 13011 "core/cfg.tab.c"
    break;

  case 999: /* cmd: ID error  */
#line 3894 "core/cfg.y"
                                                        { yyerror("'('')' expected (function call)");}
#line 13017 "core/cfg.tab.c"
    break;

  case 1001: /* func_params: func_params COMMA func_param  */
#line 3898 "core/cfg.y"
                                       { }
#line 13023 "core/cfg.tab.c"
    break;

  case 1002: /* func_params: func_param  */
#line 3899 "core/cfg.y"
                     {}
#line 13029 "core/cfg.tab.c"
    break;

  case 1003: /* func_param: rval_expr  */
#line 3902 "core/cfg.y"
                  {
		if ((yyvsp[0].rv_expr) && mod_func_action->val[1].u.number < MAX_ACTIONS-2) {
			mod_func_action->val[mod_func_action->val[1].u.number+2].type =
				RVE_ST;
			mod_func_action->val[mod_func_action->val[1].u.number+2].u.data =
				(yyvsp[0].rv_expr);
			mod_func_action->val[1].u.number++;
		} else if ((yyvsp[0].rv_expr)) {
			yyerror("Too many arguments\n");
			YYERROR;
		} else {
			YYERROR;
		}
	}
#line 13048 "core/cfg.tab.c"
    break;

  case 1004: /* ret_cmd: DROP LPAREN RPAREN  */
#line 3919 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 13057 "core/cfg.tab.c"
    break;

  case 1005: /* ret_cmd: DROP rval_expr  */
#line 3923 "core/cfg.y"
                                {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 13066 "core/cfg.tab.c"
    break;

  case 1006: /* ret_cmd: DROP  */
#line 3927 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST,
						(void*)(DROP_R_F|EXIT_R_F)); set_cfg_pos((yyval.action));
	}
#line 13075 "core/cfg.tab.c"
    break;

  case 1007: /* ret_cmd: EXIT LPAREN RPAREN  */
#line 3931 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 13085 "core/cfg.tab.c"
    break;

  case 1008: /* ret_cmd: EXIT rval_expr  */
#line 3936 "core/cfg.y"
                                {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 13094 "core/cfg.tab.c"
    break;

  case 1009: /* ret_cmd: EXIT  */
#line 3940 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)EXIT_R_F);
		set_cfg_pos((yyval.action));
	}
#line 13104 "core/cfg.tab.c"
    break;

  case 1010: /* ret_cmd: RETURN  */
#line 3945 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 13113 "core/cfg.tab.c"
    break;

  case 1011: /* ret_cmd: RETURN LPAREN RPAREN  */
#line 3949 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, (void*)1, NUMBER_ST,
						(void*)RETURN_R_F); set_cfg_pos((yyval.action));
	}
#line 13122 "core/cfg.tab.c"
    break;

  case 1012: /* ret_cmd: RETURN rval_expr  */
#line 3953 "core/cfg.y"
                                {
		(yyval.action)=mk_action(DROP_T, 2, RVE_ST, (yyvsp[0].rv_expr), NUMBER_ST, (void*)RETURN_R_F);
		set_cfg_pos((yyval.action));
	}
#line 13131 "core/cfg.tab.c"
    break;

  case 1013: /* ret_cmd: BREAK  */
#line 3957 "core/cfg.y"
                                        {
		(yyval.action)=mk_action(DROP_T, 2, NUMBER_ST, 0, NUMBER_ST, (void*)BREAK_R_F);
		set_cfg_pos((yyval.action));
	}
#line 13140 "core/cfg.tab.c"
    break;


#line 13144 "core/cfg.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 3963 "core/cfg.y"


static void get_cpos(struct cfg_pos* pos)
{
	pos->s_line=startline;
	pos->e_line=line;
	pos->s_col=startcolumn;
	pos->e_col=column-1;
	if(finame==0)
		finame = (cfg_file!=0)?cfg_file:"default";
	pos->fname=finame;
	pos->rname=(routename!=0)?routename:default_routename;
}


static void warn_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_WARN("warning in config file %s, from line %d, column %d to"
					" line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_WARN("warning in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_WARN("warning in config file %s, line %d, column %d: %s\n",
				p->fname, p->s_line, p->s_col, s);
	cfg_warnings++;
}



static void yyerror_at(struct cfg_pos* p, char* format, ...)
{
	va_list ap;
	char s[256];

	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	if (p->e_line!=p->s_line)
		LM_CRIT("parse error in config file %s, from line %d, column %d"
					" to line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_line, p->e_col, s);
	else if (p->s_col!=p->e_col)
		LM_CRIT("parse error in config file %s, line %d, column %d-%d: %s\n",
					p->fname, p->s_line, p->s_col, p->e_col, s);
	else
		LM_CRIT("parse error in config file %s, line %d, column %d: %s\n",
					p->fname, p->s_line, p->s_col, s);
	cfg_errors++;
	if(ksr_all_errors==0) {
		ksr_exit(-1);
	}
}



static void warn(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	warn_at(&pos, s);
}



static void yyerror(char* format, ...)
{
	va_list ap;
	char s[256];
	struct cfg_pos pos;

	get_cpos(&pos);
	va_start(ap, format);
	vsnprintf(s, sizeof(s), format, ap);
	va_end(ap);
	yyerror_at(&pos, s);
}



/** mk_rval_expr_v wrapper.
 *  checks mk_rval_expr_v return value and sets the cfg. pos
 *  (line and column numbers)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr_v)
 */
static struct rval_expr* mk_rve_rval(enum rval_type type, void* v)
{
	struct rval_expr* ret;
	struct cfg_pos pos;

	get_cpos(&pos);
	ret=mk_rval_expr_v(type, v, &pos);
	if (ret==0){
		yyerror("internal error: failed to create rval expr");
		/* YYABORT; */
	}
	return ret;
}


/** mk_rval_expr1 wrapper.
 *  checks mk_rval_expr1 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr1)
 */
static struct rval_expr* mk_rve1(enum rval_expr_op op, struct rval_expr* rve1)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve1==0)
		return 0;
	ret=mk_rval_expr1(op, rve1, &rve1->fpos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		yyerror_at(&rve1->fpos, "bad expression: type mismatch"
					" (%s instead of %s)", rval_type_name(bad_t),
					rval_type_name(exp_t));
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** mk_rval_expr2 wrapper.
 *  checks mk_rval_expr2 return value (!=0 and type checking)
 *  @return rval_expr* on success, 0 on error (@see mk_rval_expr2)
 */
static struct rval_expr* mk_rve2(enum rval_expr_op op, struct rval_expr* rve1,
									struct rval_expr* rve2)
{
	struct rval_expr* ret;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	struct cfg_pos pos;

	if ((rve1==0) || (rve2==0))
		return 0;
	bad_rve=0;
	bad_t=0;
	exp_t=0;
	cfg_pos_join(&pos, &rve1->fpos, &rve2->fpos);
	ret=mk_rval_expr2(op, rve1, rve2, &pos);
	if (ret && (rve_check_type(&type, ret, &bad_rve, &bad_t, &exp_t)!=1)){
		if (bad_rve)
			yyerror_at(&pos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		rve_destroy(ret);
		ret=0;
	}
	return ret;
}


/** check if the expression is an int.
 * if the expression does not evaluate to an int return -1 and
 * log an error.
 * @return 0 success, no warnings; 1 success but warnings; -1 on error */
static int rval_expr_int_check(struct rval_expr *rve)
{
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;

	if (rve==0){
		yyerror("invalid expression");
		return -1;
	}else if (!rve_check_type(&type, rve, &bad_rve, &bad_t ,&exp_t)){
		if (bad_rve)
			yyerror_at(&rve->fpos, "bad expression: type mismatch:"
						" %s instead of %s at (%d,%d)",
						rval_type_name(bad_t), rval_type_name(exp_t),
						bad_rve->fpos.s_line, bad_rve->fpos.s_col);
		else
			yyerror("BUG: unexpected null \"bad\" expression\n");
		return -1;
	}else if (type!=RV_LONG && type!=RV_NONE){
		warn_at(&rve->fpos, "non-int expression (you might want to use"
				" casts)\n");
		return 1;
	}
	return 0;
}


/** warn if the expression is constant.
 * @return 0 on success (no warning), 1 when warning */
static int warn_ct_rve(struct rval_expr *rve, char* name)
{
	if (rve && rve_is_constant(rve)){
		warn_at(&rve->fpos, "constant value in %s%s",
				name?name:"expression", name?"(...)":"");
		return 1;
	}
	return 0;
}


static struct name_lst* mk_name_lst(char* host, int flags)
{
	struct name_lst* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct name_lst));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		memset(l, 0, sizeof(struct name_lst));
		l->name=host;
		l->flags=flags;
		l->next=0;
	}
	return l;
}


static struct socket_id* mk_listen_id(char* host, int proto, int port)
{
	struct socket_id* l;
	if (host==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		memset(l, 0, sizeof(struct socket_id));
		l->addr_lst=mk_name_lst(host, 0);
		if (l->addr_lst==0){
			pkg_free(l);
			return 0;
		}
		l->flags=0;
		l->port=port;
		l->proto=proto;
		l->next=0;
	}
	return l;
}


static void free_name_lst(struct name_lst* lst)
{
	struct name_lst* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		pkg_free(tmp);
	}
}


static struct socket_id* mk_listen_id2(struct name_lst* addr_l, int proto,
										int port)
{
	struct socket_id* l;
	if (addr_l==0) return 0;
	l=pkg_malloc(sizeof(struct socket_id));
	if (l==0) {
		PKG_MEM_CRITICAL;
	} else {
		memset(l, 0, sizeof(struct socket_id));
		l->flags=addr_l->flags;
		l->port=port;
		l->proto=proto;
		l->addr_lst=addr_l;
		l->next=0;
	}
	return l;
}


static void free_socket_id(struct socket_id* i)
{
	free_name_lst(i->addr_lst);
	pkg_free(i);
}


static void free_socket_id_lst(struct socket_id* lst)
{
	struct socket_id* tmp;

	while(lst){
		tmp=lst;
		lst=lst->next;
		free_socket_id(tmp);
	}
}


/** create a temporary case statmenet structure.
 *  *err will be filled in case of error (return == 0):
 *   -1 - non constant expression
 *   -2 - expression error (bad type)
 *   -10 - memory allocation error
 */
static struct case_stms* mk_case_stm(struct rval_expr* ct, int is_re,
											struct action* a, int* err)
{
	struct case_stms* s;
	struct rval_expr* bad_rve;
	enum rval_type type, bad_t, exp_t;
	enum match_str_type t;

	t=MATCH_UNKNOWN;
	if (ct){
		/* if ct!=0 => case, else if ct==0 is a default */
		if (!rve_is_constant(ct)){
			yyerror_at(&ct->fpos, "non constant expression in case");
			*err=-1;
			return 0;
		}
		if (rve_check_type(&type, ct, &bad_rve, &bad_t, &exp_t)!=1){
			yyerror_at(&ct->fpos, "bad expression: type mismatch:"
							" %s instead of %s at (%d,%d)",
							rval_type_name(bad_t), rval_type_name(exp_t),
							bad_rve->fpos.s_line, bad_rve->fpos.s_col);
			*err=-2;
			return 0;
		}
		if (is_re)
			t=MATCH_RE;
		else if (type==RV_STR)
			t=MATCH_STR;
		else
			t=MATCH_INT;
	}

	s=pkg_malloc(sizeof(*s));
	if (s==0) {
		yyerror("internal error: memory allocation failure");
		*err=-10;
	} else {
		memset(s, 0, sizeof(*s));
		s->ct_rve=ct;
		s->type=t;
		s->actions=a;
		s->next=0;
		s->append=0;
	}
	return s;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_type(struct case_stms* stms)
{
	struct case_stms* c;
	struct case_stms* s;

	for(c=stms; c ; c=c->next){
		if (!c->ct_rve) continue;
		for (s=c->next; s; s=s->next){
			if (!s->ct_rve) continue;
			if ((s->type!=c->type) &&
				!(	(c->type==MATCH_STR || c->type==MATCH_RE) &&
					(s->type==MATCH_STR || s->type==MATCH_RE) ) ){
					yyerror_at(&s->ct_rve->fpos, "type mismatch in case");
					return -1;
			}
		}
	}
	return 0;
}


/*
 * @return 0 on success, -1 on error.
 */
static int case_check_default(struct case_stms* stms)
{
	struct case_stms* c;
	int default_no;

	default_no=0;
	for(c=stms; c ; c=c->next)
		if (c->ct_rve==0) default_no++;
	return (default_no<=1)?0:-1;
}



/** fixes the parameters and the type of a module function call.
 * It is done here instead of fix action, to have quicker feedback
 * on error cases (e.g. passing a non constant to a function with a
 * declared fixup)
 * The rest of the fixup is done inside do_action().
 * @param a - filled module function call (MODULE*_T) action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 * @return 0 on success, -1 on error (it will also print the error msg.).
 *
 */
static int mod_f_params_pre_fixup(struct action* a)
{
	ksr_cmd_export_t* cmd_exp;
	action_u_t* params;
	int param_no;
	struct rval_expr* rve;
	struct rvalue* rv;
	int r;
	str s;

	cmd_exp = a->val[0].u.data;
	param_no = a->val[1].u.number;
	params = &a->val[2];

	switch(cmd_exp->param_no) {
		case 0:
			a->type = MODULE0_T;
			break;
		case 1:
			a->type = MODULE1_T;
			break;
		case 2:
			a->type = MODULE2_T;
			break;
		case 3:
			a->type = MODULE3_T;
			break;
		case 4:
			a->type = MODULE4_T;
			break;
		case 5:
			a->type = MODULE5_T;
			break;
		case 6:
			a->type = MODULE6_T;
			break;
		case VAR_PARAM_NO:
			a->type = MODULEX_T;
			break;
		default:
			yyerror("function %s: bad definition"
					" (invalid number of parameters)", cmd_exp->name);
			return -1;
	}

	if ( cmd_exp->fixup) {
		if (is_fparam_rve_fixup(cmd_exp->fixup))
			/* mark known fparam rve safe fixups */
			cmd_exp->fixup_flags  |= FIXUP_F_FPARAM_RVE;
		else if (!(cmd_exp->fixup_flags & FIXUP_F_FPARAM_RVE) &&
				 cmd_exp->free_fixup == 0) {
			/* v0 or v1 functions that have fixups and no corresp. fixup_free
			   functions, need constant, string params.*/
			for (r=0; r < param_no; r++) {
				rve=params[r].u.data;
				if (!rve_is_constant(rve)) {
					yyerror_at(&rve->fpos, "function %s: parameter %d is not"
								" constant\n", cmd_exp->name, r+1);
					return -1;
				}
				if ((rv = rval_expr_eval(0, 0, rve)) == 0 ||
						rval_get_str(0, 0, &s, rv, 0) < 0 ) {
					/* out of mem or bug ? */
					rval_destroy(rv);
					yyerror_at(&rve->fpos, "function %s: bad parameter %d"
									" expression\n", cmd_exp->name, r+1);
					return -1;
				}
				rval_destroy(rv);
				rve_destroy(rve);
				params[r].type = STRING_ST; /* asciiz */
				params[r].u.string = s.s;
				params[r].u.str.len = s.len; /* not used right now */
			}
		}
	}/* else
		if no fixups are present, the RVEs can be transformed
		into strings at runtime, allowing seamless var. use
		even with old functions.
		Further optimizations -> in fix_actions()
		*/
	return 0;
}



/** frees a filled module function call action structure.
 * @param a - filled module function call action structure
 *            complete with parameters, starting at val[2] and parameter
 *            number at val[1].
 */
static void free_mod_func_action(struct action* a)
{
	action_u_t* params;
	int param_no;
	int r;

	param_no = a->val[1].u.number;
	params = &a->val[2];

	for (r=0; r < param_no; r++)
		if (params[r].u.data)
			rve_destroy(params[r].u.data);
	pkg_free(a);
}



/*
int main(int argc, char ** argv)
{
	if (yyparse()!=0)
		fprintf(stderr, "parsing error\n");
}
*/
