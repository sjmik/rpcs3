#pragma once

enum
{
	SYS_PPU_THREAD_ONCE_INIT,
	SYS_PPU_THREAD_DONE_INIT,
};

enum ppu_thread_flags : u64
{
	SYS_PPU_THREAD_CREATE_JOINABLE = 0x1,
	SYS_PPU_THREAD_CREATE_INTERRUPT = 0x2,
};

// SysCalls
void sys_ppu_thread_exit(u64 errorcode);
s32 sys_ppu_thread_yield();
s32 sys_ppu_thread_join(u64 thread_id, mem64_t vptr);
s32 sys_ppu_thread_detach(u64 thread_id);
void sys_ppu_thread_get_join_state(u32 isjoinable_addr);
s32 sys_ppu_thread_set_priority(u64 thread_id, s32 prio);
s32 sys_ppu_thread_get_priority(u64 thread_id, u32 prio_addr);
s32 sys_ppu_thread_get_stack_information(u32 info_addr);
s32 sys_ppu_thread_stop(u64 thread_id);
s32 sys_ppu_thread_restart(u64 thread_id);
s32 sys_ppu_thread_create(mem64_t thread_id, u32 entry, u64 arg, s32 prio, u32 stacksize, u64 flags, u32 threadname_addr);
void sys_ppu_thread_once(mem_ptr_t<std::atomic<be_t<u32>>> once_ctrl, u32 entry);
s32 sys_ppu_thread_get_id(const u32 id_addr);
