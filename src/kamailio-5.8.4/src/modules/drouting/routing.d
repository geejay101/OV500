routing.o: routing.c ../../core/str.h ../../core/resolve.h \
 ../../core/counters.h ../../core/pt.h ../../core/globals.h \
 ../../core/ip_addr.h ../../core/str.h ../../core/compiler_opt.h \
 ../../core/ut.h ../../core/comp_defs.h ../../core/config.h \
 ../../core/crypto/md5utils.h ../../core/crypto/../str.h \
 ../../core/dprint.h ../../core/cfg_core.h ../../core/cfg/cfg.h \
 ../../core/cfg/../str.h ../../core/mem/mem.h ../../core/mem/pkg.h \
 ../../core/mem/memapi.h ../../core/mem/src_loc.h \
 ../../core/mem/meminfo.h ../../core/mem/memdbg.h \
 ../../core/mem/../cfg/cfg.h ../../core/mem/../dprint.h \
 ../../core/mem/shm_mem.h ../../core/mem/shm.h \
 ../../core/mem/../lock_ops.h ../../core/mem/../futexlock.h \
 ../../core/mem/../atomic/atomic_common.h \
 ../../core/mem/../atomic/atomic_native.h \
 ../../core/mem/../atomic/atomic_x86.h ../../core/mem/../compiler_opt.h \
 ../../core/poll_types.h ../../core/timer.h ../../core/clist.h \
 ../../core/timer_ticks.h ../../core/socket_info.h ../../core/locking.h \
 ../../core/lock_ops.h ../../core/lock_alloc.h ../../core/atomic_ops.h \
 ../../core/atomic/atomic_common.h ../../core/atomic/atomic_native.h \
 ../../core/dns_func.h ../../core/dns_wrappers.h ../../core/mem/shm_mem.h \
 ../../core/parser/parse_uri.h ../../core/parser/../str.h \
 ../../core/parser/../parser/msg_parser.h \
 ../../core/parser/../parser/../comp_defs.h \
 ../../core/parser/../parser/../str.h \
 ../../core/parser/../parser/../lump_struct.h \
 ../../core/parser/../parser/.././parser/hf.h \
 ../../core/parser/../parser/.././parser/../str.h \
 ../../core/parser/../parser/.././parser/../comp_defs.h \
 ../../core/parser/../parser/../flags.h \
 ../../core/parser/../parser/../ip_addr.h \
 ../../core/parser/../parser/../config.h \
 ../../core/parser/../parser/parse_def.h \
 ../../core/parser/../parser/parse_cseq.h \
 ../../core/parser/../parser/parse_via.h \
 ../../core/parser/../parser/parse_fline.h \
 ../../core/parser/../parser/parse_retry_after.h \
 ../../core/parser/../parser/hf.h ../../core/parser/../parser/../error.h \
 ../../core/parser/../parser/../str.h routing.h ../../core/usr_avp.h \
 prefix_tree.h ../../core/ip_addr.h ../keepalive/api.h \
 ../keepalive/../../core/sr_module.h \
 ../keepalive/../../core/parser/msg_parser.h \
 ../keepalive/../../core/ver_defs.h ../keepalive/../../core/rpc.h \
 ../keepalive/../../core/locking.h ../keepalive/../../core/route_struct.h \
 ../keepalive/../../core/select.h ../keepalive/../../core/str.h \
 ../keepalive/../../core/usr_avp.h ../keepalive/../../core/route.h \
 ../keepalive/../../core/config.h ../keepalive/../../core/error.h \
 ../keepalive/../../core/action.h ../keepalive/../../core/str_hash.h \
 ../keepalive/../../core/hashes.h ../keepalive/../../core/mem/mem.h \
 ../keepalive/../../core/clist.h ../keepalive/../../core/counters.h \
 ../keepalive/../../core/pvar.h ../keepalive/keepalive.h \
 ../keepalive/../../core/locking.h ../keepalive/../../core/str.h \
 ../keepalive/../../core/utils/sruid.h \
 ../keepalive/../../core/utils/../../core/str.h \
 ../keepalive/../tm/tm_load.h ../keepalive/../tm/../../core/sr_module.h \
 ../keepalive/../tm/t_hooks.h ../keepalive/../tm/../../core/ip_addr.h \
 ../keepalive/../tm/uac.h ../keepalive/../tm/../../core/str.h \
 ../keepalive/../tm/dlg.h ../keepalive/../tm/../../core/parser/parse_rr.h \
 ../keepalive/../tm/../../core/parser/msg_parser.h \
 ../keepalive/../tm/../../core/parser/parse_nameaddr.h \
 ../keepalive/../tm/../../core/parser/../str.h \
 ../keepalive/../tm/../../core/parser/parse_param.h \
 ../keepalive/../tm/../../core/parser/hf.h \
 ../keepalive/../tm/../../core/parser/msg_parser.h \
 ../keepalive/../tm/h_table.h ../keepalive/../tm/t_stats.h \
 ../keepalive/../tm/../../core/rpc.h ../keepalive/../tm/../../core/pt.h \
 ../keepalive/../tm/../../core/clist.h \
 ../keepalive/../tm/../../core/usr_avp.h \
 ../keepalive/../tm/../../core/xavp.h ../keepalive/../tm/../../core/str.h \
 ../keepalive/../tm/../../core/str_list.h \
 ../keepalive/../tm/../../core/timer.h \
 ../keepalive/../tm/../../core/flags.h \
 ../keepalive/../tm/../../core/atomic_ops.h \
 ../keepalive/../tm/../../core/hash_func.h \
 ../keepalive/../tm/../../core/hashes.h ../keepalive/../tm/config.h \
 ../keepalive/../tm/../../core/cfg/cfg.h \
 ../keepalive/../tm/../../core/mem/shm_mem.h ../keepalive/../tm/lock.h \
 ../keepalive/../tm/../../core/dprint.h \
 ../keepalive/../tm/../../core/locking.h ../keepalive/../tm/sip_msg.h \
 ../keepalive/../tm/../../core/dns_cache.h \
 ../keepalive/../tm/../../core/config.h \
 ../keepalive/../tm/../../core/timer.h \
 ../keepalive/../tm/../../core/ip_addr.h \
 ../keepalive/../tm/../../core/atomic_ops.h \
 ../keepalive/../tm/../../core/resolve.h ../keepalive/../tm/t_fwd.h \
 ../keepalive/../tm/../../core/proxy.h ../keepalive/../tm/t_lookup.h \
 ../keepalive/../tm/t_funcs.h ../keepalive/../tm/../../core/globals.h \
 ../keepalive/../tm/../../core/udp_server.h \
 ../keepalive/../tm/../../core/msg_translator.h \
 ../keepalive/../tm/../../core/parser/msg_parser.h \
 ../keepalive/../tm/../../core/forward.h \
 ../keepalive/../tm/../../core/globals.h \
 ../keepalive/../tm/../../core/route.h \
 ../keepalive/../tm/../../core/proxy.h \
 ../keepalive/../tm/../../core/udp_server.h \
 ../keepalive/../tm/../../core/tcp_server.h \
 ../keepalive/../tm/../../core/tcp_conn.h \
 ../keepalive/../tm/../../core/tcp_init.h \
 ../keepalive/../tm/../../core/tcp_options.h \
 ../keepalive/../tm/../../core/locking.h \
 ../keepalive/../tm/../../core/timer_ticks.h \
 ../keepalive/../tm/../../core/sctp_core.h \
 ../keepalive/../tm/../../core/compiler_opt.h \
 ../keepalive/../tm/../../core/events.h \
 ../keepalive/../tm/../../core/mem/mem.h \
 ../keepalive/../tm/../../core/parser/parse_uri.h \
 ../keepalive/../tm/timer.h ../keepalive/../tm/../../core/compiler_opt.h \
 ../keepalive/../tm/ut.h ../keepalive/../tm/../../core/ut.h \
 ../keepalive/../tm/../../core/error.h \
 ../keepalive/../tm/../../core/resolve.h \
 ../keepalive/../tm/../../core/cfg_core.h ../keepalive/../tm/t_reply.h \
 ../keepalive/../tm/../../core/tags.h ../keepalive/../tm/../../core/crc.h \
 ../keepalive/../tm/../../core/socket_info.h ../keepalive/../tm/callid.h \
 ../keepalive/../tm/t_cancel.h ../keepalive/../tm/t_suspend.h \
 ../keepalive/../tm/t_append_branches.h ../keepalive/../tm/t_serial.h \
 ../keepalive/../tm/t_msgbuilder.h dr_time.h parse.h
../../core/str.h:
../../core/resolve.h:
../../core/counters.h:
../../core/pt.h:
../../core/globals.h:
../../core/ip_addr.h:
../../core/str.h:
../../core/compiler_opt.h:
../../core/ut.h:
../../core/comp_defs.h:
../../core/config.h:
../../core/crypto/md5utils.h:
../../core/crypto/../str.h:
../../core/dprint.h:
../../core/cfg_core.h:
../../core/cfg/cfg.h:
../../core/cfg/../str.h:
../../core/mem/mem.h:
../../core/mem/pkg.h:
../../core/mem/memapi.h:
../../core/mem/src_loc.h:
../../core/mem/meminfo.h:
../../core/mem/memdbg.h:
../../core/mem/../cfg/cfg.h:
../../core/mem/../dprint.h:
../../core/mem/shm_mem.h:
../../core/mem/shm.h:
../../core/mem/../lock_ops.h:
../../core/mem/../futexlock.h:
../../core/mem/../atomic/atomic_common.h:
../../core/mem/../atomic/atomic_native.h:
../../core/mem/../atomic/atomic_x86.h:
../../core/mem/../compiler_opt.h:
../../core/poll_types.h:
../../core/timer.h:
../../core/clist.h:
../../core/timer_ticks.h:
../../core/socket_info.h:
../../core/locking.h:
../../core/lock_ops.h:
../../core/lock_alloc.h:
../../core/atomic_ops.h:
../../core/atomic/atomic_common.h:
../../core/atomic/atomic_native.h:
../../core/dns_func.h:
../../core/dns_wrappers.h:
../../core/mem/shm_mem.h:
../../core/parser/parse_uri.h:
../../core/parser/../str.h:
../../core/parser/../parser/msg_parser.h:
../../core/parser/../parser/../comp_defs.h:
../../core/parser/../parser/../str.h:
../../core/parser/../parser/../lump_struct.h:
../../core/parser/../parser/.././parser/hf.h:
../../core/parser/../parser/.././parser/../str.h:
../../core/parser/../parser/.././parser/../comp_defs.h:
../../core/parser/../parser/../flags.h:
../../core/parser/../parser/../ip_addr.h:
../../core/parser/../parser/../config.h:
../../core/parser/../parser/parse_def.h:
../../core/parser/../parser/parse_cseq.h:
../../core/parser/../parser/parse_via.h:
../../core/parser/../parser/parse_fline.h:
../../core/parser/../parser/parse_retry_after.h:
../../core/parser/../parser/hf.h:
../../core/parser/../parser/../error.h:
../../core/parser/../parser/../str.h:
routing.h:
../../core/usr_avp.h:
prefix_tree.h:
../../core/ip_addr.h:
../keepalive/api.h:
../keepalive/../../core/sr_module.h:
../keepalive/../../core/parser/msg_parser.h:
../keepalive/../../core/ver_defs.h:
../keepalive/../../core/rpc.h:
../keepalive/../../core/locking.h:
../keepalive/../../core/route_struct.h:
../keepalive/../../core/select.h:
../keepalive/../../core/str.h:
../keepalive/../../core/usr_avp.h:
../keepalive/../../core/route.h:
../keepalive/../../core/config.h:
../keepalive/../../core/error.h:
../keepalive/../../core/action.h:
../keepalive/../../core/str_hash.h:
../keepalive/../../core/hashes.h:
../keepalive/../../core/mem/mem.h:
../keepalive/../../core/clist.h:
../keepalive/../../core/counters.h:
../keepalive/../../core/pvar.h:
../keepalive/keepalive.h:
../keepalive/../../core/locking.h:
../keepalive/../../core/str.h:
../keepalive/../../core/utils/sruid.h:
../keepalive/../../core/utils/../../core/str.h:
../keepalive/../tm/tm_load.h:
../keepalive/../tm/../../core/sr_module.h:
../keepalive/../tm/t_hooks.h:
../keepalive/../tm/../../core/ip_addr.h:
../keepalive/../tm/uac.h:
../keepalive/../tm/../../core/str.h:
../keepalive/../tm/dlg.h:
../keepalive/../tm/../../core/parser/parse_rr.h:
../keepalive/../tm/../../core/parser/msg_parser.h:
../keepalive/../tm/../../core/parser/parse_nameaddr.h:
../keepalive/../tm/../../core/parser/../str.h:
../keepalive/../tm/../../core/parser/parse_param.h:
../keepalive/../tm/../../core/parser/hf.h:
../keepalive/../tm/../../core/parser/msg_parser.h:
../keepalive/../tm/h_table.h:
../keepalive/../tm/t_stats.h:
../keepalive/../tm/../../core/rpc.h:
../keepalive/../tm/../../core/pt.h:
../keepalive/../tm/../../core/clist.h:
../keepalive/../tm/../../core/usr_avp.h:
../keepalive/../tm/../../core/xavp.h:
../keepalive/../tm/../../core/str.h:
../keepalive/../tm/../../core/str_list.h:
../keepalive/../tm/../../core/timer.h:
../keepalive/../tm/../../core/flags.h:
../keepalive/../tm/../../core/atomic_ops.h:
../keepalive/../tm/../../core/hash_func.h:
../keepalive/../tm/../../core/hashes.h:
../keepalive/../tm/config.h:
../keepalive/../tm/../../core/cfg/cfg.h:
../keepalive/../tm/../../core/mem/shm_mem.h:
../keepalive/../tm/lock.h:
../keepalive/../tm/../../core/dprint.h:
../keepalive/../tm/../../core/locking.h:
../keepalive/../tm/sip_msg.h:
../keepalive/../tm/../../core/dns_cache.h:
../keepalive/../tm/../../core/config.h:
../keepalive/../tm/../../core/timer.h:
../keepalive/../tm/../../core/ip_addr.h:
../keepalive/../tm/../../core/atomic_ops.h:
../keepalive/../tm/../../core/resolve.h:
../keepalive/../tm/t_fwd.h:
../keepalive/../tm/../../core/proxy.h:
../keepalive/../tm/t_lookup.h:
../keepalive/../tm/t_funcs.h:
../keepalive/../tm/../../core/globals.h:
../keepalive/../tm/../../core/udp_server.h:
../keepalive/../tm/../../core/msg_translator.h:
../keepalive/../tm/../../core/parser/msg_parser.h:
../keepalive/../tm/../../core/forward.h:
../keepalive/../tm/../../core/globals.h:
../keepalive/../tm/../../core/route.h:
../keepalive/../tm/../../core/proxy.h:
../keepalive/../tm/../../core/udp_server.h:
../keepalive/../tm/../../core/tcp_server.h:
../keepalive/../tm/../../core/tcp_conn.h:
../keepalive/../tm/../../core/tcp_init.h:
../keepalive/../tm/../../core/tcp_options.h:
../keepalive/../tm/../../core/locking.h:
../keepalive/../tm/../../core/timer_ticks.h:
../keepalive/../tm/../../core/sctp_core.h:
../keepalive/../tm/../../core/compiler_opt.h:
../keepalive/../tm/../../core/events.h:
../keepalive/../tm/../../core/mem/mem.h:
../keepalive/../tm/../../core/parser/parse_uri.h:
../keepalive/../tm/timer.h:
../keepalive/../tm/../../core/compiler_opt.h:
../keepalive/../tm/ut.h:
../keepalive/../tm/../../core/ut.h:
../keepalive/../tm/../../core/error.h:
../keepalive/../tm/../../core/resolve.h:
../keepalive/../tm/../../core/cfg_core.h:
../keepalive/../tm/t_reply.h:
../keepalive/../tm/../../core/tags.h:
../keepalive/../tm/../../core/crc.h:
../keepalive/../tm/../../core/socket_info.h:
../keepalive/../tm/callid.h:
../keepalive/../tm/t_cancel.h:
../keepalive/../tm/t_suspend.h:
../keepalive/../tm/t_append_branches.h:
../keepalive/../tm/t_serial.h:
../keepalive/../tm/t_msgbuilder.h:
dr_time.h:
parse.h:
