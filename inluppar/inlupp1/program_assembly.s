
hashtable:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 4f 00 00 	mov    0x4fd9(%rip),%rax        # 5fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 12 4f 00 00    	push   0x4f12(%rip)        # 5f38 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 14 4f 00 00    	jmp    *0x4f14(%rip)        # 5f40 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	push   $0x0
    1039:	e9 e2 ff ff ff       	jmp    1020 <_init+0x20>
    103e:	66 90                	xchg   %ax,%ax
    1040:	f3 0f 1e fa          	endbr64
    1044:	68 01 00 00 00       	push   $0x1
    1049:	e9 d2 ff ff ff       	jmp    1020 <_init+0x20>
    104e:	66 90                	xchg   %ax,%ax
    1050:	f3 0f 1e fa          	endbr64
    1054:	68 02 00 00 00       	push   $0x2
    1059:	e9 c2 ff ff ff       	jmp    1020 <_init+0x20>
    105e:	66 90                	xchg   %ax,%ax
    1060:	f3 0f 1e fa          	endbr64
    1064:	68 03 00 00 00       	push   $0x3
    1069:	e9 b2 ff ff ff       	jmp    1020 <_init+0x20>
    106e:	66 90                	xchg   %ax,%ax
    1070:	f3 0f 1e fa          	endbr64
    1074:	68 04 00 00 00       	push   $0x4
    1079:	e9 a2 ff ff ff       	jmp    1020 <_init+0x20>
    107e:	66 90                	xchg   %ax,%ax
    1080:	f3 0f 1e fa          	endbr64
    1084:	68 05 00 00 00       	push   $0x5
    1089:	e9 92 ff ff ff       	jmp    1020 <_init+0x20>
    108e:	66 90                	xchg   %ax,%ax
    1090:	f3 0f 1e fa          	endbr64
    1094:	68 06 00 00 00       	push   $0x6
    1099:	e9 82 ff ff ff       	jmp    1020 <_init+0x20>
    109e:	66 90                	xchg   %ax,%ax
    10a0:	f3 0f 1e fa          	endbr64
    10a4:	68 07 00 00 00       	push   $0x7
    10a9:	e9 72 ff ff ff       	jmp    1020 <_init+0x20>
    10ae:	66 90                	xchg   %ax,%ax
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	68 08 00 00 00       	push   $0x8
    10b9:	e9 62 ff ff ff       	jmp    1020 <_init+0x20>
    10be:	66 90                	xchg   %ax,%ax
    10c0:	f3 0f 1e fa          	endbr64
    10c4:	68 09 00 00 00       	push   $0x9
    10c9:	e9 52 ff ff ff       	jmp    1020 <_init+0x20>
    10ce:	66 90                	xchg   %ax,%ax
    10d0:	f3 0f 1e fa          	endbr64
    10d4:	68 0a 00 00 00       	push   $0xa
    10d9:	e9 42 ff ff ff       	jmp    1020 <_init+0x20>
    10de:	66 90                	xchg   %ax,%ax
    10e0:	f3 0f 1e fa          	endbr64
    10e4:	68 0b 00 00 00       	push   $0xb
    10e9:	e9 32 ff ff ff       	jmp    1020 <_init+0x20>
    10ee:	66 90                	xchg   %ax,%ax
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	68 0c 00 00 00       	push   $0xc
    10f9:	e9 22 ff ff ff       	jmp    1020 <_init+0x20>
    10fe:	66 90                	xchg   %ax,%ax
    1100:	f3 0f 1e fa          	endbr64
    1104:	68 0d 00 00 00       	push   $0xd
    1109:	e9 12 ff ff ff       	jmp    1020 <_init+0x20>
    110e:	66 90                	xchg   %ax,%ax
    1110:	f3 0f 1e fa          	endbr64
    1114:	68 0e 00 00 00       	push   $0xe
    1119:	e9 02 ff ff ff       	jmp    1020 <_init+0x20>
    111e:	66 90                	xchg   %ax,%ax
    1120:	f3 0f 1e fa          	endbr64
    1124:	68 0f 00 00 00       	push   $0xf
    1129:	e9 f2 fe ff ff       	jmp    1020 <_init+0x20>
    112e:	66 90                	xchg   %ax,%ax
    1130:	f3 0f 1e fa          	endbr64
    1134:	68 10 00 00 00       	push   $0x10
    1139:	e9 e2 fe ff ff       	jmp    1020 <_init+0x20>
    113e:	66 90                	xchg   %ax,%ax
    1140:	f3 0f 1e fa          	endbr64
    1144:	68 11 00 00 00       	push   $0x11
    1149:	e9 d2 fe ff ff       	jmp    1020 <_init+0x20>
    114e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.got:

0000000000001150 <__cxa_finalize@plt>:
    1150:	f3 0f 1e fa          	endbr64
    1154:	ff 25 9e 4e 00 00    	jmp    *0x4e9e(%rip)        # 5ff8 <__cxa_finalize@GLIBC_2.2.5>
    115a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001160 <CU_basic_set_mode@plt>:
    1160:	f3 0f 1e fa          	endbr64
    1164:	ff 25 de 4d 00 00    	jmp    *0x4dde(%rip)        # 5f48 <CU_basic_set_mode@Base>
    116a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001170 <free@plt>:
    1170:	f3 0f 1e fa          	endbr64
    1174:	ff 25 d6 4d 00 00    	jmp    *0x4dd6(%rip)        # 5f50 <free@GLIBC_2.2.5>
    117a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001180 <CU_initialize_registry@plt>:
    1180:	f3 0f 1e fa          	endbr64
    1184:	ff 25 ce 4d 00 00    	jmp    *0x4dce(%rip)        # 5f58 <CU_initialize_registry@Base>
    118a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001190 <strcpy@plt>:
    1190:	f3 0f 1e fa          	endbr64
    1194:	ff 25 c6 4d 00 00    	jmp    *0x4dc6(%rip)        # 5f60 <strcpy@GLIBC_2.2.5>
    119a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011a0 <CU_cleanup_registry@plt>:
    11a0:	f3 0f 1e fa          	endbr64
    11a4:	ff 25 be 4d 00 00    	jmp    *0x4dbe(%rip)        # 5f68 <CU_cleanup_registry@Base>
    11aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011b0 <CU_add_suite@plt>:
    11b0:	f3 0f 1e fa          	endbr64
    11b4:	ff 25 b6 4d 00 00    	jmp    *0x4db6(%rip)        # 5f70 <CU_add_suite@Base>
    11ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011c0 <CU_basic_run_tests@plt>:
    11c0:	f3 0f 1e fa          	endbr64
    11c4:	ff 25 ae 4d 00 00    	jmp    *0x4dae(%rip)        # 5f78 <CU_basic_run_tests@Base>
    11ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011d0 <strlen@plt>:
    11d0:	f3 0f 1e fa          	endbr64
    11d4:	ff 25 a6 4d 00 00    	jmp    *0x4da6(%rip)        # 5f80 <strlen@GLIBC_2.2.5>
    11da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011e0 <__stack_chk_fail@plt>:
    11e0:	f3 0f 1e fa          	endbr64
    11e4:	ff 25 9e 4d 00 00    	jmp    *0x4d9e(%rip)        # 5f88 <__stack_chk_fail@GLIBC_2.4>
    11ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011f0 <CU_get_error@plt>:
    11f0:	f3 0f 1e fa          	endbr64
    11f4:	ff 25 96 4d 00 00    	jmp    *0x4d96(%rip)        # 5f90 <CU_get_error@Base>
    11fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001200 <snprintf@plt>:
    1200:	f3 0f 1e fa          	endbr64
    1204:	ff 25 8e 4d 00 00    	jmp    *0x4d8e(%rip)        # 5f98 <snprintf@GLIBC_2.2.5>
    120a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001210 <calloc@plt>:
    1210:	f3 0f 1e fa          	endbr64
    1214:	ff 25 86 4d 00 00    	jmp    *0x4d86(%rip)        # 5fa0 <calloc@GLIBC_2.2.5>
    121a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001220 <strcmp@plt>:
    1220:	f3 0f 1e fa          	endbr64
    1224:	ff 25 7e 4d 00 00    	jmp    *0x4d7e(%rip)        # 5fa8 <strcmp@GLIBC_2.2.5>
    122a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001230 <CU_assertImplementation@plt>:
    1230:	f3 0f 1e fa          	endbr64
    1234:	ff 25 76 4d 00 00    	jmp    *0x4d76(%rip)        # 5fb0 <CU_assertImplementation@Base>
    123a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001240 <malloc@plt>:
    1240:	f3 0f 1e fa          	endbr64
    1244:	ff 25 6e 4d 00 00    	jmp    *0x4d6e(%rip)        # 5fb8 <malloc@GLIBC_2.2.5>
    124a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001250 <CU_add_test@plt>:
    1250:	f3 0f 1e fa          	endbr64
    1254:	ff 25 66 4d 00 00    	jmp    *0x4d66(%rip)        # 5fc0 <CU_add_test@Base>
    125a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001260 <strcat@plt>:
    1260:	f3 0f 1e fa          	endbr64
    1264:	ff 25 5e 4d 00 00    	jmp    *0x4d5e(%rip)        # 5fc8 <strcat@GLIBC_2.2.5>
    126a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000001270 <strdup@plt>:
    1270:	f3 0f 1e fa          	endbr64
    1274:	ff 25 56 4d 00 00    	jmp    *0x4d56(%rip)        # 5fd0 <strdup@GLIBC_2.2.5>
    127a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001280 <_start>:
    1280:	f3 0f 1e fa          	endbr64
    1284:	31 ed                	xor    %ebp,%ebp
    1286:	49 89 d1             	mov    %rdx,%r9
    1289:	5e                   	pop    %rsi
    128a:	48 89 e2             	mov    %rsp,%rdx
    128d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1291:	50                   	push   %rax
    1292:	54                   	push   %rsp
    1293:	45 31 c0             	xor    %r8d,%r8d
    1296:	31 c9                	xor    %ecx,%ecx
    1298:	48 8d 3d 84 1d 00 00 	lea    0x1d84(%rip),%rdi        # 3023 <main>
    129f:	ff 15 33 4d 00 00    	call   *0x4d33(%rip)        # 5fd8 <__libc_start_main@GLIBC_2.34>
    12a5:	f4                   	hlt
    12a6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    12ad:	00 00 00 

00000000000012b0 <deregister_tm_clones>:
    12b0:	48 8d 3d 59 4d 00 00 	lea    0x4d59(%rip),%rdi        # 6010 <__TMC_END__>
    12b7:	48 8d 05 52 4d 00 00 	lea    0x4d52(%rip),%rax        # 6010 <__TMC_END__>
    12be:	48 39 f8             	cmp    %rdi,%rax
    12c1:	74 15                	je     12d8 <deregister_tm_clones+0x28>
    12c3:	48 8b 05 16 4d 00 00 	mov    0x4d16(%rip),%rax        # 5fe0 <_ITM_deregisterTMCloneTable@Base>
    12ca:	48 85 c0             	test   %rax,%rax
    12cd:	74 09                	je     12d8 <deregister_tm_clones+0x28>
    12cf:	ff e0                	jmp    *%rax
    12d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    12d8:	c3                   	ret
    12d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012e0 <register_tm_clones>:
    12e0:	48 8d 3d 29 4d 00 00 	lea    0x4d29(%rip),%rdi        # 6010 <__TMC_END__>
    12e7:	48 8d 35 22 4d 00 00 	lea    0x4d22(%rip),%rsi        # 6010 <__TMC_END__>
    12ee:	48 29 fe             	sub    %rdi,%rsi
    12f1:	48 89 f0             	mov    %rsi,%rax
    12f4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    12f8:	48 c1 f8 03          	sar    $0x3,%rax
    12fc:	48 01 c6             	add    %rax,%rsi
    12ff:	48 d1 fe             	sar    $1,%rsi
    1302:	74 14                	je     1318 <register_tm_clones+0x38>
    1304:	48 8b 05 e5 4c 00 00 	mov    0x4ce5(%rip),%rax        # 5ff0 <_ITM_registerTMCloneTable@Base>
    130b:	48 85 c0             	test   %rax,%rax
    130e:	74 08                	je     1318 <register_tm_clones+0x38>
    1310:	ff e0                	jmp    *%rax
    1312:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1318:	c3                   	ret
    1319:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001320 <__do_global_dtors_aux>:
    1320:	f3 0f 1e fa          	endbr64
    1324:	80 3d e5 4c 00 00 00 	cmpb   $0x0,0x4ce5(%rip)        # 6010 <__TMC_END__>
    132b:	75 2b                	jne    1358 <__do_global_dtors_aux+0x38>
    132d:	55                   	push   %rbp
    132e:	48 83 3d c2 4c 00 00 	cmpq   $0x0,0x4cc2(%rip)        # 5ff8 <__cxa_finalize@GLIBC_2.2.5>
    1335:	00 
    1336:	48 89 e5             	mov    %rsp,%rbp
    1339:	74 0c                	je     1347 <__do_global_dtors_aux+0x27>
    133b:	48 8b 3d c6 4c 00 00 	mov    0x4cc6(%rip),%rdi        # 6008 <__dso_handle>
    1342:	e8 09 fe ff ff       	call   1150 <__cxa_finalize@plt>
    1347:	e8 64 ff ff ff       	call   12b0 <deregister_tm_clones>
    134c:	c6 05 bd 4c 00 00 01 	movb   $0x1,0x4cbd(%rip)        # 6010 <__TMC_END__>
    1353:	5d                   	pop    %rbp
    1354:	c3                   	ret
    1355:	0f 1f 00             	nopl   (%rax)
    1358:	c3                   	ret
    1359:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001360 <frame_dummy>:
    1360:	f3 0f 1e fa          	endbr64
    1364:	e9 77 ff ff ff       	jmp    12e0 <register_tm_clones>

0000000000001369 <ioopm_hash_table_create>:
    1369:	f3 0f 1e fa          	endbr64
    136d:	55                   	push   %rbp
    136e:	48 89 e5             	mov    %rsp,%rbp
    1371:	48 83 ec 10          	sub    $0x10,%rsp
    1375:	be 88 00 00 00       	mov    $0x88,%esi
    137a:	bf 01 00 00 00       	mov    $0x1,%edi
    137f:	e8 8c fe ff ff       	call   1210 <calloc@plt>
    1384:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1388:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    138c:	c9                   	leave
    138d:	c3                   	ret

000000000000138e <ioopm_hash_table_destroy>:
    138e:	f3 0f 1e fa          	endbr64
    1392:	55                   	push   %rbp
    1393:	48 89 e5             	mov    %rsp,%rbp
    1396:	48 83 ec 10          	sub    $0x10,%rsp
    139a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    139e:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    13a3:	74 18                	je     13bd <ioopm_hash_table_destroy+0x2f>
    13a5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13a9:	48 89 c7             	mov    %rax,%rdi
    13ac:	e8 df 03 00 00       	call   1790 <ioopm_hash_table_clear>
    13b1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13b5:	48 89 c7             	mov    %rax,%rdi
    13b8:	e8 b3 fd ff ff       	call   1170 <free@plt>
    13bd:	90                   	nop
    13be:	c9                   	leave
    13bf:	c3                   	ret

00000000000013c0 <hash_function>:
    13c0:	f3 0f 1e fa          	endbr64
    13c4:	55                   	push   %rbp
    13c5:	48 89 e5             	mov    %rsp,%rbp
    13c8:	89 7d fc             	mov    %edi,-0x4(%rbp)
    13cb:	8b 4d fc             	mov    -0x4(%rbp),%ecx
    13ce:	48 63 c1             	movslq %ecx,%rax
    13d1:	48 69 c0 79 78 78 78 	imul   $0x78787879,%rax,%rax
    13d8:	48 c1 e8 20          	shr    $0x20,%rax
    13dc:	89 c2                	mov    %eax,%edx
    13de:	c1 fa 03             	sar    $0x3,%edx
    13e1:	89 c8                	mov    %ecx,%eax
    13e3:	c1 f8 1f             	sar    $0x1f,%eax
    13e6:	29 c2                	sub    %eax,%edx
    13e8:	89 d0                	mov    %edx,%eax
    13ea:	c1 e0 04             	shl    $0x4,%eax
    13ed:	01 d0                	add    %edx,%eax
    13ef:	29 c1                	sub    %eax,%ecx
    13f1:	89 ca                	mov    %ecx,%edx
    13f3:	89 d0                	mov    %edx,%eax
    13f5:	5d                   	pop    %rbp
    13f6:	c3                   	ret

00000000000013f7 <entry_create>:
    13f7:	f3 0f 1e fa          	endbr64
    13fb:	55                   	push   %rbp
    13fc:	48 89 e5             	mov    %rsp,%rbp
    13ff:	48 83 ec 30          	sub    $0x30,%rsp
    1403:	89 7d ec             	mov    %edi,-0x14(%rbp)
    1406:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    140a:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    140e:	be 18 00 00 00       	mov    $0x18,%esi
    1413:	bf 01 00 00 00       	mov    $0x1,%edi
    1418:	e8 f3 fd ff ff       	call   1210 <calloc@plt>
    141d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1421:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1426:	75 07                	jne    142f <entry_create+0x38>
    1428:	b8 00 00 00 00       	mov    $0x0,%eax
    142d:	eb 30                	jmp    145f <entry_create+0x68>
    142f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1433:	8b 55 ec             	mov    -0x14(%rbp),%edx
    1436:	89 10                	mov    %edx,(%rax)
    1438:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    143c:	48 89 c7             	mov    %rax,%rdi
    143f:	e8 2c fe ff ff       	call   1270 <strdup@plt>
    1444:	48 89 c2             	mov    %rax,%rdx
    1447:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    144b:	48 89 50 08          	mov    %rdx,0x8(%rax)
    144f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1453:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1457:	48 89 50 10          	mov    %rdx,0x10(%rax)
    145b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    145f:	c9                   	leave
    1460:	c3                   	ret

0000000000001461 <find_previous_entry_for_key>:
    1461:	f3 0f 1e fa          	endbr64
    1465:	55                   	push   %rbp
    1466:	48 89 e5             	mov    %rsp,%rbp
    1469:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    146d:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    1470:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1474:	48 8b 00             	mov    (%rax),%rax
    1477:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    147b:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    1482:	00 
    1483:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    1488:	75 1b                	jne    14a5 <find_previous_entry_for_key+0x44>
    148a:	b8 00 00 00 00       	mov    $0x0,%eax
    148f:	eb 2a                	jmp    14bb <find_previous_entry_for_key+0x5a>
    1491:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1495:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1499:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    149d:	48 8b 40 10          	mov    0x10(%rax),%rax
    14a1:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    14a5:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    14aa:	74 0b                	je     14b7 <find_previous_entry_for_key+0x56>
    14ac:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    14b0:	8b 00                	mov    (%rax),%eax
    14b2:	39 45 e4             	cmp    %eax,-0x1c(%rbp)
    14b5:	75 da                	jne    1491 <find_previous_entry_for_key+0x30>
    14b7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    14bb:	5d                   	pop    %rbp
    14bc:	c3                   	ret

00000000000014bd <ioopm_hash_table_insert>:
    14bd:	f3 0f 1e fa          	endbr64
    14c1:	55                   	push   %rbp
    14c2:	48 89 e5             	mov    %rsp,%rbp
    14c5:	48 83 ec 40          	sub    $0x40,%rsp
    14c9:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    14cd:	89 75 d4             	mov    %esi,-0x2c(%rbp)
    14d0:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    14d4:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    14d7:	89 c7                	mov    %eax,%edi
    14d9:	e8 e2 fe ff ff       	call   13c0 <hash_function>
    14de:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    14e1:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    14e4:	48 98                	cltq
    14e6:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    14ed:	00 
    14ee:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    14f2:	48 01 c2             	add    %rax,%rdx
    14f5:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    14f8:	89 c6                	mov    %eax,%esi
    14fa:	48 89 d7             	mov    %rdx,%rdi
    14fd:	e8 5f ff ff ff       	call   1461 <find_previous_entry_for_key>
    1502:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1506:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    150b:	74 0a                	je     1517 <ioopm_hash_table_insert+0x5a>
    150d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1511:	48 8b 40 10          	mov    0x10(%rax),%rax
    1515:	eb 0e                	jmp    1525 <ioopm_hash_table_insert+0x68>
    1517:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    151b:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    151e:	48 63 d2             	movslq %edx,%rdx
    1521:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1525:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1529:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    152e:	74 34                	je     1564 <ioopm_hash_table_insert+0xa7>
    1530:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1534:	8b 00                	mov    (%rax),%eax
    1536:	39 45 d4             	cmp    %eax,-0x2c(%rbp)
    1539:	75 29                	jne    1564 <ioopm_hash_table_insert+0xa7>
    153b:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    153f:	48 8b 40 08          	mov    0x8(%rax),%rax
    1543:	48 89 c7             	mov    %rax,%rdi
    1546:	e8 25 fc ff ff       	call   1170 <free@plt>
    154b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    154f:	48 89 c7             	mov    %rax,%rdi
    1552:	e8 19 fd ff ff       	call   1270 <strdup@plt>
    1557:	48 89 c2             	mov    %rax,%rdx
    155a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    155e:	48 89 50 08          	mov    %rdx,0x8(%rax)
    1562:	eb 40                	jmp    15a4 <ioopm_hash_table_insert+0xe7>
    1564:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    1568:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    156c:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    156f:	48 89 ce             	mov    %rcx,%rsi
    1572:	89 c7                	mov    %eax,%edi
    1574:	e8 7e fe ff ff       	call   13f7 <entry_create>
    1579:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    157d:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    1582:	74 0e                	je     1592 <ioopm_hash_table_insert+0xd5>
    1584:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1588:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    158c:	48 89 50 10          	mov    %rdx,0x10(%rax)
    1590:	eb 12                	jmp    15a4 <ioopm_hash_table_insert+0xe7>
    1592:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1596:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    1599:	48 63 d2             	movslq %edx,%rdx
    159c:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    15a0:	48 89 0c d0          	mov    %rcx,(%rax,%rdx,8)
    15a4:	90                   	nop
    15a5:	c9                   	leave
    15a6:	c3                   	ret

00000000000015a7 <recursive_lookup>:
    15a7:	f3 0f 1e fa          	endbr64
    15ab:	55                   	push   %rbp
    15ac:	48 89 e5             	mov    %rsp,%rbp
    15af:	48 83 ec 10          	sub    $0x10,%rsp
    15b3:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    15b7:	89 75 f4             	mov    %esi,-0xc(%rbp)
    15ba:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    15bf:	75 07                	jne    15c8 <recursive_lookup+0x21>
    15c1:	b8 00 00 00 00       	mov    $0x0,%eax
    15c6:	eb 2a                	jmp    15f2 <recursive_lookup+0x4b>
    15c8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15cc:	8b 00                	mov    (%rax),%eax
    15ce:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    15d1:	75 0a                	jne    15dd <recursive_lookup+0x36>
    15d3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15d7:	48 8b 40 08          	mov    0x8(%rax),%rax
    15db:	eb 15                	jmp    15f2 <recursive_lookup+0x4b>
    15dd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15e1:	48 8b 40 10          	mov    0x10(%rax),%rax
    15e5:	8b 55 f4             	mov    -0xc(%rbp),%edx
    15e8:	89 d6                	mov    %edx,%esi
    15ea:	48 89 c7             	mov    %rax,%rdi
    15ed:	e8 b5 ff ff ff       	call   15a7 <recursive_lookup>
    15f2:	c9                   	leave
    15f3:	c3                   	ret

00000000000015f4 <ioopm_hash_table_lookup>:
    15f4:	f3 0f 1e fa          	endbr64
    15f8:	55                   	push   %rbp
    15f9:	48 89 e5             	mov    %rsp,%rbp
    15fc:	48 83 ec 20          	sub    $0x20,%rsp
    1600:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1604:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    1607:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    160a:	89 c7                	mov    %eax,%edi
    160c:	e8 af fd ff ff       	call   13c0 <hash_function>
    1611:	89 45 fc             	mov    %eax,-0x4(%rbp)
    1614:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1618:	8b 55 fc             	mov    -0x4(%rbp),%edx
    161b:	48 63 d2             	movslq %edx,%rdx
    161e:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1622:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    1625:	89 d6                	mov    %edx,%esi
    1627:	48 89 c7             	mov    %rax,%rdi
    162a:	e8 78 ff ff ff       	call   15a7 <recursive_lookup>
    162f:	c9                   	leave
    1630:	c3                   	ret

0000000000001631 <ioopm_hash_table_remove>:
    1631:	f3 0f 1e fa          	endbr64
    1635:	55                   	push   %rbp
    1636:	48 89 e5             	mov    %rsp,%rbp
    1639:	48 83 ec 30          	sub    $0x30,%rsp
    163d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1641:	89 75 d4             	mov    %esi,-0x2c(%rbp)
    1644:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    1647:	89 c7                	mov    %eax,%edi
    1649:	e8 72 fd ff ff       	call   13c0 <hash_function>
    164e:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    1651:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1654:	48 98                	cltq
    1656:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    165d:	00 
    165e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1662:	48 01 c2             	add    %rax,%rdx
    1665:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    1668:	89 c6                	mov    %eax,%esi
    166a:	48 89 d7             	mov    %rdx,%rdi
    166d:	e8 ef fd ff ff       	call   1461 <find_previous_entry_for_key>
    1672:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1676:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    167b:	74 0a                	je     1687 <ioopm_hash_table_remove+0x56>
    167d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1681:	48 8b 40 10          	mov    0x10(%rax),%rax
    1685:	eb 0e                	jmp    1695 <ioopm_hash_table_remove+0x64>
    1687:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    168b:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    168e:	48 63 d2             	movslq %edx,%rdx
    1691:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1695:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1699:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    169e:	74 0b                	je     16ab <ioopm_hash_table_remove+0x7a>
    16a0:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    16a4:	8b 00                	mov    (%rax),%eax
    16a6:	39 45 d4             	cmp    %eax,-0x2c(%rbp)
    16a9:	74 07                	je     16b2 <ioopm_hash_table_remove+0x81>
    16ab:	b8 00 00 00 00       	mov    $0x0,%eax
    16b0:	eb 63                	jmp    1715 <ioopm_hash_table_remove+0xe4>
    16b2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    16b6:	48 8b 40 08          	mov    0x8(%rax),%rax
    16ba:	48 89 c7             	mov    %rax,%rdi
    16bd:	e8 ae fb ff ff       	call   1270 <strdup@plt>
    16c2:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    16c6:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    16cb:	74 12                	je     16df <ioopm_hash_table_remove+0xae>
    16cd:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    16d1:	48 8b 50 10          	mov    0x10(%rax),%rdx
    16d5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    16d9:	48 89 50 10          	mov    %rdx,0x10(%rax)
    16dd:	eb 16                	jmp    16f5 <ioopm_hash_table_remove+0xc4>
    16df:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    16e3:	48 8b 48 10          	mov    0x10(%rax),%rcx
    16e7:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    16eb:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    16ee:	48 63 d2             	movslq %edx,%rdx
    16f1:	48 89 0c d0          	mov    %rcx,(%rax,%rdx,8)
    16f5:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    16f9:	48 8b 40 08          	mov    0x8(%rax),%rax
    16fd:	48 89 c7             	mov    %rax,%rdi
    1700:	e8 6b fa ff ff       	call   1170 <free@plt>
    1705:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1709:	48 89 c7             	mov    %rax,%rdi
    170c:	e8 5f fa ff ff       	call   1170 <free@plt>
    1711:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1715:	c9                   	leave
    1716:	c3                   	ret

0000000000001717 <ioopm_hash_table_size>:
    1717:	f3 0f 1e fa          	endbr64
    171b:	55                   	push   %rbp
    171c:	48 89 e5             	mov    %rsp,%rbp
    171f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1723:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%rbp)
    172a:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1731:	eb 2f                	jmp    1762 <ioopm_hash_table_size+0x4b>
    1733:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1737:	8b 55 f4             	mov    -0xc(%rbp),%edx
    173a:	48 63 d2             	movslq %edx,%rdx
    173d:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1741:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1745:	eb 10                	jmp    1757 <ioopm_hash_table_size+0x40>
    1747:	83 45 f0 01          	addl   $0x1,-0x10(%rbp)
    174b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    174f:	48 8b 40 10          	mov    0x10(%rax),%rax
    1753:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1757:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    175c:	75 e9                	jne    1747 <ioopm_hash_table_size+0x30>
    175e:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    1762:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    1766:	7e cb                	jle    1733 <ioopm_hash_table_size+0x1c>
    1768:	8b 45 f0             	mov    -0x10(%rbp),%eax
    176b:	5d                   	pop    %rbp
    176c:	c3                   	ret

000000000000176d <ioopm_hash_table_is_empty>:
    176d:	f3 0f 1e fa          	endbr64
    1771:	55                   	push   %rbp
    1772:	48 89 e5             	mov    %rsp,%rbp
    1775:	48 83 ec 08          	sub    $0x8,%rsp
    1779:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    177d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1781:	48 89 c7             	mov    %rax,%rdi
    1784:	e8 8e ff ff ff       	call   1717 <ioopm_hash_table_size>
    1789:	85 c0                	test   %eax,%eax
    178b:	0f 94 c0             	sete   %al
    178e:	c9                   	leave
    178f:	c3                   	ret

0000000000001790 <ioopm_hash_table_clear>:
    1790:	f3 0f 1e fa          	endbr64
    1794:	55                   	push   %rbp
    1795:	48 89 e5             	mov    %rsp,%rbp
    1798:	48 83 ec 30          	sub    $0x30,%rsp
    179c:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    17a0:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    17a7:	eb 61                	jmp    180a <ioopm_hash_table_clear+0x7a>
    17a9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    17ad:	8b 55 ec             	mov    -0x14(%rbp),%edx
    17b0:	48 63 d2             	movslq %edx,%rdx
    17b3:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    17b7:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    17bb:	eb 30                	jmp    17ed <ioopm_hash_table_clear+0x5d>
    17bd:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    17c1:	48 8b 40 10          	mov    0x10(%rax),%rax
    17c5:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    17c9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    17cd:	48 8b 40 08          	mov    0x8(%rax),%rax
    17d1:	48 89 c7             	mov    %rax,%rdi
    17d4:	e8 97 f9 ff ff       	call   1170 <free@plt>
    17d9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    17dd:	48 89 c7             	mov    %rax,%rdi
    17e0:	e8 8b f9 ff ff       	call   1170 <free@plt>
    17e5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    17e9:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    17ed:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    17f2:	75 c9                	jne    17bd <ioopm_hash_table_clear+0x2d>
    17f4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    17f8:	8b 55 ec             	mov    -0x14(%rbp),%edx
    17fb:	48 63 d2             	movslq %edx,%rdx
    17fe:	48 c7 04 d0 00 00 00 	movq   $0x0,(%rax,%rdx,8)
    1805:	00 
    1806:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
    180a:	83 7d ec 10          	cmpl   $0x10,-0x14(%rbp)
    180e:	7e 99                	jle    17a9 <ioopm_hash_table_clear+0x19>
    1810:	90                   	nop
    1811:	90                   	nop
    1812:	c9                   	leave
    1813:	c3                   	ret

0000000000001814 <ioopm_hash_table_keys>:
    1814:	f3 0f 1e fa          	endbr64
    1818:	55                   	push   %rbp
    1819:	48 89 e5             	mov    %rsp,%rbp
    181c:	48 83 ec 30          	sub    $0x30,%rsp
    1820:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    1824:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1828:	48 89 c7             	mov    %rax,%rdi
    182b:	e8 e7 fe ff ff       	call   1717 <ioopm_hash_table_size>
    1830:	89 45 ec             	mov    %eax,-0x14(%rbp)
    1833:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1836:	48 98                	cltq
    1838:	be 04 00 00 00       	mov    $0x4,%esi
    183d:	48 89 c7             	mov    %rax,%rdi
    1840:	e8 cb f9 ff ff       	call   1210 <calloc@plt>
    1845:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1849:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    1850:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    1857:	eb 4b                	jmp    18a4 <ioopm_hash_table_keys+0x90>
    1859:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    185d:	8b 55 e8             	mov    -0x18(%rbp),%edx
    1860:	48 63 d2             	movslq %edx,%rdx
    1863:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1867:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    186b:	eb 2c                	jmp    1899 <ioopm_hash_table_keys+0x85>
    186d:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1870:	48 98                	cltq
    1872:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1879:	00 
    187a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    187e:	48 01 c2             	add    %rax,%rdx
    1881:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1885:	8b 00                	mov    (%rax),%eax
    1887:	89 02                	mov    %eax,(%rdx)
    1889:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    188d:	48 8b 40 10          	mov    0x10(%rax),%rax
    1891:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1895:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    1899:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    189e:	75 cd                	jne    186d <ioopm_hash_table_keys+0x59>
    18a0:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    18a4:	83 7d e8 10          	cmpl   $0x10,-0x18(%rbp)
    18a8:	7e af                	jle    1859 <ioopm_hash_table_keys+0x45>
    18aa:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    18ae:	c9                   	leave
    18af:	c3                   	ret

00000000000018b0 <ioopm_hash_table_values>:
    18b0:	f3 0f 1e fa          	endbr64
    18b4:	55                   	push   %rbp
    18b5:	48 89 e5             	mov    %rsp,%rbp
    18b8:	53                   	push   %rbx
    18b9:	48 83 ec 38          	sub    $0x38,%rsp
    18bd:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    18c1:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    18c5:	48 89 c7             	mov    %rax,%rdi
    18c8:	e8 4a fe ff ff       	call   1717 <ioopm_hash_table_size>
    18cd:	89 45 dc             	mov    %eax,-0x24(%rbp)
    18d0:	8b 45 dc             	mov    -0x24(%rbp),%eax
    18d3:	48 98                	cltq
    18d5:	be 08 00 00 00       	mov    $0x8,%esi
    18da:	48 89 c7             	mov    %rax,%rdi
    18dd:	e8 2e f9 ff ff       	call   1210 <calloc@plt>
    18e2:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    18e6:	c7 45 d4 00 00 00 00 	movl   $0x0,-0x2c(%rbp)
    18ed:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    18f4:	eb 58                	jmp    194e <ioopm_hash_table_values+0x9e>
    18f6:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    18fa:	8b 55 d8             	mov    -0x28(%rbp),%edx
    18fd:	48 63 d2             	movslq %edx,%rdx
    1900:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1904:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    1908:	eb 39                	jmp    1943 <ioopm_hash_table_values+0x93>
    190a:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    190e:	48 8b 40 08          	mov    0x8(%rax),%rax
    1912:	8b 55 d4             	mov    -0x2c(%rbp),%edx
    1915:	48 63 d2             	movslq %edx,%rdx
    1918:	48 8d 0c d5 00 00 00 	lea    0x0(,%rdx,8),%rcx
    191f:	00 
    1920:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1924:	48 8d 1c 11          	lea    (%rcx,%rdx,1),%rbx
    1928:	48 89 c7             	mov    %rax,%rdi
    192b:	e8 40 f9 ff ff       	call   1270 <strdup@plt>
    1930:	48 89 03             	mov    %rax,(%rbx)
    1933:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1937:	48 8b 40 10          	mov    0x10(%rax),%rax
    193b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    193f:	83 45 d4 01          	addl   $0x1,-0x2c(%rbp)
    1943:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    1948:	75 c0                	jne    190a <ioopm_hash_table_values+0x5a>
    194a:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
    194e:	83 7d d8 10          	cmpl   $0x10,-0x28(%rbp)
    1952:	7e a2                	jle    18f6 <ioopm_hash_table_values+0x46>
    1954:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1958:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    195c:	c9                   	leave
    195d:	c3                   	ret

000000000000195e <ioopm_hash_table_has_key>:
    195e:	f3 0f 1e fa          	endbr64
    1962:	55                   	push   %rbp
    1963:	48 89 e5             	mov    %rsp,%rbp
    1966:	48 83 ec 10          	sub    $0x10,%rsp
    196a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    196e:	89 75 f4             	mov    %esi,-0xc(%rbp)
    1971:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1974:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1978:	89 d6                	mov    %edx,%esi
    197a:	48 89 c7             	mov    %rax,%rdi
    197d:	e8 72 fc ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1982:	48 85 c0             	test   %rax,%rax
    1985:	0f 95 c0             	setne  %al
    1988:	c9                   	leave
    1989:	c3                   	ret

000000000000198a <ioopm_hash_table_has_value>:
    198a:	f3 0f 1e fa          	endbr64
    198e:	55                   	push   %rbp
    198f:	48 89 e5             	mov    %rsp,%rbp
    1992:	48 83 ec 20          	sub    $0x20,%rsp
    1996:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    199a:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    199e:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    19a5:	eb 4d                	jmp    19f4 <ioopm_hash_table_has_value+0x6a>
    19a7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    19ab:	8b 55 f4             	mov    -0xc(%rbp),%edx
    19ae:	48 63 d2             	movslq %edx,%rdx
    19b1:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    19b5:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    19b9:	eb 2e                	jmp    19e9 <ioopm_hash_table_has_value+0x5f>
    19bb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19bf:	48 8b 50 08          	mov    0x8(%rax),%rdx
    19c3:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    19c7:	48 89 d6             	mov    %rdx,%rsi
    19ca:	48 89 c7             	mov    %rax,%rdi
    19cd:	e8 4e f8 ff ff       	call   1220 <strcmp@plt>
    19d2:	85 c0                	test   %eax,%eax
    19d4:	75 07                	jne    19dd <ioopm_hash_table_has_value+0x53>
    19d6:	b8 01 00 00 00       	mov    $0x1,%eax
    19db:	eb 22                	jmp    19ff <ioopm_hash_table_has_value+0x75>
    19dd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19e1:	48 8b 40 10          	mov    0x10(%rax),%rax
    19e5:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    19e9:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    19ee:	75 cb                	jne    19bb <ioopm_hash_table_has_value+0x31>
    19f0:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    19f4:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    19f8:	7e ad                	jle    19a7 <ioopm_hash_table_has_value+0x1d>
    19fa:	b8 00 00 00 00       	mov    $0x0,%eax
    19ff:	c9                   	leave
    1a00:	c3                   	ret

0000000000001a01 <ioopm_hash_table_all>:
    1a01:	f3 0f 1e fa          	endbr64
    1a05:	55                   	push   %rbp
    1a06:	48 89 e5             	mov    %rsp,%rbp
    1a09:	48 83 ec 30          	sub    $0x30,%rsp
    1a0d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1a11:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1a15:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1a19:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1a20:	eb 57                	jmp    1a79 <ioopm_hash_table_all+0x78>
    1a22:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1a26:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1a29:	48 63 d2             	movslq %edx,%rdx
    1a2c:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1a30:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1a34:	eb 38                	jmp    1a6e <ioopm_hash_table_all+0x6d>
    1a36:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a3a:	48 8b 48 08          	mov    0x8(%rax),%rcx
    1a3e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a42:	8b 00                	mov    (%rax),%eax
    1a44:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1a48:	4c 8b 45 e0          	mov    -0x20(%rbp),%r8
    1a4c:	48 89 ce             	mov    %rcx,%rsi
    1a4f:	89 c7                	mov    %eax,%edi
    1a51:	41 ff d0             	call   *%r8
    1a54:	83 f0 01             	xor    $0x1,%eax
    1a57:	84 c0                	test   %al,%al
    1a59:	74 07                	je     1a62 <ioopm_hash_table_all+0x61>
    1a5b:	b8 00 00 00 00       	mov    $0x0,%eax
    1a60:	eb 22                	jmp    1a84 <ioopm_hash_table_all+0x83>
    1a62:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a66:	48 8b 40 10          	mov    0x10(%rax),%rax
    1a6a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1a6e:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1a73:	75 c1                	jne    1a36 <ioopm_hash_table_all+0x35>
    1a75:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    1a79:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    1a7d:	7e a3                	jle    1a22 <ioopm_hash_table_all+0x21>
    1a7f:	b8 01 00 00 00       	mov    $0x1,%eax
    1a84:	c9                   	leave
    1a85:	c3                   	ret

0000000000001a86 <ioopm_hash_table_any>:
    1a86:	f3 0f 1e fa          	endbr64
    1a8a:	55                   	push   %rbp
    1a8b:	48 89 e5             	mov    %rsp,%rbp
    1a8e:	48 83 ec 30          	sub    $0x30,%rsp
    1a92:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1a96:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1a9a:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1a9e:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1aa5:	eb 54                	jmp    1afb <ioopm_hash_table_any+0x75>
    1aa7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1aab:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1aae:	48 63 d2             	movslq %edx,%rdx
    1ab1:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1ab5:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1ab9:	eb 35                	jmp    1af0 <ioopm_hash_table_any+0x6a>
    1abb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1abf:	48 8b 48 08          	mov    0x8(%rax),%rcx
    1ac3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ac7:	8b 00                	mov    (%rax),%eax
    1ac9:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1acd:	4c 8b 45 e0          	mov    -0x20(%rbp),%r8
    1ad1:	48 89 ce             	mov    %rcx,%rsi
    1ad4:	89 c7                	mov    %eax,%edi
    1ad6:	41 ff d0             	call   *%r8
    1ad9:	84 c0                	test   %al,%al
    1adb:	74 07                	je     1ae4 <ioopm_hash_table_any+0x5e>
    1add:	b8 01 00 00 00       	mov    $0x1,%eax
    1ae2:	eb 22                	jmp    1b06 <ioopm_hash_table_any+0x80>
    1ae4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ae8:	48 8b 40 10          	mov    0x10(%rax),%rax
    1aec:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1af0:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1af5:	75 c4                	jne    1abb <ioopm_hash_table_any+0x35>
    1af7:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    1afb:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    1aff:	7e a6                	jle    1aa7 <ioopm_hash_table_any+0x21>
    1b01:	b8 00 00 00 00       	mov    $0x0,%eax
    1b06:	c9                   	leave
    1b07:	c3                   	ret

0000000000001b08 <ioopm_hash_table_apply_to_all>:
    1b08:	f3 0f 1e fa          	endbr64
    1b0c:	55                   	push   %rbp
    1b0d:	48 89 e5             	mov    %rsp,%rbp
    1b10:	48 83 ec 30          	sub    $0x30,%rsp
    1b14:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1b18:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1b1c:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    1b20:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    1b25:	74 5d                	je     1b84 <ioopm_hash_table_apply_to_all+0x7c>
    1b27:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    1b2c:	74 56                	je     1b84 <ioopm_hash_table_apply_to_all+0x7c>
    1b2e:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    1b35:	eb 45                	jmp    1b7c <ioopm_hash_table_apply_to_all+0x74>
    1b37:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1b3b:	8b 55 f4             	mov    -0xc(%rbp),%edx
    1b3e:	48 63 d2             	movslq %edx,%rdx
    1b41:	48 8b 04 d0          	mov    (%rax,%rdx,8),%rax
    1b45:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1b49:	eb 26                	jmp    1b71 <ioopm_hash_table_apply_to_all+0x69>
    1b4b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1b4f:	48 8d 70 08          	lea    0x8(%rax),%rsi
    1b53:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1b57:	8b 00                	mov    (%rax),%eax
    1b59:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    1b5d:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    1b61:	89 c7                	mov    %eax,%edi
    1b63:	ff d1                	call   *%rcx
    1b65:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1b69:	48 8b 40 10          	mov    0x10(%rax),%rax
    1b6d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1b71:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1b76:	75 d3                	jne    1b4b <ioopm_hash_table_apply_to_all+0x43>
    1b78:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    1b7c:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    1b80:	7e b5                	jle    1b37 <ioopm_hash_table_apply_to_all+0x2f>
    1b82:	eb 01                	jmp    1b85 <ioopm_hash_table_apply_to_all+0x7d>
    1b84:	90                   	nop
    1b85:	c9                   	leave
    1b86:	c3                   	ret

0000000000001b87 <init_suite>:
    1b87:	f3 0f 1e fa          	endbr64
    1b8b:	55                   	push   %rbp
    1b8c:	48 89 e5             	mov    %rsp,%rbp
    1b8f:	b8 00 00 00 00       	mov    $0x0,%eax
    1b94:	5d                   	pop    %rbp
    1b95:	c3                   	ret

0000000000001b96 <clean_suite>:
    1b96:	f3 0f 1e fa          	endbr64
    1b9a:	55                   	push   %rbp
    1b9b:	48 89 e5             	mov    %rsp,%rbp
    1b9e:	b8 00 00 00 00       	mov    $0x0,%eax
    1ba3:	5d                   	pop    %rbp
    1ba4:	c3                   	ret

0000000000001ba5 <test_create_destroy>:
    1ba5:	f3 0f 1e fa          	endbr64
    1ba9:	55                   	push   %rbp
    1baa:	48 89 e5             	mov    %rsp,%rbp
    1bad:	48 83 ec 10          	sub    $0x10,%rsp
    1bb1:	e8 b3 f7 ff ff       	call   1369 <ioopm_hash_table_create>
    1bb6:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1bba:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1bbf:	0f 95 c0             	setne  %al
    1bc2:	0f b6 c0             	movzbl %al,%eax
    1bc5:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1bcb:	4c 8d 05 36 24 00 00 	lea    0x2436(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1bd2:	48 8d 15 30 24 00 00 	lea    0x2430(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1bd9:	48 89 d1             	mov    %rdx,%rcx
    1bdc:	48 8d 15 33 24 00 00 	lea    0x2433(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    1be3:	be 17 00 00 00       	mov    $0x17,%esi
    1be8:	89 c7                	mov    %eax,%edi
    1bea:	e8 41 f6 ff ff       	call   1230 <CU_assertImplementation@plt>
    1bef:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1bf3:	48 89 c7             	mov    %rax,%rdi
    1bf6:	e8 93 f7 ff ff       	call   138e <ioopm_hash_table_destroy>
    1bfb:	90                   	nop
    1bfc:	c9                   	leave
    1bfd:	c3                   	ret

0000000000001bfe <test_insert_once>:
    1bfe:	f3 0f 1e fa          	endbr64
    1c02:	55                   	push   %rbp
    1c03:	48 89 e5             	mov    %rsp,%rbp
    1c06:	48 83 ec 20          	sub    $0x20,%rsp
    1c0a:	e8 5a f7 ff ff       	call   1369 <ioopm_hash_table_create>
    1c0f:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1c13:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1c17:	be 2a 00 00 00       	mov    $0x2a,%esi
    1c1c:	48 89 c7             	mov    %rax,%rdi
    1c1f:	e8 d0 f9 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1c24:	48 85 c0             	test   %rax,%rax
    1c27:	0f 94 c0             	sete   %al
    1c2a:	0f b6 c0             	movzbl %al,%eax
    1c2d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1c33:	4c 8d 05 ce 23 00 00 	lea    0x23ce(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1c3a:	48 8d 15 c8 23 00 00 	lea    0x23c8(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1c41:	48 89 d1             	mov    %rdx,%rcx
    1c44:	48 8d 15 ed 23 00 00 	lea    0x23ed(%rip),%rdx        # 4038 <_IO_stdin_used+0x38>
    1c4b:	be 1f 00 00 00       	mov    $0x1f,%esi
    1c50:	89 c7                	mov    %eax,%edi
    1c52:	e8 d9 f5 ff ff       	call   1230 <CU_assertImplementation@plt>
    1c57:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1c5b:	48 8d 15 0a 24 00 00 	lea    0x240a(%rip),%rdx        # 406c <_IO_stdin_used+0x6c>
    1c62:	be 2a 00 00 00       	mov    $0x2a,%esi
    1c67:	48 89 c7             	mov    %rax,%rdi
    1c6a:	e8 4e f8 ff ff       	call   14bd <ioopm_hash_table_insert>
    1c6f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1c73:	be 2a 00 00 00       	mov    $0x2a,%esi
    1c78:	48 89 c7             	mov    %rax,%rdi
    1c7b:	e8 74 f9 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1c80:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1c84:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1c88:	48 8d 15 dd 23 00 00 	lea    0x23dd(%rip),%rdx        # 406c <_IO_stdin_used+0x6c>
    1c8f:	48 89 d6             	mov    %rdx,%rsi
    1c92:	48 89 c7             	mov    %rax,%rdi
    1c95:	e8 86 f5 ff ff       	call   1220 <strcmp@plt>
    1c9a:	85 c0                	test   %eax,%eax
    1c9c:	0f 94 c0             	sete   %al
    1c9f:	0f b6 c0             	movzbl %al,%eax
    1ca2:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1ca8:	4c 8d 05 59 23 00 00 	lea    0x2359(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1caf:	48 8d 15 53 23 00 00 	lea    0x2353(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1cb6:	48 89 d1             	mov    %rdx,%rcx
    1cb9:	48 8d 15 b8 23 00 00 	lea    0x23b8(%rip),%rdx        # 4078 <_IO_stdin_used+0x78>
    1cc0:	be 26 00 00 00       	mov    $0x26,%esi
    1cc5:	89 c7                	mov    %eax,%edi
    1cc7:	e8 64 f5 ff ff       	call   1230 <CU_assertImplementation@plt>
    1ccc:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    1cd3:	eb 3f                	jmp    1d14 <test_insert_once+0x116>
    1cd5:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    1cd8:	48 63 c1             	movslq %ecx,%rax
    1cdb:	48 69 c0 79 78 78 78 	imul   $0x78787879,%rax,%rax
    1ce2:	48 c1 e8 20          	shr    $0x20,%rax
    1ce6:	c1 f8 03             	sar    $0x3,%eax
    1ce9:	89 ca                	mov    %ecx,%edx
    1ceb:	c1 fa 1f             	sar    $0x1f,%edx
    1cee:	29 d0                	sub    %edx,%eax
    1cf0:	89 c2                	mov    %eax,%edx
    1cf2:	c1 e2 04             	shl    $0x4,%edx
    1cf5:	01 c2                	add    %eax,%edx
    1cf7:	89 c8                	mov    %ecx,%eax
    1cf9:	29 d0                	sub    %edx,%eax
    1cfb:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    1cff:	48 8d 15 98 23 00 00 	lea    0x2398(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    1d06:	89 c6                	mov    %eax,%esi
    1d08:	48 89 cf             	mov    %rcx,%rdi
    1d0b:	e8 ad f7 ff ff       	call   14bd <ioopm_hash_table_insert>
    1d10:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    1d14:	83 7d e4 10          	cmpl   $0x10,-0x1c(%rbp)
    1d18:	7e bb                	jle    1cd5 <test_insert_once+0xd7>
    1d1a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1d1e:	be 64 00 00 00       	mov    $0x64,%esi
    1d23:	48 89 c7             	mov    %rax,%rdi
    1d26:	e8 c9 f8 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1d2b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1d2f:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1d34:	0f 94 c0             	sete   %al
    1d37:	0f b6 c0             	movzbl %al,%eax
    1d3a:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1d40:	4c 8d 05 c1 22 00 00 	lea    0x22c1(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1d47:	48 8d 15 bb 22 00 00 	lea    0x22bb(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1d4e:	48 89 d1             	mov    %rdx,%rcx
    1d51:	48 8d 15 4d 23 00 00 	lea    0x234d(%rip),%rdx        # 40a5 <_IO_stdin_used+0xa5>
    1d58:	be 30 00 00 00       	mov    $0x30,%esi
    1d5d:	89 c7                	mov    %eax,%edi
    1d5f:	e8 cc f4 ff ff       	call   1230 <CU_assertImplementation@plt>
    1d64:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1d68:	48 89 c7             	mov    %rax,%rdi
    1d6b:	e8 1e f6 ff ff       	call   138e <ioopm_hash_table_destroy>
    1d70:	90                   	nop
    1d71:	c9                   	leave
    1d72:	c3                   	ret

0000000000001d73 <test_insert_remove>:
    1d73:	f3 0f 1e fa          	endbr64
    1d77:	55                   	push   %rbp
    1d78:	48 89 e5             	mov    %rsp,%rbp
    1d7b:	48 83 ec 20          	sub    $0x20,%rsp
    1d7f:	e8 e5 f5 ff ff       	call   1369 <ioopm_hash_table_create>
    1d84:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    1d88:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1d8c:	be 2a 00 00 00       	mov    $0x2a,%esi
    1d91:	48 89 c7             	mov    %rax,%rdi
    1d94:	e8 5b f8 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1d99:	48 85 c0             	test   %rax,%rax
    1d9c:	0f 94 c0             	sete   %al
    1d9f:	0f b6 c0             	movzbl %al,%eax
    1da2:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1da8:	4c 8d 05 59 22 00 00 	lea    0x2259(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1daf:	48 8d 15 53 22 00 00 	lea    0x2253(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1db6:	48 89 d1             	mov    %rdx,%rcx
    1db9:	48 8d 15 78 22 00 00 	lea    0x2278(%rip),%rdx        # 4038 <_IO_stdin_used+0x38>
    1dc0:	be 37 00 00 00       	mov    $0x37,%esi
    1dc5:	89 c7                	mov    %eax,%edi
    1dc7:	e8 64 f4 ff ff       	call   1230 <CU_assertImplementation@plt>
    1dcc:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1dd0:	48 8d 15 95 22 00 00 	lea    0x2295(%rip),%rdx        # 406c <_IO_stdin_used+0x6c>
    1dd7:	be 2a 00 00 00       	mov    $0x2a,%esi
    1ddc:	48 89 c7             	mov    %rax,%rdi
    1ddf:	e8 d9 f6 ff ff       	call   14bd <ioopm_hash_table_insert>
    1de4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1de8:	be 2a 00 00 00       	mov    $0x2a,%esi
    1ded:	48 89 c7             	mov    %rax,%rdi
    1df0:	e8 ff f7 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1df5:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1df9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1dfd:	48 8d 15 68 22 00 00 	lea    0x2268(%rip),%rdx        # 406c <_IO_stdin_used+0x6c>
    1e04:	48 89 d6             	mov    %rdx,%rsi
    1e07:	48 89 c7             	mov    %rax,%rdi
    1e0a:	e8 11 f4 ff ff       	call   1220 <strcmp@plt>
    1e0f:	85 c0                	test   %eax,%eax
    1e11:	0f 94 c0             	sete   %al
    1e14:	0f b6 c0             	movzbl %al,%eax
    1e17:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1e1d:	4c 8d 05 e4 21 00 00 	lea    0x21e4(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1e24:	48 8d 15 de 21 00 00 	lea    0x21de(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1e2b:	48 89 d1             	mov    %rdx,%rcx
    1e2e:	48 8d 15 43 22 00 00 	lea    0x2243(%rip),%rdx        # 4078 <_IO_stdin_used+0x78>
    1e35:	be 3e 00 00 00       	mov    $0x3e,%esi
    1e3a:	89 c7                	mov    %eax,%edi
    1e3c:	e8 ef f3 ff ff       	call   1230 <CU_assertImplementation@plt>
    1e41:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1e45:	be 64 00 00 00       	mov    $0x64,%esi
    1e4a:	48 89 c7             	mov    %rax,%rdi
    1e4d:	e8 a2 f7 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1e52:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1e56:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    1e5b:	0f 94 c0             	sete   %al
    1e5e:	0f b6 c0             	movzbl %al,%eax
    1e61:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1e67:	4c 8d 05 9a 21 00 00 	lea    0x219a(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1e6e:	48 8d 15 94 21 00 00 	lea    0x2194(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1e75:	48 89 d1             	mov    %rdx,%rcx
    1e78:	48 8d 15 26 22 00 00 	lea    0x2226(%rip),%rdx        # 40a5 <_IO_stdin_used+0xa5>
    1e7f:	be 42 00 00 00       	mov    $0x42,%esi
    1e84:	89 c7                	mov    %eax,%edi
    1e86:	e8 a5 f3 ff ff       	call   1230 <CU_assertImplementation@plt>
    1e8b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1e8f:	be 2a 00 00 00       	mov    $0x2a,%esi
    1e94:	48 89 c7             	mov    %rax,%rdi
    1e97:	e8 95 f7 ff ff       	call   1631 <ioopm_hash_table_remove>
    1e9c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1ea0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ea4:	48 8d 15 c1 21 00 00 	lea    0x21c1(%rip),%rdx        # 406c <_IO_stdin_used+0x6c>
    1eab:	48 89 d6             	mov    %rdx,%rsi
    1eae:	48 89 c7             	mov    %rax,%rdi
    1eb1:	e8 6a f3 ff ff       	call   1220 <strcmp@plt>
    1eb6:	85 c0                	test   %eax,%eax
    1eb8:	0f 94 c0             	sete   %al
    1ebb:	0f b6 c0             	movzbl %al,%eax
    1ebe:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1ec4:	4c 8d 05 3d 21 00 00 	lea    0x213d(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1ecb:	48 8d 15 37 21 00 00 	lea    0x2137(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1ed2:	48 89 d1             	mov    %rdx,%rcx
    1ed5:	48 8d 15 ec 21 00 00 	lea    0x21ec(%rip),%rdx        # 40c8 <_IO_stdin_used+0xc8>
    1edc:	be 48 00 00 00       	mov    $0x48,%esi
    1ee1:	89 c7                	mov    %eax,%edi
    1ee3:	e8 48 f3 ff ff       	call   1230 <CU_assertImplementation@plt>
    1ee8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1eec:	48 89 c7             	mov    %rax,%rdi
    1eef:	e8 7c f2 ff ff       	call   1170 <free@plt>
    1ef4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1ef8:	be 2a 00 00 00       	mov    $0x2a,%esi
    1efd:	48 89 c7             	mov    %rax,%rdi
    1f00:	e8 ef f6 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    1f05:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1f09:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    1f0e:	0f 94 c0             	sete   %al
    1f11:	0f b6 c0             	movzbl %al,%eax
    1f14:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1f1a:	4c 8d 05 e7 20 00 00 	lea    0x20e7(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1f21:	48 8d 15 e1 20 00 00 	lea    0x20e1(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1f28:	48 89 d1             	mov    %rdx,%rcx
    1f2b:	48 8d 15 c4 21 00 00 	lea    0x21c4(%rip),%rdx        # 40f6 <_IO_stdin_used+0xf6>
    1f32:	be 4d 00 00 00       	mov    $0x4d,%esi
    1f37:	89 c7                	mov    %eax,%edi
    1f39:	e8 f2 f2 ff ff       	call   1230 <CU_assertImplementation@plt>
    1f3e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1f42:	48 89 c7             	mov    %rax,%rdi
    1f45:	e8 44 f4 ff ff       	call   138e <ioopm_hash_table_destroy>
    1f4a:	90                   	nop
    1f4b:	c9                   	leave
    1f4c:	c3                   	ret

0000000000001f4d <test_size>:
    1f4d:	f3 0f 1e fa          	endbr64
    1f51:	55                   	push   %rbp
    1f52:	48 89 e5             	mov    %rsp,%rbp
    1f55:	48 83 ec 10          	sub    $0x10,%rsp
    1f59:	e8 0b f4 ff ff       	call   1369 <ioopm_hash_table_create>
    1f5e:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1f62:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1f67:	0f 95 c0             	setne  %al
    1f6a:	0f b6 c0             	movzbl %al,%eax
    1f6d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1f73:	4c 8d 05 8e 20 00 00 	lea    0x208e(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1f7a:	48 8d 15 88 20 00 00 	lea    0x2088(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1f81:	48 89 d1             	mov    %rdx,%rcx
    1f84:	48 8d 15 8b 20 00 00 	lea    0x208b(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    1f8b:	be 54 00 00 00       	mov    $0x54,%esi
    1f90:	89 c7                	mov    %eax,%edi
    1f92:	e8 99 f2 ff ff       	call   1230 <CU_assertImplementation@plt>
    1f97:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1f9b:	48 89 c7             	mov    %rax,%rdi
    1f9e:	e8 74 f7 ff ff       	call   1717 <ioopm_hash_table_size>
    1fa3:	85 c0                	test   %eax,%eax
    1fa5:	0f 94 c0             	sete   %al
    1fa8:	0f b6 c0             	movzbl %al,%eax
    1fab:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1fb1:	4c 8d 05 50 20 00 00 	lea    0x2050(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    1fb8:	48 8d 15 4a 20 00 00 	lea    0x204a(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    1fbf:	48 89 d1             	mov    %rdx,%rcx
    1fc2:	48 8d 15 47 21 00 00 	lea    0x2147(%rip),%rdx        # 4110 <_IO_stdin_used+0x110>
    1fc9:	be 57 00 00 00       	mov    $0x57,%esi
    1fce:	89 c7                	mov    %eax,%edi
    1fd0:	e8 5b f2 ff ff       	call   1230 <CU_assertImplementation@plt>
    1fd5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1fd9:	48 8d 15 5d 21 00 00 	lea    0x215d(%rip),%rdx        # 413d <_IO_stdin_used+0x13d>
    1fe0:	be 10 00 00 00       	mov    $0x10,%esi
    1fe5:	48 89 c7             	mov    %rax,%rdi
    1fe8:	e8 d0 f4 ff ff       	call   14bd <ioopm_hash_table_insert>
    1fed:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1ff1:	48 89 c7             	mov    %rax,%rdi
    1ff4:	e8 1e f7 ff ff       	call   1717 <ioopm_hash_table_size>
    1ff9:	83 f8 01             	cmp    $0x1,%eax
    1ffc:	0f 94 c0             	sete   %al
    1fff:	0f b6 c0             	movzbl %al,%eax
    2002:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2008:	4c 8d 05 f9 1f 00 00 	lea    0x1ff9(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    200f:	48 8d 15 f3 1f 00 00 	lea    0x1ff3(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2016:	48 89 d1             	mov    %rdx,%rcx
    2019:	48 8d 15 28 21 00 00 	lea    0x2128(%rip),%rdx        # 4148 <_IO_stdin_used+0x148>
    2020:	be 5d 00 00 00       	mov    $0x5d,%esi
    2025:	89 c7                	mov    %eax,%edi
    2027:	e8 04 f2 ff ff       	call   1230 <CU_assertImplementation@plt>
    202c:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    2033:	eb 1c                	jmp    2051 <test_size+0x104>
    2035:	8b 4d f4             	mov    -0xc(%rbp),%ecx
    2038:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    203c:	48 8d 15 5b 20 00 00 	lea    0x205b(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    2043:	89 ce                	mov    %ecx,%esi
    2045:	48 89 c7             	mov    %rax,%rdi
    2048:	e8 70 f4 ff ff       	call   14bd <ioopm_hash_table_insert>
    204d:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    2051:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    2055:	7e de                	jle    2035 <test_size+0xe8>
    2057:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    205b:	48 89 c7             	mov    %rax,%rdi
    205e:	e8 b4 f6 ff ff       	call   1717 <ioopm_hash_table_size>
    2063:	83 f8 11             	cmp    $0x11,%eax
    2066:	0f 94 c0             	sete   %al
    2069:	0f b6 c0             	movzbl %al,%eax
    206c:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2072:	4c 8d 05 8f 1f 00 00 	lea    0x1f8f(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2079:	48 8d 15 89 1f 00 00 	lea    0x1f89(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2080:	48 89 d1             	mov    %rdx,%rcx
    2083:	48 8d 15 ee 20 00 00 	lea    0x20ee(%rip),%rdx        # 4178 <_IO_stdin_used+0x178>
    208a:	be 64 00 00 00       	mov    $0x64,%esi
    208f:	89 c7                	mov    %eax,%edi
    2091:	e8 9a f1 ff ff       	call   1230 <CU_assertImplementation@plt>
    2096:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    209a:	48 89 c7             	mov    %rax,%rdi
    209d:	e8 ec f2 ff ff       	call   138e <ioopm_hash_table_destroy>
    20a2:	90                   	nop
    20a3:	c9                   	leave
    20a4:	c3                   	ret

00000000000020a5 <test_is_empty_clear>:
    20a5:	f3 0f 1e fa          	endbr64
    20a9:	55                   	push   %rbp
    20aa:	48 89 e5             	mov    %rsp,%rbp
    20ad:	48 83 ec 10          	sub    $0x10,%rsp
    20b1:	e8 b3 f2 ff ff       	call   1369 <ioopm_hash_table_create>
    20b6:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    20ba:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    20bf:	0f 95 c0             	setne  %al
    20c2:	0f b6 c0             	movzbl %al,%eax
    20c5:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    20cb:	4c 8d 05 36 1f 00 00 	lea    0x1f36(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    20d2:	48 8d 15 30 1f 00 00 	lea    0x1f30(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    20d9:	48 89 d1             	mov    %rdx,%rcx
    20dc:	48 8d 15 33 1f 00 00 	lea    0x1f33(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    20e3:	be 6b 00 00 00       	mov    $0x6b,%esi
    20e8:	89 c7                	mov    %eax,%edi
    20ea:	e8 41 f1 ff ff       	call   1230 <CU_assertImplementation@plt>
    20ef:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    20f3:	48 89 c7             	mov    %rax,%rdi
    20f6:	e8 72 f6 ff ff       	call   176d <ioopm_hash_table_is_empty>
    20fb:	0f b6 c0             	movzbl %al,%eax
    20fe:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2104:	4c 8d 05 fd 1e 00 00 	lea    0x1efd(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    210b:	48 8d 15 f7 1e 00 00 	lea    0x1ef7(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2112:	48 89 d1             	mov    %rdx,%rcx
    2115:	48 8d 15 94 20 00 00 	lea    0x2094(%rip),%rdx        # 41b0 <_IO_stdin_used+0x1b0>
    211c:	be 6e 00 00 00       	mov    $0x6e,%esi
    2121:	89 c7                	mov    %eax,%edi
    2123:	e8 08 f1 ff ff       	call   1230 <CU_assertImplementation@plt>
    2128:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
    212f:	eb 3f                	jmp    2170 <test_is_empty_clear+0xcb>
    2131:	8b 4d f4             	mov    -0xc(%rbp),%ecx
    2134:	48 63 c1             	movslq %ecx,%rax
    2137:	48 69 c0 79 78 78 78 	imul   $0x78787879,%rax,%rax
    213e:	48 c1 e8 20          	shr    $0x20,%rax
    2142:	c1 f8 03             	sar    $0x3,%eax
    2145:	89 ca                	mov    %ecx,%edx
    2147:	c1 fa 1f             	sar    $0x1f,%edx
    214a:	29 d0                	sub    %edx,%eax
    214c:	89 c2                	mov    %eax,%edx
    214e:	c1 e2 04             	shl    $0x4,%edx
    2151:	01 c2                	add    %eax,%edx
    2153:	89 c8                	mov    %ecx,%eax
    2155:	29 d0                	sub    %edx,%eax
    2157:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    215b:	48 8d 15 3c 1f 00 00 	lea    0x1f3c(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    2162:	89 c6                	mov    %eax,%esi
    2164:	48 89 cf             	mov    %rcx,%rdi
    2167:	e8 51 f3 ff ff       	call   14bd <ioopm_hash_table_insert>
    216c:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
    2170:	83 7d f4 10          	cmpl   $0x10,-0xc(%rbp)
    2174:	7e bb                	jle    2131 <test_is_empty_clear+0x8c>
    2176:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    217a:	48 89 c7             	mov    %rax,%rdi
    217d:	e8 0e f6 ff ff       	call   1790 <ioopm_hash_table_clear>
    2182:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2186:	48 89 c7             	mov    %rax,%rdi
    2189:	e8 df f5 ff ff       	call   176d <ioopm_hash_table_is_empty>
    218e:	0f b6 c0             	movzbl %al,%eax
    2191:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2197:	4c 8d 05 6a 1e 00 00 	lea    0x1e6a(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    219e:	48 8d 15 64 1e 00 00 	lea    0x1e64(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    21a5:	48 89 d1             	mov    %rdx,%rcx
    21a8:	48 8d 15 01 20 00 00 	lea    0x2001(%rip),%rdx        # 41b0 <_IO_stdin_used+0x1b0>
    21af:	be 79 00 00 00       	mov    $0x79,%esi
    21b4:	89 c7                	mov    %eax,%edi
    21b6:	e8 75 f0 ff ff       	call   1230 <CU_assertImplementation@plt>
    21bb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    21bf:	48 89 c7             	mov    %rax,%rdi
    21c2:	e8 c7 f1 ff ff       	call   138e <ioopm_hash_table_destroy>
    21c7:	90                   	nop
    21c8:	c9                   	leave
    21c9:	c3                   	ret

00000000000021ca <test_keys>:
    21ca:	f3 0f 1e fa          	endbr64
    21ce:	55                   	push   %rbp
    21cf:	48 89 e5             	mov    %rsp,%rbp
    21d2:	48 83 ec 50          	sub    $0x50,%rsp
    21d6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    21dd:	00 00 
    21df:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    21e3:	31 c0                	xor    %eax,%eax
    21e5:	e8 7f f1 ff ff       	call   1369 <ioopm_hash_table_create>
    21ea:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    21ee:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
    21f3:	0f 95 c0             	setne  %al
    21f6:	0f b6 c0             	movzbl %al,%eax
    21f9:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    21ff:	4c 8d 05 02 1e 00 00 	lea    0x1e02(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2206:	48 8d 15 fc 1d 00 00 	lea    0x1dfc(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    220d:	48 89 d1             	mov    %rdx,%rcx
    2210:	48 8d 15 ff 1d 00 00 	lea    0x1dff(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    2217:	be 82 00 00 00       	mov    $0x82,%esi
    221c:	89 c7                	mov    %eax,%edi
    221e:	e8 0d f0 ff ff       	call   1230 <CU_assertImplementation@plt>
    2223:	c7 45 e0 03 00 00 00 	movl   $0x3,-0x20(%rbp)
    222a:	c7 45 e4 0a 00 00 00 	movl   $0xa,-0x1c(%rbp)
    2231:	c7 45 e8 2a 00 00 00 	movl   $0x2a,-0x18(%rbp)
    2238:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    223f:	c7 45 f0 63 00 00 00 	movl   $0x63,-0x10(%rbp)
    2246:	c6 45 db 00          	movb   $0x0,-0x25(%rbp)
    224a:	c6 45 dc 00          	movb   $0x0,-0x24(%rbp)
    224e:	c6 45 dd 00          	movb   $0x0,-0x23(%rbp)
    2252:	c6 45 de 00          	movb   $0x0,-0x22(%rbp)
    2256:	c6 45 df 00          	movb   $0x0,-0x21(%rbp)
    225a:	c7 45 c4 05 00 00 00 	movl   $0x5,-0x3c(%rbp)
    2261:	c7 45 b4 00 00 00 00 	movl   $0x0,-0x4c(%rbp)
    2268:	eb 22                	jmp    228c <test_keys+0xc2>
    226a:	8b 45 b4             	mov    -0x4c(%rbp),%eax
    226d:	48 98                	cltq
    226f:	8b 4c 85 e0          	mov    -0x20(%rbp,%rax,4),%ecx
    2273:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2277:	48 8d 15 66 1f 00 00 	lea    0x1f66(%rip),%rdx        # 41e4 <_IO_stdin_used+0x1e4>
    227e:	89 ce                	mov    %ecx,%esi
    2280:	48 89 c7             	mov    %rax,%rdi
    2283:	e8 35 f2 ff ff       	call   14bd <ioopm_hash_table_insert>
    2288:	83 45 b4 01          	addl   $0x1,-0x4c(%rbp)
    228c:	8b 45 b4             	mov    -0x4c(%rbp),%eax
    228f:	3b 45 c4             	cmp    -0x3c(%rbp),%eax
    2292:	7c d6                	jl     226a <test_keys+0xa0>
    2294:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2298:	48 89 c7             	mov    %rax,%rdi
    229b:	e8 74 f5 ff ff       	call   1814 <ioopm_hash_table_keys>
    22a0:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    22a4:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
    22a9:	0f 95 c0             	setne  %al
    22ac:	0f b6 c0             	movzbl %al,%eax
    22af:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    22b5:	4c 8d 05 4c 1d 00 00 	lea    0x1d4c(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    22bc:	48 8d 15 46 1d 00 00 	lea    0x1d46(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    22c3:	48 89 d1             	mov    %rdx,%rcx
    22c6:	48 8d 15 2b 1f 00 00 	lea    0x1f2b(%rip),%rdx        # 41f8 <_IO_stdin_used+0x1f8>
    22cd:	be 8f 00 00 00       	mov    $0x8f,%esi
    22d2:	89 c7                	mov    %eax,%edi
    22d4:	e8 57 ef ff ff       	call   1230 <CU_assertImplementation@plt>
    22d9:	c7 45 b8 00 00 00 00 	movl   $0x0,-0x48(%rbp)
    22e0:	e9 8b 00 00 00       	jmp    2370 <test_keys+0x1a6>
    22e5:	c6 45 b3 00          	movb   $0x0,-0x4d(%rbp)
    22e9:	c7 45 bc 00 00 00 00 	movl   $0x0,-0x44(%rbp)
    22f0:	eb 37                	jmp    2329 <test_keys+0x15f>
    22f2:	8b 45 b8             	mov    -0x48(%rbp),%eax
    22f5:	48 98                	cltq
    22f7:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    22fe:	00 
    22ff:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    2303:	48 01 d0             	add    %rdx,%rax
    2306:	8b 10                	mov    (%rax),%edx
    2308:	8b 45 bc             	mov    -0x44(%rbp),%eax
    230b:	48 98                	cltq
    230d:	8b 44 85 e0          	mov    -0x20(%rbp,%rax,4),%eax
    2311:	39 c2                	cmp    %eax,%edx
    2313:	75 10                	jne    2325 <test_keys+0x15b>
    2315:	8b 45 bc             	mov    -0x44(%rbp),%eax
    2318:	48 98                	cltq
    231a:	c6 44 05 db 01       	movb   $0x1,-0x25(%rbp,%rax,1)
    231f:	c6 45 b3 01          	movb   $0x1,-0x4d(%rbp)
    2323:	eb 0c                	jmp    2331 <test_keys+0x167>
    2325:	83 45 bc 01          	addl   $0x1,-0x44(%rbp)
    2329:	8b 45 bc             	mov    -0x44(%rbp),%eax
    232c:	3b 45 c4             	cmp    -0x3c(%rbp),%eax
    232f:	7c c1                	jl     22f2 <test_keys+0x128>
    2331:	0f b6 45 b3          	movzbl -0x4d(%rbp),%eax
    2335:	83 f0 01             	xor    $0x1,%eax
    2338:	84 c0                	test   %al,%al
    233a:	74 30                	je     236c <test_keys+0x1a2>
    233c:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2342:	4c 8d 05 bf 1c 00 00 	lea    0x1cbf(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2349:	48 8d 05 b9 1c 00 00 	lea    0x1cb9(%rip),%rax        # 4009 <_IO_stdin_used+0x9>
    2350:	48 89 c1             	mov    %rax,%rcx
    2353:	48 8d 05 c6 1e 00 00 	lea    0x1ec6(%rip),%rax        # 4220 <_IO_stdin_used+0x220>
    235a:	48 89 c2             	mov    %rax,%rdx
    235d:	be 9c 00 00 00       	mov    $0x9c,%esi
    2362:	bf 00 00 00 00       	mov    $0x0,%edi
    2367:	e8 c4 ee ff ff       	call   1230 <CU_assertImplementation@plt>
    236c:	83 45 b8 01          	addl   $0x1,-0x48(%rbp)
    2370:	8b 45 b8             	mov    -0x48(%rbp),%eax
    2373:	3b 45 c4             	cmp    -0x3c(%rbp),%eax
    2376:	0f 8c 69 ff ff ff    	jl     22e5 <test_keys+0x11b>
    237c:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%rbp)
    2383:	eb 3b                	jmp    23c0 <test_keys+0x1f6>
    2385:	8b 45 c0             	mov    -0x40(%rbp),%eax
    2388:	48 98                	cltq
    238a:	0f b6 44 05 db       	movzbl -0x25(%rbp,%rax,1),%eax
    238f:	0f b6 c0             	movzbl %al,%eax
    2392:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2398:	4c 8d 05 69 1c 00 00 	lea    0x1c69(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    239f:	48 8d 15 63 1c 00 00 	lea    0x1c63(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    23a6:	48 89 d1             	mov    %rdx,%rcx
    23a9:	48 8d 15 a0 1e 00 00 	lea    0x1ea0(%rip),%rdx        # 4250 <_IO_stdin_used+0x250>
    23b0:	be a2 00 00 00       	mov    $0xa2,%esi
    23b5:	89 c7                	mov    %eax,%edi
    23b7:	e8 74 ee ff ff       	call   1230 <CU_assertImplementation@plt>
    23bc:	83 45 c0 01          	addl   $0x1,-0x40(%rbp)
    23c0:	8b 45 c0             	mov    -0x40(%rbp),%eax
    23c3:	3b 45 c4             	cmp    -0x3c(%rbp),%eax
    23c6:	7c bd                	jl     2385 <test_keys+0x1bb>
    23c8:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    23cc:	48 89 c7             	mov    %rax,%rdi
    23cf:	e8 9c ed ff ff       	call   1170 <free@plt>
    23d4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    23d8:	48 89 c7             	mov    %rax,%rdi
    23db:	e8 ae ef ff ff       	call   138e <ioopm_hash_table_destroy>
    23e0:	90                   	nop
    23e1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    23e5:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    23ec:	00 00 
    23ee:	74 05                	je     23f5 <test_keys+0x22b>
    23f0:	e8 eb ed ff ff       	call   11e0 <__stack_chk_fail@plt>
    23f5:	c9                   	leave
    23f6:	c3                   	ret

00000000000023f7 <test_values>:
    23f7:	f3 0f 1e fa          	endbr64
    23fb:	55                   	push   %rbp
    23fc:	48 89 e5             	mov    %rsp,%rbp
    23ff:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
    2406:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    240d:	00 00 
    240f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2413:	31 c0                	xor    %eax,%eax
    2415:	e8 4f ef ff ff       	call   1369 <ioopm_hash_table_create>
    241a:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    241e:	48 83 7d 90 00       	cmpq   $0x0,-0x70(%rbp)
    2423:	0f 95 c0             	setne  %al
    2426:	0f b6 c0             	movzbl %al,%eax
    2429:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    242f:	4c 8d 05 d2 1b 00 00 	lea    0x1bd2(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2436:	48 8d 15 cc 1b 00 00 	lea    0x1bcc(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    243d:	48 89 d1             	mov    %rdx,%rcx
    2440:	48 8d 15 cf 1b 00 00 	lea    0x1bcf(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    2447:	be ae 00 00 00       	mov    $0xae,%esi
    244c:	89 c7                	mov    %eax,%edi
    244e:	e8 dd ed ff ff       	call   1230 <CU_assertImplementation@plt>
    2453:	c7 45 b0 03 00 00 00 	movl   $0x3,-0x50(%rbp)
    245a:	c7 45 b4 0a 00 00 00 	movl   $0xa,-0x4c(%rbp)
    2461:	c7 45 b8 2a 00 00 00 	movl   $0x2a,-0x48(%rbp)
    2468:	c7 45 bc 00 00 00 00 	movl   $0x0,-0x44(%rbp)
    246f:	c7 45 c0 63 00 00 00 	movl   $0x63,-0x40(%rbp)
    2476:	48 8d 05 ec 1d 00 00 	lea    0x1dec(%rip),%rax        # 4269 <_IO_stdin_used+0x269>
    247d:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    2481:	48 8d 05 e7 1d 00 00 	lea    0x1de7(%rip),%rax        # 426f <_IO_stdin_used+0x26f>
    2488:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    248c:	48 8d 05 e0 1d 00 00 	lea    0x1de0(%rip),%rax        # 4273 <_IO_stdin_used+0x273>
    2493:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2497:	48 8d 05 de 1d 00 00 	lea    0x1dde(%rip),%rax        # 427c <_IO_stdin_used+0x27c>
    249e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    24a2:	48 8d 05 d8 1d 00 00 	lea    0x1dd8(%rip),%rax        # 4281 <_IO_stdin_used+0x281>
    24a9:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    24ad:	c6 45 ab 00          	movb   $0x0,-0x55(%rbp)
    24b1:	c6 45 ac 00          	movb   $0x0,-0x54(%rbp)
    24b5:	c6 45 ad 00          	movb   $0x0,-0x53(%rbp)
    24b9:	c6 45 ae 00          	movb   $0x0,-0x52(%rbp)
    24bd:	c6 45 af 00          	movb   $0x0,-0x51(%rbp)
    24c1:	c7 45 8c 05 00 00 00 	movl   $0x5,-0x74(%rbp)
    24c8:	c7 85 78 ff ff ff 00 	movl   $0x0,-0x88(%rbp)
    24cf:	00 00 00 
    24d2:	eb 2e                	jmp    2502 <test_values+0x10b>
    24d4:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
    24da:	48 98                	cltq
    24dc:	48 8b 54 c5 d0       	mov    -0x30(%rbp,%rax,8),%rdx
    24e1:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
    24e7:	48 98                	cltq
    24e9:	8b 4c 85 b0          	mov    -0x50(%rbp,%rax,4),%ecx
    24ed:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    24f1:	89 ce                	mov    %ecx,%esi
    24f3:	48 89 c7             	mov    %rax,%rdi
    24f6:	e8 c2 ef ff ff       	call   14bd <ioopm_hash_table_insert>
    24fb:	83 85 78 ff ff ff 01 	addl   $0x1,-0x88(%rbp)
    2502:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
    2508:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    250b:	7c c7                	jl     24d4 <test_values+0xdd>
    250d:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2511:	48 89 c7             	mov    %rax,%rdi
    2514:	e8 fb f2 ff ff       	call   1814 <ioopm_hash_table_keys>
    2519:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    251d:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2521:	48 89 c7             	mov    %rax,%rdi
    2524:	e8 87 f3 ff ff       	call   18b0 <ioopm_hash_table_values>
    2529:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    252d:	48 83 7d 98 00       	cmpq   $0x0,-0x68(%rbp)
    2532:	0f 95 c0             	setne  %al
    2535:	0f b6 c0             	movzbl %al,%eax
    2538:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    253e:	4c 8d 05 c3 1a 00 00 	lea    0x1ac3(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2545:	48 8d 15 bd 1a 00 00 	lea    0x1abd(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    254c:	48 89 d1             	mov    %rdx,%rcx
    254f:	48 8d 15 a2 1c 00 00 	lea    0x1ca2(%rip),%rdx        # 41f8 <_IO_stdin_used+0x1f8>
    2556:	be bd 00 00 00       	mov    $0xbd,%esi
    255b:	89 c7                	mov    %eax,%edi
    255d:	e8 ce ec ff ff       	call   1230 <CU_assertImplementation@plt>
    2562:	48 83 7d a0 00       	cmpq   $0x0,-0x60(%rbp)
    2567:	0f 95 c0             	setne  %al
    256a:	0f b6 c0             	movzbl %al,%eax
    256d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2573:	4c 8d 05 8e 1a 00 00 	lea    0x1a8e(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    257a:	48 8d 15 88 1a 00 00 	lea    0x1a88(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2581:	48 89 d1             	mov    %rdx,%rcx
    2584:	48 8d 15 05 1d 00 00 	lea    0x1d05(%rip),%rdx        # 4290 <_IO_stdin_used+0x290>
    258b:	be be 00 00 00       	mov    $0xbe,%esi
    2590:	89 c7                	mov    %eax,%edi
    2592:	e8 99 ec ff ff       	call   1230 <CU_assertImplementation@plt>
    2597:	c7 85 7c ff ff ff 00 	movl   $0x0,-0x84(%rbp)
    259e:	00 00 00 
    25a1:	e9 02 01 00 00       	jmp    26a8 <test_values+0x2b1>
    25a6:	c6 85 77 ff ff ff 00 	movb   $0x0,-0x89(%rbp)
    25ad:	c7 45 80 00 00 00 00 	movl   $0x0,-0x80(%rbp)
    25b4:	e9 9e 00 00 00       	jmp    2657 <test_values+0x260>
    25b9:	8b 85 7c ff ff ff    	mov    -0x84(%rbp),%eax
    25bf:	48 98                	cltq
    25c1:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    25c8:	00 
    25c9:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    25cd:	48 01 d0             	add    %rdx,%rax
    25d0:	8b 10                	mov    (%rax),%edx
    25d2:	8b 45 80             	mov    -0x80(%rbp),%eax
    25d5:	48 98                	cltq
    25d7:	8b 44 85 b0          	mov    -0x50(%rbp,%rax,4),%eax
    25db:	39 c2                	cmp    %eax,%edx
    25dd:	75 74                	jne    2653 <test_values+0x25c>
    25df:	8b 45 80             	mov    -0x80(%rbp),%eax
    25e2:	48 98                	cltq
    25e4:	48 8b 54 c5 d0       	mov    -0x30(%rbp,%rax,8),%rdx
    25e9:	8b 85 7c ff ff ff    	mov    -0x84(%rbp),%eax
    25ef:	48 98                	cltq
    25f1:	48 8d 0c c5 00 00 00 	lea    0x0(,%rax,8),%rcx
    25f8:	00 
    25f9:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    25fd:	48 01 c8             	add    %rcx,%rax
    2600:	48 8b 00             	mov    (%rax),%rax
    2603:	48 89 d6             	mov    %rdx,%rsi
    2606:	48 89 c7             	mov    %rax,%rdi
    2609:	e8 12 ec ff ff       	call   1220 <strcmp@plt>
    260e:	85 c0                	test   %eax,%eax
    2610:	0f 94 c0             	sete   %al
    2613:	0f b6 c0             	movzbl %al,%eax
    2616:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    261c:	4c 8d 05 e5 19 00 00 	lea    0x19e5(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2623:	48 8d 15 df 19 00 00 	lea    0x19df(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    262a:	48 89 d1             	mov    %rdx,%rcx
    262d:	48 8d 15 8c 1c 00 00 	lea    0x1c8c(%rip),%rdx        # 42c0 <_IO_stdin_used+0x2c0>
    2634:	be c6 00 00 00       	mov    $0xc6,%esi
    2639:	89 c7                	mov    %eax,%edi
    263b:	e8 f0 eb ff ff       	call   1230 <CU_assertImplementation@plt>
    2640:	8b 45 80             	mov    -0x80(%rbp),%eax
    2643:	48 98                	cltq
    2645:	c6 44 05 ab 01       	movb   $0x1,-0x55(%rbp,%rax,1)
    264a:	c6 85 77 ff ff ff 01 	movb   $0x1,-0x89(%rbp)
    2651:	eb 10                	jmp    2663 <test_values+0x26c>
    2653:	83 45 80 01          	addl   $0x1,-0x80(%rbp)
    2657:	8b 45 80             	mov    -0x80(%rbp),%eax
    265a:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    265d:	0f 8c 56 ff ff ff    	jl     25b9 <test_values+0x1c2>
    2663:	0f b6 85 77 ff ff ff 	movzbl -0x89(%rbp),%eax
    266a:	83 f0 01             	xor    $0x1,%eax
    266d:	84 c0                	test   %al,%al
    266f:	74 30                	je     26a1 <test_values+0x2aa>
    2671:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2677:	4c 8d 05 8a 19 00 00 	lea    0x198a(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    267e:	48 8d 05 84 19 00 00 	lea    0x1984(%rip),%rax        # 4009 <_IO_stdin_used+0x9>
    2685:	48 89 c1             	mov    %rax,%rcx
    2688:	48 8d 05 69 1c 00 00 	lea    0x1c69(%rip),%rax        # 42f8 <_IO_stdin_used+0x2f8>
    268f:	48 89 c2             	mov    %rax,%rdx
    2692:	be cd 00 00 00       	mov    $0xcd,%esi
    2697:	bf 00 00 00 00       	mov    $0x0,%edi
    269c:	e8 8f eb ff ff       	call   1230 <CU_assertImplementation@plt>
    26a1:	83 85 7c ff ff ff 01 	addl   $0x1,-0x84(%rbp)
    26a8:	8b 85 7c ff ff ff    	mov    -0x84(%rbp),%eax
    26ae:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    26b1:	0f 8c ef fe ff ff    	jl     25a6 <test_values+0x1af>
    26b7:	c7 45 84 00 00 00 00 	movl   $0x0,-0x7c(%rbp)
    26be:	eb 3b                	jmp    26fb <test_values+0x304>
    26c0:	8b 45 84             	mov    -0x7c(%rbp),%eax
    26c3:	48 98                	cltq
    26c5:	0f b6 44 05 ab       	movzbl -0x55(%rbp,%rax,1),%eax
    26ca:	0f b6 c0             	movzbl %al,%eax
    26cd:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    26d3:	4c 8d 05 2e 19 00 00 	lea    0x192e(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    26da:	48 8d 15 28 19 00 00 	lea    0x1928(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    26e1:	48 89 d1             	mov    %rdx,%rcx
    26e4:	48 8d 15 65 1b 00 00 	lea    0x1b65(%rip),%rdx        # 4250 <_IO_stdin_used+0x250>
    26eb:	be d3 00 00 00       	mov    $0xd3,%esi
    26f0:	89 c7                	mov    %eax,%edi
    26f2:	e8 39 eb ff ff       	call   1230 <CU_assertImplementation@plt>
    26f7:	83 45 84 01          	addl   $0x1,-0x7c(%rbp)
    26fb:	8b 45 84             	mov    -0x7c(%rbp),%eax
    26fe:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    2701:	7c bd                	jl     26c0 <test_values+0x2c9>
    2703:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    2707:	48 89 c7             	mov    %rax,%rdi
    270a:	e8 61 ea ff ff       	call   1170 <free@plt>
    270f:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    2716:	eb 23                	jmp    273b <test_values+0x344>
    2718:	8b 45 88             	mov    -0x78(%rbp),%eax
    271b:	48 98                	cltq
    271d:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
    2724:	00 
    2725:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2729:	48 01 d0             	add    %rdx,%rax
    272c:	48 8b 00             	mov    (%rax),%rax
    272f:	48 89 c7             	mov    %rax,%rdi
    2732:	e8 39 ea ff ff       	call   1170 <free@plt>
    2737:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    273b:	8b 45 88             	mov    -0x78(%rbp),%eax
    273e:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    2741:	7c d5                	jl     2718 <test_values+0x321>
    2743:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2747:	48 89 c7             	mov    %rax,%rdi
    274a:	e8 21 ea ff ff       	call   1170 <free@plt>
    274f:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2753:	48 89 c7             	mov    %rax,%rdi
    2756:	e8 33 ec ff ff       	call   138e <ioopm_hash_table_destroy>
    275b:	90                   	nop
    275c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2760:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2767:	00 00 
    2769:	74 05                	je     2770 <test_values+0x379>
    276b:	e8 70 ea ff ff       	call   11e0 <__stack_chk_fail@plt>
    2770:	c9                   	leave
    2771:	c3                   	ret

0000000000002772 <test_has_keys>:
    2772:	f3 0f 1e fa          	endbr64
    2776:	55                   	push   %rbp
    2777:	48 89 e5             	mov    %rsp,%rbp
    277a:	48 83 ec 10          	sub    $0x10,%rsp
    277e:	e8 e6 eb ff ff       	call   1369 <ioopm_hash_table_create>
    2783:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2787:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    278c:	0f 95 c0             	setne  %al
    278f:	0f b6 c0             	movzbl %al,%eax
    2792:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2798:	4c 8d 05 69 18 00 00 	lea    0x1869(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    279f:	48 8d 15 63 18 00 00 	lea    0x1863(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    27a6:	48 89 d1             	mov    %rdx,%rcx
    27a9:	48 8d 15 66 18 00 00 	lea    0x1866(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    27b0:	be e3 00 00 00       	mov    $0xe3,%esi
    27b5:	89 c7                	mov    %eax,%edi
    27b7:	e8 74 ea ff ff       	call   1230 <CU_assertImplementation@plt>
    27bc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    27c0:	be 01 00 00 00       	mov    $0x1,%esi
    27c5:	48 89 c7             	mov    %rax,%rdi
    27c8:	e8 91 f1 ff ff       	call   195e <ioopm_hash_table_has_key>
    27cd:	83 f0 01             	xor    $0x1,%eax
    27d0:	0f b6 c0             	movzbl %al,%eax
    27d3:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    27d9:	4c 8d 05 28 18 00 00 	lea    0x1828(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    27e0:	48 8d 15 22 18 00 00 	lea    0x1822(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    27e7:	48 89 d1             	mov    %rdx,%rcx
    27ea:	48 8d 15 3f 1b 00 00 	lea    0x1b3f(%rip),%rdx        # 4330 <_IO_stdin_used+0x330>
    27f1:	be e6 00 00 00       	mov    $0xe6,%esi
    27f6:	89 c7                	mov    %eax,%edi
    27f8:	e8 33 ea ff ff       	call   1230 <CU_assertImplementation@plt>
    27fd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2801:	48 8d 15 96 18 00 00 	lea    0x1896(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    2808:	be 01 00 00 00       	mov    $0x1,%esi
    280d:	48 89 c7             	mov    %rax,%rdi
    2810:	e8 a8 ec ff ff       	call   14bd <ioopm_hash_table_insert>
    2815:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2819:	be 01 00 00 00       	mov    $0x1,%esi
    281e:	48 89 c7             	mov    %rax,%rdi
    2821:	e8 38 f1 ff ff       	call   195e <ioopm_hash_table_has_key>
    2826:	0f b6 c0             	movzbl %al,%eax
    2829:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    282f:	4c 8d 05 d2 17 00 00 	lea    0x17d2(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2836:	48 8d 15 cc 17 00 00 	lea    0x17cc(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    283d:	48 89 d1             	mov    %rdx,%rcx
    2840:	48 8d 15 21 1b 00 00 	lea    0x1b21(%rip),%rdx        # 4368 <_IO_stdin_used+0x368>
    2847:	be ec 00 00 00       	mov    $0xec,%esi
    284c:	89 c7                	mov    %eax,%edi
    284e:	e8 dd e9 ff ff       	call   1230 <CU_assertImplementation@plt>
    2853:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2857:	48 89 c7             	mov    %rax,%rdi
    285a:	e8 2f eb ff ff       	call   138e <ioopm_hash_table_destroy>
    285f:	90                   	nop
    2860:	c9                   	leave
    2861:	c3                   	ret

0000000000002862 <test_has_values>:
    2862:	f3 0f 1e fa          	endbr64
    2866:	55                   	push   %rbp
    2867:	48 89 e5             	mov    %rsp,%rbp
    286a:	48 83 ec 10          	sub    $0x10,%rsp
    286e:	e8 f6 ea ff ff       	call   1369 <ioopm_hash_table_create>
    2873:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    2877:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    287c:	0f 95 c0             	setne  %al
    287f:	0f b6 c0             	movzbl %al,%eax
    2882:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2888:	4c 8d 05 79 17 00 00 	lea    0x1779(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    288f:	48 8d 15 73 17 00 00 	lea    0x1773(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2896:	48 89 d1             	mov    %rdx,%rcx
    2899:	48 8d 15 76 17 00 00 	lea    0x1776(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    28a0:	be f6 00 00 00       	mov    $0xf6,%esi
    28a5:	89 c7                	mov    %eax,%edi
    28a7:	e8 84 e9 ff ff       	call   1230 <CU_assertImplementation@plt>
    28ac:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    28b0:	48 8d 15 e7 17 00 00 	lea    0x17e7(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    28b7:	48 89 d6             	mov    %rdx,%rsi
    28ba:	48 89 c7             	mov    %rax,%rdi
    28bd:	e8 c8 f0 ff ff       	call   198a <ioopm_hash_table_has_value>
    28c2:	83 f0 01             	xor    $0x1,%eax
    28c5:	0f b6 c0             	movzbl %al,%eax
    28c8:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    28ce:	4c 8d 05 33 17 00 00 	lea    0x1733(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    28d5:	48 8d 15 2d 17 00 00 	lea    0x172d(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    28dc:	48 89 d1             	mov    %rdx,%rcx
    28df:	48 8d 15 b2 1a 00 00 	lea    0x1ab2(%rip),%rdx        # 4398 <_IO_stdin_used+0x398>
    28e6:	be f9 00 00 00       	mov    $0xf9,%esi
    28eb:	89 c7                	mov    %eax,%edi
    28ed:	e8 3e e9 ff ff       	call   1230 <CU_assertImplementation@plt>
    28f2:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    28f6:	48 8d 15 a1 17 00 00 	lea    0x17a1(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    28fd:	be 01 00 00 00       	mov    $0x1,%esi
    2902:	48 89 c7             	mov    %rax,%rdi
    2905:	e8 b3 eb ff ff       	call   14bd <ioopm_hash_table_insert>
    290a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    290e:	be 01 00 00 00       	mov    $0x1,%esi
    2913:	48 89 c7             	mov    %rax,%rdi
    2916:	e8 d9 ec ff ff       	call   15f4 <ioopm_hash_table_lookup>
    291b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    291f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2923:	48 8d 15 74 17 00 00 	lea    0x1774(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    292a:	48 89 d6             	mov    %rdx,%rsi
    292d:	48 89 c7             	mov    %rax,%rdi
    2930:	e8 eb e8 ff ff       	call   1220 <strcmp@plt>
    2935:	85 c0                	test   %eax,%eax
    2937:	0f 94 c0             	sete   %al
    293a:	0f b6 c0             	movzbl %al,%eax
    293d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2943:	4c 8d 05 be 16 00 00 	lea    0x16be(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    294a:	48 8d 15 b8 16 00 00 	lea    0x16b8(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2951:	48 89 d1             	mov    %rdx,%rcx
    2954:	48 8d 15 7d 1a 00 00 	lea    0x1a7d(%rip),%rdx        # 43d8 <_IO_stdin_used+0x3d8>
    295b:	be 00 01 00 00       	mov    $0x100,%esi
    2960:	89 c7                	mov    %eax,%edi
    2962:	e8 c9 e8 ff ff       	call   1230 <CU_assertImplementation@plt>
    2967:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    296b:	48 8d 15 2c 17 00 00 	lea    0x172c(%rip),%rdx        # 409e <_IO_stdin_used+0x9e>
    2972:	48 89 d6             	mov    %rdx,%rsi
    2975:	48 89 c7             	mov    %rax,%rdi
    2978:	e8 0d f0 ff ff       	call   198a <ioopm_hash_table_has_value>
    297d:	0f b6 c0             	movzbl %al,%eax
    2980:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2986:	4c 8d 05 7b 16 00 00 	lea    0x167b(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    298d:	48 8d 15 75 16 00 00 	lea    0x1675(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2994:	48 89 d1             	mov    %rdx,%rcx
    2997:	48 8d 15 62 1a 00 00 	lea    0x1a62(%rip),%rdx        # 4400 <_IO_stdin_used+0x400>
    299e:	be 03 01 00 00       	mov    $0x103,%esi
    29a3:	89 c7                	mov    %eax,%edi
    29a5:	e8 86 e8 ff ff       	call   1230 <CU_assertImplementation@plt>
    29aa:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    29ae:	48 8d 15 84 1a 00 00 	lea    0x1a84(%rip),%rdx        # 4439 <_IO_stdin_used+0x439>
    29b5:	48 89 d6             	mov    %rdx,%rsi
    29b8:	48 89 c7             	mov    %rax,%rdi
    29bb:	e8 ca ef ff ff       	call   198a <ioopm_hash_table_has_value>
    29c0:	83 f0 01             	xor    $0x1,%eax
    29c3:	0f b6 c0             	movzbl %al,%eax
    29c6:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    29cc:	4c 8d 05 35 16 00 00 	lea    0x1635(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    29d3:	48 8d 15 2f 16 00 00 	lea    0x162f(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    29da:	48 89 d1             	mov    %rdx,%rcx
    29dd:	48 8d 15 64 1a 00 00 	lea    0x1a64(%rip),%rdx        # 4448 <_IO_stdin_used+0x448>
    29e4:	be 06 01 00 00       	mov    $0x106,%esi
    29e9:	89 c7                	mov    %eax,%edi
    29eb:	e8 40 e8 ff ff       	call   1230 <CU_assertImplementation@plt>
    29f0:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    29f4:	48 89 c7             	mov    %rax,%rdi
    29f7:	e8 92 e9 ff ff       	call   138e <ioopm_hash_table_destroy>
    29fc:	90                   	nop
    29fd:	c9                   	leave
    29fe:	c3                   	ret

00000000000029ff <all_keys_bigger_than_10>:
    29ff:	f3 0f 1e fa          	endbr64
    2a03:	55                   	push   %rbp
    2a04:	48 89 e5             	mov    %rsp,%rbp
    2a07:	89 7d fc             	mov    %edi,-0x4(%rbp)
    2a0a:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    2a0e:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    2a12:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
    2a16:	0f 9f c0             	setg   %al
    2a19:	5d                   	pop    %rbp
    2a1a:	c3                   	ret

0000000000002a1b <test_all>:
    2a1b:	f3 0f 1e fa          	endbr64
    2a1f:	55                   	push   %rbp
    2a20:	48 89 e5             	mov    %rsp,%rbp
    2a23:	48 83 ec 60          	sub    $0x60,%rsp
    2a27:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2a2e:	00 00 
    2a30:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2a34:	31 c0                	xor    %eax,%eax
    2a36:	e8 2e e9 ff ff       	call   1369 <ioopm_hash_table_create>
    2a3b:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    2a3f:	48 83 7d a8 00       	cmpq   $0x0,-0x58(%rbp)
    2a44:	0f 95 c0             	setne  %al
    2a47:	0f b6 c0             	movzbl %al,%eax
    2a4a:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2a50:	4c 8d 05 b1 15 00 00 	lea    0x15b1(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2a57:	48 8d 15 ab 15 00 00 	lea    0x15ab(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2a5e:	48 89 d1             	mov    %rdx,%rcx
    2a61:	48 8d 15 ae 15 00 00 	lea    0x15ae(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    2a68:	be 13 01 00 00       	mov    $0x113,%esi
    2a6d:	89 c7                	mov    %eax,%edi
    2a6f:	e8 bc e7 ff ff       	call   1230 <CU_assertImplementation@plt>
    2a74:	c7 45 b0 0b 00 00 00 	movl   $0xb,-0x50(%rbp)
    2a7b:	c7 45 b4 0a 00 00 00 	movl   $0xa,-0x4c(%rbp)
    2a82:	c7 45 b8 2a 00 00 00 	movl   $0x2a,-0x48(%rbp)
    2a89:	c7 45 bc 1e 00 00 00 	movl   $0x1e,-0x44(%rbp)
    2a90:	c7 45 c0 63 00 00 00 	movl   $0x63,-0x40(%rbp)
    2a97:	48 8d 05 cb 17 00 00 	lea    0x17cb(%rip),%rax        # 4269 <_IO_stdin_used+0x269>
    2a9e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    2aa2:	48 8d 05 c6 17 00 00 	lea    0x17c6(%rip),%rax        # 426f <_IO_stdin_used+0x26f>
    2aa9:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    2aad:	48 8d 05 bf 17 00 00 	lea    0x17bf(%rip),%rax        # 4273 <_IO_stdin_used+0x273>
    2ab4:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2ab8:	48 8d 05 bd 17 00 00 	lea    0x17bd(%rip),%rax        # 427c <_IO_stdin_used+0x27c>
    2abf:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2ac3:	48 8d 05 b7 17 00 00 	lea    0x17b7(%rip),%rax        # 4281 <_IO_stdin_used+0x281>
    2aca:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    2ace:	c7 45 a4 05 00 00 00 	movl   $0x5,-0x5c(%rbp)
    2ad5:	c7 45 a0 00 00 00 00 	movl   $0x0,-0x60(%rbp)
    2adc:	eb 25                	jmp    2b03 <test_all+0xe8>
    2ade:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2ae1:	48 98                	cltq
    2ae3:	48 8b 54 c5 d0       	mov    -0x30(%rbp,%rax,8),%rdx
    2ae8:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2aeb:	48 98                	cltq
    2aed:	8b 4c 85 b0          	mov    -0x50(%rbp,%rax,4),%ecx
    2af1:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2af5:	89 ce                	mov    %ecx,%esi
    2af7:	48 89 c7             	mov    %rax,%rdi
    2afa:	e8 be e9 ff ff       	call   14bd <ioopm_hash_table_insert>
    2aff:	83 45 a0 01          	addl   $0x1,-0x60(%rbp)
    2b03:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2b06:	3b 45 a4             	cmp    -0x5c(%rbp),%eax
    2b09:	7c d3                	jl     2ade <test_all+0xc3>
    2b0b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2b0f:	ba 00 00 00 00       	mov    $0x0,%edx
    2b14:	48 8d 0d e4 fe ff ff 	lea    -0x11c(%rip),%rcx        # 29ff <all_keys_bigger_than_10>
    2b1b:	48 89 ce             	mov    %rcx,%rsi
    2b1e:	48 89 c7             	mov    %rax,%rdi
    2b21:	e8 db ee ff ff       	call   1a01 <ioopm_hash_table_all>
    2b26:	0f b6 c0             	movzbl %al,%eax
    2b29:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2b2f:	4c 8d 05 d2 14 00 00 	lea    0x14d2(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2b36:	48 8d 15 cc 14 00 00 	lea    0x14cc(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2b3d:	48 89 d1             	mov    %rdx,%rcx
    2b40:	48 8d 15 41 19 00 00 	lea    0x1941(%rip),%rdx        # 4488 <_IO_stdin_used+0x488>
    2b47:	be 1f 01 00 00       	mov    $0x11f,%esi
    2b4c:	89 c7                	mov    %eax,%edi
    2b4e:	e8 dd e6 ff ff       	call   1230 <CU_assertImplementation@plt>
    2b53:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2b57:	48 8d 15 72 19 00 00 	lea    0x1972(%rip),%rdx        # 44d0 <_IO_stdin_used+0x4d0>
    2b5e:	be 03 00 00 00       	mov    $0x3,%esi
    2b63:	48 89 c7             	mov    %rax,%rdi
    2b66:	e8 52 e9 ff ff       	call   14bd <ioopm_hash_table_insert>
    2b6b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2b6f:	ba 00 00 00 00       	mov    $0x0,%edx
    2b74:	48 8d 0d 84 fe ff ff 	lea    -0x17c(%rip),%rcx        # 29ff <all_keys_bigger_than_10>
    2b7b:	48 89 ce             	mov    %rcx,%rsi
    2b7e:	48 89 c7             	mov    %rax,%rdi
    2b81:	e8 7b ee ff ff       	call   1a01 <ioopm_hash_table_all>
    2b86:	83 f0 01             	xor    $0x1,%eax
    2b89:	0f b6 c0             	movzbl %al,%eax
    2b8c:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2b92:	4c 8d 05 6f 14 00 00 	lea    0x146f(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2b99:	48 8d 15 69 14 00 00 	lea    0x1469(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2ba0:	48 89 d1             	mov    %rdx,%rcx
    2ba3:	48 8d 15 3e 19 00 00 	lea    0x193e(%rip),%rdx        # 44e8 <_IO_stdin_used+0x4e8>
    2baa:	be 25 01 00 00       	mov    $0x125,%esi
    2baf:	89 c7                	mov    %eax,%edi
    2bb1:	e8 7a e6 ff ff       	call   1230 <CU_assertImplementation@plt>
    2bb6:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2bba:	48 89 c7             	mov    %rax,%rdi
    2bbd:	e8 cc e7 ff ff       	call   138e <ioopm_hash_table_destroy>
    2bc2:	90                   	nop
    2bc3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2bc7:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2bce:	00 00 
    2bd0:	74 05                	je     2bd7 <test_all+0x1bc>
    2bd2:	e8 09 e6 ff ff       	call   11e0 <__stack_chk_fail@plt>
    2bd7:	c9                   	leave
    2bd8:	c3                   	ret

0000000000002bd9 <key_is_equal>:
    2bd9:	f3 0f 1e fa          	endbr64
    2bdd:	55                   	push   %rbp
    2bde:	48 89 e5             	mov    %rsp,%rbp
    2be1:	89 7d ec             	mov    %edi,-0x14(%rbp)
    2be4:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    2be8:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    2bec:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2bf0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2bf4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2bf8:	8b 00                	mov    (%rax),%eax
    2bfa:	39 45 ec             	cmp    %eax,-0x14(%rbp)
    2bfd:	0f 94 c0             	sete   %al
    2c00:	5d                   	pop    %rbp
    2c01:	c3                   	ret

0000000000002c02 <test_any>:
    2c02:	f3 0f 1e fa          	endbr64
    2c06:	55                   	push   %rbp
    2c07:	48 89 e5             	mov    %rsp,%rbp
    2c0a:	48 83 ec 70          	sub    $0x70,%rsp
    2c0e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2c15:	00 00 
    2c17:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2c1b:	31 c0                	xor    %eax,%eax
    2c1d:	e8 47 e7 ff ff       	call   1369 <ioopm_hash_table_create>
    2c22:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    2c26:	48 83 7d a8 00       	cmpq   $0x0,-0x58(%rbp)
    2c2b:	0f 95 c0             	setne  %al
    2c2e:	0f b6 c0             	movzbl %al,%eax
    2c31:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2c37:	4c 8d 05 ca 13 00 00 	lea    0x13ca(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2c3e:	48 8d 15 c4 13 00 00 	lea    0x13c4(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2c45:	48 89 d1             	mov    %rdx,%rcx
    2c48:	48 8d 15 c7 13 00 00 	lea    0x13c7(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    2c4f:	be 33 01 00 00       	mov    $0x133,%esi
    2c54:	89 c7                	mov    %eax,%edi
    2c56:	e8 d5 e5 ff ff       	call   1230 <CU_assertImplementation@plt>
    2c5b:	c7 45 b0 03 00 00 00 	movl   $0x3,-0x50(%rbp)
    2c62:	c7 45 b4 0a 00 00 00 	movl   $0xa,-0x4c(%rbp)
    2c69:	c7 45 b8 2a 00 00 00 	movl   $0x2a,-0x48(%rbp)
    2c70:	c7 45 bc 00 00 00 00 	movl   $0x0,-0x44(%rbp)
    2c77:	c7 45 c0 63 00 00 00 	movl   $0x63,-0x40(%rbp)
    2c7e:	48 8d 05 e4 15 00 00 	lea    0x15e4(%rip),%rax        # 4269 <_IO_stdin_used+0x269>
    2c85:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    2c89:	48 8d 05 df 15 00 00 	lea    0x15df(%rip),%rax        # 426f <_IO_stdin_used+0x26f>
    2c90:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    2c94:	48 8d 05 d8 15 00 00 	lea    0x15d8(%rip),%rax        # 4273 <_IO_stdin_used+0x273>
    2c9b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2c9f:	48 8d 05 d6 15 00 00 	lea    0x15d6(%rip),%rax        # 427c <_IO_stdin_used+0x27c>
    2ca6:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2caa:	48 8d 05 d0 15 00 00 	lea    0x15d0(%rip),%rax        # 4281 <_IO_stdin_used+0x281>
    2cb1:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    2cb5:	c7 45 a4 05 00 00 00 	movl   $0x5,-0x5c(%rbp)
    2cbc:	c7 45 a0 00 00 00 00 	movl   $0x0,-0x60(%rbp)
    2cc3:	eb 25                	jmp    2cea <test_any+0xe8>
    2cc5:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2cc8:	48 98                	cltq
    2cca:	48 8b 54 c5 d0       	mov    -0x30(%rbp,%rax,8),%rdx
    2ccf:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2cd2:	48 98                	cltq
    2cd4:	8b 4c 85 b0          	mov    -0x50(%rbp,%rax,4),%ecx
    2cd8:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2cdc:	89 ce                	mov    %ecx,%esi
    2cde:	48 89 c7             	mov    %rax,%rdi
    2ce1:	e8 d7 e7 ff ff       	call   14bd <ioopm_hash_table_insert>
    2ce6:	83 45 a0 01          	addl   $0x1,-0x60(%rbp)
    2cea:	8b 45 a0             	mov    -0x60(%rbp),%eax
    2ced:	3b 45 a4             	cmp    -0x5c(%rbp),%eax
    2cf0:	7c d3                	jl     2cc5 <test_any+0xc3>
    2cf2:	c7 45 98 2a 00 00 00 	movl   $0x2a,-0x68(%rbp)
    2cf9:	48 8d 55 98          	lea    -0x68(%rbp),%rdx
    2cfd:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2d01:	48 8d 0d d1 fe ff ff 	lea    -0x12f(%rip),%rcx        # 2bd9 <key_is_equal>
    2d08:	48 89 ce             	mov    %rcx,%rsi
    2d0b:	48 89 c7             	mov    %rax,%rdi
    2d0e:	e8 73 ed ff ff       	call   1a86 <ioopm_hash_table_any>
    2d13:	0f b6 c0             	movzbl %al,%eax
    2d16:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2d1c:	4c 8d 05 e5 12 00 00 	lea    0x12e5(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2d23:	48 8d 15 df 12 00 00 	lea    0x12df(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2d2a:	48 89 d1             	mov    %rdx,%rcx
    2d2d:	48 8d 15 04 18 00 00 	lea    0x1804(%rip),%rdx        # 4538 <_IO_stdin_used+0x538>
    2d34:	be 40 01 00 00       	mov    $0x140,%esi
    2d39:	89 c7                	mov    %eax,%edi
    2d3b:	e8 f0 e4 ff ff       	call   1230 <CU_assertImplementation@plt>
    2d40:	c7 45 9c 64 00 00 00 	movl   $0x64,-0x64(%rbp)
    2d47:	48 8d 55 9c          	lea    -0x64(%rbp),%rdx
    2d4b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2d4f:	48 8d 0d 83 fe ff ff 	lea    -0x17d(%rip),%rcx        # 2bd9 <key_is_equal>
    2d56:	48 89 ce             	mov    %rcx,%rsi
    2d59:	48 89 c7             	mov    %rax,%rdi
    2d5c:	e8 25 ed ff ff       	call   1a86 <ioopm_hash_table_any>
    2d61:	83 f0 01             	xor    $0x1,%eax
    2d64:	0f b6 c0             	movzbl %al,%eax
    2d67:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2d6d:	4c 8d 05 94 12 00 00 	lea    0x1294(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2d74:	48 8d 15 8e 12 00 00 	lea    0x128e(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2d7b:	48 89 d1             	mov    %rdx,%rcx
    2d7e:	48 8d 15 fb 17 00 00 	lea    0x17fb(%rip),%rdx        # 4580 <_IO_stdin_used+0x580>
    2d85:	be 44 01 00 00       	mov    $0x144,%esi
    2d8a:	89 c7                	mov    %eax,%edi
    2d8c:	e8 9f e4 ff ff       	call   1230 <CU_assertImplementation@plt>
    2d91:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2d95:	48 89 c7             	mov    %rax,%rdi
    2d98:	e8 f1 e5 ff ff       	call   138e <ioopm_hash_table_destroy>
    2d9d:	90                   	nop
    2d9e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2da2:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2da9:	00 00 
    2dab:	74 05                	je     2db2 <test_any+0x1b0>
    2dad:	e8 2e e4 ff ff       	call   11e0 <__stack_chk_fail@plt>
    2db2:	c9                   	leave
    2db3:	c3                   	ret

0000000000002db4 <append_suffix>:
    2db4:	f3 0f 1e fa          	endbr64
    2db8:	55                   	push   %rbp
    2db9:	48 89 e5             	mov    %rsp,%rbp
    2dbc:	53                   	push   %rbx
    2dbd:	48 83 ec 48          	sub    $0x48,%rsp
    2dc1:	89 7d cc             	mov    %edi,-0x34(%rbp)
    2dc4:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    2dc8:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    2dcc:	48 83 7d c0 00       	cmpq   $0x0,-0x40(%rbp)
    2dd1:	0f 84 9b 00 00 00    	je     2e72 <append_suffix+0xbe>
    2dd7:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2ddb:	48 8b 00             	mov    (%rax),%rax
    2dde:	48 85 c0             	test   %rax,%rax
    2de1:	0f 84 8b 00 00 00    	je     2e72 <append_suffix+0xbe>
    2de7:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    2deb:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    2def:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2df3:	48 8b 00             	mov    (%rax),%rax
    2df6:	48 89 c7             	mov    %rax,%rdi
    2df9:	e8 d2 e3 ff ff       	call   11d0 <strlen@plt>
    2dfe:	48 89 c3             	mov    %rax,%rbx
    2e01:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2e05:	48 89 c7             	mov    %rax,%rdi
    2e08:	e8 c3 e3 ff ff       	call   11d0 <strlen@plt>
    2e0d:	48 01 d8             	add    %rbx,%rax
    2e10:	48 83 c0 01          	add    $0x1,%rax
    2e14:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2e18:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    2e1c:	48 89 c7             	mov    %rax,%rdi
    2e1f:	e8 1c e4 ff ff       	call   1240 <malloc@plt>
    2e24:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2e28:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    2e2d:	74 43                	je     2e72 <append_suffix+0xbe>
    2e2f:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2e33:	48 8b 10             	mov    (%rax),%rdx
    2e36:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2e3a:	48 89 d6             	mov    %rdx,%rsi
    2e3d:	48 89 c7             	mov    %rax,%rdi
    2e40:	e8 4b e3 ff ff       	call   1190 <strcpy@plt>
    2e45:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2e49:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2e4d:	48 89 d6             	mov    %rdx,%rsi
    2e50:	48 89 c7             	mov    %rax,%rdi
    2e53:	e8 08 e4 ff ff       	call   1260 <strcat@plt>
    2e58:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2e5c:	48 8b 00             	mov    (%rax),%rax
    2e5f:	48 89 c7             	mov    %rax,%rdi
    2e62:	e8 09 e3 ff ff       	call   1170 <free@plt>
    2e67:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2e6b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    2e6f:	48 89 10             	mov    %rdx,(%rax)
    2e72:	90                   	nop
    2e73:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2e77:	c9                   	leave
    2e78:	c3                   	ret

0000000000002e79 <test_apply>:
    2e79:	f3 0f 1e fa          	endbr64
    2e7d:	55                   	push   %rbp
    2e7e:	48 89 e5             	mov    %rsp,%rbp
    2e81:	48 83 ec 70          	sub    $0x70,%rsp
    2e85:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2e8c:	00 00 
    2e8e:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2e92:	31 c0                	xor    %eax,%eax
    2e94:	e8 d0 e4 ff ff       	call   1369 <ioopm_hash_table_create>
    2e99:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    2e9d:	48 83 7d 98 00       	cmpq   $0x0,-0x68(%rbp)
    2ea2:	0f 95 c0             	setne  %al
    2ea5:	0f b6 c0             	movzbl %al,%eax
    2ea8:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2eae:	4c 8d 05 53 11 00 00 	lea    0x1153(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2eb5:	48 8d 15 4d 11 00 00 	lea    0x114d(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2ebc:	48 89 d1             	mov    %rdx,%rcx
    2ebf:	48 8d 15 50 11 00 00 	lea    0x1150(%rip),%rdx        # 4016 <_IO_stdin_used+0x16>
    2ec6:	be 5c 01 00 00       	mov    $0x15c,%esi
    2ecb:	89 c7                	mov    %eax,%edi
    2ecd:	e8 5e e3 ff ff       	call   1230 <CU_assertImplementation@plt>
    2ed2:	c7 45 b4 01 00 00 00 	movl   $0x1,-0x4c(%rbp)
    2ed9:	c7 45 b8 02 00 00 00 	movl   $0x2,-0x48(%rbp)
    2ee0:	c7 45 bc 03 00 00 00 	movl   $0x3,-0x44(%rbp)
    2ee7:	48 8d 05 dd 16 00 00 	lea    0x16dd(%rip),%rax        # 45cb <_IO_stdin_used+0x5cb>
    2eee:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    2ef2:	48 8d 05 d9 16 00 00 	lea    0x16d9(%rip),%rax        # 45d2 <_IO_stdin_used+0x5d2>
    2ef9:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    2efd:	48 8d 05 d5 16 00 00 	lea    0x16d5(%rip),%rax        # 45d9 <_IO_stdin_used+0x5d9>
    2f04:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    2f08:	48 8d 05 d1 16 00 00 	lea    0x16d1(%rip),%rax        # 45e0 <_IO_stdin_used+0x5e0>
    2f0f:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    2f13:	c7 45 90 00 00 00 00 	movl   $0x0,-0x70(%rbp)
    2f1a:	eb 25                	jmp    2f41 <test_apply+0xc8>
    2f1c:	8b 45 90             	mov    -0x70(%rbp),%eax
    2f1f:	48 98                	cltq
    2f21:	48 8b 54 c5 c0       	mov    -0x40(%rbp,%rax,8),%rdx
    2f26:	8b 45 90             	mov    -0x70(%rbp),%eax
    2f29:	48 98                	cltq
    2f2b:	8b 4c 85 b4          	mov    -0x4c(%rbp,%rax,4),%ecx
    2f2f:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    2f33:	89 ce                	mov    %ecx,%esi
    2f35:	48 89 c7             	mov    %rax,%rdi
    2f38:	e8 80 e5 ff ff       	call   14bd <ioopm_hash_table_insert>
    2f3d:	83 45 90 01          	addl   $0x1,-0x70(%rbp)
    2f41:	83 7d 90 02          	cmpl   $0x2,-0x70(%rbp)
    2f45:	7e d5                	jle    2f1c <test_apply+0xa3>
    2f47:	48 8b 55 a0          	mov    -0x60(%rbp),%rdx
    2f4b:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    2f4f:	48 8d 0d 5e fe ff ff 	lea    -0x1a2(%rip),%rcx        # 2db4 <append_suffix>
    2f56:	48 89 ce             	mov    %rcx,%rsi
    2f59:	48 89 c7             	mov    %rax,%rdi
    2f5c:	e8 a7 eb ff ff       	call   1b08 <ioopm_hash_table_apply_to_all>
    2f61:	c7 45 94 00 00 00 00 	movl   $0x0,-0x6c(%rbp)
    2f68:	e9 89 00 00 00       	jmp    2ff6 <test_apply+0x17d>
    2f6d:	8b 45 94             	mov    -0x6c(%rbp),%eax
    2f70:	8d 50 01             	lea    0x1(%rax),%edx
    2f73:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    2f77:	89 d1                	mov    %edx,%ecx
    2f79:	48 8d 15 68 16 00 00 	lea    0x1668(%rip),%rdx        # 45e8 <_IO_stdin_used+0x5e8>
    2f80:	be 14 00 00 00       	mov    $0x14,%esi
    2f85:	48 89 c7             	mov    %rax,%rdi
    2f88:	b8 00 00 00 00       	mov    $0x0,%eax
    2f8d:	e8 6e e2 ff ff       	call   1200 <snprintf@plt>
    2f92:	8b 45 94             	mov    -0x6c(%rbp),%eax
    2f95:	48 98                	cltq
    2f97:	8b 54 85 b4          	mov    -0x4c(%rbp,%rax,4),%edx
    2f9b:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    2f9f:	89 d6                	mov    %edx,%esi
    2fa1:	48 89 c7             	mov    %rax,%rdi
    2fa4:	e8 4b e6 ff ff       	call   15f4 <ioopm_hash_table_lookup>
    2fa9:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    2fad:	48 8d 55 e0          	lea    -0x20(%rbp),%rdx
    2fb1:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    2fb5:	48 89 d6             	mov    %rdx,%rsi
    2fb8:	48 89 c7             	mov    %rax,%rdi
    2fbb:	e8 60 e2 ff ff       	call   1220 <strcmp@plt>
    2fc0:	85 c0                	test   %eax,%eax
    2fc2:	0f 94 c0             	sete   %al
    2fc5:	0f b6 c0             	movzbl %al,%eax
    2fc8:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2fce:	4c 8d 05 33 10 00 00 	lea    0x1033(%rip),%r8        # 4008 <_IO_stdin_used+0x8>
    2fd5:	48 8d 15 2d 10 00 00 	lea    0x102d(%rip),%rdx        # 4009 <_IO_stdin_used+0x9>
    2fdc:	48 89 d1             	mov    %rdx,%rcx
    2fdf:	48 8d 15 12 16 00 00 	lea    0x1612(%rip),%rdx        # 45f8 <_IO_stdin_used+0x5f8>
    2fe6:	be 70 01 00 00       	mov    $0x170,%esi
    2feb:	89 c7                	mov    %eax,%edi
    2fed:	e8 3e e2 ff ff       	call   1230 <CU_assertImplementation@plt>
    2ff2:	83 45 94 01          	addl   $0x1,-0x6c(%rbp)
    2ff6:	83 7d 94 02          	cmpl   $0x2,-0x6c(%rbp)
    2ffa:	0f 8e 6d ff ff ff    	jle    2f6d <test_apply+0xf4>
    3000:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    3004:	48 89 c7             	mov    %rax,%rdi
    3007:	e8 82 e3 ff ff       	call   138e <ioopm_hash_table_destroy>
    300c:	90                   	nop
    300d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    3011:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    3018:	00 00 
    301a:	74 05                	je     3021 <test_apply+0x1a8>
    301c:	e8 bf e1 ff ff       	call   11e0 <__stack_chk_fail@plt>
    3021:	c9                   	leave
    3022:	c3                   	ret

0000000000003023 <main>:
    3023:	f3 0f 1e fa          	endbr64
    3027:	55                   	push   %rbp
    3028:	48 89 e5             	mov    %rsp,%rbp
    302b:	48 83 ec 10          	sub    $0x10,%rsp
    302f:	e8 4c e1 ff ff       	call   1180 <CU_initialize_registry@plt>
    3034:	85 c0                	test   %eax,%eax
    3036:	74 0a                	je     3042 <main+0x1f>
    3038:	e8 b3 e1 ff ff       	call   11f0 <CU_get_error@plt>
    303d:	e9 b2 01 00 00       	jmp    31f4 <main+0x1d1>
    3042:	48 8d 05 4d eb ff ff 	lea    -0x14b3(%rip),%rax        # 1b96 <clean_suite>
    3049:	48 89 c2             	mov    %rax,%rdx
    304c:	48 8d 05 34 eb ff ff 	lea    -0x14cc(%rip),%rax        # 1b87 <init_suite>
    3053:	48 89 c6             	mov    %rax,%rsi
    3056:	48 8d 05 cf 15 00 00 	lea    0x15cf(%rip),%rax        # 462c <_IO_stdin_used+0x62c>
    305d:	48 89 c7             	mov    %rax,%rdi
    3060:	e8 4b e1 ff ff       	call   11b0 <CU_add_suite@plt>
    3065:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    3069:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    306e:	75 0f                	jne    307f <main+0x5c>
    3070:	e8 2b e1 ff ff       	call   11a0 <CU_cleanup_registry@plt>
    3075:	e8 76 e1 ff ff       	call   11f0 <CU_get_error@plt>
    307a:	e9 75 01 00 00       	jmp    31f4 <main+0x1d1>
    307f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    3083:	48 8d 15 1b eb ff ff 	lea    -0x14e5(%rip),%rdx        # 1ba5 <test_create_destroy>
    308a:	48 8d 0d b1 15 00 00 	lea    0x15b1(%rip),%rcx        # 4642 <_IO_stdin_used+0x642>
    3091:	48 89 ce             	mov    %rcx,%rsi
    3094:	48 89 c7             	mov    %rax,%rdi
    3097:	e8 b4 e1 ff ff       	call   1250 <CU_add_test@plt>
    309c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    30a0:	48 8d 15 57 eb ff ff 	lea    -0x14a9(%rip),%rdx        # 1bfe <test_insert_once>
    30a7:	48 8d 0d a8 15 00 00 	lea    0x15a8(%rip),%rcx        # 4656 <_IO_stdin_used+0x656>
    30ae:	48 89 ce             	mov    %rcx,%rsi
    30b1:	48 89 c7             	mov    %rax,%rdi
    30b4:	e8 97 e1 ff ff       	call   1250 <CU_add_test@plt>
    30b9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    30bd:	48 8d 15 af ec ff ff 	lea    -0x1351(%rip),%rdx        # 1d73 <test_insert_remove>
    30c4:	48 8d 0d 9e 15 00 00 	lea    0x159e(%rip),%rcx        # 4669 <_IO_stdin_used+0x669>
    30cb:	48 89 ce             	mov    %rcx,%rsi
    30ce:	48 89 c7             	mov    %rax,%rdi
    30d1:	e8 7a e1 ff ff       	call   1250 <CU_add_test@plt>
    30d6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    30da:	48 8d 15 6c ee ff ff 	lea    -0x1194(%rip),%rdx        # 1f4d <test_size>
    30e1:	48 8d 0d 94 15 00 00 	lea    0x1594(%rip),%rcx        # 467c <_IO_stdin_used+0x67c>
    30e8:	48 89 ce             	mov    %rcx,%rsi
    30eb:	48 89 c7             	mov    %rax,%rdi
    30ee:	e8 5d e1 ff ff       	call   1250 <CU_add_test@plt>
    30f3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    30f7:	48 8d 15 a7 ef ff ff 	lea    -0x1059(%rip),%rdx        # 20a5 <test_is_empty_clear>
    30fe:	48 8d 0d 81 15 00 00 	lea    0x1581(%rip),%rcx        # 4686 <_IO_stdin_used+0x686>
    3105:	48 89 ce             	mov    %rcx,%rsi
    3108:	48 89 c7             	mov    %rax,%rdi
    310b:	e8 40 e1 ff ff       	call   1250 <CU_add_test@plt>
    3110:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    3114:	48 8d 15 af f0 ff ff 	lea    -0xf51(%rip),%rdx        # 21ca <test_keys>
    311b:	48 8d 0d 78 15 00 00 	lea    0x1578(%rip),%rcx        # 469a <_IO_stdin_used+0x69a>
    3122:	48 89 ce             	mov    %rcx,%rsi
    3125:	48 89 c7             	mov    %rax,%rdi
    3128:	e8 23 e1 ff ff       	call   1250 <CU_add_test@plt>
    312d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    3131:	48 8d 15 bf f2 ff ff 	lea    -0xd41(%rip),%rdx        # 23f7 <test_values>
    3138:	48 8d 0d 65 15 00 00 	lea    0x1565(%rip),%rcx        # 46a4 <_IO_stdin_used+0x6a4>
    313f:	48 89 ce             	mov    %rcx,%rsi
    3142:	48 89 c7             	mov    %rax,%rdi
    3145:	e8 06 e1 ff ff       	call   1250 <CU_add_test@plt>
    314a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    314e:	48 8d 15 1d f6 ff ff 	lea    -0x9e3(%rip),%rdx        # 2772 <test_has_keys>
    3155:	48 8d 0d 54 15 00 00 	lea    0x1554(%rip),%rcx        # 46b0 <_IO_stdin_used+0x6b0>
    315c:	48 89 ce             	mov    %rcx,%rsi
    315f:	48 89 c7             	mov    %rax,%rdi
    3162:	e8 e9 e0 ff ff       	call   1250 <CU_add_test@plt>
    3167:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    316b:	48 8d 15 f0 f6 ff ff 	lea    -0x910(%rip),%rdx        # 2862 <test_has_values>
    3172:	48 8d 0d 44 15 00 00 	lea    0x1544(%rip),%rcx        # 46bd <_IO_stdin_used+0x6bd>
    3179:	48 89 ce             	mov    %rcx,%rsi
    317c:	48 89 c7             	mov    %rax,%rdi
    317f:	e8 cc e0 ff ff       	call   1250 <CU_add_test@plt>
    3184:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    3188:	48 8d 15 8c f8 ff ff 	lea    -0x774(%rip),%rdx        # 2a1b <test_all>
    318f:	48 8d 0d 34 15 00 00 	lea    0x1534(%rip),%rcx        # 46ca <_IO_stdin_used+0x6ca>
    3196:	48 89 ce             	mov    %rcx,%rsi
    3199:	48 89 c7             	mov    %rax,%rdi
    319c:	e8 af e0 ff ff       	call   1250 <CU_add_test@plt>
    31a1:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    31a5:	48 8d 15 56 fa ff ff 	lea    -0x5aa(%rip),%rdx        # 2c02 <test_any>
    31ac:	48 8d 0d 20 15 00 00 	lea    0x1520(%rip),%rcx        # 46d3 <_IO_stdin_used+0x6d3>
    31b3:	48 89 ce             	mov    %rcx,%rsi
    31b6:	48 89 c7             	mov    %rax,%rdi
    31b9:	e8 92 e0 ff ff       	call   1250 <CU_add_test@plt>
    31be:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    31c2:	48 8d 15 b0 fc ff ff 	lea    -0x350(%rip),%rdx        # 2e79 <test_apply>
    31c9:	48 8d 0d 0c 15 00 00 	lea    0x150c(%rip),%rcx        # 46dc <_IO_stdin_used+0x6dc>
    31d0:	48 89 ce             	mov    %rcx,%rsi
    31d3:	48 89 c7             	mov    %rax,%rdi
    31d6:	e8 75 e0 ff ff       	call   1250 <CU_add_test@plt>
    31db:	bf 02 00 00 00       	mov    $0x2,%edi
    31e0:	e8 7b df ff ff       	call   1160 <CU_basic_set_mode@plt>
    31e5:	e8 d6 df ff ff       	call   11c0 <CU_basic_run_tests@plt>
    31ea:	e8 b1 df ff ff       	call   11a0 <CU_cleanup_registry@plt>
    31ef:	e8 fc df ff ff       	call   11f0 <CU_get_error@plt>
    31f4:	c9                   	leave
    31f5:	c3                   	ret

Disassembly of section .fini:

00000000000031f8 <_fini>:
    31f8:	f3 0f 1e fa          	endbr64
    31fc:	48 83 ec 08          	sub    $0x8,%rsp
    3200:	48 83 c4 08          	add    $0x8,%rsp
    3204:	c3                   	ret
