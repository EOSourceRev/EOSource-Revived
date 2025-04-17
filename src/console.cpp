#include "console.hpp"

#include <cstdio>
#include <cstdarg>

#include "platform.h"

#ifdef WIN32
#include <windows.h>
#endif

namespace Console
{
    bool Styled[2] = {true, true};

    #ifdef WIN32
    static HANDLE Handles[2];

    inline void Init(Stream i)
    {
        if (!Handles[i])
        {
            Handles[i] = GetStdHandle((i == STREAM_OUT) ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE);
        }
    }

    void SetTextColor(Stream stream, Color color, bool bold)
    {
        char command[8] = {27, '[', '1', ';', '3', '0', 'm', 0};

        if (bold)
        {
            command[5] += (color - 30);
        }
        else
        {
            for (int i = 2; i < 6; ++i)
                command[i] = command[i + 2];

            command[3] += (color - 30);
        }

        std::fputs(command, (stream == STREAM_OUT) ? stdout : stderr);
    }

    void ResetTextColor(Stream stream)
    {
        Init(stream);
        SetConsoleTextAttribute(Handles[stream], COLOR_GREY);
    }

    #else

    void SetTextColor(Stream stream, Color color, bool bold)
    {
        char command[8] = {27, '[', '1', ';', '3', '0', 'm', 0};

        if (bold)
        {
            command[5] += (color - 30);
        }
        else
        {
            for (int i = 2; i < 6; ++i)
                command[i] = command[i + 2];

            command[3] += (color - 30);
        }

        std::fputs(command, (stream == STREAM_OUT) ? stdout : stderr);
    }

    void ResetTextColor(Stream stream)
    {
        char command[5] = {27, '[', '0', 'm', 0};
        std::fputs(command, (stream == STREAM_OUT) ? stdout : stderr);
    }

    #endif

    #define CONSOLE_GENERIC_OUT(prefix, stream, color, bold) \
    if (Styled[stream]) SetTextColor(stream, color, bold); \
    va_list args; \
    va_start(args, f); \
    std::vfprintf((stream == STREAM_OUT) ? stdout : stderr, (std::string(prefix) + f + "\n").c_str(), args); \
    va_end(args); \
    if (Styled[stream]) ResetTextColor(stream);

    void Out(std::string f, ...)
    {
        // Check if this is part of the data section (database info)
        if (f.find("Database type") != std::string::npos || 
            f.find("accounts") != std::string::npos ||
            f.find("characters") != std::string::npos ||
            f.find("staff members") != std::string::npos ||
            f.find("guilds") != std::string::npos ||
            f.find("Banned IPS") != std::string::npos ||
            f.find("members") != std::string::npos) {
            // Data section in green
            #ifdef WIN32
            if (Styled[STREAM_OUT])
            {
                Init(STREAM_OUT);
                SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            va_list args;
            va_start(args, f);
            std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
            va_end(args);
            if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
            #else
            CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREEN, true);
            #endif
        } 
        // Check if this is loading files text
        else if (f.find("load") != std::string::npos || 
                f.find("Loading") != std::string::npos ||
                f.find(".ini") != std::string::npos ||
                f.find("config") != std::string::npos ||
                f.find("admin.ini") != std::string::npos ||
                f.find("defaults") != std::string::npos) {
            // Loading files text in white
            #ifdef WIN32
            if (Styled[STREAM_OUT])
            {
                Init(STREAM_OUT);
                SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            va_list args;
            va_start(args, f);
            std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
            va_end(args);
            if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
            #else
            CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREY, true);
            #endif
        }
        // Regular output in white
        else {
            #ifdef WIN32
            if (Styled[STREAM_OUT])
            {
                Init(STREAM_OUT);
                SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            va_list args;
            va_start(args, f);
            std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
            va_end(args);
            if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
            #else
            CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREY, true);
            #endif
        }
    }

    void RedOut(std::string f, ...)
    {
        // Change to white output
        #ifdef WIN32
        if (Styled[STREAM_OUT])
        {
            Init(STREAM_OUT);
            SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
        #else
        CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREY, true);
        #endif
    }

    void PurpleOut(std::string f, ...)
    {
        // Change to white output
        #ifdef WIN32
        if (Styled[STREAM_OUT])
        {
            Init(STREAM_OUT);
            SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
        #else
        CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREY, true);
        #endif
    }

    void YellowOut(std::string f, ...)
    {
        // Keep yellow for special messages
        #ifdef WIN32
        if (Styled[STREAM_OUT])
        {
            Init(STREAM_OUT);
            SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
        #else
        CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_YELLOW, true);
        #endif
    }

    void GreenOut(std::string f, ...)
    {
        // Keep green for data sections
        #ifdef WIN32
        if (Styled[STREAM_OUT])
        {
            Init(STREAM_OUT);
            SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stdout, (std::string("  > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
        #else
        CONSOLE_GENERIC_OUT("  > ", STREAM_OUT, COLOR_GREEN, true);
        #endif
    }

    void Wrn(std::string f, ...)
    {
        // Warning in orange/yellow
        #ifdef WIN32
        if (Styled[STREAM_ERR])
        {
            Init(STREAM_ERR);
            SetConsoleTextAttribute(Handles[STREAM_ERR], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stderr, (std::string(" WRN > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_ERR]) ResetTextColor(STREAM_ERR);
        #else
        CONSOLE_GENERIC_OUT(" WRN > ", STREAM_ERR, COLOR_YELLOW, true);
        #endif
    }

    void Err(std::string f, ...)
    {
        // Error in red (keep as is)
        CONSOLE_GENERIC_OUT(" ERR > ", STREAM_ERR, COLOR_RED, true);
    }

    void Dbg(std::string f, ...)
    {
        // Debug in white
        #ifdef WIN32
        if (Styled[STREAM_OUT])
        {
            Init(STREAM_OUT);
            SetConsoleTextAttribute(Handles[STREAM_OUT], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        va_list args;
        va_start(args, f);
        std::vfprintf(stdout, (std::string(" DBG > ") + f + "\n").c_str(), args);
        va_end(args);
        if (Styled[STREAM_OUT]) ResetTextColor(STREAM_OUT);
        #else
        CONSOLE_GENERIC_OUT(" DBG > ", STREAM_OUT, COLOR_GREY, true);
        #endif
    }
}
