publish.o: publish.c ../../core/ut.h ../../core/comp_defs.h \
 ../../core/compiler_opt.h ../../core/config.h \
 ../../core/crypto/md5utils.h ../../core/crypto/../str.h \
 ../../core/dprint.h ../../core/cfg_core.h ../../core/cfg/cfg.h \
 ../../core/cfg/../str.h ../../core/str.h ../../core/mem/mem.h \
 ../../core/mem/pkg.h ../../core/mem/memapi.h ../../core/mem/src_loc.h \
 ../../core/mem/meminfo.h ../../core/mem/memdbg.h \
 ../../core/mem/../cfg/cfg.h ../../core/mem/../dprint.h \
 ../../core/mem/shm_mem.h ../../core/mem/shm.h \
 ../../core/mem/../lock_ops.h ../../core/mem/../futexlock.h \
 ../../core/mem/../atomic/atomic_common.h \
 ../../core/mem/../atomic/atomic_native.h \
 ../../core/mem/../atomic/atomic_x86.h ../../core/mem/../compiler_opt.h \
 ../../core/str.h ../../core/parser/parse_to.h ../../core/parser/../str.h \
 ../../core/parser/msg_parser.h ../../core/parser/../comp_defs.h \
 ../../core/parser/../lump_struct.h ../../core/parser/.././parser/hf.h \
 ../../core/parser/.././parser/../str.h \
 ../../core/parser/.././parser/../comp_defs.h \
 ../../core/parser/../flags.h ../../core/parser/../ip_addr.h \
 ../../core/parser/../str.h ../../core/parser/../compiler_opt.h \
 ../../core/parser/../ut.h ../../core/parser/../dprint.h \
 ../../core/parser/../config.h ../../core/parser/parse_def.h \
 ../../core/parser/parse_cseq.h ../../core/parser/parse_via.h \
 ../../core/parser/parse_fline.h ../../core/parser/parse_retry_after.h \
 ../../core/parser/hf.h ../../core/parser/../error.h \
 ../../core/parser/parse_addr_spec.h ../../core/parser/parse_uri.h \
 ../../core/parser/../parser/msg_parser.h \
 ../../core/parser/parse_expires.h ../../core/parser/parse_event.h \
 ../../core/parser/parse_param.h ../../core/parser/parse_content.h \
 ../../core/lock_ops.h ../../core/hashes.h ../../core/strutils.h \
 ../../core/mod_fix.h ../../core/sr_module.h \
 ../../core/parser/msg_parser.h ../../core/ver_defs.h ../../core/rpc.h \
 ../../core/locking.h ../../core/lock_ops.h ../../core/lock_alloc.h \
 ../../core/atomic_ops.h ../../core/atomic/atomic_common.h \
 ../../core/atomic/atomic_native.h ../../core/route_struct.h \
 ../../core/select.h ../../core/usr_avp.h ../../core/route.h \
 ../../core/error.h ../../core/action.h ../../core/str_hash.h \
 ../../core/hashes.h ../../core/clist.h ../../core/counters.h \
 ../../core/pt.h ../../core/globals.h ../../core/ip_addr.h \
 ../../core/poll_types.h ../../core/timer.h ../../core/timer_ticks.h \
 ../../core/socket_info.h ../../core/pvar.h ../../lib/srdb1/db.h \
 ../../lib/srdb1/db_key.h ../../lib/srdb1/../../core/ut.h \
 ../../lib/srdb1/db_op.h ../../lib/srdb1/db_val.h \
 ../../lib/srdb1/db_con.h ../../lib/srdb1/../../core/str.h \
 ../../lib/srdb1/db_res.h ../../lib/srdb1/db_cap.h \
 ../../lib/srdb1/db_row.h ../../lib/srdb1/db_pooling.h \
 ../../lib/srdb1/db_locking.h presence.h ../../core/parser/msg_parser.h \
 ../../modules/tm/tm_load.h ../../modules/tm/../../core/sr_module.h \
 ../../modules/tm/t_hooks.h ../../modules/tm/../../core/ip_addr.h \
 ../../modules/tm/uac.h ../../modules/tm/../../core/str.h \
 ../../modules/tm/dlg.h ../../modules/tm/../../core/parser/parse_rr.h \
 ../../modules/tm/../../core/parser/msg_parser.h \
 ../../modules/tm/../../core/parser/parse_nameaddr.h \
 ../../modules/tm/../../core/parser/../str.h \
 ../../modules/tm/../../core/parser/parse_param.h \
 ../../modules/tm/../../core/parser/hf.h \
 ../../modules/tm/../../core/parser/msg_parser.h \
 ../../modules/tm/h_table.h ../../modules/tm/t_stats.h \
 ../../modules/tm/../../core/rpc.h ../../modules/tm/../../core/pt.h \
 ../../modules/tm/../../core/clist.h \
 ../../modules/tm/../../core/usr_avp.h ../../modules/tm/../../core/xavp.h \
 ../../modules/tm/../../core/str.h ../../modules/tm/../../core/str_list.h \
 ../../modules/tm/../../core/timer.h ../../modules/tm/../../core/flags.h \
 ../../modules/tm/../../core/atomic_ops.h \
 ../../modules/tm/../../core/hash_func.h \
 ../../modules/tm/../../core/hashes.h ../../modules/tm/config.h \
 ../../modules/tm/../../core/cfg/cfg.h \
 ../../modules/tm/../../core/mem/shm_mem.h ../../modules/tm/lock.h \
 ../../modules/tm/../../core/dprint.h \
 ../../modules/tm/../../core/locking.h ../../modules/tm/sip_msg.h \
 ../../modules/tm/../../core/dns_cache.h \
 ../../modules/tm/../../core/config.h ../../modules/tm/../../core/timer.h \
 ../../modules/tm/../../core/ip_addr.h \
 ../../modules/tm/../../core/atomic_ops.h \
 ../../modules/tm/../../core/resolve.h \
 ../../modules/tm/../../core/counters.h \
 ../../modules/tm/../../core/dns_func.h \
 ../../modules/tm/../../core/dns_wrappers.h ../../modules/tm/t_fwd.h \
 ../../modules/tm/../../core/proxy.h ../../modules/tm/t_lookup.h \
 ../../modules/tm/t_funcs.h ../../modules/tm/../../core/globals.h \
 ../../modules/tm/../../core/udp_server.h \
 ../../modules/tm/../../core/msg_translator.h \
 ../../modules/tm/../../core/parser/msg_parser.h \
 ../../modules/tm/../../core/forward.h \
 ../../modules/tm/../../core/globals.h \
 ../../modules/tm/../../core/route.h ../../modules/tm/../../core/proxy.h \
 ../../modules/tm/../../core/udp_server.h \
 ../../modules/tm/../../core/tcp_server.h \
 ../../modules/tm/../../core/tcp_conn.h \
 ../../modules/tm/../../core/tcp_init.h \
 ../../modules/tm/../../core/tcp_options.h \
 ../../modules/tm/../../core/locking.h \
 ../../modules/tm/../../core/timer_ticks.h \
 ../../modules/tm/../../core/sctp_core.h \
 ../../modules/tm/../../core/compiler_opt.h \
 ../../modules/tm/../../core/events.h \
 ../../modules/tm/../../core/mem/mem.h \
 ../../modules/tm/../../core/parser/parse_uri.h ../../modules/tm/timer.h \
 ../../modules/tm/../../core/compiler_opt.h ../../modules/tm/ut.h \
 ../../modules/tm/../../core/ut.h ../../modules/tm/../../core/error.h \
 ../../modules/tm/../../core/resolve.h \
 ../../modules/tm/../../core/cfg_core.h ../../modules/tm/t_reply.h \
 ../../modules/tm/../../core/tags.h ../../modules/tm/../../core/crc.h \
 ../../modules/tm/../../core/socket_info.h ../../modules/tm/callid.h \
 ../../modules/tm/t_cancel.h ../../modules/tm/t_suspend.h \
 ../../modules/tm/t_append_branches.h ../../modules/tm/t_serial.h \
 ../../modules/tm/t_msgbuilder.h ../../modules/sl/sl.h \
 ../../modules/sl/../../core/sr_module.h \
 ../../modules/sl/../../core/parser/msg_parser.h \
 ../../core/parser/parse_from.h ../../core/parser/parse_to.h \
 ../../core/utils/sruid.h ../../core/utils/../../core/str.h event_list.h \
 ../../core/parser/parse_param.h subscribe.h hash.h notify.h \
 ../../modules/tm/dlg.h presentity.h utils_func.h ../../core/mem/mem.h \
 ../../core/dprint.h publish.h /usr/include/libxml2/libxml/parser.h \
 /usr/include/libxml2/libxml/xmlversion.h \
 /usr/include/libxml2/libxml/xmlexports.h \
 /usr/include/libxml2/libxml/tree.h \
 /usr/include/libxml2/libxml/xmlstring.h \
 /usr/include/libxml2/libxml/xmlregexp.h \
 /usr/include/libxml2/libxml/dict.h /usr/include/libxml2/libxml/hash.h \
 /usr/include/libxml2/libxml/valid.h \
 /usr/include/libxml2/libxml/xmlerror.h \
 /usr/include/libxml2/libxml/list.h \
 /usr/include/libxml2/libxml/xmlautomata.h \
 /usr/include/libxml2/libxml/entities.h \
 /usr/include/libxml2/libxml/encoding.h \
 /usr/include/libxml2/libxml/xmlIO.h \
 /usr/include/libxml2/libxml/globals.h /usr/include/libxml2/libxml/SAX2.h \
 /usr/include/libxml2/libxml/xlink.h \
 /usr/include/libxml2/libxml/xmlmemory.h \
 /usr/include/libxml2/libxml/threads.h ../../core/mem/shm_mem.h \
 ../alias_db/alias_db.h ../alias_db/../../lib/srdb1/db.h \
 ../alias_db/../../core/parser/msg_parser.h
../../core/ut.h:
../../core/comp_defs.h:
../../core/compiler_opt.h:
../../core/config.h:
../../core/crypto/md5utils.h:
../../core/crypto/../str.h:
../../core/dprint.h:
../../core/cfg_core.h:
../../core/cfg/cfg.h:
../../core/cfg/../str.h:
../../core/str.h:
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
../../core/str.h:
../../core/parser/parse_to.h:
../../core/parser/../str.h:
../../core/parser/msg_parser.h:
../../core/parser/../comp_defs.h:
../../core/parser/../lump_struct.h:
../../core/parser/.././parser/hf.h:
../../core/parser/.././parser/../str.h:
../../core/parser/.././parser/../comp_defs.h:
../../core/parser/../flags.h:
../../core/parser/../ip_addr.h:
../../core/parser/../str.h:
../../core/parser/../compiler_opt.h:
../../core/parser/../ut.h:
../../core/parser/../dprint.h:
../../core/parser/../config.h:
../../core/parser/parse_def.h:
../../core/parser/parse_cseq.h:
../../core/parser/parse_via.h:
../../core/parser/parse_fline.h:
../../core/parser/parse_retry_after.h:
../../core/parser/hf.h:
../../core/parser/../error.h:
../../core/parser/parse_addr_spec.h:
../../core/parser/parse_uri.h:
../../core/parser/../parser/msg_parser.h:
../../core/parser/parse_expires.h:
../../core/parser/parse_event.h:
../../core/parser/parse_param.h:
../../core/parser/parse_content.h:
../../core/lock_ops.h:
../../core/hashes.h:
../../core/strutils.h:
../../core/mod_fix.h:
../../core/sr_module.h:
../../core/parser/msg_parser.h:
../../core/ver_defs.h:
../../core/rpc.h:
../../core/locking.h:
../../core/lock_ops.h:
../../core/lock_alloc.h:
../../core/atomic_ops.h:
../../core/atomic/atomic_common.h:
../../core/atomic/atomic_native.h:
../../core/route_struct.h:
../../core/select.h:
../../core/usr_avp.h:
../../core/route.h:
../../core/error.h:
../../core/action.h:
../../core/str_hash.h:
../../core/hashes.h:
../../core/clist.h:
../../core/counters.h:
../../core/pt.h:
../../core/globals.h:
../../core/ip_addr.h:
../../core/poll_types.h:
../../core/timer.h:
../../core/timer_ticks.h:
../../core/socket_info.h:
../../core/pvar.h:
../../lib/srdb1/db.h:
../../lib/srdb1/db_key.h:
../../lib/srdb1/../../core/ut.h:
../../lib/srdb1/db_op.h:
../../lib/srdb1/db_val.h:
../../lib/srdb1/db_con.h:
../../lib/srdb1/../../core/str.h:
../../lib/srdb1/db_res.h:
../../lib/srdb1/db_cap.h:
../../lib/srdb1/db_row.h:
../../lib/srdb1/db_pooling.h:
../../lib/srdb1/db_locking.h:
presence.h:
../../core/parser/msg_parser.h:
../../modules/tm/tm_load.h:
../../modules/tm/../../core/sr_module.h:
../../modules/tm/t_hooks.h:
../../modules/tm/../../core/ip_addr.h:
../../modules/tm/uac.h:
../../modules/tm/../../core/str.h:
../../modules/tm/dlg.h:
../../modules/tm/../../core/parser/parse_rr.h:
../../modules/tm/../../core/parser/msg_parser.h:
../../modules/tm/../../core/parser/parse_nameaddr.h:
../../modules/tm/../../core/parser/../str.h:
../../modules/tm/../../core/parser/parse_param.h:
../../modules/tm/../../core/parser/hf.h:
../../modules/tm/../../core/parser/msg_parser.h:
../../modules/tm/h_table.h:
../../modules/tm/t_stats.h:
../../modules/tm/../../core/rpc.h:
../../modules/tm/../../core/pt.h:
../../modules/tm/../../core/clist.h:
../../modules/tm/../../core/usr_avp.h:
../../modules/tm/../../core/xavp.h:
../../modules/tm/../../core/str.h:
../../modules/tm/../../core/str_list.h:
../../modules/tm/../../core/timer.h:
../../modules/tm/../../core/flags.h:
../../modules/tm/../../core/atomic_ops.h:
../../modules/tm/../../core/hash_func.h:
../../modules/tm/../../core/hashes.h:
../../modules/tm/config.h:
../../modules/tm/../../core/cfg/cfg.h:
../../modules/tm/../../core/mem/shm_mem.h:
../../modules/tm/lock.h:
../../modules/tm/../../core/dprint.h:
../../modules/tm/../../core/locking.h:
../../modules/tm/sip_msg.h:
../../modules/tm/../../core/dns_cache.h:
../../modules/tm/../../core/config.h:
../../modules/tm/../../core/timer.h:
../../modules/tm/../../core/ip_addr.h:
../../modules/tm/../../core/atomic_ops.h:
../../modules/tm/../../core/resolve.h:
../../modules/tm/../../core/counters.h:
../../modules/tm/../../core/dns_func.h:
../../modules/tm/../../core/dns_wrappers.h:
../../modules/tm/t_fwd.h:
../../modules/tm/../../core/proxy.h:
../../modules/tm/t_lookup.h:
../../modules/tm/t_funcs.h:
../../modules/tm/../../core/globals.h:
../../modules/tm/../../core/udp_server.h:
../../modules/tm/../../core/msg_translator.h:
../../modules/tm/../../core/parser/msg_parser.h:
../../modules/tm/../../core/forward.h:
../../modules/tm/../../core/globals.h:
../../modules/tm/../../core/route.h:
../../modules/tm/../../core/proxy.h:
../../modules/tm/../../core/udp_server.h:
../../modules/tm/../../core/tcp_server.h:
../../modules/tm/../../core/tcp_conn.h:
../../modules/tm/../../core/tcp_init.h:
../../modules/tm/../../core/tcp_options.h:
../../modules/tm/../../core/locking.h:
../../modules/tm/../../core/timer_ticks.h:
../../modules/tm/../../core/sctp_core.h:
../../modules/tm/../../core/compiler_opt.h:
../../modules/tm/../../core/events.h:
../../modules/tm/../../core/mem/mem.h:
../../modules/tm/../../core/parser/parse_uri.h:
../../modules/tm/timer.h:
../../modules/tm/../../core/compiler_opt.h:
../../modules/tm/ut.h:
../../modules/tm/../../core/ut.h:
../../modules/tm/../../core/error.h:
../../modules/tm/../../core/resolve.h:
../../modules/tm/../../core/cfg_core.h:
../../modules/tm/t_reply.h:
../../modules/tm/../../core/tags.h:
../../modules/tm/../../core/crc.h:
../../modules/tm/../../core/socket_info.h:
../../modules/tm/callid.h:
../../modules/tm/t_cancel.h:
../../modules/tm/t_suspend.h:
../../modules/tm/t_append_branches.h:
../../modules/tm/t_serial.h:
../../modules/tm/t_msgbuilder.h:
../../modules/sl/sl.h:
../../modules/sl/../../core/sr_module.h:
../../modules/sl/../../core/parser/msg_parser.h:
../../core/parser/parse_from.h:
../../core/parser/parse_to.h:
../../core/utils/sruid.h:
../../core/utils/../../core/str.h:
event_list.h:
../../core/parser/parse_param.h:
subscribe.h:
hash.h:
notify.h:
../../modules/tm/dlg.h:
presentity.h:
utils_func.h:
../../core/mem/mem.h:
../../core/dprint.h:
publish.h:
/usr/include/libxml2/libxml/parser.h:
/usr/include/libxml2/libxml/xmlversion.h:
/usr/include/libxml2/libxml/xmlexports.h:
/usr/include/libxml2/libxml/tree.h:
/usr/include/libxml2/libxml/xmlstring.h:
/usr/include/libxml2/libxml/xmlregexp.h:
/usr/include/libxml2/libxml/dict.h:
/usr/include/libxml2/libxml/hash.h:
/usr/include/libxml2/libxml/valid.h:
/usr/include/libxml2/libxml/xmlerror.h:
/usr/include/libxml2/libxml/list.h:
/usr/include/libxml2/libxml/xmlautomata.h:
/usr/include/libxml2/libxml/entities.h:
/usr/include/libxml2/libxml/encoding.h:
/usr/include/libxml2/libxml/xmlIO.h:
/usr/include/libxml2/libxml/globals.h:
/usr/include/libxml2/libxml/SAX2.h:
/usr/include/libxml2/libxml/xlink.h:
/usr/include/libxml2/libxml/xmlmemory.h:
/usr/include/libxml2/libxml/threads.h:
../../core/mem/shm_mem.h:
../alias_db/alias_db.h:
../alias_db/../../lib/srdb1/db.h:
../alias_db/../../core/parser/msg_parser.h:
