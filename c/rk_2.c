#include 
int main() {
 HINSTANCE hInst = LoadLibrary("kernel32.dll");
 typedef BOOLAPI (BOOL)(HMODULE hModule, DWORD fdwMajorVersion, DWORD dwMinorVersion, LPSTR lpReserved, DWORD cbReserved, LPSTR lpClassDriver, DWORD cbClassDriver, LPSTR lpDeviceObjectName, DWORD cbDeviceObjectName);
 BOOL (WINAPI* FAR PFN_SetDoubleStar)(HMODULE hMod, LPSTR lpszFuncName, LPSTR lpszOrdinalBase, LPSTR lpszCompatibleFileName, DWORD i, LPSTR lpszExePath);
 FAR *pfnSetDoubleStar = (PFN_SETDOUBLESTAR*)GetProcAddress(hInst, "LoadLibraryA@16");
 if (*((ULONG_PTR*)&hInst + 8) == LOAD_LIBRARY_SEARCH_SYSTEM32) {
 *((ULONG_PTR*)&hInst + 8) = LOAD_LIBRARY_OPTIONAL_SEARCH_SYSTEM32;
 *((ULONG_PTR*)&hInst + 4) = GetFileTime();
 *((ULONG_PTR*)&hInst - 4) = GetFileTime();
 *((ULONG_PTR*)&hInst - 8) = GetFileTime();
 } else {
 *((ULONG_PTR*)&hInst - 8) = GetFileTime();
 }
}
return 0;
