# EOSource Revived 1.0.0

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

EOSource Revived is a modern, secure, and transparent rebuild of the classic Endless Online server engine with all the eosource features you know and love.

---

## 🔐 Security & Transparency

EOSource has been completely re-worked to prioritize security and transparency:

- **No Backdoors** – All known backdoors have been removed, ensuring server integrity.
- **Server Owner Controlled** – There is no code that allows unauthorized shutdowns or remote access. Server owners retain full control at all times.
- **Open Source** – Released under the [MIT License](https://opensource.org/licenses/MIT) as an EOServ fork, allowing for free use, modification, and distribution. No hidden strings attached.

---

## ⚙️ Compilation Requirements

To compile EOSource on Windows (32-bit), use the following tools:

- **Code::Blocks 20.03 (32-bit)**  
- **TDM-GCC 4.6.1 (32-bit)**  

> Ensure that the compiler’s installation directory is correctly set in Code::Blocks under  
> `Settings → Compiler → Toolchain Executables` (usually `C:/MINGW32`)

---

## 🛠️ Post-Compilation

After building `EOSource.exe`, the following DLL files must be present in the executable directory:

- `pthreadGC2.dll`
- `libmariadb.dll`

---

## ❓ Troubleshooting

### Common Issues

- `pthread` not found  
- `struct timespec` error  
- General compilation errors

### Solutions

- Uninstall all versions of Code::Blocks.
- Remove all custom global compiler settings.
- Reinstall the exact versions of Code::Blocks and TDM-GCC listed above.

> ⚠️ This guide supports **32-bit builds only**. Use only the provided versions and settings.

---

For more information and updates, visit our [discord community](https://discord.gg/veG8TkVCsZ).
