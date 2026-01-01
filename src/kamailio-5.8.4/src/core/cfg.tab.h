/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CORE_CFG_TAB_H_INCLUDED
# define YY_YY_CORE_CFG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FORWARD = 258,                 /* FORWARD  */
    FORWARD_TCP = 259,             /* FORWARD_TCP  */
    FORWARD_TLS = 260,             /* FORWARD_TLS  */
    FORWARD_SCTP = 261,            /* FORWARD_SCTP  */
    FORWARD_UDP = 262,             /* FORWARD_UDP  */
    EXIT = 263,                    /* EXIT  */
    DROP = 264,                    /* DROP  */
    RETURN = 265,                  /* RETURN  */
    RETURN_MODE = 266,             /* RETURN_MODE  */
    BREAK = 267,                   /* BREAK  */
    LOG_TOK = 268,                 /* LOG_TOK  */
    ERROR = 269,                   /* ERROR  */
    ROUTE = 270,                   /* ROUTE  */
    ROUTE_REQUEST = 271,           /* ROUTE_REQUEST  */
    ROUTE_FAILURE = 272,           /* ROUTE_FAILURE  */
    ROUTE_ONREPLY = 273,           /* ROUTE_ONREPLY  */
    ROUTE_REPLY = 274,             /* ROUTE_REPLY  */
    ROUTE_BRANCH = 275,            /* ROUTE_BRANCH  */
    ROUTE_SEND = 276,              /* ROUTE_SEND  */
    ROUTE_EVENT = 277,             /* ROUTE_EVENT  */
    EXEC = 278,                    /* EXEC  */
    SET_HOST = 279,                /* SET_HOST  */
    SET_HOSTPORT = 280,            /* SET_HOSTPORT  */
    SET_HOSTPORTTRANS = 281,       /* SET_HOSTPORTTRANS  */
    PREFIX = 282,                  /* PREFIX  */
    STRIP = 283,                   /* STRIP  */
    STRIP_TAIL = 284,              /* STRIP_TAIL  */
    SET_USERPHONE = 285,           /* SET_USERPHONE  */
    APPEND_BRANCH = 286,           /* APPEND_BRANCH  */
    REMOVE_BRANCH = 287,           /* REMOVE_BRANCH  */
    CLEAR_BRANCHES = 288,          /* CLEAR_BRANCHES  */
    SET_USER = 289,                /* SET_USER  */
    SET_USERPASS = 290,            /* SET_USERPASS  */
    SET_PORT = 291,                /* SET_PORT  */
    SET_URI = 292,                 /* SET_URI  */
    REVERT_URI = 293,              /* REVERT_URI  */
    FORCE_RPORT = 294,             /* FORCE_RPORT  */
    ADD_LOCAL_RPORT = 295,         /* ADD_LOCAL_RPORT  */
    LOCAL_RPORT = 296,             /* LOCAL_RPORT  */
    FORCE_TCP_ALIAS = 297,         /* FORCE_TCP_ALIAS  */
    UDP_MTU = 298,                 /* UDP_MTU  */
    UDP_MTU_TRY_PROTO = 299,       /* UDP_MTU_TRY_PROTO  */
    UDP4_RAW = 300,                /* UDP4_RAW  */
    UDP4_RAW_MTU = 301,            /* UDP4_RAW_MTU  */
    UDP4_RAW_TTL = 302,            /* UDP4_RAW_TTL  */
    IF = 303,                      /* IF  */
    ELSE = 304,                    /* ELSE  */
    SET_ADV_ADDRESS = 305,         /* SET_ADV_ADDRESS  */
    SET_ADV_PORT = 306,            /* SET_ADV_PORT  */
    FORCE_SEND_SOCKET = 307,       /* FORCE_SEND_SOCKET  */
    SET_FWD_NO_CONNECT = 308,      /* SET_FWD_NO_CONNECT  */
    SET_RPL_NO_CONNECT = 309,      /* SET_RPL_NO_CONNECT  */
    SET_FWD_CLOSE = 310,           /* SET_FWD_CLOSE  */
    SET_RPL_CLOSE = 311,           /* SET_RPL_CLOSE  */
    SWITCH = 312,                  /* SWITCH  */
    CASE = 313,                    /* CASE  */
    DEFAULT = 314,                 /* DEFAULT  */
    WHILE = 315,                   /* WHILE  */
    CFG_SELECT = 316,              /* CFG_SELECT  */
    CFG_RESET = 317,               /* CFG_RESET  */
    URIHOST = 318,                 /* URIHOST  */
    URIPORT = 319,                 /* URIPORT  */
    MAX_LEN = 320,                 /* MAX_LEN  */
    SETFLAG = 321,                 /* SETFLAG  */
    RESETFLAG = 322,               /* RESETFLAG  */
    ISFLAGSET = 323,               /* ISFLAGSET  */
    SETAVPFLAG = 324,              /* SETAVPFLAG  */
    RESETAVPFLAG = 325,            /* RESETAVPFLAG  */
    ISAVPFLAGSET = 326,            /* ISAVPFLAGSET  */
    METHOD = 327,                  /* METHOD  */
    URI = 328,                     /* URI  */
    FROM_URI = 329,                /* FROM_URI  */
    TO_URI = 330,                  /* TO_URI  */
    SRCIP = 331,                   /* SRCIP  */
    SRCPORT = 332,                 /* SRCPORT  */
    DSTIP = 333,                   /* DSTIP  */
    DSTPORT = 334,                 /* DSTPORT  */
    TOIP = 335,                    /* TOIP  */
    TOPORT = 336,                  /* TOPORT  */
    SNDIP = 337,                   /* SNDIP  */
    SNDPORT = 338,                 /* SNDPORT  */
    SNDPROTO = 339,                /* SNDPROTO  */
    SNDAF = 340,                   /* SNDAF  */
    PROTO = 341,                   /* PROTO  */
    AF = 342,                      /* AF  */
    MYSELF = 343,                  /* MYSELF  */
    MSGLEN = 344,                  /* MSGLEN  */
    UDP = 345,                     /* UDP  */
    TCP = 346,                     /* TCP  */
    TLS = 347,                     /* TLS  */
    SCTP = 348,                    /* SCTP  */
    WS = 349,                      /* WS  */
    WSS = 350,                     /* WSS  */
    DEBUG_V = 351,                 /* DEBUG_V  */
    FORK = 352,                    /* FORK  */
    FORK_DELAY = 353,              /* FORK_DELAY  */
    MODINIT_DELAY = 354,           /* MODINIT_DELAY  */
    LOGSTDERROR = 355,             /* LOGSTDERROR  */
    LOGFACILITY = 356,             /* LOGFACILITY  */
    LOGNAME = 357,                 /* LOGNAME  */
    LOGCOLOR = 358,                /* LOGCOLOR  */
    LOGPREFIX = 359,               /* LOGPREFIX  */
    LOGPREFIXMODE = 360,           /* LOGPREFIXMODE  */
    LOGENGINETYPE = 361,           /* LOGENGINETYPE  */
    LOGENGINEDATA = 362,           /* LOGENGINEDATA  */
    XAVPVIAPARAMS = 363,           /* XAVPVIAPARAMS  */
    XAVPVIAFIELDS = 364,           /* XAVPVIAFIELDS  */
    XAVPVIAREPLYPARAMS = 365,      /* XAVPVIAREPLYPARAMS  */
    LISTEN = 366,                  /* LISTEN  */
    ADVERTISE = 367,               /* ADVERTISE  */
    VIRTUAL = 368,                 /* VIRTUAL  */
    STRNAME = 369,                 /* STRNAME  */
    ALIAS = 370,                   /* ALIAS  */
    SR_AUTO_ALIASES = 371,         /* SR_AUTO_ALIASES  */
    DOMAIN = 372,                  /* DOMAIN  */
    SR_AUTO_DOMAINS = 373,         /* SR_AUTO_DOMAINS  */
    DNS = 374,                     /* DNS  */
    REV_DNS = 375,                 /* REV_DNS  */
    DNS_TRY_IPV6 = 376,            /* DNS_TRY_IPV6  */
    DNS_TRY_NAPTR = 377,           /* DNS_TRY_NAPTR  */
    DNS_SRV_LB = 378,              /* DNS_SRV_LB  */
    DNS_UDP_PREF = 379,            /* DNS_UDP_PREF  */
    DNS_TCP_PREF = 380,            /* DNS_TCP_PREF  */
    DNS_TLS_PREF = 381,            /* DNS_TLS_PREF  */
    DNS_SCTP_PREF = 382,           /* DNS_SCTP_PREF  */
    DNS_RETR_TIME = 383,           /* DNS_RETR_TIME  */
    DNS_SLOW_QUERY_MS = 384,       /* DNS_SLOW_QUERY_MS  */
    DNS_RETR_NO = 385,             /* DNS_RETR_NO  */
    DNS_SERVERS_NO = 386,          /* DNS_SERVERS_NO  */
    DNS_USE_SEARCH = 387,          /* DNS_USE_SEARCH  */
    DNS_SEARCH_FMATCH = 388,       /* DNS_SEARCH_FMATCH  */
    DNS_NAPTR_IGNORE_RFC = 389,    /* DNS_NAPTR_IGNORE_RFC  */
    DNS_CACHE_INIT = 390,          /* DNS_CACHE_INIT  */
    DNS_USE_CACHE = 391,           /* DNS_USE_CACHE  */
    DNS_USE_FAILOVER = 392,        /* DNS_USE_FAILOVER  */
    DNS_CACHE_FLAGS = 393,         /* DNS_CACHE_FLAGS  */
    DNS_CACHE_NEG_TTL = 394,       /* DNS_CACHE_NEG_TTL  */
    DNS_CACHE_MIN_TTL = 395,       /* DNS_CACHE_MIN_TTL  */
    DNS_CACHE_MAX_TTL = 396,       /* DNS_CACHE_MAX_TTL  */
    DNS_CACHE_MEM = 397,           /* DNS_CACHE_MEM  */
    DNS_CACHE_GC_INT = 398,        /* DNS_CACHE_GC_INT  */
    DNS_CACHE_DEL_NONEXP = 399,    /* DNS_CACHE_DEL_NONEXP  */
    DNS_CACHE_REC_PREF = 400,      /* DNS_CACHE_REC_PREF  */
    AUTO_BIND_IPV6 = 401,          /* AUTO_BIND_IPV6  */
    BIND_IPV6_LINK_LOCAL = 402,    /* BIND_IPV6_LINK_LOCAL  */
    IPV6_HEX_STYLE = 403,          /* IPV6_HEX_STYLE  */
    DST_BLST_INIT = 404,           /* DST_BLST_INIT  */
    USE_DST_BLST = 405,            /* USE_DST_BLST  */
    DST_BLST_MEM = 406,            /* DST_BLST_MEM  */
    DST_BLST_TTL = 407,            /* DST_BLST_TTL  */
    DST_BLST_GC_INT = 408,         /* DST_BLST_GC_INT  */
    DST_BLST_UDP_IMASK = 409,      /* DST_BLST_UDP_IMASK  */
    DST_BLST_TCP_IMASK = 410,      /* DST_BLST_TCP_IMASK  */
    DST_BLST_TLS_IMASK = 411,      /* DST_BLST_TLS_IMASK  */
    DST_BLST_SCTP_IMASK = 412,     /* DST_BLST_SCTP_IMASK  */
    IP_FREE_BIND = 413,            /* IP_FREE_BIND  */
    PORT = 414,                    /* PORT  */
    STAT = 415,                    /* STAT  */
    STATS_NAMESEP = 416,           /* STATS_NAMESEP  */
    CHILDREN = 417,                /* CHILDREN  */
    SOCKET = 418,                  /* SOCKET  */
    BIND = 419,                    /* BIND  */
    WORKERS = 420,                 /* WORKERS  */
    SOCKET_WORKERS = 421,          /* SOCKET_WORKERS  */
    ASYNC_WORKERS = 422,           /* ASYNC_WORKERS  */
    ASYNC_USLEEP = 423,            /* ASYNC_USLEEP  */
    ASYNC_NONBLOCK = 424,          /* ASYNC_NONBLOCK  */
    ASYNC_WORKERS_GROUP = 425,     /* ASYNC_WORKERS_GROUP  */
    CHECK_VIA = 426,               /* CHECK_VIA  */
    PHONE2TEL = 427,               /* PHONE2TEL  */
    MEMLOG = 428,                  /* MEMLOG  */
    MEMDBG = 429,                  /* MEMDBG  */
    MEMSUM = 430,                  /* MEMSUM  */
    MEMSAFETY = 431,               /* MEMSAFETY  */
    MEMADDSIZE = 432,              /* MEMADDSIZE  */
    MEMJOIN = 433,                 /* MEMJOIN  */
    MEMSTATUSMODE = 434,           /* MEMSTATUSMODE  */
    SIP_PARSER_LOG_ONELINE = 435,  /* SIP_PARSER_LOG_ONELINE  */
    SIP_PARSER_LOG = 436,          /* SIP_PARSER_LOG  */
    SIP_PARSER_MODE = 437,         /* SIP_PARSER_MODE  */
    CORELOG = 438,                 /* CORELOG  */
    SIP_WARNING = 439,             /* SIP_WARNING  */
    SERVER_SIGNATURE = 440,        /* SERVER_SIGNATURE  */
    SERVER_HEADER = 441,           /* SERVER_HEADER  */
    USER_AGENT_HEADER = 442,       /* USER_AGENT_HEADER  */
    REPLY_TO_VIA = 443,            /* REPLY_TO_VIA  */
    LOADMODULE = 444,              /* LOADMODULE  */
    LOADMODULEX = 445,             /* LOADMODULEX  */
    LOADPATH = 446,                /* LOADPATH  */
    MODPARAM = 447,                /* MODPARAM  */
    MODPARAMX = 448,               /* MODPARAMX  */
    CFGENGINE = 449,               /* CFGENGINE  */
    MAXBUFFER = 450,               /* MAXBUFFER  */
    MAXSNDBUFFER = 451,            /* MAXSNDBUFFER  */
    SQL_BUFFER_SIZE = 452,         /* SQL_BUFFER_SIZE  */
    MSG_RECV_MAX_SIZE = 453,       /* MSG_RECV_MAX_SIZE  */
    TCP_MSG_READ_TIMEOUT = 454,    /* TCP_MSG_READ_TIMEOUT  */
    TCP_MSG_DATA_TIMEOUT = 455,    /* TCP_MSG_DATA_TIMEOUT  */
    TCP_ACCEPT_IPLIMIT = 456,      /* TCP_ACCEPT_IPLIMIT  */
    TCP_CHECK_TIMER = 457,         /* TCP_CHECK_TIMER  */
    USER = 458,                    /* USER  */
    GROUP = 459,                   /* GROUP  */
    CHROOT = 460,                  /* CHROOT  */
    WDIR = 461,                    /* WDIR  */
    RUNDIR = 462,                  /* RUNDIR  */
    MHOMED = 463,                  /* MHOMED  */
    DISABLE_TCP = 464,             /* DISABLE_TCP  */
    TCP_ACCEPT_ALIASES = 465,      /* TCP_ACCEPT_ALIASES  */
    TCP_ACCEPT_UNIQUE = 466,       /* TCP_ACCEPT_UNIQUE  */
    TCP_CONNECTION_MATCH = 467,    /* TCP_CONNECTION_MATCH  */
    TCP_CHILDREN = 468,            /* TCP_CHILDREN  */
    TCP_CONNECT_TIMEOUT = 469,     /* TCP_CONNECT_TIMEOUT  */
    TCP_SEND_TIMEOUT = 470,        /* TCP_SEND_TIMEOUT  */
    TCP_CON_LIFETIME = 471,        /* TCP_CON_LIFETIME  */
    TCP_POLL_METHOD = 472,         /* TCP_POLL_METHOD  */
    TCP_MAX_CONNECTIONS = 473,     /* TCP_MAX_CONNECTIONS  */
    TLS_MAX_CONNECTIONS = 474,     /* TLS_MAX_CONNECTIONS  */
    TCP_NO_CONNECT = 475,          /* TCP_NO_CONNECT  */
    TCP_SOURCE_IPV4 = 476,         /* TCP_SOURCE_IPV4  */
    TCP_SOURCE_IPV6 = 477,         /* TCP_SOURCE_IPV6  */
    TCP_OPT_FD_CACHE = 478,        /* TCP_OPT_FD_CACHE  */
    TCP_OPT_BUF_WRITE = 479,       /* TCP_OPT_BUF_WRITE  */
    TCP_OPT_CONN_WQ_MAX = 480,     /* TCP_OPT_CONN_WQ_MAX  */
    TCP_OPT_WQ_MAX = 481,          /* TCP_OPT_WQ_MAX  */
    TCP_OPT_RD_BUF = 482,          /* TCP_OPT_RD_BUF  */
    TCP_OPT_WQ_BLK = 483,          /* TCP_OPT_WQ_BLK  */
    TCP_OPT_DEFER_ACCEPT = 484,    /* TCP_OPT_DEFER_ACCEPT  */
    TCP_OPT_DELAYED_ACK = 485,     /* TCP_OPT_DELAYED_ACK  */
    TCP_OPT_SYNCNT = 486,          /* TCP_OPT_SYNCNT  */
    TCP_OPT_LINGER2 = 487,         /* TCP_OPT_LINGER2  */
    TCP_OPT_KEEPALIVE = 488,       /* TCP_OPT_KEEPALIVE  */
    TCP_OPT_KEEPIDLE = 489,        /* TCP_OPT_KEEPIDLE  */
    TCP_OPT_KEEPINTVL = 490,       /* TCP_OPT_KEEPINTVL  */
    TCP_OPT_KEEPCNT = 491,         /* TCP_OPT_KEEPCNT  */
    TCP_OPT_CRLF_PING = 492,       /* TCP_OPT_CRLF_PING  */
    TCP_OPT_ACCEPT_NO_CL = 493,    /* TCP_OPT_ACCEPT_NO_CL  */
    TCP_OPT_ACCEPT_HEP3 = 494,     /* TCP_OPT_ACCEPT_HEP3  */
    TCP_OPT_ACCEPT_HAPROXY = 495,  /* TCP_OPT_ACCEPT_HAPROXY  */
    TCP_OPT_CLOSE_RST = 496,       /* TCP_OPT_CLOSE_RST  */
    TCP_CLONE_RCVBUF = 497,        /* TCP_CLONE_RCVBUF  */
    TCP_REUSE_PORT = 498,          /* TCP_REUSE_PORT  */
    TCP_WAIT_DATA = 499,           /* TCP_WAIT_DATA  */
    TCP_SCRIPT_MODE = 500,         /* TCP_SCRIPT_MODE  */
    DISABLE_TLS = 501,             /* DISABLE_TLS  */
    ENABLE_TLS = 502,              /* ENABLE_TLS  */
    TLS_THREADS_MODE = 503,        /* TLS_THREADS_MODE  */
    TLSLOG = 504,                  /* TLSLOG  */
    TLS_PORT_NO = 505,             /* TLS_PORT_NO  */
    TLS_METHOD = 506,              /* TLS_METHOD  */
    TLS_HANDSHAKE_TIMEOUT = 507,   /* TLS_HANDSHAKE_TIMEOUT  */
    TLS_SEND_TIMEOUT = 508,        /* TLS_SEND_TIMEOUT  */
    SSLv23 = 509,                  /* SSLv23  */
    SSLv2 = 510,                   /* SSLv2  */
    SSLv3 = 511,                   /* SSLv3  */
    TLSv1 = 512,                   /* TLSv1  */
    TLS_VERIFY = 513,              /* TLS_VERIFY  */
    TLS_REQUIRE_CERTIFICATE = 514, /* TLS_REQUIRE_CERTIFICATE  */
    TLS_CERTIFICATE = 515,         /* TLS_CERTIFICATE  */
    TLS_PRIVATE_KEY = 516,         /* TLS_PRIVATE_KEY  */
    TLS_CA_LIST = 517,             /* TLS_CA_LIST  */
    DISABLE_SCTP = 518,            /* DISABLE_SCTP  */
    ENABLE_SCTP = 519,             /* ENABLE_SCTP  */
    SCTP_CHILDREN = 520,           /* SCTP_CHILDREN  */
    ADVERTISED_ADDRESS = 521,      /* ADVERTISED_ADDRESS  */
    ADVERTISED_PORT = 522,         /* ADVERTISED_PORT  */
    DISABLE_CORE = 523,            /* DISABLE_CORE  */
    OPEN_FD_LIMIT = 524,           /* OPEN_FD_LIMIT  */
    SHM_MEM_SZ = 525,              /* SHM_MEM_SZ  */
    SHM_FORCE_ALLOC = 526,         /* SHM_FORCE_ALLOC  */
    MLOCK_PAGES = 527,             /* MLOCK_PAGES  */
    REAL_TIME = 528,               /* REAL_TIME  */
    RT_PRIO = 529,                 /* RT_PRIO  */
    RT_POLICY = 530,               /* RT_POLICY  */
    RT_TIMER1_PRIO = 531,          /* RT_TIMER1_PRIO  */
    RT_TIMER1_POLICY = 532,        /* RT_TIMER1_POLICY  */
    RT_TIMER2_PRIO = 533,          /* RT_TIMER2_PRIO  */
    RT_TIMER2_POLICY = 534,        /* RT_TIMER2_POLICY  */
    MCAST_LOOPBACK = 535,          /* MCAST_LOOPBACK  */
    MCAST_TTL = 536,               /* MCAST_TTL  */
    MCAST = 537,                   /* MCAST  */
    TOS = 538,                     /* TOS  */
    PMTU_DISCOVERY = 539,          /* PMTU_DISCOVERY  */
    KILL_TIMEOUT = 540,            /* KILL_TIMEOUT  */
    MAX_WLOOPS = 541,              /* MAX_WLOOPS  */
    PVBUFSIZE = 542,               /* PVBUFSIZE  */
    PVBUFSLOTS = 543,              /* PVBUFSLOTS  */
    PVCACHELIMIT = 544,            /* PVCACHELIMIT  */
    PVCACHEACTION = 545,           /* PVCACHEACTION  */
    HTTP_REPLY_PARSE = 546,        /* HTTP_REPLY_PARSE  */
    VERSION_TABLE_CFG = 547,       /* VERSION_TABLE_CFG  */
    VERBOSE_STARTUP = 548,         /* VERBOSE_STARTUP  */
    ROUTE_LOCKS_SIZE = 549,        /* ROUTE_LOCKS_SIZE  */
    WAIT_WORKER1_MODE = 550,       /* WAIT_WORKER1_MODE  */
    WAIT_WORKER1_TIME = 551,       /* WAIT_WORKER1_TIME  */
    WAIT_WORKER1_USLEEP = 552,     /* WAIT_WORKER1_USLEEP  */
    CFG_DESCRIPTION = 553,         /* CFG_DESCRIPTION  */
    SERVER_ID = 554,               /* SERVER_ID  */
    KEMI = 555,                    /* KEMI  */
    REQUEST_ROUTE_CALLBACK = 556,  /* REQUEST_ROUTE_CALLBACK  */
    ONSEND_ROUTE_CALLBACK = 557,   /* ONSEND_ROUTE_CALLBACK  */
    REPLY_ROUTE_CALLBACK = 558,    /* REPLY_ROUTE_CALLBACK  */
    EVENT_ROUTE_CALLBACK = 559,    /* EVENT_ROUTE_CALLBACK  */
    RECEIVED_ROUTE_CALLBACK = 560, /* RECEIVED_ROUTE_CALLBACK  */
    RECEIVED_ROUTE_MODE = 561,     /* RECEIVED_ROUTE_MODE  */
    PRE_ROUTING_CALLBACK = 562,    /* PRE_ROUTING_CALLBACK  */
    MAX_RECURSIVE_LEVEL = 563,     /* MAX_RECURSIVE_LEVEL  */
    MAX_BRANCHES_PARAM = 564,      /* MAX_BRANCHES_PARAM  */
    LATENCY_CFG_LOG = 565,         /* LATENCY_CFG_LOG  */
    LATENCY_LOG = 566,             /* LATENCY_LOG  */
    LATENCY_LIMIT_DB = 567,        /* LATENCY_LIMIT_DB  */
    LATENCY_LIMIT_ACTION = 568,    /* LATENCY_LIMIT_ACTION  */
    LATENCY_LIMIT_CFG = 569,       /* LATENCY_LIMIT_CFG  */
    RPC_EXEC_DELTA_CFG = 570,      /* RPC_EXEC_DELTA_CFG  */
    MSG_TIME = 571,                /* MSG_TIME  */
    ONSEND_RT_REPLY = 572,         /* ONSEND_RT_REPLY  */
    URI_HOST_EXTRA_CHARS = 573,    /* URI_HOST_EXTRA_CHARS  */
    HDR_NAME_EXTRA_CHARS = 574,    /* HDR_NAME_EXTRA_CHARS  */
    FLAGS_DECL = 575,              /* FLAGS_DECL  */
    AVPFLAGS_DECL = 576,           /* AVPFLAGS_DECL  */
    ATTR_MARK = 577,               /* ATTR_MARK  */
    SELECT_MARK = 578,             /* SELECT_MARK  */
    ATTR_FROM = 579,               /* ATTR_FROM  */
    ATTR_TO = 580,                 /* ATTR_TO  */
    ATTR_FROMURI = 581,            /* ATTR_FROMURI  */
    ATTR_TOURI = 582,              /* ATTR_TOURI  */
    ATTR_FROMUSER = 583,           /* ATTR_FROMUSER  */
    ATTR_TOUSER = 584,             /* ATTR_TOUSER  */
    ATTR_FROMDOMAIN = 585,         /* ATTR_FROMDOMAIN  */
    ATTR_TODOMAIN = 586,           /* ATTR_TODOMAIN  */
    ATTR_GLOBAL = 587,             /* ATTR_GLOBAL  */
    ADDEQ = 588,                   /* ADDEQ  */
    SUBST = 589,                   /* SUBST  */
    SUBSTDEF = 590,                /* SUBSTDEF  */
    SUBSTDEFS = 591,               /* SUBSTDEFS  */
    EQUAL = 592,                   /* EQUAL  */
    LOG_OR = 593,                  /* LOG_OR  */
    LOG_AND = 594,                 /* LOG_AND  */
    BIN_OR = 595,                  /* BIN_OR  */
    BIN_AND = 596,                 /* BIN_AND  */
    BIN_XOR = 597,                 /* BIN_XOR  */
    BIN_LSHIFT = 598,              /* BIN_LSHIFT  */
    BIN_RSHIFT = 599,              /* BIN_RSHIFT  */
    EQUAL_T = 600,                 /* EQUAL_T  */
    DIFF = 601,                    /* DIFF  */
    MATCH = 602,                   /* MATCH  */
    INTEQ = 603,                   /* INTEQ  */
    INTDIFF = 604,                 /* INTDIFF  */
    STREQ = 605,                   /* STREQ  */
    STRDIFF = 606,                 /* STRDIFF  */
    GT = 607,                      /* GT  */
    LT = 608,                      /* LT  */
    GTE = 609,                     /* GTE  */
    LTE = 610,                     /* LTE  */
    PLUS = 611,                    /* PLUS  */
    MINUS = 612,                   /* MINUS  */
    STAR = 613,                    /* STAR  */
    SLASH = 614,                   /* SLASH  */
    MODULO = 615,                  /* MODULO  */
    NOT = 616,                     /* NOT  */
    UNARY = 617,                   /* UNARY  */
    BIN_NOT = 618,                 /* BIN_NOT  */
    DEFINED = 619,                 /* DEFINED  */
    INTCAST = 620,                 /* INTCAST  */
    STRCAST = 621,                 /* STRCAST  */
    DOT = 622,                     /* DOT  */
    STRLEN = 623,                  /* STRLEN  */
    STREMPTY = 624,                /* STREMPTY  */
    SELVAL = 625,                  /* SELVAL  */
    NUMBER = 626,                  /* NUMBER  */
    ID = 627,                      /* ID  */
    NUM_ID = 628,                  /* NUM_ID  */
    STRING = 629,                  /* STRING  */
    IPV6ADDR = 630,                /* IPV6ADDR  */
    PVAR = 631,                    /* PVAR  */
    AVP_OR_PVAR = 632,             /* AVP_OR_PVAR  */
    EVENT_RT_NAME = 633,           /* EVENT_RT_NAME  */
    COMMA = 634,                   /* COMMA  */
    SEMICOLON = 635,               /* SEMICOLON  */
    RPAREN = 636,                  /* RPAREN  */
    LPAREN = 637,                  /* LPAREN  */
    LBRACE = 638,                  /* LBRACE  */
    RBRACE = 639,                  /* RBRACE  */
    LBRACK = 640,                  /* LBRACK  */
    RBRACK = 641,                  /* RBRACK  */
    CR = 642,                      /* CR  */
    COLON = 643                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 199 "core/cfg.y"

	long intval;
	unsigned long uval;
	char* strval;
	struct expr* expr;
	struct action* action;
	struct case_stms* case_stms;
	struct net* ipnet;
	struct ip_addr* ipaddr;
	struct socket_id* sockid;
	struct name_lst* name_l;
	struct avp_spec* attr;
	struct _pv_spec* pvar;
	struct lvalue* lval;
	struct rvalue* rval;
	struct rval_expr* rv_expr;
	select_t* select;

#line 471 "core/cfg.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CORE_CFG_TAB_H_INCLUDED  */
