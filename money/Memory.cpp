

#include "../hotkeys/Trainer.h"
#include <windows.h>
#include <tlhelp32.h>

// GameMem: external process memory. ReadProcessMemory and
// WriteProcessMemory only - nothing is injected into FH6.

namespace fh6 {

bool GameMem::waitFor(const char* process, unsigned long timeoutMs) {
    DWORD pid = 0, waited = 0;
    while (!pid && waited < timeoutMs * 60) {
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 pe{ sizeof(pe) };
        if (Process32First(snap, &pe)) {
            do {
                if (_stricmp(pe.szExeFile, process) == 0)
                    pid = pe.th32ProcessID;
            } while (Process32Next(snap, &pe) && !pid);
        }
        CloseHandle(snap);
        if (!pid) { Sleep(500); waited += 500; }
    }
    if (!pid) return false;

    handle_ = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION,
                          FALSE, pid);
    return handle_ != nullptr;
}

bool GameMem::writeBytes(uintptr_t addr, const void* data, size_t size) {
    SIZE_T done = 0;
    return WriteProcessMemory(handle_, reinterpret_cast<LPVOID>(addr),
                              data, size, &done) && done == size;
}

bool GameMem::readBytes(uintptr_t addr, void* out, size_t size) {
    SIZE_T got = 0;
    return ReadProcessMemory(handle_, reinterpret_cast<LPCVOID>(addr),
                             out, size, &got) && got == size;
}

} // namespace fh6
